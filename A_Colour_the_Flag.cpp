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
#define M (1000*1000*1000+7)
#define test ll T; cin>>T; while(T--)
#define all(z) z.begin() , z.end()
#define allr(z) z.rbegin() , z.rend()
#define sp(x,y)   fixed << setprecision(x) << y
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

const int maxn = 1e5;
int n , m;
bool is_safe(int x , int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
    return false;
    return true;
}

void solve()
{
    cin >> n >> m;
    string s[n];

    fon(i , n) cin >> s[i];
    int dx[4] = {0 , 1 , 0 , -1};
    int dy[4] = {1 , 0 , -1 , 0};
    int cnt = 0;
    fon(i,n)
    {
        fon(j , m)
        {
            cnt += (s[i][j] == '.');
        }
    }
    if(cnt == n*m)
    {
        s[0][0] = 'R';
    }
    for(int i = 0 ; i < n; i++)
    {
        fon(j , m)
        {
           if(s[i][j] == '.') continue;
           for(int k = 0 ; k < 4 ; k++)
           {
               int x = i+dx[k];
               int y = j+dy[k];
               if(is_safe(x , y))
               {
                   if(s[x][y] == '.')
                   {
                       if(s[i][j] == 'R')
                         s[x][y] = 'W';
                        else 
                         s[x][y] = 'R';
                   }
               }
           }
        }
    }
    for(int i = n-1 ; i >= 0; i--)
    {
        for(int j = m-1 ; j>=0 ; j--)
        {
           if(s[i][j] == '.') continue;
           for(int k = 0 ; k < 4 ; k++)
           {
               int x = i+dx[k];
               int y = j+dy[k];
               if(is_safe(x , y))
               {
                   if(s[x][y] == '.')
                   {
                       if(s[i][j] == 'R')
                         s[x][y] = 'W';
                        else 
                         s[x][y] = 'R';
                   }
               }
           }
        }
    }
    for(int i = 0 ; i < n; i++)
    {
        fon(j , m)
        {
           for(int k = 0 ; k < 4 ; k++)
           {
               int x = i+dx[k];
               int y = j+dy[k];
               if(is_safe(x , y))
               {
                  if(s[i][j] == s[x][y])
                    {
                        cout << "NO" << endl;
                        return;
                    }
               }
           }
        }
    }
    cout << "YES" << endl;
    fon(i , n)
    {
        cout << s[i] << endl;
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