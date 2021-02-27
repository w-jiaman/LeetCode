#include <iostream>
#include "vector"
#include "Solution.h"

using namespace std;

int main() {
    vector<vector<int>> it = {
            {1,2},
            {2,3},
            {3,4},
            {4,5}
    };
    cout << Solution::findMinArrowShots(it) << endl;
}
