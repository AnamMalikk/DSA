/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // Simple DFS.
 // TC=O(N)
 // SC=O(H)
class Solution {
public:
    int maxSum;

    int solve(TreeNode*root){
        if(root==NULL)
        return 0;

        int leftAns=solve(root->left);
        int rightAns=solve(root->right);
        
        // you cannot return this below value--> it will not be a valid path.
        // because ya path neeche hi converge ho gya ha including its root i.e  uss path ka ans pahla hi nikal chuka ha.
        int neeche_sa_hi_ans_aagya=leftAns+rightAns+root->val;  // (1)
        
        // root sa uper bhi nodes include ho skta ha.
        int koi_ek_achha=max(rightAns,leftAns)+root->val;          // (2)

        int sirf_root_achha=root->val;                 // (3)

        maxSum=max({maxSum,neeche_sa_hi_ans_aagya,koi_ek_achha,sirf_root_achha});

        // most important part.--> you cannot return (1) because then the path will be invalid.
        return max(koi_ek_achha,sirf_root_achha);
    }
    int maxPathSum(TreeNode* root) 
    {
         maxSum=INT_MIN;
         solve(root);
         return maxSum;
    }
};