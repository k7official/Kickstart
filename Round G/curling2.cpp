#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define pii             pair<int,int>
#define F               first
#define S               second
#define mp              make_pair


int dist(int x, int y) { return x * x + y * y; }

void solve() {

    int stone_rad, house_rad;
    cin >> stone_rad >> house_rad;

    vector<pii> red;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        pii pos = mp(x, y);
        red.pb(pos);
    }
    vector<pii> yellow;
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int z, w;
        cin >> z >> w;
        pii pos = mp(z, w);
        yellow.pb(pos);
    }

    int m_red = INT_MAX; //least squared distance
    for(int i=0; i<n; i++){
        m_red = min(m_red, dist(red[i].first, red[i].second));
    }
    int m_yellow = INT_MAX; //least squared distance
    for(int i=0; i<m; i++){
        m_yellow = min(m_yellow, dist(yellow[i].first, yellow[i].second));
    }

    int s_red = 0;
    for(int i = 0; i < n; i++) {
        bool is_scoring = dist(red[i].first, red[i].second) <= (house_rad + stone_rad) * (house_rad + stone_rad); //Inside the house
        is_scoring &= dist(red[i].first, red[i].second) < m_yellow;
        s_red += is_scoring;
    }

    int s_yellow = 0;
    for(int i = 0; i < m; i++) {
        bool is_scoring = dist(yellow[i].first, yellow[i].second) <= (house_rad + stone_rad) * (house_rad + stone_rad); //Inside the house
        is_scoring &= dist(yellow[i].first, yellow[i].second) < m_red;
        s_yellow += is_scoring;
    }

    std::cout << s_red << " " << s_yellow << endl;

}

int main() {
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
  
    std::cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}
