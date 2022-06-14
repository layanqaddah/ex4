//
// Created by Layan & Omar on 6/14/2022.
//

#include "Goblin.h"

Card* Goblin::clone()
{
    return new Goblin(*this);
}
void Goblin::print(std::ostream& os)const
{
    printCardDetails(os,"Goblin");
    printMonsterDetails(os,m_force,-m_hpDamage,m_loot);
    printEndOfCardDetails(os);
}
void Goblin::onWinBattle(Player& player)
{
    player.addCoins(m_loot);
    printWinBattle(player.getPlayerName(),"Goblin");
    player.levelUp();
}
void Goblin::onLossBattle(Player& player)
{
    player.changeHp(m_hpDamage);
    printLossBattle(player.getPlayerName(),"Goblin");
}
