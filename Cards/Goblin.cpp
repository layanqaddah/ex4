//
// Created by layan&omar on 6/14/2022.
//

#include "Goblin.h"
const std::string Goblin::GOBLIN_NAME = "Goblin";

Card* Goblin::clone()
{
    return new Goblin(*this);
}
void Goblin::print(std::ostream& os)const
{
    printCardDetails(os,GOBLIN_NAME);
    printMonsterDetails(os,m_force,-HP_DAMAGE,m_loot);
    printEndOfCardDetails(os);
}
void Goblin::onWinBattle(Player& player)
{
    player.addCoins(m_loot);
    printWinBattle(player.getPlayerName(),GOBLIN_NAME);
    player.levelUp();
}
void Goblin::onLossBattle(Player& player)
{
    player.setHp(HP_DAMAGE);
    printLossBattle(player.getPlayerName(),GOBLIN_NAME);
}