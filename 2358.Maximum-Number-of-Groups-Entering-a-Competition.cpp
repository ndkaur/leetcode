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

class Solution0 { // O(n)
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        sort(grades.begin(), grades.end());
        // 3 5 6 7 10 12 
        int prevCnt =0;
        int currCnt = 0;
        int ans  = 0;
        int currSum = 0;
        int prevSum = 0;
        for(int i=0; i<n; i++){
            currSum += grades[i];
            currCnt++;
            if(currCnt>prevCnt && currSum>prevSum){
                ans++;
                prevSum = currSum;
                prevCnt = currCnt;
                currSum = 0;
                currCnt = 0;
            }
        }
        return ans;
    }
};


class Solution { // nlogn 
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        long long  l = 1;
        long long  r = n;
        long long ans;
         // first condition itself gets satisfied as the array is sorted 
        // to satisfy second condition we must put 
        // first group 1 elem 
        // 2nd group -> 2 elemts
        // 3rd -> 3 elemts
        // now sum of groups is 1+ 2+ 3 +..n = sum of natural nos = n(n+1)/2
        while(l<=r){
            long long  mid = l+(r-l)/2;
            long long sum = mid * (mid+1)/2;
            if(sum<=n){
                ans = mid;
                l = mid+1;
            }
            else 
                r = mid-1;
        }
        return (int)ans;
    }
};




int main(){

    return 0;
}