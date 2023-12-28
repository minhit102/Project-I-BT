#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* insert_node(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }

    if (val < root->val) {
        root->left = insert_node(root->left, val);
    } else if (val > root->val) {
        root->right = insert_node(root->right, val);
    }

    return root;
}

void pre_node(Node* root) {
    if (root) {
        cout << root->val << " ";
        pre_node(root->left);
        pre_node(root->right);
    }
}

int main() {
    Node* root = NULL;
    string cm;
    int val;

    while (true) {
        cin >> cm;
        if (cm == "#") {
            break;
        } else if (cm == "insert") {
            cin >> val;
            root = insert_node(root, val);
        }
    }

    pre_node(root);

    return 0;
}
