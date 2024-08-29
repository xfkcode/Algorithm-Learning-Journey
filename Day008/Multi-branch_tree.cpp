#include <iostream>
#include <vector>
#include <queue>

class Node {
public:
    int val;
    std::vector<Node*> children;
    Node(int _val) : val(_val) {}
};

// 前后序遍历
void traverse(Node* root) {
    if (root == nullptr) {
        return;
    }
    // 前序位置
    std::cout << "Preorder: " << root->val << std::endl;
    for (Node* child : root->children) {
        traverse(child);
    }
    // 后序位置
    std::cout << "Postorder: " << root->val << std::endl;
}

// 层序遍历1
void levelOrderTraverse1(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        std::cout << "LevelOrder1: " << cur->val << std::endl;
        for (Node* child : cur->children) {
            q.push(child);
        }
    }
}

// 层序遍历2
void levelOrderTraverse2(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    int depth = 1;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Node* cur = q.front();
            q.pop();
            std::cout << "LevelOrder2 - depth = " << depth << ", val = " << cur->val << std::endl;
            for (Node* child : cur->children) {
                q.push(child);
            }
        }
        depth++;
    }
}

// 层序遍历3
class State {
public:
    Node* node;
    int depth;
    State(Node* node, int depth) : node(node), depth(depth) {}
};

void levelOrderTraverse3(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::queue<State> q;
    q.push(State(root, 1));
    while (!q.empty()) {
        State state = q.front();
        q.pop();
        Node* cur = state.node;
        int depth = state.depth;
        std::cout << "LevelOrder3 - depth = " << depth << ", val = " << cur->val << std::endl;
        for (Node* child : cur->children) {
            q.push(State(child, depth + 1));
        }
    }
}

// 测试用例
int main() {
    // 创建多叉树
    Node* root = new Node(1);
    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);
    Node* child4 = new Node(5);

    root->children = {child1, child2, child3};
    child1->children = {child4};

    std::cout << "        1\n";
    std::cout << "      / | \\\n";
    std::cout << "     2  3  4\n";
    std::cout << "    /\n";
    std::cout << "   5\n";

    std::cout << "----- 前后序遍历 -----" << std::endl;
    traverse(root);

    std::cout << "----- 层序遍历1 -----" << std::endl;
    levelOrderTraverse1(root);

    std::cout << "----- 层序遍历2 -----" << std::endl;
    levelOrderTraverse2(root);

    std::cout << "----- 层序遍历3 -----" << std::endl;
    levelOrderTraverse3(root);

    // 释放内存
    delete root;
    delete child1;
    delete child2;
    delete child3;
    delete child4;

    return 0;
}
