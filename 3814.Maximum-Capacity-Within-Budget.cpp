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
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({costs[i], capacity[i]});
        }
        sort(arr.begin(), arr.end());
        // for finding reamining cost , if in that range the valid costs are (1,10) (2,5) , and we pick 2, whose capacity is 5 but there exist 1 also with capacity 10 so we will try to take it , in that range 0->i-1 we make prefix arr to strore the max capacity we have seen till then cause picking cost less than is necessary but maximizing the capacity is alos important 
        
        vector<int> pref(n); // capacity 
        pref[0] = arr[0].second;
        for(int i=1; i<n; i++){
            pref[i] = max(pref[i-1], arr[i].second);
        }
        // for every cost idx we have to binary search and find every possible
        int ans = 0;

        for(int i=0; i<n; i++){
            int rem = budget - arr[i].first; // picking curr and finding for 2nd 
            if(rem<=0)
                continue;
            
            ans = max(ans, arr[i].second);
            // binary search -> val small then remaining
            int l = 0;
            int r = i-1;
            int idx = -1;

            while(l<=r){
                int mid = (l+r)/2;
                if(arr[mid].first>=rem){
                    r = mid-1;
                }
                else {
                    idx = mid;
                    l = mid+1;
                }      
            }

            if(idx!=-1){
                ans = max(ans, arr[i].second + pref[idx]);
            }
        }
        
        return ans;
    }
};


int main(){

    return 0;
}