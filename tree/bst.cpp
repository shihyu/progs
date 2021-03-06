// from: linux c 編程 - 一站式學習 (p 432) 


#include "bst.h"

#define COROUTINE_MORRIS_TRAVERSAL

#if 0
{
	link p;
	if (!t)
		return NULL;
	if (t->item > key) /* delete from left subtree */
		t->l = delete(t->l, key);
	else if (t->item < key) /* delete from right subtree */
		t->r = delete(t->r, key);
	else { /* if (t->item == key) */
		if (t->l == NULL && t->r == NULL) { /* if t is leaf node */
			free_node(t);
			t = NULL;
		} else if (t->l) { /* if t has left subtree */
			/* replace t with the rightmost node in left subtree */
			for (p = t->l; p->r; p = p->r);
			t->item = p->item;
			t->l = delete(t->l, t->item);
		} else { /* if t has right subtree */
			/* replace t with the leftmost node in right subtree */
			for (p = t->r; p->l; p = p->l);
			t->item = p->item;
			t->r = delete(t->r, t->item);
		}
	}
	return t;
}
#endif


void test_1()
{
#if 0
  Node *root = 0;

  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 10);
  root = insert(root, 9);
  root = insert(root, 2);
  root = insert(root, 8);
  root = insert(root, 4);
  root = insert(root, 5);

  printf("\\tree");
  print_tree(root);
  printf("\n");
#endif
}

void test_2()
{
#if 0
  Node *root = 0;
  root = insert(root, "abc", 3);
  root = insert(root, "def", 1);
  root = insert(root, "xyz", 10);
  printf("\\tree");
  print_tree(root);
  printf("\n");

  string str("adef");
  Node *n = search(root, str);
  if (n==0)
    cout << "not found: " << str << endl;
  else
    cout << "found (" << n->k_ << ", " <<  n->v_<< ")" << endl;
#endif
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

template <typename NodeType>
NodeType* invert_tree(NodeType* root) 
{
  NodeType *tmpNode;

  if (root) 
  {
    tmpNode = root->l_;
    root->l_ = invert_tree(root->r_);
    root->r_ = invert_tree(tmpNode);
  }

  return root;
}

#if 0
const char * ascending (void) 
{
    static int i;
    const char *arr[]= {"abcd", "def", 0};
 
    scrBegin;
    for (i=0; i<10; i++) {
       scrReturn(arr[i]);
    }
    scrFinish(0);
}
#endif

#ifdef TEST_MAIN
int main(int argc, char *argv[])
{
#if 0
  const char *c = ascending();
  cout << "c: " << c << endl;
  c = ascending();
  cout << "c: " << c << endl;
  exit(0);

  map<int, int> m;

  m = 
  { 
    {5,1}, 
    {10,2},
    {1,5}, 
    {11,8}, 
    {100,81}, 
    {1000,811}, 
  };

  for (auto i=m.begin() ; i != m.end() ; ++i)
  {
    cout << i->first << endl;
  }
  exit(0);
#endif

#ifdef COROUTINE_MORRIS_TRAVERSAL
{
  GNode<double, int> *r1 = 0;
  r1 = insert(r1, 8.2, 7);

  r1 = insert(r1, 4.2, 7);
  r1 = insert(r1, 1.2, 3);
  r1 = insert(r1, 3.2, 5);
  r1 = insert(r1, 2.2, 4);
  r1 = insert(r1, 3.4, 4);
  r1 = insert(r1, 5.8, 0);
  r1 = insert(r1, 14.2, 7);
  //print_tree(r1);

  
  GNode<double, int> *cur_node = r1;
  cout << "use morris_traversal" << endl;

  while(cur_node)
  {
    cur_node = morris_traversal(r1);
    if (cur_node != 0)
      cout << cur_node->k_ << endl;
  }
  exit(0);
}
#endif

#if 0
  GNode<std::string, int> *root = 0;
  root = insert(root, "abc", 3);
  root = insert(root, "def", 1);
  root = insert(root, "xyz", 10);
  root = insert(root, "lmn", 987);
  printf("\\tree");
  print_tree(root);
  printf("\n");

  string str("def");
  GNode<std::string, int> *n = search(root, str);
  if (n==0)
    cout << "not found: " << str << endl;
  else
    cout << "found (" << n->k_ << ", " <<  n->v_<< ")" << endl;

#else
  GNode<double, int> *r1 = 0;
  r1 = insert(r1, 8.2, 7);
  r1 = insert(r1, 4.2, 7);
  r1 = insert(r1, 1.2, 3);
  r1 = insert(r1, 3.2, 5);
  r1 = insert(r1, 2.2, 4);
  r1 = insert(r1, 3.4, 4);
  r1 = insert(r1, 5.8, 0);
  r1 = insert(r1, 14.2, 7);

  morris_traversal(r1);


#if 0
  printf("\\tree");
  print_tree(r1);
  printf("\n");
  del(r1, 3.2);
  printf("\\tree");
  print_tree(r1);
  printf("\n");
#endif

#if 0
  GNode<double, int> *r2 = 0;

  r2 = invert_tree(r1);

  printf("\n\n");
  printf("\\tree");
  print_tree(r2);
  printf("\n");
#endif

#endif
  return 0;
}
#endif
