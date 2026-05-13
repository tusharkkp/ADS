 
#include <iostream> 
#include <stack> 
using namespace std; 
 
class Node { 
public: 
    int data; 
    Node *left, *right; 
    bool leftThread, rightThread; 
 
    Node(int val) { 
        data = val; 
        left = right = NULL; 
        leftThread = rightThread = true; 
    } 
}; 
 
class ThreadedBT { 
public: 
    Node *root; 
 
    ThreadedBT() { 
        root = NULL; 
    } 
 
    void insert(int value) { 
        Node *newNode = new Node(value); 
 
        if (root == NULL) { 
            root = newNode; 
            return; 
        } 
 
        Node *temp = root, *parent = NULL; 
 
        while (temp != NULL) { 
            parent = temp; 
 
            if (value < temp->data) { 
                if (!temp->leftThread) 
                    temp = temp->left; 
                else 
                    break; 
            } 
            else if (value > temp->data) { 
                if (!temp->rightThread) 
                    temp = temp->right; 
                else 
                    break; 
            } 
            else { 
                cout << "Duplicate not allowed\n"; 
                return; 
            } 
        } 
 
        if (value < parent->data) { 
            newNode->left = parent->left; 
            newNode->right = parent; 
            parent->leftThread = false; 
            parent->left = newNode; 
        } 
        else { 
            newNode->right = parent->right; 
            newNode->left = parent; 
            parent->rightThread = false; 
            parent->right = newNode; 
        } 
    } 
 
    Node* inorderSuccessor(Node *ptr) { 
        if (ptr->rightThread) 
            return ptr->right; 
 
        ptr = ptr->right; 
        while (!ptr->leftThread) 
            ptr = ptr->left; 
 
        return ptr; 
    } 
 
    void inorderNonRecursive() { 
        if (root == NULL) return; 
 
        Node *ptr = root; 
 
        while (!ptr->leftThread) 
            ptr = ptr->left; 
 
        while (ptr != NULL) { 
            cout << ptr->data << " "; 
            ptr = inorderSuccessor(ptr); 
        } 
        cout << endl; 
    } 
 
    void inorderRecursive(Node *node) { 
        if (node == NULL) return; 
 
        if (!node->leftThread) 
            inorderRecursive(node->left); 
 
        cout << node->data << " "; 
 
        if (!node->rightThread) 
            inorderRecursive(node->right); 
    } 
 
    void preorderRecursive(Node *node) { 
        if (node == NULL) return; 
 
        cout << node->data << " "; 
 
        if (!node->leftThread) 
            preorderRecursive(node->left); 
 
        if (!node->rightThread) 
            preorderRecursive(node->right); 
    } 
 
    void preorderNonRecursive() { 
        if (root == NULL) return; 
 
        stack<Node*> st; 
        st.push(root); 
 
        while (!st.empty()) { 
            Node *curr = st.top(); 
            st.pop(); 
 
            cout << curr->data << " "; 
 
            if (!curr->rightThread) 
                st.push(curr->right); 
 
            if (!curr->leftThread) 
                st.push(curr->left); 
        } 
        cout << endl; 
    } 
 
    void postorderRecursive(Node *node) { 
        if (node == NULL) return; 
 
        if (!node->leftThread) 
            postorderRecursive(node->left); 
 
        if (!node->rightThread) 
            postorderRecursive(node->right); 
 
        cout << node->data << " "; 
    } 
 
    void postorderNonRecursive() { 
        if (root == NULL) return; 
 
        stack<Node*> s1, s2; 
        s1.push(root); 
 
        while (!s1.empty()) { 
            Node *curr = s1.top(); 
            s1.pop(); 
            s2.push(curr); 
 
            if (!curr->leftThread) 
                s1.push(curr->left); 
 
            if (!curr->rightThread) 
                s1.push(curr->right); 
        } 
 
        while (!s2.empty()) { 
            cout << s2.top()->data << " "; 
            s2.pop(); 
        } 
        cout << endl; 
    } 
}; 
 
int main() { 
    ThreadedBT t; 
    int choice, value; 
 
    do { 
        cout << "\n--------------Threaded Binary Tree Menu ----------------\n"; 
        cout << "1. Insert\n"; 
        cout << "2. Inorder Traversal Recursive\n"; 
        cout << "3. Inorder Traversal Non-Recursive\n"; 
        cout << "4. Preorder Traversal Recursive\n"; 
        cout << "5. Preorder Traversal Non-Recursive\n"; 
        cout << "6. Postorder Traversal Recursive\n"; 
        cout << "7. Postorder Traversal Non-Recursive\n"; 
        cout << "8. Exit\n"; 
        cout << "Enter choice: "; 
        cin >> choice; 
 
        switch (choice) { 
 
        case 1: 
            cout << "Enter value: "; 
            cin >> value; 
            t.insert(value); 
            break; 
 
        case 2: 
            cout << "Inorder Recursive: "; 
            t.inorderRecursive(t.root); 
            cout << endl; 
            break; 
 
        case 3: 
            cout << "Inorder Non-Recursive: "; 
            t.inorderNonRecursive(); 
            break; 
 
        case 4: 
            cout << "Preorder Recursive: "; 
            t.preorderRecursive(t.root); 
            cout << endl; 
            break; 
 
        case 5: 
            cout << "Preorder Non-Recursive: "; 
            t.preorderNonRecursive(); 
            break; 
 
        case 6: 
            cout << "Postorder Recursive: "; 
            t.postorderRecursive(t.root); 
            cout << endl; 
            break; 
 
        case 7: 
            cout << "Postorder Non-Recursive: "; 
            t.postorderNonRecursive(); 
            break; 
 
        case 8: 
            cout << "Exiting...\n"; 
            break; 
 
        default: 
            cout << "Invalid choice\n"; 
        } 
 
    } while (choice != 8); 
 
    return 0; 
} 
 
