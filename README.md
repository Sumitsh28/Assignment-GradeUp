# Mr. Zamar's ATM Machine

Welcome to Mr. Zamar's ATM Machine! This C++ program simulates an ATM system where users can create accounts, log in, deposit money, withdraw money, check their balance, and more.

## Features

1. **Create a Bank Account**: Users can create a bank account by providing a user ID and password.
2. **Login**: Users can log in using their user ID and password.
3. **Withdraw Money**: Users can withdraw money from their account.
4. **Deposit Money**: Users can deposit money into their account.
5. **Request Balance**: Users can request their current account balance.
6. **Quit**: Users can quit the program.

### Additional Features Added

1. **Change Password**: Users can change their password after logging in.
2. **Transaction History**: Users can view the transaction history for their account.
3. **Account Locking After Failed Login Attempts**: Accounts are locked after three consecutive failed login attempts to enhance security.

## Program Flow

1. **Introduction Menu**:
    - `l -> Login`
    - `c -> Create New Account`
    - `q -> Quit`

2. **Main Menu (after successful login)**:
    - `d -> Deposit Money`
    - `w -> Withdraw Money`
    - `r -> Request Balance`
    - `t -> Show Transaction History`
    - `p -> Change Password`
    - `q -> Quit`

## Sample Usage

```
Hi! Welcome to Mr. Zamar’s ATM Machine!
Please select an option from the menu below:
l -> Login
c -> Create New Account
q -> Quit
> c
Please enter your user id: 12
Please enter your password: 2345
Thank You! Your account has been created!
l -> Login
c -> Create New Account
q -> Quit
> l
Please enter your user id: 12
Please enter your password: 2345
Access Granted!
d -> Deposit Money
w -> Withdraw Money
r -> Request Balance
t -> Show Transaction History
p -> Change Password
q -> Quit
> d
Amount of deposit: $20
Your balance is $20.
d -> Deposit Money
w -> Withdraw Money
r -> Request Balance
t -> Show Transaction History
p -> Change Password
q -> Quit
> r
Your balance is $20.
d -> Deposit Money
w -> Withdraw Money
r -> Request Balance
t -> Show Transaction History
p -> Change Password
q -> Quit
> w
Amount of withdrawal: $2.5
Your balance is $17.5.
d -> Deposit Money
w -> Withdraw Money
r -> Request Balance
t -> Show Transaction History
p -> Change Password
q -> Quit
> q
Thanks for stopping by!
```
