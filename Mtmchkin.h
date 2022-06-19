#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "Players/Player.h"
#include "Cards/Card.h"
#include<deque>
#include <memory>
/////////////////////////////////////////////////////////////////////
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include <algorithm>
////////////////////////////////////////////////////////////////////////


class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    Mtmchkin();

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
    std::deque<std::shared_ptr<Player>> playersDeck;
    void createPlayersDeck();
    int getTeamSize();
    bool isValidTeamSize(int teamSize);
    void getPlayers(int teamSize);
    void insertNewPlayer();
    bool containsOnlyEnglishLetters(std::string const &str);
    void invalidDetail(std::string playerName,std::string playerType);
    bool isValidClass(std::string playerType);
    void printExpectedClassFormat();
    void printExpectedPlayerNameFormat();

    static const std::string ROGUE_CLASS ;
    static const std::string WIZARD_CLASS ;
    static const std::string FIGHTER_CLASS ;
    static const int MAX_PLAYER_NAME_SIZE = 15;
    static const int MAX_PLAYERS_TEAM_SIZE = 6;
    static const int MIN_PLAYERS_TEAM_SIZE = 2;
};


#endif /* MTMCHKIN_H_ */
