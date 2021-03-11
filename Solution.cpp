//
// Created by User on 2021/1/25.
//

#include "Solution.h"

#include "iostream"
#include "string"
#include "vector"
#include "map"
#include "queue"
#include "algorithm"

using namespace std;


/*
 * 递增快排
 * */
void Solution::quickSort(int *arr, int left, int right) {
    int recordLeft = left, recordRight = right;
    int pivot = arr[left];

    while(left<right){
        while(arr[right]>=pivot && left<right){
            right--;
        }
        if(left<right){
            arr[left] = arr[right];
            left++;
        }
        while(arr[left]<=pivot && left<right){
            left++;
        }
        if(left<right){
            arr[right] = arr[left];
            right--;
        }
    }

    arr[left] = pivot;

    if(recordLeft<left-1){
        quickSort(arr, recordLeft, left-1);
    }
    if(recordRight>right+1){
        quickSort(arr, right+1, recordRight);
    }
}
void Solution::quickSort(vector<int>& arr, int left, int right) {
    int recordLeft = left, recordRight = right;
    int pivot = arr[left];

    while(left<right){
        while(arr[right]>=pivot && left<right){
            right--;
        }
        if(left<right){
            arr[left] = arr[right];
            left++;
        }
        while(arr[left]<=pivot && left<right){
            left++;
        }
        if(left<right){
            arr[right] = arr[left];
            right--;
        }
    }

    arr[left] = pivot;

    if(recordLeft<left-1){
        quickSort(arr, recordLeft, left-1);
    }
    if(recordRight>right+1){
        quickSort(arr, right+1, recordRight);
    }
}


/*
 * 递减快排
 * */
void Solution::quickSortReverse(int* arr, int left, int right) {
    int recordLeft = left, recordRight = right;
    int pivot = arr[left];

    while(left<right){
        while(arr[right]<=pivot && left<right){
            right--;
        }
        if(left<right){
            arr[left] = arr[right];
            left++;
        }
        while(arr[left]>=pivot && left<right){
            left++;
        }
        if(left<right){
            arr[right] = arr[left];
            right--;
        }
    }

    arr[left] = pivot;

    if(recordLeft<left-1){
        quickSortReverse(arr, recordLeft, left-1);
    }
    if(recordRight>right+1){
        quickSortReverse(arr, right+1, recordRight);
    }
}
void Solution::quickSortReverse(vector<int>& arr, int left, int right) {
    int recordLeft = left, recordRight = right;
    int pivot = arr[left];

    while(left<right){
        while(arr[right]<=pivot && left<right){
            right--;
        }
        if(left<right){
            arr[left] = arr[right];
            left++;
        }
        while(arr[left]>=pivot && left<right){
            left++;
        }
        if(left<right){
            arr[right] = arr[left];
            right--;
        }
    }

    arr[left] = pivot;

    if(recordLeft<left-1){
        quickSortReverse(arr, recordLeft, left-1);
    }
    if(recordRight>right+1){
        quickSortReverse(arr, right+1, recordRight);
    }
}


/*
 * [1.两数之和] 暴力法
 * */
vector<int> Solution::twoSum(vector<int> &nums, int target) {
    vector<int> answer ;
    for(int i=0;i<nums.size();i++){
        int num = target - nums[i];
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]==num){
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
    return answer;
}

/*
 * [27.移除元素] 数组操作
 * */
int Solution::removeElement(vector<int> &nums, int val) {
    int pivot = nums.size() - 1;
    for (int i = 0; i <=pivot; i++) {
        if(nums[i]==val){
            while(pivot>=i&&nums[pivot]==val){
                pivot--;
            }
            if(pivot<i){
                break;
            }
            nums[i] = nums[pivot--];
        }
    }
    return pivot+1;
}

/*
 * [16.最接近的三数之和] 双指针
 * */
int Solution::threeSumClosest(vector<int> &nums, int target) {
    int len = nums.size();

    quickSort(nums,0,len-1);
    int result = nums[0] + nums[1] + nums[2];

    for(int i=0;i<len-2;i++){
        int start = i+1;
        int end = len-1;
        while(start<end){
            int sum = nums[i] + nums[start] + nums[end];
            if(abs(target-sum)<abs(target-result)){
                result = sum;
            }
            if(sum>target){
                end--;
            } else if(sum<target){
                start++;
            } else{
                return result;
            }
        }
    }

    return result;
}

