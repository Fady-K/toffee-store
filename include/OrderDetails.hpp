#include <iostream>
#include <string>
#include "../src/Utility.cpp"
using namespace std;

class OrderDetails
{
private:
    /* data */
    string _orderId;
    string _productId;
    int _quantity;
    double _unitPrice;
    double _totalPrice;

public:
    OrderDetails();                                                                                                               // Default constructor
    OrderDetails(const string& t_orderid="None", const string& t_productId="None", int t_qunatity=0, double t_unitPrice=0, double t_totalPrice=0);         // paramerized constructor
    ~OrderDetails();                                                                                                                         // destructor


    /* Setters & Getters (encapsulation) */
    bool SetOrderId(const string& t_id);
    bool SetProductId(const string& t_id);
    bool SetOrderedQuntity(const int t_quantity);
    bool SetUnitPrice(const double t_price);
    bool SetTotalPrice(const double t_price);

    string GetOrderId() const;
    string GetProductId() const;
    int GetQuantity() const;
    double GetPricePerUnit() const;
    double GetTotalPrice() const;


    /* Instance Methods */
    void print() const;


    /* Operators Overloading */
    friend ostream& operator<< (ostream& output, const OrderDetails& t_details);
};  

