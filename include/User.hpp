#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
protected:
    /* data */
    string _userName;
    string _password;


public:
    User();                                      
    User(string t_name, string t_password);
    ~User();


    void SetUserName(const string& t_name);
    string GetUserName() const;

    void SetPassword(const string& t_password);
    string GetPassowrd() const;

    virtual void DisplayInfo() const;
    friend ostream& operator<< (ostream& output, const User& t_user);
};

