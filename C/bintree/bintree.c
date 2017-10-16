#include <stdio.h>
#include <stdlib.h>

struct bintree {
  struct bintree *left;
  struct bintree *right;
  int data;
};

struct queue {
  struct queue *next;
  struct bintree *data;
};

/* BIN TREE */
struct bintree *initree(int val);
void setvalue(struct bintree *tree,int val);
void insert_node_left(struct bintree *tree, int val);
void insert_node_right(struct bintree *tree, int val);
void printlefthand(struct bintree *tree);
void printrighthand(struct bintree *tree);
struct bintree *creat_test_tree();

/* QUEUE */

struct queue *init_queue();
void enqueue(struct queue *queue, struct bintree *tree);
struct bintree *dequeue (struct queue *queue);

void print_larg(struct bintree *tree);

/*ABR */
int is_ABR(struct bintree *tree);
struct bintree*creat_test_ABR();


int main ()
{

  /*Test bintree*/
  struct bintree *tree = creat_test_tree();
  printf("Main gauche : ");
  printlefthand(tree);
  printf("\nMain droite : ");
  printrighthand(tree);
  printf("\nLargeur :     ");
  print_larg(tree);
  printf("\n");
  printf("ABR ? %d \n",is_ABR(tree));


  /*Test ABR*/
  struct bintree *ABR = creat_test_ABR();
  printf ("PArcours largeur : ");
  print_larg(ABR);
  printf("\n ABR ? %d \n",is_ABR(ABR));
  return 0;
}

/* BIN TREE */

struct bintree *initree(int val)
{
  struct bintree *tree = malloc(sizeof(struct bintree));
  tree->left = NULL;
  tree->right= NULL;
  tree->data =val;
  return tree;
}

void setvalue(struct bintree *tree, int elem)
{
  tree->data = elem;
}

void insert_node_left(struct bintree *tree, int val)
{
  struct bintree *node = initree(val);
  if (tree->left == NULL)
    tree->left = node;
  else 
  {
    node->left = tree->left;
    tree->left = node;
  }
}

void insert_node_right(struct bintree *tree,int val)
{
  struct bintree *node = initree(val);
  if (tree->right == NULL)
    tree->right = node;
  else
  {
    node->right = tree->right;
    tree->right = node;
  }
}

void printlefthand(struct bintree *tree)
{
  if (tree == NULL)
    return;
  printlefthand(tree->left);
  printf("%d - ",tree->data);
  printlefthand(tree->right);
}

void printrighthand(struct bintree *tree)
{
  if (tree == NULL)
    return;
  printf("%d - ",tree->data);
  printrighthand(tree->right);
  printrighthand(tree->left);
}

struct bintree *creat_test_tree()
{
  struct bintree *tree = initree(0);
  insert_node_left(tree,1);
  insert_node_left(tree->left,2);
  insert_node_right(tree->left,5);
  insert_node_left(tree->left->left,3);
  insert_node_right(tree->left->left,4);
  insert_node_right(tree,6);
  insert_node_left(tree->right,7);
  insert_node_right(tree->right,8);
  insert_node_left(tree->right->right,9);
  insert_node_right(tree->right->right,10);
  
  printf("------------------------------------\n");
  printf("             arbre de test: \n\n");
  printf("               0\n\n");
  printf("        1              6\n\n");
  printf("    2       5      7        8\n\n");
  printf(" 3     4                 9     10\n");
  printf("-------------------------------------\n");
  return tree;
}

struct bintree *creat_test_ABR()
{
  struct bintree *tree = initree(8);
  insert_node_left(tree,3);
  insert_node_left(tree->left,1);
  insert_node_right(tree->left,5);
  insert_node_right(tree,10);
  insert_node_right(tree->right,12);

  printf ("---------------------------------------\n");
  printf ("              ABR de test              \n");
  printf ("\n");
  printf ("                   8                   \n\n");
  printf ("              3        10              \n\n");
  printf ("           1     5         12          \n\n");
  printf ("---------------------------------------\n\n");

}

/* QUEUE */

struct queue *init_queue()
{
  struct queue *queue = malloc(sizeof(struct queue));
  queue->next = NULL;
  return queue;
}

void enqueue (struct queue *queue, struct bintree *tree)
{
  struct queue *temp = queue;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = init_queue ();
  temp->next->data=tree;
}
  
struct bintree *dequeue (struct queue *queue)
{
  struct bintree *tree = initree(0);
  if (queue->next!= NULL)
    tree = queue->next->data;
  if (queue->next->next !=NULL)
    queue->next = queue->next->next;
  else
    queue->next = NULL;
  return tree;
}

void print_larg(struct bintree *tree)
{
  struct queue *queue = init_queue();
  enqueue (queue,tree);
  while (queue->next !=NULL){
    struct bintree *node = dequeue(queue);
    if (node->left != NULL)
      enqueue (queue, node->left);
    if (node->right !=NULL)
      enqueue (queue,node->right);
    printf ("%d - ",node->data);
  }
}


/* ABR */

int is_ABR(struct bintree *tree)
{
  if (tree->left != NULL && tree -> right != NULL)
  {
    is_ABR(tree->left);
    is_ABR(tree->right);
    return (tree->left->data < tree->data &&
	tree->data < tree->right->data);
  }
  else if (tree->left != NULL)
  {
    is_ABR(tree->left);
    return (tree->left->data < tree -> data);
  }
  else if (tree->right != NULL)
  {
    is_ABR(tree->left);
    return (tree->data < tree->right->data);
  }
  return 1;
}


