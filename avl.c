#include "avl.h"

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int height(AVLNode *node)
{
	if (node == NULL)
		return 0;

	return node->height;
}

AVLNode* createAVLNode(Team *team)
{
	AVLNode *newNode = (AVLNode*)malloc(sizeof(AVLNode));

	newNode->team = team;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;

	return newNode;
}

AVLNode* rightRotate(AVLNode *y)
{
	AVLNode *x  = y->left;
	AVLNode *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

AVLNode* leftRotate(AVLNode *x)
{
	AVLNode *y = x->right;
	AVLNode *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;

}

int getBalance(AVLNode *node)
{
	if (node == NULL)
		return 0;

	return height(node->left) - height(node->right);
}

AVLNode *insertAVLNode(AVLNode *root, Team *team)
{

	if (root == NULL)
		return createAVLNode(team);

	if (Points(team) < Points(root->team))
		root->left = insertAVLNode(root->left, team);
	else if (Points(team) > Points(root->team))
		root->right = insertAVLNode(root->right, team);
	else
		return root;

	root->height = 1 + max(height(root->left), height(root->right));

	int balance = getBalance(root);

	//Left Left Case
	if (balance > 1 && Points(team) < Points(root->left->team))
		return rightRotate(root);

	//Right Right Case
	if (balance < -1 && Points(team) > Points(root->right->team))
		return leftRotate(root);

	//Left Right Case
	if (balance > 1 && Points(team) > Points(root->left->team))
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	//Right Left Case
	if (balance < -1 && Points(team) < Points(root->right->team))
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void printGivenLevel(AVLNode *root, int level, FILE *file)
{
	if (root == NULL)
		return;

	if (level == 0)
		fprintf(file, "%-20s -- %.2f\n", root->team->name, Points(root->team));
	else if (level > 0)
	{
		printGivenLevel(root->left, level - 1, file);
		printGivenLevel(root->right, level - 1, file);
	}
}
