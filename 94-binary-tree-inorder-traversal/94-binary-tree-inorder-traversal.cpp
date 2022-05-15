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

/*boolean DFS(int root, int target) {
    Set<Node> visited;
    Stack<Node> stack;
    add root to stack;
    while (stack is not empty) {
        Node cur = the top element in stack;
        remove the cur from the stack;
        return true if cur is target;
        for (Node next : the neighbors of cur) {
            if (next is not in visited) {
                add next to visited;
                add next to stack;
            }
        }
    }
    return false;
}*/

class Solution {
public:
    bool isLeaf( TreeNode* node )
    {
        if( (node->left == nullptr) && (node->right == nullptr) )
        {
            return true;
        }
        
        return false;
    }
    
    bool allChildernHaveBeenTraversed( TreeNode* cur, std::set<TreeNode*> const& traversalSet )
    {
        bool leftHasBeenTraversed { (cur->left == nullptr) || 
            ( traversalSet.find( cur->left ) != traversalSet.end() ) };
        
        bool rightHasBeenTraversed { (cur->right == nullptr) || 
            ( traversalSet.find( cur->right ) != traversalSet.end() ) };
        
        return leftHasBeenTraversed && rightHasBeenTraversed;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal {};
        
        if( root == nullptr )
        {
            return traversal;
        }
        
        std::set<TreeNode*> traversalSet {};
        std::stack<TreeNode*> nodeStack {};
        nodeStack.push( root );
        
        while( !nodeStack.empty() )
        {
            TreeNode* cur { nodeStack.top() };
            
            if( isLeaf( cur ) )
            {
                traversal.push_back( cur->val );
                traversalSet.insert( cur );
                nodeStack.pop();
            }
            else if( (cur->left) != nullptr && ( traversalSet.find( cur->left ) == traversalSet.end() ) )
            {
                nodeStack.push( cur->left );
            }
            else if( cur->right != nullptr && ( traversalSet.find( cur->right ) == traversalSet.end() ) )
            {
                traversal.push_back( cur->val );
                traversalSet.insert( cur );
                nodeStack.pop();
                nodeStack.push( cur->right );
            }
            else if( allChildernHaveBeenTraversed( cur, traversalSet ) )
            {
                traversal.push_back( cur->val );
                traversalSet.insert( cur );
                nodeStack.pop();
            }
        }
        
        return traversal;
    }
};