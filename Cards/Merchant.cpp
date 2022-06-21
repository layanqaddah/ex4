//
// Created by Omar on 15/06/2022.
//

#include "Merchant.h"
const std::string Merchant::MERCHANT_NAME = "Merchant";


Card* Merchant::clone()
{
    return  new Merchant(*this);
}

void Merchant::print(std::ostream& os) const
{
    printCardDetails(os,MERCHANT_NAME);
    printEndOfCardDetails(os);
}

bool Merchant::isValidBuyOption(int buyDecision) const
{
    return buyDecision == HP_BOOST_OPTION || buyDecision == FORCE_BOOST_OPTION || buyDecision == DEAL_BREAK_OPTION;
}

void Merchant::getPlayerDecision(int& Decision)
{
    std::string input;
    while(std::getline(std::cin,input))
    {
        if(input.size()==1)
        {
            try
            {
                Decision = std::stoi(input);
                if(isValidBuyOption(Decision))
                {
                    return;
                }
            }
            catch(std::invalid_argument&)
            {}
        }
        if(input.size()>0)
        {
            printInvalidInput();
        }
    }
}

void Merchant::applyCard(Player& player)
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getPlayerName(), player.getCoins());
    int buyDecision = -1;
    getPlayerDecision(buyDecision);
    bool playerHasEnoughMoney=false;
    switch (buyDecision)
    {
        case HP_BOOST_OPTION:
            playerHasEnoughMoney = player.pay(HP_BOOST_COST);
            if(playerHasEnoughMoney)
            {
                player.setHp(HP_BOOST);
                printMerchantSummary(std::cout, player.getPlayerName(), HP_BOOST_OPTION, HP_BOOST_COST);
            }
            else
            {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getPlayerName(), HP_BOOST_OPTION, 0);
            }
            break;
        case FORCE_BOOST_OPTION:
            playerHasEnoughMoney = player.pay(FORCE_BOOST_COST);
            if(playerHasEnoughMoney)
            {
                player.setForce(FORCE_BOOST);
                printMerchantSummary(std::cout, player.getPlayerName(), FORCE_BOOST_OPTION, FORCE_BOOST_COST);
            }
            else
            {
                printMerchantInsufficientCoins(std::cout);
                printMerchantSummary(std::cout, player.getPlayerName(), FORCE_BOOST_OPTION, 0);
            }
            break;
        case DEAL_BREAK_OPTION:
            printMerchantSummary(std::cout, player.getPlayerName(), 0, 0);
            break;
        default:
            break;
    }
}