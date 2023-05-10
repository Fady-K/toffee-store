#include "../include/ShippingInfo.hpp"

///////////////////////////////////////////// constructors and destructor ///////////////
ShippingInfo::ShippingInfo(): _recipientName("None"), _recipientPhoneNumber("None"), _email("None"), _city("None"), _shippingAddress("None"){}

ShippingInfo::ShippingInfo(string t_recipientName, string t_recipientPhoneNumber,  string t_email, string t_city, string t_shippingAddress)
{
    SetRecipientName(t_recipientName);
    SetRecipientPhoneNumber(t_recipientPhoneNumber);
    SetEmail(t_email);
    SetCity(t_city);
    SetShippingAddress(t_shippingAddress);
}

ShippingInfo::~ShippingInfo(){}


/////////////////////////////////////////// Setters and getters ///////////////////


void ShippingInfo::SetRecipientName(const string& t_name)
{
    if (Utility::isValidName(t_name))
    {
        this->_recipientName = t_name;
    }
    else
    {
        throw invalid_argument("!! Not A Valid Name !!");
    }
}

void ShippingInfo::SetRecipientPhoneNumber(const string& t_phoneNumber)
{
    if (Utility::isValidPhoneNumber(t_phoneNumber))
    {
        this->_recipientPhoneNumber = t_phoneNumber;
    }
    else
    {
        throw invalid_argument("!! Not A Valid PhoneNumber !!");
    }
}

void ShippingInfo::SetEmail(const string& t_email)
{
    if (Utility::isValidEmail(t_email))
    {
        this->_email = t_email;
    }
    else
    {
        throw invalid_argument("!! Not A Valid Email !!");
    }
}

void ShippingInfo::SetCity(const string& t_city)
{
    if (Utility::isValidCity(t_city))
    {
        this->_city = t_city;
    }
    else
    {
        throw invalid_argument("!! Not A Valid City !!");
    }
}

void ShippingInfo::SetShippingAddress(const string& t_address)
{
    // if (Utility::isValidAddress(t_address))1
    if (true)
    {
        this->_shippingAddress = t_address;
    }
    else
    {
        throw invalid_argument("!! Not A Valid Address !!");
    }
}


string ShippingInfo::GetRecipientName() const
{
    return this->_recipientName;
}

string ShippingInfo::GetRecipientPhoneNumber() const
{
    return this->_recipientPhoneNumber;
}

string ShippingInfo::GetEmail() const
{
    return this->_email;
}

string ShippingInfo::GetCity() const
{
    return this->_city;
}

string ShippingInfo::GetShippingAddress() const
{
    return this->_shippingAddress;
}


/////////////////////////////////////////// Instance Methods /////////////////////////
void ShippingInfo::print() const
{
    cout << "----------------------------------------- " << this->_recipientName << " Shipping Information -------------------------------" << endl;
    cout << "RecipientName: " << _recipientName << "\n" << "RecipientPhoneNumber: " << this->_recipientPhoneNumber << endl;
    cout << "RecipientEmail: " << _email << "\n" << "City: " << this->_city << endl;
    cout << "Address: " << this->_shippingAddress << endl;
}


/////////////////////////////////////// Operator overloading ////////////////////
ostream& operator<< (ostream& output, const ShippingInfo& t_info)
{
    output << "----------------------------------------- " << t_info.GetRecipientName() << " Shipping Information -------------------------------" << endl;
    output << "RecipientName: " << t_info.GetRecipientName() << "\n" << "RecipientPhoneNumber: " <<t_info.GetRecipientPhoneNumber() << endl;
    output << "RecipientEmail: " << t_info.GetEmail() << "\n" << "City: " << t_info.GetCity() << endl;
    output << "Address: " <<t_info.GetShippingAddress() << endl;

    return output;
}