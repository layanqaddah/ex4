//
// Created by user on 6/14/2022.
//

#include "Fairy.h"
#include "../Players/Wizard.h"

Card* Fairy::clone()
{
    return  new Fairy(*this);
}

void Fairy::print(std::ostream& os) const
{
    printCardDetails(os,"Fairy");
    printEndOfCardDetails(os);
}

void Fairy::applyCard(Player& player)
{
    const Wizard* wizardPtr = dynamic_cast<const Wizard*> (&player);
    bool isWizard= false;
    if(wizardPtr!= nullptr);
    {
        isWizard= true;
        player.setHp(m_hpBoost);
    }
    printFairyMessage(isWizard);
}
