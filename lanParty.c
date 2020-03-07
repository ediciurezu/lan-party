#include "queuestack.h"
#include "bst.h"
#include "avl.h"
#include "utility.h"

int main(int argc, char **argv)
{
	FILE *g = fopen(argv[3], "wt");

	Team *head = NULL;
	int numTeams;
	int *req;
	req = (int*)malloc(5 * sizeof(int));
	TestAlloc((int*)req);

	Requests(req, argv[1]);

	CreateTeamList(&head, &numTeams, argv[2]);

	Queue *q;
	Stack *win = NULL, *lose = NULL, *copy = NULL;
	Team *idx;
	Game *Game1;

	Stack *ranking = NULL;

	if (req[0] == 1 && req[1] == 0)
		DisplayTeam(head, g);

	if (req[1] == 1)
	{
		KillLowTeams(&head, &numTeams);
		DisplayTeam(head, g);
	}

	if (req[2] == 1)
	{
		q = createQueue();

		for (idx = head; idx != NULL; idx = idx->next->next)
		{
			Game1 = (Game*)malloc(sizeof(Game));
			Game1->TeamA = idx;
			Game1->TeamB = idx->next;
			enQueue(q, Game1);
		}

		while (q->front != NULL)
			{
				DisplayQueue(q, &win, &lose, g);
				DeleteStack(&lose);

				if(countStack(win) == 8)
				{
					copy = win;
					while (copy != NULL)
					{
						push(&ranking, copy->Team);
						copy = copy->next;
					}
				}


				DisplayStack(&win, q, g);
			}
	}
			
	if (req[3] == 1 && req[4] == 0)
	{

		BSTNode *root = NULL;

		for (int i = 0; i < 8; i++)
		{
			root = insertNode(root, ranking->Team);
			ranking = ranking->next;
		}
		inOrder(root, g);
			
		DeleteStack(&ranking);
	}

	if (req[4] == 1)
	{

		AVLNode *rootAVL = NULL;

		for (int i = 0; i < 8; i++)
		{
			rootAVL = insertAVLNode(rootAVL, ranking->Team);
			ranking = ranking->next;
		}
		printGivenLevel(rootAVL, 2, g);
			
		DeleteStack(&ranking);
	}

	DeleteList(&head);
	fclose(g);

	return 0;
}
