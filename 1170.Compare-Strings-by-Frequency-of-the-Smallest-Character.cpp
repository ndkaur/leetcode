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


class Solution { //O(n*m)
public: 
    int find(string& s){
        int n = s.size();
        map<char, int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        int ans=0;
        for(auto itr:mp){
            if(itr.second!=0){
                ans = itr.second;
                break;
            }
        }
        return ans;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        int m = words.size();
        vector<int>q , w;
        for(int i=0; i<n; i++){
            q.push_back(find(queries[i]));
        }
        for(int i=0; i<m; i++){
            w.push_back(find(words[i]));
        }
        // q ={3,2}  , w= {1 2 3 4}
        vector<int>ans;
        for(auto query:q){
            int cnt =0;
            for(auto word:w){
                if(query<word){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }   
};



class Solution { //O(n)+O(m) + O(nlogm)
public: 
    int find(string& s){ 
        int n = s.size();
        vector<int> arr(26,0);
        for(auto ch:s){
            arr[ch-'a']++;
        }
        for(int i=0; i<26; i++){
            if(arr[i]!=0){
                return arr[i];
            }
        }
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        int m = words.size();
        vector<int>q , w;
        for(int i=0; i<n; i++){
            q.push_back(find(queries[i]));
        }
        for(int i=0; i<m; i++){
            w.push_back(find(words[i]));
        }
        // q ={3,2}  , w= {1 2 3 4}
        // now two array -> queries, words
        // we need to find query < word , can apply binary search 
        // look for target in word with condition 
        vector<int>ans(q.size());

        sort(w.begin(), w.end());
        // iterating on each query
        for(int i=0; i<q.size(); i++){
            int l = 0;
            int r = w.size()-1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(w[mid]<=q[i]){
                    l= mid+1;
                }
                else 
                    r = mid-1;
            }
            // l is the pinter where first greater of w values occurs so toatl len - l
            ans[i] = w.size()-l;
        }
        return ans;
    }   
};


int main(){

    return 0;
}