# AVL tree Algorithm
C++ Implementation of AVL Trees

You are required to implement the following functionalities in C++:
1. Binary Tree Traversal
2. AVL Tree Insertion and Deletion

You should begin your program by initializing an empty AVL tree. The program will read a single line of input. This input line will consist of n "modification moves" separated by spaces, where n is between 1 and 100 (1 <= n <= 100). The possible modification moves are:

1. `Aint` (Character 'A' followed by an integer value between 1 and 100): For instance, `A3` indicates the insertion of the value 3 into the AVL tree. If the value 3 is already present in the tree, no action is taken.
2. `Dint` (Character 'D' followed by an integer value between 1 and 100): For instance, `D3` means that the value 3 should be deleted from the AVL tree. If the value 3 is not in the tree, no action is taken.

Following the modification moves, there will be exactly one finishing move: `PRE`, `POST`, or `IN`.

1. If the finishing move is `PRE`, you should print the tree's current state in pre-order traversal.
2. If the tree is empty, you should print `EMPTY`.
3. Otherwise, print the values in the traversal order, separated by spaces. The handling of `POST` and `IN` is similar.

In summary, your task is to implement AVL tree operations for insertion and deletion based on the input moves. After applying the modifications, you'll perform a requested tree traversal and print the corresponding output.

You can assume that the inputs will be valid. Your goal is to implement the described AVL tree operations and produce the requested traversal results.
  
		Sample input 1: A1 A2 A3 IN
		Sample output 1: 1 2 3
		Sample input 2: A1 A2 A3 PRE
		Sample output 2: 2 1 3
		Sample input 3: A1 D1 POST
		Sample output 3: EMPTY
