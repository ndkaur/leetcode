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
    static bool comp(string& s1, string& s2){
        return s1+s2 > s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> temp;
        for(auto num:nums){
            temp.push_back(to_string(num));
        }
        // we want to sort in decresing oder by adding two nums making a full stirng
        
        //   sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        sort(temp.begin(), temp.end(), comp);
        string ans;
        for(auto t:temp){
            ans+=t;
        }
        // case when all nums are 0 or the staring nums are 0
        while(ans[0]=='0' && ans.size()>1){
            ans.erase(0,1);
        }
        return ans;
    }
};

// 10 2   102  210  
// 2 10  res = 210

// 3 30 34 5 9     
// 3 34 5 9 30   
// 34 5 9 3 30
// 34 9 5 3 30   
// 9 34 5 3 30 
// 9 5 34 3 30 

// 0 0 0 ans= 0
// 000 ans[0]=0 , len =3  ans = 00
// 00 ans[0]=0 , len=2  ans = 0



int main(){

    return 0;
}