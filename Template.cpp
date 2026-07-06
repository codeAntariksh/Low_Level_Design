#include<bits/stdc++.h>
using namespace std;

class ModelTrainer {
    protected:
        virtual void load(string path) = 0;
        virtual void preprocess() = 0;
        virtual void train() = 0;
        virtual void evaluate() = 0;
        virtual void saveModel() = 0;
    public:
        const void templateMethod(string path){
            load(path);
            preprocess();
            train();
            evaluate();
            saveModel();
        }
        virtual ~ModelTrainer() {}
};

class NeuralNetwork : public ModelTrainer{
    private:
        void load(string path) override {
            cout<<"Data Loaded from Library to "<<path<<endl;
        }
        void preprocess() override {
            cout<<"Data Preprocessed Via LDA"<<endl;
        }
        void train() override{
            cout<<"Neural Network Trained"<<endl;
        }
        void evaluate() override{
            cout<<"Neural Network Evaluated"<<endl;
        }
        void saveModel() override{
            cout<<"Neural Network Model saved"<<endl;
        }
};

class DecisionTree : public ModelTrainer{
    private:
        void load(string path) override {
            cout<<"Data Loaded from Library to "<<path<<endl;
        }
        void preprocess() override {
            cout<<"Data Preprocessed Via LDA"<<endl;
        }
        void train() override{
            cout<<"Decision Tree Trained"<<endl;
        }
        void evaluate() override{
            cout<<"Decision Tree Evaluated"<<endl;
        }
        void saveModel() override{
            cout<<"Decision Tree Model saved"<<endl;
        }
};


int main()
{
    ModelTrainer* mt1 = new DecisionTree();
    ModelTrainer* mt2 = new NeuralNetwork();
    mt1->templateMethod("heart.csv");
    mt2->templateMethod("data.csv");
    return 0;
}