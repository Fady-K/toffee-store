#include "../include/EWallet.hpp"

//////////////////////////////////////////////////// Constructors and destructor //////////////////////////////////////////////////////
EWallet::EWallet(): _balance(0){}


EWallet::EWallet(const int t_balance)
{
    // check if valid amount of money
    if(Utility::isValidAmountOfMoney(t_balance))
    {
        // init attribute
        this->_balance = t_balance;
    }
    else
    {
        throw runtime_error("!! Balance < 0 !!");
    }
}

EWallet::~EWallet(){}


//////////////////////////////////////////////// Setters And Getters ///////////////////
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
    if (Utility::isValidAmountOfMoney(t_amount))
    {
        if (!isEmpty())
        {
            if (isThereEnoughtMoneyToWithDraw(t_amount))
            {
                // withdraw
                _balance -= t_amount;
                withdrawn = true;
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
    }
    else
    {
        cout << "!! invalid amount of money !!" << endl;
    }

    return withdrawn;
}

bool EWallet::Desposite(const double t_amount)
{
    // flag
    bool deposted = false;

    // if valid amount of money
    if (Utility::isValidAmountOfMoney(t_amount))
    {
        this->_balance += t_amount;
        deposted = true;
    }
    else
    {
        cout << "!! invalid amount of money !!" << endl;
    }

    // return flag
    return deposted;
}


///////////////////////////////////////////// Helper functions ///////////////////////////
bool EWallet::isThereEnoughtMoneyToWithDraw(const double t_amount) 
{
    return (_balance - t_amount) >= 0;
}