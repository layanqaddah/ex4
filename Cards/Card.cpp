//
// Created by user on 6/13/2022.
//

#include "Card.h"
std::ostream& operator<<(std::ostream& os,const Card& card)
{
    card.print(os);
    return os;
}
