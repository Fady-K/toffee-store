#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "./src/Product.cpp"
#define endl "\n"


int main()
{
   Product p("T.v", "Electronics", "None", 4000, 3);
   p.SetDescription("Television, or TV, is a dynamic medium that brings the world into your home. With its vibrant colors, high-quality images, and crystal-clear sound, TV has the power to entertain, educate, and inform audiences of all ages. Whether you're watching the latest blockbuster movie");
   p.DecreaseAmount(1);
   p.IncreaseAmount(5);
    
    cout << p << endl;
    

    return 0;
}
