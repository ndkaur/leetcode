/*
 * @lc app=leetcode id=2058 lang=cpp
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX;
        int firstIdx= -1;
        int prevIdx= -1;
        int index= 1;
        ListNode* prev= head;
        ListNode* curr= head->next;
        while(curr->next){
            if((curr->val > prev->val && curr->val > curr->next->val) || (curr->val< prev->val && curr->val< curr->next->val)){
                if(firstIdx ==-1){
                    firstIdx = index;
                }
                if(prevIdx !=-1){
                    minDistance = min(minDistance , index-prevIdx);
                }
                prevIdx = index;
            }
            prev= curr;
            curr= curr->next;
            index++;
        }
        if(minDistance == INT_MAX){
            return {-1,-1};
        }
        return {minDistance , prevIdx- firstIdx};
    }
};
// @lc code=end

