 //
// Created by user on 6/14/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"


class Dragon :public Battle{

public:

    Dragon(): Battle(25,1000){};
    Dragon(const Dragon& otherWizard)=default;
    Dragon& operator=(const Dragon& otherWizard)=default;
    ~Dragon()=default;
    Card* clone() override;

protected:
        void print(std::ostream& os) const override;
        void onWinBattle(Player& player) override;
        void onLossBattle(Player& player)override;
private:


};


#endif //EX4_DRAGON_H
