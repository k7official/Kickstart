#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

ll find_mentor(ll rating, vector<ll>ratings){
    sort(ratings.begin(), ratings.end());
    ll mentor;
    while(ratings.size()){
        mentor = ratings[ratings.size()-1];
        ll same_rating;
        same_rating = count(ratings.begin(), ratings.end(), rating);
        if(same_rating > 1 && mentor == rating){
            return mentor;
        }
        else if(mentor > 2 * rating || mentor == rating){
            ratings.pop_back();
        }
        else{
            return mentor;
        }
    }
    return -1;
}

int main() {
  int T;
  // Get number of test cases
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    ll N;
    cin >> N;
    vector<ll> ratings;
    ll rating;
    for(ll i=0; i<N; i++){
        cin >> rating;
        ratings.push_back(rating);
    }
    cout << "Case #" << tc << ": ";
    for(ll i=0; i<ratings.size(); i++){
        ll mentor;
        mentor = find_mentor(ratings[i], ratings);
        if(i != ratings.size()-1)
            cout << mentor << " ";
        else
            cout  << mentor << endl;
    }
  }
  return 0;
}