//
// Created by assur on 15/06/2022.
//

#include "Merchant.h"


Card* Merchant::clone()
{
    return  new Merchant(*this);
}

void Merchant::print(std::ostream& os) const
{
    printCardDetails(os,"Merchant");
}

bool Merchant::isValidBuyOption(int buyDecision) const
{
    return buyDecision==m_hpBoostOption || buyDecision==m_forceBoostOption || buyDecision==m_dealBreakOption;
}


void Merchant::applyCard(Player& player)
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getPlayerName(), player.getCoins());
    int buyDecision = -1;
    bool playerHasEnoughMoney=false;
    while(scanf("%d",&buyDecision)!=1 || !isValidBuyOption(buyDecision))
    {
        printInvalidInput();
    }
    switch (buyDecision)
    {
        case m_hpBoostOption:
            playerHasEnoughMoney = player.pay(m_hpBoostCost);
            if(playerHasEnoughMoney)
            {
                player.changeHp(m_hpBoost);
                printMerchantSummary(std::cout, player.getPlayerName(), m_hpBoostOption, m_hpBoostCost);
            }
            else
            {
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        case m_forceBoostOption:
            playerHasEnoughMoney = player.pay(m_forceBoostCost);
            if(playerHasEnoughMoney)
            {
                player.changeForce(m_forceBoost);
                printMerchantSummary(std::cout, player.getPlayerName(), m_forceBoostOption, m_forceBoostCost);
            }
            else
            {
                printMerchantInsufficientCoins(std::cout);
            }
            break;
        case m_dealBreakOption:
            printMerchantSummary(std::cout, player.getPlayerName(), 0, 0);
            break;
        default:
            break;
    }
}