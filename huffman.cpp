#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root) return;
    if (!root->left && !root->right) huffmanCode[root->ch] = str;
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void buildHuffman(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto pair : freq) pq.push(new Node(pair.first, pair.second));
    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *node = new Node('\0', left->freq + right->freq);
        node->left = left;
        node->right = right;
        pq.push(node);
    }
    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);
    for (auto pair : huffmanCode) cout << pair.first << ": " << pair.second << endl;
}

int main() {
    string text;
    cin >> text;
    buildHuffman(text);
    return 0;
}
