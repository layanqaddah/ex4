//
// Created by user on 6/15/2022.
//

#include "Pitfall.h"
#include "../Players/Rogue.h"


Card*  Pitfall::clone()
{
    return  new Pitfall(*this);
}

void Pitfall::print(std::ostream& os) const
{
    printCardDetails(os,"Pitfall");
    printEndOfCardDetails(os);
}

void Pitfall::applyCard(Player& player)
{
    const Rogue* roguePtr = dynamic_cast<const Rogue*> (&player);
    bool isRogue = true;
    if(roguePtr==nullptr)
    {
        isRogue= false;
        player.setHp(m_hpDamage);
    }
    printPitfallMessage(isRogue);
}

