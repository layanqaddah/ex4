//
// Created by layan & omar on 6/9/2022.
//
#include "Wizard.h"

const std::string Wizard::WIZARD_CLASS_NAME="Wizard";

void Wizard::setHp(int hpQuantity)
{
    if (hpQuantity>0)
    {
        m_healthPoints+=WIZARD_HP_MULTIPLIER*hpQuantity;
    } else
    {
        m_healthPoints+=hpQuantity;
    }
    if(m_healthPoints<0)
    {
        m_healthPoints=0;
    }
    if (m_healthPoints>MAX_HP)
    {
        m_healthPoints= MAX_HP;
    }
}

Player* Wizard::clone()
{
    return new Wizard(*this);
}

void Wizard::print(std::ostream& os) const
{
    printPlayerDetails(os,m_name,WIZARD_CLASS_NAME,m_level,m_force,m_healthPoints,m_coins);
}
