//
// Created by user on 6/9/2022.
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H

#include "Player.h"

class Rogue: public Player
{
private:

public:
    Rogue(std::string name): Player(name){};
    Rogue(const Rogue& otherRogue)=default;
    Rogue& operator=(const Rogue& otherRogue)=default;
    ~Rogue()=default;
     Player* clone() override;
    void addCoins(int coins) override;

};
#endif //EX4_ROGUE_H