//
// Created by Layan & omar on 6/9/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include "Player.h"
#include "../utilities.h"

class Fighter : public Player
{
public:
    Fighter(std::string name): Player(name){};
    Fighter(const Fighter& otherWizard)=default;
    Fighter& operator=(const Fighter& otherWizard)=default;

    ~Fighter()=default;
    Player* clone() override;
    int getAttackStrength() const override;

protected:
    void print(std::ostream& os) const override;

private:
    static const int FIGHTER_FORCE_MULTIPLIER=2;
    static const std::string FIGHTER_CLASS_NAME;
};
#endif //EX4_FIGHTER_H