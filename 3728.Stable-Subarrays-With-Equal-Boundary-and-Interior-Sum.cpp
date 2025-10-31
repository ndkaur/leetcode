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


class Solution0 {  // wrong answer
public:
// sliding window with 2 ptr can never work here as in [0,0,0,0]
//  there are diffretn windows ans we cant take them all uding two ptrs 
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long> pref(n,0);
        pref[0]=capacity[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1]+capacity[i];
        }

        int l =0;
        int r =n-1;
        long long cnt =0;
        while(l<r){
            int win_sum = pref[r]-pref[l]-capacity[r];
            if(capacity[l]==win_sum && capacity[r]==win_sum && r-l+1>=3){
                cnt++;
                l++; 
                r--;
            }
            else{
                if(capacity[l]!=0)
                    r--;
                else 
                    l++;
                // int diffl = win_sum-capacity[l];
                // int diffr = win_sum-capacity[r];
                // if(diffl<diffr && diffl>0){
                //     r--;
                // }
                // else 
                //     l++;
            }
        }
        return cnt;
    }
};



class Solution { 
public:
    long long countStableSubarrays(vector<int>& capacity) { 
        // approach kind of like subarray sum equal to k 
        // making a map to store the prefix sum that will help us get a window and we also need to stire the capacity value cause it will help us to make sure that the left and right value are both the same 
        // so if left and right value are equal then the sum of window in between will be total prefix sum - 2* left 
        int n = capacity.size();
        vector<long long int> pref(n,0);
        pref[0]=capacity[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1]+capacity[i];
        }

        long long cnt =0;
        map<long long , map<long long, long long>> mp;

        for(int i=1; i<n; i++){
            long long win_sum = pref[i]- 2*capacity[i];
            cnt += mp[win_sum][capacity[i]];
            mp[pref[i-1]][capacity[i-1]]++;
        }
        return cnt;
    }
};



int main(){

    return 0;
}