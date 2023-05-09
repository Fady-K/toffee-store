#include "../include/Cart.hpp"


////////////////////////////////// Constructors and destructor////////////////////////
Cart::Cart(){}

Cart::~Cart(){}

////////////////////////////////// Setters & Getters ///////////////////////
string Cart::GetId() const
{
    return m_cartId;
}

vector<Product>& Cart::GetGoods()
{
    return m_goods;
}

////////////////////////////////// Instance Methods ///////////////////////
Product Cart::AddToCart(Product t_product, const int quntity)
{
    // set product quantity as quantity he wants to puy
    t_product.SetAmount(quntity);

    // append to cart
    m_goods.push_back(t_product);
    return t_product;

}

Product Cart::RemoveFromCart(const string& t_productName)
{
    if (isEmpty())
    {
        throw runtime_error("!! Cart is Empty !!");
    }
    else
    {
        // find product
        auto it = find_if(m_goods.begin(), m_goods.end(), [&]( const Product& p) {return p.GetProductName() == t_productName; });

        if (it != m_goods.end())
        {
            // remove from cart
            Product tmp = *it;
            m_goods.erase(it);

            return tmp;
        }
        else
        {
            cout << "!! No such product" << endl;
            return Product();
        }
    }
}

void Cart::Clear()
{
    if (isEmpty())
    {
        throw runtime_error("!! Cart Is Empty !!");
    }
    else
    {
        m_goods.clear();
    }
}

bool Cart::isEmpty() const
{
    return m_goods.empty();
}

void Cart::print() const
{
    if (isEmpty())
    {
        cout << "--------------------------- Cart Is Empty -------------------" << endl;
        return;
    }
    else
    {
        cout << "--------------------------- Cart -------------------" << endl;
        cout << "CartId: " << GetId() << "\n";
        cout << "Products In Cart:" << endl;

        for (auto it = m_goods.begin(); it != m_goods.end(); ++it)
        {
            cout << *it;
        }
    }
    
}