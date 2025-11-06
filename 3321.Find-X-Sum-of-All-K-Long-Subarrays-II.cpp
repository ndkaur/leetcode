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
    long long res;
    set<pair<int,int>> small;
    set<pair<int,int>> large;
    map<int,int> freq;

    void insertIntoSet(pair<int,int> p, int x){
        // if current pair is greater that the elem in large set
        if(large.size()<x || *(large.begin())<p){
            res += p.first * 1LL * p.second;
            large.insert(p);
            // after nserting the size exceeds x 
            if(large.size()>x){
                auto itr = *large.begin();
                res -= itr.first*1LL*itr.second;
                large.erase(itr);
                small.insert(itr);
            }
        }
        else 
            small.insert(p);
    }

    void removeFromSet(pair<int,int> p){
        // if p value greter will be in larger  if smaller will be in small
        if(p >= *(large.begin())){
            res -= p.first * 1LL * p.second;
            large.erase(p);
        // if p is part of large and we remove it so the set sie is now x-1, but 
        // we have to always maintian x size of set so we will take largest elm from small and add in large

            if(small.size()>0){ // if small has elem then only we can remove 
                auto itr = *small.rbegin(); // largest elm
                res += itr.first * 1LL * itr.second;
                small.erase(itr);
                large.insert(itr);
            }   
        }
        else { // p is not a part of large then remove from small
            small.erase(p);
        }
    }

    void insert(int num, int x){
        // we need to remove the pre exising freq , incresing it then add it again
        if(freq[num]){
            removeFromSet({freq[num], num});
        }
        freq[num]++;
        insertIntoSet({freq[num], num},x);
    }

    void remove(int& num, int& x){
        // we need to remove preexisting freq, decrease it and add it again in set
        removeFromSet({freq[num], num});
        freq[num]--;
        if(freq[num]){
            insertIntoSet({freq[num], num}, x);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        res = 0;
        small.clear();
        large.clear();
        freq.clear();

        vector<long long> ans;
        for(int i=0; i<n; i++){
            insert(nums[i], x);

            if(i>=k){
                remove(nums[i-k], x);
            }
            // adding sum  when window is made
            if(i>=k-1)
                ans.push_back(res);
        }
        return ans;
    }
};

int main(){

    return 0;
}