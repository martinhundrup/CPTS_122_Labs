#include "Lab8.hpp"
#include "AVLNode.hpp"

template <typename T>
class AVLTree {

private:

	/// <summary>
	/// A pointer to the root node of the tree.
	/// </summary>
	AVLNode<T>* pRoot;

	/// -- PRIVATE FUNCTIONS -- //

	/// <summary>
	/// Determines if tree is empty.
	/// </summary>
	/// <returns>True if empty; false if not.</returns>
	bool isEmpty() {

		return pRoot == nullptr;
	}

	/// <summary>
	/// Rotates a sub tree clockwise.
	/// </summary>
	/// <param name="pCur">The old rootnode.</param>
	/// <returns>The new rootnode.</returns>
	AVLNode<T>* rotateRight(AVLNode<T>* pCur) {

		AVLNode<T>* left = pCur->getLeft();
		AVLNode<T>* right = left->getRight();

		// the ol' switcheroo
		left->setRight(pCur);
		pCur->setLeft(right);

		// update heights
		int leftHeight = (pCur->getLeft() == nullptr) ? 0 : pCur->getLeft()->getHeight();
		int rightHeight = (pCur->getRight() == nullptr) ? 0 : pCur->getRight()->getHeight();
		pCur->setHeight(1 + std::max(leftHeight, rightHeight));

		leftHeight = (left->getLeft() == nullptr) ? 0 : left->getLeft()->getHeight();
		rightHeight = (left->getRight() == nullptr) ? 0 : left->getRight()->getHeight();
		left->setHeight(1 + std::max(leftHeight, leftHeight));

		return left;
	}

	/// <summary>
	/// Rotates a sub tree counterclockwise.
	/// </summary>
	/// <param name="pCur">The old rootnode.</param>
	/// <returns>The new rootnode.</returns>
	AVLNode<T>* rotateLeft(AVLNode<T>* pCur) {

		AVLNode<T>* right = pCur->getRight();
		AVLNode<T>* left = right->getLeft();

		// the ol' switcheroo
		right->setLeft(pCur);
		pCur->setRight(left);

		// update heights
		int leftHeight = (pCur->getLeft() == nullptr) ? 0 : pCur->getLeft()->getHeight();
		int rightHeight = (pCur->getRight() == nullptr) ? 0 : pCur->getRight()->getHeight();
		pCur->setHeight(1 + std::max(leftHeight, rightHeight));

		leftHeight = (right->getLeft() == nullptr) ? 0 : right->getLeft()->getHeight();
		rightHeight = (right->getRight() == nullptr) ? 0 : right->getRight()->getHeight();
		right->setHeight(1 + std::max(leftHeight, leftHeight));

		return right;
	}

	/// <summary>
	/// Recursively inserts a node into the tree.
	/// </summary>
	/// <param name="pCur">The current node in the tree.</param>
	/// <param name="nKey">The key to insert</param>
	/// <returns>The new root node of the subtree.</returns>
	AVLNode<T>* insert(AVLNode<T>* pCur, T nKey) {

		/// -- normal insert -- ///

		if (pCur == nullptr) { // inserting a new leaf

			return new AVLNode<T>(nKey);
		}

		if (nKey < pCur->getKey()) { // insert to left

			pCur->setLeft(insert(pCur->getLeft(), nKey));
		}
		else if (nKey > pCur->getKey()) { // insert to right

			pCur->setRight(insert(pCur->getRight(), nKey));
		}
		else { // duplicate key not allowed

			return pCur;
		}

		/// -- AVL time -- ///

		// set new height of the node.
		/*int leftHeight = (pCur->getLeft() == nullptr) ? 0 : pCur->getLeft()->getHeight();
		int rightHeight = (pCur->getRight() == nullptr) ? 0 : pCur->getRight()->getHeight();
		pCur->setHeight(std::max(leftHeight, rightHeight));*/

		depth(pCur);

		// find the balance factor of the subtree
		int balance = pCur->balance();

		// case: inserted left left
		if (balance > 1 && nKey < pCur->getLeft()->getKey()) {

			return rotateRight(pCur);
		}

		// case: inserted right right
		if (balance < -1 && nKey > pCur->getRight()->getKey()) {

			return rotateLeft(pCur);
		}

		// case: inserted left right
		if (balance > 1 && nKey > pCur->getLeft()->getKey()) {

			pCur->setLeft(rotateLeft(pCur->getLeft() ) );
			return rotateRight(pCur);
		}

		// case: inserted right left
		if (balance < -1 && nKey < pCur->getRight()->getKey()) {

			pCur->setRight(rotateRight(pCur->getRight() ) );
			return rotateLeft(pCur);
		}

		return pCur;
	}

	/// <summary>
	/// Recursively calculates the depth of the tree.
	/// </summary>
	/// <param name="pCur">The root node of the current sub-tree.</param>
	/// <returns>The depth of the sub-tree.</returns>
	int depth(AVLNode<T>* pCur) {

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
	void printInOrder(std::ostream& lhs, const AVLNode<T>* rhs) const {

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
	void printInOrder(const AVLNode<T>* pCur) const {

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
	void printPreOrder(const AVLNode<T>* pCur) const {

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
	void printPostOrder(const AVLNode<T>* pCur) const {

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
	void destroyTree(AVLNode<T>* pCur) {

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
	void printLevelOrder(AVLNode<T>* pCur, int level) {

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
	int countNodes(AVLNode<T>* pCur) {

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
	int fillArray(AVLNode<T>* pCur, int n, T* array) {

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
	friend std::ostream& operator<<(std::ostream& lhs, const AVLTree<T>& rhs) {

		rhs.printInOrder(lhs, rhs.getRoot());
		return lhs;
	}

public:

	/// -- CONSTRUCTORS -- ///

	/// <summary>
	/// Default constructor; intializes pRoot to nullptr.
	/// </summary>
	AVLTree() {

		pRoot = nullptr;
	}

	/// -- DESTRUCTORS -- ///

	/// <summary>
	/// Destroys the object.
	/// </summary>
	~AVLTree() {

		destroyTree();
	}

	/// -- GETTERS -- //

	/// <summary>
	/// Gets the root pointer.
	/// </summary>
	/// <returns>A reference to the root pointer.</returns>
	AVLNode<T>* getRoot() const {

		return pRoot;
	}

	/// -- PUBLIC MEMBER FUNCTIONS -- //

	/// <summary>
	/// Inserts a new node into the tree.
	/// </summary>
	/// <param name="nKey">The key to insert.</param>
	void insert(T nKey) {

		if (isEmpty()) { // inserting into empty tree

			pRoot = new AVLNode<T>(nKey);
		}
		else {

			pRoot = insert(pRoot, nKey);
		}
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