//
// Created by Layan & Omar on 14/06/2022.
//

#include "Fairy.h"
#include "../Players/Wizard.h"

const std::string Fairy::FAIRY_NAME = "Fairy";

Card* Fairy::clone()
{
    return  new Fairy(*this);
}

void Fairy::print(std::ostream& os) const
{
    printCardDetails(os,FAIRY_NAME);
    printEndOfCardDetails(os);
}

void Fairy::applyCard(Player& player)
{
    const Wizard* wizardPtr = dynamic_cast<const Wizard*> (&player);
    bool isWizard= false;
    if(wizardPtr!=nullptr)
    {
        isWizard= true;
        player.setHp(HP_BOOST);
    }
    printFairyMessage(isWizard);
}
