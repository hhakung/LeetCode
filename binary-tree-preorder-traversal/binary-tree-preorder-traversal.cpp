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
public:
    // recursive solution
    void preOrder( TreeNode* node, std::vector<int>& traversal )
    {
        // put in the current node
        traversal.push_back( node->val );
        
        // go to the left
        auto leftNode { node->left };
        if( leftNode != nullptr )
        {
            preOrder( leftNode, traversal );
        }
        
        // go to the right
        auto rightNode { node->right };
        if( rightNode != nullptr )
        {
            preOrder( rightNode, traversal );
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> traversal {};
        
        if( root == nullptr )
        {
            return traversal;
        }
        
        preOrder( root, traversal );
        
        return traversal;
    }
};