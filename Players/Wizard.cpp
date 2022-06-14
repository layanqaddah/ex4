//
// Created by layan & omar on 6/9/2022.
//
#include "Wizard.h"
void Wizard::changeHp(int hpQuantity)
{
    if (hpQuantity>0)
    {
        m_healthPoints+=2*hpQuantity;
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
    printPlayerDetails(os,m_name,"Wizard",m_level,m_force,m_healthPoints,m_coins);
}

