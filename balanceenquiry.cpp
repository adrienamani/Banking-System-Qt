#include "balanceenquiry.h"

BalanceEnquiry::BalanceEnquiry(QDate fDate, QDate tDate):Transaction("Balance Enquiry", QDateTime::currentDateTime()), m_FromDate(fDate),m_ToDate(tDate)
{
}

QString BalanceEnquiry::toString() const
{
    return QString("%1, Start date: %2, End date: %3").arg(Transaction::toString()).arg(m_FromDate.toString("dd.MM.yyyy")).arg(m_ToDate.toString("dd.MM.yyyy"));
}

double BalanceEnquiry::computeCost() const
{
    return 0.0;
}
