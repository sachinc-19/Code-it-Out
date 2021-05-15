                                            // S@CHIN
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fon(n) for(int i=0;i<n;i++)
#define fo(n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll ,ll>
#define vii vector<int>
#define vll vector<ll>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define M (1000*1000*1000+7)
#define test ll T; cin>>T; while(T--)
#define all(z) z.begin() , z.end()
#define allr(z) z.rbegin() , z.rend()
// =============================================

int prime[60];
int dp[12][2][60][60];
void get_prime()
{
    // memset(prime , 1 , sizeof(prime));
    fill(prime , prime+60 , 1);
    prime[0] = prime[1] = 0;

    for(int i = 2 ; i*i < 60 ; i++)
    {
        if(prime[i])
        for(int j = i*i ; j < 60 ; j += i)
        {
            prime[j] = 0;
        }
    } 
}

int is_prime(int even , int odd , int n)
{
    if(n%2==1)
    swap(even, odd);

    int diff = even - odd;
    
    if(diff > 0)
     return prime[diff];
    else
     return 0; 
}

int sum(string &s , int p = 0, int even = 0 , int odd = 0 , int e = 1)
{
    if(p>=s.size())
    {
      return is_prime(even , odd , s.size()); 
    }
    if(dp[p][e][odd][even]!=-1)
      return dp[p][e][odd][even];

    int res = 0 , ulim = 9;
    if(e)
        ulim = s[p]-'0';

    for(int i = 0 ; i <= ulim ; i++)
    {
        int od = odd , ev = even;
        if(p&1)
         od += i;
        else
         ev += i;
        
        if(e && i == s[p]-'0')
          res += sum(s , p+1 , ev , od , 1);
        else
        {
            res += sum(s , p+1 , ev , od , 0);
        }
    }
    return dp[p][e][odd][even] = res;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   get_prime();
   test
   {
      memset(dp , -1 , sizeof(dp));

      string a , b;
      cin >> a >> b;
      
      int temp = stoi(a) ;
      a = to_string(temp-1);

      int ans1 = sum(b);
      memset(dp , -1 , sizeof(dp));

      int ans2 = sum(a);

      cout << ans1-ans2 << endl;

   }
}