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
// ===================================================================
 
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vii a(3, 0);

    fon(i, n)
    {
        a[s[i] - '0']++;
    }
    int x = n/3;
    if(a[2] < x)
    {
        for(int i = n-1 ; i >= 0 ; i--)
        {
            if(s[i] == '1')
            {
                if(a[1] > x){
                    a[1]--;
                    a[2]++;
                    s[i] = '2';
                }
            }
            else if(s[i] == '0')
            {
                if(a[0] > x){
                    a[0]--;
                    a[2]++;
                    s[i] = '2';
                }
            }
            if(a[2] >= x) break;
        }
    }
    if(a[0] < x)
    {
        for(int i = 0 ; i <= n && a[0] < x; i++)
        {
            if(s[i] == '2' )
            {
                if(a[2] > x){
                    a[2]--;
                    a[0]++;
                    s[i] = '0';
                }
            }
            else if(s[i] == '1')
            {
                if(a[1] > x){
                    a[1]--;
                    a[0]++;
                    s[i] = '0';
                }
            }
        }
    }
    if(a[1] < x)
    {
        for(int i = 0 ; i <= n && a[1] < x; i++)
        {
            if(s[i] == '2')
            {
                if(a[2] > x){
                    a[2]--;
                    a[1]++;
                    s[i] = '1';
                }
            }
        }
        for(int i = n-1 ; i >= 0 ; i--)
        {
            if(s[i] == '0')
            {
                if(a[0] > x){
                    a[0]--;
                    a[1]++;
                    s[i] = '1';
                }
            }
            if(a[1] >= x) break;
        }
    }
    cout << s << endl;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}