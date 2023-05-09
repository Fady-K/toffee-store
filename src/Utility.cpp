#include "..\include\Utility.hpp"


/**/
std::string Utility::s_ClassDescription = "";


/**/
bool Utility::checkCinFaliure()
{
    if (cin.fail())
    {
        cout << "##########################" << "\n";
        cout << "ERROR -- You did not enter an integer\n";

        // get rid of failure state
        cin.clear();

        // discard 'bad' character(s) 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return true;
    }
    else
    {
        return false;
    }
}


bool Utility::isValidName(string name)
{
    regex pattern("^[a-zA-Z]{2,}(?: [a-zA-Z]+){0,3}$");
    
    return regex_match(name, pattern);
}

bool Utility::isValidPhoneNumber(string phoneNumber)
{
    regex pattern("^(010|011|012|015)\\d{8}$");
    return regex_match(phoneNumber, pattern);
}

bool Utility::isValidAddress(string address)
{
    regex pattern("");
    return regex_match(address, pattern);
}

/**/
bool Utility::isValidAmountOfMoney(double amountOfMoney)
{
    // amount of money is a nonnegative value
    return (amountOfMoney >= 0);
}

bool Utility::isValidAccountID(string accountID)
{
    regex pattern("^FCAI\\-\\d+$");
    return regex_match(accountID, pattern);
}

string Utility::getValidNameFromUser()
{
    // name to store user input
    string name;

    // take input from user
    cout << "Name: ";
    getline(cin >> ws, name);

    while (!isValidName(name))
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid Name !!" << "\n";
        cout << "###########################" << "\n";

        cout << "Please Enter A Valid Name  (e.g., Fady Kamal) : ";
        getline(cin >> ws, name);
    }

    return name;

}

string Utility::getValidPhoneNumberFromUser()
{
    // phoneNumber to store user input
    string phoneNumber;

    // take input from user
    cout << "Phone Number: ";
    getline(cin >> ws, phoneNumber);

    while (!isValidPhoneNumber(phoneNumber))
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid Phone Number !!" << "\n";
        cout << "###########################" << "\n";
        cout << "Please Enter A Valid Phone Number (e.g., 01212345678) : ";
        getline(cin >> ws, phoneNumber);
    }

    return phoneNumber;
}

string Utility::getValidAddressFromuser()
{
    // address to store user input
    string address;

    // take input from user
    cout << "Address: ";
    getline(cin >> ws, address);

    while (!isValidName(address))
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid Address !!" << "\n";
        cout << "###########################" << "\n";

        cout << "Please Enter A Valid Address: ";
        getline(cin >> ws, address);
    }
    return address;
}

double Utility::getValidAmountOfMoneyFromUser(bool isFirstTime)
{
    double amount;

    if (isFirstTime)
    {
        // inittial balance
        cout << "Please Enter the Starting Balance: ";
    }
    else
    {
        cout << "Amount Of Money: ";
    }

    // variable to store user input
    cin >> amount;

    while(!isValidAmountOfMoney(amount) || Utility::checkCinFaliure())
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid Amount Of Money !!" << "\n";
        cout << "###########################" << "\n";

        cout << "Please Enter A Valid Amount Of Money (e.g., 100.15) : ";
        cin >> amount;
    }
    return amount;
    
}

string Utility::getValidAccountID()
{
    // variable to store user input
    string accoutID;

    cout << "AccountID: ";
    getline(cin >> ws, accoutID);

    while (!isValidAccountID(accoutID))
    {
        cout << "###########################" << "\n";
        cout << "!! Invalid AccountID !!" << "\n";
        cout << "###########################" << "\n";

        cout << "Please Enter A Valid AccountID (e.g., FCAI-1)  : ";
        getline(cin >> ws, accoutID);
    }
    return accoutID;
}

