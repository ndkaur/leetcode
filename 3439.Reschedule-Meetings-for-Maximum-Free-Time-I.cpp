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
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // time line starts from 0 , but its not necessary for the first startitme to be 0 , so the first gap in array will be starttime [0];
        vector<int> gap(1,startTime[0]);
        // (st1, en1) (st2,en2) gap = st2-en1
        for(int i=1; i<startTime.size(); i++){
            gap.push_back(startTime[i]-endTime[i-1]);
        }
        // now we also have eventime , if the end l=time is less than eventime , then its possible that some time is remaining
        gap.push_back(eventTime-endTime.back());

        // we got the gap array now use sliding windoe to find the max subarry sum of length k+1;
        int sum = 0;
        int mx = 0;
        // for(int i=0; i<gap.size(); i++){
        //     sum += gap[i];
        //     // when window size execeeded k+1 or got equal 
        //     if(i>=k+1){
        //         sum -= gap[i-(k+1)];
        //     }
        //     mx = max(mx, sum);
        // }
        int i =0;
        int j=0;
        while(j<gap.size()){
            sum+=gap[j];
            if((j-i+1) >= (k+1)){
                mx= max(mx, sum);
                sum-=gap[i];
                i++;
            }
            j++;
        }
        return mx;
    }
};
// we want to find the sum of the gaps 
// so we want to take some values of gap find the max sum of them 
// we will take k+1 subarray sum 
// ie maximum sum of lenth k+1 in array 

int main(){

    return 0;
}