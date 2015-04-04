#define	TRUE	1
#define	FALSE	0
#define	t	3
typedef struct B_TREE {
	short	leaf;
	unsigned int	n;
	char	key[2 * t];
	struct	B_TREE	*c[2 * t + 1];
} btree;

struct BTREE {
	btree	*root;
};

typedef struct B_TREE_RETURN {
	btree	*node;
	int		index;
} BTRR;

void disk_read(btree*);
void disk_write(btree*);
