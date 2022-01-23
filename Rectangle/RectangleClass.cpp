#include <iostream>
using namespace std;

class Rectangle
{
    public:
    float length,breadth;
    Rectangle(int l,int b)
    {
        length=l;    
        breadth=b;  
        if(length<=0 || breadth<=0)
            cout<<"Invalid Entry\n";
    }
    int getArea()
    {
        return length*breadth;
    }
};
int main()
{
    Rectangle rect= Rectangle(20,20);
    int area = rect.getArea();
    cout << "Area of the rectangle : " << area << endl;
    return 0;
}