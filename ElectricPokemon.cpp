#include "ElectricPokemon.h"

ElectricPokemon::ElectricPokemon(string pokeName, int pokeHP, int pokeDamage) : Pokemon('e', pokeName, pokeHP, pokeDamage, 30, 3, true)
{
    electricPokemonRemainingConfusion = 0;
};


void ElectricPokemon::setPokemonIsConfused(bool tf)
{
    if (getPokemonIsOnOwnTerrain())
    {
        Pokemon::setPokemonIsConfused(false);
    }
    else
    {
        Pokemon::setPokemonIsConfused(tf);
    }
    if (tf)
    {
        setElectricPokemonRemainingConfusion(3);
    }
}


const float ElectricPokemon::getElectricPokemonPowerAttackMultiplier() const
{
    return this->electricPokemonPowerAttackMultiplier;
}


void ElectricPokemon::terrainCheck(string terrainType)
{
    if (terrainType == "electric")
    {
        this->setPokemonIsOnOwnTerrain(true);
        Pokemon::setPokemonIsConfused(false);
    }
    else
    {
        this->setPokemonIsOnOwnTerrain(false);
    }
}


void ElectricPokemon::performAttack(Pokemon *opponent)
{
    if (!getPokemonIsFainted())
    {
        if (getPokemonIsAbleToPowerUp() == false)
        {
            decreasePokemonPowerUpCooldown();
        }
        if (getPokemonIsConfused())
        {
            if (getElectricPokemonRemainingConfusion() > 0)
            {
                setElectricPokemonRemainingConfusion(getElectricPokemonRemainingConfusion() - 1);
            }
        }
        else
        {
            opponent->setPokemonHP(opponent->getPokemonHP() - getPokemonDamage());
        }
    }
}


void ElectricPokemon::performPowerAttack(Pokemon *opponent)
{
    if (!getPokemonIsFainted())
    {
        setPokemonIsAbleToPowerUp(false);
        setPokemonPowerUpCooldown(getPokemonRechargeRate());
        if (getPokemonIsConfused())
        {
            if (getElectricPokemonRemainingConfusion() > 0)
            {
                setElectricPokemonRemainingConfusion(getElectricPokemonRemainingConfusion() - 1);
            }
        }
        else
        {
            opponent->setPokemonHP(opponent->getPokemonHP() - (getPokemonDamage() * getElectricPokemonPowerAttackMultiplier() / 100));
        }
    }
}


void ElectricPokemon::setElectricPokemonRemainingConfusion(int remainingConfusion)
{
    this->electricPokemonRemainingConfusion = remainingConfusion;

    if (remainingConfusion == 0)
    {
        Pokemon::setPokemonIsConfused(false);
    }
}


int ElectricPokemon::getElectricPokemonRemainingConfusion() const
{
    return this->electricPokemonRemainingConfusion;
}