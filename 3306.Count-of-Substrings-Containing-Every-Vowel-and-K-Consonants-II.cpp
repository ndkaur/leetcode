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
        bool isVowel(char ch){
            return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
        }
        void findnext(vector<int>& next_consonant, string& word){
            int n = word.size();
            int next_occurance= n;
            // alccoating and then updating the next consonant value 
            for(int i=n-1; i>=0; i--){
                next_consonant[i]=next_occurance;
                if(!isVowel(word[i])){
                    next_occurance=i;
                }
            }
        }
        long long countOfSubstrings(string word, int k) {
            int n = word.size();
            // precomputing the occurnce of cononant for each char
            vector<int> next_consonant(n);
            findnext(next_consonant, word);
            
            long long ans = 0;
            int cons = 0;
            unordered_map<char, int> mp;
            int l = 0;
            int r =0;
            // if the right ptr is not moving to the right hand side then we dont end up changing the frequency
            int prev = -1;
    
            // we need to keep chaeck of both whether the map size is 5 or if 
            // if the consonant count became greater than k then move left ptr
            while(r<n){
                if(prev!=r){
                    if(isVowel(word[r])){
                        mp[word[r]]++;
                    }
                    else 
                        cons++;
                    prev=r;
                }
                // we can from beigning keep on checking if the map has 5 vowels 
                // so to save time we keep the asusming length after which there is a possiblity
                // that we can find a valid window 
                // valid window minimum length required = 5 + k - 1 
                // 5 vowel map size, k = consonants, -1 for 0 based indexing 
                if(r>=(5+k-1)){
                    if(mp.size()==5 && cons==k){
                        // valid window, cnt= windows starting from l
                        // cnt = till we dont make the window unvalid by finding the next constonnst 
                        // next vowel occurance - where our r pointer is cuurenlty 
                        ans+=  next_consonant[r]-r;
                    }
                    // shrink window 
                    // we move l ptr on two conditon 
                    // 1. when window is still vald
                    // 2. the constant cnt got greater than k
                    // if not any of these above 2 conditons happen we simply move r ptr
                    if((mp.size()==5 && cons==k) || (cons>k)){
                        if(isVowel(word[l])){ // l is a vowel
                            mp[word[l]]--;
                            // if the freq became 0 remove that char from map 
                            // as it will impact the map size
                            if(mp[word[l]]==0){
                                mp.erase(word[l]);
                            }
                        }
                        else // l is a consonantt
                            cons--;
                        // move l ptr
                        l++;
                    }
                    else // not valid window or cons !=k
                        r++;  
                } 
                else // we havent gone till minimum assuming length 
                    r++;
            }
            return ans;
        }
    };
    
    // freq[a,e,i,o,u] can be >=1, must occur once but can occur more than oce
    // freq of non vowel must be==k
    // for keeping track of freq we use map cause if we use set then its hard to remove the chars for the ith pointer , set remove the c=occurance of char all toghter , but what if the same char occur at another place also in the window
    
    // no of valid windows 
    // a) window staring at l 
    // b) windows ending at r
    //      0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    // eg=  a e e a e p k b i o  u  a  e  e  i p
    //  l=0  curr window= aeiou and 3 constonants occur till j=10
    // windows string from l=0 ?
    // then string at l -> we find the nearest constonant cause that will make or break a valid windoe
    // nearest constonat occur at 15 , so 15-10 =5 
    // that means 5 sucbstrings can be there staring from l=0 
    
    // valid windoes ending at r ?
    // when we move the l ptr the size of window changes but if the conditon stisfy then its valid
    
    // a) window staring at l -> count until non consonant is found
    // b) windows ending at r -> count unitl valid window is break by moving l
    
    // for finding the next consonant where it occurs ? 
    // we can precompute the consonant array for each char store its next constanct index 
    

int main(){

    return 0;
}