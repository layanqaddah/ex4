#include <iostream>
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Players/Player.h"
#include "utilities.h"
#include "Cards/Goblin.h"
#include "Cards/Battle.h"
#include "Cards/Barfight.h"

using std::cout;
using std::endl;

int main() {
    std::cout << "Hello, World!" << std::endl;
    Wizard layan("Layan");
    printPlayerLeaderBoard(1,layan);

    Barfight barfight;
    barfight.applyCard(layan);

    cout<<endl<<endl;
    printPlayerLeaderBoard(1,layan);


    /*
    cout<<endl<<endl;
    Goblin goblin;
    goblin.applyCard(layan);
    printPlayerLeaderBoard(1,layan);
    cout<<goblin;
     */


    return 0;
}
