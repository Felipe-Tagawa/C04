#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* n) {
    return n ? n->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1; // new node is initially added at leaf
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Inserção em árvore binária comum
void tInsere(Node*& root, int key) {
    if (root == NULL) {
        root = newNode(key);
        return;
    }
    if (key < root->key) {
        tInsere(root->left, key);
    } else {
        tInsere(root->right, key);
    }
}

// Inserção em árvore AVL
Node* tInsereAVL(Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = tInsereAVL(node->left, key);
    else if (key > node->key)
        node->right = tInsereAVL(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int tPesq(Node* root, int key, int& count) {
    count++;
    if (root == NULL || root->key == key)
        return root != NULL;

    if (key < root->key)
        return tPesq(root->left, key, count);
    else
        return tPesq(root->right, key, count);
}

int main() {
    Node* arvore = NULL;
    Node* arvoreAVL = NULL;
    int valor, x;
    
    while (cin >> valor && valor != 0) {
        tInsere(arvore, valor);
        arvoreAVL = tInsereAVL(arvoreAVL, valor);
    }
    
    cin >> x;
    
    int countNormal = 0;
    int countAVL = 0;
    
    tPesq(arvore, x, countNormal);
    tPesq(arvoreAVL, x, countAVL);
    
    cout << "Arvore normal: " << countNormal << endl;
    cout << "AVL: " << countAVL << endl;
    
    return 0;
}
