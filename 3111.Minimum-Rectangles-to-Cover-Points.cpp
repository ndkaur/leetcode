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
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int n = points.size();
        sort(points.begin(), points.end());
        int cnt = 1;
        int prev = points[0][0];
        for(int i=1; i<n; i++){
            if(points[i][0]-prev>w){ // diff rectangle
                cnt++;
                prev = points[i][0];
            }
        }
        return cnt;
    }
};

// sorted -> (1,0) (1,4) (1,8) (2,1) (3,5) (4,6)    w =1
// prev = 1, 1-1=0 ,  2-1= 1!>1,   3-1= 2>1 , cnt++ cnt =2 
//  prev = 3,   4-3  no  

int main(){

    return 0;
}
