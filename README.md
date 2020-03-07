# Lan Party
## Solution Description
The first step is to read the files and create a singly linked list through
adding each team to the top of the list. We make the list to behave like a
circular one, at each step we look for the minimum number of points in the list
and eliminate the team which score is equal to the minimum. We continue the
eliminations until the number of teams becomes equal to the power of 2
previously found. The next step is to create one queues of games and two stacks
of teams. The list from the previous step is loaded in the tail in the form of
games, represented by two teams. The two teams in each game will be processed
and transmitted to stacks, one of the winners, respectively the one of the
losers. The winning teams will be loaded back into the queue and through
successive calls, until the existence of a single match in the queue, will have
the final winner. At the moment the stack of winners will count 8 elements,
these will be transmitted to another stack, called "ranking". By pop from the
stack respective teams will be inserted as nodes in a Binary Search Tree. In
the finally, an inorder traversal will be made (Right-Root-Left) for displaying
the ranking of the 8 teams in descending order. The same principle that
earlier, the AVL will be created, the teams in the ranking stack will be
inserted as nodes in AVL and we will display the second level of this data
structure.

## Headers
* utility.h
* queuestack.h
* bst.h
* avl.h

## Explanation of functions
### utility.h
* `void freeTeam(Team *team)`
Receives as a parameter a pointer to a team and releases the memory used for
the players and the respective team

* `void AddPoints(Team **team)`
Add players from a team one more point in the xp field

* `float Points(Team *Team)`
Returns the score of a team sent as a parameter

* `void TestAlloc(void *p)`
Check if memory is correctly allocated to a pointer

* `void CreateTeamList(Team **head, int *numTeam, char *filename)`
Read from the file "filename" a given number of teams, allocate memory and add
at the beginning of a singly linked list

* `int MaxPower(int numTeams)`
Returns the max power of 2 less than a given number. Starts shifting the bits
to the left until the number exceeds the given value and returns the
immediately preceding value

* `float MinPoints(Team *head)`
Receives as parameter the head of a singly linked list and returns the minimum
score of the teams in it

* `void DeleteTeam(Team **head, Team *p)`
Remove a team from a singly linked list by its address

* `void KillLowTeams(Team **head, int *numTeams)`
Calculate at each step the minimum of the scores from a singly linked list and
eliminate the teams until the highest power of 2 is reached. The list behaves
like a circular list and elimination it is done by first checking the head,
then continuing from the last eliminated minimum.

* `void DisplayTeam(Team *head, FILE *file)`
Displays the names of the teams from a singly linked list in a given file

* `void Requests(int *req, char *filename)`
Encodes the requirements from the given file into a vector

* `void DeleteList(Team **head)`
Frees the memory from the singly linked list

