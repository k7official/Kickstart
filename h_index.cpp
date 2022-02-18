#include <bits/stdc++.h>
using namespace std;

vector<int> GetHIndexScore(vector<int> citations_per_paper) {
  vector<int> h_index;
  // TODO: Calculate and return h-index score for each paper.
  vector<int> citations; //keep track for inserting papers one by one
  for(int i=0; i<citations_per_paper.size(); i++){
    citations.push_back(citations_per_paper[i]);
    sort(citations.begin(), citations.end(), greater<int>()); //sort them in descending order after each paperCitation insertion
    int hIndex = 0;//variable for h_index after each publication
    for(int i=0; i<citations.size(); i++){
      if(citations[i] >= i+1){
        hIndex++;
      }
      else break;
    }
    h_index.push_back(hIndex);
  }
  return h_index;
}

int main() {
  int tests;
  cin >> tests;
  for (int test_case = 1; test_case <= tests; test_case++) {
    // Get number of papers for this test case
    int paper_count;
    cin >> paper_count;
    // Get number of citations for each paper
    vector<int> citations(paper_count);
    for (int i = 0; i < paper_count; i++) {
      cin >> citations[i];
    }
    vector<int> answer = GetHIndexScore(citations);
    cout << "Case #" << test_case << ": ";
    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
