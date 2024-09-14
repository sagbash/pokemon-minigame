#include "Pokemon.h"


Pokemon::Pokemon(char pokeType, string pokeName, int pokeHP, int pokeDamage, float pokePowerUpChance, int pokeRechargeRate, bool pokeIsProneToConfusion) : m_pokemonType(pokeType), m_pokemonName(pokeName), m_pokemonHP(pokeHP), m_pokemonDamage(pokeDamage), m_pokemonPowerUpChance(pokePowerUpChance), m_pokemonPowerUpRechargeRate(pokeRechargeRate), m_pokemonIsProneToConfusion(pokeIsProneToConfusion)
{
    this->m_pokemonIsFainted = false;
    this->m_pokemonIsAbleToPowerUp = true;
    this->m_pokemonIsOnOwnTerrain = false;
    this->m_pokemonIsConfused = false;
    this->m_pokemonPowerUpCooldown = 0;
}
const char Pokemon::getPokemonType() const
{
    return this->m_pokemonType;
}

const string Pokemon::getPokemonName() const
{
    return this->m_pokemonName;
}

int Pokemon::getPokemonHP() const
{
    return this->m_pokemonHP;
}

const int Pokemon::getPokemonDamage() const
{
    return this->m_pokemonDamage;
}

const float Pokemon::getPokemonPowerUpChance() const
{
    return this->m_pokemonPowerUpChance;
}

int Pokemon::getPokemonPowerUpCooldown() const
{
    return this->m_pokemonPowerUpCooldown;
}

void Pokemon::decreasePokemonPowerUpCooldown()
{
    if (getPokemonPowerUpCooldown() > 0)
    {
        setPokemonPowerUpCooldown(getPokemonPowerUpCooldown() - 1);
        if (getPokemonPowerUpCooldown() == 0)
        {
            setPokemonIsAbleToPowerUp(true);
        }
    }
}

void Pokemon::setPokemonPowerUpCooldown(int cooldown)
{
    this->m_pokemonPowerUpCooldown = cooldown;
}

const int Pokemon::getPokemonRechargeRate() const
{
    return this->m_pokemonPowerUpRechargeRate;
}

bool Pokemon::getPokemonIsFainted() const
{
    return this->m_pokemonIsFainted;
}
void Pokemon::setPokemonIsFainted(bool tf)
{
    this->m_pokemonIsFainted = tf;
}
const bool Pokemon::getPokemonIsProneToConfusion() const
{
    return this->m_pokemonIsProneToConfusion;
}
void Pokemon::setPokemonIsConfused(bool tf)
{
    this->m_pokemonIsConfused = tf;
}

bool Pokemon::getPokemonIsConfused() const
{
    return this->m_pokemonIsConfused;
}
bool Pokemon::getPokemonIsAbleToPowerUp() const
{
    return this->m_pokemonIsAbleToPowerUp;
}
bool Pokemon::setPokemonIsAbleToPowerUp(bool tf)
{
    this->m_pokemonIsAbleToPowerUp = tf;
}

bool Pokemon::getPokemonIsOnOwnTerrain() const
{
    return this->m_pokemonIsOnOwnTerrain;
}
void Pokemon::setPokemonIsOnOwnTerrain(bool tf)
{
    this->m_pokemonIsOnOwnTerrain = tf;
}

int Pokemon::setPokemonHP(int setHP)
{
    (setHP < 0) ? this->m_pokemonHP = 0 : this->m_pokemonHP = setHP;
}

Pokemon::~Pokemon()
{
}