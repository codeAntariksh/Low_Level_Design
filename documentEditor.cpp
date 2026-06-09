#include<bits/stdc++.h>
using namespace std;

class DocumentElement {
    public:
        virtual string render() = 0;
};


class TextElement : public DocumentElement {
    private:
        string text;
    public:
        TextElement(string text):text(text){};
        string render() override {
            return text;
        }
};

class ImageElement : public DocumentElement {
    private:
        string path;
    public:
        ImageElement(string path):path(path){};
        string render() override {
            return path;
        }
};

class NewLineElement : public DocumentElement {
    public:
        string render() override {
            return "\n";
        }
};

class TabSpaceElement : public DocumentElement {
    public:
        string render() override {
            return "\t";
        }
};

class Document {
    private:
        vector<DocumentElement*> documentElements;
    public:
        void addElement(DocumentElement* element)
        {
            documentElements.push_back(element);
        }

        string render()
        {
            string result;
            for(auto element:documentElements)
            {
                result+=element->render();
            }
            return result;
        }
};


class Persistence {
    public:
        virtual void save() = 0;
};

class DBStorage : public Persistence {
    public:
        void save(string document) override{
            // Logic
            cout<<"Stored in DB"<<endl;
        }
};

class DocumentEditor {
    private:
        Document* document;
        Persistence* storage;
        string renderedDocument;
    public:
        DocumentEditor(Document* document,Persistence* storage):document(document),storage(storage){};
        void addText(string text)
        {
            document->addElement(new TextElement(text));
        }
        void addImage(string text)
        {
            document->addElement(new TextElement(text));
        }
        void addNewLine()
        {
            document->addElement(new NewLineElement());
        }
        void addTabSpace()
        {
            document->addElement(new TabSpaceElement());
        }
        string renderDocument()
        {
            if(renderedDocument.empty())
            {
                renderedDocument = document->render();
            }
            return renderedDocument;
        }
        void saveDocument() {
            storage->save(renderDocument());
        }
};











int main()
{
    Document* document;
    Persistence* persistence;
    DocumentEditor editor(document,persistence);
    editor.addText("Hello World");
    editor.addText("Hii! Ami Antarikshya");
    editor.addImage("https://amarimage.jpg");
    editor.saveDocument();
    return 0;
}