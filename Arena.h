#pragma once
#include "Pokemon.h"
#include "ElectricPokemon.h"
#include "PsychicPokemon.h"
class Arena {
    public:
    Arena() {
        m_fighter1 = nullptr;
        m_fighter2 = nullptr;
        m_remainingTerrainLife = 0;
    }
    //adds pokemons
    void addPokemon(char type,string name,int hp,int damage);
    //deletes pokemons and calls restartTerrain
    void removeFighters();
    //simulates the battle
    void simulateBattle();
    //spawns terrains
    void spawnTerrain();
    //Gets the terrain type
    //This method is used to give terrain parameter to pokemons checkTerrain method
    string getTerrainType();
    void setTerrainType(string terrainType);
    //The attack function which calls pokemons performAttack and performPowerAttack
    void fighterAttack(Pokemon* self,Pokemon* opponent);
    //restarts terrain
    void restartTerrain();
    //getter setters
    int getRemainingTerrainLife();
    void setRemainingTerrainLife(int terrainLife);
    //prints round stats
    void printRoundStats(int round,int heads);
    //prints match results
    void printMatchResults();
    private:
    int m_remainingTerrainLife;
    string m_terrainType;
    Pokemon* m_fighter1;
    Pokemon* m_fighter2;

};