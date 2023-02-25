#include <string>
#include <unordered_map>
using namespace std;
class items;
class cart;

class Product
{
   /// @brief 
   int id;
   string name;
   int price;
   public:
   Product(){

   }
   Product(int u_id, string name, int price)
   {
     id = u_id;
     this->name = name;
     this->price = price;
   }
   string getDisplayName()
   {
     return name + " : Rs " + to_string(price) + "\n";
   }
   string getShortName(){
     return name.substr(0,1);
   }
  friend class items;
  friend class cart;
};

class items{
     Product product;
    int quantity;
    public:
    //constructor using initiallization list
    items(){}
    items(Product p, int q):product(p), quantity(q){}
    int getitemprice()
    {
        return quantity*product.price;
    }
    string getiteminfo()
    {
        return to_string(quantity) + " x " + product.name  + " Rs " + to_string(quantity*product.price);
    }
    friend class cart;
};

class cart{
 //collection
  unordered_map<int, items> item;
  public: 
  void addProduct(Product product){
    if(item.count(product.id)==0){
        items newItem(product, 1);
        item[product.id] = newItem;
    }
    else{
        item[product.id].quantity += 1;
    }
    
  }
  int getTotal(){
     int total = 0;
     for(auto itemPair : item){
        auto items = itemPair.second;
        total += items.getitemprice();
     }
     return total;
  }
  string viewcart(){
    if(item.empty()){
        return "cart is empty";
    }
    string itemizedList;
    int cart_total = getTotal();
    for(auto itemPair : item){
        auto items = itemPair.second;
        itemizedList.append(items.getiteminfo());
    } 
    return itemizedList + "\n Total Amount : Rs. " + to_string(cart_total) + '\n';
  }
  bool isEmpty(){
    return item.empty();
  }
};