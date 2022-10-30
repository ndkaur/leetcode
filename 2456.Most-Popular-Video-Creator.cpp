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
    vector<vector<string>> mostPopularCreator(vector<string>& cre, vector<string>& ids, vector<int>& views) {
        int n = cre.size();
        // creator , { view , id}
        map<string, vector<pair<int,string>>> mp1;
        // creator views 
        map<string, long long> mp2;

        for(int i=0; i<n; i++){
            mp2[cre[i]] += views[i];
            mp1[cre[i]].push_back({views[i], ids[i]});
        }
        // finding the max view count of all 
        long long mx =0;
        for(auto itr:mp2){
            long long popular = itr.second;
            mx = max(mx, popular);
        }

        vector<vector<string>> ans;
        for(auto itr: mp2){
            string creator = itr.first;
            long long popular = itr.second;
            if(popular == mx){
                // go in mp1 find all the values of ids with the view cnt as mx cnt 
                sort(mp1[creator].begin(), mp1[creator].end(), [](pair<int,string>& a, pair<int,string>& b)-> bool{
                    // coparing the int val ie the views 
                    // compare strings ids only when both the views values are equal 
                    // otherwise go according to the max view cnt 
                    if(a.first > b.first)
                        return true;
                    else if(a.first < b.first)
                        return false;
                    else // lexciographical smaller string return true 
                        return (a.second < b.second);
                });

                string mostView = mp1[creator][0].second;
                ans.push_back({creator, mostView});
            }
        }
        return ans;
    }
};



class Solution {
private: 
    static bool cmp(pair<long long, string> a , pair<long long, string> b){
        // both the view values are equal  then return lexicographical small
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
public:
    vector<vector<string>> mostPopularCreator(vector<string>& cre, vector<string>& ids, vector<int>& views) {
        long long n = cre.size();
        
        map<string, long long> mp1; // creator views 

        map<string, vector<pair<long long,string>>> mp2;  // creator , { view , id}

        vector<vector<string>> ans; // creator, id
        long long mx = INT_MIN;

        for(int i=0; i<n; i++){
            mp1[cre[i]] += views[i];
            mp2[cre[i]].push_back({views[i], ids[i]});
            // finding the max view count of all 
            mx = max(mx, mp1[cre[i]]);
        }
    
        for(auto &[creator,view]: mp1){
            
            if(view == mx){
                sort(mp2[creator].begin(), mp2[creator].end(), cmp);
                ans.push_back({creator, mp2[creator].front().second}); // creator , ids
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}