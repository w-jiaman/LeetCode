//
// Created by User on 2021/1/25.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include "map"
#include "string"
#include "vector"

using namespace std;

/* 链表节点 2 23 25 206 剑指 Offer 22 142 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 二叉树结点 104 102 103 144 1382 108 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 双向链表节点 146 */
struct DListNode {
    int key, value;
    DListNode *prev, *next;
    DListNode(): key(0), value(0), prev(nullptr), next(nullptr){}
};

/* [146.LRU缓存机制] LRU */
class LRUCache {
private:
    std::map<int, DListNode*> cache;
    DListNode* head;
    DListNode* tail;
    int size;
    int capacity;
    void move2Head(DListNode* node){    // 将当前指向的节点换到第一个
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void addNode(DListNode* node){     // 将新键的节点添加到双向链表头
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    int removeTail(){   // 移除最后一个节点，且返回 key
        DListNode* lastOne = tail->prev;
        int key = lastOne->key;

        lastOne->prev->next = tail;
        tail->prev = lastOne->prev;

        delete lastOne;
        return key;
    }
public:
    explicit LRUCache(int _capacity){
        capacity = _capacity;
        size = 0;
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache(){
        DListNode* ptr = head;
        while(ptr){
            DListNode* tmp = ptr->next;
            delete ptr;
            ptr = tmp;
        }
    }
    void put(int key, int value){
        if(cache.find(key)==cache.end()){
            // 若不存在，新建 [关键字-值]
            DListNode* newNode = new DListNode();
            newNode->key = key;
            newNode->value = value;
            cache[key] = newNode;
            addNode(newNode);

            // 检查容量，若此时 size==capacity，则移除最后一个节点，否则递增size
            if(size==capacity){
                cache.erase(removeTail());
            }else{
                size++;
            }
        }else{
            // 若存在，覆盖原值，更新缓存
            DListNode* node = cache[key];
            node->value = value;
            move2Head(node);
        }

    }
    int get(int key){
        // 若不存在，返回 -1
        if(cache.find(key)==cache.end()){
            return -1;
        }

        // 若存在，获取双向链表节点指针，并将该节点移到第一个
        DListNode* node = cache[key];
        move2Head(node);
        return node->value;
    }
};

/* [460.LFU 缓存] LFU*/
class LFUCache {
private:
    const int capacity;
    unsigned long index = 0;
public:
    LFUCache(int capacity) : capacity(capacity) {

    }

    int get(int key) {

    }

    void put(int key, int value) {

    }
};


class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target);       // [1.两数之和] 暴力法
    static int removeElement(vector<int>& nums, int val);   // [27.移除元素] 数组操作
    static int threeSumClosest(vector<int>& nums, int target);  // [16.最接近的三数之和] 双指针
    static vector<vector<int>> threeSum(vector<int>& nums);     // [15.三数之和] 双指针
    static vector<string> letterCombinations(string digits);    // [17.电话号码的字母组合] 回溯算法
    static string convert(string s, int numRows);           // [6.Z字形变换] 几何
    static int maxArea(vector<int>& height);       // [11.盛最多水的容器] 双指针
    static vector<int> twoSum2(vector<int>& numbers, int target);    // [167.两数之和II-输入有序数组] 数组操作
    static int maxDepth(TreeNode* root);        // [104.二叉树的最大深度] 深度优先搜索
    static vector<vector<int>> transpose(vector<vector<int>>& A);    // [867.转置矩阵] 数组操作
    static int majorityElement(vector<int>& nums);       // 面试题 17.10 数组操作
    static int trap(vector<int>& height);   // 面试题 17.21 双指针
    static int getWinner(vector<int>& arr, int k);      // [1535.找出数组游戏的赢家] 数组操作
    static vector<int> sortedSquares(vector<int>& nums);   // [977.有序数组的平方] 排序
    static bool exist(vector<vector<char>>& board, string word);    // [79.单词搜索] 深度优先搜索
    static void solve(vector<vector<char>>& board);         // [130.被围绕的区域] 深度优先搜索
    static vector<int> findDuplicates(vector<int>& nums);   // [442.数组中重复的数据] 哈希算法
    static int dominantIndex(vector<int>& nums);        // [747.至少是其他数字两倍的最大数] 暴力法
    static int longestSubarray(vector<int>& nums);      // [1493.删掉一个元素以后全为 1 的最长子数组] 递推算法
    static int characterReplacement(string s, int k);   // [424.替换后的最长重复字符] 滑动窗口
    static vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A);  // [832.翻转图像] 数组操作
    static vector<int> maxSlidingWindow(vector<int>& nums, int k);      // 剑指 Offer 59 - I 滑动窗口
    static int maxScore(vector<int>& cardPoints, int k);        // [1423.可获得的最大点数] 数组操作
    static int maxDotProduct(vector<int>& nums1, vector<int>& nums2);   // [1458.两个子序列的最大点积] 动态规划
    static int numSquares(int n);       // [279.完全平方数] 动态规划
    static int findMaxForm(vector<string>& strs, int m, int n);        // [474.一和零] 动态规划
    static int lengthOfLIS(vector<int>& nums);         // [300.最长递增子序列] 动态规划
    static int maxTurbulenceSize(vector<int>& arr);        // [978.最长湍流子数组] 滑动窗口
    static int distinctSubseqII(const string& S);     // [940.不同的子序列 II] 动态规划
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);    // [2.两数相加] 链表
    static ListNode* mergeKLists(vector<ListNode*>& lists);       // [23.合并K个升序链表] 链表
    static int minCost(string s, vector<int>& cost);       // [1578.避免重复字母的最小删除成本] 贪心算法
    static string getSmallestString(int n, int k);      // [1663.具有给定数值的最小字符串] 贪心算法
    static int minSetSize(vector<int>& arr);           // [1338.数组大小减半] 贪心算法
    static vector<int> minSubsequence(vector<int>& nums);   // [1403.非递增顺序的最小子序列] 贪心算法
    static int eraseOverlapIntervals(vector<vector<int>>& intervals);   // [435.无重叠区间] 贪心算法
    static int findMinArrowShots(vector<vector<int>>& points);      // [452.用最少数量的箭引爆气球] 贪心算法
    static int wiggleMaxLength(vector<int>& nums);         // [376.摆动序列] 动态规划
    static int wiggleMaxLength2(vector<int>& nums);
    static int wiggleMaxLength3(vector<int>& nums);     // [376.摆动序列] 贪心算法
    static ListNode* reverseKGroup(ListNode* head, int k);  // [25.K 个一组翻转链表] 链表
    static int maxProfit(vector<int>& prices);  // [121.买卖股票的最佳时机] 遍历
    static vector<vector<int>> levelOrder(TreeNode* root);     // [102.二叉树的层序遍历] 广度优先搜索
    static vector<vector<int>> zigzagLevelOrder(TreeNode* root);      // [103.二叉树的锯齿形层序遍历] 广度优先搜索
    static ListNode* reverseList(ListNode* head);          // [206.反转链表] 链表
    static ListNode* reverseList2(ListNode* head);
    static vector<int> preorderTraversal(TreeNode* root);      // [144.二叉树的前序遍历] 栈
    static int calculate(string s);     // [224.基本计算器] 栈
    static int rob(vector<int>& nums);  // [198.打家劫舍] 动态规划
    static bool isBalanced(TreeNode* root);    // [110.平衡二叉树] 深度优先搜索
    static ListNode *detectCycle(ListNode *head);   // [142.环形链表 II] 快慢指针
    static ListNode* getKthFromEnd(ListNode* head, int k);  // [剑指 Offer 22.链表中倒数第k个节点] 链表操作
    static TreeNode* balanceBST(TreeNode* root);    // [1382.将二叉搜索树变平衡] 深度优先搜索
    static TreeNode* sortedArrayToBST(vector<int>& nums);   // [108.将有序数组转换为二叉搜索树] 深度优先搜索
    static vector<int> dailyTemperatures(vector<int>& temperatures);  // [739.每日温度] 单调栈
    static int longestConsecutive(vector<int>& nums);       // [128.最长连续序列] 哈希查找
    static int firstMissingPositive(vector<int>& nums);     // [41.缺失的第一个正数] 哈希 位运算
    static int compareVersion(string version1, string version2);       // [165.比较版本号] 字符串操作
