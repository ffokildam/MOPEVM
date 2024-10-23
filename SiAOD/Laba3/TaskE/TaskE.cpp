//ЮФУ, ИКТИБ, МОП ЭВМ
//Структуры и алгоритмы обработки данных
//Лаба3
//КТбо1-6, Кравченко Александр Андреевич
//TaskE
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

void SecondLargest(Node* root, Node*& first, Node*& second) {
    if (root == nullptr) return;

    SecondLargest(root->right, first, second);

    if (first == nullptr) first = root;
    else if (second == nullptr) second = root;
    else return;

    SecondLargest(root->left, first, second);
}

int main() {
    Node* root = nullptr;
    int key;
    while (cin >> key && key != 0) TreeInsert(root, key);
 
    Node* first = nullptr;
    Node* second = nullptr;
    SecondLargest(root, first, second);

    cout << second->key << endl;
}
