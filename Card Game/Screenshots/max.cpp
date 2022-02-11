#include<iostream>

using namespace std;

int max(int x)
{   
    static int maxnum= -1000;
    if(x>maxnum)
        maxnum=x;
    return maxnum;
}


int main()
{
    cout<<max(1)<<endl;
    cout<<max(19)<<endl;
    cout<<max(5)<<endl;
}