//
// Created by user on 6/14/2022.
//

#include "Dragon.h"
const std::string Dragon::DRAGON_NAME = "Dragon";

Card* Dragon::clone()
{
    return new Dragon(*this);
}
void Dragon::print(std::ostream& os)const
{
    bool isDragon= true;
    printCardDetails(os,DRAGON_NAME);
    printMonsterDetails(os,m_force,0,m_loot,isDragon);
    printEndOfCardDetails(os);
}
void Dragon::onWinBattle(Player& player)
{
    player.addCoins(m_loot);
    printWinBattle(player.getPlayerName(),DRAGON_NAME);
    player.levelUp();
}
void Dragon::onLossBattle(Player& player)
{
    player.killThePlayer();
    printLossBattle(player.getPlayerName(),DRAGON_NAME);
}
