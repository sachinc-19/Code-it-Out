#include<bits/stdc++.h>
#pragma GCC target ("sse4.2")
using namespace std;
//include <ext/pb_ds/assoc_container.hpp>
//include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define ld long double
#define fon(od1,n) for(int od1=0;od1<n;od1++)
#define fo(od1,n) for(int od1=1;od1<=n;od1++)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll ,ll>
#define vii vector<int>
#define vll vector<ll>
#define vvii vector<vii>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define setbits(x) __builtin_popcountll(x)
#define M (1000*1000*1000+7)
#define test ll T; cin>>T; while(T--)
#define all(z) z.begin() , z.end()
#define allr(z) z.rbegin() , z.rend()
#define sp(x,y)    fixed << setprecision(x) << y
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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &od1: x) cerr << (f++ ? "," : ""), __print(od1); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// ===================================================================

ll gcd(ll a , ll b){
    return __gcd(a , b);}

ll lcm(ll a , ll b){
    return (a*b)/__gcd(a , b);}

ll mod(ll x){
    return ((x % M + M) % M);}

ll add(ll a , ll b){
    return mod(mod(a) + mod(b));}

ll mul(ll a , ll b){
    return mod(mod(a) * mod(b));}

bool sortbysec(pair<int ,int> &a , pair<int , int> &b)
{
    return a.ss > b.ss;
}

const int maxn = 1e5;
constexpr long long INF = 1e18;
ll rgb(vll a , vll b)
{
    ll ans = INF;
    int i = 0 , j = 0;
    while(i < a.size() &&  j < b.size())
    {
       ll x = abs(a[i] - b[j]);
       if(ans > x)
       {
           ans = x;
       }
        if(a[i] < b[j]) i++;
        else j++;
    }
    return ans;
}
void solve()
{
    ll n , x;
    cin >> n;
    n *= 2;
    vll r , g , b;
    fon(i , n)
    {
        char c;
        cin >> x >> c;
        if(c == 'R') r.eb(x);
        else if(c == 'G') g.eb(x);
        else b.eb(x);
    }
    if(r.size() % 2==0 && g.size() % 2 ==0 && b.size() % 2 == 0)
    {
        cout << 0 << endl;
        return;
    }
    sort(all(r));
    sort(all(g));
    sort(all(b));
    ll rgmin = rgb(r , g);
    ll gbmin = rgb(g , b);
    ll rbmin = rgb(r , b);
    ll ans = INF;
    if(r.size() % 2==0)
    {
       ans = min({ans , gbmin , rgmin + rbmin});
    }
    else if(g.size() % 2 == 0)
    {
       ans = min({ans , rbmin , rgmin + gbmin});
    }
    else 
    {
       ans = min({ans , rgmin , rbmin + gbmin});
    }
    cout << ans << endl;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}