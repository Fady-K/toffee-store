#include <iostream>
#include <string>
#include <vector>
#include "../src/Utility.cpp"
#include "../src/Product.cpp"
using namespace std;

class Cart
{
private:
    string m_cartId;
    double m_subTotal;
    vector<Product> m_goods;
    
public:
    Cart();                                 // Default constructor
    ~Cart();                                // Destructor


    /* Setters And Getters */
    string GetId() const;
    vector<Product>& GetGoods();

    /* Instance Methods */
    Product AddToCart(Product t_product, const int t_quantity = 0);
    Product RemoveFromCart(const string& t_productName);
    bool IncreaseProductAmount(const string& t_productName, const int t_amount = 0);
    bool DecreaseProductAmount(const string& t_productName, const int t_amount = 0);
    pair<bool, Product*> exists(const string& t_productName);
    double TotalPrice() const;
    void Clear();
    void print() const;
    bool isEmpty() const;


};

