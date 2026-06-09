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
        virtual void saveToDB(ShoppingCart* cart) = 0;
};

class SQLDB : public ShoppingCartStorage {
    public:
        SQLDB(ShoppingCart* cart):ShoppingCartStorage(cart){};
        void saveToDB(ShoppingCart* cart) override
        {
            cout<<"Saving Shopping Cart to SQL Database"<<endl;
        }
};

class MongoDB : public ShoppingCartStorage {
 public:
        MongoDB(ShoppingCart* cart):ShoppingCartStorage(cart){};
        void saveToDB(ShoppingCart* cart) override
        {
            cout<<"Saving Shopping Cart to MongoDB Database"<<endl;
        }
};

class FileDB : public ShoppingCartStorage {
    public:
        FileDB(ShoppingCart* cart):ShoppingCartStorage(cart){};
        void saveToDB(ShoppingCart* cart) override
        {
            cout<<"Saving Shopping Cart to File Database"<<endl;
        }    
};

int main()
{
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop",1500));
    cart->addProduct(new Product("Mouse",500));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->PrintInvoice();

    ShoppingCartStorage* sql = new SQLDB(cart);
    ShoppingCartStorage* mongo = new MongoDB(cart);
    ShoppingCartStorage* file = new FileDB(cart);

    sql->saveToDB(cart);
    mongo->saveToDB(cart);
    file->saveToDB(cart);
    

    return 0;
}
