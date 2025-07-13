class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mp = 0, sum = 0;
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++){
            mp = nums[i] - target;
            int k = i+1, h = nums.size()-1;
            while(k < h){
                if(k == i) ++k;
                else if(h == i) --h;
                else {
                    sum = nums[h] + nums[k] + mp;
                    res = abs(res) > abs(sum) ? sum : res;
                    if(sum < 0) ++k;
                    else --h;
                }
            }
        }
        return res + target;
    }
};