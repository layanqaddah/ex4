//
// Created by Layan & Omar on 6/14/2022.
//

#include "Treasure.h"

#include "Card.h"
const std::string Treasure::TREASURE_NAME= "Treasure";

Card* Treasure::clone()
{
    return  new Treasure(*this);
}

void Treasure::print(std::ostream& os) const
{
    printCardDetails(os,TREASURE_NAME);
    printEndOfCardDetails(os);
}

void Treasure::applyCard(Player& player)
{
    player.addCoins(TREASURE_LOOT);
    printTreasureMessage();
}