/*
 * [15.三数之和] 双指针
 * */
vector<vector<int>> Solution::threeSum(vector<int> &nums) {
    int len = nums.size();
    vector<vector<int>> result = vector<vector<int>>();

    if(len<3){
        return result;
    }

    quickSort(nums,0,len-1);

    for(int i=0;i<len-2;i++){
        if(i>0&&nums[i-1]==nums[i]){
            continue;
        }

        int start = i+1;
        int end = len-1;

        while(start<end){
            int sum = nums[i] + nums[start] + nums[end];
            if(sum==0){
                vector<int> vec = {nums[i],nums[start],nums[end]};
                result.push_back(vec);
                start++;
                end--;
                while(start<end&&nums[start]==nums[start-1]){
                    start++;
                }
                while(start<end&&nums[end]==nums[end+1]){
                    end--;
                }
            }else if(sum<0){
                start++;
            }else{
                end--;
            }
        }
    }
    return result;
}

/*
 * [17.电话号码的字母组合] 回溯算法
 * */
vector<string> Solution::letterCombinations(string digits) {
    // 使用string数组来表示数字与字母间的对应关系
    // 通过 下标+2 来访问某个数字对应的所有字符
    string data[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    // 获取输入的所有数字
    vector<int> input = vector<int>();
    for(char c:digits){
        int number = c-48;
        input.push_back(number);
    }

    // 声明一个长度为2的 vector<string> 数组，来缓存前一次计算的结果
    vector<string> cache[2];

    // 定义两个指针，来指示缓存中当前操作的向量
    int current = 0;
    int prevent = 1;
    // 动态规划
    for(int i=0;i<input.size();i++){
        cache[current].clear();

        // 对于输入的第i个数字
        vector<string> vec = vector<string>();
        if(i==0){
            // 若为递归边界
            for(char c:data[input[i]-2]){
                cache[current].push_back(string("")+c);
            }
        }else{
            for(const string& s:cache[prevent]){
                for(char c:data[input[i]-2]){
                    cache[current].push_back(s+c);
                }
            }
        }
        current = current + prevent;
        prevent = current - prevent;
        current = current - prevent;
    }
    return cache[prevent];
}

/*
 * [6.Z字形变换] 几何
 * */
string Solution::convert(string s, int numRows) {
    if(numRows==1){
        return  s;
    }

    vector<string> rows = vector<string>(min((int)s.size(),numRows));
    bool isGoingDown = false;

    int currentRow = 0;
    for(char c:s){
        rows[currentRow] += c;
        if(currentRow==0 || currentRow == numRows-1){
            isGoingDown = !isGoingDown;
        }
        currentRow += isGoingDown?1:-1;
    }

    string result;
    for(const string& str:rows){
        result += str;
    }

    return result;
}

/*
 * [11.盛最多水的容器] 双指针
 * */
int Solution::maxArea(vector<int> &height) {
    int start = 0;
    int end = height.size()-1;
    int maxVolume = 0;
    while (start<end){
        if(height[start]<height[end]){
            maxVolume = maxVolume>height[start]*(end-start)?maxVolume:height[start]*(end-start);
            start++;
        }else{
            maxVolume = maxVolume>height[end]*(end-start)?maxVolume:height[end]*(end-start);
            end--;
        }
    }
    return maxVolume;
}

/*
 * [167.两数之和II-输入有序数组]
 * */
vector<int> Solution::twoSum2(vector<int>& numbers, int target) {
    int start = 0;
    int end = (int)numbers.size()-1;
    while (start<end){
        int sum = numbers[start] + numbers[end];
        if(sum==target){
            break;
        }else if(sum>target){
            end--;
        }else if(sum<target){
            start++;
        }
    }
    return vector<int>(2)={start+1,end+1};
}

/*
 * [104.二叉树的最大深度] 深度优先搜索
 * */
int Solution::maxDepth(TreeNode *root) {
    if(root== nullptr){
        return 0;
    }
    return max(maxDepth(root->left),maxDepth(root->right))+1;
}

/*
 * [867.转置矩阵] 数组操作
 * */
vector<vector<int>> Solution::transpose(vector<vector<int>> &A) {
    vector<vector<int>> result = vector<vector<int>>();

    for(std::size_t i=0; i<A[0].size(); i++){
        vector<int> vec = vector<int>();
        for(std::size_t j=0; j<A.size(); j++){
            vec.push_back(A[j][i]);
        }
        result.push_back(vec);
    }

    return result;
}

/*
 * 面试题 17.10 数组操作
 * */
int Solution::majorityElement(vector<int> &nums) {
    if(nums.size()==1){
        return nums[0];
    }

    map<int,int> Map = map<int,int>();

    for(int i=0; i<nums.size(); i++){
        auto iterator = Map.find(nums[i]);
        if(iterator != Map.end()){
            int times = iterator->second + 1;
            if(times>(int)nums.size()/2){
                return nums[i];
            }
            Map[nums[i]] = times;
        }else{
            Map[nums[i]] = 1;
        }
    }

    return -1;
}

/*
 * 面试题 17.21 双指针
 * */
int Solution::trap(vector<int> &height) {
    if(height.size()<=2){
        return 0;
    }

    int left=0, right=(int)height.size()-1;
    int leftMax=height[left],rightMax=height[right];
    int result=0;

    while(left<right){
        if(leftMax<rightMax){
            result += (leftMax-height[left++]);
            leftMax = max(leftMax,height[left]);
        }else{
            result += (rightMax-height[right--]);
            rightMax = max(rightMax,height[right]);
        }
    }

    return result;
}

/*
 * [1535.找出数组游戏的赢家] 数组操作
 * */
int Solution::getWinner(vector<int>& arr, int k){
    int ptr=1,times=0;

    while(ptr<arr.size()){
        if(arr[0]>arr[ptr]){
            times++;
            ptr++;
        }else{
            int tmp = arr[0];
            arr[0] = arr[ptr];
            arr[ptr] = tmp;
            ptr++;
            times = 1;
        }
        if(times==k){
            break;
        }
    }

    return arr[0];
}

/*
 * [977.有序数组的平方] 排序
 * */
vector<int> Solution::sortedSquares(vector<int> &nums) {
    vector<int> result = vector<int>(nums.size());
    int* cache = new int[nums.size()];
    int a=0,b=(int)nums.size()-1;

    for(int i=0; i<nums.size(); i++){
        cache[i] = nums[i]*nums[i];
    }

    for(int i=(int)nums.size()-1; i>=0; i--){
        if(cache[b]>cache[a]){
            result[i] = cache[b];
            b--;
        }else{
            result[i] = cache[a];
            a++;
        }
    }

    return result;
}

/*
 * [79.单词搜索] 深度优先搜索
 * */
bool Solution::exist(vector<vector<char>> &board, string word) {
    bool flag = false;

    bool **visited = new bool*[board.size()];
    for(int i=0; i<board.size(); i++){
        visited[i] = new bool[board[0].size()];
        for(int j=0; j<board[0].size(); j++){
            visited[i][j] = false;
        }
    }

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j]==word[0]){
                visited[i][j] = true;
                flag = existCore(board, i, j, word, 1, visited);
            }
            if(flag){
                break;
            }else{
                visited[i][j] = false;
            }
        }
        if(flag){
            break;
        }
    }

    return flag;
}

