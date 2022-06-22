//
// Created by Layan & Omar on 14/06/2022.
//

#include "Barfight.h"
#include "../Players/Fighter.h"

const std::string Barfight::BARFIGHT_NAME = "Barfight";

Card* Barfight::clone()
{
    return  new Barfight(*this);
}

void Barfight::print(std::ostream& os) const
{
    printCardDetails(os,BARFIGHT_NAME);
    printEndOfCardDetails(os);
}

void Barfight::applyCard(Player& player)
{
    const Fighter* fighterPtr = dynamic_cast<const Fighter*> (&player);
    bool isFighter= true;
    if(fighterPtr==nullptr)
    {
        isFighter= false;
        player.setHp(HP_DAMAGE);
    }
    printBarfightMessage(isFighter);
}
