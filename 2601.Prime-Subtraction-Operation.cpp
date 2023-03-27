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
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        

        for(int i=0; i<n; i++){
            if(nums[i]==1 && i==0)
                continue;
            else if(nums[i]==1 && i>0)
                return false;
            // finding prime numbers till one num smaller than curr num
            vector<int> pnum = findPrime(nums[i]-1);
            // we need the last smaller prime num than curr num
            // adding 0 in front od arr -> reverse add 0 reverse
            reverse(pnum.begin(), pnum.end());
            pnum.push_back(0);
            reverse(pnum.begin(), pnum.end());

            if(i==0){
                // for the first num 
                // last prime num which will be imediate smalller 
                nums[i] = nums[i]- pnum[pnum.size()-1];
            }
            else{
                bool flag = false;
                for(int j=pnum.size()-1; j>=0; j--){
                    // subtract the num from the pnum until the increasing condition meet
                    if(nums[i]-pnum[j] > nums[i-1]){ /// inc condtion satisfied
                        nums[i] = nums[i]-pnum[j];
                        flag = true;
                        break;
                    }
                }
                if(!flag) // if flag still false means somewhere decreasing array
                    return false;
            }
        }
        return true;
    }

    vector<int> findPrime(int n){
        // finding all prime nums less than n 
        vector<int> v;
        vector<bool> isPrime(n+1,1); // consedring all are prime at first
        isPrime[0] = isPrime[1] = false;
        for(int p=2; p*p<=n; p++){
            if(isPrime[p]){
                for(int i=p*p; i<=n; i+=p){
                    isPrime[i]= false;
                }
            }
        }
        for(int i=2; i<=n; i++){
            if(isPrime[i])
                v.push_back(i);
        }
        return v;
    }
};

int main(){

    return 0;
}