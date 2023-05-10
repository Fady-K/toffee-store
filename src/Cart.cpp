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

    // add to total price
    m_subTotal += (t_product.GetPrice() * quntity);

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
            Product tmp = *it;          // store copy to return

            // decrement subTotal
            m_subTotal -= (it->GetPrice() * it->GetAvailableAmount());

            // remove item from cart
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

pair<bool, Product*> Cart::exists(const string& t_productName)
{
    pair<bool, Product*> ans;

    auto it = find_if(m_goods.begin(), m_goods.end(),
                      [&](const Product& p){ return p.GetProductName() == t_productName; });

    if (it != m_goods.end())
    {
        // Product exists in cart
        ans.first = true;
        ans.second = &(*it);
    }
    else
    {
        ans.first = false;
        ans.second = nullptr;
    }

    return ans;
}


bool Cart::IncreaseProductAmount(const string& t_productName, const int t_amount)
{
    // flag
    bool hasIncreased = false;

    // check if valid amount
    if (t_amount >= 0)
    {
        /* note on exists: 

            returns pair where, pair.first boolian value indicating whether item exists or not, 
            pair.second returns a pointer to the product soThat user be able to increase it.

        */

        // get pair
        pair<bool, Product*> existsAndProduct =  exists(t_productName);

        if (existsAndProduct.first)
        {
            // increase product amount
            existsAndProduct.second->IncreaseAmount(t_amount);

            // update total price
            m_subTotal += (existsAndProduct.second->GetPrice() * t_amount);

            // switch flag
            hasIncreased = true;
        }
        else
        {
            cout << "!! No Such Product: " << t_productName << " Exists In Cart !!" << endl;
        }
    }
    else
    {
        cout << "!! Invalid Amount !!" << endl;
    }

    // return flag
    return hasIncreased;
}

bool Cart::DecreaseProductAmount( const string& t_productName, const int t_amount)
{
    // flag
    bool hasDecreeased = false;

    // check if valid amount
    if (t_amount >= 0)
    {
        /* note on exists: 

            returns pair where, pair.first boolian value indicating whether item exists or not, 
            pair.second returns a pointer to the product soThat user be able to increase it.

        */

        // get pair
        pair<bool, Product*> existsAndProduct =  exists(t_productName);

        if (existsAndProduct.first)
        {
            // increase product amount
           if (existsAndProduct.second->DecreaseAmount(t_amount))
           {
                // update total price
               m_subTotal -= (existsAndProduct.second->GetPrice() * t_amount);

               
                // switch flag
                hasDecreeased = true;
           }

        }

        else
        {
            cout << "!! No Such Product: " << t_productName << " Exists In Cart !!" << endl;
        }
    }
    else
    {
        cout << "!! Invalid Amount !!" << endl;
    }

    // return flag
    return hasDecreeased;
}



double Cart::TotalPrice() const
{
    return this->m_subTotal;
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
        cout << endl;

        for (auto it = m_goods.begin(); it != m_goods.end(); ++it)
        {
            cout << *it;
        }

        cout << "TotalPrice: " << this->m_subTotal << '$' << endl;
    }
    
}