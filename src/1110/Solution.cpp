// My version
class Solution {
public:
    void traverse(TreeNode** node_ptr, unordered_set<int>& del_set, 
                  vector<TreeNode*>& res, bool isRoot) {
        TreeNode *node = *node_ptr, **left_ptr = &(*node_ptr)->left, **right_ptr = &(*node_ptr)->right;
        bool isLeftRoot = false, isRightRoot = false;
        auto iter = del_set.find(node->val);
        if (isRoot && iter == del_set.end())
            res.push_back(node);
        if (iter != del_set.end()) {
            del_set.erase(iter);
            *node_ptr = nullptr;
            isLeftRoot = true;
            isRightRoot = true;
        }
        
        if (*left_ptr) traverse(left_ptr, del_set, res, isLeftRoot);
        if (*right_ptr) traverse(right_ptr, del_set, res, isRightRoot);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> del_set(to_delete.begin(), to_delete.end());
        traverse(&root, del_set, res, true);
        return res;
    }
};
