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
    int distinctPrimeFactors(vector<int>& nums) {
        int  n= nums.size();
        set<int> st;
        for(int i=0; i<n; i++){ // passing each num of array one by one 
            FindPrimeFactors(nums[i], st);
        }
        return st.size();
    }
    void FindPrimeFactors(int num, set<int>& s){
        // finding the prime factors of num and adding them to the set 
        while(num % 2 == 0){ // if two is the prime factor 
            s.insert(2);
            num = num /2 ;
        }
        // i<sqrt(num) can also be written as i * i <= num
        for(int i=3; i<= sqrt(num); i=i+2){ // i = 3 ,5 , 6 skipping even num , as they alredy taken out by num % 2
            // i will always be prime as we remove all the multiples 
            while(num % i == 0){ // start from 3 to find prime factor 
                s.insert(i);
                num = num/i;
            } 
        } 
        // sometimes it is the case when num is not get into for loop 
        //  eg = 7 , i=3 -> 3*3 =9 , 9< 7 no 
        // but 7 is prime so directly put in the set 
        if(num>2){
            s.insert(num);
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2};
    int ans = sol.distinctPrimeFactors(nums);
    cout<<ans;
    return 0;
}