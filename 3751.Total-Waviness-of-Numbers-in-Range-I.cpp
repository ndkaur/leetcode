#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}


class Solution {
public:
    int calculate(int num){
        string s = to_string(num);
        int sz = s.size();
        int cnt = 0;
        if(sz<3)
            return 0;

        for(int i=1; i<sz-1; i++){
            int prev = s[i-1]-'0';
            int curr = s[i]-'0';
            int next = s[i+1]-'0';
            if(curr>prev && curr>next)
                cnt++;
            else if(curr<prev && curr<next)
                cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for(int i=num1; i<=num2; i++){
            int c = calculate(i);
            cnt+=c;
        }
        return cnt;
    }
};



int main(){

    return 0;
}