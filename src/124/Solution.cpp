// My version, over-designed
class Solution {
public:
    typedef struct TreeNodeW {
        TreeNode* node;
        TreeNodeW* left;
        TreeNodeW* right;
        int lMax;
        int rMax;
        TreeNodeW(TreeNode* node) : node(node), left(nullptr), right(nullptr), 
            lMax(0), rMax(0) {}
    } TreeNodeW;

    TreeNodeW* initTree(TreeNode* root) {
        TreeNodeW* rootW = new TreeNodeW(root);
        if (root->left) rootW->left = initTree(root->left);
        if (root->right) rootW->right = initTree(root->right);
        return rootW;
    }

    void freeTree(TreeNodeW* root) {
        if (root->left) freeTree(root->left);
        if (root->right) freeTree(root->right);
        delete root;
    }

    int calTreeWeight(TreeNodeW* root) {
        if (root->left)
            root->lMax = max({ 0, root->left->node->val + calTreeWeight(root->left) });
        if (root->right)
            root->rMax = max({ 0, root->right->node->val + calTreeWeight(root->right) });        

        return max(root->lMax, root->rMax);
    }

    void findMaxSum(TreeNodeW* root, int* res) {
        if (root->lMax + root->rMax + root->node->val > *res) 
            *res = root->lMax + root->rMax + root->node->val;
        if (root->left) findMaxSum(root->left, res);
        if (root->right) findMaxSum(root->right, res);
    }

    int maxPathSum(TreeNode* root) {
        TreeNodeW* rootW = initTree(root);
        int res = root->val;
        
        calTreeWeight(rootW);
        findMaxSum(rootW, &res);

        freeTree(rootW);
        return res;
    }
};

// Community version
class Solution {
public:
int s(TreeNode* root, int &ms)
{
    if(root==NULL) return 0;
    int left = max(0,s(root->left,ms));
    int right = max(0,s(root->right,ms));
    ms=max(ms,root->val+left+right);
    return(root->val+max(left,right));
}

    int maxPathSum(TreeNode* root) {
        int ms=INT_MIN;
        s(root,ms);
        return ms;
    }
};
