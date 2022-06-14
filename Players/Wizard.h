//
// Created by layan & omar on 6/9/2022.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"
#include "../utilities.h"

class Wizard : public Player
{
public:
    Wizard(std::string name): Player(name){};
    Wizard(const Wizard& otherWizard)=default;
    Wizard& operator=(const Wizard& otherWizard)=default;
    ~Wizard()=default;
    Player* clone() override;
    void changeHp(int hpQuantity) override;

protected:
    void print(std::ostream& os) const override;

private:
};

#endif //EX4_WIZARD_H
