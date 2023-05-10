#include "../include/Product.hpp"

///////////////////////////////////////////////// Statice attributes //////////////////////////////////////////////////
int Product::s_productsCount = 0;


///////////////////////////////////////////////// Rule Of big 5 //////////////////////////////////////////////////
Product::Product(): m_productName("None"), m_productCategory("None"), m_productDescription("None"), m_productPrice(0), m_availableAmount(0)
{
    // increament total n of Products
    this->s_productsCount ++;   
}

Product::Product(string t_name, string t_category, string t_descr, double t_price, int t_amount): m_productName(t_name), m_productCategory(t_category), m_productDescription(t_descr), m_productPrice(t_price), m_availableAmount(t_amount)
{
    // increament total n of Products
    this->s_productsCount ++; 
}

Product::~Product()
{
    // decreament total n of Products
    this->s_productsCount --; 
}


///////////////////////////////////////////////// Instance Methods Setters & Getters (encapsulation) //////////////////////////////////////////////////
void Product::SetProductName(const string& t_name)
{
    this->m_productName = t_name;
}

string Product::GetProductName() const
{
    return this->m_productName;
}

void Product::SetCategory(const string& t_category)
{
    this->m_productCategory = t_category;
}

string Product::GetCategory() const
{
    return this->m_productCategory;
}

void Product::SetDescription(const string& t_descr)
{
    this->m_productDescription = t_descr;
}

string Product::GetDescription() const
{
    return this->m_productDescription;
}

void Product::SetPrice(const double& t_price)
{
    this->m_productPrice = t_price;
}

double Product::GetPrice() const
{
    return this->m_productPrice;
}

void Product::SetAmount(const int& t_amount)
{
    this->m_availableAmount = t_amount;
}

int Product::GetAvailableAmount() const
{
    return this->m_availableAmount;
}


///////////////////////////////////////////////// Instance Methods  //////////////////////////////////////////////////
int Product::IncreaseAmount(const int& t_value)
{
    // add new quntity
    this->m_availableAmount += t_value;

    // return total number after addition
    return m_availableAmount;
}

bool Product::DecreaseAmount(const int& t_value)
{
    // decreased variable
    bool decreased = true;

    // check if there is no available amount
    if (this->m_availableAmount == 0 || (m_availableAmount - t_value) < 0)
    {
        cout << "!! There are no enough Prodcuts !!" << endl;
        decreased = false;

    }
    else
    {
        // add new quntity
        this->m_availableAmount -= t_value;
    }

    // return if amount was decresed or not
    return decreased;
}


///////////////////////////////////////////////// Instance Methods  //////////////////////////////////////////////////
Product Product::Rename(const string& t_newName)
{
    // change product current name
    SetProductName(t_newName);

    // return the renamed product (*this)
    return *this;
}

Product Product::Print() const
{
    // box width
    int boxWidth = 30;

    // Print the top border of the box
    cout << "+" << string(boxWidth - 2, '-') << "+" << endl;

    // Print the name of the product, centered within the box
    int nameLength = m_productName.length();
    int spaces = (boxWidth - 2 - nameLength) / 2;
    cout << "|" << string(spaces, ' ') << m_productName << string(boxWidth - 2 - spaces - nameLength, ' ') << "|" << endl;

    cout << "+" << string(boxWidth - 2, '-') << "+" << endl;
    // Print the price of the product, centered within the box
    string priceStr = "$" + to_string(m_productPrice);
    int priceLength = priceStr.length();
    spaces = (boxWidth - 9 - priceLength) / 2;
    cout << "|" << string(spaces, ' ') << "Price: " << priceStr << string(boxWidth - 9 - spaces - priceLength, ' ') << "|" << endl;
    cout << "+" << string(boxWidth - 2, '-') << "+" << endl;

    // Print the amout of the product, centered within the box
    string amountStr =  to_string(m_availableAmount);
    int amountLength = amountStr.length();
    spaces = (boxWidth - 10 - amountLength) / 2;
    cout << "|" << string(spaces, ' ') << "Amount: " << amountStr << string(boxWidth - 10 - spaces - amountLength, ' ') << "|" << endl;
    cout << "+" << string(boxWidth - 2, '-') << "+" << endl;

    
    // prodcut description
    if (m_productDescription.length() > 0 && m_productDescription != "None")
    {
        cout << "|" << string(spaces, ' ') << "About product: " << string(boxWidth - 16 - spaces - amountLength, ' ') << "|" << endl;
        ParseDescription(m_productDescription);

        // Print the bottom border of the box
        cout << "+" << string(boxWidth - 2, '-') << "+" << endl;    
    }


    // return current prodcut (solid prenc)
    return (*this);
}


