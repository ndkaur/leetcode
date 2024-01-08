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


// move can always be 1 or 2 
// 1 move when queen is in the path 
// 2 move when queen isnt on the path , so 1 move to change path , 2nd move to reach the queen 
// there can be 4 cases :- 
// rook and queen in same row
// rook and queen in same col
// bishop and queen in same antidigonal
// bishop and quenn in same diagonal

// inbetween condition eg bishop between rook and queen 
//  (a,b) = (1,2)   (c,d) = (1,4)    (e,f)= (1,6)
//  min(b,f) = min(2,6) = 2 -> 4>2  inbetween  min<d
//  max(b,f) = max(2,6) = 6 ->  6>4  inbetween  max>d
//  min < d < max 

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // (a,b) rook  , (c,d) bishop  (e,f) queen 
        
        // rook and queen in same row , but col can be diff and bishop is not inbetween
        if((a==e && !(a==c && min(b,f)<d && d<max(b,f))))
            return 1;
        // rook and queen in same column and no overlap with boshop 
        if(b==f && !(b==d && min(a,e)<c && c<max(a,e)))
            return 1;
        
        // bishop and queen in anti-diagonal and rook no overlap 
        if(c+d==e+f && !(c+d==a+b &&  min(c,e)<a &&  a<max(c,e)))
            return 1;

        // bishop and queen in same diagonal and rook no overlap
        if(c-d==e-f && !(c-d==a-b && min(c,e)<a && a<max(c,e)))
            return 1;
        // in different 
        return 2;
    }
};

int main(){

    return 0;
}