//10.Tree creation using array.
#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    TreeNode* root;

public:
    Tree() : root(nullptr) {}

    void buildTreeFromArray(vector<int>& arr, int index, int size) {
        if (index >= size || arr[index] == -1) {
            return;
        }

        root = new TreeNode(arr[index]);
        buildTreeFromArray(arr, 2 * index + 1, size);
        buildTreeFromArray(arr, 2 * index + 2, size);
    }

    void printInOrder(TreeNode* node) {
        if (node != nullptr) {
            printInOrder(node->left);
            cout << node->data << " ";
            printInOrder(node->right);
        }
    }

    void printTree() {
        printInOrder(root);
        cout << endl;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, -1, -1, 4, 5};
    
    Tree tree;
    tree.buildTreeFromArray(arr, 0, arr.size());
    
    cout << "In-order traversal of the tree: ";
    tree.printTree();

    return 0;
}