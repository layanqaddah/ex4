//
// Created by user on 6/9/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H
#include "Player.h"
class Fighter : public Player
{
public:
    Fighter(std::string name): Player(name){};
    Fighter(const Fighter& otherWizard)=default;
    Fighter& operator=(const Fighter& otherWizard)=default;
    ~Fighter()=default;
    Player* clone() override;
    int getAttackStrength() const override;
private:
};
#endif //EX4_FIGHTER_H
