#include "withdrawal.h"

Withdrawal::Withdrawal(double amount):Transaction("Withdrawal", QDateTime::currentDateTime()),m_Amount(amount)
{
}

double Withdrawal::m_Percentage = 0.50;

QString Withdrawal::toString() const
{
    return QString("%1, Amount Withdrawn: %2, Withdraw Fee: %3").arg(Transaction::toString()).arg(m_Amount).arg(m_Percentage);
}

double Withdrawal::computeCost() const
{
    return m_Amount * m_Percentage;
}