/*
 * 79 helper
 * */
bool Solution::existCore(vector<vector<char>> &board, int i, int j, string word, int k, bool **visited) {       // 递归调用核心，将问题分解成更小规模
    // 递归边界
    if(k>=word.size()){
        return true;
    }

    // 上
    if(i>0 && !visited[i-1][j] && board[i - 1][j] == word[k]){
        visited[i-1][j] = true;
        if(existCore(board, i-1, j, word, k+1, visited)){
            return true;
        }else{
            visited[i-1][j] = false;
        }
    }

    // 下
    if(i<board.size()-1 && !visited[i+1][j] && board[i + 1][j] == word[k]){
        visited[i+1][j] = true;
        if(existCore(board, i+1, j, word, k+1, visited)){
            return true;
        }else{
            visited[i+1][j] = false;
        }

    }

    // 左
    if(j>0 && !visited[i][j-1] && board[i][j - 1] == word[k]){
        visited[i][j-1] = true;
        if(existCore(board, i, j-1, word, k+1, visited)){
            return true;
        }else{
            visited[i][j-1] = false;
        }

    }

    // 右
    if(j<board[0].size()-1 && !visited[i][j+1] && board[i][j+1]==word[k]){
        visited[i][j+1] = true;
        if(existCore(board, i, j+1, word, k+1, visited)){
            return true;
        }else{
            visited[i][j+1] = false;
        }
    }

    return false;
}

