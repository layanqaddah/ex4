#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include<vector>
#include<fstream>
#include<string>
#include<deque>
#include<list>
#include<memory>
/////////////////////////////////////////////////////////////////////
#include "Cards/Card.h"
#include "Cards/Vampire.h"
#include "Cards/Goblin.h"
#include "Cards/Treasure.h"
#include "Cards/Pitfall.h"
#include "Cards/Merchant.h"
#include "Cards/Fairy.h"
#include "Cards/Dragon.h"
#include "Cards/Barfight.h"
/////////////////////////////////////////////////////////////////////
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include <algorithm>
/////////////////////////////////////////////////////////////////////

using std::deque;
using std::string;
using std::unique_ptr;
using std::ifstream;
using std::list;
using std::shared_ptr;

class Mtmchkin
{
public:
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const string& fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    /// card related functions
    void initializeCardsDeck(const string filename);
    unique_ptr<Card> constructCard(const string cardName);
    void spinCardDeck();
    /// leader board related functions
    void initializeLeaderBoard();
    void updateLeaderBoard();
    void relocatePlayerInLeaderBoard();
    void popCurrentPlayerFromLeaderBoard();
    void pushCurrentPlayerInLeaderBoard();
    /// player related functions
    void updatePlayersQueue();
    void createPlayersQueue();
    int getTeamSize();
    bool isValidTeamSize(int teamSize);
    void getPlayers(int teamSize);
    void insertNewPlayer();
    bool containsOnlyEnglishLetters(string const &str);
    void invalidDetail(string playerName,string playerType);
    bool isValidClass(string playerType);

    deque<unique_ptr<Card>> cardsDeck;
    list<shared_ptr<const Player>> leaderBoard;
    deque<shared_ptr<Player>> playersQueue;
    int roundsCount;
    int killedPlayersCounter;
    int victoriousPlayersCount;

    static const string ROGUE_CLASS ;
    static const string WIZARD_CLASS ;
    static const string FIGHTER_CLASS ;
    static const string BARFIGHT_CLASS;
    static const string DRAGON_CLASS;
    static const string FAIRY_CLASS;
    static const string GOBLIN_CLASS;
    static const string MERCHANT_CLASS;
    static const string PITFALL_CLASS;
    static const string TREASURE_CLASS;
    static const string VAMPIRE_CLASS;
    static const int MAX_PLAYER_NAME_SIZE = 15;
    static const int MAX_PLAYERS_TEAM_SIZE = 6;
    static const int MIN_PLAYERS_TEAM_SIZE = 2;

};

void readCardsFile(std::vector<string>& cardNames, ifstream& cardsFile);
bool playerWon(const Player& player);

#endif /* MTMCHKIN_H_ */