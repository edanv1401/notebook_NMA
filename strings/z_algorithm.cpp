#include <bits/stdc++.h>
#include <cstdlib>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
  string p, t;
  cin>>p>>t;
  int ans = 0;
  function<vector<int>(string)> z_algorithm = [&](string s){
    int n = s.size();
    vector<int>z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++){
      z[i] = max(0,min(z[i-l],r-i+1));
      while(i + z[i] < n && s[ z[i] ]== s[ i + z[i] ]){
        l = i, r = i + z[i], z[i]++;
      }
    }
    return z;
  };
  vector<int> z = z_algorithm(p+"#"+t);
  for(int i = p.size()+1;i<z.size();i++){
    ans += z[i] == p.size();
  }
  cout<<ans<<endl;
}

