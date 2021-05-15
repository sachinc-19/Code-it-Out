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
 
const int N = 505;
int a[N][N] , b[N][N];
int dx[4] = {0 , 0 , 1, 1};
int dy[4] = {0 , 1 , 0 , 1};
void solve()
{
    int n , m;
    cin >>n >> m;
    fon(i ,n){
      fon(j , m)
      {
           cin >> a[i][j];
      }
    }
    
    fon(i ,n){
      fon(j , m)
      {
           cin >> b[i][j];
      }
    }
    // a -> b
    
    fon(i , n-1)
    {
        fon(j , m-1)
        {
           if(a[i][j] == b[i][j]) continue;
           fon(k , 4)
           {
               int x = i + dx[k];
               int y = j + dy[k];
               a[x][y] = !a[x][y];
           }
        }
    }
    fon(i ,n)
    {
        fon(j ,m)
        {
            if(i == n-1 && a[i][j] != b[i][j])
            {
                cout << "No" << endl;
                return;
            }
            else if(j == m-1 && a[i][j] != b[i][j])
            {
                cout << "No" << endl;
                return;
            }
        }
    }  
    cout << "Yes" << endl;  
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}