//
// Created by User on 2021/1/25.
//

#include "Solution.h"

#include "iostream"
#include "string"
#include "vector"

using namespace std;

/*
 * 474 动态规划
 * */
int Solution::findMaxForm(vector<string>& strs, int m, int n){
    int ***dpCache = new int** [2];
    int current = 0;    // 维护一个指针指向当前使用的数组

    for(int i=0; i<2; i++){
        dpCache[i] = new int* [m+1];
        for(int j=0; j<=m; j++){
            dpCache[i][j] = new int[n+1];
            for(int k=0; k<=n; k++){
                dpCache[i][j][k] = 0;
            }
        }
    }

    int *count = new int[2];
    for(int i=1; i<=strs.size(); i++, current++){
        count0And1(strs[i-1], count);
        for(int j=0; j<=m; j++){
            for(int k=0; k<=n; k++){
                dpCache[current%2][j][k] = dpCache[(current+1)%2][j][k];

                if(j>=count[0]&&k>=count[1]) {
                    if (dpCache[(current+1)%2][j - count[0]][k - count[1]] + 1 > dpCache[current%2][j][k]) {
                        dpCache[current%2][j][k] = dpCache[(current+1)%2][j - count[0]][k - count[1]] + 1;
                    }
                }
            }
        }
    }
    delete[] count;

    int result = dpCache[(current+1)%2][m][n];

    for(int i=0; i<2; i++){
        for(int j=0; j<=m; j++){
            delete []dpCache[i][j];
        }
    }

    return result;
}

/*
 * 474 helper
 * */
void Solution::count0And1(string &str, int* result) {
    result[0] = 0;
    result[1] = 0;

    for(char ch:str){
        if(ch=='0'){
            result[0]++;
        }else if(ch=='1'){
            result[1]++;
        }
    }
}

/*
 * 300 动态规划
 * */
