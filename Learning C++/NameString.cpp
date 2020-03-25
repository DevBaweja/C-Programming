// Bjarne Stroustrup - Created c++
// C - Top Down
// C++ - Bottom Up

#include<iostream>
#include<math.h>
// In turbo c++ iostream.h was used
using namespace std;

int main()
{
    cout<<"Print Number n:"<<endl;
    int n; cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
        {
            cout<<"Enter "<<(i+1)<<" Name"<<endl;
            cin>>s[i];
        }
    for(int i=0;i<n;i++)
        cout<<(i+1)<<". "<<s[i]<<endl;
}
