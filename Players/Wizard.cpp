//
// Created by user on 6/9/2022.
//
#include "Wizard.h"
void Wizard::heal(int hpBoost)
{
    if (hpBoost<=0)
    {
        return;
    }
    m_healthPoints+=2*hpBoost;
    if (m_healthPoints>MAX_HP)
    {
        m_healthPoints= MAX_HP;
    }
}
Player* Wizard::clone()
{
    return new Wizard(*this);
}

