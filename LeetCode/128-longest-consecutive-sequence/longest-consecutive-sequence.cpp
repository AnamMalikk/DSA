class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> exists, used;
        for (int i : nums) exists[i] = 1; 
        int current = 1, ans = 0, j;

        for (int i : nums) {
            current = 1;
            if (used[i] == 0) {
                j = i-1;
                while (exists[j] == 1) {
                    current++;
                    used[j] = 1;
                    j--;
                }
                j = i+1;
                while (exists[j] == 1) {
                    current++;
                    used[j] = 1;
                    j++;
                }
            }

            used[i] = 1;
            ans = max(current, ans);
        }

        return ans;
    }
};