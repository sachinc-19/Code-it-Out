#include<bits/stdc++.h>
using namespace std;
const int N=1010;
typedef long long int ll;
#define forn(n) for(int i=0;i<n;i++)
#define f(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define mod (1000*1000*1000+7)
#define pi (22/7.0)
#define sq(x) x*x
#define MAX 100000

void solve()
{
    //vector<int>v;
    char str[MAX];
    ll num=0,count=0;
    cin>>str;
    int i=0;
    while(str[i])
    {
    	num+=(int)str[i]-48;
    	i++;
    }
    if(i>1)
    count++;
    while(num>9)
    {
    	ll sum=0;
    	while(num>0)
    	{
    		sum+=num%10;
    		num/=10;
    	}
    	count++;
    	num= sum;
    }
    cout<<count;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
       

	 solve();

	return 0;
}	
