//
// Created by Layan & Omar on 6/9/2022.
//
#include "Fighter.h"

const std::string Fighter::FIGHTER_CLASS_NAME="Fighter";

int Fighter::getAttackStrength() const
{
    return m_level+FIGHTER_FORCE_MULTIPLIER*m_force;
}
Player* Fighter::clone()
{
    return new Fighter(*this);
}

void Fighter::print(std::ostream& os) const
{
    printPlayerDetails(os,m_name,FIGHTER_CLASS_NAME,m_level,m_force,m_healthPoints,m_coins);
}