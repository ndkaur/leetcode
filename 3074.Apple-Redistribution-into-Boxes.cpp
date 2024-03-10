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
    int minimumBoxes(vector<int>& apples, vector<int>& cap) {
        int n = apples.size();
        int m = cap.size();
        int sum = 0;
        for(int a:apples){
            sum += a;
        }

        sort(cap.begin(), cap.end(), greater<int>());

        int cnt =0;
        int j;
        for( j=0; j<m && sum>0; j++){
            sum -= cap[j];
        }
        return j;
    }
};

// 6    5 4 3 2 1
// 5 5 5      7 4 2 2

int main(){

    return 0;
}