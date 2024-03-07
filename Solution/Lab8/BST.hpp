#include "Lab8.hpp"
#include "BSTNode.hpp"

template <typename T>
class BST {

private:

	/// <summary>
	/// A pointer to the root node of the tree.
	/// </summary>
	BSTNode<T>* pRoot;

	/// -- PRIVATE FUNCTIONS -- //

	/// <summary>
	/// Determines if tree is empty.
	/// </summary>
	/// <returns>True if empty; false if not.</returns>
	bool isEmpty() {

		return pRoot == nullptr;
	}

	/// <summary>
	/// Recursively inserts a node into the tree.
	/// </summary>
	/// <param name="pCur">The current node in the tree.</param>
	/// <param name="nKey">The key to insert</param>
	bool insert(BSTNode<T>* pCur, T nKey) {

		if (nKey == pCur->getKey()) { // key already in tree

			return false;
		}
		else if (nKey < pCur->getKey()) { // check for left insertion

			if (pCur->getLeft() == nullptr) { // left pointer is null

				pCur->setLeft(nKey);
				depth(pCur);
				return true;
			}
			depth(pCur);

			return insert(pCur->getLeft(), nKey); // recurive insert call
		}
		else { // right insertion

			if (pCur->getRight() == nullptr) { // right pointer is null

				pCur->setRight(nKey);
				depth(pCur);
				return true;
			}
			depth(pCur);

			return insert(pCur->getRight(), nKey);
		}
	}

	/// <summary>
	/// Recursively calculates the depth of the tree.
	/// </summary>
	/// <param name="pCur">The root node of the current sub-tree.</param>
	/// <returns>The depth of the sub-tree.</returns>
	int depth(BSTNode<T>* pCur) {

		if (pCur == nullptr) { // we reached the end of a sub-tree

			return 0;
		}

		int leftDepth = 1 + depth(pCur->getLeft());
		int rightDepth = 1 + depth(pCur->getRight());

		if (leftDepth >= rightDepth) {

			pCur->setHeight(leftDepth);
			return leftDepth;
		}

		pCur->setHeight(rightDepth);
		return rightDepth;
	}

	/// <summary>
	/// Recursively prints the tree in ascending order.
	/// </summary>
	/// <param name="lhs">The stream to output to.</param>
	/// <param name="rhs">The current node being output.</param>
	void printInOrder(std::ostream& lhs, const BSTNode<T>* rhs) const {

		if (rhs != nullptr) {

			printInOrder(lhs, rhs->getLeft()); // print left sub-tree

			lhs << *rhs << " "; // insert this to stream

			printInOrder(lhs, rhs->getRight()); // print right sub-tree
		}
	}

	/// <summary>
	/// Recursively prints the tree in ascending order.
	/// </summary>
	/// <param name="pCur">The current node being output.</param>
	void printInOrder(const BSTNode<T>* pCur) const {

		if (pCur != nullptr) {

			printInOrder(pCur->getLeft()); // print left sub-tree

			std::cout << *pCur << " "; // insert this to stream

			printInOrder(pCur->getRight()); // print right sub-tree
		}
	}

	/// <summary>
	/// Recursively prints the tree in pre order.
	/// </summary>
	/// <param name="pCur">The current node being output.</param>
	void printPreOrder(const BSTNode<T>* pCur) const {

		if (pCur != nullptr) {

			std::cout << *pCur << " "; // insert this to stream

			printPreOrder(pCur->getLeft()); // print left sub-tree

			printPreOrder(pCur->getRight()); // print right sub-tree
		}
	}

	/// <summary>
	/// Recursively prints the tree in post order.
	/// </summary>
	/// <param name="pCur">The current node being output.</param>
	void printPostOrder(const BSTNode<T>* pCur) const {

		if (pCur != nullptr) {

			printPostOrder(pCur->getLeft()); // print left sub-tree

			printPostOrder(pCur->getRight()); // print right sub-tree

			std::cout << *pCur << " "; // insert this to stream
		}
	}

	/// <summary>
	/// Reursive helper function for deleting all nodes in the tree.
	/// </summary>
	/// <param name="pCur">The current node to delete.</param>
	void destroyTree(BSTNode<T>* pCur) {

		if (pCur != nullptr) {

			destroyTree(pCur->getLeft()); // destroy left sub-tree
			destroyTree(pCur->getRight()); // destroy right sub-tree
			delete (pCur);
		}
	}

