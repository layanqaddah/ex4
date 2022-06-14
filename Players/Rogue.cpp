//
// Created by user on 6/9/2022.
//
#include "Rogue.h"
void Rogue::addCoins(int coins)
{
    if (coins <= 0) {
        return;
    }
    m_coins += 2 * coins;
}
Player* Rogue::clone()
{
    return new Rogue(*this);
}


void Rogue::print(std::ostream& os) const
{
    printPlayerDetails(os,m_name,"Rogue",m_level,m_force,m_healthPoints,m_coins);
}
