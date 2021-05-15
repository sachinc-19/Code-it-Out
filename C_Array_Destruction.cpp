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
 
void solve()
{
    int n;
    cin >> n;
    vii a(2*n);

    fon(i, 2*n) cin >> a[i];
    sort(all(a));
    int j = 2*n-1;
    for(int i = 0 ; i < 2*n-1 ; i++)
    {
      vii v = a ;
      vpii ans;
      v[i] = v[j] = -1;
      int cnt = 1 , jj = j-1;
      ans.eb(a[i] , a[j]);
      while(cnt < n)
      {
        int sum = a[jj+1];
        bool f = true;
        while(v[jj] == -1) jj--; //a valid j has been found
        for(int ii = 0 ; ii < jj ; ii++)
        {
            if(v[ii] == -1) continue;
            if(v[ii] + v[jj] == sum){
                v[ii] = v[jj] = -1;
                ans.eb(a[ii], a[jj]);
                f = false;
                break;
            }
        }
        if(f) break;
        cnt++;
        jj--;
      }
      if(cnt == n)
      {
          cout << "YES" << endl;
          cout << a[i] + a[j] << endl;
          for(pii i : ans) cout << i.ff << " " << i.ss << endl;
          return;
      }
    }
    cout << "NO" << endl;
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