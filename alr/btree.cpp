#include <stdio.h>
#include <stdlib.h>

#include "btree.h"

void initTree( BTree** head )
{
	BTree* root = (BTree*)malloc(sizeof(BTree));
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;

	*head = root;
}

void deleteTree( BTree* node )
{
	if (node->left)
	{
		deleteTree(node->left);
		node->left = NULL;
		return ;
	}
	if (node->right)
	{
		deleteTree(node->right);
		node->right = NULL;
		return;
	}

	free(node);
	return ;
}

static void printNode( NodeL* node )
{
	static int cnt = 0;
	printf ("count: %d \n", cnt++);
	return;
}

void printTreeLeft( BTree* node )
{
	if (node->left)
	{
		printTreeLeft(node->left);
	}
	printNode(node->node);
	if (node->right)
	{
		printTreeLeft(node->right);
	}
}

void printTreeMid( BTree* node )
{
	printNode(node->node);
	if (node->left)
	{
		printTreeMid(node->left);
	}
	if (node->right)
	{
		printTreeMid(node->right);
	}
}

void printTreeRight( BTree* node )
{
	if (node->right)
	{
		printTreeRight(node->right);
	}
	printNode(node->node);
	if (node->left)
	{
		printTreeRight(node->left);
	}
}

BTree* addLeftChild( BTree* node, NodeL* data )
{
	if (!node || !data)
	{
		return NULL;
	}
	if (node->left)
	{
		printf("node has its left child already! \n");
		return NULL;
	}
	int len = sizeof(BTree);
	BTree* item = (BTree*) malloc(len);
	item->left = NULL;
	item->right = NULL;
	item->parent = node;
	node->left = item;

	item->node = data;
	return item;
}

BTree* addRightChild( BTree* node, NodeL* data )
{
	if (!node || !data)
	{
		return NULL;
	}
	if (node->right)
	{
		printf("node has its right child already! \n");
		return NULL;
	}
	int len = sizeof(BTree);
	BTree* item = ( BTree*)malloc(len);
	item->left = NULL;
	item->right = NULL;
	item->parent = node;
	node->right = item;

	item->node = data;
	return item;
}
