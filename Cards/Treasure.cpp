//
// Created by layan on 6/14/2022.
//

#include "Treasure.h"

#include "Card.h"

Card* Treasure::clone()
{
    return  new Treasure(*this);
}

void Treasure::print(std::ostream& os) const
{
    printCardDetails(os,"Treasure");
    printEndOfCardDetails(os);
}

void Treasure::applyCard(Player& player)
{
    player.addCoins(m_loot);
    printTreasureMessage();
}
