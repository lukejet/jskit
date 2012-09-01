#ifndef _BTREE_H_
#define _BTREE_H_

typedef struct NodeL{
	int key;
	int value;

} NodeL;

typedef struct List {
	struct NodeL* node;
	struct List* pre;
	struct List* next;
} List;


typedef struct BTree {
	int key;
	struct NodeL* node;
	struct BTree* left;
	struct BTree* right;
	struct BTree* parent;
} BTree;

void initTree(BTree** head);

void deleteTree(BTree* node);

void printTreeLeft(BTree* node);

void printTreeMid(BTree* node);

void printTreeRight(BTree* node);

BTree* addLeftChild(BTree* node, NodeL* data);

BTree* addRightChild( BTree* node,  NodeL* data);


#endif // _BTREE_H_
