#include <iostream>
#include <deque>
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Players/Player.h"
#include "utilities.h"
#include "Cards/Goblin.h"
#include "Cards/Barfight.h"
#include "Cards/Vampire.h"
#include "Cards/Merchant.h"

using std::cout;
using std::endl;


void printCardsQueue(std::deque<Card*> cards)
{
    for(Card* cardPtr: cards)
    {
        cout<<*cardPtr;
    }
}

void spinCardDeck(std::deque<Card*>& cards)
{
    Card* tmpPtr=cards.front();
    cards.push_back(tmpPtr);
    cards.pop_front();
}


int main()
{
    Fighter layan("layan20");
    printLeaderBoardStartMessage();
    printPlayerLeaderBoard(1,layan);

    Goblin greenGoblin;
    Barfight boozedAndRash;
    Vampire bloodThirsty;
    Merchant jackOfAllTrades;

    std::deque<Card*> cardsList;
    cardsList.push_front(&greenGoblin);
    cardsList.push_front(&boozedAndRash);
    cardsList.push_front(&bloodThirsty);
    cardsList.push_front(&jackOfAllTrades);

    printCardsQueue(cardsList);
    spinCardDeck(cardsList);
    cout<<endl<<endl<<endl<<endl;
    printCardsQueue(cardsList);

    return 0;
}

