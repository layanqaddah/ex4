//
// Created by Layan & Omar on 14/06/2022.
//

#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"


class Fairy : public Card
{
public:
    Fairy()=default;
    Fairy(const Fairy& otherFairy)=default;
    Fairy& operator=(const Fairy& otherFairy)=default;
    ~Fairy()=default;

    Card* clone() override;
    void applyCard(Player& player) override;

protected:
    void print(std::ostream& os) const override;

private:
    static const std::string FAIRY_NAME;
    static const int HP_BOOST = 10;
};

#endif //EX4_FAIRY_H
