                               // CPP
#include<bits/stdc++.h>
using namespace std;
//include <ext/pb_ds/assoc_container.hpp>
//include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define fon(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define eb emplace_back
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
#define memo(oo , zz) memset(oo , zz , sizeof(oo))
// =============================================
//1.integer overflow (1e5 * 1e5) (2e9 + 2e9)

bool s_prime(ll n) 
{ 
    if(n<=1)  return false; 
    if(n<=3)  return true; 
    if(n%2==0||n%3==0) return false; 
    for(ll i=5; i*i<=n; i=i+6) 
    if (n%i == 0 || n%(i+2) == 0) 
    return false; 
    return true; 
}
void solve()
{
   int n;
   cin >> n;

   int a[n];
   int idx = -1 ;
   int mn = INT_MAX;
   fon(i , n)
   {
       cin >> a[i];
       if(mn > a[i])
       {
           mn = a[i];
           idx = i;
       }
   }
   cout << n-1 << endl;
   int x , y;
   x = mn+1;
   int i = mn+2;  
//    for(i ; i <= 2e9 ; i++)
//    {
//        if(s_prime(i))
//         {
//             x = i;
//             break;
//         }
//    }
   for(i ; i <= 2e9 ; i++)
   {
       if(s_prime(i))
        {
            y = i;
            break;
        }
   }
   fon(i , n)
   {
       if(idx == i)
       {
           continue;
       }
       cout << i+1 <<  " " << idx+1 << " ";
       if(i % 2) cout <<x << " ";
       else cout << y << " ";
       cout << mn << endl;
   }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   test
   {
      solve();
   }
}