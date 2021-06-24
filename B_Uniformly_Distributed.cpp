#include<bits/stdc++.h>
#pragma GCC target ("sse4.2")
using namespace std;
//include <ext/pb_ds/assoc_container.hpp>
//include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define ld long double
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
#define vvii vector<vii>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define setbits(x) __builtin_popcountll(x)
#define M (998244353)
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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
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

ll modpower(ll x , ll n)
{
     ll res = 1;
     x = mod(x);
     while(n > 0)
     {
         if(n&1)
         res = mul(res , x);
         x = mul(x , x);
         n >>= 1;
     }
     return res;
}
const int maxn = 1e5;
void solve()
{
    int n , m;
    cin >> n >> m;
    string s[n];
    fon(i , n) cin >> s[i];
    ll p = 0;
    for(int j = 0 ; j < m ; j++)
    {
        int i = 0;
        bool f = 1 , fb = 0 , fr = 0;
        for(int k = j ; k >= 0 && i < n ; k--)
        {
            f &= (s[i][k] == '.');
            fr &= (s[i][k] == 'R');
            fb &= (s[i][k] == 'B');
            i++;
        }
        if(fr && fb){
            cout << "0" << endl;
            return;
        }
        p += f;
    }    
    for(int ii = 1 ; ii < n ; ii++)
    {
        int i = ii;
        bool f = 1 , fb = 0 , fr = 0;
        for(int j = m-1 ; j >= 0 && i < n ; j--)
        {
            f &= (s[i][j] == '.');
            fr &= (s[i][j] == 'R');
            fb &= (s[i][j] == 'B');
            i++;
        }
        if(fr && fb){
            cout << "0" << endl;
            return;
        }
        p += f;
    }
    cout << modpower(2LL , p) << endl;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}