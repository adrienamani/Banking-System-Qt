#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>
#include <QDateTime>

class Transaction
{
public:
    Transaction(QString type, QDateTime datetime);
    virtual ~Transaction();
    QString getType() const;
    virtual QString toString() const;
    QDateTime getDateTime() const;
    virtual double computeCost() const = 0;
protected:
    QString m_Type;
    QDateTime m_DateTime;
};

#endif // TRANSACTION_H
