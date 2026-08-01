#include "transaction.h"
#include "deposit.h"
#include "withdrawal.h"
#include "savingsaccount.h"
#include "balanceenquiry.h"

#include <QTextStream>

void delay()
{
    int c_Time = QTime::currentTime().msec();
    while((c_Time + 3) > (QTime::currentTime().msec()));
        return;
}

int main()
{
   QTextStream cout(stdout);

   //initailise transactions here
   SavingsAccount jw("Jack williams", "168662899");
   jw.addTransaction(new Deposit(8000.00)); delay;
   jw.addTransaction(new Withdrawal(350.00)); delay;
   jw.addTransaction(new BalanceEnquiry(QDate(2023,06,20), QDate::currentDate()));
   SavingsAccount aa("Adrien Amni", "653751306");
   aa.addTransaction(new Deposit(3200.32)); delay;
   aa.addTransaction(new Withdrawal(1000.00)); delay;
   aa.addTransaction(new BalanceEnquiry(QDate(2023,05,01), QDate::currentDate()));


   cout << "Summary of Savings Account: " << endl;
   cout << jw.toString() << endl;
   cout << aa.toString() << endl;

   cout << "Total Transaction cost: " << jw.totalTransactionCost() << endl;
   cout << "Most Frequent transaction: " << jw.frequentTransactionType() << endl;
   QDate date(2023,06,20);

   QList<Transaction*>result = jw.transactionsOnAdate(date);
   cout << QString("Transaction on a given date(%1): ").arg(date.toString("dd.MM.yyyy"));

   if(result.size()==0)
       cout << "none found" << endl;
   else
   {
       foreach (Transaction* t, result)
       cout << t->toString() << endl << endl;
   }


    return 0;
}
