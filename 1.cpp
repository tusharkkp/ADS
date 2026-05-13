 
#include <iostream> 
#include <queue> 
#include <stack> 
using namespace std; 
 
class Node{ 
    public: 
        int data; 
        Node* left; 
        Node* right; 
 
        Node(int data){ 
            this->data = data; 
            this->left = NULL; 
            this->right = NULL; 
        } 
}; 
 
class BinarySearchTree{ 
    public: 
        Node* root; 
 
        BinarySearchTree(){ 
            root = NULL; 
        } 
 
        Node* insert(Node* root, int key); 
 
        void create(); 
        void inorder(Node* root); 
        void preorder(Node* root); 
        void postorder(Node* root); 
 
        void nr_inorder(Node* root); 
        void nr_preorder(Node* root); 
        void nr_postorder(Node* root); 
 
        void levelorder(Node* root); 
        bool searchInBST(Node* root, int key); 
        Node* maxNode(Node* root); 
        Node* minNode(Node* root); 
        Node* deletion(Node* root, int key); 
        
 
}; 
 
Node* BinarySearchTree::insert(Node* root, int key){ 
    if(root == NULL){ 
        root = new Node(key); 
        return root; 
    } 
    
    if(root->data < key){ 
        root->right = insert(root->right, key); 
    } 
    else{ 
        root->left = insert(root->left, key); 
    } 
    return root; 
} 
 
void BinarySearchTree::create(){ 
    int data = 0; 
    do{ 
        cout << "Enter data (-1 to stop): "; 
        cin >> data; 
 
        if(data == -1) break; 
        root = insert(root, data); 
    }while(true); 
} 
 
void BinarySearchTree::inorder(Node* root){ 
    if(root == NULL){ 
        return; 
    } 
 
    inorder(root->left); 
    cout << root->data << " "; 
    inorder(root->right); 
} 
 
void BinarySearchTree::preorder(Node* root){ 
    if(root == NULL){ 
        return; 
    } 
 
    cout << root->data << " "; 
    preorder(root->left); 
    preorder(root->right); 
} 
 
void BinarySearchTree::postorder(Node* root){ 
    if(root == NULL){ 
        return; 
    } 
 
    postorder(root->left); 
    postorder(root->right); 
    cout << root->data << " "; 
} 
 
void BinarySearchTree::nr_inorder(Node* root){ 
 
    if(root == NULL){ 
        return; 
    } 
    else{ 
        stack<Node*> st; 
        Node* temp = root; 
 
        while(temp != NULL || !st.empty()){ 
 
            while (temp != NULL) 
            { 
                st.push(temp); 
                temp = temp->left; 
            } 
            temp = st.top(); 
            st.pop(); 
            cout << temp->data << " "; 
            temp = temp->right; 
        } 
    } 
} 
 
void BinarySearchTree::nr_preorder(Node* root){ 
    if(root == NULL){ 
        return; 
    } 
    else{ 
        stack<Node*> st; 
        Node* temp = root; 
 
        while(temp != NULL || !st.empty()){ 
 
            while(temp != NULL){ 
                st.push(temp); 
                cout << temp->data << " "; 
 
                temp = temp->left; 
            } 
 
            temp = st.top(); 
            st.pop(); 
            temp = temp->right; 
        } 
 
    } 
} 
 
void BinarySearchTree::nr_postorder(Node* root){ 
    if(root == NULL){ 
        return; 
    } 
    else{ 
        if (root == NULL) { 
        cout << "Tree is empty !" << endl; 
        return; 
    } 
 
    stack<Node*> st1; 
    stack<Node*> st2; 
 
    Node *current = root; 
    st1.push(current); 
    while (!st1.empty()) 
    { 
        current = st1.top(); 
        st1.pop(); 
        st2.push(current); 
        
        if (current->left) { 
            st1.push(current->left); 
        } 
 
        if (current->right) { 
            st1.push(current->right); 
        } 
    } 
 
    while (!st2.empty()) 
    { 
        cout << st2.top()->data << " "; 
        st2.pop(); 
    } 
    
    cout << endl; 
    } 
} 
 
void BinarySearchTree::levelorder(Node* root){ 
    queue<Node*> q; 
    q.push(root); 
    q.push(NULL); 
 
    while(!q.empty()){ 
        Node* temp = q.front(); 
        q.pop(); 
 
        if(temp == NULL){ 
            cout << endl; 
            if(!q.empty()){ 
                q.push(NULL); 
            } 
        } 
        else{ 
            cout << temp->data << " "; 
 
            if(temp->left){ 
                q.push(temp->left); 
            } 
            if(temp->right){ 
                q.push(temp->right); 
            } 
        } 
    }   
} 
 
bool BinarySearchTree::searchInBST(Node* root, int key){ 
    if(root == NULL){ 
        return false; 
    } 
 
    if(root->data == key ){ 
        return true; 
    } 
    else if(root->data > key){ 
        return searchInBST(root->left, key); 
    } 
    else{ 
        return searchInBST(root->right, key); 
    } 
} 
 
