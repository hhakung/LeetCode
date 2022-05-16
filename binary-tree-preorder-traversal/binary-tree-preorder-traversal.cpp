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
    // Option 1: Iterative solution
    bool allChildrenHaveBeenVisited( TreeNode* node, std::set<TreeNode*> const& visited )
    {
        auto const leftHasBeenVisited { (node->left == nullptr) || 
                                        (visited.find( node->left ) != visited.end()) };
        
        auto const rightHasBeenVisited { (node->right == nullptr) || 
                                         (visited.find( node->right ) != visited.end()) };
        
        return leftHasBeenVisited && rightHasBeenVisited;
    }
    
    bool isLeaf( TreeNode* node )
    {
        if( (node->left == nullptr) && (node->right == nullptr) )
        {
            return true;
        }
        
        return false;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int>      traversal      {};
        std::set<TreeNode*>   visited        {};
        std::stack<TreeNode*> traversalStack {};
        
        if( root == nullptr )
        {
            return traversal;
        }
        
        traversal.push_back( root->val );
        visited.insert( root );
        traversalStack.push( root );
        
        while( !traversalStack.empty() )
        {
            auto currNode { traversalStack.top() };
            
            if( isLeaf( currNode ) )
            {
                traversalStack.pop();
            }
            else if( allChildrenHaveBeenVisited( currNode, visited ) )
            {
                traversalStack.pop();
            }
            else if( (currNode->left != nullptr) && (visited.find( currNode->left ) == visited.end()) )
            {
                traversal.push_back( currNode->left->val );
                traversalStack.push( currNode->left );
                visited.insert( currNode->left );
            }
            else if( (currNode->right != nullptr) && (visited.find( currNode->right ) == visited.end()) )
            {
                traversal.push_back( currNode->right->val );
                traversalStack.push( currNode->right );
                visited.insert( currNode->right );
            }
        }
        
        return traversal;
    }
    
    
    /*
    // Option 2: Recursive solution
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
    */
};