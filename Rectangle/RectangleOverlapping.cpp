#include<iostream>
using namespace std;
struct Points
{
    int x,y;
};

class RectangleOverlap
{
    public:
    bool OverlapCheck(Points tl1, Points br1, Points tl2, Points br2)//Taking Top Left and Bottom Right points 
                                                                 //of both triangles
    {
        
        //if rectangles are on top of each other
        if(br1.y>=tl2.y || br2.y>=tl1.y)
            return false;
        //if rectanles are side by side
        if(tl1.x>=br2.x || tl2.x>=br1.x)
            return false;
        return true;
    }
};
int main()
{
    Points tl1,br1,tl2,br2;
    cout<<"Input x and y coordinates for Top Left points of Rectangle 1: ";
    cin>>tl1.x>>tl1.y;
    cout<<"Input x and y coordinates for Bottom Right points of Rectangle 1: ";
    cin>>br1.x>>br1.y;
    cout<<"Input x and y coordinates for Top Left points of Rectangle 2: ";
    cin>>tl2.x>>tl2.y;
    cout<<"Input x and y coordinates for Bottom Right points of Rectangle 2: ";
    cin>>br2.x>>br2.y;

    RectangleOverlap obj;

    cout<<"\nDo Rectangles Overlap?\n";
    if(obj.OverlapCheck(tl1,br1,tl2,br2)==0)
        cout<<"False";
    else
        cout<<"True";
}