//
// Created by Omar on 15/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Battle.h"

class Vampire : public Battle
{
public:
    Vampire(): Battle(VAMPIRE_FORCE,VAMPIRE_LOOT){};
    Vampire(const Vampire& otherVampire)=default;
    Vampire& operator=(const Vampire& otherVampire)=default;
    ~Vampire()=default;
    Card* clone() override;

protected:
    void print(std::ostream& os) const override;
    void onWinBattle(Player& player) override;
    void onLossBattle(Player& player)override;

private:
    static const int VAMPIRE_FORCE = 10;
    static const int VAMPIRE_LOOT = 2;
    static const int HP_DAMAGE = -10;
    static const int FORCE_DAMAGE = -1;
    static const std::string VAMPIRE_NAME;
};


#endif //EX4_VAMPIRE_H
