#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define EPSILON 0.000001

typedef struct Player
{
	char *last_name;
	char *first_name;
	int xp;
} Player;

typedef struct Team
{
	char *name;
	int numPlayers;
	Player *players;
	struct Team *next;
} Team;

void freeTeam(Team *team);

void AddPoints(Team **Team);

float Points(Team *Team);

void TestAlloc(void *p);

void CreateTeamList(Team **head, int *numTeams, char *filename);

int MaxPower(int numTeams);

float MinPoints(Team *head);

void DeleteTeam(Team **head, Team *p);

void KillLowTeams(Team **head, int *numTeams);

void DisplayTeam(Team *head, FILE *file);

void Requests(int *req, char *filename);

void DeleteList(Team **head);