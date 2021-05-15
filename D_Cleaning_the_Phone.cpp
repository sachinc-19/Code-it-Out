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

const int N = 2e5+5;
int a[N] , b[N];
void test_case()
{
    ll n , m;
    cin >> n >> m;
    
    fon(i , n) cin >> a[i];
    fon(i , n) cin >> b[i];

    vll one , two ;
    fon(i , n)
    {
        if(b[i] == 1) one.eb(a[i]);
        else two.eb(a[i]);
    }
    sort(allr(one));
    sort(allr(two));

    for(int i = 1 ; i < one.size() ; i++)
     one[i] += one[i-1];
    for(int i = 1 ; i < two.size() ; i++)
     two[i] += two[i-1];

    ll ans = INT_MAX;
    for(int i = 0 ; i <= two.size() ; i++)
    {
        ll n2 = i , sum = 0;
        if(i > 0)
         sum = two[i-1];
        ll need = m-sum;
        if(need <= 0)
        {
           ans = min(ans , n2*2);
        }
        ll n1 = lb(all(one) , need) - one.begin();
        if(n1 < one.size())
        {
            ans = min(ans , 2*n2+n1+1);
        }
    }
    if(ans == INT_MAX)
    cout << "-1" << endl;
    else 
    cout << ans << endl;

}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   test
   {
      test_case();
   }
}