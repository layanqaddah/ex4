//
// Created by Omar on 15/06/2022.
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

void Merchant::readInput(int *buyDecision) const
{
    std::string input;
    std::getline(std::cin,input);
    try
    {
        *buyDecision = std::stoi(input);
    }
    catch(std::invalid_argument)
    {
        *buyDecision = -1;
    }
}

void Merchant::applyCard(Player& player)
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getPlayerName(), player.getCoins());
    int buyDecision = -1;
    bool playerHasEnoughMoney=false;
    readInput(&buyDecision);
    while(!isValidBuyOption(buyDecision))
    {
        printInvalidInput();
        readInput(&buyDecision);
    }
    switch (buyDecision)
    {
        case m_hpBoostOption:
            playerHasEnoughMoney = player.pay(m_hpBoostCost);
            if(playerHasEnoughMoney)
            {
                player.setHp(m_hpBoost);
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
                player.setForce(m_forceBoost);
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
