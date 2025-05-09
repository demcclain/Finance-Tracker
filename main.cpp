#include <iostream>
#include "classes.hpp"

using namespace std;

transactionMaker make(5);

void printEndl()
{
    cout << endl;
}

int main()
{
    string ans;
    bool go = true;
    string goAns;

    make.loadFromFile("info.json");

    while (go)
    {
        cout << "1) Add Transaction " << endl
            << "2) Edit Transaction " << endl
            << "3) Display Transactions " << endl
            << "4) Delete Transactions" << endl
            << "5) Display by Category" << endl
            << "6) Exit" << endl;
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
            string searchCat;
            cin.ignore();
            cout << "Enter category to search: ";
            getline(cin, searchCat);
            make.displayByCategory(searchCat);
        }

        else if (ans == "6")
        {
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
                make.saveToFile("info.json");
                go = false;
            }
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}
