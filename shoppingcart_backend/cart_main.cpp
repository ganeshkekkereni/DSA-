#include <iostream>
#include <vector>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(2, "guava", 36),
    Product(3, "mango", 16),
    Product(4, "strawberry", 29),
    Product(5, "banana", 10),
    Product(6, "pineapple", 20),
};

Product* chooseProduct()
{
    //display the list of products
    string productList;
    cout<<"Available Products "<<endl;
    for(auto product: allProducts)
    {
        productList.append(product.getDisplayName());   
    }
    cout<<productList <<endl;
    cout<<"------------"<<endl;
    string choice;
    cin>>choice;
    for(int i = 0; i<allProducts.size(); i++){
        if(allProducts[i].getShortName()==choice)
        {
            return &allProducts[i];
        }
    }
    cout<<"Product not found"<<endl;
    return NULL;

}
int main()
{
    /*Product p(1, "apple", 26);
    cout<<p.getDisplayName();
    items fruit(p, 3);
    cout<<fruit.getiteminfo();
    */
    char action;
    while(true)
    {
        cout<<"select an action = (a)dd item, (v)iew cart, (c)heckout"<<endl;
        cin>>action;
        cart cart;
        if(action=='a')
        {
            //Todo : Add to cart
            // view all products + choose product + add to the cart
            Product * product = chooseProduct();
            if(product != NULL)
            {
                cout<<"Added to the cart "<<product->getDisplayName()<<endl;
                //todo:
                cart.addProduct(*product);
            }
        }
        else if(action == 'v')
        {
            //view the cart
            cout<<"------------"<<endl;
            cout<<cart.viewcart()<<endl;;
            cout<<"------------"<<endl;
        }
        else{
            //simply checkout
        }

    }

    
    return 0;
}