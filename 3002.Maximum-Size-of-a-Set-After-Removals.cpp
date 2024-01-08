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
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // we want the answer set size to be max 
        // so we will pick the not common elems from both 
        set<int> s1, s2, s;

        // s1 will have unique elemts of num1
        // s2 will have unique elements of num2
        // s will have unique elements from both num1 and num2

        for(int num:nums1){
            s1.insert(num);
            s.insert(num);
        }
        for(int num:nums2){
            s2.insert(num);
            s.insert(num);
        }

        //  The answer is minimum of:
        // a. size of s
        // b. sum of number of unique elements provided by both arrays, which is min(n/2, s1.size) + min(n/2, s2.size)
        int ans = min((int)s.size(), min(n/2,(int)s1.size()) + min(n/2, (int)s2.size()));

        return ans;
    }
};

//  nums1 = [1,2,3,4,5,6], nums2 = [2,3,2,3,2,3]
// s1 = {1,2,3,4,5,6}   , s2 ={2,3}  s={1,2,3,4,5,6}
// ans = min(6, min(3,6)+min(3,2)) = min(6, 3+2) = min(6,5) = 5


int main(){

    return 0;
}