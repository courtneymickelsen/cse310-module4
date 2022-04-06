//  main.cpp
//  transactions

//  Created by Courtney Mickelsen on 3/5/22.

#include <iostream>
#include <fstream>
using namespace std;

class Transaction{
public:

int t_main() {
    // create and open file for reading, writing, and appending
    fstream file;
    file.open("/Users/courtneymickelsen/Documents/Winter-2022/cse310-applied-programming/module4/cse310-module4/transactions/transactions/transactions.txt", ios::out|ios::in|ios::app);

//    check for errors opening file
    if (file.fail()) {
        cout << endl << "ERROR: File failed to open." << endl;
        return 1;
    }

//    call the menu function as long as the user hasn't decided to exit
    int choice = 0;
    while (choice != 5) {
        choice = display_menu(choice, file);
    }

    return 0;
};

int display_menu(int choice, fstream& file) {
//     menu interface
    cout << "\n-----------------------------\nMENU:\n1) See yearly transaction total \n2) See monthly transaction total \n3) See daily transaction total \n4) Add a new transaction \n5) Quit program \n-----------------------------\n";

//     take user input for menu choice
    cout << "Enter your menu choice: ";
    cin >> choice;

//     call the correct functions for each menu item based on user selection
    switch (choice) {
        case 1:
            view_transactions(1, file);
            break;
        case 2:
            view_transactions(2, file);
            break;
        case 3:
            view_transactions(3, file);
            break;
        case 4:
            add_transaction(file);
            break;
        case 5:
//            close the file before ending
            file.close();
            cout << "Your data has been saved. Have a nice day!" << endl << "-----------------------------\n" << endl;
            break;
        default:
            cout << "Invalid. Please enter a number from 1 to 5.";
            return 0;
    }
    
//    send the choice back to main
    return choice;
};

void view_transactions(int tf, fstream& file){
    string line, f_value, f_date, f_day, f_month, f_year, f_amount, c_value, c_date, c_day, c_month, c_year;
    int count = 0;
    
//    get user input
    cout << "Please enter the date (MMDDYYYY): ";
    cin >> c_date;
    
//    get the year, month, and day from the uesr input
    c_year = c_date.substr(4);
    c_month = c_date.substr(0, 2);
    c_day = c_date.substr(2, 2);

//    start back at the beginning of the file if we've already looked through it
    file.clear();
    file.seekg(0);
    cout << "\nDate:          Amount:\n---------------------\n";

//    run through each line of the file...
    while (!file.eof()) {
//        put the file line into a variable to manipulate and compare
        file >> line;

        f_year = line.substr(4, 4);
//        cout << "f_year: " <<  f_year << endl;
        f_month = line.substr(0, 2);
//        cout << "f_month: " << f_month << endl;
        f_day = line.substr(2, 2);
//        cout << "f_day:" + f_day << endl;
        f_amount = line.substr(8);

//        set values for comparing each line according to the timeframe
        switch (tf) {
            case 1:
//                the timeframe is year
                c_value = c_year;
                f_value = f_year;
                break;
            case 2:
//                the timeframe is month
                c_value = c_month + c_year;
                f_value = f_month + f_year;
                break;
            case 3:
//                the timeframe is day
                c_value = c_day + c_month + c_year;
                f_value = f_day + f_month + f_year;
                break;
            default:
                cout << "ERROR: The timeframe is invalid.\n";
                break;
        }
        
//        check for matches and display them
        if (f_value == c_value) {
            count++;
            cout << f_month << "-" << f_day << "-" << f_year << "  -  $" << f_amount << endl;
        }
    }
    
//    if there's no matching transactions, let the user know
        if (count == 0) {
            cout << "No matching transactions found for this timeframe.";
        }
}

void add_transaction(fstream& file) {
    string date, amount, line;
    
//    get date and amount from user
    cout << "Please enter the date for your new transaction (MMDDYYYY): ";
    cin >> date;
    cout << "Please enter the transaction amount: $";
    cin >> amount;
    
//    format the data correctly to be written to the file correctly
    line = "\n" + date + amount;
    
//    write the line to the file and let the user know if it works
    if (file << line) {
        cout << "\nYour transaction has been entered. Added transactions will be permanant once the program ends." << endl;
    }
}
};

int main () {
//    create an instance on transaction and call the starting function
    Transaction t;
    t.t_main();
}

int main();
