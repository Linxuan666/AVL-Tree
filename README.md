# AVL tree Algorithm
C++ Implementation of AVL Trees
1.Task Description: 
		You are asked to use C++ to implement:
		1) Binary Tree Traversal
		2) AVL Tree Insertion and Deletion
	2.Submission Guideline:
		You should start your program by initializing an empty AVL tree. 
		Your program takes one line as input. 
		The input line contains n "modification moves" separated by spaces (1 <= n <= 100). 
		The available modification moves are:
			1) Aint (Character A followed by an int value between 1 and 100): A3 means insert value 3 into the AVLtree. 
			   If 3 is already in the tree, do nothing.
			2) Dint (Character D followed by an int value between 1 and 100): D3 means delete value 3 into the AVL tree. 
			   If 3 is not in the tree, do nothing.
		Your input is then followed by exactly one nishing move (PRE or POST or IN): 
			1) If the finishing move is PRE, then you should print out the tree (in its current situation) in pre-order. 
			2) If the tree is empty, print out EMPTY. 
			3) Otherwise, print out the values separated by spaces. POST and IN are handled similarly.
		You don't need to worry about invalid inputs.
		Sample input 1: A1 A2 A3 IN
		Sample output 1: 1 2 3
		Sample input 2: A1 A2 A3 PRE
		Sample output 2: 2 1 3
		Sample input 3: A1 D1 POST
		Sample output 3: EMPTY
