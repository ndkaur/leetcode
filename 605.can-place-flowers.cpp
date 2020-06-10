/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

#include "bits/stdc++.h"
using namespace std;
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n){    
        int len = flowerbed.size();
        int count=0;
        // if(len==1 && flowerbed[0]==0)
        //     return true;
        for(int i=0;i<len;i++){
            if(flowerbed[i]==0){
                // starting i from [i]=0 
                if(i==0 && flowerbed[i+1]!=1)
                {
                    flowerbed[i]=1;
                    count++;
                }  
                // last value of i is 0;
                else if(i==len-1 && flowerbed[i-1]!=1)
                {
                    flowerbed[i]=1;
                    count++;
                }
                //  when i is in between the array
                else if(i!=0 && i!=flowerbed.size()-1 && flowerbed[i+1]!=1 && flowerbed[i-1]!=1)
                {
                    flowerbed[i]=1;
                    count++;
                }
            }
        }
        return count>=n;
    }
};

int main(){
    Solution sol;
    vector<int> flower={1,0,0,0,1};
    int n;
    bool out=sol.canPlaceFlowers(flower,2);
    cout<<out;
    return 0;
}

