# Small Business Finance Tracker

This finance tracker is a lightweight, command-line C++ application to manage transactions. It supports adding, viewing, and editing transactions, stored in a local JSON file for storage.

## Description

This tool allows users to:
- Record transactions with a **date**, **category**, and **amount**
- View a list of all stored transactions
- Save data to a JSON file to ensure storage across sessions

It's is a simple and effective tool for small business owners, freelancers, or students  who want to manage their expenses and income without using spreadsheets or external apps

## Code Structure

```
Finance-Tracker/
├── main.cpp          # Main file that handles the user input
├── classes.hpp       # transactionMaker class with core transaction logic and functions
├── json.hpp          # JSON library (from nlohmann/json)
├── info.json         # transaction storage
├── README.md         # Documentation

```

## How the Code Works
### `main.cpp`
- Loads data from `info.json` at startup
- Calls transaction functions
- Prompts to continue or exit after each action
- Saves to `info.json` before exiting

### `transactionMaker` Class (in `classes.hpp`)
- Uses a dynamic array of `transaction` structs
- Auto-resizes when full
- Reads from/writes to JSON file using `nlohmann/json`

## Getting Started
### Dependencies

* C++17
* Compatible with Windows, Linux, or MacOS
* [nlohmann/json](https://github.com/nlohmann/json) (JSON header library)
* A C++ compiler such as `g++` or `clang++`

### Installing

* Clone this repository to your computer:
```bash
git clone https://github.com/demcclain/Finance-Tracker.git
```

### Running program

* CD into the project directory
```bash
cd Finance-Tracker
```
* Compile the code
```bash
g++ -o main.cpp app
```
* Execute the compiled program
```bash
./app
```


## 💡 Sample Interaction

```
1) Add Transaction
2) Edit Transaction
3) Display Transactions
4) Delete Transactions
5) Exit
> 1

Date of your transaction (MM-DD-YYYY):
> 04-10-2025
Category of your transaction:
> Rent
Cost of your transaction:
> 950

Transaction added

Transaction
-------------------------------------------------
ID: 1
Date: 04-10-2025
Amount: 950
Category: Rent
-------------------------------------------------

Would you like to continue? (Y/N)
> n
```

---



## Acknowledgments

* [nlohmann](https://github.com/nlohmann)
