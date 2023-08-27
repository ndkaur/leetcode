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
    int minOperations(vector<int>& nums, int target) {
        int n  = nums.size();
        long long sum =0;
        for(int num:nums){
            sum+=num;
        }
        if(sum<target)
            return -1;
        int cnt =0;
        sort(nums.begin(), nums.end());
        while(target>0){
            int num = nums.back();
            nums.pop_back();
            if(sum-num >= target)
                sum = sum-num;
            else if( num <= target){
                sum = sum-num;
                target = target-num;
            }
            else {  // num > target then half
                nums.push_back(num/2);
                nums.push_back(num/2);
                cnt++;
            }
        }
        return cnt;
    }
};


class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int n  = nums.size();
        long long sum =0;
        priority_queue<int> pq;
        for(int num:nums){
            sum+=num;
            pq.push(num);
        }

        if(sum<target)
            return -1;

        int cnt =0;
        
        while(target>0){
            int num = pq.top();
            pq.pop();
            sum = sum - num;

            if(num <= target) // num is alredy less than target
                target = target-num;
            else if(num>target && sum<target){
                cnt++;
                sum += num;
                pq.push(num/2);
                pq.push(num/2);
            }

            if(pq.empty() && target!=0){
                if(num>target && num!=1){
                    cnt++;
                    sum+= num;
                    pq.push(num/2);
                    pq.push(num/2);
                }
                else    
                    return -1;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}