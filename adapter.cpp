#include <bits/stdc++.h>
using namespace std;


class IAdapter {
    public:
        virtual ~IAdapter() {}
        virtual void getJsonData() = 0; 
};

class XMLDataProvider {
private:
    string xml;
public:
    XMLDataProvider(string xml): xml(xml) {}
    string getXMLData() {
        return this->xml + " Converted to XML Data";
    }
};

class XMLDataProviderAdapter : public IAdapter {
private:
    XMLDataProvider* xml;
public:
    XMLDataProviderAdapter(string website)
    {
        xml = new XMLDataProvider(website);
    }
    void getJsonData() override{
        cout<<"Converting to JSON Data From XML Data"<<endl;
        cout<<"The Json Data is - "<<xml->getXMLData();
    }
};

class Client {
    private:
        IAdapter* a;    
    public:
        Client(string  website){
            a = new XMLDataProviderAdapter(website);
        }
        void obtainData(){
            a->getJsonData();
        }
};

int main()
{
    Client* myClient = new Client("www.airbnb.com");
    myClient->obtainData();
    return 0;
}