#include<iostream>
#include<cmath>
using namespace std;

const double m = (1+sqrt(5.0))/2;

void check(int a, int b)
{
	int k = a/m;
 
	if ( a == int(k*m) )
	{
		if( b == a + k )
			cout<<"T win";
	}
	else if( a == int((k+1)*m) )
	{
		if( b == a + k + 1 )
			cout<<"T win";
	}
	cout<<"G win";
}


int main(){
    int n,k;
    cin>>n>>k;
	check(n,k);

}