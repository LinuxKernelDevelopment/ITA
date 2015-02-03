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
void rb_insert(rbt*, rbn*);
void rb_insert_fixup(rbt*, rbn*);
void rb_transplant(rbt*, rbn*, rbn*);
void rb_delete(rbt*, rbn*);
rbn* rb_minimum(rbt*, rbn*);
void rb_delete_fixup(rbt*, rbn*);
rbn* rb_search(rbn*, int);
void dbg(rbn*, rbn*);

#define	RED		1
#define	BLACK	0
typedef	int		COLOR;
