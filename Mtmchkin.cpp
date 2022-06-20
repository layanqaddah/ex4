//
// Created by Omar on 16/06/2022.
//

#include "Mtmchkin.h"
#include "Exception.h"

using std::vector;
using std::move;

const string DeckFileException::BASE_MESSAGE = "Deck File Error: ";
const string DeckFileNotFound::FILE_NOT_FOUND_ERROR = "File not found";
const string DeckFileFormatError::FILE_FORMAT_ERROR = "File format error in line ";
const string DeckFileInvalidSize::INVALID_SIZE_ERROR = "Deck size is invalid";

const string Mtmchkin::ROGUE_CLASS = "Rogue";
const string Mtmchkin::WIZARD_CLASS = "Wizard";
const string Mtmchkin::FIGHTER_CLASS = "Fighter";
const string Mtmchkin::BARFIGHT_CLASS = "Barfight";
const string Mtmchkin::DRAGON_CLASS = "Dragon";
const string Mtmchkin::FAIRY_CLASS = "Fairy";
const string Mtmchkin::GOBLIN_CLASS = "Goblin";
const string Mtmchkin::MERCHANT_CLASS = "Merchant";
const string Mtmchkin::PITFALL_CLASS = "Pitfall";
const string Mtmchkin::TREASURE_CLASS = "Treasure";
const string Mtmchkin::VAMPIRE_CLASS = "Vampire";


Mtmchkin::Mtmchkin(const string fileName): roundsCount(1), killedPlayersCounter(0), victoriousPlayersCount(0)
{
    printStartGameMessage();
    initializeCardsDeck(fileName);
    createPlayersQueue();
    initializeLeaderBoard();
};

void Mtmchkin::playRound()
{
    printRoundStartMessage(roundsCount);
    int initialTeamSize = playersQueue.size();
    for (int i = 0; i < initialTeamSize; ++i)
    {
        Player& currentPlayer = *(playersQueue.front());
        Card& currentCard = *(cardsDeck.front());
        printTurnStartMessage(currentPlayer.getPlayerName());
        currentCard.applyCard(currentPlayer);
        spinCardDeck();
        updateLeaderBoard();
        updatePlayersQueue();
    }
    ++roundsCount;
    if(isGameOver())
    {
        printGameEndMessage();
    }
}
bool Mtmchkin::isGameOver() const
{
   if(playersQueue.size()==0)
   {
       return true;
   }
    return false;
}
void Mtmchkin::printLeaderBoard() const
{
    int playerRank=0;
    printLeaderBoardStartMessage();
    for(shared_ptr<const Player> playerPtr : leaderBoard)
    {
        printPlayerLeaderBoard(++playerRank,*playerPtr);
    }
}


int Mtmchkin::getNumberOfRounds() const
{
    return roundsCount;
}



///################################## Cards Deck related ##################################
void Mtmchkin::initializeCardsDeck(const string filename)
{
    ifstream cardsFile = openCardsFile(filename);
    vector<string> cardNames;
    readCardsFile(cardNames,cardsFile);
    int lineCount=1;
    for(const string& cardName:cardNames)
    {
        unique_ptr<Card> tmpPtr = move(constructCard(cardName));
        if(!tmpPtr)
        {
            throw DeckFileFormatError(std::to_string(lineCount));
        }
        cardsDeck.push_back(move(tmpPtr));
        ++lineCount;
    }
}

ifstream openCardsFile(const string filename)
{
    ifstream cardsDeckFile(filename);
    if(!cardsDeckFile)
    {
        throw DeckFileNotFound();
    }
    return cardsDeckFile;
}


void readCardsFile(vector<string> &cardNames, ifstream& cardsFile)
{
    char buffer[30];
    int count=0;
    while(cardsFile.getline(buffer,sizeof(buffer)))
    {
        ++count;
        cardNames.push_back(buffer);
    }
    if(count<5)
    {
        throw DeckFileInvalidSize();
    }
}


unique_ptr<Card> Mtmchkin::constructCard(const string cardName)
{
    if(cardName==VAMPIRE_CLASS)
    {
        return unique_ptr<Card> (new Vampire);
    }
    if(cardName==TREASURE_CLASS)
    {
        return unique_ptr<Card> (new Treasure);
    }
    if(cardName==PITFALL_CLASS)
    {
        return unique_ptr<Card> (new Pitfall);
    }
    if(cardName==MERCHANT_CLASS)
    {
        return unique_ptr<Card> (new Merchant);
    }
    if(cardName==GOBLIN_CLASS)
    {
        return unique_ptr<Card> (new Goblin);
    }
    if(cardName==FAIRY_CLASS)
    {
        return unique_ptr<Card> (new Fairy);
    }
    if(cardName==DRAGON_CLASS)
    {
        return unique_ptr<Card> (new Dragon);
    }
    if(cardName==BARFIGHT_CLASS)
    {
        return unique_ptr<Card> (new Barfight);
    }
    return nullptr;
}

void Mtmchkin::spinCardDeck()
{
    cardsDeck.push_back(std::move(cardsDeck.front()));
    cardsDeck.pop_front();
}


void Mtmchkin::printCardsQueue()
{
    for(unique_ptr<Card>& uniqueCardPtr: cardsDeck)
    {
        std::cout<<*uniqueCardPtr;
    }
}

