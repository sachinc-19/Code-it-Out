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
 
void solve()
{
    int n ;
    cin >>n;
    
    int a[n];
    fon(i ,n) cin >> a[i];
    vii xr(n+1 , 0);

    xr[0] = a[0];
    for(int i = 1 ; i < n ;i++) xr[i] = xr[i-1] ^ a[i];
    if(xr[n-1] == 0)
    {
        for(int i = 0 ; i < n-1; i++)
        {
            if(xr[i] == (xr[n-1] ^ xr[i]))
            {
                cout << "YES" << endl;
                return;
            }
        }
    } 
    else
    {
        int i = 0;
        while(i < n-2 && (xr[i] != xr[n-1])) i++;
        int j = n-2 , x = a[n-1];
    
        if(xr[i] == xr[n-1])
        {
            while(j-1 > i && x != xr[i]) x ^= a[j--];
            if(x == xr[i] && (xr[j] ^ xr[i]) == x)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
     cout << "NO" << endl;
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