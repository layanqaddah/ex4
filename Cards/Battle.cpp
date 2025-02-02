//
// Created by user on 6/14/2022.
//

#include "Battle.h"

bool Battle::battleResult(const Player& player)
{
    return (m_force<=player.getAttackStrength());
}

void Battle::applyCard(Player& player)
{
    if(battleResult(player))
    {
        onWinBattle(player);
    }
    else
    {
        onLossBattle(player);
    }
}