# include <iostream>
using namespace std;

class LegacyDevice
{
    public:
    void print()
    {
        cout << "Legacy version of device" << endl;
    }
};

class NewDevice
{
    public:
    virtual void newprint() = 0;
};

class adapter : public NewDevice
{
    LegacyDevice* ptr; // adding a pointer to old class
    public:
    adapter(LegacyDevice* p) : ptr(p) {} // constructor takes the pointer to old class

    void newprint() override
    {
        ptr -> print(); // adapting 
    }
};

class newprinter : public NewDevice
{
    public:
    void newprint() override
    {
        cout << "New version of device" << endl;
    } 
};

int main()
{
    LegacyDevice l;
    newprinter n;
    adapter a(&l);
    a.newprint();
    n.newprint();
    return 0;
}