#include <iostream>
#include "../Mtmchkin.h"

using std::cout;
using std::endl;

int main()
{
    const int MAX_NUMBER_OF_ROUNDS = 100;
    std::string path = ("deck.txt");
    try
    {
        Mtmchkin gameTest(path);
        while (!gameTest.isGameOver() && gameTest.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS)
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