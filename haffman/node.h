#include <iostream>
using namespace std;

template<class T>
class TreeNode {
    public :
        int weight;
        int parent;
        int left;
        int right;
    public :
        TreeNode();
};

template<class T>
TreeNode<T>::TreeNode() {
    weight = parent = left = right = 0;
}


