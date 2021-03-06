/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void DFS(TreeNode* t1, TreeNode* t2)
    {
        t1->val += t2->val; 
        
        if(t1->left != NULL && t2->left!=NULL)
        {
            DFS(t1->left, t2->left);
        }
        else if(t1->left == NULL && t2->left!= NULL)
        {
            t1->left = t2->left;
        }
        
         if(t1->right != NULL && t2->right!=NULL)
        {
            DFS(t1->right, t2->right);
        }
        else if(t1->right == NULL && t2->right!=NULL)
        {
            t1->right = t2->right;
        }       
        
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
     
        if( t1 == NULL && t2 == NULL) return NULL;
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;
        DFS(t1, t2);
        return t1;
    }
};