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
#define MOD (1000*1000*1000+7)
#define test ll T; cin>>T; while(T--)
#define all(z) z.begin() , z.end()
#define allr(z) z.rbegin() , z.rend()
#define memo(oo , zz) memset(oo , zz , sizeof(oo))
// =============================================
//1.integer overflow (1e5 * 1e5) (2e9 + 2e9)

const int MAXN = 501;
int a[MAXN][MAXN] , b[MAXN][MAXN];
int N , M , K;
int dx[] = {-1 , 0 , 1 , 0};
int dy[] = {0 , 1 , 0 , -1};
bool check(int x , int y)
{
  if(x < 0 || x >= N || y < 0 || y >= M)
     return false;
     return true;
}
int dp[MAXN][MAXN][12];
int dfs(int x , int y , int k )
{
    if(k == 0)
    {
        return 0;
    }
    int &ans = dp[x][y][k];
    if(ans != -1) return ans;
    ans = INT_MAX;
    for(int i = 0 ; i < 4 ;i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        int cc = 0;
        if(dy[i] == 1 ) cc += a[x][y];
        else if(dy[i] == -1) cc += a[X][Y];
        else if(dx[i] == 1) cc += b[x][y];
        else cc += b[X][Y];
        if(check(X , Y))
        {
            ans = min(ans , cc + dfs(X , Y , k-1));
        }
    }
    return ans;
}
void solve()
{
    int k;
    cin >> N >> M >> K;
    fon(i , N)
    {
        fon(j , M-1)
        {
            cin >> a[i][j];
        }
    }
    fon(i , N-1)
    {
        fon(j , M)
        {
            cin >> b[i][j];
        }
    }
            memo(dp , -1);
    fon(i , N)
    {
        fon(j , M)
        {
            if(K % 2)
            {
                cout << -1 << " ";
                continue;
            }
            cout << 2*dfs(i , j , K/2) << " ";
        }
        cout << endl;
    }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}