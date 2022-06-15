//
// Created by Omar on 15/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H


#include "Card.h"

class Merchant : public Card
{
public:
    Merchant()=default;
    Merchant(const Merchant&)=default;
    Merchant& operator=(const Merchant&)=default;

    ~Merchant()=default;
    Card* clone() override;
    void applyCard(Player& player) override;


protected:
    void print(std::ostream& os) const override;

private:
    static const int m_hpBoost = 1;
    static const int m_hpBoostCost = 5;
    static const int m_forceBoost = 1;
    static const int m_forceBoostCost = 10;
    static const int m_hpBoostOption = 1;
    static const int m_forceBoostOption = 2;
    static const int m_dealBreakOption = 0;
    bool isValidBuyOption(int buyDecision) const;

};


#endif //EX4_MERCHANT_H
