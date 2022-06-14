//
// Created by user on 6/14/2022.
//

#include "Barfight.h"
#include "../Players/Fighter.h"


Card* Barfight::clone()
{
    return  new Barfight(*this);
}

void Barfight::print(std::ostream& os) const
{
    printCardDetails(os,"Barfight");
}

void Barfight::applyCard(Player& player)
{
    const Fighter* fighterPtr = dynamic_cast<const Fighter*> (&player);
    bool isFighter= true;
    if(fighterPtr==nullptr)
    {
        isFighter= false;
        player.changeHp(m_hpDamage);
    }
    printBarfightMessage(isFighter);
}
