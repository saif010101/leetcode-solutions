/*
[Intuition]
Since Level Order Traversal goes from left to right, we can determine if tree is from left to right, 
for if we encounter a non-null node and we have encountered a NULL node before, than it means 
it is not a complete binary tree.

[Approach]
- Use the queue data structure for level order traversal and check if a null was encountered before.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        // queue data structure
        queue<TreeNode*> q;

        // a flag variable to check if null was encountered
        bool nullEncountered = false;

        // initially push the root
        q.push(root);

        // while the queue is not empty
        while (!q.empty()) {
            
            // store front in temp
            TreeNode* temp = q.front();

            // if left node is not null and we have encountered null before than it cannot be a CBT, hence return false
            if (temp->left && nullEncountered)
                return false;

            // else if we have encountered a null node then set flag to true
            else if (!temp->left)
                nullEncountered = true;
            // else just push the node in the queue
            else
                q.push(temp->left);


            // if right node is not null and we have encountered null before than it cannot be a CBT, hence return false
            if (temp->right && nullEncountered)
                return false;
            // else if we have encountered a null node then set flag to true
            else if (!temp->right)
                nullEncountered = true;
            // else just push the node in the queue
            else
                q.push(temp->right);

            // pop the front
            q.pop();
        }

        return true;
    }
};