/*
 * [130.被围绕的区域] 深度优先搜索
 * */
void Solution::solve(vector<vector<char>> &board) {
    if(board.empty()||board.size()==1){
        return;
    }

    bool **isAround = new bool*[board.size()];
    for(int i=0; i<board.size(); i++){
        isAround[i] = new bool[board[0].size()];
        for(int j=0; j<board[0].size(); j++){
            isAround[i][j] = true;
        }
    }

    for(int i=0; i<board[0].size(); i++){      // 遍历第一行与最后一行
        if(board[0][i]=='O'&&isAround[0][i]){
            solveCore(board, 0, i, isAround);
        }
        if(board[board.size()-1][i]=='O'&&isAround[board.size()-1][i]){
            solveCore(board, board.size()-1, i, isAround);
        }
    }

    for(int i=1; i<board.size()-1; i++){      // 遍历第一列与最后一列
        if(board[i][0]=='O'&&isAround[i][0]){
            solveCore(board, i, 0, isAround);
        }
        if(board[i][board[0].size()-1]=='O'&&isAround[i][board[0].size()-1]){
            solveCore(board, i, board[0].size()-1, isAround);
        }
    }

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            cout << isAround[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=1; i<board.size()-1; i++){
        for(int j=1; j<board[0].size()-1; j++){
            if(board[i][j]=='O'&&isAround[i][j]){
                board[i][j] = 'X';
            }
        }
    }

}

/*
 * 130 helper
 * */
void Solution::solveCore(vector<vector<char>> &board, int i, int j, bool** isAround) {

    isAround[i][j] = false;

    if(i>0 && board[i-1][j]=='O' && isAround[i-1][j]){
        solveCore(board, i-1, j, isAround);
    }

    if(i<board.size()-1 && board[i+1][j]=='O' && isAround[i+1][j]){
        solveCore(board, i+1, j, isAround);
    }

    if(j>0 && board[i][j-1]=='O' && isAround[i][j-1]){
        solveCore(board, i, j-1, isAround);
    }

    if(j<board[0].size()-1 && board[i][j+1]=='O' && isAround[i][j+1]) {
        solveCore(board, i, j+1, isAround);
    }

}

/*
 * [442.数组中重复的数据] 哈希算法
 * */
