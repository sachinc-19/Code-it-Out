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
#define memo(oo , x) memset(oo , x , sizeof(oo))
// =============================================
//1.integer overflow (1e5 * 1e5) (2e9 + 2e9)

ll mod(ll x){
    return ((x % M + M) % M);}

ll add(ll a , ll b){
    return mod(mod(a) + mod(b));}

ll mul(ll a , ll b){
    return mod(mod(a) * mod(b));}

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

void solve()
{
    int h , w;
    cin >> h >> w;
    int a[h][w] , x;
    int r[h] , c[w];
    memo(a , 0);

    fon(i , h)
    {
        cin >> r[i];
        for(int j = 0 ; j < r[i] ; j++)
         a[i][j] = 1;
    }

    fon(j , w)
    {
        cin >> c[j];
        fon(i , c[j])
        {
            if(a[i][j] == 1)
                a[i][j] = 3;
            else
            {
                a[i][j] = 2;
            }
        }
    }

    ll p = 0;
    for(int i = 1 ; i < h; i++)
    {
        for(int j = 1 ; j < w ; j++)
        {
            if(a[i][j-1] != 1 && a[i][j-1] != 3 && a[i-1][j] != 2 && a[i-1][j] != 3)
             p++;
        }
    }
    // fon(i , h)
    // {
    //     fon(j , w) cout << a[i][j] << " ";
    //     cout << endl;
    // }
    for(int i = 0 ; i < h ; i++)
    {
        int tmp = 0;
        for(int j = 0 ; j < w; j++)
        {
           if(a[i][j]) tmp++;
           else break;
        }
        if(tmp > r[i])
        {
            cout << "0" << endl;
            return; 
        }
    }
    for(int j = 0 ; j < w ; j++)
    {
        int tmp = 0;
        for(int i = 0 ; i < h ; i++)
        {
           if(a[i][j]) tmp++;
           else break;
        }
        if(tmp > c[j])
        {
            cout << "0" << endl;
            return; 
        }
    }
    cout << modpower(2 , p) << endl;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   solve();
}