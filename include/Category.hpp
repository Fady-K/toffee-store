#pragma once 
#include <string>
#include "../src/Product.cpp"
#define endl "\n"
using namespace std;

class Category
{
private:
    /* static attributes (related to class only, and have nothing to do with instance) */
    static int s_categoriesCount;

    /* Instance attributes */
    string m_name; 
    int n_products;
    Product* t_products;

        
public:
    /* Constructors and Destructor */
    Category();                                         // Default contructor
    Category(const string& t_name);                                         // Parametrized constructor
    Category(const string& t_name, Product* t_products);
    ~Category();


    /* Setters And Getters (encapsulation) */
    void SetName(const string& t_newName);
    string GetName() const;
    int SetNumberOfProducts(const int n);
    int GetNumberOfProducts() const;
    Product* GetAllProducts() const;


    /* Instance Methdos */
    Product AddProduct(const string& t_name, const string& t_category, const string& t_descr, double t_price, const int t_amount);
    Product RemoveProduct(const string& t_name);
    void SortProducts(const bool ascendingOrder=true);
    Product SearchProductByName(const string& t_name);
    void DisplayAllProducts() const;
    bool IsEmpty() const;
    void Clear();

    /* Operators overloading */
    friend ostream& operator<< (ostream& output, const Category& t_cat);


    /* static Methods (related to class only, and has nothing with instance) */
    static int GetAllNumberOfCategories();


private:
    /* Helper Functions */

};
