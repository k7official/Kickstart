#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
  int T;
  // Get number of test cases
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int N;
    cin >> N;
    vector<int> Task1;
    int p;
    for(int i=0; i<N; i++){
        cin >> p;
        Task1.push_back(p);
    }
    int M;
    cin >> M;
    vector<int> Task2;
    for(int i=0; i<M; i++){
        cin >> p;
        Task2.push_back(p);
    }
    int K;
    cin >> K;
    //sort(Task1.begin(), Task1.end());
    //sort(Task2.begin(), Task2.end());
    int max_points = 0;
    for(int i=0; i<K; i++){
        auto it1 = max_element(Task1.begin(), Task1.end());
        auto it2 = max_element(Task2.begin(), Task2.end());
        int index1 = distance(Task1.begin(), it1);
        int index2 = distance(Task2.begin(), it2);
        int index1back = distance(Task1.end(), it1);
        int index2back = distance(Task2.end(), it2);
        int sz1 = Task1.size();
        int sz2 = Task2.size();

        int min_ = min(index1, min(index2, min(index1back, index2back)));

        bool back1=false, front1=false, back2 = false, front2 = false;
        if(index1 > index2){
            front2 = true;
        }
        else{
            front1 = true;
        }
        if(index1back > index2back){
            back2 = true;
        }else{
            back1 = true;
        }

        if(f)



        if(Task1[sz1-1] > Task2[sz2-1]){
            max_points += Task1[sz1-1];
            Task1.pop_back();
        }
        else{
            max_points += Task2[sz2-1];
            Task2.pop_back();
        }
    }
    cout << "Case #" << tc << ": " << max_points
         << endl;
  }
  return 0;
}