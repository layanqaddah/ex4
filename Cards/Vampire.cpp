//
// Created by Omar on 6/14/2022.
//

#include "Vampire.h"

const std::string Vampire::VAMPIRE_NAME = "Vampire";

Card* Vampire::clone()
{
    return new Vampire(*this);
}
void Vampire::print(std::ostream& os)const
{
    printCardDetails(os,VAMPIRE_NAME);
    printMonsterDetails(os, m_force, -HP_DAMAGE, m_loot);
    printEndOfCardDetails(os);
}
void Vampire::onWinBattle(Player& player)
{
    player.addCoins(m_loot);
    printWinBattle(player.getPlayerName(),VAMPIRE_NAME);
    player.levelUp();
}
void Vampire::onLossBattle(Player& player)
{
    player.setHp(Vampire::HP_DAMAGE);
    player.setForce(Vampire::FORCE_DAMAGE);
    printLossBattle(player.getPlayerName(),VAMPIRE_NAME);
}