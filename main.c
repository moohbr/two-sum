#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  int position;
  struct Node *next;
} Node;

Node *create_node(int value, Node *next, int position, int target) {
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
    printf("Erro: falha na alocacao de memoria para o no com valor %d!\n",
           value);
    exit(1);
  }
  new_node->value = value;
  new_node->position = position;
  new_node->next = next;
  return new_node;
}

void verify(Node **node, int actual_position, int number, int target) {
  if (number > target) {
    printf("Erro: valor %d nao pode ser inserido, pois e maior que o valor da "
           "raiz (%d).\n",
           number, target);
    return;
  }

  if (*node == NULL) {
    *node = create_node(number, NULL, actual_position, target);
    return;
  }

  if ((number + (*node)->value) == target) {
    printf("Soma de %d + %d = %d\n", number, (*node)->value, target);
    exit(0);
    return;
  } else {
    verify(&(*node)->next, actual_position, number, target);
  }
}

int main() {
  // const int target = 6;
  // int nums[] = {3, 2, 4};

  // const int target = 9;
  // int nums[] = {2, 7, 11, 15};

  const int target = 6;
  int nums[] = {3, 3};

  int size = sizeof(nums) / sizeof(nums[0]);
  Node *head = NULL;

  for (int i = 0; i < size; i++) {
    verify(&head, i, nums[i], target);
  }
  return 0;
}