vector<int> Solution::findDuplicates(vector<int> &nums) {
    vector<int> ret = vector<int>();
    for(int i=0; i<nums.size(); i++){
        if(nums[abs(nums[i])-1]<0){
            ret.push_back(abs(nums[i]));
        }else{
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
    }
    return ret;
}

/*
 * [747.至少是其他数字两倍的最大数] 暴力法
 * */
int Solution::dominantIndex(vector<int> &nums) {
    int locOfMaxValue = 0;

    for(int i=1; i<nums.size(); i++){
        if(nums[i]>nums[locOfMaxValue]){
            locOfMaxValue = i;
        }
    }

    for(int i=0; i<nums.size(); i++){
        if(i!=locOfMaxValue){
            if(nums[locOfMaxValue]<2*nums[i]){
                return -1;
            }
        }
    }

    return locOfMaxValue;
}

/*
 * [1493.删掉一个元素以后全为 1 的最长子数组] 递推算法
 * */
int Solution::longestSubarray(vector<int> &nums) {
    int a=0,b=0,max=0;

    for(int num : nums){
        if(num==1){
            a++;
            b++;
            if(a>max){
                max = a;
            }
        }else{
            a=b;
            b=0;
        }
    }

    if(max==nums.size()){
        max--;
    }

    return max;
}

/*
 * [424.替换后的最长重复字符] 滑动窗口
 * */
int Solution::characterReplacement(string s, int k) {
    int *count = new int[26];
    for(int i=0; i<26; i++){
        count[i] = 0;
    }

    int left,right,maxCount;
    left = 0;
    maxCount = 0;
    for(right=0; right<s.size(); right++){
        int index = s[right]-'A';
        count[index]++;

        if(count[index]>maxCount){
            maxCount = count[index];
        }

        if(right-left+1>maxCount+k){        // 窗口右滑条件
            count[s[left]-'A']--;
            left++;
        }
    }

    return k+maxCount>s.size()?(int)s.size():k+maxCount;
}

/*
 * [832.翻转图像] 数组操作
 * */
vector<vector<int>> Solution::flipAndInvertImage(vector<vector<int>> &A) {
    vector<vector<int>> result = vector<vector<int>>();

    for(int i=0; i<A.size(); i++){
        vector<int> vec = vector<int>(A[0].size());
        for(int j=0; j<(A[0].size()+1)/2; j++){
            vec[j] = 1 - A[i][A[0].size()-1-j];
            vec[A[0].size()-1-j] = 1 - A[i][j];
        }
        result.push_back(vec);
    }

    return result;
}

/*
 * 剑指 offer 59 - I 滑动窗口
 * */
vector<int> Solution::maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result = vector<int>();

    if(nums.empty()||!k){
        return result;
    }
    if(k==1){
        return nums;
    }

    int max = nums[0];
    for(int i=1; i<k; i++){
        if(nums[i]>max){
            max = nums[i];
        }
    }
    result.push_back(max);

    for(int i=0; i<nums.size()-k; i++){
        if(nums[k+i]>max){
            max = nums[k+i];
        }else if(max==nums[i]){
            int maxPart = nums[i+1];
            for(int j=i+2; j<=k+i; j++){
                if(nums[j]>maxPart){
                    maxPart = nums[j];
                }
            }
            max = maxPart;
        }
        result.push_back(max);
    }

    return result;
}

/*
 * [1458.两个子序列的最大点积] 动态规划
 * */
int Solution::maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size(),size2 = nums2.size();
    int **cache = new int*[size1+1];
    for(int i=0; i<=size1; i++){
        cache[i] = new int[size2+1];

        for(int j=0; j<=size2; j++){
            cache[i][j] = -1e8;
        }
    }

    for(int i=1; i<=size1; i++){
        for(int j=1; j<=size2; j++){
            cache[i][j] = nums1[i-1]*nums2[j-1];

            cache[i][j] = max(cache[i][j],cache[i-1][j-1]+nums1[i-1]*nums2[j-1]);

            cache[i][j] = max(cache[i][j],cache[i][j-1]);

            cache[i][j] = max(cache[i][j],cache[i-1][j]);

            cache[i][j] = max(cache[i][j],cache[i-1][j-1]);
        }
    }

    return cache[size1][size2];
}

/*
 * [279.完全平方数] 动态规划
 * */
