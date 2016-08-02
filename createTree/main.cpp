#include <iostream>
#include <fstream>
#include "tree.h"
#include "stack.h"

using namespace std;

TreeNode<char> *tree = new TreeNode<char>();
TreeNode<char> *root = new TreeNode<char>();

Stack<TreeNode<char> > *stack = new Stack<TreeNode<char> >();

void createTree() {
    TreeNode<char> *temp = root;
    ifstream in;
    int left;
    int right;
    char data;
    in.open("data.txt");
    while (!in.eof()) {
        in >> left >> right >> data;
        if (right == 1) {                      
             stack->add(root);                           //若该节点有右子树,节点入栈
        }
        if (left == 1) {
            tree->createNode(root, 'l', data);          //若该节点有左子树,创建左子树
            root = root->left;
        }
        if (left == 0) {
            root = tree->remove();                      //若该节点没有左子树,取栈顶元素
        }
    }
    in.close();
}

int main() {
//    createTree();
    return 0;
}
