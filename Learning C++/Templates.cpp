#include<iostream>
#include<math.h>
using namespace std;

template <typename T>
T square(T n)
{
    return n*n;
}
int main()
{
    while(true)
    {
        cout << "Enter Type"<<endl;
        cout << "1-Integer 2-Float 3-Double"<<endl;
        int ch; cin>>ch;
        switch(ch)
        {
            case 1 : {
                cout<<"Enter Integer"<<endl;
                int temp; cin>>temp;
                cout<<square(temp)<<endl;
            }break;
            case 2 : {
                cout<<"Enter Float"<<endl;
                float temp; cin>>temp;
                cout<<square(temp)<<endl;
            }break;
            case 3 :{
                cout<<"Enter Double"<<endl;
                double temp; cin>>temp;
                cout<<square(temp)<<endl;
            }break;
            default:
               {   cout<<"Invalid Type"<<endl;  }
        }
    }
    return 0;
}
