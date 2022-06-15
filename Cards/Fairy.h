//
// Created by user on 6/14/2022.
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
    //friend std::ostream& operator<<(std::ostream& os,const Fairy& fairy);

    ~Fairy()=default;
    Card* clone() override;
    void applyCard(Player& player) override;

protected:
    void print(std::ostream& os) const override;

private:
    static const int m_hpBoost = 10;
};


#endif //EX4_FAIRY_H
