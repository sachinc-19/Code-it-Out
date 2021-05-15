#include <bits/stdc++.h>
using namespace std;
 
#define      PSB                 push_back
#define      ll                 long long
#define      FastIO      ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
constexpr ll mod = 1e9  + 7;
const ll N=3e5+5;
 
int main(){
  FastIO
  
  int test;
  cin>>test;
  while(test--){
      int a,b;
      cin>>a>>b;
      if(a&b) 
      cout<<"No"<<endl;
      else 
      cout<<"Yes"<<endl;
  }
  return 0;
}