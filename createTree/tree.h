#include <iostream>
using namespace std;

template<class T> 
class TreeNode {
    public :
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode<T> *parent;
        T data;
    public :
        TreeNode();
        void createNode(TreeNode<T> *parent, char child, T data);
};

template<class T>
TreeNode<T>::TreeNode() {

}

template<class T>
void TreeNode<T>::createNode(TreeNode<T> *root, char child, T data) {
    TreeNode<T> *node = new TreeNode<T>();
    node->data = data;
    node->parent = root;
    if (child == 'l') {
        root->left = node;
    } 
    else if (child == 'r') {
        root->right = node;
    }
}
