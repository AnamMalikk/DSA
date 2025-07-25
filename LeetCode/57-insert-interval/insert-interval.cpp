class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        //Optimal 
        //TC = O(N)  SC = O(N)

        int i = 0;
        int n = intervals.size();
        vector<vector<int>> ans;

        while(i < n && intervals[i][1] < newInterval[0]){ //no overlapping on left side
            ans.emplace_back(intervals[i]);
            i++;
        }
        //MIGHT overlap if this (intervals[i][1] < newInterval[0]) becomes false
        //if the below condition also becomes false it means no overlapping and we'll just insert the new interval

        while(i < n && intervals[i][0] <= newInterval[1]){ //overlap
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        while(i<n){ //no overlapping on the right side
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};