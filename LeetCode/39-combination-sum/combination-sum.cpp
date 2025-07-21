class Solution {
private:
void func(vector<int>& cand, int i,int n , int sum, vector<int>& curr, vector<vector<int>>& ans) 
{
    if(sum==0)
    {
        ans.push_back(curr);
        return;
    }

    if(sum<0 || i== n)
    return;
   
    curr.push_back(cand[i]);
    func(cand ,i , n , sum - cand[i], curr ,ans );


     curr.pop_back();
     func(cand, i+1 , n ,sum, curr ,ans );
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> v;
        int n = candidates.size();

        func(candidates,0 , n, target, v, ans);

        return ans;

        
    }
};