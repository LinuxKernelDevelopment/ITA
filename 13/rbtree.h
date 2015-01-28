typedef struct rbnode {
	int	color;
	int key;
	struct rbnode *left;
	struct rbnode *right;
	struct rbnode *p;
} rbn;

typedef struct rbtree {
	struct rbnode *root;
	struct rbnode *nil;
} rbt;

void left_rotate(rbt*, rbn*);
void right_rotate(rbt*, rbn*);
