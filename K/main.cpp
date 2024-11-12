#include <bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n; cin>>n;
   vector<long long> a(n);
   for(auto &i:a) cin>>i;
   sort(a.begin(), a.end());
   int res = 0;
   vector<pair<int, int> >dp(n);
   for(int i = 0 ;i < n; i++){
      dp[i] = {1, -a[i]};
      for(int j = i-1; j>=0; j--){
	  if(-dp[j].second >= a[i]) continue;
	  dp[i] = max(dp[i], {dp[j].first+1, dp[j].second-a[i]});
      }
   }
   cout << dp.back().first<<endl;
   return 0;
}
/*

3 5 6 8 20
1 1 1 1 1
1 2 
* */
