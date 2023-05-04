#pragma once
#include "../src/Category.cpp"

class CategoriesManger
{
private:
    vector<Category> t_categoires;
    int n_categories;


public:
    /* Constructors and Destructor */
    CategoriesManger();                                          // Default constructor
    CategoriesManger(vector<Category>& t_pCategories);            // Parametrized constructor
    ~CategoriesManger();                                         // Destructor

    /* Setters And Getters (encapsulation) */
    void SetCategories(vector<Category>& t_pCategories);
    vector<Category> GetCategories() const;

    void SetNumberCategoriesNumber(const int n);
    int GetNumberOfCategories() const;


    /* Instane Methods */
    Category AddCategory(const string& t_catName, vector<Product> t_prodcucts=vector<Product>(0));
    Category RemoveCategory(const string& t_catName);

    void SortCategories(const bool& ascendingOrder=true);
    int SearchCategoryByName(const string& t_catName) const;
    Category& GetCategoryByName(const string& t_catName);
    void DisplayAllCategories() const;

    bool IsEmpty() const;
    bool Exists(const string& t_catName) const;
    void Clear();


    /* Operators Overloading */
    Category& operator[](const int index);                  // Arr indexing operator


private:
    bool CompareCategroriesByName(const Category& t_cat, const string& t_catName) const;
};

