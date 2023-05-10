#pragma once
#include <iostream>
#include <string>
#include "../src/Utility.cpp"
using namespace std;

class ShippingInfo
{
private:
    string _recipientName;
    string _recipientPhoneNumber;
    string _city;
    string _email; 
    string _shippingAddress;


public:
    ShippingInfo();                         // Default constructor
    ShippingInfo(string t_recipientName="", string t_recipientPhoneNumber="", string t_city="", string t_email="", string t_shippingAddress="");                         // Parametrized constructor
    ~ShippingInfo();                        // Destructor


    /* Setters And Getters (encapsulation) */
    void SetRecipientName(const string& t_name);
    void SetRecipientPhoneNumber(const string& t_phoneNumber);
    void SetCity(const string& t_city);
    void SetEmail(const string& t_email);
    void SetShippingAddress(const string& t_address);

    string GetRecipientName() const;
    string GetRecipientPhoneNumber() const;
    string GetCity() const;
    string GetEmail() const;
    string GetShippingAddress() const;

    /* Instance Methods */
    void print() const;

    /* Operator overloading */
    friend ostream& operator<< (ostream& output, const ShippingInfo& t_info);


};