private:
    static void quickSort(int* arr, int left, int right);           // 递增快排
    static void quickSort(vector<int>& arr, int left, int right);    // 递增快排
    static void quickSortReverse(int* arr, int left, int right);    // 递减快排
    static void quickSortReverse(vector<int>& arr, int left, int right);     // 递减快排
    static bool existCore(vector<vector<char>>& board, int i, int j, string word, int k, bool **visited);   // 79 helper
    static void solveCore(vector<vector<char>>& board, int i, int j, bool **isAround);      // 130 helper
    static void count0And1(string& str, int* result);      // 474 helper
    static ListNode* mergeKLists(vector<ListNode*>& lists, int beg, int end);       // 23 helper
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);       // 23 helper
    static void eraseOverlapIntervalsQuickSort(vector<vector<int>>& intervals, int left, int right);// 435 helper
    static void findMinArrowShotsQuickSort(vector<vector<int>>& points, int left, int right);    // 452 helper
    static void reverseKGroupHelper(ListNode* head, ListNode* tail);      // 25 helper
    static ListNode* reverseList2Helper(ListNode* node, ListNode* prev);      // 206 helper
    static bool isBalancedHelper(TreeNode* root, int &depth);    // 110 helper
    static void balanceBSTHelper(TreeNode* root, vector<TreeNode*>& inorderVec);   // 1382 helper 获取 BST 中序遍历的结果
    static TreeNode* balanceBSTHelper(vector<TreeNode*>& inorderVec, int leftPos, int rightPos);      // 1382 helper 递归构造平衡二叉树
    static TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int leftPos, int rightPos);    // 108 helper
};


#endif //LEETCODE_SOLUTION_H