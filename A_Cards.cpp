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
#define memo(oo) memset(oo , -1 , sizeof(oo))
// =============================================
//1.integer overflow (1e5 * 1e5) (2e9 + 2e9)
 
template<typename T> 
class Array{
   private:
     T *ptr;
     int size;
   public:
     // constructor
     Array(T arr[] , int s);
     void print();
};

template<typename T> 
Array<T>::Array(T arr[] , int s)
{
   ptr = new T[s];
   size = s;
   for(int i = 0 ; i < size ; i++)
   {
      ptr[i] = arr[i];
   }
}

template<typename T> 
void Array<T>::print()
{
   for(int i = 0 ; i < size ; i++)
    cout << *(ptr+i) << " ";
    cout << endl;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int array[] = {1 ,2 , 3 , 4 , 5};
   Array<int> a(array , 5);
   a.print();

}