#include<iostream>
#include<vector>

using namespace std;
using ll = int64_t;

int main(){

    ll T;
    cin >> T;
    for(ll cas=1; cas<=T; cas++){
        ll n, x, y;
        cin >> n >> x >> y;
        //total sum is S = n*(n+1)/2
        //want a s.t a/(S-a) == x/y
        //a*y == x*(S-a)
        //ay == xS - xa
        //a*(x+y) == xS
        //a = xS/(x+y)
        ll S = n*(n+1)/2;
        if((x*S) % (x+y) == 0){
            cout << "Case #" << cas << ": POSSIBLE" << endl;
            ll a = (x*S)/(x+y);
            vector<ll> A;
            for(ll i=n; i>=1; i--){
                if(a>=i){
                    A.push_back(i);
                    a -= i;
                }
            }
            cout << A.size() << endl;
            for(ll i=0; i<A.size(); i++){
                cout << A[i];
                if(i+1 < A.size()){
                    cout << " ";
                }
                else{
                    cout << endl;
                }
            }
        }else{
            cout << "Case #" << cas << ": IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
