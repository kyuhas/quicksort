#ifndef NODE_HEADER_FILE
#define NODE_HEADER_FILE

struct mynode {
	int const value;
	struct mynode *next;   
	struct mynode *prev;
};


struct mynode *theHead;
struct mynode *theTail;

struct mynode *quicksort(struct mynode *head);
void printlist(struct mynode *head);

struct mynode *getLast(struct mynode *theNode);
void quick(struct mynode *l, struct mynode *r);
struct mynode *partition(struct mynode *left, struct mynode *right);
void swap(struct mynode *node1, struct mynode *node2);
int getIndexOf(struct mynode *node);
struct mynode *getNodeAt(int index);

#endif