//
// Created by layan on 6/9/2022.
//
#include "Player.h"
/*
Player* Player::clone()
{
    return new Player(*this);
}
*/
void Player::levelUp()
{
    m_level += (m_level == FINAL_LEVEL) ? 0 : 1;
}

int Player::getLevel()const
{
    return m_level;
}
void Player::buff(int force)
{
    if(force<0)
    {
        return;
    }
    m_force+=force;
}

void Player::damage(int hpDamage)
{
    if(hpDamage<=0)
    {
        return;
    }
    m_healthPoints-=hpDamage;
    if(m_healthPoints<0)
    {
        m_healthPoints=0;
    }
}

bool Player::isKnockedOut()const
{
    if (m_healthPoints==0)
    {
        return  true;
    }
    return false;
}

bool Player::pay(int payment)
{
    if(payment<=0)
    {
        return true ;
    }
    if (m_coins>=payment)
    {
        m_coins-=payment;
        return true;
    }
    return false;
}

void Player::addCoins(int coins)
{
    if (coins<=0)
    {
        return;
    }
    m_coins+=coins;
}


void Player::heal(int hpBoost)
{
    if (hpBoost<=0)
    {
        return;
    }
    m_healthPoints+=hpBoost;
    if (m_healthPoints>MAX_HP)
    {
        m_healthPoints= MAX_HP;
    }
}

int Player::getAttackStrength() const
{
    return m_level+m_force;
}
