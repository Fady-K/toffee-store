#include <iostream>
#include <string>
#include <vector>
#include "../src/Product.cpp"
using namespace std;

class Cart
{
private:
    string m_cartId;
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
    void Clear();
    void print() const;
    bool isEmpty() const;

};

