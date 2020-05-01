#include<bits/stdc++.h>
#include<vector>;
using namespace std;
typedef long long int number;

number primefactor(number num){

	number x1=0; // Only for 2
	while(num%2==0)
	{
		num = num/2;
		x1++;
	} 

	number x2 = 0;
	for(number i=3;i<=sqrt(num);i+=2)
	{
		number x = 0; // loop
		while(num%i==0)
		{
			x++;
			num = num/i;
		}
		x2+=x;
	}

	number x3=0;
	if(num>2)
		x3 = 1;

	return (x1+x2+x3);
}

int main(){

	number n;
	cin >> n;
	vector<number> A;
	number temp;
	for(number i=0;i<n;i++)
	{
		cin>>temp;
		A.push_back(temp);
	}


	number test;
	cin >> test;
	while(test--)
	{
		number L,R;
		cin >> L >> R;
		number result=0;
		for(number i=L;i<=R;i++)
		{
			result += primefactor(A[i]);
		}
		cout << result << endl;
	}
}