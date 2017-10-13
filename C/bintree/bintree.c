#include <stdio.h>
#include <stdlib.h>

struct bintree {
  struct bintree *left;
  struct bintree *right;
  int data;
};

struct file {
  struct file *suiv;
  struct tree *donne;
};

struct bintree *initree(int val);
void setvalue(struct bintree *tree,int val);
void insert_node_left(struct bintree *tree, int val);
void insert_node_right(struct bintree *tree, int val);
void printlefthand(struct bintree *tree);
void printrighthand(struct bintree *tree);
struct bintree *creat_test_tree();
struct file *inifile();
void file_insert(struct file *file,struct bintree *tree);
void file_pop(struct file *file);
int file_empty(struct file *file);
void print_prof(struct bintree *tree);
void print_file (struct file *file);
int main ()
{

  struct bintree *tree = creat_test_tree();
//  printlefthand(tree);
//  printrighthand(tree);
//  print_prof(tree);
  struct file *file = init
  return 0;
}



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
  printf("%d - ",tree->data);
  printlefthand(tree->left);
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

struct file *inifile()
{
  struct file *file = malloc(sizeof(struct file));
  file -> suiv = NULL;
  return file;
}

void file_insert (struct file *file, struct bintree *tree)
{
  struct file *newelem = inifile(tree);
  file -> suiv = newelem;
}

void file_pop(struct file *file)
{
  file = file->suiv->suiv;
}

int file_empty(struct file *file)
{
  return file->suiv == NULL;
}

void print_prof (struct bintree *tree)
{
  struct file *file = inifile();
  file_insert(file,tree);
  while (!file_empty(file))
  {
    /*
    if (file->donne->left !=NULL)
      file_insert(file,file->donne->left);
    if (file->donne->right != NULL)
      file_insert(file,file->donne->right);
    */
    printf("%d - ",file->suiv->donne==NULL);
    file_pop(file);
  }

}

void print_file (struct file *file)
{
  while (file->suiv != NULL)
  {
    printf (file->suiv

}
