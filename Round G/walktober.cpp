#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define all(v)          v.begin(),v.end()

int main() {
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    int M, N, P;
    cin >> M >> N >> P;
    vector<vector<int>> prev(N,vector<int>(M, 0));
    int john = 0;

     for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)     {
            cin >> prev[j][i];
        }
    }
    
    for(int i=0;i<N;++i) {
        john += *max_element(all(prev[i])) - prev[i][P - 1];
    }
    
    cout << "Case #" << tc << ": " << john << endl;
  }
  return 0;
}
