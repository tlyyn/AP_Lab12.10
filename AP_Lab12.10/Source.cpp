#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void printTree(Node* root, int indent = 0) {
    if (root == nullptr) {
        return;
    }
    printTree(root->right, indent + 4);
    for (int i = 0; i < indent; i++) {
        cout << " ";
    }
    cout << root->data << endl;
    printTree(root->left, indent + 4);
}

Node* mergeSubtrees(Node* leftSubtree, Node* rightSubtree) {
    if (leftSubtree == nullptr) {
        return rightSubtree;
    }
    if (rightSubtree == nullptr) {
        return leftSubtree;
    }
    return leftSubtree;
}

Node* removeEvenNodes(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    root->left = removeEvenNodes(root->left);
    root->right = removeEvenNodes(root->right);
    if (root->data % 2 == 0) {
        Node* temp = root;
        root = mergeSubtrees(root->left, root->right);
        delete temp;
    }
    return root;
}

int main() {
    ifstream inputFile("tree.txt");
    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return 0;
    }

    Node* root = nullptr;
    int value;
    while (inputFile >> value) {
        root = insertNode(root, value);
    }

    cout << "Tree before removing even nodes:" << endl;
    printTree(root);

    root = removeEvenNodes(root);

    cout << "Tree after removing even nodes:" << endl;
    printTree(root);

    inputFile.close();

    return 0;
}
