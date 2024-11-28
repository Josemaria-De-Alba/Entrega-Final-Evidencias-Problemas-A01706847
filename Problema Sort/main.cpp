#include <iostream>
#include <vector>

//https://codeforces.com/problemset/problem/1992/B

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n;
        cin >> k;
        vector<int> s(k);
        int m = 0;
        int mpos = 0;
        for (int i = 0; i < k; i++){
            cin >> s[i];
            m = max(m, s[i]);
        }
        
        for (int i = 0; i < k; i++){
           if(s[i] == m){
               mpos = i;
           }
        }
        
        int count = 0;
        for(int i = 0; i < k; i++){
            if(i != mpos){
                while(s[i] != 1){
                    s[i] = s[i] - 1;
                    s.insert(s.end(),1);
                    count++;
                }
            }
        }        
    
        for(int i = 0; i < s.size(); i++){
            count++;
        }
        
        cout << count - 1 << '\n';
    }
}