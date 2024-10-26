// Community version
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int previousLevelSum = root->val;

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            int currentLevelSum = 0;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                // Update node value to cousin sum.
                currentNode->val = previousLevelSum - currentNode->val;

                // Calculate sibling sum.
                int siblingSum =
                    (currentNode->left != nullptr ? currentNode->left->val
                                                  : 0) +
                    (currentNode->right != nullptr ? currentNode->right->val
                                                   : 0);

                if (currentNode->left != nullptr) {
                    currentLevelSum +=
                        currentNode->left
                            ->val;  // Accumulate current level sum.
                    currentNode->left->val =
                        siblingSum;  // Update left child's value.
                    nodeQueue.push(
                        currentNode->left);  // Add to queue for next level.
                }
                if (currentNode->right != nullptr) {
                    currentLevelSum +=
                        currentNode->right
                            ->val;  // Accumulate current level sum.
                    currentNode->right->val =
                        siblingSum;  // Update right child's value.
                    nodeQueue.push(
                        currentNode->right);  // Add to queue for next level.
                }
            }

            previousLevelSum = currentLevelSum;  // Update previous level sum
                                                 // for next iteration.
        }
        return root;
    }
};

// My version
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        int sum = 0;
        root->val = 0;
        q1.push(root);
        while (!q1.empty() || !q2.empty()) {
            while (!q1.empty()) {
                sum += (q1.front()->left ? q1.front()->left->val : 0)
                     + (q1.front()->right ? q1.front()->right->val : 0);
                q2.push(q1.front());
                q1.pop();
            }
            while (!q2.empty()) {
                int new_val = sum - (q2.front()->left ? q2.front()->left->val : 0)
                                  - (q2.front()->right ? q2.front()->right->val : 0);
                if (q2.front()->left) {
                    q2.front()->left->val = new_val;
                    q1.push(q2.front()->left);
                }
                if (q2.front()->right) {
                    q2.front()->right->val = new_val;
                    q1.push(q2.front()->right);
                }
                q2.pop();
            }
            sum = 0;
        }
        return root;
    }
};
