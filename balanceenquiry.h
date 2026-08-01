#ifndef BALANCEENQUIRY_H
#define BALANCEENQUIRY_H

#include "transaction.h"

class BalanceEnquiry: public Transaction
{
public:
    BalanceEnquiry(QDate fDate, QDate tDate);
    QString toString() const;
    double computeCost() const;

private:
    QDate m_FromDate;
    QDate m_ToDate;
};

#endif // BALANCEENQUIRY_H
