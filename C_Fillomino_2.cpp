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
 
int a[505][505];
int dx[2] = {0 , 1 };
int dy[2] = {-1 , 0};
int N ;
bool is_safe(int x , int y)
{
    if(x < 0 || y < 0 || x >= N || y >= N  || x < y || a[x][y] != 0)
    {
        return false;
    }
    return true;
}
bool dfs(int x , int y , int n, int val)
{
    a[x][y] = val;
    if(n == 1)
    {
        return true;
    }
    bool f = false;
    for(int i = 0 ; i < 2 ; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if(is_safe(X , Y))
        {
            f = dfs(X , Y , n-1 , val);
        }
        if(f) return true;
    }
    return f;
}
void solve()
{
    int n;
    cin >> n;
    N = n;
    fon(i , n)
    {
        cin >> a[i][i];
    }
    fon(i , n)
    {
        int m = a[i][i];
        int x = i , y = i;
        fon(j , m)
        {
           a[x][y] = a[i][i];
           if(y > 0)
           {
               if(a[x][y-1] == 0)
               {
                   y--;
               }
               else 
                x++;
           }
           else
           x++;
        }
    }
    fon(i , n)
    {
        for(int j = 0 ; j <= i ; j++)
        cout << a[i][j] << " ";
        cout << endl;
    }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   solve();
}