#include <stdio.h>
#include <stdlib.h>

#include "btree.h"
#include "RedBlack.h"
#include "alr.h"

int main()
{
	BTree* head = NULL;
	initTree(&head);
	Node data;

	BTree* item = addLeftChild(head, &data);
	item = addRightChild(head, &data);
	item = addRightChild(item, &data);
	item = addRightChild(head, &data);

	printTreeMid(head);
	deleteTree(head);
	return 0;
}

