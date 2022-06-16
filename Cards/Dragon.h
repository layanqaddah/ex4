//
// Created by user on 6/14/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"


class Dragon :public Battle{

public:

    Dragon(): Battle(DRAGON_FORCE,DRAGON_LOOT){};
    Dragon(const Dragon& otherDragon)=default;
    Dragon& operator=(const Dragon& otherDragon)=default;
    ~Dragon()=default;
    Card* clone() override;

protected:
        void print(std::ostream& os) const override;
        void onWinBattle(Player& player) override;
        void onLossBattle(Player& player)override;
private:
    static const int DRAGON_FORCE = 25;
    static const int DRAGON_LOOT = 1000;
    static const std::string DRAGON_NAME;

};


#endif //EX4_DRAGON_H
