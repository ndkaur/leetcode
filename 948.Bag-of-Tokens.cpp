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
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n= tokens.size();
        sort(tokens.begin(), tokens.end());
        int mx = 0;
        int i = 0;
        int j = n-1;
        int cnt = 0;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                cnt++;
                mx = max(mx, cnt);
                i++;
            }
            else if(cnt>0){
                cnt--;
                power+=tokens[j];
                j--;
            }
            else {
                break;
            }
        }
        return mx;
    }
};
// power >= token i 

int main(){

    return 0;
}