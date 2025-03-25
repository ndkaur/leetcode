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
        int countDays(int days, vector<vector<int>>& meet) {
            int n = meet.size();
            sort(meet.begin(), meet.end());
            vector<vector<int>> temp;
    
            int l1 = meet[0][0];
            int r1 = meet[0][1];
        
            for(int i=1; i<n; i++){
                int l2 = meet[i][0];
                int r2 = meet[i][1];
                // l1 r1   l1<r2
                // l2 r2 ,,,, l2<r1 then overlap 
                if(l2>r1){
                    temp.push_back({l1,r1}); // no overlap simply push interval
                    l1 = l2;
                }
                r1 = max(r1,r2);
            }
            temp.push_back({l1,r1});
    
            int d = 0;
            for(auto t:temp){
                int start = t[0];
                int end = t[1];
                d += end-start+1;
            }
            return days-d;
        }
    };
    
    
    // sort 
    // merge intervals
    // find -> days - val
    // val = end - start + 1
    
    
    // 2 4
    // 1 3  2<3, 1<4 overlap


int main(){

    return 0;
}