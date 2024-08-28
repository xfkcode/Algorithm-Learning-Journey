#include <iostream>
#include <queue>
using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 层序遍历1
void levelOrderTraverse1(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        // 访问 cur 节点
        cout << cur->val << endl;
        
        // 把 cur 的左右子节点加入队列
        if (cur->left != nullptr) {
            q.push(cur->left);
        }
        if (cur->right != nullptr) {
            q.push(cur->right);
        }
    }
}

// 层序遍历2
void levelOrderTraverse2(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    // 记录当前遍历到的层数（根节点视为第 1 层）
    int depth = 1;

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            TreeNode* cur = q.front();
            q.pop();
            // 访问 cur 节点，同时知道它所在的层数
            cout << "depth = " << depth << ", val = " << cur->val << endl;

            // 把 cur 的左右子节点加入队列
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
        depth++;
    }
}

// 层序遍历3
class State {
public:
    TreeNode* node;
    int depth;

    State(TreeNode* node, int depth) : node(node), depth(depth) {}
};

void levelOrderTraverse3(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<State> q;
    // 根节点的路径权重和是 1
    q.push(State(root, 1));

    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        // 访问 cur 节点，同时知道它的路径权重和
        cout << "depth = " << cur.depth << ", val = " << cur.node->val << endl;

        // 把 cur 的左右子节点加入队列
        if (cur.node->left != nullptr) {
            q.push(State(cur.node->left, cur.depth + 1));
        }
        if (cur.node->right != nullptr) {
            q.push(State(cur.node->right, cur.depth + 1));
        }
    }
}

// 测试函数
void testLevelOrderTraverse() {
    // 创建一个测试树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Testing levelOrderTraverse1:" << endl;
    levelOrderTraverse1(root);

    cout << "Testing levelOrderTraverse2:" << endl;
    levelOrderTraverse2(root);

    cout << "Testing levelOrderTraverse3:" << endl;
    levelOrderTraverse3(root);

    // 释放树节点
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;
}

int main() {
    testLevelOrderTraverse();
    return 0;
}
