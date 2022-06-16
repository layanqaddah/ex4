//
// Created by user on 6/14/2022.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"


class Treasure : public Card
{
public:
    Treasure()=default;
    Treasure(const Treasure& otherTreasureTreasure)=default;
    Treasure& operator=(const Treasure& otherTreasurer)=default;

    ~Treasure()=default;
    Card* clone() override;
    void applyCard(Player& player) override;

protected:
    void print(std::ostream& os) const override;

private:
    static const int TREASURE_LOOT =10;
    static const std::string TREASURE_NAME;
};


#endif //EX4_TREASURE_H
