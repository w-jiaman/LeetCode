#include <iostream>
#include "vector"
#include "Solution.h"

using namespace std;

int main() {
    vector<vector<int>> it = {
            {1,2},
            {2,3},
            {3,4},
            {-100,-2},
            {5,7}
    };

    cout << Solution::eraseOverlapIntervals(it) << endl;
}
