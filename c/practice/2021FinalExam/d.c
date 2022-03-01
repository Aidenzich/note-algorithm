// gcc d.c -o d && ./d < d.in
#include <stdio.h>
#include <stdlib.h>

struct node {
  int id;
  struct node *next;
};

struct node *read_data(int *size); // TODO: implement this function

void print_data(struct node *adj, int size) {
  if (!adj)
    return;
  for (int i = 0; i < size; ++i) {
    printf("%d -> ", adj[i].id);
    for (struct node *ptr = adj[i].next; ptr != NULL; ptr = ptr->next)
      printf("%d ", ptr->id);
    putchar('\n');
  }
}

void free_data(struct node *adj, int size) {
  if (!adj)
    return;
  for (int i = 0; i < size; ++i) {
    struct node *ptr = adj[i].next;
    while (ptr) {
      adj[i].next = ptr->next;
      free(ptr);
      ptr = adj[i].next;
    }
  }
  free(adj);
}

int main() {
  int size;
  struct node *adj = read_data(&size);
  if (!adj) {
    fprintf(stderr, "Error allocating memory.");
    exit(1);
  }
  print_data(adj, size);
  free_data(adj, size);
  return 0;
}

struct node *read_data(int *size) {
    static struct node *temp;
    char inStr[1000000], ch;
    // printf("%d\n", *size);
    scanf("%s -> ", inStr);
    while ((ch = getchar()) != EOF ){
      printf("%c\n", ch);
    }
    // printf("%s\n", inStr);
    // for (int i=0; i<*size; i++){
    //   long long nodeid = 0;
    //   
    //   scanf("%lld -> %s", &nodeid, inStr);
    //   // printf("%s", inStr);      
    // }
    return temp;
}