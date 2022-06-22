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
    bool validDecision(int decision);

private:
    static const std::string MERCHANT_NAME;
    static const std::string DEAL_BREAK_STR_OPTION;
    static const std::string HP_BOOST_STR_OPTION;
    static const std::string FORCE_BOOST_STR_OPTION;
    static const int HP_BOOST = 1;
    static const int HP_BOOST_COST = 5;
    static const int FORCE_BOOST = 1;
    static const int FORCE_BOOST_COST = 10;
    static const int HP_BOOST_OPTION = 1;
    static const int FORCE_BOOST_OPTION = 2;
    static const int DEAL_BREAK_OPTION = 0;
    bool isValidBuyOption(std::string& input) const;
    void getPlayerDecision(int& Decision);
};


#endif //EX4_MERCHANT_H