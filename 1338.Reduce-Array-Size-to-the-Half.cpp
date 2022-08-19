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
// #include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    int minSetSize(vector<int>& arr){
        int n = arr.size();
        vector<int> v;
        sort(arr.begin(),arr.end());
        int count=1;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1])  
                count++;
            else{
                v.push_back(count);
                count=1;
            }
        } // counted the occurence of each element
        v.push_back(count);
        sort(v.begin(),v.end());
        int sz=n/2;
        int ans =0;
        for(int i=v.size()-1; i>=0 && sz>0;i--){
            ans++;
            sz=sz-v[i];
        } // move from behind and remove ele till not grater than or equal to half
        return ans;
    }
};


//  priority queue 
class Solution {
public:
    int minSetSize(vector<int>& arr){
        int n= arr.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>> pq; // cnt, ele
        for(auto m:mp){
            pq.push({m.second, m.first});
        }
        int count=0;
        int k=n;
        while(k-pq.top().first>n/2){
            k= k- pq.top().first;
            pq.pop();
            count++;
        }
        count++;
        return count;
    }
};

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n= arr.size();
        
        map<int,int> freq; // {key,occurence}
        for(auto a:arr)
            freq[a]++;
        // multimap cause now our key is the occurence , and there can be same value of occurence of nums 
        // {occurence , number , decresing order }
        multimap<int,int, greater<int>> mp;
        for(auto itr:freq){
            mp.insert({itr.second, itr.first}); //{count, num}
        }

         int count=0;
        int sz= n;
        for(auto itr:mp){
            count++;
            sz= sz- itr.first;
            if(sz <= n/2)
                return count;
        }
        return count;
    }
};


int main(){
    Solution sol;
    vector<int> arr ={7,7,7,7,7};
    int ans = sol.minSetSize(arr);
    cout<<ans;
    return 0;
}