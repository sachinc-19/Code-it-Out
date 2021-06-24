                               // CPP
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

const int maxn = 1010;
char a[maxn][maxn];
int dx[3][3];
int dy[3][3];
int n , m;
string s[maxn];
void mark(int x ,int y) {
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(i == 1 && j == 1) continue;
            a[i+x][j+y] = '#';
        }
    }
}
bool ok(int x , int y)
{
    int cnt1 = 0 , cnt2 = 0;
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(s[i][j] == '#') cnt1++;
            else cnt2++;
        }
    }
    if(cnt1 == 7 && cnt2 == 1) return true;
    else return false;
}
bool check(int x , int y)
{
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3; j++)
        {
            int X = x-dx[i][j];
            int Y = y-dy[i][j];
            if(X < 0 ||  Y < 0 || X+2 >= n || Y+2 >= m)
            {
                continue;
            }
            if(ok(X , Y))
            {
                mark(X , Y);
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    // int n,m ;
    cin >> n >> m;
    fon(i ,n) cin >> s[i];
    
    if(m < 3)
    {
        cout << "NO" << endl;
        return;
    }
    
    fon(i , n)
        fon(j , m) a[i][j] = '.';
    fon(i , 3)
     fon(j , 3){
         dx[i][j] = i;
         dy[i][j] = j;
         
     }

    for(int i =0 ;i < n-2 ;i++)
    {
        for(int j = 0 ; j < m-2 ; j++)
        {
            if(s[i][j] == '#' && a[i][j] == '.')
            {
                bool f = check(i , j);
                if(!f)
                {
                    cout << "NO" << endl;
                    break;
                }
            }
        }
    }
    fon(i, n){
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