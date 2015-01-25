#define BST
typedef struct bst_node {
	struct bst_node *p;
	struct bst_node *left;
	struct bst_node *right;
	int	key;
} bn;

void inorder_tree_walk(bn*);
void inorder_tree_walk_nore(bn*);
bn* tree_search(bn*, int);
bn* iterative_tree_search(bn*, int);
bn* tree_minimum(bn*);
bn* tree_maximum(bn*);
bn* tree_successor(bn*);
bn* tree_minimum_rec(bn*);
bn* tree_maximum_rec(bn*);
bn* tree_predecessor(bn*);
