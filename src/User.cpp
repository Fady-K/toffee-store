#include "../include/User.hpp"

User::User(): _userName("None"), _password("None") {}


User::User(string t_name, string t_password): _userName(t_name), _password(t_password) {}


User::~User(){}

void User::SetPassword(const string& t_password)
{
    _password = t_password;
}

string User::GetPassowrd() const
{
    return _password;
}

void User::SetUserName(const string& t_name)
{
    _userName = t_name;
}

string User::GetUserName() const
{
    return _userName;
}

void User::DisplayInfo() const
{
    cout  << "userName: " << GetUserName() << endl;
    cout  << "password: " << GetPassowrd() << endl;
}

ostream& operator<< (ostream& output, const User& t_user)
{
    output << "userName: " << t_user.GetUserName() << endl;
    output << "password: " << t_user.GetPassowrd() << endl;

    return output;
}