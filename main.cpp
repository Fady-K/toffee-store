#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
// #include "./src/Product.cpp"
#include "./src/CategoriesManger.cpp"
#define endl "\n"


int main()
{
//    Product p("T.v", "Electronics", "None", 4000, 3);
//    p.SetDescription("Television, or TV, is a dynamic medium that brings the world into your home. With its vibrant colors, high-quality images, and crystal-clear sound, TV has the power to entertain, educate, and inform audiences of all ages. Whether you're watching the latest blockbuster movie");
//    p.DecreaseAmount(1);
//    p.IncreaseAmount(5);


    Category electorincs("Electronics");

    electorincs.AddProduct("T.V", "", 5000, 10);
    electorincs.AddProduct("Sweeper", "", 5000, 10);
    electorincs.AddProduct("Laptop", "", 20000, 5);

    Category Dairy("Dairy");
    Dairy.AddProduct("Milik", "", 23, 20);
    Dairy.AddProduct("Butter", "", 250, 40);
    Dairy.AddProduct("Cheese", "", 40, 20);
    // electorincs.DisplayAllProducts();

    vector<Category> cats = {electorincs, Dairy};

    CategoriesManger m(cats);
    // m.SortCategories(false);
    // m.Clear();
    // cout << m.Exists("Dairy") << endl;
    // m.RemoveCategory("Dairy")
    cout << m.GetCategoryByName("Dairy");
    // m.DisplayAllCategories();

    // cout << electorincs.SearchProductByName("T.V") << endl;
    // cout << electorincs.GetProductByName("T.V").IncreaseAmount(20) << endl;
    // cout << electorincs.GetName() << endl;
    // cout << electorincs.GetNumberOfProducts() << endl;
    // cout << electorincs.GetAllProducts()[0] << endl;
    // electorincs.Clear();

    // cout << electorincs << endl;
    // cout << Dairy << endl;
    // cout << electorincs << endl;
    // cout << electorincs << endl;
    // electorincs.DisplayAllProducts();

   
    
    // cout << p << endl;
    

    return 0;
}
