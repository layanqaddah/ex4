//
// Created by Layan & Omar on 13/06/2022.
//

#include "Card.h"

std::ostream& operator<<(std::ostream& os,const Card& card)
{
    card.print(os);
    return os;
}
