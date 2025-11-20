#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, accountNumber;
    double amount;

    // Asking user for details
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your bank account number: ";
    getline(cin, accountNumber);

    cout << "Enter deposit amount: ";
    cin >> amount;

    // Writing data to file
    ofstream fout("bankdata.txt", ios::app);  // app mode to add more records
    if (!fout) {
        cout << "Error opening file!";
        return 1;
    }

    fout << "Name: " << name << endl;
    fout << "Account Number: " << accountNumber << endl;
    fout << "Amount: " << amount << endl;
    fout << "--------------------------" << endl;

    fout.close();

    cout << "\nData saved to file successfully!\n\n";

    // Reading and displaying file content
    ifstream fin("bankdata.txt");
    if (!fin) {
        cout << "Error opening file for reading!";
        return 1;
    }

    cout << "===== Bank Records =====\n";

    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }

    fin.close();

    return 0;
}

