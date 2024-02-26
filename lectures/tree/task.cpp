#include <iostream>

using namespace std;
struct Node
{
    int value;
    struct Node *left, *right;
}; 
struct Node *getEmptynode(int val)
{
    struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
    tempNode->value = val;
    tempNode->left = NULL;
    tempNode->right = NULL;
    return tempNode;
}
struct Node *successor(struct Node *node)
{
    struct Node *present = node;
    // going to the left most node
    while (present != NULL && present->left != NULL)
    {
        present = present->left;
    }
    return present;
}
struct Node *insert(struct Node *node, int value)
{
    if (node == NULL)
    {
        return getEmptynode(value);
    }
    if (value < node->value)
    {
        node->left = insert(node->left, value);
    }
    else
    {
        node->right = insert(node->right, value);
    }
    return node;
}
int searchInBST(struct Node *node, int value)
{
    struct Node *current = node;
    while (current->value != value)
    {
        if (current->value > value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
        if (current == NULL)
        {
            return 0;
        }
    }
    return 1;
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}
struct Node *deleteNode(struct Node *node, int value)
{
    if (node == NULL)
    {
        return node;
    }
    if (value < node->value)
    {
        node->left = deleteNode(node->left, value);
    }
    else if (value > node->value)
    {
        node->right = deleteNode(node->right, value);
    }
    else
    {
        if (node->left == NULL)
        {
            struct Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }
        struct Node *temp = successor(node->right);
        node->value = temp->value;
        node->right = deleteNode(node->right, temp->value);
    }
    return node;
}
int main()
{
    system("cls");

    struct Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 13);
    root = insert(root, 15);

    cout << "InOrder Traversal after inserting all nodes: " << endl;
    inorder(root);
    root = insert(root, -10);
    cout << "\nInOrder Traversal after inserting -10 : " << endl;
    inorder(root);
    cout << "\nSearching -5 in the BST: " << searchInBST(root, -5) << endl;
    cout << "Searching -10 in the BST: " << searchInBST(root, -10) << endl;
    root = deleteNode(root, 8);
    cout << "After deleting node 8, inorder traversal: " << endl;
    inorder(root);
    root = deleteNode(root, -10);
    cout << "\nAfter deleting node -10, inorder traversal: " << endl;
    inorder(root);
}
