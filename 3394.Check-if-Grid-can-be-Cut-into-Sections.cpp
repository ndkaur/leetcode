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
        vector<vector<int>> mergee(vector<vector<int>>& arr){
            int n = arr.size();
            if(n<=1)
                return arr;
            //O(nlogn) ->sortinf time complexity
            sort(arr.begin(), arr.end());
            vector<vector<int>> temp;
            temp.push_back(arr[0]);
            // l1 r1      l1<r2
            // l2 r2 ,,,, l2<r1 then overlap 
            for(int i=1; i<n; i++){
                int l1 = temp.back()[0];
                int r1 = temp.back()[1];
                int l2 = arr[i][0];
                int r2 = arr[i][1];
                // l2<r1
                if(l2<r1){// overlaping
                // min(l1,l2), max(r1,r1)
                    temp.back()[1] = max(r1,r2);
                }
                else{ // no overlap -> directly take that interval
                    temp.push_back(arr[i]);
                }
            }
            return temp;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            // check for 3 sections 
            // {x1,x2,e1,e2} -> convert it into {x1,e1} {x2,e2}
            vector<vector<int>> x_cor,y_cor;
            for(auto rec:rectangles){
                x_cor.push_back({rec[0],rec[2]});
                y_cor.push_back({rec[1], rec[3]});
            }
            vector<vector<int>> x_merge = mergee(x_cor);
            vector<vector<int>> y_merge = mergee(y_cor);
            return x_merge.size()>=3 || y_merge.size()>=3;
        }
    };
    
    // x interval, y interval seperate 
    // sort -> time comp -> O(nlog n)
    // overlap make a new array , 
    // check if any of the merges array size is >=3
    
    // l1 r1      l1<r2
    // l2 r2 ,,,, l2<r1 then overlap 
    
    // dry run
    // x inervals = {1,5} {0,2} {3,5} {0,4}
    // yintervals = {0,2} {2,4} {2,3} {4,5}
    
    // x inervals = {1,5} {0,2} {3,5} {0,4}
    // sort x-interval = {0,2} {0,4} {1,5} {3,5}
    
    

int main(){

    return 0;
}