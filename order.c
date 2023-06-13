#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

enum stanZam { czeka, dostarczone, anulowane };
enum platnosc { oczekujace, oplacone, zwrocone };
enum typOplaty { karta, gotowka, online };

struct MenuNode {
  void *value;
  struct MenuNode *next;
};

struct MenuQueue {
  int size;
  int max_size;
  struct MenuNode *head;
  struct MenuNode *tail;
};

struct Order {
  int stanZamow;
  int idtable;
  struct MenuQueue menu;
};

struct Payment {
  double suma;
  int plat;
  int typOpl;
};

// Create Node
struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
  struct Order order;
  struct Payment pay;
};

// Menu functions
struct MenuQueue *newMenuQueue(int capacity) {
  struct MenuQueue *q;
  q = malloc(sizeof(struct MenuQueue));

  if (q == NULL) {
    return q;
  }

  q->size = 0;
  q->max_size = capacity;
  q->head = NULL;
  q->tail = NULL;

  return q;
}

int enqueueMenu(struct MenuQueue *q, void *value) {
  if ((q->size + 1) > q->max_size) {
    return q->size;
  }

  struct MenuNode *node = malloc(sizeof(struct MenuNode));

  if (node == NULL) {
    return q->size;
  }

  node->value = value;
  node->next = NULL;

  if (q->head == NULL) {
    q->head = node;
    q->tail = node;
    q->size = 1;

    return q->size;
  }

  q->tail->next = node;
  q->tail = node;
  q->size += 1;

  return q->size;
}

void *dequeueMenu(struct MenuQueue *q) {
  if (q->size == 0) {
    return NULL;
  }

  void *value = NULL;
  struct MenuNode *tmp = NULL;

  value = q->head->value;
  tmp = q->head;
  q->head = q->head->next;
  q->size -= 1;

  free(tmp);

  return value;
}

void freeMenuQueue(struct MenuQueue *q) {
  if (q == NULL) {
    return;
  }

  while (q->head != NULL) {
    struct MenuNode *tmp = q->head;
    q->head = q->head->next;
    if (tmp->value != NULL) {
      free(tmp->value);
    }

    free(tmp);
  }

  if (q->tail != NULL) {
    free(q->tail);
  }

  free(q);
}

// Binary tree functions
int max(int a, int b);

// Calculate height
int height(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) { return (a > b) ? a : b; }

// Create a node
struct Node *newNode(int key) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

// Get the balance factor
int getBalance(struct Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert node
struct Node *insertNode(struct Node *node, int key) {
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left), height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height = 1 + max(height(root->left), height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

// Print the tree
void printPreOrder(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

int main() {
  struct Node *root = NULL;

  root = insertNode(root, 2);
  root = insertNode(root, 1);
  root = insertNode(root, 7);
  root = insertNode(root, 4);
  root = insertNode(root, 5);
  root = insertNode(root, 3);
  root = insertNode(root, 8);

  printPreOrder(root);

  root = deleteNode(root, 3);

  printf("\nAfter deletion: ");
  printPreOrder(root);

  return 0;
}
