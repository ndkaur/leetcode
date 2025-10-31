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
    bool valid(vector<int> nums, int dir, int curr){
        int n = nums.size();
        while(curr>=0 && curr<n){
            if(nums[curr]==0){
                curr+= dir;
            }
            else { // num !=0
                // reduce value 
                nums[curr]--;
                //change dir
                if(dir==-1)
                    dir=1;
                else
                    dir = -1;
                // chnge dir for i(curr) also 
                curr += dir;
            }
        }
        bool flag = true;
        for(int num:nums){
            if(num!=0){
                flag= false;
                break;
            }
        }
        return flag;
    }
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        for(int i=0; i<n; i++){
            if(nums[i]!=0)
                continue;
            cnt += valid(nums, -1, i);// left
            cnt += valid(nums, 1, i); // right
        }
        return cnt;
    }
};



class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        // sum
        int left =0;
        int right =0;

        for(int num:nums){
            right += num;
        }

        for(int num:nums){
            if(num==0){
                // eg = 1 0 2 0 4 , here at idx=3, lsum =3, rsum =4
                // if we first start by moving right dir then we can make all zero 
                // if we first start by moving left then not possible 
                // so wee nedd to keep check of diff 1 also 
                if(left>=right && left-right<=1)
                    cnt++;
                if(right>=left && right-left<=1)
                    cnt++;
            }
            left+=num;
            right-=num;
        }
        return cnt;
    }
};



int main(){

    return 0;
}