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
    Goblin(const Goblin& otherGoblin)=default;
    Goblin& operator=(const Goblin& otherGoblin)=default;
    ~Goblin()=default;
    Card* clone() override;

protected:
     void print(std::ostream& os) const override;
     void onWinBattle(Player& player) override;
     void onLossBattle(Player& player)override;
private:
    static const int GOBLIN_FORCE = 6;
    static const int GOBLIN_LOOT = 2;
    static const int HP_DAMAGE = -10;
    static const std::string GOBLIN_NAME;
};


#endif //EX4_GOBLIN_H
