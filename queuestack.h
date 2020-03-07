#ifndef QUEUESTACK_H
#define QUEUESTACK_H

#include "utility.h"

typedef struct Game 
{					
	Team *TeamA;	
	Team *TeamB;
} Game;

typedef struct GameList
{
	Game *Game;
	struct GameList *next;
} GameList;

typedef struct Queue
{
	GameList *front;
	GameList *rear;
} Queue;

typedef struct Stack
{
	Team *Team;
	struct Stack *next;
} Stack;

void push(Stack **top, Team *Team);

int isStackEmpty(Stack *top);

Team* pop(Stack **top);

Queue* createQueue();

void enQueue(Queue *q, Game *Game);

int isQueueEmpty(Queue *q);

Game* deQueue(Queue *q) ;

Team* Winner(Game *Game);

int countStack(Stack *top);

void DisplayQueue(Queue *q, Stack **topWin, Stack **topLose, FILE *file);

void DeleteStack(Stack **top);

void DisplayStack(Stack **top, Queue *q, FILE *file);

#endif