int Solution::lengthOfLIS(vector<int> &nums) {
    int *dp = new int[nums.size()];

    for(int i=0; i<nums.size(); i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(nums[i]>nums[j]&&dp[j]+1>dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
    }

    int maxLen = 0;
    for(int i=0; i<nums.size(); i++){
        if(dp[i]>maxLen){
            maxLen = dp[i];
        }
    }

    delete []dp;

    return maxLen;
}

/*
 * 978 滑动窗口
 * */
int Solution::maxTurbulenceSize(vector<int> &arr) {
    if(arr.size()==1||(arr.size()==2&&arr[0]==arr[1])){
        return 1;
    }

    int left=0, right=1;
    int maxLen=0;
    int bigger = 0;

    while(right<arr.size()){
        if(right==left+1){        // 从上一轮退出，重新定义大小规律
            if(arr[left]>arr[right]){
                bigger = left%2;
            }else if(arr[right]>arr[left]){
                bigger = right%2;
            }else{      // 相等
                left++;
            }
            right++;
            continue;
        }

        if(bigger==0){  // 双数索引的值更大
            if((right%2==0&&arr[right]>arr[right-1]) || (right%2==1&&arr[right]<arr[right-1])){     // 当前索引为双数，且大于前一个数 或 当前索引为单数，且小于前一个数
                right++;
                continue;
            }else{      // 若不满足上述条件，则退出当前窗口周期
                if(right-left>maxLen){
                    maxLen = right - left;
                }
                left=right-1;
            }
        }else{      // 单数索引的值更大
            if((right%2==1&&arr[right]>arr[right-1]) || (right%2==0&&arr[right]<arr[right-1])){
                right++;
                continue;
            }else{
                if(right-left>maxLen){
                    maxLen = right-left;
                }
                left=right-1;
            }
        }
    }

    if(right-left>maxLen){
        maxLen = right-left;
    }

    return maxLen;
}

/*
 * 940 动态规划
 * */
int Solution::distinctSubseqII(const string& S) {
    int* dp = new int[S.size()+1];
    for(int i=0; i<S.size()+1; i++){
        dp[i] = 0;
    }

    int* count = new int[26];   // 记录字符上一次出现在S中的位置
    for(int i=0; i<26; i++){
        count[i] = -1;
    }

    for(int i=1; i<S.size()+1; i++){
        // 对应字符S[i-1]
        if(count[S[i-1]-97]==-1){
            dp[i] = dp[i-1]*2 + 1;
        }else{
            dp[i] = dp[i-1]*2 - dp[count[S[i-1]-97]];
        }

        count[S[i-1]-97] = i-1;

        if(dp[i]<0){
            dp[i] += 1000000007;
        }else{
            dp[i] %= 1000000007;
        }
    }

    int result = dp[S.size()];

    delete []dp;
    delete []count;

    return result;
}

/*
 * 2 链表
 * */
ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    // 遍历两个链表，找出较长的链表
    int lenOfl1=0, lenOfl2=0;
    ListNode* current;

    current= l1;
    while(current){
        lenOfl1++;
        current = current->next;
    }

    current = l2;
    while(current){
        lenOfl2++;
        current = current->next;
    }

    // x 为更长的链表
    int x,y;
    ListNode *xPtr, *yPtr;
    if(lenOfl1>lenOfl2){
        x = lenOfl1;
        xPtr = l1;
        y = lenOfl2;
        yPtr = l2;
    }else{
        x = lenOfl2;
        xPtr = l2;
        y = lenOfl1;
        yPtr = l1;
    }

    bool isCarry = false;
    ListNode* result = new ListNode;
    current = result;

    while(y>0){
        current->val = xPtr->val + yPtr->val;
        if(isCarry){
            current->val += 1;
        }
        isCarry = false;

        if(current->val>9){
            current->val %= 10;
            isCarry = true;
        }

        x--;
        y--;

        xPtr = xPtr->next;
        yPtr = yPtr->next;

        if(x!=0){
            current->next = new ListNode;
            current = current->next;
        }
    }

    while(x!=0){
        current->val = xPtr->val;
        x--;
        xPtr = xPtr->next;

        if(isCarry){
            current->val += 1;
        }

        if(current->val>9){
            current->val %= 10;
            isCarry = true;
        }else{
            isCarry = false;
        }

        if(x!=0){
            current->next = new ListNode;
            current = current->next;
        }
    }

    if(isCarry){
        current->next = new ListNode;
        current = current->next;
        current->val = 1;
    }

    return result;
}

/*
 * 23 链表
 * */
ListNode* Solution::mergeKLists(vector<ListNode *> &lists) {
    return mergeKLists(lists, 0, lists.size()-1);
}

/*
 * 23 helper
 * */
ListNode* Solution::mergeKLists(vector<ListNode*> &lists, int beg, int end) {
    if(beg==end){
        return lists[beg];
    }else if(beg>end){
        return nullptr;
    }else{
        int mid = (beg+end)/2;
        return mergeTwoLists(mergeKLists(lists, beg, mid), mergeKLists(lists, mid+1, end));
    }
}

/*
 * 23 helper
 * */
ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode head, *tail = &head;
    while(list1 && list2){
        if(list1->val < list2->val){
            tail->next = list1;
            list1 = list1->next;
        }else{
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 ? list1 : list2;
    return head.next;
}

/*
 * 1578 贪心算法
 * */
int Solution::minCost(string s, vector<int> &cost) {
    int left=0, right=0;
    int minCost = 0;
    while(left<s.size()){
        right = left + 1;
        while(right<s.size() && s[left]==s[right]){
            right++;
        }

        int maxCost = -1;
        int sumCost = 0;
        for(int i=left; i<right; i++){
            if(cost[i]>maxCost){
                maxCost = cost[i];
            }
            sumCost+=cost[i];
        }

        minCost += (sumCost-maxCost);

        left = right;
    }
    return minCost;
}

/*
 * 1663 贪心算法
 * */
string Solution::getSmallestString(int n, int k) {
    string result;
    while(n>0){
        if(k<=(n-1)*26){
            result += 'a';
            k -= 1;
        }else{
            result += ((k-(n-1)*26)+96);
            k = (n-1)*26;
        }
        n--;
    }
    return result;
}
