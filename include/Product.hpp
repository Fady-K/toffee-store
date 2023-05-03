#pragma once
#include <bits/stdc++.h>
using namespace std;

class Product
{
private:
    /* static attributes ( Related to class only and have nothing to do with instance) */
    static int s_productsCount;

    /* instance attributs ( instance properties ) */
    string m_productName;
    string m_productCategory;
    string m_productDescription;
    double m_productPrice;
    int m_availableAmount;


public:
    /* Rule of big five (dConstructor, paraConstructor, defaultCopyConstructor, MoveConstructor, Destructor) */
    Product();
    Product(string t_name, string t_category, string t_descr, double t_price, int t_amount);        
    ~Product();                   


    /* Instance Methods, Setters & Getters (encapsulation) */
    void SetProductName(const string& t_name);
    string GetProductName() const;

    void SetCategory(const string& t_category);
    string GetCategory() const;

    void SetDescription(const string& t_descr);
    string GetDescription() const;

    void SetPrice(const double& t_price);
    double GetPrice() const;
    
    void SetAmount(const int& t_amount);
    int GetAvailableAmount() const;

    /* Instance Methods */
    int IncreaseAmount(const int& t_value);
    bool DecreaseAmount(const int& t_value);

    Product Rename(const string& t_newName);
    Product Print() const;


    /* Operators overloading */
                                    // bitwise operator (extraction operator <<)
    friend ostream& operator<< (ostream& output, const Product& t_prodcut);


    /* static Methods (related to class only, and has nothing with instance) */
    static int GetTotalNumberOfProducts();


private:
    /* Helper methods */
    void ParseDescription(const string& m_descr) const;
};