///////////////////////////////////////////////// operators overloading //////////////////////////////////////////////////
ostream& operator<< (ostream& output, const Product& t_product)
{
    // box width
    int boxWidth = 30;

    // Print the top border of the box
    output << "+" << string(boxWidth - 2, '-') << "+" << endl;

    // Print the name of the product, centered within the box
    int nameLength = t_product.GetProductName().length();
    int spaces = (boxWidth - 2 - nameLength) / 2;
    output << "|" << string(spaces, ' ') << t_product.GetProductName() << string(boxWidth - 2 - spaces - nameLength, ' ') << "|" << endl;

    output << "+" << string(boxWidth - 2, '-') << "+" << endl;
    // Print the price of the product, centered within the box
    string priceStr = "$" + to_string(t_product.GetPrice());
    int priceLength = priceStr.length();
    spaces = (boxWidth - 9 - priceLength) / 2;
    output << "|" << string(spaces, ' ') << "Price: " << priceStr << string(boxWidth - 9 - spaces - priceLength, ' ') << "|" << endl;
    output << "+" << string(boxWidth - 2, '-') << "+" << endl;

    // Print the amout of the product, centered within the box
    string amountStr =  to_string(t_product.GetAvailableAmount());
    int amountLength = amountStr.length();
    spaces = (boxWidth - 10 - amountLength) / 2;
    output << "|" << string(spaces, ' ') << "Amount: " << amountStr << string(boxWidth - 10 - spaces - amountLength, ' ') << "|" << endl;
    output << "+" << string(boxWidth - 2, '-') << "+" << endl;

    
    // prodcut description
    if (t_product.GetDescription().length() > 0 && t_product.GetDescription() != "None")
    {
        cout << "|" << string(spaces, ' ') << "About product " << string(boxWidth - 15 - spaces - amountLength, ' ') << "|" << endl;
        cout << "|" << string(spaces, ' ') << string(boxWidth - 1 - spaces - amountLength, ' ') << "|" << endl;
        t_product.ParseDescription(t_product.GetDescription());

        // Print the bottom border of the box
        output << "+" << string(boxWidth - 2, '-') << "+" << endl;
    }

    // return current prodcut (solid prenc)
    return output;
}


/**
 * @brief 
 * 
 * @param t_product 
 * @return true 
 * @return false 
 */
bool Product::operator< (const Product& t_product) const
{
    return (this->m_productName < t_product.GetProductName());
}


/**
 * @brief 
 * 
 * @param t_product 
 * @return true 
 * @return false 
 */
bool Product::operator> (const Product& t_product) const
{
    return (this->m_productName > t_product.GetProductName());
}


/**
 * @brief 
 * 
 * @param t_product 
 * @return true 
 * @return false 
 */
bool Product::operator== (const Product& t_product) const
{
    return (this->m_productName == t_product.GetProductName());
}


///////////////////////////////////////////////// Static Methods (related to class only and have nothing to do with instance) //////////////////////////////////////////////////
int Product::GetTotalNumberOfProducts()
{
    // return total count
    return s_productsCount;
}


////////////////////////////////////////////// Helper Functions ///////////////////////////////////////////////////////////////////////////////////////
void Product::ParseDescription(const string& m_descr) const
{
    stringstream ss(m_productDescription);
    int wordCount = 0;
    string word;
    string line;
    stringstream so;

    // add to so stream lines so that each compriesed of 4 words at most
    while (ss >> word)
    {
        if (wordCount == 4)
        {
            so << line << endl;
            line = "";
            wordCount = 0;

        }
        line += (word + " ");
        wordCount++;
    }


    // print each line
    while (getline(so >> ws, line))
    {
        // Center the sentence within the field and add pipe characters at the beginning and end
        cout << "|" << string(1, ' ') << line << endl;
    }
}






