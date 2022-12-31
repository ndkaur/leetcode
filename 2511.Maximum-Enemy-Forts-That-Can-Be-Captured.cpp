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


// [1,0,0,-1,0,0,0,0,1]
// ans = 4 
// basically we want to calculate the number of 0's btw 1 and -1 from both directions 

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(forts[i] == 0 || forts[i] == -1)
                continue;
            for(int j=i+1; j<n; j++){
                if(forts[j] == 1)
                    break;
                if(forts[j] == -1){
                    ans = max(ans,j-i-1);
                    break;
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            if(forts[i] == 0 || forts[i] == -1)
                continue;
            for(int j=i-1; j>=0; j--){
                if(forts[j] == 1)
                    break;
                if(forts[j] == -1){
                    ans = max(ans, i-j-1);
                    break;
                }
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}