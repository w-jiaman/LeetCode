#include <iostream>
#include "vector"
#include "Solution.h"

using namespace std;

int main() {
    vector<vector<int>> interator = {
            {0,3},
            {1,4},
            {5,3},
            {7,9},
            {4,2},
            {3,1},
            {5,8}
    };

    Solution::eraseOverlapIntervals(interator);
}
