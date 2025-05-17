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


class Solution0 {
    public:
        int lengthAfterTransformations(string s, int t) {
            // int n  = s.size();
            string temp="";
            while(t--){
                for(int i=0; i<s.size(); i++){
                    if(s[i]=='z'){
                        temp+= "ab";
                    }
                    else{
                        temp+= s[i]+1;
                    }
                }
                cout<<temp<<" ";
                s = temp;
                temp =""; 
            }
            return s.size();
        }
    };
    
    
    
    class Solution {
    public:
        int mod = 1e9+7;
        int modADD(int a, int b){
            return ((a%mod)+ (b%mod))%mod;
        }
        int lengthAfterTransformations(string s, int t) {
            int n  = s.size();
            vector<int> freq(26,0);
            for(auto ch:s){
                freq[ch-'a']++;
            }
    
            while(t--){
                vector<int> nfreq(26,0);
                // going to each char and increasing its frequency 
                for(int i=0; i<26; i++){
                    if(i<25){// char is not z
                        // a ->b  freq[b]= freq[a]
                        nfreq[i+1] = freq[i];
                    }
                    else{ // char is z
                        // z -> ab , freq[a]= freq[z] , freq[b]=freq[z]
                        // nfreq array is empty 
                        // if there is "a" in string it will become "b"
                        // and freq of "b" would have increased
    
                        //but "b" could already have a count so when "z" occurs
                        // the freq of both "a" and "b" increase 
                        // so the prevFreq of "b"  and "z" freq should be added 
                        nfreq[0] = freq[i];
                        // z->b 
                        nfreq[1] = modADD(nfreq[1], freq[i]);
                    }
                }
                freq = nfreq;
            }
            int new_sz =0;
            for(int i=0; i<26; i++){
                // adding all the frequiencies we have collected in the freq arrray 
                new_sz =  modADD(new_sz, freq[i]);
            }
            return new_sz;
        }
    };

int main(){

    return 0;
}