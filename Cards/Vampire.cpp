//
// Created by Omar on 6/14/2022.
//

#include "Vampire.h"

Card* Vampire::clone()
{
    return new Vampire(*this);
}
void Vampire::print(std::ostream& os)const
{
    printCardDetails(os,"Vampire");
    printMonsterDetails(os,m_force,-m_hpDamage,m_loot);
    printEndOfCardDetails(os);
}
void Vampire::onWinBattle(Player& player)
{
    player.addCoins(m_loot);
    printWinBattle(player.getPlayerName(),"Vampire");
    player.levelUp();
}
void Vampire::onLossBattle(Player& player)
{
    player.setHp(m_hpDamage);
    printLossBattle(player.getPlayerName(),"Vampire");
}
