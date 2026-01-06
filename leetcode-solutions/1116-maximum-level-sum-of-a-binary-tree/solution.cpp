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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 1, bestLevel = 1, bestSum = INT_MIN;

        while (!q.empty()) {

            int nodesAtThisLevel = q.size();
            int currentSum = 0;

            for (int i = 0; i < nodesAtThisLevel; i++) {
                TreeNode* node = q.front();
                q.pop();

                currentSum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (currentSum > bestSum) {
                bestSum = currentSum;
                bestLevel = level;
            }
            level++;
        }
        return bestLevel;
    }
};
