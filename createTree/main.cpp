#include <iostream>
#include <fstream>
#include "tree.h"
#include "stack.h"

using namespace std;

TreeNode<char> *tree = new TreeNode<char>();
TreeNode<char> *root = new TreeNode<char>();

Stack<TreeNode<char> > *stack = new Stack<TreeNode<char> >();

void createTree() {
    root->data = 'R';
    TreeNode<char> *temp = root;
//    TreeNode<char> *change = new TreeNode<char>();
    ifstream in;
    int left;
    int right;
    char data;
    in.open("data.txt");
    while (!in.eof()) {
        in >> left >> right >> data;
        
        if (right == 1 && left == 1) {                      
             stack->add(root);                           //若该节点有右子树,节点入栈
        }
        if (left == 1) {
            tree->createNode(root, 'l', data);          //若该节点有左子树,创建左子树
            root = root->left;
        }
        if (right == 1 && left == 0) {                  //若该节点只有右子树,创建右子树
            tree->createNode(root, 'r', data);
            root = root->right;
        }
        if (left == 0 && right == 0) {
            root = stack->remove();                      //若该节点没有子树,取栈顶元素
        }
    }
    root = temp;
}

void PreOrder(TreeNode<char> *root) {
    Stack<TreeNode<char> > *stack = new Stack<TreeNode<char> >();   
    TreeNode<char> *temp = root;
    while (temp != NULL || !stack->isEmpty()) {
        if (temp != NULL) {
            cout << temp->data << endl;
            stack->add(temp);
            temp = temp->left;
        } else {
            temp = stack->remove();
            temp = temp->right;
        }
    }
}

void InOrder(TreeNode<char> *root) {
    Stack<TreeNode<char> > *stack = new Stack<TreeNode<char> >();
    TreeNode<char> *temp = root;
    while (temp != NULL || !stack->isEmpty()) {
        if (temp != NULL) {
            stack->add(temp);
            temp = temp->left;
        } else {
            temp = stack->remove();
            cout << temp->data << endl;
            temp = temp->right;
        }
    }
}

void PostOrder(TreeNode<char> *root) {
    if (root) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << endl;
    }
}

int main() {
    createTree();
//    PreOrder(root);
//    InOrder(root);
    PostOrder(root);
    return 0;
}
