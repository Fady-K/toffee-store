#include "../include/Category.hpp"

///////////////////////////////////////////////// Statice attributes //////////////////////////////////////////////////
int Category::s_categoriesCount = 0;


///////////////////////////////////////////////// Constructors And Destructor //////////////////////////////////////////////////


/**
 * @brief Construct a new Category:: Category object
 * @details Default contructor
 * 
 */
Category::Category(): m_name("None"), n_products(0)
{
    // allocate vector with 200 products as a start
    t_products = vector<Product>(0);

    // increment number of created Categories (class entire program level)
    this->s_categoriesCount ++;
}


/**
 * @brief Construct a new Category:: Category object
 * 
 * @param t_name Name of to be created Category 
 */
Category::Category(const string& t_name): m_name(t_name), n_products(0)
{
    // allocate vector with 0 products as a start
    t_products = vector<Product>(0);

    // increment number of created Categories (class entire program level)
    this->s_categoriesCount ++;
}


/**
 * @brief Construct a new Category:: Category object
 * 
 * @param t_name 
 * @param t_products 
 */
Category::Category(const string& t_name, vector<Product> t_products): m_name(t_name), n_products(t_products.size())
{
    // allocate vector with given vector
    this->t_products = t_products;

    // increment number of created Categories (class entire program level)
    this->s_categoriesCount ++;
}


/**
 * @brief Destroy the Category:: Category object
 * 
 */
Category::~Category()
{
    // decrement total number of created Categories (whole program level)
    s_categoriesCount --;
}



///////////////////////////////////////////////// Setters And Getters (encpsulation) /////////////////////////////////////////////////////////////////


/**
 * @brief Set Category's name
 * 
 * @param t_name CategoryName - newName
 */
void Category::SetName(const string& t_name)
{
    // updated current name
    this->m_name = t_name;
}


/**
 * @brief Returns current of category
 * 
 * @return string Categories current name
 */
string Category::GetName() const
{
    return this->m_name;
}


/**
 * @brief Sets Current Number of Categories
 * 
 * @param n Number of products in Categories
 */
void Category::SetNumberOfProducts(const int n)
{
    this->n_products = n;
}


/**
 * @brief 
 * 
 * @return int 
 */
int Category::GetNumberOfProducts() const
{
    return this->n_products;
}


/**
 * @brief 
 * 
 * @return vector<Product> 
 */
vector<Product> Category::GetAllProducts() const
{
    return this->t_products;
}


///////////////////////////////////////////////// Instance Methods /////////////////////////////////////////////////////////////////
/**
 * @brief Adds new product to Category
 * 
 * @param t_name newProduct's name
 * @param t_descr newProduct's description
 * @param t_price newProduct's init price
 * @param t_amount newProdcuct's available amount
 * @return Product newProduct
 */
Product Category::AddProduct(const string& t_name, const string& t_descr, double t_price, const int t_amount)
{
    // create new product
    Product p(t_name, this->m_name, t_descr, t_price, t_amount);

    if (t_products.capacity() - t_products.size() < 5)
    {
        // emplace back is faster than push back
        t_products.emplace_back(p);
    }
    else
    {
        // add it using arr indexing opertator []
        t_products[n_products++] = p;
    }

    // incrment number of products by one
    this->n_products++;

    return p;
}


/**
 * @brief Removes a product by name
 * 
 * @param t_name Name of prodcut that will be removed
 * @return Product Removed product
 */
Product Category::RemoveProduct(const string& t_name)
{
    // check if exsists
    auto it = find_if(t_products.begin(), t_products.end(), [&](const Product& p) { return CompareByName(p, t_name); });

    if (it != t_products.end())
    {
        // if prodcut found then remove it
        t_products.erase(it);

        // reduce prodcut count
        this->n_products --;

        // return the earsed one
        return (*it);
    }
    else
    {
        cout << "Couldn't Find Product with name: " << t_name <<  " To Erase............!" << endl;
        return Product();
    }

}


/**
 * @brief Sorts products based on name
 * 
 * @param ascendingOrder Order of sorting
 */
void Category::SortProducts(const bool ascendingOrder)
{
    if (ascendingOrder)
    {
        // ascending order
        sort(this->t_products.begin(), this->t_products.end());
    }
    else
    {
        // descending order
        sort(this->t_products.rbegin(), this->t_products.rend());
    }

}


/**
 * @brief Takes product name and returns its index 
 * 
 * @param t_productName Name of product 
 * @return int Index of product
 */
