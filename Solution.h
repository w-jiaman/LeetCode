//
// Created by User on 2021/1/25.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "string"
#include "vector"

using namespace std;

/* 2 23 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static int findMaxForm(vector<string>& strs, int m, int n);        // 474 动态规划
    static int lengthOfLIS(vector<int>& nums);         // 300 动态规划
    static int maxTurbulenceSize(vector<int>& arr);        // 978 滑动窗口
    static int distinctSubseqII(const string& S);     // 940 动态规划
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);    // 2 链表
    static ListNode* mergeKLists(vector<ListNode*>& lists);       // 23 链表
    static int minCost(string s, vector<int>& cost);       // 1578 贪心算法
private:
    static void count0And1(string& str, int* result);      // 474 helper
    static ListNode* mergeKLists(vector<ListNode*>& lists, int beg, int end);       // 23 helper
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);       // 23 helper
};


#endif //LEETCODE_SOLUTION_H
