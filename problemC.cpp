#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<tuple>
#include<deque>
#include<algorithm>
using namespace std;
using ll = int64_t;
using Ant = tuple<ll, ll, ll>;
using pll = pair<ll, ll>;

int main(){
    ll T;
    cin >> T;
    for(ll cas=1; cas<=T; cas++){
        ll n, L;
        cin >> n >> L;

        deque<Ant> A;
        vector<ll> P(n, 0);
        vector<ll> D(n, 0);
        for(ll i=0; i<n; i++){
            ll pi, di;
            cin >> pi >> di;
            A.push_back(make_tuple(pi, di, i+1));
        }
        sort(A.begin(), A.end());
        vector<pll> E;
        for(ll i=0; i<n; i++){
            auto [pi, di, ii] = A[i];
            (void)ii;//ignore ii
            if(di==0){
                E.push_back(make_pair(pi, 0));//facing left time of falling
            }else{
                E.push_back(make_pair(L-pi,1));//facing right time of falling
            }
        }
        sort(E.begin(), E.end());//sort according to fall time
        vector<ll> ANS;
        vector<ll> TMP;//ants which fall at current timestamp
        for(ll i=0; i<E.size(); i++){
            if(i>0 && E[i].first > E[i-1].first){//if we get a new timestamp, push all the ants in the last timestamp into the answer
                sort(TMP.begin(), TMP.end());
                for(ll x : TMP){
                    ANS.push_back(x);
                }
                TMP.clear();
            }
            if(E[i].second == 0){//facing left
                TMP.push_back(get<2>(A.front()));//front of the stick
                A.pop_front();//remove it
            }else{//facing right
                TMP.push_back(get<2>(A.back()));//back of the stick
                A.pop_back();//remove it
            }
        }
        sort(TMP.begin(), TMP.end());
        for(ll x : TMP){//push all the ants who fell of in the last timestamp
            ANS.push_back(x);
        }
        TMP.clear();
        cout << "Case #" << cas << ":";
        for(ll x : ANS){
            cout << " " << x;
        }
        cout << endl;
    }

    return 0;
}