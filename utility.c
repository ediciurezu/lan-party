#include "utility.h"

void freeTeam(Team *team)
{
	int i;

	free(team->name);
		for (i = 0; i < team->numPlayers; i++)
			{
				free(team->players[i].last_name);
				free(team->players[i].first_name);
			}
		free(team->players);
		free(team);
}

void AddPoints(Team **Team)
{
	int i;

	for (i = 0; i < (*Team)->numPlayers; i++)
		(*Team)->players[i].xp += 1;	
}

float Points(Team *Team)
{
	int i, S = 0;
	float points;

	for (i = 0; i < Team->numPlayers; i++)
		S += Team->players[i].xp;

	points = (float) S / Team->numPlayers;

	return points;
}

void TestAlloc(void *p)
{
	if (p == NULL)
	{
		fprintf(stderr, "Alocarea memoriei a esuat!\n");
		exit(1);
	}
}

void CreateTeamList(Team **head, int *numTeams, char *filename)
{
	Team *temp = NULL;
	FILE *f = fopen(filename, "rt");

	fscanf(f, "%d", numTeams);

	for (int i = 0; i < *numTeams; i++)
	{
		temp = (Team*)malloc(sizeof(Team));
		TestAlloc((Team*)temp);

		fscanf(f, "%d", &temp->numPlayers); 
		temp->name = (char*)malloc(50);
		TestAlloc((char*)temp->name);

		fscanf(f, "%[^\n]s", temp->name);
		temp->name = (char*)realloc(temp->name, strlen(temp->name) + 1);

		temp->players = (Player*)malloc(temp->numPlayers * sizeof(Player));
		TestAlloc((Player*)temp->players);

		for (int j = 0; j < temp->numPlayers; j++)
			{
				temp->players[j].last_name = (char*)malloc(50);
				TestAlloc((char*)temp->players[j].last_name);

				temp->players[j].first_name = (char*)malloc(50);
				TestAlloc((char*)temp->players[j].first_name);

				fscanf(f, "%s", temp->players[j].last_name); 
				temp->players[j].last_name = (char*)realloc(temp->players[j].last_name, strlen(temp->players[j].last_name) + 1);

				fscanf(f, "%s", temp->players[j].first_name); 
				temp->players[j].first_name = (char*)realloc(temp->players[j].first_name, strlen(temp->players[j].first_name) + 1);

				fscanf(f, "%d", &temp->players[j].xp); 
			}
		temp->next = NULL;

		if (*head == NULL)
		{
			*head = temp;
		}
		else
		{
			temp->next = *head;
		}
		*head = temp;
	}

	fclose(f);
}

int MaxPower(int numTeams)
{
	int pow = 1;

	while (pow <= numTeams)
		pow <<= 1;

	return pow >> 1;
}

float MinPoints(Team *head)
{
	Team *idx;

	float minPoints = Points(head);

	for (idx = head->next; idx != NULL; idx = idx->next)
		if (Points(idx) < minPoints) minPoints = Points(idx);

	return minPoints;
}

void DeleteTeam(Team **head, Team *p)
{
	Team *temp;

	temp = *head;

	if (p == *head)
	{
		*head = temp->next;
		freeTeam(temp);
		return;
	}

	while (temp->next != p)
	{
		temp = temp->next;
	}

	temp->next = p->next;
	freeTeam(p);
}

void KillLowTeams(Team **head, int *numTeams)
{
	Team *idx;
	int pow;
	float minPoints;

	pow = MaxPower(*numTeams);

	idx = *head;

	while (pow < *numTeams) 
	{
		minPoints = MinPoints(*head);

		if (fabs(Points(*head) - minPoints) < EPSILON) 
		{
			idx = *head;
			(*numTeams)--;
			DeleteTeam(head, idx);
			idx = idx->next;
			if (idx == NULL) idx = *head;
			continue;
		}

		if (fabs(Points(idx) - minPoints) < EPSILON) { (*numTeams)--; DeleteTeam(head, idx); }

		idx = idx->next;
		if (idx == NULL) idx = *head;

	}
}

void DisplayTeam(Team *head, FILE *file)
{
	Team *temp;

	for (temp = head; temp != NULL; temp = temp->next)
		fprintf(file, "%s\n", temp->name);
}

void Requests(int *req, char *filename)
{
	FILE *f = fopen(filename, "rt");

	int i;

	for (i = 0; i < 5; i++)
		fscanf(f, "%d", &req[i]);

	fclose(f);
}

void DeleteList(Team **head)
{
	Team *temp;

	while (*head!=NULL)
	{
		temp = *head;
		*head = (*head)->next;
		freeTeam(temp);
	}
}