#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int len=startTime.size();
        int c=0;
        for(int i=0;i<len;i++){
            if(startTime[i]<=queryTime && endTime[i]>=queryTime)
                c++;
        }
        return c;
        
    }
};
int main(){
    Solution sol;
    vi startTime,endTime; int queryTime;
    startTime={4};endTime={4};queryTime=4;
    int out=sol.busyStudent(startTime,endTime,queryTime);
    cout<<out;
    return 0;
}