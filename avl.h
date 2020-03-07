#ifndef AVL_H
#define AVL_H

#include "utility.h"

typedef struct AVLNode
{
	Team *team;
	struct AVLNode *left;
	struct AVLNode *right;
	int height;
} AVLNode;

int max(int a, int b);

int height(AVLNode *node);

AVLNode* createAVLNode(Team *team);

AVLNode* rightRotate(AVLNode *y);

AVLNode* leftRotate(AVLNode *x);

int getBalance(AVLNode *node);

AVLNode *insertAVLNode(AVLNode *root, Team *team);

void printGivenLevel(AVLNode *root, int level, FILE *file);

#endif