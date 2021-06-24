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
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// ========================================================================
 
void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    fon(i, n) cin >> a[i];
    ll ans = 0 , ans1 = 0 , ans2 = 0 , cnt1 = 0 , cnt2 = 0;

    ll i =0;
    bool f = 1;
    while(i < n && a[i] < 0) i++;  
    while(i < n)
    {
        if(f)
        {
            ll mx = 0;
            while(i < n && a[i] > 0)
            {
                mx = max(mx , a[i]);
                i++;
            }
            ans1 += mx;
        }
        else
        {
            ll mn = INT_MIN;
            while(i < n && a[i] < 0)
            {
                mn = max(mn , a[i]);
                i++;
            }
            ans1 += mn;
        }
        cnt1++;
        f = !f;
    }
    // debug(ans1);
    i = 0;
    while(i < n && a[i] > 0) i++;
    f = 0;
    while(i < n)
    {
        if(f)
        {
            ll mx = 0;
            while(i < n && a[i] > 0)
            {
                mx = max(mx , a[i]);
                i++;
            }
            ans2 += mx;
        }
        else
        {
            ll mn = INT_MIN;
            while(i < n && a[i] < 0)
            {
                mn = max(mn , a[i]);
                i++;
            }
            ans2 += mn;
        }
        cnt2++;
        f = !f;
    }
    if(cnt1 > cnt2) cout << ans1 << endl;
    else if(cnt1 == cnt2) cout << max(ans1 , ans2) << endl;
    else 
  cout << ans2 << endl;
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