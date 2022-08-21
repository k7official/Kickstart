#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
  int T;
  // Get number of test cases
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    ll N, M;
    cin >> N >> M;
    vector<ll> regions;
    ll n;
    for(int i=0; i<N; i++){
        cin >> n;
        regions.push_back(n);
    }
    double median = 0;
    if(M == 1){
        sort(regions.begin(), regions.end());
        ll reg_size = regions.size();
        if(reg_size % 2 == 1){
            median = double(regions[reg_size / 2]);
        }
        else{
            median = double(regions[reg_size / 2 - 1] + regions[reg_size / 2]) / 2;
        }
    }
    else{
        for(ll i=0; i<M-1; i++){
            //auto it = max_element(begin(regions), end(regions));
            sort(regions.begin(), regions.end());
            ll reg_size = regions.size();
            median += double(regions[reg_size - 1]);
            //cout << median << endl;
            regions.pop_back();
        }
        ll reg_size = regions.size();
        if(reg_size % 2 == 1){
            median += double(regions[reg_size / 2]);
        }
        else{
            median += double(regions[reg_size / 2 - 1] + regions[reg_size / 2]) / 2;
        }
    }
    cout << "Case #" << tc << ": " << fixed << setprecision(1) << median
         << endl;
  }
  return 0;
}