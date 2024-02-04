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
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt =0;
        auto comp = [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };

        sort(points.begin(), points.end(), comp);// this ensures that all points occur one after other in ascending order  of x points
    
        // conditions:- 
        // 1. one point should be higher right and other lower left
        //  no other point should lie between two points

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(points[i][1] >= points[j][1]){ // i point at top than j
                    int flag =1;
                    // checking if any point comes inbetween 
                    for(int k=i+1; k<j; k++){
                        // (2,6) (4,4) (6,2)
                        if(points[k][1]<=points[i][1] && points[k][1]>=points[j][1]) // comes inbetween 
                            flag = 0;
                    }
                    if(flag)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}