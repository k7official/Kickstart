#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
  int T;
  // Get number of test cases
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    ll N;
    cin >> N;
    ll score{};
    ll cells[N];
    while(N > 0){
        N -= 2;
        score++;
        N -= 3;
    }
    cout << "Case #" << tc << ": " << score << endl;
  }
  return 0;
}