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

// *1500 O(n * log(n))
void solve()
{
    ll n , h , w , x;
    cin >> w >> h >> n;
    set<int> a , b;  
    multiset<ll , greater<ll>> sa , sb;  // 2. Data Structure
    a.insert(0);
    a.insert(w);
    b.insert(0);
    b.insert(h);
    sa.insert(w);
    sb.insert(h);
    ll dx = w , dy = h;
    fon(i , n)
    {
        char c;
        cin >> c >> x;
        if(c == 'H')
        {
            auto it = b.ub(x);  // 1. binary search
            ll y2 = *it;
            it--;
            ll y1 = *it;
            sb.erase(sb.find(y2-y1));// 3. Implementation
            sb.insert(x-y1);
            sb.insert(y2-x);
            b.insert(x);
            dy = *(sb.begin());
        }
        else 
        {
            auto it = a.ub(x);
            ll x2 = *it;
            it--;
            ll x1 = *it;   // remove only one instance
            sa.erase(sa.find(x2-x1)); // erase the len from x1 to x2;
            sa.insert(x-x1);  // now add one len which is from x1 to x and x to x2
            sa.insert(x2-x); // because we are making one cut between x1 and x2 so x1 to x2 is no more are valid len 
            a.insert(x); // inserting a cut
            dx = *(sa.begin());
        }
        cout << dx * dy << endl;
    }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}
