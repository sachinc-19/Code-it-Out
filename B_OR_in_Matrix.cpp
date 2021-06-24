                               // CPP
#include<bits/stdc++.h>
#pragma GCC target ("sse4.2")
using namespace std;
//include <ext/pb_ds/assoc_container.hpp>
//include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define lld long long double
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

bool sortbysec(pair<int ,int> &a , pair<int , int> &b)
{
    return a.ss > b.ss;
}

//[ capture clause ] (parameters) -> return-type
//{
//	definition of method
//}
//Syntax used for capturing variables :
//[&] : capture all external variable by reference
//[=] : capture all external variable by value
//[a, &b] : capture a by value and b by reference
// for the generalised lambda function use the auto keyword with the parameters

void solve()
{
    int n , m;
    cin >>n >> m;

    int b[n][m];
    vector<vii> a(n , vii(m , 0));
    vector<vii> v(n , vii(m , 0));
    fon(i , n){
        fon(j , m) cin >> b[i][j];
    }
    
    for(int i = 0 ; i < n;i ++)
    {
        for(int j = 0 ; j < m; j++){
            bool f1 = true , f2 = true;
            if(b[i][j] == 0) continue;
            for(int r = 0 ; r < n; r++)
            {
               f1 &= b[r][j]; 
            }
            for(int c = 0 ; c < m ; c++)
            {
               f2 &= b[i][c]; 
            }
            if(!f1 && !f2)
            {
                cout << "NO" << endl;
                return;
            }
            if(f1 && f2)
            {
                a[i][j] = 1;
            }
        }
    }
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ;j < m; j++){
            if(a[i][j] == 1)
            {
            for(int r = 0 ; r < n; r++)
            {
               v[r][j] = 1; 
            }
            for(int c = 0 ; c < m ; c++)
            {
               v[i][c] = 1; 
            }
            }
        }
    }
    bool f = true;
    
    fon(i , n) 
    {
        fon(j , m)
        if(v[i][j] != b[i][j]){
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
    fon(i , n) 
    {
        fon(j , m) cout << a[i][j] << " ";
        cout << endl;
    }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}