#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left;
  struct node *right;
};

// Create a node
struct node *newNode(int data) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *root, int key) {
  // Return a new node if the tree is empty
  if (root == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key <= root->key)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);

  return root;
}

// Search for a key in the BST
struct node *search(struct node *root, int key) {
  // Base Cases: root is null or key is present at root
  if (root == NULL || root->key == key)
     return root;

  // Key is smaller than the root's key
  if (key < root->key)
     return search(root->left, key);

  // Key is larger than the root's key
  return search(root->right, key);
}

int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  insert(root, 3);
  insert(root, 1);
  insert(root, 6);
  insert(root, 7);
  insert(root, 10);
  insert(root, 14);
  insert(root, 4);

  printf("Inorder traversal: ");
  inorder(root);

  int key_to_search = 6;
  struct node *search_result = search(root, key_to_search);

  if (search_result != NULL)
    printf("\n%d found in the tree.\n", key_to_search);
  else
    printf("\n%d not found in the tree.\n", key_to_search);

  return 0;
}