///################################## Cards Deck related ##################################

void Mtmchkin::initializeLeaderBoard()
{
    for(shared_ptr<Player> playerPtr : playersQueue)
    {
        leaderBoard.push_back(shared_ptr<Player>(playerPtr));
    }
}

void Mtmchkin::updateLeaderBoard()
{
    const Player& currentPlayer = *(playersQueue.front());
    if(playerWon(currentPlayer))
    {
        ++victoriousPlayersCount;
        return;
    }
    relocatePlayerInLeaderBoard();
    if(currentPlayer.isKnockedOut())
    {
        ++killedPlayersCounter;
    }
}

void Mtmchkin::relocatePlayerInLeaderBoard()
{
    popCurrentPlayerFromLeaderBoard();
    pushCurrentPlayerInLeaderBoard();
}

void Mtmchkin::popCurrentPlayerFromLeaderBoard()
{
    list<shared_ptr<const Player>>::const_iterator it = leaderBoard.begin();
    for (int i = 0; i < victoriousPlayersCount; ++i)
    {
        ++it;
    }
    leaderBoard.erase(it);
}

void Mtmchkin::pushCurrentPlayerInLeaderBoard()
{
    shared_ptr<Player> tmpPtr = playersQueue.front();
    list<shared_ptr<const Player>>::const_iterator it = leaderBoard.end();
    for (int i = 0; i < killedPlayersCounter; ++i)
    {
        --it;
    }
    leaderBoard.insert(it, tmpPtr);
}

///################################## Player related ##################################
void Mtmchkin::createPlayersQueue()
{
    int teamSize=getTeamSize();
    while (!isValidTeamSize(teamSize))
    {
        printInvalidTeamSize();
        teamSize=getTeamSize();
    }
    getPlayers(teamSize);
}

void Mtmchkin::updatePlayersQueue()
{
    if(!playersQueue.front()->isKnockedOut() && !playerWon(*(playersQueue.front())) )
    {
        playersQueue.push_back(playersQueue.front());
    }
    playersQueue.pop_front();
}

int Mtmchkin::getTeamSize()
{
    printEnterTeamSizeMessage();
    int teamSize;
    std::string input;
    std::getline (std::cin,input);
    try
    {
        teamSize = std::stoi(input);
    }
    catch(std::invalid_argument)
    {
        teamSize=0;
    }
    return teamSize;
}
bool Mtmchkin::isValidTeamSize(int teamSize)
{
    if(teamSize>=MIN_PLAYERS_TEAM_SIZE && teamSize<=MAX_PLAYERS_TEAM_SIZE)
    {
        return true;
    }
    return false;
}


void Mtmchkin::getPlayers(int teamSize)
{
    for(int i=0; i<teamSize;i++)
    {
        printInsertPlayerMessage();
        insertNewPlayer();
    }
}
void Mtmchkin::insertNewPlayer()
{
    std::string playerName;
    std::cin>>playerName;
    std::string playerType;
    std::cin>>playerType;
    while(playerName.size()>MAX_PLAYER_NAME_SIZE || !containsOnlyEnglishLetters(playerName) || !isValidClass(playerType))
    {
        invalidDetail(playerName,playerType);
        std::cin>>playerName;
        std::cin>>playerType;
    }
    if(playerType==ROGUE_CLASS)
    {
        playersQueue.push_back(std::shared_ptr<Rogue> (new Rogue(playerName)));
    }
    if(playerType==WIZARD_CLASS)
    {
        playersQueue.push_back(std::shared_ptr<Wizard> (new Wizard(playerName)));
    }
    if(playerType==FIGHTER_CLASS)
    {
        playersQueue.push_back(std::shared_ptr<Fighter> (new Fighter(playerName)));
    }
}
void Mtmchkin::invalidDetail(std::string playerName,std::string playerType)
{

    if(playerName.size()>MAX_PLAYER_NAME_SIZE || !containsOnlyEnglishLetters(playerName))
    {
        printInvalidName();
        printExpectedPlayerNameFormat();
        return;
    }
    if(!isValidClass(playerType))
    {
        printInvalidClass();
        printExpectedClassFormat();
    }
}
bool Mtmchkin::isValidClass(std::string playerType)
{
    return (playerType==ROGUE_CLASS || playerType==WIZARD_CLASS || playerType==FIGHTER_CLASS);
}
bool Mtmchkin::containsOnlyEnglishLetters(std::string const &str)
{
    for (char const &c : str)
    {
        if(!std::isalpha(c))
        {
            return false;
        }
    }
    return true;
}

void Mtmchkin::printExpectedClassFormat()
{
    std::cout<<"Available player types:"<<std::endl;
    std::cout<<WIZARD_CLASS<<std::endl;
    std::cout<<ROGUE_CLASS<<std::endl;
    std::cout<<FIGHTER_CLASS<<std::endl;
}

void Mtmchkin::printExpectedPlayerNameFormat()
{
    std::cout<<"A player name should contain english letters only."<<std::endl;
    std::cout<<"A player name should contain at most 15 letters."<<std::endl;
}

bool playerWon(const Player& player)
{
    return (player.getLevel() == 10) ? true : false;
}
