//
// Created by user on 6/14/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"


class Barfight : public Card
{
public:
    Barfight()=default;
    Barfight(const Barfight& otherBarfight)=default;
    Barfight& operator=(const Barfight& otherPlayer)=default;
    friend std::ostream& operator<<(std::ostream& os,const Barfight& barfight);

    ~Barfight()=default;
    Card* clone() override;
    void applyCard(Player& player) override;

protected:
    void print(std::ostream& os) const override;

private:
    static const int m_hpDamage = -10;
};


#endif //EX4_BARFIGHT_H
