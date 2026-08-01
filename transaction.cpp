#include "transaction.h"

Transaction::Transaction(QString type, QDateTime datetime):m_Type(type), m_DateTime(datetime)
{
}

Transaction::~Transaction()
{}

QString Transaction::getType() const
{
    return m_Type;
}

QDateTime Transaction::getDateTime() const
{
    return m_DateTime;
}

QString Transaction::toString() const
{
    return QString("Type: %1, Date and Time: %2 %3").arg(m_Type).arg(m_DateTime.toString("dd.MM.yyyy")).arg(m_DateTime.toString("hh:mm:ss"));
}
