#include <iostream>
#include "Pokemon.h"
#include "ElectricPokemon.h"
#include "PsychicPokemon.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Pokemon *ElectricPokemon1 = new ElectricPokemon("Pikachu", 150, 20);
    Pokemon *PsychicPokemon1 = new PsychicPokemon("Abra", 120, 10);
    cout << "Electric Pokemon's Name: " << ElectricPokemon1->getPokemonName() << endl;
    cout << "Psychic Pokemon's Name: " << PsychicPokemon1->getPokemonName() << endl;
    ElectricPokemon1->performAttack(PsychicPokemon1);
    PsychicPokemon1->performAttack(ElectricPokemon1);
    cout << "Electric Pokemon's HP: " << ElectricPokemon1->getPokemonHP() << endl;
    cout << "Psychic Pokemon's HP: " << PsychicPokemon1->getPokemonHP() << endl;
    PsychicPokemon1->performPowerAttack(ElectricPokemon1);
    ElectricPokemon1->performPowerAttack(PsychicPokemon1);
    ElectricPokemon1->performPowerAttack(PsychicPokemon1);
    ElectricPokemon1->performPowerAttack(PsychicPokemon1);

    cout << "Electric Pokemon's HP: " << ElectricPokemon1->getPokemonHP() << endl;
    cout << "Psychic Pokemon's HP: " << PsychicPokemon1->getPokemonHP() << endl;
    delete ElectricPokemon1;
    delete PsychicPokemon1;
    return 0;
}