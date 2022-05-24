#include <bits/stdc++.h>
#include <cstdlib>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
using namespace std;
typedef long long ll;
int main(){
    string p;cin>>p;
    int i = 0;
    int n = p.size();
    vector<int> phi(n);
    phi[0] = 0;
    for(int j = 1 ;j < n; j++){
      while(i > 0 && p[i]!=p[j]) i = phi[i-1];
      if(p[i] == p[j]) i++;
      phi[j] = i;
    }
    string t;cin>>t;
    int match = 0;
    for(int j=0, i=0;j<t.size();j++){
      while(i>0 && p[i]!=t[j]) i = phi[i-1];
      if(p[i] == t[j])i++;
      if(i==p.size()){
        match++;
        i = phi[i-1];
      }
    }
    cout<<match<<endl;
}