int Solution::numSquares(int n) {
    int *dp = new int[n+1]();

    for(int i=1; i<=n; i++){
        dp[i] = i;

        for(int j=1; i-j*j>=0; j++){
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }

    return dp[n];
}

/*
 * [1423.可获得的最大点数] 数组操作
 * */
int Solution::maxScore(vector<int> &cardPoints, int k) {
    int maxScore=0;

    for(int i=0; i<k; i++){
        maxScore += cardPoints[i];
    }

    if(cardPoints.size()==k){
        return maxScore;
    }

    int cacheScore = maxScore;
    for(int i=1; i<=k; i++){
        int tempScore = cacheScore - cardPoints[k-i] + cardPoints[cardPoints.size()-i];
        maxScore = tempScore>maxScore?tempScore:maxScore;
        cacheScore = tempScore;
    }

    return maxScore;
}



/*
 * [474.一和零] 动态规划
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
 * [300.最长递增子序列] 动态规划
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
 * [978.最长湍流子数组] 滑动窗口
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
 * [940.不同的子序列 II] 动态规划
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
 * [2.两数相加] 链表
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
 * [23.合并K个升序链表] 链表
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
 * [1578.避免重复字母的最小删除成本] 贪心算法
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
 * [1663.具有给定数值的最小字符串] 贪心算法
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

/*
 * [1338.数组大小减半] 贪心算法
 * */
int Solution::minSetSize(vector<int> &arr) {
    map<int,int> freq;
    for(int num:arr){
        freq[num]++;
    }
    vector<int> orderFreq;
    orderFreq.reserve(freq.size());
    for(auto & it : freq){
        orderFreq.push_back(it.second);
    }

    sort(orderFreq.begin(), orderFreq.end(), greater<int>());

    int count=0, answer=0;
    for(int cnt:orderFreq){
        count+=cnt;
        answer+=1;
        if (count * 2 >= arr.size()) {
            break;
        }
    }
    return answer;
}

/*
 * [1403.非递增顺序的最小子序列] 贪心算法
 * */
vector<int> Solution::minSubsequence(vector<int> &nums) {
    int sum=0, sonSum=0, ptr=0;
    vector<int> result;

    for(int num:nums){
        sum+=num;
    }

    quickSortReverse(nums, 0, nums.size()-1);

    sonSum = 0;
    while(sonSum<=sum){
        sonSum += nums[ptr];
        sum -= nums[ptr];
        result.push_back(nums[ptr]);
        ptr++;
    }

    return result;
}

/*
 * [435.无重叠区间] 贪心算法
 * */
int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals){
    if(intervals.size()<=1){
        return 0;
    }

    eraseOverlapIntervalsQuickSort(intervals, 0, intervals.size()-1);

    int right=INT_MIN;
    int result=0;
    for(auto & interval : intervals){
        if(interval[0]<right){
            result++;
        }else{
            right=interval[1];
        }
    }

    return result;
}

/*
 * 435 helper
 * */
void Solution::eraseOverlapIntervalsQuickSort(vector<vector<int>> &intervals, int left, int right) {
    vector<int> pivot = intervals[left];
    int leftRecord = left;
    int rightRecord = right;

    while(left<right){
        while(intervals[right][1]>pivot[1] && left<right){
            right--;
        }
        if(left<right){
            intervals[left] = intervals[right];
            left++;
        }

        while(intervals[left][1]<pivot[1] && left<right){
            left++;
        }
        if(left<right){
            intervals[right] = intervals[left];
            right--;
        }
    }

    intervals[left] = pivot;

    if(left>leftRecord+1){
        eraseOverlapIntervalsQuickSort(intervals, leftRecord, left-1);
    }
    if(right<rightRecord-1){
        eraseOverlapIntervalsQuickSort(intervals, right+1, rightRecord);
    }
}

/*
 * [452.用最少数量的箭引爆气球] 贪心算法
 * */
int Solution::findMinArrowShots(vector<vector<int>> &points) {
    if (points.size() <= 1) {
        return points.size();
    }

    findMinArrowShotsQuickSort(points, 0, points.size() - 1);

    int i=0;
    int result = 0;
    while(i<points.size()){
        result++;

        int j=i+1;
        while(j<points.size()&&points[j][0]<=points[i][1]){
            j++;
        }


        i = j;
    }

    return result;
}

/*
 * 452 helper
 * */
void Solution::findMinArrowShotsQuickSort(vector<vector<int>> &points, int left, int right) {
    vector<int> pivot = points[left];
    int leftRecord = left, rightRecord = right;

    while(left<right){
        while(points[right][1]>pivot[1] && left<right){
            right--;
        }
        if(left<right){
            points[left] = points[right];
            left++;
        }

        while(points[left][1]<pivot[1] && left<right){
            left++;
        }
        if(left<right){
            points[right] = points[left];
            right--;
        }
    }

    points[left] = pivot;

    if(left>leftRecord+1){
        findMinArrowShotsQuickSort(points, leftRecord, left-1);
    }
    if(right+1<rightRecord){
        findMinArrowShotsQuickSort(points, right+1, rightRecord);
    }
}

/*
 * [376.摆动序列] 动态规划
 * */
