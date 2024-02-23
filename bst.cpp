#include <iostream>
#include <queue>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

int max(int a, int b) {
    if(a >= b)
        return a;
    else
        return b;
}

struct node* newNode(int item) {
    struct node *temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key) {
    if (node == NULL)
        return newNode(key);
    else if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

bool search(struct node* root, int key) {
    if (root == NULL || root->key == key)
        return root != NULL;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

int findSmallest(struct node* root) {
    if (root == NULL)
        return -1;
    while (root->left != NULL)
        root = root->left;
    return root->key;
}

int findLargest(struct node* root) {
    if (root == NULL)
        return -1;
    while (root->right != NULL)
        root = root->right;
    return root->key;
}

int height(struct node *root) {
    if (root == NULL)
        return 0;
    else {
        int left_height = height(root->left);
        int right_height = height(root->right);
        return max(left_height, right_height) + 1;
    }
}

int countNodes(struct node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(struct node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countNonLeafNodes(struct node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

void inorderTraversal(struct node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(struct node* root) {
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->key << " ";
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            delete root;
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void mirror(struct node* root) {
    if (root == NULL)
        return;
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

void deleteTree(struct node* root) {
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void display(struct node* root) {
    if (root == NULL)
        return;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        struct node* temp = q.front();
        cout << temp->key << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
        q.pop();
    }
}

int main() {
    struct node *root = NULL;
    int choice, value;
    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Find Smallest\n4. Find Largest\n5. Height\n6. Count Nodes\n7. Count Leaf Nodes\n8. Count Non-leaf Nodes\n9. Inorder Traversal\n10. Preorder Traversal\n11. Postorder Traversal\n12. Delete Node\n13. Mirror Image\n14. Delete Tree\n15. Display\n16. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value))
                    cout << "Key " << value << " is present in the BST." << endl;
                else
                    cout << "Key " << value << " is not present in the BST." << endl;
                break;
            case 3:
                cout << "Smallest element in BST: " << findSmallest(root) << endl;
                break;
            case 4:
                cout << "Largest element in BST: " << findLargest(root) << endl;
                break;
            case 5:
                cout << "Height of the BST: " << height(root) << endl;
                break;
            case 6:
                cout << "Total nodes in BST: " << countNodes(root) << endl;
                break;
            case 7:
                cout << "Total leaf nodes in BST: " << countLeafNodes(root) << endl;
                break;
            case 8:
                cout << "Total non-leaf nodes in BST: " << countNonLeafNodes(root) << endl;
                break;
            case 9:
                cout << "Inorder traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 10:
                cout << "Preorder traversal: ";
                preorderTraversal(root);
                cout << endl;
                break;
            case 11:
                cout << "Postorder traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;
            case 12:
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 13:
                mirror(root);
                cout << "Mirror image created." << endl;
                break;
            case 14:
                deleteTree(root);
                root = NULL;
                cout << "Tree deleted." << endl;
                break;
            case 15:
                cout << "Level-order traversal: ";
                display(root);
                cout << endl;
                break;
            case 16:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
    return 0;
}

