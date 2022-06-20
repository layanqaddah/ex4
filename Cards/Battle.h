//
// Created by user on 6/14/2022.
//

#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#include "Card.h"

class Battle : public Card
{
public:
    Battle(int force,int loot):m_force(force),m_loot(loot){};
    Battle(const Battle& battle)=default;
    Battle& operator=(const Battle& battle)=delete;

    virtual ~Battle()=default;
    virtual Card* clone()=0;

     void applyCard(Player& player) override;
protected:
    const int m_force;
    const int m_loot;

    virtual void print(std::ostream& os) const = 0;

    virtual void onWinBattle(Player& player)=0;
    virtual void onLossBattle(Player& player)=0;

private:
    bool battleResult(const Player& player);
};


#endif //EX4_BATTLE_H
