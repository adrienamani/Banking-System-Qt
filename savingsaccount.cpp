#include "savingsaccount.h"
#include <QStringList>

SavingsAccount::SavingsAccount(QString name, QString num):m_CustomerName(name), m_AccountNumber(num)
{
}

SavingsAccount::~SavingsAccount()
{
    qDeleteAll(m_TransactionList);
}

void SavingsAccount::addTransaction(Transaction* t)
{
    m_TransactionList.append(t);
}

double SavingsAccount::totalTransactionCost() const
{
    double cost = 0.0;
    foreach(Transaction* t,m_TransactionList )
    {
        cost +=t->computeCost();
    }
    return cost;
}

QString SavingsAccount::frequentTransactionType() const
{
    int dCount = 0, wCount = 0, beCount = 0, mostCount = 0;
    QString dTransaction = "Deposit", wTranaction = "withdrawal", beTransaction = "Balance Enquiry";
    QStringList result;

    foreach (Transaction* t, m_TransactionList)
    {
        QString type = t->getType();
        if(type == dTransaction)
            dCount++;
        if(type == wTranaction)
            wCount++;
        if(type == beTransaction)
            beCount++;
    }
    mostCount = dCount > wCount ? dCount: wCount;
    mostCount = beCount > mostCount ? beCount: mostCount;

    if(mostCount == dCount)
            result.append(dTransaction);
    if(mostCount == wCount)
            result.append(wTranaction);
    if(mostCount == beCount)
            result.append(beTransaction);

    return result.join(",");
}

QList<Transaction*>SavingsAccount::transactionsOnAdate(QDate date)const
{
       QList<Transaction*>result;
       foreach (Transaction* t, m_TransactionList)
       {
           if(t->getDateTime().date() == date)
               result.append(t);

       }
       return result;
}

QString SavingsAccount::toString() const
{
    QString result = QString("Customer name: %1, Account number: %2\n").arg(m_CustomerName).arg(m_AccountNumber);
    foreach(Transaction* t, m_TransactionList)
    {
        return result.append(t->toString());
        return result.append("\n");
    }
    return result;
}
