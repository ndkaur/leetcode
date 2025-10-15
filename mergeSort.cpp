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


// we first divide the array using mid and then break the array till a single elem each 
// once diving is done we merge the arr


class Solution{
public: 
    void merge(vector<int>& arr, int left, int mid, int right){
        int n1 = mid-left+1; // size of first arr
        int n2 = right-mid;

        // arrays to store two halves 
        vector<int> left_arr(n1);
        vector<int> right_arr(n2);
        int idx = left; // idx for the arr 

        // copying the data from the array into both the arrays
        for(int i=0; i<n1; i++){
            left_arr[i]= arr[idx];
            idx++;
        }

        for(int j=0; j<n2; j++){
            right_arr[j] = arr[idx];
            idx++;
        }

        // now sorting both the arrays 
        int i =0;
        int j=0;
        idx = left;

        while(i<n1 && j<n2){
            if(left_arr[i]<=right_arr[j]){
                arr[idx] = left_arr[i];
                i++;
            }
            else{
                arr[idx] = right_arr[j];
                j++;
            }
            idx++;
        }

        // remining elms
        while(i<n1){
            arr[idx] = left_arr[i];
            i++;
            idx++;
        }

        while(j<n2){
            arr[idx] = right_arr[j];
            j++;
            idx++;
        }
    }

    void mergeSort(vector<int>& arr, int left, int right){
        if(left>=right) 
            return;
        
        int mid = left+(right-left)/2;
        // diving the array 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        // merging the divide array as one 
        merge(arr, left, mid, right);
    }
};

int main(){
    Solution sol;
    vector<int> arr = {2,5,8,6,4};
    sol.mergeSort(arr, 0, arr.size()-1);
    for(auto val:arr){
        cout<<val<<" ";
    }
    return 0;
}