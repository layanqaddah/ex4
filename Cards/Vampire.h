//
// Created by Omar on 15/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H
#include "Battle.h"

class Vampire : public Battle
{
public:
    Vampire(): Battle(10,2){};
    Vampire(const Vampire& otherVampire)=default;
    Vampire& operator=(const Vampire& otherVampire)=default;
    ~Vampire()=default;
    Card* clone() override;

protected:
    void print(std::ostream& os) const override;
    void onWinBattle(Player& player) override;
    void onLossBattle(Player& player)override;

private:
    static const int m_hpDamage = -10;
};


#endif //EX4_VAMPIRE_H
