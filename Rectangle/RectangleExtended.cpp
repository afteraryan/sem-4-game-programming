#include<iostream>
using namespace std;
struct Points
{
    int x,y;
};

class RectangleOverlap
{
    public:
    bool OverlapCheck(Points TopLeft1, Points BottomRight1, Points TopLeft2, Points BottomRight2)
    //Taking Top Left and Bottom Right points of both triangles
    {
        
        //if rectangles are on top of each other
        if(BottomRight1.y>=TopLeft2.y || BottomRight2.y>=TopLeft1.y)
            return false;
        //if rectanles are side by side
        if(TopLeft1.x>=BottomRight2.x || TopLeft2.x>=BottomRight1.x)
            return false;
        return true;
    }

    void InsideCheck(Points TopLeft1, Points BottomRight1, Points TopLeft2, Points BottomRight2)
    //Taking Top Left and Bottom Right points of both triangles
    {
        
        //if rectangles are on top of each other
        if(BottomRight1.x>BottomRight2.x && BottomRight1.y<BottomRight2.y && TopLeft1.x<TopLeft2.y && TopLeft1.y>TopLeft2.y)
            cout<<"\nRectange 2 is inside Rectangle 1!";
        else if(BottomRight1.x<BottomRight2.x && BottomRight1.y>BottomRight2.y && TopLeft1.x>TopLeft2.y && TopLeft1.y<TopLeft2.y)
            cout<<"\nRectange 1 is inside Rectangle 2!";
        else
            cout<<"\nRectangles are NOT inside each other";
        
    }

    void BiggerCheck(Points TopLeft1, Points BottomRight1, Points TopLeft2, Points BottomRight2)
    {
        float AreaRect1 = (TopLeft1.y-BottomRight1.y)*(BottomRight1.x-TopLeft1.x);
        float AreaRect2 = (TopLeft2.y-BottomRight2.y)*(BottomRight2.x-TopLeft2.x);
        if(AreaRect1>AreaRect2)
            cout<<"\nRectangle 1 is Bigger";
        else if(AreaRect2>AreaRect1)
            cout<<"\nRectangle 2 is Bigger";
        else
            cout<<"\nBoth Rectangles have equal area";

    }
};
int main()
{
    Points TopLeft1,BottomRight1,TopLeft2,BottomRight2;
    cout<<"Input x and y coordinates for Top Left points of Rectangle 1: ";
    cin>>TopLeft1.x>>TopLeft1.y;
    cout<<"Input x and y coordinates for Bottom Right points of Rectangle 1: ";
    cin>>BottomRight1.x>>BottomRight1.y;
    cout<<"Input x and y coordinates for Top Left points of Rectangle 2: ";
    cin>>TopLeft2.x>>TopLeft2.y;
    cout<<"Input x and y coordinates for Bottom Right points of Rectangle 2: ";
    cin>>BottomRight2.x>>BottomRight2.y;

    RectangleOverlap obj;

    cout<<"\nDo Rectangles Overlap?\n";
    if(obj.OverlapCheck(TopLeft1,BottomRight1,TopLeft2,BottomRight2)==0)
        cout<<"False";
    else
        cout<<"True";

    obj.InsideCheck(TopLeft1,BottomRight1,TopLeft2,BottomRight2);
    obj.BiggerCheck(TopLeft1,BottomRight1,TopLeft2,BottomRight2);
    
}