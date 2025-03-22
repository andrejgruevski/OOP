//
// Created by Huhe on 3/8/2025.
//
#include "iostream"
#include "cstring"
using namespace std;
class Product{
private:
    char name[100];
    int id;
    char category[100];
    double price;
    int quantity;
public:
   Product(){

   }
    Product(char *n, int idd, char *cat, double cena, int kolichina){
        strcpy(name,n);
        id = idd;
        strcpy(category,cat);
        price = cena;
        quantity = kolichina;


    }

    const char *getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Product::id = id;
    }

    const char *getCategory() const {
        return category;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Product::price = price;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        Product::quantity = quantity;
    }
    void setName(char *namee){
        strcpy(name,namee);
    }
    void setCategory(char *cat){
        strcpy(category,cat);
    }
    void print(){
        cout<<"Name: "<<name<<", Id: "<<id<<", Price: "<<price<<", Quantity: "<<quantity<<endl;
    }
};
void printByCategory(Product *products, int n, const char *category ){
    double suma = 0;
    bool found = false;
    cout<<"Category: "<<category<<endl;
    for (int i = 0; i < n; ++i) {

        if (strcmp(products[i].getCategory(),category)==0){
            products[i].print();
            suma += products[i].getPrice() * products[i].getQuantity();
            found = true;
        }
    }
    if (found){
        cout<<"Total sum : "<<suma<<endl;
    }

}
int main()
{
    int m;
    cin>>m;
    if(m==0)
    {
        cout<<"---Testing constructor with arguments and print()---"<<"\n";
        char name[100]={'B','o','o','k'};
        int id = 1;
        char category [100] = {'B','o','o','k','s'};
        double price = 14.99;
        int quantity = 3;


        Product product = Product(name, id, category, price, quantity);

        product.print();
    }
    else if(m==1)
    {
        cout<<"---Testing get and set methods---"<<"\n";
        char name[100]={'B','o','o','k'};
        int id = 1;
        char category [100] = {'B','o','o','k','s'};
        double price = 14.99;
        int quantity = 3;
        Product product;
        product.setName(name);
        product.setId(id);
        product.setCategory(category);
        product.setPrice(price);
        product.setQuantity(quantity);
        cout<<"Name: "<<product.getName()<<endl;
        cout<<"Id: "<<product.getId()<<endl;
        cout<<"Category: "<<product.getCategory()<<endl;
        cout<<"Price: "<<product.getPrice()<<endl;
        cout<<"Quantity: "<<product.getQuantity()<<endl;

    }
    else if(m==2)
    {
        const int numProducts = 8;
        Product products[numProducts];

        for (int i = 0; i < numProducts; ++i) {
            char name[100];
            int id;
            char category[100];
            double price;
            int quantity;


            cin>>name>>id>>category>>price>>quantity;

            products[i] = Product(name, id, category, price, quantity);
        }


        cout<<"---Testing function---"<<"\n";
        printByCategory(products, numProducts, "Electronics");
        cout << endl;
        printByCategory(products, numProducts, "Clothing");
        cout << endl;
        printByCategory(products, numProducts, "Books");
    }
    return 0;
}
