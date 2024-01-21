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
class Solution {
private:
    int maxDepthsum(TreeNode* root , int &sum) {
        if(root == NULL){
            return 0 ;
        }
        int left = maxDepthsum(root->left,sum) ;
        int right = maxDepthsum(root->right,sum);

        if(left >= 0 && right >= 0){
            sum = max(sum,left + right + root->val ) ;
        }
        else if(left < 0 && right < 0){
            sum = max(sum, root->val );
            return root->val ;
        }
        else if(left < 0){
            sum = max(sum , right + root->val);
        }
        else if(right < 0){
            sum = max(sum , left + root->val );
        }


        return max(left,right) + root->val ; 

    }
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN ;
        int heightsum = maxDepthsum(root, sum) ;
        return sum ;
    }
};