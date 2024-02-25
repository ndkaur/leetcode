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
    long long largestSquareArea(vector<vector<int>>& b, vector<vector<int>>& t) {
        int n = b.size();
        int m = t.size();
        long long area =0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long mn_x = max(b[i][0], b[j][0]);
                long long mx_x = min(t[i][0], t[j][0]);
                long long mn_y = max(b[i][1], b[j][1]);
                long long mx_y = min(t[i][1], t[j][1]);

                if(mn_x < mx_x && mn_y<mx_y){
                    long long temp = min(mx_x-mn_x, mx_y-mn_y);
                    area = max(area, temp*temp);
                }
            }
        }
        return area;
    }
};

int main(){

    return 0;
}