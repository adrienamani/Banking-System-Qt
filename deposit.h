#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "transaction.h"


class Deposit : public Transaction
{
public:
    Deposit(double m_Amount);
    QString toString()const;
    double computeCost() const;
    
private:
    double m_Amount;
    static double m_Fee;
};

#endif // DEPOSIT_H
