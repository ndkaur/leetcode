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
    bool isPossible(vector<int>& dist, double& hour, int mid){
        int n = dist.size();
        double total = 0;
        // we take ceil divison for all trains but for the last train we take direct division 
        for(int i=0; i<n; i++){
            double time = ((dist[i]*1.0/mid));
            if(i!=n-1)
                total += ceil(time);
            else 
                total += time;
        }
        return total<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int l = 1;
        int h = 1e7;
        int ans = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(isPossible(dist, hour, mid)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}