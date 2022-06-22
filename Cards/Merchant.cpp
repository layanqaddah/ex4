//
// Created by Omar on 15/06/2022.
//

#include "Merchant.h"
#include<assert.h>
const std::string Merchant::MERCHANT_NAME = "Merchant";
const std::string Merchant::DEAL_BREAK_STR_OPTION = "0";
const std::string Merchant::HP_BOOST_STR_OPTION = "1";
const std::string Merchant::FORCE_BOOST_STR_OPTION ="2";



Card* Merchant::clone()
{
    return  new Merchant(*this);
}

void Merchant::print(std::ostream& os) const
{
    printCardDetails(os,MERCHANT_NAME);
    printEndOfCardDetails(os);
}

bool Merchant::isValidBuyOption(std::string& input) const
{
    return input == HP_BOOST_STR_OPTION || input == FORCE_BOOST_STR_OPTION || input == DEAL_BREAK_STR_OPTION;
}

void Merchant::getPlayerDecision(int& Decision)
{
    std::string input;
    while(std::getline(std::cin,input))
    {
        if(isValidBuyOption(input))
        {
            Decision = std::stoi(input);
            return;
        }
        printInvalidInput();
    }
}


void Merchant::applyCard(Player& player)
{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getPlayerName(), player.getCoins());
    int buyDecision = -1;
    getPlayerDecision(buyDecision);
    assert(buyDecision==0 || buyDecision==1 || buyDecision==2);
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