int Solution::wiggleMaxLength(vector<int> &nums) {
    if(nums.size()<=1){
        return nums.size();
    }

    int* up = new int[nums.size()];
    int *down = new int[nums.size()];

    up[0] = 1;
    down[0] = 1;

    for(int i=1; i<nums.size(); i++){
        if (nums[i]>nums[i-1]){
            if(down[i-1]+1>up[i-1]){
                up[i] = down[i-1] + 1;
            }else{
                up[i] = up[i-1];
            }
            down[i] = down[i-1];
        }else if(nums[i]<nums[i-1]){
            if(up[i-1]+1>down[i-1]){
                down[i] = up[i-1] + 1;
            }else{
                down[i] = down[i-1];
            }
            up[i] = up[i-1];
        }else{
            up[i] = up[i-1];
            down[i] = down[i-1];
        }
    }

    int result;
    if(down[nums.size()-1]>up[nums.size()-1]){
        result = down[nums.size()-1];
    }else{
        result = up[nums.size()-1];
    }

    delete []up;
    delete []down;

    return result;
}

int Solution::wiggleMaxLength2(vector<int> &nums) {
    if(nums.size()<=1)
        return nums.size();

    int up = 1;
    int down = 1;

    for(int i=1; i<nums.size(); i++){
        if (nums[i]>nums[i-1]){
            if(down+1>up){
                up = down + 1;
            }
        }else if(nums[i]<nums[i-1]){
            if(up+1>down){
                down = up + 1;
            }
        }
    }

    if(up>down){
        return up;
    }else{
        return down;
    }
}

/*
 * [376.摆动序列] 贪心算法
 * */
int Solution::wiggleMaxLength3(vector<int> &nums) {
    if(nums.size()<=1)
        return nums.size();

    bool isUp = false;
    int beginLoc = 1;
    while(beginLoc<nums.size() && nums[0]==nums[beginLoc]){
        beginLoc++;
    }

    if(beginLoc<nums.size() && nums[beginLoc]>nums[0]){
        isUp = true;
    }

    int result = 1;
    if(beginLoc<nums.size()){
        result=2;
    }

    for(int i=beginLoc; i<nums.size(); i++){
        if(nums[i]<nums[i-1]){
            if(isUp){
                result++;
                isUp = false;
            }
        }else if(nums[i]>nums[i-1]){
            if(!isUp){
                result++;
                isUp = true;
            }
        }
    }

    return result;
}

/*
 * [25.K 个一组翻转链表] 链表
 * */
ListNode *Solution::reverseKGroup(ListNode *head, int k) {
    int count = 0;
    ListNode newHead;
    newHead.next = head;
    ListNode *prev=&newHead, *current=head;
    while(current->next){
        current=current->next;
        count++;
        if(count==k){
            ListNode* next = current->next, *prevTmp=prev->next;
            reverseKGroupHelper(prev->next, current);
            prev->next->next = next;
            prev->next = current;
            current = next;
            prev = prevTmp;
            count=0;
        }
    }

    return nullptr;
}

/*
 * 25 helper
 * */
void Solution::reverseKGroupHelper(ListNode *head, ListNode *tail) {
    // 能调用这个函数的都是 k!=1 的情况，所以 head 与 tail 不会指向同一个节点
    ListNode* current=head->next, *prev=head, *next;
    while(current!=tail->next){
        next = current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
}

/*
 * [121.买卖股票的最佳时机] 遍历
 * */
int Solution::maxProfit(vector<int> &prices) {
    int min=prices[0], result=0;
    for(int i=1; i<prices.size(); i++){
        if(prices[i]<min){
            min = prices[i];
        }else{
            if(prices[i]-min > result){
                result = prices[i] - min;
            }
        }
    }

    return result;
}

/*
 * [102.二叉树的层序遍历] 广度优先搜索
 * */
vector<vector<int>> Solution::levelOrder(TreeNode *root) {
    vector<vector<int>> result;

    if(!root)
        return result;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        vector<int> currentLevel;
        int currentSize = q.size();
        for(int i=0; i<currentSize; i++){
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        result.push_back(currentLevel);
    }

    return result;
}

/*
 * [103.二叉树的锯齿形层序遍历] 广度优先搜索
 * */
vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> result;

    if(!root)
        return result;

    bool flag=0;        // flag 为 0 时正序输出

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        deque<int> currentLevel;
        int currentSize = q.size();
        for(int i=0; i<currentSize; i++){
            TreeNode* node = q.front();
            q.pop();

            if(flag){
                currentLevel.push_front(node->val);
            }else{
                currentLevel.push_back(node->val);
            }

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        result.emplace_back(vector<int>{currentLevel.begin(), currentLevel.end()});
        flag = !flag;
    }

    return result;
}