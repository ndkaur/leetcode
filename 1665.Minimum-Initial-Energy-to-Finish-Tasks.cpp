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



class Solution0 {
public:
    bool isPossible(int val, vector<vector<int>>& tasks){
        int n = tasks.size();
        for(auto task:tasks){
            int start= task[1];
            int req = task[0];
            if(val>=start){
                val-= req;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b){
            return (a[1]-a[0]) > (b[1]-b[0]);
        });
        int mxelm = 0;
        int sum = 0;
        for(auto t:tasks){
            mxelm= max(t[0], t[1]);
            sum += t[0];
            sum +=t[1];
        }
        int ans = 0;
        int l = mxelm;
        int h = sum;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(isPossible(mid, tasks)){
                ans= mid;
                h = mid-1;
            }
            else{
                l= mid+1;
            }
        } 
        return ans;
    }
};

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        //sort on bais of diff, more the diff, more we need to put first 
        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b){
            return (a[1]-a[0]) > (b[1]-b[0]);
        });
        
        int start = tasks[0][1];
        int rem = tasks[0][1]-tasks[0][0];
        int extra =0;
        
        for(int i=1; i<n; i++){
            int cost = tasks[i][1];
            int req = tasks[i][0];
            if(rem<cost){
                extra += cost-rem;
                rem = cost;
            }
            rem = rem-req;
        }

        return start+extra;
    }
};




int main(){

    return 0;
}