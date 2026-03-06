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
    bool check(int sum, int num, map<int,int>& mp){
        while(sum>0){
            int rem = sum%10;
            if(mp.find(rem)==mp.end()) // digit in sum doesnt exist 
                return false;
            mp[rem]--;
            if(mp[rem]==0)
                mp.erase(rem);
            sum = sum/10;
        }
        return mp.empty();
    }
    bool isDigitorialPermutation(int n) {
        vector<int> fact = {1,1,2 , 6 , 24 , 120 , 720 , 5040 , 40320 , 362880};
        int sum =0;
        int num = n;
        map<int,int> mp;
        while(n>0){
            int rem = n%10;
            mp[rem]++;
            sum += fact[rem];
            n=n/10;
        }
        return check(sum, num, mp);
    }
};

// 145 = 1!+ 4! + 5! = 145 , 145==145 true
// but  541 = 5!+4!+1! = 145 , 541 != 145 , so with logic sum==num this will return false 

// we need to return true for that num whose permutation also has same sum , so directly using the condition that num==sum is not right 
// to resolve this issue :- 
// find factorial sum , and for the sum we check if the digits are same 

// if the sum digits and the num digits are same then any permutaton wil lead to same result 


int main(){

    return 0;
}