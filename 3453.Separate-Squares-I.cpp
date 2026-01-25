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
    double find(double mid, vector<vector<int>>& squares){
        double above_height = 0;
        double below_height = 0;

        for(auto& square:squares){
            int x = square[0];
            int y = square[1];
            int len = square[2];

            // mid is above the sqaure 
            if(mid>=(y+len)){
                below_height += (double)len*len;
            }
            else if(y>=mid){// mid is below the square
                above_height += (double)len*len;
            }   
            // mid is intersecting the square
            else{
                // now it becomes a rectangle are = len*widht len ?
                double above_len =  (y+len)-mid; 
                double below_len = mid-y;
                above_height += above_len*len;
                below_height += below_len*len;
            }
        }
        return above_height - below_height;
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double low = 0;
        double high = 2*1e9;
        double total = 0.0000;

        for(auto& square:squares){
            double x = square[0];
            double y = square[1];
            double l = square[2];
            total += l*l;

            low = min(low, y);
            high = max(high, y+l);
        }

        double ans = 0.0;

        while(high-low > 1e-5){
            double mid = (low+high)/2.0;
            ans = mid;

            double diff = find(mid, squares);
            if(diff>0){//diff +ve, above_height>below_height
                // mid up shift -> low move
                low = mid;
            }
            else { // diff -ve, above<below-> mid down move 
                high = mid;
            }
        }
        return ans;
    }
};


// a point is given and the length of the squre made by that point is given, we have to decide where to make a line so that it divides the area of swaure above and bealow to be equal , we can lineraly keep on palcing the line and keep on checking 
// but better way is to do binary search 




int main(){

    return 0;
}