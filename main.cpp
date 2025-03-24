#include <iostream>
#include "classes.hpp"
using namespace std;

transactionMaker make(3);

void autoPopulate()
{
    make.addTransaction("02-01-2024", "Groceries", 50.75);
    make.addTransaction("02-02-2024", "Entertainment", 120.00);
    make.addTransaction("02-03-2024", "Rent", 950.00);
}

void printEndl()
{
    cout << endl;
}

int main()
{
    string ans;
    bool go = true;
    string goAns;

    autoPopulate(); // Prepopulate transactions

    while (go)
    {
        cout << "1) Add Transaction " << endl
            << "2) Edit Transaction " << endl
            << "3) Display Transactions " << endl
            << "4) Delete Transactions" << endl
            << "5) Exit" << endl;
        cin >> ans;

        if (ans == "1")
        {
            getUserInputA();
            make.addTransaction(date, category, cost);
            printEndl();

            int lastID = make.getLastTransactionID(); // Get last transaction ID
            make.displaySpecificTransaction(lastID, date, category, cost); // Display last transaction

        }
        else if (ans == "2")
        {
            make.displayTransactions();
            getUserInputE();
            make.editTransaction(id2, newDate, newCategory, newCost);
            printEndl();
            make.displayTransactions(); // Show all transactions AFTER editing
            printEndl();
        }
        else if (ans == "3")
        {
            make.displayTransactions();
        }
        else if (ans == "4")
        {
            make.displayTransactions();
            getID();
            make.deleteTransaction(id2);
            printEndl();
            make.displayTransactions();
        }
        else if (ans == "5")
        {
            go = false;
            break;
        }
        else
        {
            cout << "Invalid option. Try again." << endl;
        }

        if (go)
        {
            cout << "Would you like to continue? (Y/N)" << endl;
            cin >> goAns;
            if (goAns != "Y" && goAns != "y")
            {
                go = false;
            }
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}
