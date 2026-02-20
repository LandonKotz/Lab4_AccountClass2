#include <iostream>

class Account {
private:
    int id;
    double balance;
    double annual_interest_rate;

public:
    void setId(int newId) { id = (newId > 0) ? newId : 0; }
    void setBalance(double newBal) { balance = (newBal > 0) ? newBal : 0; }
    void setAnnualInterestRate(double rate) { annual_interest_rate = (rate > 0) ? rate : 0; }

    Account(int newId, double newBal, double rate) {
        setId(newId);
        setBalance(newBal);
        setAnnualInterestRate(rate);
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds: Current balance is: $" << balance << std::endl;
        }
    }

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    int getId() { return id; }
    double getBalance() { return balance; }
    double getMonthlyInterest() { return balance * (annual_interest_rate / 12); }
};

int main() {
    Account myAccount(-1, 20000, 0.045);

    myAccount.withdraw(25000);
    myAccount.deposit(3000);

    std::cout << "ID is: " << myAccount.getId() << std::endl;
    std::cout << "Balance is: $" << myAccount.getBalance() << std::endl;
    std::cout << "Monthly interest is: $" << myAccount.getMonthlyInterest() << std::endl;

    return 0;
}
