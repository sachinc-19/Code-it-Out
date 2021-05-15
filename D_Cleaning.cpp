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

bool check(vii a , int n)
{
    for(int i = 0 ; i < n-1 ; i++)
    {
        if(a[i] > a[i+1])
        {
            return false;
        }
        a[i+1] -= a[i];
        a[i] = 0;
    }
    return (a[n-1] == 0);
}
void solve()
{
    int n;
    cin >> n;
    vii a(n+2 , 0);
    fo(i , n) cin >> a[i];
    vii p = a;
    vii s = a;
    for(int i = 1 ; i <=n ; i++)
    {
        p[i] = p[i] - p[i-1];
    }
    for(int i = n ; i >= 1 ; i--)
    {
        s[i] = s[i] - s[i+1];
    }
    for(int i = 1 ; i < n;  i++)
    {
      vii b = {p[i-1] , a[i+1] , a[i] , s[i+2]};
      vii c = {p[i-1] , a[i] , a[i+1] , s[i+2]};
      if(check(b , 4) || check(c , 4))
       {
           cout << "YES" << endl;
           return;
       }
    }
    cout << "NO" <<endl;
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