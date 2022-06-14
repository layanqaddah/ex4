//
// Created by user on 6/14/2022.
//

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H
#include "Battle.h"

class Goblin: public Battle
{
public:

    Goblin(): Battle(6,2){};
    Goblin(const Goblin& otherWizard)=default;
    Goblin& operator=(const Goblin& otherWizard)=default;
    ~Goblin()=default;
    Card* clone() override;

protected:
     void print(std::ostream& os) const override;
     void onWinBattle(Player& player) override;
     void onLossBattle(Player& player)override;
private:
   static const int m_hpDamage = -10;
};


#endif //EX4_GOBLIN_H
