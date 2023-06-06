#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

// Definición de la clase Pokemon
class Pokemon 
{
private:
    std::string nombre;
    int nivel;
    int vida;
    
public:
    Pokemon(std::string nombre, int nivel, int vida) {
        this->nombre = nombre;
        this->nivel = nivel;
        this->vida = vida;
        setlocale(LC_ALL, "es_MX.UTF-8");
    }

    std::string getNombre() 
    {
        return nombre;
        setlocale(LC_ALL, "es_MX.UTF-8");
    }

    int getNivel() {
        return nivel;
        setlocale(LC_ALL, "es_MX.UTF-8");
    }

    int getVida() {
        return vida;
        setlocale(LC_ALL, "es_MX.UTF-8");
    }

    void recibirAtaque(int dano) {
        vida -= dano;
        if (vida < 0)
            vida = 0;
        setlocale(LC_ALL, "es_MX.UTF-8");
    }

    bool estaVivo() {
        return vida > 0;
setlocale(LC_ALL, "es_MX.UTF-8");
    }
};

// Función para simular una batalla Pokémon 1v1 con elección de Pokémon
void batallaPokemon1v1() {
    std::cout << "¡Comienza el dududu duelooo!" << std::endl;

    
    Pokemon pikachu("Pikachu", 50, 100);
    Pokemon charizard("Charizard", 60, 120);
    Pokemon blastoise("Blastoise", 55, 110);

    
    std::vector<Pokemon> pokemonsDisponibles;
    pokemonsDisponibles.push_back(pikachu);
    pokemonsDisponibles.push_back(charizard);
    pokemonsDisponibles.push_back(blastoise);

    // Elegir el Pokémon del jugador
    std::cout << "Elige tu Pokémon mi chavox:" << std::endl;
    for (int i = 0; i < pokemonsDisponibles.size(); i++) {
        std::cout << i + 1 << ". " << pokemonsDisponibles[i].getNombre() << std::endl;
    }

    int opcion;
    std::cin >> opcion;

    Pokemon pokemonJugador = pokemonsDisponibles[opcion - 1];
    std::cout << "Has elegido a " << pokemonJugador.getNombre() << " (nivel " << pokemonJugador.getNivel() << ")" << std::endl;
    std::cout << std::endl;
    srand(time(0));
    int indiceOponente = rand() % pokemonsDisponibles.size();
    Pokemon pokemonOponente = pokemonsDisponibles[indiceOponente];
    std::cout << "Tu oponente ha elegido a " << pokemonOponente.getNombre() << " (nivel " << pokemonOponente.getNivel() << ")" << std::endl;
    std::cout << std::endl;

    while (pokemonJugador.estaVivo() && pokemonOponente.estaVivo()) {
        // Turno del jugador
        std::cout << "Tu turno, elige una opción:" << std::endl;
        std::cout << "1. Atacar" << std::endl;
        std::cout << "2. Usar item" << std::endl;
        std::cout << "3. Huir" << std::endl;
        int opcion;
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            std::cout << "Elige un ataque:" << std::endl;
            std::cout << "1. Lanzallamas" << std::endl;
            std::cout << "2. Rayo solar" << std::endl;
            std::cout << "3. Pistola de agua" << std::endl;
            int ataque;
            std::cin >> ataque;

            int dano;
            if (ataque == 1)
                dano = 20;
            else if (ataque == 2)
                dano = 30;
            else if (ataque == 3)
                dano = 25;

            pokemonOponente.recibirAtaque(dano);
            std::cout << "¡Has causado " << dano << " de daño!" << std::endl;

            break;
        }
        case 2:
            std::cout << "Usaste un item. ¡Recuperaste 10 de vida!" << std::endl;
            pokemonJugador.recibirAtaque(-10);
            break;
        case 3:
            std::cout << "Has huido de la batalla." << std::endl;
            return;
        }

        // Turno del oponente
        if (pokemonOponente.estaVivo()) 
        {
            srand(time(0));
            int ataqueOponente = rand() % 2 + 1;

            int danoOponente;
            if (ataqueOponente == 1)
            {
                danoOponente = 15;
            }
            else if (ataqueOponente == 2)
            {
                danoOponente = 25;
            pokemonJugador.recibirAtaque(danoOponente);
            }
            std::cout << "¡El oponente te ha causado " << danoOponente << " de daño!" << std::endl;
        }

        std::cout << "Vida restante de " << pokemonJugador.getNombre() << ": " << pokemonJugador.getVida() << std::endl;
        std::cout << "Vida restante del oponente: " << pokemonOponente.getVida() << std::endl;
        std::cout << std::endl;
    }

    if (!pokemonJugador.estaVivo()) {
        std::cout << "¡Tu Pokémon ha sido derrotado!" << std::endl;
    }
    else {
        std::cout << "¡Has derrotado al sistema! ¡Ganaste la batalla pokemon!" << std::endl;
    }
}
int main() 
{
    batallaPokemon1v1();
    return 0;
}

