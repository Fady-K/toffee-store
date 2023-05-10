#include "../include/EWallet.hpp"

//////////////////////////////////////////////////// Constructors and destructor //////////////////////////////////////////////////////
EWallet::EWallet(): _balance(0){}


EWallet::EWallet(const int t_balance)
{
    // set via setter to apply validation
    SetBalance(t_balance);
}

EWallet::~EWallet(){}


//////////////////////////////////////////////// Setters And Getters ///////////////////
bool EWallet::SetBalance(const double t_balance)
{
    // flag
    bool updated = false;

    // validation
    if (Utility::isValidAmountOfMoney(t_balance))
    {
        // set it
        this->_balance = t_balance;
        updated = true;
    }
    else
    {
        // throw logical error argument
        throw runtime_error("!! Balance < 0 !!");    
    }

    return updated;
}

string EWallet::GetId() const
{
    return _id;
}

double EWallet::GetBalance() const
{
    return _balance;
}


////////////////////////////////////////////// Insatnce Methods ////////////////////

void EWallet::print() const
{
    cout << "---------------------------------- Ewallet Details -------------------------------------" << endl << endl;
    cout << "Ewallet id: " << this->GetId() << "\t\t" << "Current Balance: " << GetBalance() << endl;
}

bool EWallet::isEmpty() const
{
    return _balance == 0;
}

bool EWallet::WithDraw(const double t_amount)
{
    // to know whether withdrawn or not
    bool withdrawn = false;

    if (!isEmpty())
    {
        if (isThereEnoughtMoneyToWithDraw(t_amount))
        {
            // withdraw
            double currentBalance = GetBalance();
            double newBalance =(currentBalance -= t_amount);

            // update balance
            if (SetBalance(newBalance))
            {
                withdrawn = true;
            }
        }
        else
        {
            cout << "!! Not Enought Balance In Ewallet !!" << endl;
        }
    }
    else
    {
        cout << "!! Ewallet is empty !!" << endl;
    }

    return withdrawn;
}

bool EWallet::Desposite(const double t_amount)
{
    // flag
    bool deposted = false;

    // new Balance
    double newBalance = _balance += t_amount;
    if (SetBalance(newBalance))
    {
        deposted = true;
    }

    // return flag
    return deposted;
}


///////////////////////////////////////////// Helper functions ///////////////////////////
bool EWallet::isThereEnoughtMoneyToWithDraw(const double t_amount) 
{
    return (_balance - t_amount) >= 0;
}