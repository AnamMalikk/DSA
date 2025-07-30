class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums, int i = 0) {
        if(i >= nums.size()){
            return {{}};
        }
        auto temp = subsets(nums,i+1);
        vector<vector<int>> ans = temp;
        for(auto& v : temp){
            v.push_back(nums[i]);
            ans.push_back(v);
        }
        return ans;
    }
};