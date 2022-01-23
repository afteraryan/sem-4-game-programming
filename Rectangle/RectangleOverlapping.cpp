#include<iostream>
using namespace std;
struct Points
{
    int x,y;
};

class RectangleOverlap
{
    public:
    bool OverlapCheck(Points l1, Points r1, Points l2, Points r2)//Taking Top Left and Bottom Right points 
                                                                 //of both triangles
    {
        
        //if rectangles are on top of each other
        if(r1.y>=l2.y || r2.y>=l1.y)
            return false;
        //if rectanles are side by side
        if(l1.x>=r2.x || l2.x>=r1.x)
            return false;
        return true;
    }
};
int main()
{
    Points l1,r1,l2,r2;
    cout<<"Input x and y coordinates for Top Left points of Rectangle 1: ";
    cin>>l1.x>>l1.y;
    cout<<"Input x and y coordinates for Bottom Right points of Rectangle 1: ";
    cin>>r1.x>>r1.y;
    cout<<"Input x and y coordinates for Top Left points of Rectangle 2: ";
    cin>>l2.x>>l2.y;
    cout<<"Input x and y coordinates for Bottom Right points of Rectangle 2: ";
    cin>>r2.x>>r2.y;

    RectangleOverlap obj;

    cout<<"\nDo Rectangles Overlap?\n";
    if(obj.OverlapCheck(l1,r1,l2,r2)==0)
        cout<<"False";
    else
        cout<<"True";
}