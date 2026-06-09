#include<bits/stdc++.h>
using namespace std;

class NonWithDrawableAccount {
    public:
        virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public NonWithDrawableAccount {
    public:
        virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public WithdrawableAccount {
    private:
        double balance;
    public:
        SavingsAccount(double bal):balance(bal){};
        void withdraw (double amount) override
        {
            if(balance>=amount)
            {
                balance-=amount;
                cout<<amount<<" Withdrawn"<<endl;
            }
            else
            {
                cout<<"Insufficient Balance"<<endl;
            }
        }
        void deposit(double amount) override
        {
            balance+=amount;
            cout<<"Deposited: "<<amount<<endl;
        }
};

class FixedDepositAccount : public NonWithDrawableAccount {
    private:
        double balance;
    public:
        FixedDepositAccount(double bal):balance(bal){};
        void deposit(double amount) override
        {
            balance+=amount;
            cout<<"Deposited: "<<amount<<endl;
        }
};

class BankClient {
    private:
        vector<WithdrawableAccount*> withdrawable_acc;
        vector<NonWithDrawableAccount*> non_withdrawable_acc;
    public:
        BankClient(vector<WithdrawableAccount*> withdrawable_acc,
        vector<NonWithDrawableAccount*> non_withdrawable_acc)
        {
            this->non_withdrawable_acc = non_withdrawable_acc;
            this->withdrawable_acc = withdrawable_acc;
        }
        void processTransaction()
        {
            for(WithdrawableAccount* acc:withdrawable_acc)
            {
                acc->deposit(1000);
                acc->withdraw(500);
            }
            for(NonWithDrawableAccount* acc:non_withdrawable_acc)
            {
                acc->deposit(1000);
            }
        }
};

int main()
{
    // 1. Create instances of our accounts
    // SavingsAccount can both deposit and withdraw
    SavingsAccount* savings1 = new SavingsAccount(5000); 
    SavingsAccount* savings2 = new SavingsAccount(1500);

    // FixedDepositAccount can only deposit
    FixedDepositAccount* fd1 = new FixedDepositAccount(10000);
    FixedDepositAccount* fd2 = new FixedDepositAccount(25000);

    // 2. Categorize them into their respective interface vectors
    vector<WithdrawableAccount*> withdrawableList = { savings1, savings2 };
    vector<NonWithDrawableAccount*> nonWithdrawableList = { fd1, fd2 };

    // 3. Pass the accounts to the BankClient
    BankClient client(withdrawableList, nonWithdrawableList);

    // 4. Process the transactions
    cout << "--- Starting Bank Transactions ---" << endl;
    client.processTransaction();
    cout << "----------------------------------" << endl;

    // 5. Clean up allocated memory
    for (WithdrawableAccount* acc : withdrawableList) {
        delete acc;
    }
    for (NonWithDrawableAccount* acc : nonWithdrawableList) {
        delete acc;
    }

    return 0;
}