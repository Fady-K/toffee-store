#pragma once
#include "../src/Utility.cpp"
#include <iostream>
#include <string>
using namespace std;

class EWallet
{
private:
    string _id;
    double _balance;


public:
    EWallet();                                      // Default constructor
    EWallet(const int t_balance);                   // Parametrized constructor
    ~EWallet();                                     // Destructor

    /* Setters And Getters */
    bool SetBalance(const double t_balance);
    string GetId() const;
    double GetBalance() const;

    /* Instance Methods */
    bool WithDraw(const double t_amount);
    bool Desposite(const double t_amount);
    bool isEmpty() const;
    void print() const;

private:
    bool isThereEnoughtMoneyToWithDraw(const double t_amount);
    
};

