//
// Created by layan & omar on 6/9/2022.
//

#include "Player.h"

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    player.print(os);
    return os;
}


void Player::levelUp()
{
    m_level += (m_level == FINAL_LEVEL) ? 0 : 1;
}

int Player::getLevel()const
{
    return m_level;
}

int Player::getCoins()
{
    return m_coins;
}

void Player::changeForce(int forceQuantity)
{
    m_force+=forceQuantity;
    if(m_force<0)
    {
        m_force=0;
    }
}
void Player::changeHp(int hpQuantity)
{
    m_healthPoints+=hpQuantity;
    if(m_healthPoints<0)
    {
        m_healthPoints=0;
    }
    if (m_healthPoints>MAX_HP)
    {
        m_healthPoints= MAX_HP;
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

void Player::killThePlayer()
{
    m_healthPoints=0;
}
std::string Player::getPlayerName()
{
    return m_name;
}
bool Player::pay(int payment)
{
    if(payment<=0)
    {
        return true;
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


int Player::getAttackStrength() const
{
    return m_level+m_force;
}
