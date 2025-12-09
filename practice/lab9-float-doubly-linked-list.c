#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

Node *allocate();
void readFloats(Node **, Node **, int, char **);
void displayFloats(Node *);

struct Node {
  float n;
  Node *prev;
  Node *next;
};

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  Node *first = NULL;
  Node *last = NULL;

  readFloats(&first, &last, n, argv);
  displayFloats(last);

  return 0;
}

Node *allocate() {
  Node *node = calloc(1, sizeof(Node));
  if (!node) {
    printf("Unable to allocate memory, exiting...\n");
    exit(0);
  }
  node->prev = NULL;
  node->next = NULL;

  return node;
}

void readFloats(Node **first, Node **last, int n, char **argv) {
  *first = allocate();
  Node *curr = *first;
  *last = curr;
  curr->n = atof(argv[2]);
  for (int i = 1; i < n; i++) {
    curr->next = allocate();
    curr->next->prev = curr;
    curr = curr->next;
    curr->n = atof(argv[2 + i]);
    *last = curr;
  }
}

void displayFloats(Node *last) {
  Node *curr = last;
  while (curr) {
    printf("%.2f\n", curr->n);
    curr = curr->prev;
  }
}
