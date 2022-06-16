//
// Created by Layan & Omar on 6/9/2022.
//
#include "Rogue.h"

const std::string Rogue::ROGUE_CLASS_NAME="Rogue";

void Rogue::addCoins(int coins)
{
    if (coins <= 0) {
        return;
    }
    m_coins += ROGUE_COINS_MULTIPLIER * coins;
}
Player* Rogue::clone()
{
    return new Rogue(*this);
}


void Rogue::print(std::ostream& os) const
{
    printPlayerDetails(os,m_name,ROGUE_CLASS_NAME,m_level,m_force,m_healthPoints,m_coins);
}