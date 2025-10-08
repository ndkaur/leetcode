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


class Solution0 { // it gives wrong answer
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        int zcnt = 0;
        map<int,int> mp;
        vector<int> zidx;
        vector<int> ans(n,1);
        int idx=0;

        for(int i=0; i<n; i++){
            if(rains[i]==0){
                zcnt++;
                zidx.push_back(i);
            }
            else{
                mp[rains[i]]++;
                ans[i]=-1;
            }
            
            if(mp[rains[i]]>1 && zcnt>=1 && idx<zidx.size()){
                // int first_occ= lower_bound(rains.begin(), rains.end(), rains[i])-rains.begin();         
                // if(first_occ > zidx[idx]){ // first occ, zero , second occ
                //     return {};
                // }
                mp[rains[i]]--;
                zcnt--;
                ans[zidx[idx]]=rains[i];
                idx++;
            }
            else if(mp[rains[i]]>1 && zcnt==0){
                return {};
            }
        }
        return ans;
    }
};

// {0,1,1} -> in this case the ans ={} it will be flooded, as the 0 exist before the occurence of the first lake , if it would have been loke this 
// {1,0,1}-> then ans = {-1,1, -1} 
// so we need to check that mp[rain[i]] when it gets 2 then the first occurence of lake must be before the zero occurence 


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        // map is storing the index of the value 
        map<int,int> mp;
        set<int> zidx; // we use set so that we can easily remove the values once they are used 
        vector<int> ans(n,0);
      
        for(int i=0; i<n; i++){
            if(rains[i]==0){
                zidx.insert(i);
                continue;
            }
            // if that value alredy exist in map 
            if(mp.find(rains[i])!=mp.end()){
                // we dont have zeros but a value is repeating 
                if(zidx.size()==0){
                    return {};
                }
                // we have zeros the empty the lake 
                else{
                    // {0,1,1} -> cause of this case we know that the zero must occur after the first occurence of the value 
                    // if zero occur before the first occurence and then second occurence is there then we cant fill it ans ={ empty array }
                    // we find lb idx>=val ie lb for the first occurence in the zerostore set 
                    auto itr = zidx.lower_bound(mp[rains[i]]);
                    // if all the zero exist before the first occrence the itr will reach end of set
                    if(itr==zidx.end())
                        return {};
                    
                    // if the actual valid zero idx occur then fill zero in ans array with the rain value 
                    ans[*itr] = rains[i];
                    zidx.erase(itr);
                }
            }
            ans[i] = -1;
            mp[rains[i]] = i;
        }

        // eg-> {4, 0, 0, 0, 4}
        // ans= {-1,4, 1, 1, -1}
        // so case wehre there are remining 0 so fill them with 1 
        for(int i=0; i<n; i++){
            if(ans[i]==0)
                ans[i]=1;
        }
        return ans;
    }
};


int main(){

    return 0;
}