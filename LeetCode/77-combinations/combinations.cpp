class Solution {
public:
    void Combo(int ind, vector<int>&ds,vector<vector<int>>&vec,int n, int k){
        if(ds.size()==k){
            vec.push_back(ds);
            return;
        }
        for(int i = ind;i<=n;i++){
            if(i == n) break;
            ds.push_back(i+1);
            Combo(i+1,ds,vec,n,k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>vec;
        vector<int>ds;
        Combo(0,ds,vec,n,k);
        return vec;
    }
};