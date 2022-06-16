//
// Created by user on 6/15/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H


#include "Card.h"

class Pitfall : public Card
{
public:
    Pitfall()=default;
    Pitfall(const Pitfall& otherPitfall)=default;
    Pitfall& operator=(const Pitfall& otherPitfall)=default;

    ~Pitfall()=default;
    Card* clone() override;
    void applyCard(Player& player) override;

protected:
    void print(std::ostream& os) const override;

private:
    static const int HP_DAMAGE = -10;
    static const std::string PITFALL_NAME;
};


#endif //EX4_PITFALL_H
