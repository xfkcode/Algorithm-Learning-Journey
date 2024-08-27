#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <string>
using namespace std;


template<typename T>
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(T value) : val(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {}

    void insert(T value) {
        root = insert(root, value);
    }

    TreeNode<T>* search(T value) {
        return search(root, value);
    }

    void preOrderTraversal() {
        preOrderTraversal(root);
    }
    void inOrderTraversal() {
        inOrderTraversal(root);
    }
    void postOrderTraversal() {
        postOrderTraversal(root);
    }

private:
    TreeNode<T>* root;

    TreeNode<T>* insert(TreeNode<T>* node, T value) {
        if (node == nullptr) {
            return new TreeNode<T>(value);
        }
        if (value < node->val) {
            node->left = insert(node->left, value);
        } else if (value > node->val) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    TreeNode<T>* search(TreeNode<T>* node, T value) {
        if (node == nullptr || node->val == value) {
            return node;
        }
        if (value < node->val) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }
    
    // 前序遍历 (根 -> 左 -> 右)
    void preOrderTraversal(TreeNode<T>* node) {
        if (node == nullptr) return;
        cout << node->val << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
    // 中序遍历 (左 -> 根 -> 右)
    void inOrderTraversal(TreeNode<T>* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->val << " ";
        inOrderTraversal(node->right);
    }
    // 后序遍历 (左 -> 右 -> 根)
    void postOrderTraversal(TreeNode<T>* node) {
        if (node == nullptr) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->val << " ";
    }
};


int main() {
    BinaryTree<int> tree;  // 使用整数类型的二叉树
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);

    cout << "前序遍历: ";
    tree.preOrderTraversal();
    cout << endl;

    cout << "中序遍历: ";
    tree.inOrderTraversal();
    cout << endl;

    cout << "后序遍历: ";
    tree.postOrderTraversal();
    cout << endl;

    TreeNode<int>* found = tree.search(7);
    if (found) {
        cout << "找到节点: " << found->val << endl;
    } else {
        cout << "未找到节点" << endl;
    }

    // 使用字符串类型的二叉树
    BinaryTree<string> treeString;
    treeString.insert("apple");
    treeString.insert("banana");
    treeString.insert("cherry");

    cout << "字符串中序遍历: ";
    treeString.inOrderTraversal();
    cout << endl;


    system("pause");
    return 0;
}