#pragma once
#include <string>
using std::string;

class Pokemon
{
private:
    const char m_pokemonType;
    const string m_pokemonName;
    int m_pokemonHP;
    const int m_pokemonDamage;
    const float m_pokemonPowerUpChance;
    int m_pokemonPowerUpCooldown;
    const int m_pokemonPowerUpRechargeRate;
    bool m_pokemonIsAbleToPowerUp;
    bool m_pokemonIsFainted;
    bool m_pokemonIsOnOwnTerrain;
    const bool m_pokemonIsProneToConfusion;
    bool m_pokemonIsConfused;

public:
    // constructor
    Pokemon(char pokeType, string pokeName, int pokeHP, int pokeDamage, float pokePowerUpChance, int pokeRechargeRate, bool pokeIsProneToConfusion);
    // getters and setters. Method names are pretty explicit
    const char getPokemonType() const;
    const string getPokemonName() const;
    int getPokemonHP() const;
    int setPokemonHP(int setHP);
    const int getPokemonDamage() const;
    const float getPokemonPowerUpChance() const;
    const int getPokemonRechargeRate() const;
    bool getPokemonIsFainted() const;
    void setPokemonIsFainted(bool tf);
    bool getPokemonIsAbleToPowerUp() const;
    bool setPokemonIsAbleToPowerUp(bool tf);
    bool getPokemonIsOnOwnTerrain() const;
    void setPokemonIsOnOwnTerrain(bool tf);
    const bool getPokemonIsProneToConfusion() const;
    bool getPokemonIsConfused() const;
    int getPokemonPowerUpCooldown() const;
    void decreasePokemonPowerUpCooldown();
    void setPokemonPowerUpCooldown(int cooldown);
    // Every pokemon is terrainchecking or power attacking or attacking so those methods are pure virtual
    // I considered this to be the correct way to do it
    virtual void performAttack(Pokemon *opponent) = 0;
    virtual void performPowerAttack(Pokemon *opponent) = 0;
    virtual void terrainCheck(string terrainType) = 0;
    // set pokemon confused should exist because inside PsychicPokemon::confuseOpponent we use this method so I can't write that method do ElectricPokemon only
    virtual void setPokemonIsConfused(bool tf);
    //destructor in order to destroy subobjects because of virtual methods
    ~Pokemon();
};