int Category::SearchProductByName(const string& t_productName) const
{
    // check if prodcut exists
    if (Exists(t_productName))
    {
        auto it = find_if(t_products.begin(), t_products.end(), [&](const Product& p) {return CompareByName(p, t_productName); });
        
        // return index
        return (it - t_products.begin());
    }
    else
    {
        cout << "Couldn't Find Product with name: " << t_productName <<  "............!" << endl;
        return -1;
    }
}


/**
 * @brief Takes productName and returns reference to it, so as user be able to update it
 * 
 * @param t_productName Products'Name
 * @return Product& The product
 */
Product& Category::GetProductByName(const string& t_productName)
{
    return (*this)[SearchProductByName(t_productName)];
}


void Category::DisplayAllProducts() const
{
    if (IsEmpty())
    {
        cout << "------------------------------------ " << this->m_name << " Department Is Empty ------------------------------------" << endl;
    }
    else
    {
        // header
        cout << "------------------------------------ " << this->m_name << " ------------------------------------" << endl;

        // print each product
        for (auto it = t_products.begin(); it != (t_products.end()); ++it)
        {
            cout << *it << endl;
        }

        // footer
        cout << endl;
    }
}


/**
 * @brief 
 * 
 * @param t_productName 
 * @return true 
 * @return false 
 */
bool Category::Exists(const string& t_productName)  const
{
    auto it = find_if(this->t_products.begin(), this->t_products.end(), [&]( const Product& p) {return CompareByName(p, t_productName); });

    if (it != t_products.end())
    {
        // it not pointing the element after the last, then it found something
        return true;
    }
    else
    {
        // if it hasn't found something then return false
        return false;
    }
}


/**
 * @brief 
 * 
 * @param t_product 
 * @return true 
 * @return false 
 */
bool Category::Exists(const Product& t_product) const
{
    auto it = find(this->t_products.begin(), this->t_products.end(), t_product);

    if (it != this->t_products.end())
    {
        // if it hasn't reached the end (actully after end), then product exists
        return true;
    }
    else
    {
        // incase reached the end prodcut doesn't exist
        return false;
    }
}


/**
 * @brief Checks whether category is empty of not
 * 
 * @return true if category is empty 
 * @return false if categpry isn't emtpy
 */
bool Category::IsEmpty() const
{
    return t_products.empty();
}


/**
 * @brief Removes all products in category
 * 
 */
void Category::Clear()
{
    if (IsEmpty())
    {
        cout << this->m_name << " Deparment Is Already Empty........................!" << endl;
    }
    else
    {
        // clrea t_products
        this->t_products.clear();
        
        // set number of products to zeros
        this->SetNumberOfProducts(0);

        // shrink v to fit it new size and resize
        t_products.shrink_to_fit();

        // footer
        cout << "!...................... " << this->m_name << " Department Has Been Cleared .....................!" << endl;
    }
 
}



////////////////////////////////////////////////////////// Operators Overloading ////////////////////////////////////////
Product& Category::operator[](const int index)
{
    return t_products.at(index);
}


/**
 * @brief Overloading of << operator (extraction)
 * 
 * @param output An ostream& ref incase there are mulitple adding to ostream (cout << name << title << age << endl)
 * @param t_cat Category that will be added to output stream
 * @return ostream& refefrence to ostream
 */
ostream& operator<< (ostream& output, const Category& t_cat)
{

    // header
    string s = "------------------------------------ " + t_cat.m_name + " Department" + ((t_cat.IsEmpty())? (" Is Empty"): "") + " ------------------------------------";

    // add s to ostream
    output << s << endl;
    
    // print each product
    for (auto it = t_cat.t_products.begin(); it != (t_cat.t_products.end()); ++it)
    {
        output << *it << endl;
    }

    // footer
    output << endl;

    return output;
}



////////////////////////////////////////////////////////// Static Methods (related to class only) ////////////////////////////
/**
 * @brief Keeps track of the created Categories on Program level and return their count
 * 
 * @return int Current number of created categories
 */
int Category::GetAllNumberOfCategories()
{
    return s_categoriesCount;
}


////////////////////////////////////////////////////////// Helper Functions /////////////////////////////////////////////
/**
 * @brief Takse product and t_name, and compare product.name with the passed name (string)
 * @details main purpose of this function is work as lamabda function in find_if
 * @param p Product whose name will be compared
 * @param t_name Which will be compared with Product's name
 * @return true if p.GetName() = t_name
 * @return false if p.GetName() != t_name
 */
bool Category::CompareByName(const Product& p, const string& t_name) const
{
    return (p.GetProductName() == t_name);
}

