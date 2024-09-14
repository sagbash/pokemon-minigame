#include "PsychicPokemon.h"

PsychicPokemon::PsychicPokemon(string pokeName, int pokeHP, int pokeDamage) : Pokemon('e', pokeName, pokeHP, pokeDamage, 30, 5, false){};


void PsychicPokemon::performAttack(Pokemon *opponent)
{
    if (!getPokemonIsFainted())
    {
        if (getPokemonIsAbleToPowerUp() == false)
        {
            decreasePokemonPowerUpCooldown();
        }
        if (getPokemonIsOnOwnTerrain())
        {
            opponent->setPokemonHP(opponent->getPokemonHP() - getPokemonDamage() * 2);
        }
        else
        {
            opponent->setPokemonHP(opponent->getPokemonHP() - getPokemonDamage());
        }
    }
}


void PsychicPokemon::performPowerAttack(Pokemon *opponent)
{
    if (!getPokemonIsFainted())
    {
        setPokemonIsAbleToPowerUp(false);
        setPokemonPowerUpCooldown(getPokemonRechargeRate());
        if (getPokemonIsOnOwnTerrain())
        {
            opponent->setPokemonHP(opponent->getPokemonHP() - getPokemonDamage() * 2);
        }
        else
        {
            opponent->setPokemonHP(opponent->getPokemonHP() - getPokemonDamage());
        }
        if (opponent->getPokemonIsProneToConfusion())
        {
            confuseOpponent(opponent);
        }
    }
}


void PsychicPokemon::terrainCheck(string terrainType)
{
    if (terrainType == "psychic")
    {
        setPokemonIsOnOwnTerrain(true);
    }
    else
    {
        setPokemonIsOnOwnTerrain(false);
    }
}


void PsychicPokemon::confuseOpponent(Pokemon *opponent)
{
    opponent->setPokemonIsConfused(true);
}