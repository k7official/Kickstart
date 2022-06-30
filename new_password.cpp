#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;

    int i = 0;
    //unordered_set<char> special = {'#', '@', '*', '&'};
    
    while(i<T){
        int N;
        string old, ans;
    

        cin >> N;
        cin >> old;
        ans = old;
        
        bool uppercase = false;
        bool lowercase = false;
        bool special = false;
        bool  digit = false;

        for(int i=0; i<N; i++){
            if(old[i]-'A'>=0 && old[i]-'A'<=25)uppercase = true;
            if(old[i]-'a'>=0 && old[i]-'a'<=25)lowercase = true;
            if(old[i]-'0'>=0 && old[i]-'0'<=9)digit = true;
            if(old[i]=='#' || old[i]=='@' || old[i]=='*' || old[i]=='&')special=true;
        }
      
        if(!uppercase)ans += 'A';
        if(!lowercase)ans += 'a'; 
        if(!digit)ans += '1';
        if(!special)ans += '@';
        while(ans.length()<7)ans += '1';
        cout << "Case #" << i+1 << ": " << ans << endl;
        i++;
    }

    return 0;
}

