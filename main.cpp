#include <iostream>
#include <deque>
#include <fstream>
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Players/Player.h"
#include "utilities.h"
#include "Cards/Goblin.h"
#include "Cards/Barfight.h"
#include "Cards/Vampire.h"
#include "Cards/Merchant.h"
#include "Mtmchkin.h"

using std::cout;
using std::endl;

int main()
{
    Fighter layan("layan");
    std::string path = ("D:\\Varrock\\technion\\courses\\sem_D\\234124\\ex4\\Cards.txt");
    try
    {
        Mtmchkin gameTest(path);
        while (!gameTest.isGameOver())
        {
            gameTest.playRound();
            gameTest.printLeaderBoard();
        }
    }
    catch(const std::exception& e)
    {
        e.what();
        return 0;
    }
    return 0;
}





