//
// Created by Layan & Omar on 6/14/2022.
//

#include "Battle.h"
bool Battle::battleResult(const Player& player)
{
    return (m_force<=player.getAttackStrength());
}
/*
void Battle::onWinBattle(Player& player)
{
    player.changeHp(m_loot);
    printWinBattle(player.getPlayerName(),);
}
*/
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
