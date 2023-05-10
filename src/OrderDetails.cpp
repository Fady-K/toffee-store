#include "../include/OrderDetails.hpp"


////////////////////////////////////////////////// Constructors and Destructor ////////////////////////////////////////
OrderDetails::OrderDetails(){}

OrderDetails::OrderDetails(const string& t_orderid, const string& t_productId, int t_qunatity, double t_unitPrice, double t_totalPrice)
{
    // set all of them
    SetOrderId(t_orderid);
    SetProductId(t_productId);
    SetOrderedQuntity(t_qunatity);
    SetUnitPrice(t_unitPrice);
    SetTotalPrice(t_totalPrice);
}

OrderDetails::~OrderDetails(){}


////////////////////////////////////////////////// Setters and Getters (encapsulation) ////////////////////////////////////////


bool OrderDetails::SetOrderId(const string& t_id)
{
    // validate
    if(Utility::isValidOrderId(t_id))
    {
        this->_orderId = t_id;
        return true;
    }

    return false;
}

bool OrderDetails::SetProductId(const string& t_id)
{
    // validate
    if(Utility::isValidProductId(t_id))
    {
        this->_productId = t_id;
        return true;
    }

    return false;
}

bool OrderDetails::SetOrderedQuntity(const int t_quantity)
{
    // validate
    if(t_quantity >= 0)
    {
        this->_quantity = t_quantity;
        return true;
    }

    return false;
}

bool OrderDetails::SetUnitPrice(const double t_price)
{
    // validate
    if(Utility::isValidAmountOfMoney(t_price))
    {
        this->_unitPrice = t_price;
        return true;
    }

    return false;
}

bool OrderDetails::SetTotalPrice(const double t_price)
{
    // validate
    if(Utility::isValidAmountOfMoney(t_price))
    {
        this->_totalPrice = t_price;
        return true;
    }

    return false;
}


string OrderDetails::GetOrderId() const
{
    return this->_orderId;
}

string OrderDetails::GetProductId() const
{
    return this->_productId;
}

int OrderDetails::GetQuantity() const
{
    return this->_quantity;
}

double OrderDetails::GetPricePerUnit() const
{
    return this->_unitPrice;
}

double OrderDetails::GetTotalPrice() const
{
    return this->_totalPrice;
}


///////////////////////////////////////////////////////////// Instance Methods ////////////////////////////////////
void OrderDetails::print() const
{
    cout << "---------------------------------------- Order Details -------------------------------" << endl;
    cout << "OrderId: " << GetOrderId()<< "\n" << "ProductId: " << GetProductId() << endl;
    cout << "Ordered Qunantity: " << GetQuantity() << "\n" << "Price per unit: " << GetPricePerUnit() << endl;
    cout << "Total price: " << GetTotalPrice() << endl;

}


///////////////////////////////////////////////////////////// Operators overloading //////////////////////////////////
ostream& operator<< (ostream& output, const OrderDetails& t_details)
{
    output << "---------------------------------------- Order Details -------------------------------" << endl;
    output << "OrderId: " << t_details.GetOrderId()<< "\n" << "ProductId: " << t_details.GetProductId() << endl;
    output << "Ordered Qunantity: " << t_details.GetQuantity() << "\n" << "Price per unit: " << t_details.GetPricePerUnit() << endl;
    output << "Total price: " << t_details.GetTotalPrice() << endl;

    // return ostream
    return output;
}