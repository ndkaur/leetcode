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


//Approach (Using BFS + Sieve)
//T.C : O(maxEL * loglog(maxEl))
//S.C : O(maxEl + n)
class Solution {
public:
    void build(int mx, vector<bool>& isPrime){
        isPrime[0]= false; // 0 and 1 not prime 
        isPrime[1] = false;

        for(int num=2; num<=sqrt(mx); num++){
            if(isPrime[num]){ // mark all its multiples as not prime false
                for(int factor=num*2; factor<=mx; factor+=num){
                    isPrime[factor] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> mp; // store elm->idx
        int mx =0;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
            mx = max(mx, nums[i]);
        }

        // seive for prime factor
        // storing if num is prime or not for each num till max 
        vector<bool> isPrime(mx+1,true);
        build(mx, isPrime);

        queue<int> q;
        q.push(0);  //storing the indexes
        vector<bool> visited(n,false);
        visited[0] = true;

        set<int> seen;
        int cnt = 0;

        while(q.size()){
            int sz = q.size();
            while(sz--){
                int idx = q.front();
                q.pop();

                if(idx==n-1){
                    return cnt;
                }
                // move back 
                if(idx-1>=0 && !visited[idx-1]){
                    q.push(idx-1);
                    visited[idx-1]=true;
                }

                // move ahead
                if(idx+1<n && !visited[idx+1]){
                    q.push(idx+1);
                    visited[idx+1] = true;
                }
                // not prime or alredy seen prime
                if(!isPrime[nums[idx]] || seen.count(nums[idx]))
                    continue;
                
                // prime and exist in nums then push in q
                for(int factor=nums[idx]; factor<=mx; factor+=nums[idx]){
                    if(!mp.contains(factor))
                        continue;
                    // exist in map, then add all the idx of the factors
                    for(int j:mp[factor]){
                        if(!visited[j]){
                            q.push(j);
                            visited[j]= true;
                        }
                    }
                }

                seen.insert(nums[idx]);
            }
            cnt++;
        }
        return cnt;
    }
};

// store all the factors for a prime num already in a array
// store map idx->elem
// use bfs , mainitan visited, for i+1, i-1 and is prime then factoe 
// mainted a set for not repating the already taken prime num



int main(){

    return 0;
}