//
// Created by user on 6/9/2022.
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
