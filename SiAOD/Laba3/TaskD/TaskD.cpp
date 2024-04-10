//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба3.1
//КТбо1-6, Кравченко Александр Андреевич
//TaskD
//24.03.2024
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

void TreeInsert(Node*& root, int key) {
    if (!root) {
        root = new Node;
        root->key = key;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (key < root->key) TreeInsert(root->left, key);
    else if (key > root->key) TreeInsert(root->right, key);
}

void OneChild(Node* root, vector<int>& nodes) {
    if (!root) return;
    int children = (root->left ? 1 : 0) + (root->right ? 1 : 0);
    if (children == 1) nodes.push_back(root->key);
    OneChild(root->left, nodes);
    OneChild(root->right, nodes);
}

int main() {
    Node* root = nullptr;
    int key;
    while (cin >> key && key != 0) TreeInsert(root, key);
    vector<int> nodes;
    OneChild(root, nodes);
    sort(nodes.begin(), nodes.end());
    for (int node : nodes) cout << node << endl;
}