#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

//define Node class
class Node {
	public:
		int key;
		Node* left;
		Node* right;
		Node(int k):key(k),left(nullptr),right(nullptr) {}
};

//define AVLTree class
class AVLTree {
	private:
		Node* LL_Rotation(Node* root);
		Node* RR_Rotation(Node* root);
		Node* RL_Rotation(Node* root);
		Node* LR_Rotation(Node* root);
		int getheight(Node* root);
		int diff(Node* root);
		Node* balance(Node* root);
		Node* findMax(Node* root);

	public:
		Node* avlroot;
		AVLTree() { avlroot = nullptr; } 
		Node* insertNode(Node* root, int k);
		Node* deleteNode(Node* root, int k);
		bool isEmptyTree(Node* root);
		void preOrder(Node* root);
		void inOrder(Node* root);
		void postOrder(Node* root);
};

//Left Rotation
Node* AVLTree::LL_Rotation(Node* root) {
	Node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return temp;
}

//Right Rotation
Node* AVLTree::RR_Rotation(Node* root) {
	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp;
}

//Right-Left Rotation
Node* AVLTree::RL_Rotation(Node* root) {
	root->right = LL_Rotation(root->right);
	return RR_Rotation(root);
}

//Left-Right Rotation
Node* AVLTree::LR_Rotation(Node* root) {
	root->left = RR_Rotation(root->left);
	return LL_Rotation(root);
}

//calculate the height of root
int AVLTree::getheight(Node* root) {
	if (root == nullptr) return 0;
	return max(getheight(root->left), getheight(root->right)) + 1;
}

//calculate height difference between left and right child
int AVLTree::diff(Node* root) {
	if (root == nullptr) return 0;
	return getheight(root->left) - getheight(root->right);
}

//balance the tree
Node* AVLTree::balance(Node* root) {
	if (diff(root) > 1) {
		if (diff(root->left) >= 0)
			root = LL_Rotation(root);
		else
			root = LR_Rotation(root);
	}
	else if (diff(root) < -1) {
		if (diff(root->right) <= 0)
			root = RR_Rotation(root);
		else
			root = RL_Rotation(root);
	}
	return root;
}

//insert a key in AVL tree
Node* AVLTree::insertNode(Node* root,int k) {
	if (root == nullptr) {
		root = new Node(k);
		return root;
	}
	if (k < root->key) {
		root->left = insertNode(root->left, k);
		root = balance(root);
		return root;
	}
	else if (k > root->key) {
		root->right = insertNode(root->right, k);
		root = balance(root);
		return root;
	}
	else {
		return root;
	}
}

//find maximum of the tree
Node* AVLTree::findMax(Node* root) {
	if (root == nullptr || root->right == nullptr) {
		return root;
	}
	else {
		return findMax(root->right);
	}
}

//delete a key from AVL tree
Node* AVLTree::deleteNode(Node* root, int k) {
	if (root == nullptr) {
		return root;
	}
	if (k < root->key) {
		root->left = deleteNode(root->left, k);
		root = balance(root);
		return root;
	}
	else if (k > root->key) {
		root->right = deleteNode(root->right, k);
		root = balance(root);
		return root;
	}
	else {
		// case 1: the node has no children or only one child
		if (root->left == nullptr || root->right == nullptr) {
			Node* temp = root->left ? root->left : root->right;
			// if the node has no children
			if (temp == nullptr) {
				temp = root;
				root = nullptr;
			}
			// if the node has one child
			else {
				*root = *temp;
			}
			delete temp;
		}
		// case 2: the node has two children
		else {
			Node* temp = findMax(root->left);
			root->key = temp->key;
			root->left = deleteNode(root->left, temp->key);
		}
		root = balance(root);
		return root;
	}
}

// preorder traversal "AVL tree"
void AVLTree::preOrder(Node* root) {
	if (root == nullptr) return;
	cout << root->key << ' ';
	preOrder(root->left);
	preOrder(root->right);
}

// inorder traversal "AVL tree"
void AVLTree::inOrder(Node* root) {
	if (root == nullptr) return;
	inOrder(root->left);
	cout << root->key << ' ';
	inOrder(root->right);
}

// Postorder traversal "AVL tree"
void AVLTree::postOrder(Node* root) {
	if (root == nullptr) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->key << ' ';
}

//determine whether the tree is empty
bool isEmptyTree(Node* root) {
	if (root == nullptr) {
		return true;
	}
	else return false;
}

//process the input string of user, set AVL tree and print the traversal of tree finally
int main() {
	string str;
	getline(cin, str);  
	stringstream ss(str);  
	AVLTree tree;
	string word;
	while (ss >> word) {
		if (word[0] == 'A') {
			int i = stoi(word.substr(1));
			tree.avlroot = tree.insertNode(tree.avlroot, i); 
		}
		else if (word[0] == 'D') {
			int i = stoi(word.substr(1));
			tree.avlroot = tree.deleteNode(tree.avlroot, i);
		}
		else {
			if (isEmptyTree(tree.avlroot)) {
				cout << "EMPTY";
			}
			else {
				if (word == "IN") {
					tree.inOrder(tree.avlroot);
				}
				else if (word == "PRE") {
					tree.preOrder(tree.avlroot);
				}
				else if (word == "POST") {
					tree.postOrder(tree.avlroot);
				}
				else {
					cout << "Error of Output Type";
				}
			}
		}
	}
	return 0;
}
