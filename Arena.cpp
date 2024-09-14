#include "Arena.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
void Arena::addPokemon(char type, string name, int hp, int damage)
{
    switch (type)
    {
    case 'e':
        m_fighter1 = new ElectricPokemon(name, hp, damage);
        cout << "Electric Pokemon " << name << " has entered the arena." << endl;
        cout << "Class: Electric" << endl;
        break;
    case 'p':
        m_fighter2 = new PsychicPokemon(name, hp, damage);
        cout << "Psychic Pokemon " << name << " has entered the arena." << endl;
        cout << "Class: Psychic" << endl;
        break;
    default:
        cout << "Unrecognized type" << endl;
        break;
    }
    cout << "        Name: " << name << endl;
    cout << "        HP: " << hp << endl;
    cout << "        Damage: " << damage << "\n\n"<< endl;
}

void Arena::simulateBattle()
{
    int whoGoesFirst;
    int roundCounter = 1;
    while (!m_fighter1->getPokemonIsFainted() && !m_fighter2->getPokemonIsFainted())
    {
        spawnTerrain();
        m_fighter1->terrainCheck(m_terrainType);
        m_fighter2->terrainCheck(m_terrainType);
        whoGoesFirst = (random() % 2 + 1);
        if (whoGoesFirst == 1)
        {
            fighterAttack(m_fighter1, m_fighter2);
            if (!(m_fighter2->getPokemonIsFainted()))
                fighterAttack(m_fighter2, m_fighter1);
        }
        else
        {
            fighterAttack(m_fighter2, m_fighter1);
            if (!(m_fighter1->getPokemonIsFainted()))
                fighterAttack(m_fighter1, m_fighter2);
        }
        printRoundStats(roundCounter, whoGoesFirst);
        roundCounter++;
        setRemainingTerrainLife(getRemainingTerrainLife() - 1);

        if (m_fighter1->getPokemonHP() <= 0 || m_fighter2->getPokemonHP() <= 0)
        {
            if (m_fighter1->getPokemonHP() <= 0)
                m_fighter1->setPokemonIsFainted(true);
            if (m_fighter2->getPokemonHP() <= 0)
                m_fighter2->setPokemonIsFainted(true);
        }
    }
    printMatchResults();
    removeFighters();
}
void Arena::fighterAttack(Pokemon *self, Pokemon *opponent)
{
    if (self->getPokemonIsAbleToPowerUp())
    {
        // cout << self->getPokemonName() << " Pokemon is Able to PowerUp True" << endl;
        int randomPowerUp = random() % 100 + 1;
        if (randomPowerUp <= self->getPokemonPowerUpChance())
        {
            self->performPowerAttack(opponent);
            // cout << "Performed power attack" << endl;
        }
        else
        {
            self->performAttack(opponent);
        }
    }
    else
    {
        self->performAttack(opponent);
    }
}
void Arena::removeFighters()
{
    delete m_fighter1;
    delete m_fighter2;
    restartTerrain();
}

int Arena::getRemainingTerrainLife()
{
    return m_remainingTerrainLife;
}
void Arena::setRemainingTerrainLife(int terrainLife)
{
    m_remainingTerrainLife = terrainLife;
}

string Arena::getTerrainType()
{
    return m_terrainType;
}

void Arena::setTerrainType(string terrainType)
{
    this->m_terrainType = terrainType;
}

void Arena::spawnTerrain()
{
    if (m_remainingTerrainLife == 0)
    {
        int x = random() % 10 + 1;
        if (x <= 2)
        {
            setTerrainType("electric");
            setRemainingTerrainLife(5);
        }
        else if (x <= 4)
        {
            setTerrainType("psychic");
            setRemainingTerrainLife(5);
        }
        else
        {
            setTerrainType("none");
            setRemainingTerrainLife(1);
        }
    }
}
void Arena::restartTerrain()
{
    setRemainingTerrainLife(0);
}

void Arena::printRoundStats(int round, int heads)
{
    cout << "Round: " << round << endl;
    cout << "Current Terrain: " << getTerrainType() << endl;

    cout << ((heads == 1) ? m_fighter1->getPokemonName() : m_fighter2->getPokemonName()) << " goes first." << endl;
    if (m_fighter1->getPokemonPowerUpCooldown() == m_fighter1->getPokemonRechargeRate())
    {
        // cout << fighter1->getPokemonName() << " pokemon cooldown is " << fighter1->getPokemonPowerUpCooldown() << endl;
        // cout << fighter1->getPokemonName() << " pokemon Recharge rate is " << fighter1->getPokemonRechargeRate() << endl;
        cout << m_fighter1->getPokemonName() << " has initiated a power up." << endl;
    }

    if (m_fighter2->getPokemonPowerUpCooldown() == m_fighter2->getPokemonRechargeRate())
    {
        // cout << fighter2->getPokemonName() << " pokemon cooldown is " << fighter2->getPokemonPowerUpCooldown() << endl;
        // cout << fighter2->getPokemonName() << " pokemon Recharge rate is " << fighter2->getPokemonRechargeRate() << endl;

        cout << m_fighter2->getPokemonName() << " has initiated a power up." << endl;
    }
    cout << m_fighter1->getPokemonName() << " HP: " << m_fighter1->getPokemonHP() << endl;
    cout << m_fighter2->getPokemonName() << " HP: " << m_fighter2->getPokemonHP() << endl;
    if (m_fighter1->getPokemonHP() > m_fighter2->getPokemonHP())
    {
        cout << m_fighter1->getPokemonName() << " is in the lead!\n\n"
             << endl;
    }
    else if (m_fighter2->getPokemonHP() > m_fighter1->getPokemonHP())
    {
        cout << m_fighter2->getPokemonName() << " is in the lead!\n\n"
             << endl;
    }
    else
    {
        cout << "The match is currently a tie!\n\n"
             << endl;
    }
}

void Arena::printMatchResults()
{
    cout << "Match Results: " << endl;
    cout << ((m_fighter1->getPokemonIsFainted()) ? m_fighter2->getPokemonName() : m_fighter1->getPokemonName()) << " has won the match!\n\n"
         << endl;
}
