#include<iostream>
using namespace std;
long long mypow ( long long a , long long b , long long k ) {
if ( b == 0 )
return 1 ;
long long tmp = mypow ( a , b /2 , k ) ;
if ( ( b % 2 ) == 1 )
{
return ( ( ( tmp * tmp ) % k ) * a ) % k ;
}
else
{
return ( tmp * tmp ) % k ;
}
}
int main()
{
	int t, p, a;
	cin>>t>>p>>a;
	cout<<mypow(t,p,p-2);
	cin.get();
	return 0;
	
}
