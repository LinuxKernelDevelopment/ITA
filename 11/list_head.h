
struct list_head {
	struct list_head *next, *prev;
};

#define INIT_LIST_HEAD(ptr) do { \
	(ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

static __inline void __list_add(struct list_head *new,
		struct list_head *prev,
		struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void __list_del(struct list_head *prev,
		struct list_head *next)
{
	next->prev = prev;
	prev->next = next;
}

#define list_entry(ptr, type, member) \
	((type *)((char *)(ptr) - (unsigned long) (&((type *)0)->member)))
