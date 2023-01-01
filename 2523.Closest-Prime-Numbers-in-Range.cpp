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
    vector<int> closestPrimes(int left, int right) {
        // true = primes , false= composite  
        vector<bool> is_prime(right+1 , true);
        is_prime[1] = false; 
        vector<int> all; // to store all the prime factors found 
        
        // seive approach 
        for(int i =2; i * i <= right; i++){ // going only till square root of num 
            if(is_prime[i]){ // if it is a prime number 
            //mark all its multiples starting from square root 
                for(int j = i*i; j<=right; j+=i){ // move j to next multiple 
                    is_prime[j] = false; // composite  
                }
            }
        }
        // fill in the array with all prime numbers 
        for(int i=left; i<= right; i++){
            if(is_prime[i] == 1)
                all.push_back(i);
        }

        // 13, 17, 19, 23, 29, 31, 37, 41, 43, 47
        int mn = INT_MAX;
        vector<int> arr(2);
        for(int i=1; i<all.size(); i++){
            if(all[i] - all[i-1] < mn){
                mn = all[i] - all[i-1];
                arr = {all[i-1], all[i]};
            }
        }
        if(all.size()<2)
            return {-1,-1};
        return arr;
    }
};  

int main(){

    return 0;
}