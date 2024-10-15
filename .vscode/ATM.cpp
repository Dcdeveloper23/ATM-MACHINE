#include <iostream>
#include <string>
using namespace std;

// Base class for ATM operations
class ATM
{
private:
     double balance;
     string pin;
     string accountNumber;
     string phoneNumber;

public:
     // Constructor
     ATM(double initial_balance, string initial_pin, string acc_num, string phone_num)
         : balance(initial_balance), pin(initial_pin), accountNumber(acc_num), phoneNumber(phone_num) {}

     // Method to check balance
     void checkBalance()
     {
          cout << "Your current balance is: $" << balance << endl;
     }

     // Method to withdraw money
     void withdraw(double amount)
     {
          if (amount > balance)
          {
               cout << "Insufficient balance." << endl;
          }
          else
          {
               balance -= amount;
               cout << "Please collect your cash. $" << amount << " has been withdrawn." << endl;
               checkBalance();
          }
     }

     // Method to deposit money
     void deposit(double amount)
     {
          balance += amount;
          cout << "$" << amount << " has been deposited into your account." << endl;
          checkBalance();
     }

     // Method to validate PIN
     bool validatePin(string input_pin)
     {
          return input_pin == pin;
     }

     // Method to display account details
     void checkAccountDetails()
     {
          cout << "Account Number: " << accountNumber << endl;
          cout << "Phone Number: " << phoneNumber << endl;
     }
};

// Derived class to handle the ATM interface
class ATMInterface : public ATM
{
public:
     // Constructor
     ATMInterface(double initial_balance, string initial_pin, string acc_num, string phone_num)
         : ATM(initial_balance, initial_pin, acc_num, phone_num) {}

     // Method to display the menu
     void menu()
     {
          cout << "\n----Welcome to the ATM Machine----" << endl;
          cout << "1. Check Balance" << endl;
          cout << "2. Deposit" << endl;
          cout << "3. Withdraw" << endl;
          cout << "4. View Account Details" << endl;
          cout << "5. Exit" << endl;
     }

     // Method to run the ATM machine
     void run()
     {
          string input_pin;
          cout << "Please enter your PIN: ";
          cin >> input_pin;

          // Validate the entered PIN
          if (validatePin(input_pin))
          {
               int choice;
               double amount;

               // Display menu until the user chooses to exit
               do
               {
                    menu();
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                         checkBalance();
                         break;
                    case 2:
                         cout << "Enter the amount to deposit: ";
                         cin >> amount;
                         deposit(amount);
                         break;
                    case 3:
                         cout << "Enter the amount to withdraw: ";
                         cin >> amount;
                         withdraw(amount);
                         break;
                    case 4:
                         checkAccountDetails();
                         break;
                    case 5:
                         cout << "Thank you for using the ATM. Goodbye!" << endl;
                         break;
                    default:
                         cout << "Invalid choice. Please try again." << endl;
                    }
               } while (choice != 5);
          }
          else
          {
               cout << "Invalid PIN. Access Denied." << endl;
          }
     }
};

int main()
{
     // Initializing the ATM with a balance, PIN, account number, and phone number
     ATMInterface atm(1000.0, "1234", "9876543210", "9876543216");
     atm.run(); // Running the ATM interface

     return 0;
}
