#pragma once 
#include <string>
#include <vector>
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
    vector<Product> t_products;

        
public:
    /* Constructors and Destructor */
    Category();                                         // Default contructor
    Category(const string& t_name);                                         // Parametrized constructor
    Category(const string& t_name, vector<Product> t_products);
    ~Category();


    /* Setters And Getters (encapsulation) */
    void SetName(const string& t_newName);
    string GetName() const;
    void SetNumberOfProducts(const int n);
    int GetNumberOfProducts() const;
    vector<Product> GetAllProducts() const;


    /* Instance Methdos */
    Product AddProduct(const string& t_name="", const string& t_descr="", double t_price=0, const int t_amount=0);
    Product RemoveProduct(const string& t_name);
    void SortProducts(const bool ascendingOrder=true);
    int SearchProductByName(const string& t_name) const;
    Product& GetProductByName(const string& t_name);
    void DisplayAllProducts() const;
    bool IsEmpty() const;
    bool Exists(const Product& t_product) const;
    bool Exists(const string& t_productName) const;
    void Clear();

    /* Operators overloading */
    friend ostream& operator<< (ostream& output, const Category& t_cat);
    Product& operator[](const int index);


    // /* static Methods (related to class only, and has nothing with instance) */
    // static int GetAllNumberOfCategories();


private:
    /* Helper Functions */
    bool CompareByName(const Product& p, const string& t_name) const;
};
