#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    const long long int mod =1000000007;
    int maxArea(int h, int w, vector<int>& hz, vector<int>& vr) {
        int he = hz.size();
        int we = vr.size();
        int ans =0;
        sort(hz.begin(),hz.end());
        sort(vr.begin(),vr.end());

        vector<int> hzdiff={hz[0]};
        for(int i=1;i<he;i++){
            int dif = hz[i]-hz[i-1]; // diff of each consectutive element 
            hzdiff.push_back(dif);
        }
        int a= h-hz.back(); // h given -last element 
        hzdiff.push_back(a);
        
        vector<int> vrdiff={vr[0]};
        for(int i=1;i<we;i++){
            int dif= vr[i]-vr[i-1];
            vrdiff.push_back(dif);
        }
        int b = w-vr.back(); // w given - last ele of vr array 
        vrdiff.push_back(b);

        long long int ans1= *max_element(hzdiff.begin(),hzdiff.end());
        long long int ans2= *max_element(vrdiff.begin(),vrdiff.end());

        return (int)(ans1%mod * ans2%mod);
    }
};


int main(){
    Solution sol;
    vector<int> hz={1,2,4};
    vector<int> vr= {1,3};
    int h =5;
    int w=4;
    int ans = sol.maxArea(h,w,hz,vr);
    cout<<ans;
    return 0;
}