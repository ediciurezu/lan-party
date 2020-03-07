#include "bst.h"

BSTNode* createNode(Team *value)
{
	BSTNode *newNode = (BSTNode*)malloc(sizeof(BSTNode));

	newNode->Team = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

BSTNode* insertNode(BSTNode *root, Team *data)
{
	if (root == NULL) return createNode(data);

	if (Points(data) < Points(root->Team))
		root->left = insertNode(root->left, data);

	if (Points(data) > Points(root->Team))
		root->right = insertNode(root->right, data);

	return root;
} 

void inOrder(BSTNode *root, FILE *file)
{
	if (root == NULL) return;

	inOrder(root->right, file);
	fprintf(file, "%-20s -- %.2f\n", root->Team->name, Points(root->Team));
	inOrder(root->left, file);
}