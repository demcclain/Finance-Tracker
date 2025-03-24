#include<iostream>
#include<string>
using namespace std;

// PART 1
struct transaction
{
    int id;          // ID to keep track of transactions
    string date;     // date of transaction
    string category; // category of the transaction e.g. entertainment, food, rent, etc...
    float amount;    // amount of the transaction

    // Default constructor
    transaction()
    {
        id = 0;        // Default value
        date = "";     // Default value
        category = ""; // Default value
        amount = 0.0;  // Default value
    }

    // paramaterized constructor
    transaction(int id, string date, string category, float amount)
    {
        this->id = id;             // Assigninginput ID to the struct ID
        this->date = date;         // Assigning input date to struct date
        this->amount = amount;     // Assigning input amt to struct amt
        this->category = category; // Assigning input category to struct category
    }
};

class transactionMaker
{
private:
    int count;                 // keeps track of the total transactions
    int capacity;              // total capacity of the array
    int nextID;                //keeps track of the ID
    transaction *transactions; // dynamic array that holds the transactions

public:
    transactionMaker(int size)
    {
        this->capacity = size;                    // making capacity point to the size value
        this->count = 0;                          // making count point to 0
        this->nextID = 1;                         // Start IDs from 1
        transactions = new transaction[capacity]; // making a new array called transactions with the size being capacity
    }

    // deconstructor
    ~transactionMaker()
    {
        delete[] transactions;
    }

    // Check if the array is empty
    bool isEmpty()
    {
        return (count == 0);
    }

    // Check if the array is full
    bool isFull()
    {
        return (count == capacity);
    }

    // function to add a transaction
    void addTransaction(string date, string category, float amount)
    {
        if (isFull())
        {
            // if its full, it will add 5

            capacity *= 2;                                            // increasing capacity
            transaction *newTransactions = new transaction[capacity]; // creating a new, larger array

            // loop to copy info from old array to the new array
            for (int i = 0; i < count; i++)
            {
                newTransactions[i] = transactions[i];
            }
            delete[] transactions;          // freeing up tghe old name
            transactions = newTransactions; // point transactions to the new array
        }
            transactions[count] = transaction(nextID, date, category, amount); //just setting the transactions array with count to = all the parameters
            count++;
            nextID++;
            cout << "Transaction added" << endl;
    }

    void editTransaction(int id, string newDate, string newCategory, float newAmount)
    {
        for (int i = 0; i < count; i++)
        {
            if (transactions[i].id == id)
            {
                //just setting the old values to the new ones
                transactions[i].date = newDate;
                transactions[i].category = newCategory;
                transactions[i].amount = newAmount;
                cout << "Transaction updated" << endl;
                return;
            }

            // loops through until it finishes the count, and just lets you update the previous
            // values with new parameters
        }
        cout << "Transaction not found!" << endl;
    }

    // simple display array, just outputs the given information
    void displayTransactions()
    {
        if (isEmpty())
        {
            cout << "No transactions recorded" << endl;
        }
        else
        {
            //listing all the transactions
            cout << "Transactions List" << endl;
            cout << "-------------------------------------------------" << endl;
            for (int i = 0; i < count; i++)
            {
                cout << "ID: " << transactions[i].id << endl
                    << "Date: " << transactions[i].date << endl
                    << "Amount: " << transactions[i].amount << endl
                    << "Category: " << transactions[i].category << endl
                    << endl;
            }
            cout << "-------------------------------------------------" << endl;
        }
    }

    void displaySpecificTransaction(int id, string date, string category, int cost)
        {
            if (isEmpty())
            {
                cout << "No transactions recorded" << endl;
            }
            else
            {
                // listing all the transactions
                cout << "Transaction" << endl;
                cout << "-------------------------------------------------" << endl;
                cout << "ID: " << id << endl
                    << "Date: " << date << endl
                    << "Amount: " << cost << endl
                    << "Category: " << category << endl
                    << endl;
                cout << "-------------------------------------------------" << endl;
            }
        }

    void deleteTransaction(int id)
    {
        bool found = false; //using to bool to use IDs as true or false

        for (int i = 0; i < count; i++) //first for loop which checks for the ID
        {
            if (transactions[i].id == id) //checks to see if its the right ID you wanna delete
            {
                found = true;
                for (int j = i; j < count - 1; j++) //after finding the one you wanna delete this loop
                {                                   //shifts the other transactions up to fill the gap made
                    transactions[j] = transactions[j + 1];
                }
                count--; //reducing the count since one got deleted
                cout << "Transaction deleted" << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Transaction not found!" << endl; //if the ID doesn't exist it prints this
        }
    }

    int getLastTransactionID()
    {
        if (count == 0)
            return -1;                     // No transactions yet
        return transactions[count - 1].id; // Last transaction’s ID
    }
};



int id;
string date;
string category;
float cost;
void getUserInputA()
{

    cin.ignore();

    cout << "Date of your transaction (MM-DD-YYYY): " << endl;
    getline(cin, date);
    cout << "Category of your transaction: " << endl;
    getline(cin, category);

    cout << "Cost of your transaction: " << endl;
    cin >> cost;
}

int id2;
string newDate;
string newCategory;
float newCost;
void getUserInputE() {
    cout << "Which one do you want to edit? Use the ID: " << endl;
    cin >> id2;

    //Clear input buffer before using getline for string input
    cin.ignore();

    cout << "Give me the new date: " << endl;
    getline(cin, newDate);

    cout << "Give me the new category: " << endl;
    getline(cin, newCategory);

    cout << "Give me the new cost: " << endl;
    cin >> newCost;

}

// Function to get the ID for deleting an entry.
void getID() {
    cout << "Which one do you want to delete? Use the ID: " << endl;
    cin >> id2;
}



