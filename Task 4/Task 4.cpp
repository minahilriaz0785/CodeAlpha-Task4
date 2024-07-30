////CodeAlpha  Task 4
///* A C++ project is designed with an object - oriented
//approach, with classes for customers, accounts,
//transactions, and banking services.Features included
//creating and managing customers, accounts, and
//transactions, as well as performing banking services
//such as withdrawals, deposits, and transfers.It also
//allows customers to view their account information,
//including account balances, recent transactions, and
//other details.*/
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//// Account class definition
//class Account {
//public:
//    Account(int id, const string& ownerName, double initialBalance)
//        : id(id), ownerName(ownerName), balance(initialBalance) {}
//
//    int getId() const { return id; }
//    string getOwnerName() const { return ownerName; }
//    double getBalance() const { return balance; }
//
//    void deposit(double amount) {
//        balance += amount;
//        transactions.push_back("Deposited $" + to_string(amount));
//    }
//
//    void withdraw(double amount) {
//        if (amount <= balance) {
//            balance -= amount;
//            transactions.push_back("Withdrew $" + to_string(amount));
//        }
//        else {
//            cout << "Insufficient funds!" << endl;
//        }
//    }
//
//    void transfer(Account& toAccount, double amount) {
//        if (amount <= balance) {
//            withdraw(amount);
//            toAccount.deposit(amount);
//            transactions.push_back("Transferred $" + to_string(amount) + " to account " + to_string(toAccount.getId()));
//        }
//        else {
//            cout << "Insufficient funds!" << endl;
//        }
//    }
//
//    void printTransactions() const {
//        for (const auto& transaction : transactions) {
//            cout << transaction << endl;
//        }
//    }
//
//private:
//    int id;
//    string ownerName;
//    double balance;
//    vector<string> transactions;
//};
//
//// Customer class definition
//class Customer {
//public:
//    Customer(int id, const string& name) : id(id), name(name) {}
//
//    void addAccount(const Account& account) {
//        accounts.push_back(account);
//    }
//
//    Account* getAccountById(int id) {
//        for (auto& account : accounts) {
//            if (account.getId() == id) {
//                return &account;
//            }
//        }
//        return nullptr;
//    }
//
//    Account* getAccountById(int id) const {
//        for (auto& account : accounts) {
//            if (account.getId() == id) {
//                return const_cast<Account*>(&account);
//            }
//        }
//        return nullptr;
//    }
//
//    void printAccounts() const {
//        for (const auto& account : accounts) {
//            cout << "Account ID: " << account.getId()
//                << ", Owner: " << account.getOwnerName()
//                << ", Balance: $" << account.getBalance() << endl;
//        }
//    }
//
//    int getId() const { return id; }
//    string getName() const { return name; }
//
//private:
//    int id;
//    string name;
//    vector<Account> accounts;
//};
//
//// BankingSystem class definition
//class BankingSystem {
//public:
//    void addCustomer(const Customer& customer) {
//        customers.push_back(customer);
//    }
//
//    void createAccount(int customerId, int accountId, const string& ownerName, double initialBalance) {
//        for (auto& customer : customers) {
//            if (customer.getId() == customerId) {
//                customer.addAccount(Account(accountId, ownerName, initialBalance));
//                return;
//            }
//        }
//        cout << "Customer not found!" << endl;
//    }
//
//    void deposit(int accountId, double amount) {
//        for (auto& customer : customers) {
//            Account* account = customer.getAccountById(accountId);
//            if (account) {
//                account->deposit(amount);
//                return;
//            }
//        }
//        cout << "Account not found!" << endl;
//    }
//
//    void withdraw(int accountId, double amount) {
//        for (auto& customer : customers) {
//            Account* account = customer.getAccountById(accountId);
//            if (account) {
//                account->withdraw(amount);
//                return;
//            }
//        }
//        cout << "Account not found!" << endl;
//    }
//
//    void transfer(int fromAccountId, int toAccountId, double amount) {
//        Account* fromAccount = nullptr;
//        Account* toAccount = nullptr;
//
//        for (auto& customer : customers) {
//            fromAccount = customer.getAccountById(fromAccountId);
//            if (fromAccount) {
//                toAccount = customer.getAccountById(toAccountId);
//                if (toAccount) {
//                    fromAccount->transfer(*toAccount, amount);
//                    return;
//                }
//            }
//        }
//        cout << "Accounts not found or insufficient funds!" << endl;
//    }
//
//    void printAccountDetails(int accountId) const {
//        for (const auto& customer : customers) {
//            Account* account = customer.getAccountById(accountId);
//            if (account) {
//                cout << "Account ID: " << account->getId()
//                    << ", Owner: " << account->getOwnerName()
//                    << ", Balance: $" << account->getBalance() << endl;
//                account->printTransactions();
//                return;
//            }
//        }
//        cout << "Account not found!" << endl;
//    }
//
//private:
//    vector<Customer> customers;
//};
//
//// Main function
//int main() {
//    BankingSystem bank;
//
//    Customer customer1(1, "Alice");
//    Customer customer2(2, "Bob");
//
//    bank.addCustomer(customer1);
//    bank.addCustomer(customer2);
//
//    bank.createAccount(1, 101, "Alice's Checking", 500.00);
//    bank.createAccount(2, 102, "Bob's Savings", 1000.00);
//
//    while (true) {
//        int choice;
//        cout << "Welcome to the Banking System" << endl;
//        cout << "1. Deposit" << endl;
//        cout << "2. Withdraw" << endl;
//        cout << "3. Transfer" << endl;
//        cout << "4. View Account Details" << endl;
//        cout << "5. Exit" << endl;
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        if (choice == 5) {
//            break;
//        }
//
//        int accountId, toAccountId;
//        double amount;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter account ID to deposit to: ";
//            cin >> accountId;
//            cout << "Enter amount to deposit: ";
//            cin >> amount;
//            bank.deposit(accountId, amount);
//            break;
//        case 2:
//            cout << "Enter account ID to withdraw from: ";
//            cin >> accountId;
//            cout << "Enter amount to withdraw: ";
//            cin >> amount;
//            bank.withdraw(accountId, amount);
//            break;
//        case 3:
//            cout << "Enter your account ID to transfer from: ";
//            cin >> accountId;
//            cout << "Enter account ID to transfer to: ";
//            cin >> toAccountId;
//            cout << "Enter amount to transfer: ";
//            cin >> amount;
//            bank.transfer(accountId, toAccountId, amount);
//            break;
//        case 4:
//            cout << "Enter account ID to view details: ";
//            cin >> accountId;
//            bank.printAccountDetails(accountId);
//            break;
//        default:
//            cout << "Invalid choice! Please try again." << endl;
//        }
//    }
//    return 0;
//}
