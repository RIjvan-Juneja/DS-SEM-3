// Binary Search Tree operations in C

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

}