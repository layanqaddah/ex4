//
// Created by user on 6/16/2022.
//

#include "Mtmchkin.h"
#include "utilities.h"


const std::string Mtmchkin::ROGUE_CLASS = "Rogue";
const std::string Mtmchkin::WIZARD_CLASS = "Wizard";
const std::string Mtmchkin::FIGHTER_CLASS = "Fighter";

Mtmchkin::Mtmchkin()
{
    printStartGameMessage();
    createPlayersDeck();
}
void Mtmchkin::createPlayersDeck()
{
    int teamSize=getTeamSize();
    while (!isValidTeamSize(teamSize))
    {
        printInvalidTeamSize();
        teamSize=getTeamSize();
    }
    getPlayers(teamSize);
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
        playersDeck.push_back(std::shared_ptr<Rogue> (new Rogue(playerName)));
    }
    if(playerType==WIZARD_CLASS)
    {
        playersDeck.push_back(std::shared_ptr<Wizard> (new Wizard(playerName)));
    }
    if(playerType==FIGHTER_CLASS)
    {
        playersDeck.push_back(std::shared_ptr<Fighter> (new Fighter(playerName)));
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
