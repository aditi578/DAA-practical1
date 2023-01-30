#include <bits/stdc++.h>

using namespace std;

// class Node{
// public:
//  int data;
//  Node*left;
//  Node*right;

//  Node(int val){
//      data = val;
//      left = NULL;
//      right = NULL;
//  }
// };

struct TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {

        val = data;
        left = NULL;
        //this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree
{
public:
    vector<int> pre(TreeNode *root1)
    {

        vector<int> ans;
        preorder(root1, ans);

        return ans;
    }

    void preorder(TreeNode *root1, vector<int> &ans)
    {

        if (root1 == NULL)
        {
            return;
        }

        ans.push_back(root1->val);

        preorder(root1->left, ans);
        preorder(root1->right, ans);
    }

    void inorder(TreeNode *root1)
    {
        if (root1 == NULL)
            return;
        inorder(root1->left);
        cout << root1->val << " ";
        inorder(root1->right);
    }

    void postorder(TreeNode *root1)
    {
        if (root1 == NULL)
            return;

        postorder(root1->left);
        postorder(root1->right);
        cout << root1->val << " ";
    }

    int levelorder(TreeNode *root1)
    {
        queue<TreeNode *> q;
        if (root1 == NULL)
            cout << "NULL";

        q.push(root1);
        while (!q.empty())
        {

            TreeNode *node = q.front();
            int l = q.size();
            cout << node << endl;
            q.pop();

            for (int i = 0; i < l; i++)
            {
                if (root1->left)
                    q.push(root1->left);
                if (root1->right)
                    q.push(root1->right);
                // levelorder(root1->left);
                // levelorder(root1->right);
            }
        }
    }

    // check if given tree is symmetric
    bool isSymmetric(TreeNode *root1)
    {
        if (root1 == nullptr)
            return true;

        return checkSym(root1->left, root1->right);
    }
    bool checkSym(TreeNode *l, TreeNode *r)
    {

        if (l == NULL and r == NULL)
            return true;

        else if (l == NULL || r == NULL)
            return false;

        else if (l->val != r->val)
        {
            return false;
        }

        return checkSym(l->left, r->right) && checkSym(l->right, r->left);
    }

    // check if two trees are same
    bool areSameTree(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL or root2 == NULL)
            return root1 == root2;

        return (root1->val == root2->val) and areSameTree(root1->left, root2->left) and areSameTree(root1->right, root2->right);
    }

    // height of a binary tree
    int height(TreeNode *root1)
    {
        if (root1 == NULL)
            return 0;
        return max(height(root1->left), height(root1->right)) + 1;
    }

    // sum of all nodes in a binary tree
    int sumTree(TreeNode *root2)
    {

        if (root2 == NULL)
            return 0;

        return sumTree(root2->left) + sumTree(root2->right) + root2->val;
    }

    // right view of tree

    void rightView(TreeNode *root1, vector<int> &ans, int level)
    {
        if (!root1)
            return;

        if (ans.size() == level)
        {
            ans.push_back(root1->val);
            cout << root1->val << " ";
        }

        rightView(root1->right, ans, level + 1);
        // for left view exchange these two recurrsive calls
        rightView(root1->left, ans, level + 1);
    }

    // zigzag traversal
    vector<vector<int>> zigzag(TreeNode *root1)
    {
        vector<vector<int>> ans;
        if (!root1)
            return ans;

        queue<TreeNode *> q;
        q.push(root1);
        bool lTr = true;

        while (!q.empty())
        {
            int sz = q.size();
            vector<int> res(sz);

            for (int i = 0; i < sz; ++i)
            {
                TreeNode *node = q.front();
                q.pop();

                // position to fill the node's value
                int index = (lTr) ? i : sz - 1 - i;
                res[index] = node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
            lTr = !lTr;
            ans.push_back(res);
        }
        return ans;
    }

    // boundary traversal acw (left->leaf->right)
    bool isleaf(TreeNode *root1)
    {

        return  root1->left == NULL and root1->right == NULL;
    }

    void addLeft(TreeNode *root1, vector<int> &res)
    {
        // if(root1==NULL) return res;

        TreeNode *curr = root1->left;
        while (curr)
        {

            if (!isleaf(curr))
            {
                res.push_back(curr->val);
            }

            if (curr->left)
            {
                curr = curr->left;
            }
            else
                curr = curr->right;
        }
    }

    void addRight(TreeNode *root1, vector<int> &res)
    {
        vector<int> temp;

        TreeNode *curr = root1->right;
        while (curr)
        {

            if (!isleaf(curr))
            {
                temp.push_back(curr->val);
            }

            if (curr->left)
            {
                curr = curr->left;
            }
            else
                curr = curr->right;
        }
        for (int i = temp.size() - 1; i >= 0; ++i)
        {
            res.push_back(temp[i]);
        }
    }

    void addLeaves(TreeNode *root1, vector<int> &res)
    {
        if (isleaf(root1))
        {
            res.push_back(root1->val);
            return;
        }

        if (root1->left)
        {
            addLeaves(root1->left, res);
        }
        if (root1->right)
        {
            addLeaves(root1->right, res);
        }
    }


    vector<int> printBoundary(TreeNode *root1)
    {
        vector<int> res;
        if (root1 == NULL)
            return res;

        if (!isleaf(root1))
        res.push_back(root1->val);
        addLeft(root1, res);
        addLeaves(root1, res);
        addRight(root1, res);
        return res;
    }


// lowest common ancestor
    TreeNode* Ancestor(TreeNode*root1,TreeNode*p,TreeNode*q){
        if (root1 == nullptr || root1==p || root1 == q)
        {
            return root1;
        }

        TreeNode*lft = Ancestor(root1->left,p,q);
        TreeNode*rght = Ancestor(root1->right,p,q);

        if(left == nullptr)return rght;
        if(right == nullptr) return lft;

        else 
            return root1;
    }
};

int main()
{
    BinaryTree b;
    // tree 1
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(6);
    root1->left->left->left = new TreeNode(4);
    root1->right = new TreeNode(3);
    root1->right->right = new TreeNode(5);

    // tree 2
    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(4);
    root2->right = new TreeNode(3);
    root2->right->left = new TreeNode(5);
    // root2->right->right = new TreeNode(6);
    for (auto i : b.pre(root1))
        cout << i << " ";
   // cout << endl;
   // b.inorder(root1);
    cout << endl;
    b.postorder(root1);
    cout << endl;

    if (b.isSymmetric(root1))
    {
        cout << "The tree is symmetric" << endl;
    }
    else
        cout << "Not symmetric" << endl;

    if (b.areSameTree(root1, root2))
    {
        cout << "Both the trees are identical" << endl;
    }
    else
        cout << "Trees are not identical" << endl;
    cout << b.height(root1) << endl;
    cout << b.sumTree(root2) << endl;
    // b.levelorder(root1);

    vector<vector<int>> v = b.zigzag(root1);
    for (int i = 0; i < v.size(); i++)
    {
        for (auto k : v[i])
        {
            cout << k << " ";
        }
    }

    
    vector<int> o = b.printBoundary(root1);
    for (int i = 0; i < o.size(); i++)
    {
        cout << o.at(i) << " ";
    }
    
    cout<<b.Ancestor(root1, root1->left->left->left , root1->left->right);

}