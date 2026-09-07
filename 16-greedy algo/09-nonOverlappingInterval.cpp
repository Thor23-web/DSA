// remove the minimum intervals so the array have only non-overlapping intervals
// Overlapping is the intersection have in two interval,, ones end and other start is same
// is not consider as a overlapping in this problem

// The ans is return mini number of interval removes

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapping(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; }
            );

        int cnt = 1, lastEndTime = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= lastEndTime){
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }
        return intervals.size() - cnt;

        // TC-> O(n logn) + O(n)
        // SC-> O(1);
    }
};

int main()
{
     Solution sol;

    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {3, 5}, {1, 2}};

    cout << "Minimum number of intervals to remove: " << sol.eraseOverlapping(intervals) << endl;
    return 0;
}