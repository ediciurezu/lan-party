#ifndef BST_H
#define BST_H

#include "utility.h"

typedef struct BSTNode
{
	Team *Team;
	struct BSTNode *left;
	struct BSTNode *right;
} BSTNode;

BSTNode* createNode(Team *value);

BSTNode* insertNode(BSTNode *root, Team *data);

void inOrder(BSTNode *root, FILE *file);

#endif