#pragma once
#include "Pokemon.h"

class PsychicPokemon : public Pokemon {
    /*
    No attributes are private I thought there is no need
    since my implementation required no attributes inside psychic
    */
    public:
    //Electric Pokemon Constructor calling the Base Pokemon constructor first
    PsychicPokemon(string pokeName, int pokeHP,int pokeDamage);
    //Attack methods below
    void performAttack(Pokemon* opponent) override;
    void performPowerAttack(Pokemon* opponent) override;
    //Confuse opponent
    void confuseOpponent(Pokemon* opponent);
    //Check terrain
    void terrainCheck(string terrainType) override;

};
