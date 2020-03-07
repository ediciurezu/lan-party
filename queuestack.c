#include "queuestack.h"

void push(Stack **top, Team *Team)
{
	Stack *newStack;
	newStack = (Stack*)malloc(sizeof(Stack));

	newStack->Team = Team;
	newStack->next = *top;

	*top = newStack;
}

int isStackEmpty(Stack *top)
{
	return top == NULL;
}

Team* pop(Stack **top)
{
	if (isStackEmpty(*top))  return NULL;

	Stack *temp = *top;

	Team *aux = temp->Team;

	*top = (*top)->next;
	free(temp);

	return aux;
}

Queue* createQueue()
{
	Queue *q;

	q = (Queue*)malloc(sizeof(Queue));

	if (q == NULL) return NULL;

	q->front = q->rear = NULL;

	return q;
}

void enQueue(Queue *q, Game *Game)
{
	GameList *newGame = (GameList*)malloc(sizeof(GameList));
	newGame->Game = Game;
	newGame->next = NULL;

	if (q->rear == NULL)
		q->rear = newGame;
	else
	{
		q->rear->next = newGame;
		q->rear = newGame;
	}

	if (q->front == NULL) q->front = q->rear;
}

int isQueueEmpty(Queue *q)
{
	return q->front == NULL;
}

Game* deQueue(Queue *q) 
{
	Game *data = NULL;
	GameList *newGame;

	if (isQueueEmpty(q)) return NULL;

	newGame = q->front;
	data = newGame->Game;
	q->front = q->front->next;
	free(newGame);

	return data;
}

Team* Winner(Game *Game)
{
	if (Points(Game->TeamA) >= Points(Game->TeamB)) return Game->TeamA;
	else return Game->TeamB;
}

int countStack(Stack *top)
{
	int count = 0;

	while(!isStackEmpty(top))
	{
		top = top->next;
		count++;
	}

	return count;
}

void DisplayQueue(Queue *q, Stack **topWin, Stack **topLose, FILE *file)
{
	Game *temp;

	if (q->front == q->rear)
	{
		temp = deQueue(q);

		if (temp->TeamA == Winner(temp)) 
		{
			AddPoints(&temp->TeamA);
			push(topWin, temp->TeamA);
			push(topLose, temp->TeamB);
		}

		else
		{
			AddPoints(&temp->TeamB);
			push(topWin, temp->TeamB);
			push(topLose, temp->TeamA);
		}

		fprintf(file, "%-25s -- %25s\n", temp->TeamA->name, temp->TeamB->name);

		q->front = q->rear = NULL;
	}

	else
	{
		while(!isQueueEmpty(q))
		{
			temp = deQueue(q);

			if (temp->TeamA == Winner(temp)) 
			{
				AddPoints(&temp->TeamA);
				push(topWin, temp->TeamA);
				push(topLose, temp->TeamB);
			}

			else
			{
				AddPoints(&temp->TeamB);
				push(topWin, temp->TeamB);
				push(topLose, temp->TeamA);
			}

			fprintf(file, "%-25s -- %25s\n", temp->TeamA->name, temp->TeamB->name);
		}
	}
}

void DeleteStack(Stack **top)
{
	Stack *temp;

	while (!isStackEmpty(*top))
	{
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}

void DisplayStack(Stack **top, Queue *q, FILE *file)
{
	Team *temp1, *temp2 ;
	Game *newGame;

	if (q->front == q->rear)
	{
		fprintf(file, "%-25s --- %.2f\n", (*top)->Team->name, Points((*top)->Team));
	}

	else
	{
		while (!isStackEmpty(*top))
		{
			temp1 = pop(top);
			temp2 = pop(top);

			newGame = (Game*)malloc(sizeof(Game));

			newGame->TeamA = temp1;
			newGame->TeamB = temp2;

			enQueue(q, newGame);


			fprintf(file, "%-25s --- %.2f\n", temp1->name, Points(temp1));
			fprintf(file, "%-25s --- %.2f\n", temp2->name, Points(temp2));
		}
	}


}