Node* BinarySearchTree::maxNode(Node* root){ 
    Node* temp = root; 
    if(temp == NULL){ 
        cout << "Tree is Empty" << endl; 
        return NULL; 
    } 
    while(temp->right != NULL){ 
        temp = temp->right; 
    } 
    return temp; 
} 
 
Node* BinarySearchTree::minNode(Node* root){ 
    Node* temp = root; 
    if(temp == NULL){ 
        cout << "Tree is Empty" << endl; 
        return NULL; 
    } 
    while(temp->left != NULL){ 
        temp = temp->left; 
    } 
    return temp; 
} 
 
Node* BinarySearchTree::deletion(Node* root, int key){ 
    if(root == NULL){ 
        cout << "Tree is Empty" << endl; 
        return NULL; 
    } 
 
    if(root->data == key){ 
        if(root->left == NULL && root->right == NULL){ 
            delete root; 
            return NULL; 
        } 
        else if(root->left == NULL && root->right != NULL){ 
            Node* temp = root->right; 
            delete root; 
            return temp; 
        } 
        else if(root->left != NULL && root->right == NULL){ 
            Node* temp = root->left; 
            delete root; 
            return temp; 
        } 
        else if(root->left != NULL && root->right != NULL){ 
            int mini = minNode(root->right)->data; 
            root->data = mini; 
            root->right = deletion(root->right, mini); 
            return root; 
        } 
    } 
    else if(root->data > key){ 
        root->left = deletion(root->left, key); 
        return root; 
    } 
    else if(root->data < key){ 
        root->right = deletion(root->right, key); 
        return root; 
    } 
} 
 
int main(){ 
 
    BinarySearchTree BST; 
 
    int choice, value; 
 
    do{ 
        cout << "\n===== Binary Search Tree Menu =====\n"; 
        cout << "1. Create Tree\n"; 
        cout << "2. Insert Element\n"; 
        cout << "3. Recursive Inorder\n"; 
        cout << "4. Recursive Preorder\n"; 
        cout << "5. Recursive Postorder\n"; 
        cout << "6. Non-Recursive Inorder\n"; 
        cout << "7. Non-Recursive Preorder\n"; 
        cout << "8. Non-Recursive Postorder\n"; 
        cout << "9. Level Order Traversal\n"; 
        cout << "10. Search Element\n"; 
        cout << "11. Find Minimum\n"; 
        cout << "12. Find Maximum\n"; 
        cout << "13. Delete Element\n"; 
        cout << "0. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch(choice){ 
 
            case 1: 
                BST.create(); 
                break; 
 
            case 2: 
                cout << "Enter value to insert: "; 
                cin >> value; 
                BST.root = BST.insert(BST.root, value); 
                break; 
 
            case 3: 
                cout << "Inorder Traversal: "; 
                BST.inorder(BST.root); 
                cout << endl; 
                break; 
 
            case 4: 
                cout << "Preorder Traversal: "; 
                BST.preorder(BST.root); 
                cout << endl; 
                break; 
 
            case 5: 
                cout << "Postorder Traversal: "; 
                BST.postorder(BST.root); 
                cout << endl; 
                break; 
 
            case 6: 
                cout << "Non-Recursive Inorder: "; 
                BST.nr_inorder(BST.root); 
                cout << endl; 
                break; 
 
            case 7: 
                cout << "Non-Recursive Preorder: "; 
                BST.nr_preorder(BST.root); 
                cout << endl; 
                break; 
 
            case 8: 
                cout << "Non-Recursive Postorder: "; 
                BST.nr_postorder(BST.root); 
                break; 
 
            case 9: 
                cout << "Level Order Traversal:\n"; 
                BST.levelorder(BST.root); 
                break; 
 
            case 10: 
                cout << "Enter element to search: "; 
                cin >> value; 
                if(BST.searchInBST(BST.root, value)) 
                    cout << "Element Found\n"; 
                else 
                    cout << "Element Not Found\n"; 
                break; 
 
            case 11: { 
                Node* minNode = BST.minNode(BST.root); 
                if(minNode) 
                    cout << "Minimum value: " << minNode->data << endl; 
                break; 
            } 
 
            case 12: { 
                Node* maxNode = BST.maxNode(BST.root); 
                if(maxNode) 
                    cout << "Maximum value: " << maxNode->data << endl; 
                break; 
            } 
 
            case 13: 
                cout << "Enter element to delete: "; 
                cin >> value; 
                BST.root = BST.deletion(BST.root, value); 
                cout << "Element deleted if it existed.\n"; 
                break; 
 
            case 0: 
                cout << "Exiting program...\n"; 
                break; 
 
            default: 
                cout << "Invalid choice! Try again.\n"; 
        } 
 
    } while(choice != 0); 
    
    return 0; 
} 
 
 
