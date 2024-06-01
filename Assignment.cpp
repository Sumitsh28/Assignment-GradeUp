#include <bits/stdc++.h>

using namespace std;

class BankAccount
{
public:
  string password;
  double balance;
  vector<string> transactionHistory;
  int failedLoginAttempts;
  bool isLocked;

  BankAccount() : balance(0.0), failedLoginAttempts(0), isLocked(false) {}
  BankAccount(string pass) : password(pass), balance(0.0), failedLoginAttempts(0), isLocked(false) {}
  void addTransaction(const string &transaction)
  {
    transactionHistory.push_back(transaction);
  }
};

map<string, BankAccount> accounts;

void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();
void userMenu(BankAccount &account);
void changePassword(BankAccount &account);
void showTransactionHistory(BankAccount &account);

char menuInput;

int main()
{

  cout << "Hi! Welcome to Mr. Zamar’s ATM Machine!" << endl;

  start();
  return 0;
}

void printIntroMenu()
{

  cout << "Please select an option from the menu below:" << endl;
  cout << "l -> Login" << endl;
  cout << "c -> Create New Account" << endl;
  cout << "q -> Quit" << endl;
  cout << "> ";
}

void printMainMenu()
{

  cout << "d -> Deposit Money" << endl;
  cout << "w -> Withdraw Money" << endl;
  cout << "r -> Request Balance" << endl;
  cout << "t -> Show Transaction History" << endl;
  cout << "p -> Change Password" << endl;
  cout << "q -> Quit" << endl;
  cout << "> ";
}

void start()
{
  while (true)
  {

    printIntroMenu();

    cin >> menuInput;

    switch (menuInput)
    {
    case 'l':
      login();
      break;
    case 'c':
      createAccount();
      break;
    case 'q':
      exit(0);
    default:
      cout << "Invalid option. Please try again." << endl;
    }
  }
}

void createAccount()
{
  string userId, password;
  cout << "Please enter your user id: ";
  cin >> userId;
  cout << "Please enter your password: ";
  cin >> password;

  if (accounts.find(userId) == accounts.end())
  {
    accounts[userId] = BankAccount(password);
    cout << "Thank You! Your account has been created!" << endl;
  }
  else
  {
    cout << "Account with this user id already exists!" << endl;
  }
}

void login()
{
  string userId, password;
  cout << "Please enter your user id: ";
  cin >> userId;
  cout << "Please enter your password: ";
  cin >> password;

  auto it = accounts.find(userId);
  if (it != accounts.end())
  {
    if (it->second.isLocked)
    {
      cout << "Account is locked due to multiple failed login attempts." << endl;
      return;
    }
    if (it->second.password == password)
    {
      cout << "Access Granted!" << endl;
      it->second.failedLoginAttempts = 0;
      userMenu(it->second);
    }
    else
    {
      cout << "******** LOGIN FAILED! ********" << endl;
      it->second.failedLoginAttempts++;
      if (it->second.failedLoginAttempts >= 3)
      {
        it->second.isLocked = true;
        cout << "Account locked due to multiple failed login attempts." << endl;
      }
    }
  }
  else
  {
    cout << "******** LOGIN FAILED! ********" << endl;
  }
}

void userMenu(BankAccount &account)
{
  while (true)
  {

    printMainMenu();

    cin >> menuInput;
    switch (menuInput)
    {
    case 'd':
    {
      double amount;
      cout << "Amount of deposit: $";
      cin >> amount;
      account.balance += amount;
      account.addTransaction("Deposited $" + to_string(amount));
      cout << fixed << setprecision(2) << "Your balance is $" << account.balance << endl;
      break;
    }
    case 'w':
    {
      double amount;
      cout << "Amount of withdrawal: $";
      cin >> amount;
      if (amount <= account.balance)
      {
        account.balance -= amount;
        account.addTransaction("Withdrew $" + to_string(amount));
        cout << fixed << setprecision(2) << "Your balance is $" << account.balance << endl;
      }
      else
      {
        cout << "Insufficient funds." << endl;
      }
      break;
    }
    case 'r':
      cout << fixed << setprecision(2) << "Your balance is $" << account.balance << endl;
      break;
    case 't':
      showTransactionHistory(account);
      break;
    case 'p':
      changePassword(account);
      break;
    case 'q':
      return;
    default:
      cout << "Invalid option. Please try again." << endl;
    }
  }
}

void changePassword(BankAccount &account)
{
  string oldPassword, newPassword;
  cout << "Enter your old password: ";
  cin >> oldPassword;
  if (oldPassword == account.password)
  {
    cout << "Enter your new password: ";
    cin >> newPassword;
    account.password = newPassword;
    cout << "Password changed successfully." << endl;
  }
  else
  {
    cout << "Incorrect old password." << endl;
  }
}

void showTransactionHistory(BankAccount &account)
{
  cout << "Transaction History:" << endl;
  for (const auto &transaction : account.transactionHistory)
  {
    cout << transaction << endl;
  }
  if (account.transactionHistory.empty())
  {
    cout << "No transactions yet." << endl;
  }
}
