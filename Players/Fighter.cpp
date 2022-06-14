//
// Created by Layan & Omar on 6/9/2022.
//
#include "Fighter.h"
int Fighter::getAttackStrength() const
{
    return m_level+2*m_force;
}
Player* Fighter::clone()
{
    return new Fighter(*this);
}

void Fighter::print(std::ostream& os) const
{
    printPlayerDetails(os,m_name,"Fighter",m_level,m_force,m_healthPoints,m_coins);
}
