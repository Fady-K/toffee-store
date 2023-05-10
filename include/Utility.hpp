#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <limits>
#include <algorithm>
#define endl "\n"
using namespace std;

class Utility
{
    /* Static Attriubtes */
    static std::string s_ClassDescription;


public:
    /* Static Methods*/

    static bool isValidName(string name);    
    static bool isValidPhoneNumber(string phoneNumber);
    static bool isValidAddress(string  address);
    static bool isValidAmountOfMoney(double amountOfMoney);
    static bool isValidAccountID(string accountID);
    static bool isValidEmail(string email);
    static bool isValidCity(string city);
    static bool isValidOrderId(string t_orderId);
    static bool isValidProductId(string t_productId);



    static string getValidNameFromUser();
    static string getValidPhoneNumberFromUser();
    static string getValidAddressFromuser();
    static double getValidAmountOfMoneyFromUser(bool isFirstTime);
    static string getValidAccountID();


    bool static checkCinFaliure();

};