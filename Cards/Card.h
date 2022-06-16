//
// Created by user on 6/13/2022.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#include <iostream>
#include "../Players/Player.h"
#include "../utilities.h"

class Card
{
public:
    Card()=default;
    Card(const Card& otherCard)=default;
    Card& operator=(const Card& otherCard)=delete;
    friend std::ostream& operator<<(std::ostream& os,const Card& card);

    virtual ~Card()=default;
    virtual Card* clone()=0;

    virtual void applyCard(Player& player)=0;

protected:
    virtual void print(std::ostream& os) const = 0;
private:
};


#endif //EX4_CARD_H
