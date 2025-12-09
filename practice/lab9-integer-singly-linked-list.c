#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

Node *allocate();
Node *readInts(int, char **);
void displayInts(Node *);

struct Node {
  int n;
  Node *next;
};

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  Node *first = NULL;

  first = readInts(n, argv);
  displayInts(first);

  return 0;
}

Node *allocate() {
  Node *node = calloc(1, sizeof(Node));
  if (!node) {
    printf("Unable to allocate memory\n");
    exit(0);
  }
  node->next = NULL;
  return node;
}

Node *readInts(int n, char **argv) {
  Node *first = allocate();
  Node *curr = first;
  curr->n = atoi(argv[2]);
  for (int i = 0; i < n - 1; i++) {
    curr->next = allocate();
    curr = curr->next;
    curr->n = atoi(argv[i + 3]);
  }
  return first;
}

void displayInts(Node *first) {
  Node *curr = first;
  while (curr) {
    printf("%d\n", curr->n);
    curr = curr->next;
  }
}