	/// <summary>
	/// Recursive helper function for printing a tree in level order.
	/// </summary>
	/// <param name="pCur">The current node to check.</param>
	/// <param name="level">The level height to output.</param>
	void printLevelOrder(BSTNode<T>* pCur, int level) {

		if (pCur == nullptr || level < 0) { // can't print a nullptr

			return;
		}
		else if (level == 0) {
			
			std::cout << *pCur << " ";
			return;
		}
		else {

			printLevelOrder(pCur->getLeft(), level - 1);
			printLevelOrder(pCur->getRight(), level - 1);
		}
	}

	/// <summary>
	/// Recursive helper function for counting amount of nodes in the tree.
	/// </summary>
	/// <param name="pCur">The current node to process.</param>
	/// <returns>The number of nodes in the subtree.</returns>
	int countNodes(BSTNode<T>* pCur) {

		if (pCur == nullptr) { // we reached end of leaf

			return 0;
		}

		return 1 + countNodes(pCur->getLeft()) + countNodes(pCur->getRight());
	}

	/// <summary>
	/// Dynamically fills an array with the contents of the node.
	/// </summary>
	/// <param name="pCur">The current node to process.</param>
	/// <param name="n">The current index to be filled.</param>
	/// <param name="array">The array being filled.</param>
	/// <returns>The next index to fill.</returns>
	int fillArray(BSTNode<T>* pCur, int n, T* array) {

		if (pCur == nullptr) { // don't update n if we reached a leaf

			return n;
		}

		// fill left first
		n = fillArray(pCur->getLeft(), n, array);
		
		// store this data
		array[n++] = pCur->getKey();

		// fill right last
		n = fillArray(pCur->getRight(), n, array);

		return n;		
	}

	/// <summary>
	/// Prints the tree in ascending order.
	/// </summary>
	/// <param name="lhs">The stream to output to.</param>
	/// <param name="rhs">The tree to traverse.</param>
	/// <returns></returns>
	friend std::ostream& operator<<(std::ostream& lhs, const BST<T>& rhs) {

		rhs.printInOrder(lhs, rhs.getRoot());
		return lhs;
	}

public:

	/// -- CONSTRUCTORS -- ///

	/// <summary>
	/// Default constructor; intializes pRoot to nullptr.
	/// </summary>
	BST() {

		pRoot = nullptr;
	}

	/// -- DESTRUCTORS -- ///

	/// <summary>
	/// Destroys the object.
	/// </summary>
	~BST() {

		destroyTree();
	}

	/// -- GETTERS -- //

	/// <summary>
	/// Gets the root pointer.
	/// </summary>
	/// <returns>A reference to the root pointer.</returns>
	BSTNode<T>* getRoot() const {

		return pRoot;
	}

	/// -- PUBLIC MEMBER FUNCTIONS -- //

	/// <summary>
	/// Inserts a new node into the tree.
	/// </summary>
	/// <param name="nKey">The key to insert.</param>
	/// <returns>False when key already existed; true when inserted succesfully.</returns>
	bool insert(T nKey) {

		if (isEmpty()) { // inserting into empty tree

			pRoot = new BSTNode<T>(nKey);
			return true;
		}

		return insert(pRoot, nKey);
	}

	/// <summary>
	/// Finds the max depth of this tree.
	/// </summary>
	/// <returns>Returns the max depth.</returns>
	int depth() {

		return depth(pRoot);
	}

	/// <summary>
	/// Prints the tree in ascending order.
	/// </summary>
	void printInOrder() {

		printInOrder(pRoot);
	}

	/// <summary>
	/// Prints the tree in pre order.
	/// </summary>
	void printPreOrder() {

		printPreOrder(pRoot);
	}

	/// <summary>
	/// Prints the tree in post order.
	/// </summary>
	void printPostOrder() {

		printPostOrder(pRoot);
	}

	/// <summary>
	/// Deallocates all nodes currently in the tree.
	/// </summary>
	void destroyTree() {

		destroyTree(pRoot);
		pRoot = nullptr;
	}

	/// <summary>
	/// Prints each level of the tree on it's own line.
	/// </summary>
	void printLevelOrder() {

		for (int i = 0; i <= pRoot->getHeight(); i++) { // loop for each level in tree

			printLevelOrder(pRoot, i);
			std::cout << std::endl;
		}
	}


	/// <summary>
	/// Counts the amount of nodes stored in the tree.
	/// </summary>
	/// <returns>The number of nodes in the tree.</returns>
	int countNodes() {

		return countNodes(pRoot);
	}

	/// <summary>
	/// Fills an array in ascending order.
	/// </summary>
	/// <returns>A new array containing the items of the tree.</returns>
	T* fillArray() {

		T* array = new T[countNodes()];
		fillArray(pRoot, 0, array);

		return array;
	}
};