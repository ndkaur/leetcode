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

// how to see if a point les in between 2 points 
// x1<= x2 <=x2
// y1<= y3 <=y2
// so if we sort it accoring to x axis then its will be sure that x1<=x2 then we only need to check for y point 
class Solution { // O(n^2)
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        // a->b = down right , (x1,y1) ( x2,y2) -> x1>x2 , y1<y2 
        sort(points.begin(), points.end(), [](const vector<int>& p1, const vector<int>& p2){// descending order accordimg to y 
        // if x value small then ony y be big when both not equal 
            return p1[0]==p2[0] ? p1[1]>p2[1] : p1[0]<p2[0];
        });

        int cnt =0;
        for(int i=0; i<n-1; i++){
            int bottom_right_y = INT_MIN;
            for(int j=i+1; j<n; j++){ // y1 <= y3 <= y2
                if(points[j][1]<=points[i][1] && points[j][1]>bottom_right_y){
                    cnt++;
                    bottom_right_y = points[j][1];
                }
            }
        }
        return cnt;
    }
};


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