#include<bits/stdc++.h>
using namespace std;

class Product {
    public:
        string name;
        double price;

        Product(string name,double price) {
            this->name = name;
            this->price = price;
        }
};

class ShoppingCart {
    private:
        vector<Product*> products;
    public:
        void addProduct(Product *p)
        {
            products.push_back(p);
        }
        const vector<Product*>& getProducts()
        {
            return products;
        }
        double calculateTotal()
        {
            double total = 0;
            for(auto p:products)
                total+=p->price;
            return total;
        }
};

class ShoppingCartPrinter {
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartPrinter(ShoppingCart* cart)
        {
            this->cart = cart;
        }
        void PrintInvoice()
        {
            cout<<"Shopping Cart Invoice:"<<endl;
            for(auto p:cart->getProducts())
                cout<<p->name<<" "<<" - $"<<p->price<<endl;
            cout<<"Total Purchase: $"<<cart->calculateTotal()<<endl;
        }
};

class ShoppingCartStorage {
    private:
        ShoppingCart* cart;
    public:
        ShoppingCartStorage(ShoppingCart* cart)
        {
            this->cart = cart;
        }
        void saveToDB()
        {
            cout<<"Saving Shopping Cart to DB"<<endl;
        }
};

int main()
{
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mouse",500));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->PrintInvoice();

    ShoppingCartStorage* storage = new ShoppingCartStorage(cart);
    storage->saveToDB();

    return 0;
}
