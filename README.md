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
*'c if (a == b) return a'

