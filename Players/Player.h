//
// Created by user on 6/9/2022.
//

#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string>
#include <iostream>

class  Player
{
public:


    Player(std::string name):m_level(INITIAL_LEVEL),m_force(INITIAL_FORCE),
    m_healthPoints(MAX_HP) ,m_coins(INITIAL_COINS) , m_name(name){};

    Player():m_level(INITIAL_LEVEL),m_force(INITIAL_FORCE),
    m_healthPoints(MAX_HP) ,m_coins(INITIAL_COINS), m_name(nullptr){};

    Player(const Player& otherPlayer)=default;
    Player& operator=(const Player& otherPlayer)=default;
    friend std::ostream& operator<<(std::ostream& os,Player& player);

    virtual ~Player()=default;
    virtual Player* clone()=0;

    void levelUp();
    int getLevel() const;
    void buff(int force);
    void damage(int hpDamage);
    bool isKnockedOut() const;
    bool pay(int payment);
    virtual void heal(int hpBoost);
    virtual void addCoins(int coins);
    virtual int getAttackStrength() const;

protected:
    int m_level ;
    int m_force;
    int m_healthPoints;
    int m_coins;
    static const int MAX_HP=100;

private:
    static const int INITIAL_LEVEL=1;
    static const int INITIAL_FORCE=5;
    static const int INITIAL_COINS=10;
    static const int FINAL_LEVEL=10;

     std::string m_name;
};

std::ostream& operator<<(std::ostream& os,Player& player)
{
}

#endif //EX4_PLAYER_H
