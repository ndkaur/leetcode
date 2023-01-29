/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */
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

// @lc code=start
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        set<string> s;
        // insert each word int he set
        for(auto word:words){
            s.insert(word);
        }
        vector<string> ans;

        for(auto word: words){
            int  n= word.size();
            // for each word make a dp array 
            vector<int> dp(n+1,0);
            dp[0] = 1;
            for(int i=0; i<n; i++){
                if(!dp[i]) // if the value is 0 skip and move to the next index
                    continue;
                for(int j=i+1; j<=n; j++){
                    // in case when words is just cat , dog the  i = 0, j=3 , j-i = 3 <3 no so 
                    // the last index will not be marked as 1 
                    // but in case of concaneted string the dp of last index will be filled as 1 
                    // used j -i so that small words like cat dog dogs doesnt get added in ans cause otherwise there dp[n] = 1
                    if(j-i < n && s.count(word.substr(i, j-i))){
                        dp[j] = 1;
                    }
                }
                if(dp[n]){ // if last index is 1 that menas wor formed so add to the ans 
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};


// words =  cat, dog , catdog

// for word  = cat 
//  c  a  t    n =3
//  0  1  2    
//  dp=  0  1  2  3 
//       1  0  0  0 
//  i = 0 , j= 1   j-i = 1 <3 so subst(0,1) ->c 
//        , j= 2  j-i = 2 , 2<3  so substr(0,2) -> ca
//        , j = 3  j-i = 3 , 3 < 3  no so no substr 
// hence  final dp  =   1 0 0 0

// same for  word dog 

//  for word catdog   n= 6
//  c  a  t  d  o  g
//  0  1  2  3  4  5

// dp =  0  1  2  3  4  5  6  
//       1  0  0  0  0  0  0

// i=0 , j= 1  1<6 substr(0,1) -> c
//       j =2  2 <6  substr(0,2)-> ca 
//       j= 3  3<6  substr(0,3) -> cat   // found i =n set so mark dp[j] = dp[3] =1 

// dp =  0  1  2  3  4  5  6  
//       1  0  0  1  0  0  0

// i= 3 , j =4   (4-3) = 1<6  substr(3,1) =  d
//      j = 5   (5-3) = 2 < 6  substr(3,2) = do 
//    j= 6     (6-3)= 3 <6  substr(3, 3) = dog  // dog exist in set so dp[j] = dp[6] = 1
// // dp =  0  1  2  3  4  5  6  
//          1  0  0  1  0  0  1  
//  finally check that dp[n] = dp[6] = 1 so this is concatenated word 
// add to ans 



// @lc code=end


int main(){

    return 0;
}