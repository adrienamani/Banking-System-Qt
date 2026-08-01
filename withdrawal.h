#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "transaction.h"

class Withdrawal: public Transaction
{
public:
    Withdrawal(double amount);
    QString toString() const;
    double computeCost() const;
    
private:
    double m_Amount;
    static double m_Percentage;
};

#endif // WITHDRAWAL_H
