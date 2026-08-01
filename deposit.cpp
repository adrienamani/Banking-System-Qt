#include "deposit.h"

double Deposit::m_Fee = 10;
       

Deposit::Deposit(double amount):Transaction("Deposit",QDateTime::currentDateTime()),m_Amount(amount)
{
}

QString Deposit::toString() const
{
    return QString("%1, Amount Deposited: %2, Deposit Fee: %3").arg(Transaction::toString()).arg(m_Amount).arg(m_Fee);
}

double Deposit::computeCost()const
{
    return m_Fee;
}
