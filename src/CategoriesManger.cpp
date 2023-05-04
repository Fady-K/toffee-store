#include "../include/CategoriesManger.hpp"


////////////////////////////////////////////////////// Constructor And Destructor ////////////////////////////////////////////////////////////
/**
 * @brief Construct a new Categories Manger:: Categories Manger object
 * @details Default contructor
 */
CategoriesManger::CategoriesManger(): n_categories(0){}              


/**
 * @brief Construct a new Categories Manger:: Categories Manger object
 * @details Parametrized constsurctor
 * @param t_categories Vector of Categories that need to be managed
 */
CategoriesManger::CategoriesManger(vector<Category>& t_pCategories)
{
    // init size of n prodcut with passed size
    n_categories = t_categoires.size();

    // equalize member with passed vector
    this->t_categoires = t_pCategories;
}


/**
 * @brief Destroy the Categories Manger:: Categories Manger object
 * 
 */
CategoriesManger::~CategoriesManger(){}


/////////////////////////////////////////////////////////// Setters And Getters (encapsulation) //////////////////////////////////////////////////
/**
 * @brief Set categories to manage
 * 
 * @param t_categories Categories that will be managed
 */
void CategoriesManger::SetCategories(vector<Category>& t_pCategories)
{
    // init member with passed on 
    this->t_categoires = t_pCategories;

    // update size
    this->n_categories = t_pCategories.size();
}


/**
 * @brief Get all Categories by value (you can't modify any them as it returns a copy not a reference)
 * 
 * @return vector<Category> Categories that are beening menaged 
 */
vector<Category> CategoriesManger::GetCategories() const
{
    return this->t_categoires;
}


/**
 * @brief Take number from user and set n_categories membor to that number
 * 
 * @param n Number of categories that will be manged
 */
void CategoriesManger::SetNumberCategoriesNumber(const int n)
{
    this->n_categories = n;
}


/**
 * @brief Returns Totla nubmer of categories beening managed
 * 
 * @return int Total number of categories
 */
int CategoriesManger::GetNumberOfCategories() const
{
    return n_categories;
}



///////////////////////////////////////////////////////////// Instance Methdos /////////////////////////////////////////////////

Category CategoriesManger::AddCategory(const string& t_catName, vector<Product> t_products)
{
    // instanciate a category with given name and products
    Category cat(t_catName, t_products);

    // check capacity
    if (t_categoires.capacity() - t_categoires.size() < 5)
    {
        // emplace back so that increase it's capacity
        t_categoires.emplace_back(cat);
    }
    else
    {
        // meaning there is enought space
        this->t_categoires[n_categories++] = cat;
    }


    // return the added one
    return cat;
}


Category CategoriesManger::RemoveCategory(const string& t_catName)
{
    // check if cat with such name exists
    auto it = find_if(t_categoires.begin(), t_categoires.end(), [&](const Category& t_cat) { return CompareCategroriesByName(t_cat, t_catName); });

    if (it != t_categoires.end())
    {
        // if found erase it, decrment number of categories, return the earsed one
        // store it in temp variable so that i be able to return it
        Category removedCategory = (*it);

        // erase it
        this->t_categoires.erase(it);

        // (*this).DisplayAllCategories();

        // decrement number of cat
        this->n_categories --;

        return removedCategory;
    }
    else
    { 
        printf("!................................. Couldn't Find Category Named: %s ..................................!\n", t_catName.c_str());
    
        // return empty cat
        return Category();        
    }
    
}


void CategoriesManger::SortCategories(const bool& ascendingOrder)
{
    if (ascendingOrder)
    {
        // asending order
        sort(t_categoires.begin(), t_categoires.end());
    }
    else
    {
        // descending order by passing reverse iterator
        sort(t_categoires.rbegin(), t_categoires.rend());
    }
}


int CategoriesManger::SearchCategoryByName(const string& t_catName) const
{
    // check if exists and matchs givend name
    auto it = find_if(t_categoires.begin(), t_categoires.end(), [&](const Category& t_cat) {return CompareCategroriesByName(t_cat, t_catName); });

    if (it != t_categoires.end())
    {
        // if found then reutrn its index (v.begin() - it)
        return (it - t_categoires.begin());
    }
    else
    { 
        printf("!................................. Couldn't Find Category Named: %s ..................................!\n", t_catName.c_str());
    
        // return empty cat
        return -1;        
    }
}


Category& CategoriesManger::GetCategoryByName(const string& t_catName)
{
    const int index = SearchCategoryByName(t_catName);

    if (index == -1)
    {
        throw runtime_error("!! Couldn't Find Category !!\n");
    }
    else
    {
        return (*this)[index];
    }
}


void CategoriesManger::DisplayAllCategories() const
{
    if (IsEmpty())
    {
        printf("!................................ Manger Is Empty ..................................!\n");
    }
    else
    {
        // iterate over them and print each
        for (auto it = t_categoires.begin(); it != t_categoires.end(); it++)
        {
            cout << (*it) << endl;
        }
    }
}


bool CategoriesManger::IsEmpty() const
{
    return t_categoires.empty();
}

bool CategoriesManger::Exists(const string& t_catName) const
{
    auto it = find_if(t_categoires.begin(), t_categoires.end(), [&](const Category& t_cat){return CompareCategroriesByName(t_cat, t_catName); });

    if (it != t_categoires.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}


void CategoriesManger::Clear()
{
    if (IsEmpty())
    {
        printf("!................................ Manger Is Empty ..................................!\n");
        return;
    }
    else
    {
        // clear it
        t_categoires.clear();
        n_categories = 0;

        printf("!................................ Categories Have Been Cleared ..........................!\n");

    }

}





////////////////////////////////////////////////////// Operators Overloading /////////////////////////////////////////
Category& CategoriesManger::operator[](const int index)
{
    return this->t_categoires.at(index);
}












////////////////////////////////////////////////////////////////// Helper Functions //////////////////////////////////////////////////////////
bool CategoriesManger::CompareCategroriesByName(const Category& t_category, const string& t_catName) const
{
    return t_category.GetName() == t_catName;
}