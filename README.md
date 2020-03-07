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
receive as a parameter a pointer to a team and releases the memory used for
the players and the respective team

* `void AddPoints(Team **team)`
add players from a team one more point in the xp field

* `float Points(Team *Team)`
return the score of a team sent as a parameter

* `void TestAlloc(void *p)`
check if memory is correctly allocated to a pointer

* `void CreateTeamList(Team **head, int *numTeam, char *filename)`
read from the file "filename" a given number of teams, allocate memory and add
at the beginning of a singly linked list

* `int MaxPower(int numTeams)`
return the max power of 2 less than a given number. Start shifting the bits
to the left until the number exceeds the given value and return the
immediately preceding value

* `float MinPoints(Team *head)`
receive as parameter the head of a singly linked list and return the minimum
score of the teams in it

* `void DeleteTeam(Team **head, Team *p)`
remove a team from a singly linked list by its address

* `void KillLowTeams(Team **head, int *numTeams)`
calculate at each step the minimum of the scores from a singly linked list and
eliminate the teams until the highest power of 2 is reached. The list behaves
like a circular list and elimination it is done by first checking the head,
then continuing from the last eliminated minimum.

* `void DisplayTeam(Team *head, FILE *file)`
display the names of the teams from a singly linked list in a given file

* `void Requests(int *req, char *filename)`
encode the requirements from the given file into a vector

* `void DeleteList(Team **head)`
free the memory from the singly linked list

### queuestack.h
* `void push(Stack **top, Team *Team)`
add a team to the stack

* `int isStackEmpty(Stack *top)`
return 1 if the stack is empty and 0 if it is not

* `Team* pop(Stack **top)`
remove a team from the stack and return it

* `Queue* createQueue()`
create the queue

* `void enQueue(Queue *q, Game *Game)`
add a game to the queue

* `int isQueueEmpty(Queue *q)`
return 1 if the queue is empty and 0 if it is not

* `Game* deQueue(Queue *q)`
remove a game from the queue and return it

* `Team* Winner(Game *Game)`
return the winning team from a game (depending on the score)

* `int countStack(Stack *top)`
return the size of the stack

* `void DisplayQueue(Queue *q, Stack **topWin, Stack **topLose, FILE *file)`
display the queue games in a file and add the winning teams in a stack,
respectively the losing teams in another stack received as parameters

* `void DeleteStack(Stack **top)`
frees the memory of the stack

* `void DisplayStack(Stack **top, Queue *q, FILE *file)`
display in a file the name and score of the teams in a stack and add them in a
queue

### bst.h
* `BSTNode* createNode(Team *value)`
create a node in BST with a pointer to a team sent as a parameter

* `BSTNode* insertNode(BSTNode *root, Team *data)`
ddd in the BST a node with a pointer to a team

* `void inOrder(BSTNode *root, FILE *file)`
display in a file the BST traversal inorder (Right-Root-Left)

### avl.h

* `int max(int a, int b)`
return the maximum between two integers

* `AVLNode* createAVLNode(Team *team)`
create a node in AVL with a pointer to a team sent as a parameter

* `AVLNode* rightRotate(AVLNode *y)`
make the right rotation in a node

* `AVLNode* leftRotate(AVLNode *x)`
make the left rotation in a node

* `int getBalance(AVLNode *node)`
return the difference between the height of the left subtree and the height of
the right subtree

* `AVLNode *insertAVLNode(AVLNode *root, Team *team)`
add in AVL a node with a pointer to a team

* `void printGivenLevel(AVLNode *root, int level, FILE *file)`
display in a file the nodes on a lovel of an AVL
