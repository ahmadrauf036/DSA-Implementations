#include <iostream>
using namespace std;

class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
protected:
    AVLNode* root;

    AVLNode* insert(AVLNode* node, int key);
    AVLNode* deleteNode(AVLNode* root, int key);
    AVLNode* search(AVLNode* root, int key);
    int calculateHeight(AVLNode* node);
    int calculateDiameter(AVLNode* node, int& height);
    AVLNode* findMin(AVLNode* node);
    AVLNode* findMax(AVLNode* node);
    AVLNode* successor(AVLNode* node, int key);
    AVLNode* predecessor(AVLNode* node, int key);
    void inorder(AVLNode* root);
    void preorder(AVLNode* root);
    void postorder(AVLNode* root);
public:
    void inorder();
    void preorder();
    void postorder();
    AVLTree() : root(nullptr) {}
    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    int max(int a, int b);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* minValueNode(AVLNode* node);
    void insert(int key);
    void deleteNode(int key);

    void search(int key);

    int calculateHeight();
    int calculateDiameter();

    int findMin();

    int findMax();

    int successor(int key);
    int predecessor(int key);
};

int AVLTree::getHeight(AVLNode* node) {
    return node ? node->height : 0;
}
int AVLTree::getBalance(AVLNode* node) {
    return node ? getHeight(node->right) - getHeight(node->left) : 0;
}
int AVLTree::max(int a, int b) {
    return (a > b) ? a : b;
}
AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}
AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}
void AVLTree::insert(int key) {
    root = insert(root, key);
}
AVLNode* AVLTree::insert(AVLNode* node, int key) {
    if (!node) return new AVLNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance < -1 && key < node->left->key)
        return rotateRight(node);

    if (balance > 1 && key > node->right->key)
        return rotateLeft(node);

    if (balance < -1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance > 1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}
AVLNode* AVLTree::deleteNode(AVLNode* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            AVLNode* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = nullptr;
            }
            else
                *root = *temp;

            delete temp;
        }
        else {
            AVLNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance < -1 && getBalance(root->left) <= 0)
        return rotateRight(root);

    if (balance > 1 && getBalance(root->right) >= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalance(root->left) > 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance > 1 && getBalance(root->right) < 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}
AVLNode* AVLTree::search(AVLNode* root, int key) {
    if (!root || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}
void AVLTree::inorder(AVLNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
void AVLTree::preorder(AVLNode* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void AVLTree::postorder(AVLNode* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}
int AVLTree::calculateHeight(AVLNode* node) {
    if (!node) return 0;
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return 1 + max(leftHeight, rightHeight);
}
int AVLTree::calculateDiameter(AVLNode* node, int& height) {
    if (!node) {
        height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int ldiameter = calculateDiameter(node->left, lh);
    int rdiameter = calculateDiameter(node->right, rh);

    height = 1 + max(lh, rh);

    return max(lh + rh, max(ldiameter, rdiameter));
}
AVLNode* AVLTree::findMin(AVLNode* node) {
    if (node == nullptr)
    {
        cout << endl;
        return node;
    }
    else {
        AVLNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }
}
AVLNode* AVLTree::findMax(AVLNode* node) {
    if (node == nullptr)
    {
        cout << endl;
        return node;
    }
    else {
        AVLNode* current = node;
        while (current->right != nullptr)
            current = current->right;
        return current;
    }
}
AVLNode* AVLTree::successor(AVLNode* node, int key) {
    AVLNode* curr = search(root, key);
    if (!curr) return nullptr;

    if (curr->right) return findMin(curr->right);

    AVLNode* succ = nullptr;
    AVLNode* ancestor = root;
    while (ancestor != curr) {
        if (curr->key < ancestor->key) {
            succ = ancestor;
            ancestor = ancestor->left;
        }
        else
            ancestor = ancestor->right;
    }
    return succ;
}
AVLNode* AVLTree::predecessor(AVLNode* node, int key) {
    AVLNode* curr = search(root, key);
    if (!curr) return nullptr;

    if (curr->left) return findMax(curr->left);

    AVLNode* pred = nullptr;
    AVLNode* ancestor = root;
    while (ancestor != curr) {
        if (curr->key > ancestor->key) {
            pred = ancestor;
            ancestor = ancestor->right;
        }
        else
            ancestor = ancestor->left;
    }
    return pred;
}
void AVLTree::deleteNode(int key) {
    root = deleteNode(root, key);
}
void AVLTree::search(int key) {
    root = search(root, key);
}
int AVLTree::calculateHeight() {
    return calculateHeight(root);
}
int AVLTree::calculateDiameter() {
    int height = 0;
    return calculateDiameter(root, height);
}
int AVLTree::findMin() {
    AVLNode* minNode = findMin(root);
    return minNode ? minNode->key : -1;
}

int AVLTree::findMax() {
    AVLNode* maxNode = findMax(root);
    return maxNode ? maxNode->key : -1;
}

int AVLTree::successor(int key) {
    AVLNode* succ = successor(root, key);
    return succ ? succ->key : -1;
}

int AVLTree::predecessor(int key) {
    AVLNode* pred = predecessor(root, key);
    return pred ? pred->key : -1;
}
void AVLTree::inorder() {
    inorder(root);
    cout << endl;
}

void AVLTree::preorder() {
    preorder(root);
    cout << endl;
}

void AVLTree::postorder() {
    postorder(root);
    cout << endl;
}