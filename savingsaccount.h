#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "transaction.h"

class SavingsAccount
{
public:
    SavingsAccount(QString name, QString num);
    ~SavingsAccount();
    void addTransaction(Transaction* t);
    double totalTransactionCost() const;
    QString frequentTransactionType() const;
    QList<Transaction*>transactionsOnAdate(QDate date) const;
    QString toString() const;

private:
    QString m_CustomerName;
    QString m_AccountNumber;
    QList<Transaction*>m_TransactionList;
};

#endif // SAVINGSACCOUNT_H
