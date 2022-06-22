//
// Created by Layan & Omar on 14/06/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"


class Barfight : public Card
{
public:
    Barfight()=default;
    Barfight(const Barfight& otherBarfight)=default;
    Barfight& operator=(const Barfight& otherBarfight)=default;

    ~Barfight()=default;
    Card* clone() override;
    void applyCard(Player& player) override;

protected:
    void print(std::ostream& os) const override;

private:
    static const std::string BARFIGHT_NAME;
    static const int HP_DAMAGE = -10;
};


#endif //EX4_BARFIGHT_H
