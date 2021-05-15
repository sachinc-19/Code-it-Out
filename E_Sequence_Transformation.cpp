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
// ===================================================================
 
const int maxn = 1e6 + 6;
int ans[maxn];
int ptr = 0;
void rec(int n , int x)
{
    if(n == 0) return;
    else if(n == 3){
        ans[ptr++] = x; ans[ptr++] = x; ans[ptr++] = 3*x;
        return;
    }
    for (int  i = 0; i < n; i+=2)
    {
        ans[ptr++] = x;
    }
    rec(n/2 , x*2);
}
void solve()
{
    int n;
    cin >> n;
    rec(n , 1);
    fon(i , n) cout << ans[i] << " ";
    cout << endl;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}