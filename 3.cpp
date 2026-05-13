#include <iostream> 
#include <stack> 
#include <queue> 
using namespace std; 
 
class Node { 
public: 
    int data; 
    Node *left, *right; 
    int height; 
 
    Node(int val) { 
        data = val; 
        left = right = NULL; 
        height = 1; 
    } 
}; 
 
class TBT { 
public: 
    Node* root; 
 
    TBT() { 
        root = NULL; 
    } 
 
    int height(Node* n) { 
        if (n == NULL) return 0; 
        return n->height; 
    } 
 
    int max(int a, int b) { 
        return (a > b) ? a : b; 
    } 
 
    int getBalance(Node* n) { 
        if (n == NULL) return 0; 
        return height(n->left) - height(n->right); 
    } 
 
    Node* rightRotate(Node* y) { 
        Node* x = y->left; 
        Node* t2 = x->right; 
 
        x->right = y; 
        y->left = t2; 
 
        y->height = max(height(y->left), height(y->right)) + 1; 
        x->height = max(height(x->left), height(x->right)) + 1; 
 
        return x; 
    } 
 
    Node* leftRotate(Node* x) { 
        Node* y = x->right; 
        Node* t2 = y->left; 
 
        y->left = x; 
        x->right = t2; 
 
        x->height = max(height(x->left), height(x->right)) + 1; 
        y->height = max(height(y->left), height(y->right)) + 1; 
 
        return y; 
    } 
 
    Node* insertAVL(Node* node, int key) { 
        if (node == NULL) 
            return new Node(key); 
 
        if (key < node->data) 
            node->left = insertAVL(node->left, key); 
        else if (key > node->data) 
            node->right = insertAVL(node->right, key); 
        else 
            return node; 
 
        node->height = 1 + max(height(node->left), height(node->right)); 
 
        int balance = getBalance(node); 
 
        // LL 
        if (balance > 1 && key < node->left->data) 
            return rightRotate(node); 
 
        // RR 
        if (balance < -1 && key > node->right->data) 
            return leftRotate(node); 
 
        // LR 
        if (balance > 1 && key > node->left->data) { 
            node->left = leftRotate(node->left); 
            return rightRotate(node); 
        } 
 
        // RL 
        if (balance < -1 && key < node->right->data) { 
            node->right = rightRotate(node->right); 
            return leftRotate(node); 
        } 
 
        return node; 
    } 
 
    void insert(int key) { 
        root = insertAVL(root, key); 
    } 
 
    void create() { 
        int n, val; 
        cout << "Enter number of nodes: "; 
        cin >> n; 
        for (int i = 0; i < n; i++) { 
            cin >> val; 
            insert(val); 
        } 
    } 
 
     
    void inorder(Node* node) { 
        if (node) { 
            inorder(node->left); 
            cout << node->data << " "; 
            inorder(node->right); 
        } 
    } 
 
    void preorder(Node* node) { 
        if (node) { 
            cout << node->data << " "; 
            preorder(node->left); 
            preorder(node->right); 
        } 
    } 
 
    void postorder(Node* node) { 
        if (node) { 
            postorder(node->left); 
            postorder(node->right); 
            cout << node->data << " "; 
        } 
    } 
 
   
    void inorderNR() { 
        stack<Node*> st; 
        Node* curr = root; 
 
        while (curr != NULL || !st.empty()) { 
            while (curr != NULL) { 
                st.push(curr); 
                curr = curr->left; 
            } 
            curr = st.top(); st.pop(); 
            cout << curr->data << " "; 
            curr = curr->right; 
        } 
    } 
 
    void preorderNR() { 
        if (!root) return; 
 
        stack<Node*> st; 
        st.push(root); 
 
        while (!st.empty()) { 
            Node* curr = st.top(); st.pop(); 
            cout << curr->data << " "; 
 
            if (curr->right) st.push(curr->right); 
            if (curr->left) st.push(curr->left); 
        } 
    } 
 
    void postorderNR() { 
        if (!root) return; 
 
        stack<Node*> s1, s2; 
        s1.push(root); 
 
        while (!s1.empty()) { 
            Node* curr = s1.top(); s1.pop(); 
            s2.push(curr); 
 
            if (curr->left) s1.push(curr->left); 
            if (curr->right) s1.push(curr->right); 
        } 
 
        while (!s2.empty()) { 
            cout << s2.top()->data << " "; 
            s2.pop(); 
        } 
    } 
 
   
    void levelorder() { 
        if (!root) return; 
 
        queue<Node*> q; 
        q.push(root); 
 
        while (!q.empty()) { 
            Node* curr = q.front(); q.pop(); 
            cout << curr->data << " "; 
 
            if (curr->left) q.push(curr->left); 
            if (curr->right) q.push(curr->right); 
        } 
    } 
}; 
 
int main() { 
    TBT t; 
    t.create(); 
 
    cout << "\nRecursive Inorder: "; 
    t.inorder(t.root); 
 
    cout << "\nRecursive Preorder: "; 
    t.preorder(t.root); 
 
    cout << "\nRecursive Postorder: "; 
    t.postorder(t.root); 
 
    cout << "\nNon-Recursive Inorder: "; 
    t.inorderNR(); 
 
    cout << "\nNon-Recursive Preorder: "; 
    t.preorderNR(); 
 
    cout << "\nNon-Recursive Postorder: "; 
    t.postorderNR(); 
 
    cout << "\nLevel Order: "; 
    t.levelorder(); 
 
    return 0; 
} 
 
