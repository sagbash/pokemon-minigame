#pragma once
#include "Pokemon.h"

class ElectricPokemon : public Pokemon
{
private:
    bool electricPokemonRemainingConfusion;
    const float electricPokemonPowerAttackMultiplier = 300.0;

public:
    //Electric Pokemon Constructor calling the Base Pokemon constructor first
    ElectricPokemon(string pokeName, int pokeHP, int pokeDamage);
    //Attack methods below
    void performAttack(Pokemon *opponent) override;
    void performPowerAttack(Pokemon *opponent) override;
    //Overriden function in order to set pokemon confusion in relation to terrain
    void setPokemonIsConfused(bool tf) override;
    //Checks terrain
    void terrainCheck(string terrainType) override;
    const float getElectricPokemonPowerAttackMultiplier() const;
    //Get and set electric pokemon's confusion (int)
    void setElectricPokemonRemainingConfusion(int remainingConfusion);
    int getElectricPokemonRemainingConfusion() const;
};