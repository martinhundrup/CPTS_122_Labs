#include "Lab10.hpp"
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
				return true;
			}

			return insert(pCur->getLeft(), nKey); // recurive insert call
		}
		else { // right insertion

			if (pCur->getRight() == nullptr) { // right pointer is null

				pCur->setRight(nKey);
				return true;
			}

			return insert(pCur->getRight(), nKey);
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
	/// Deletes a node in the tree.
	/// </summary>
	/// <param name="pCur">The current root of the subtree.</param>
	/// <param name="query">The key to search for.</param>
	/// <returns>The new root of the subtree.</returns>
	BSTNode<T>* deleteNode(BSTNode<T>* pCur, T query) {

		if (pCur == nullptr) { // base case: we recursed off a leaf

			return pCur;
		}

		if (query < pCur->getKey()) { // case: we are deleted in left subtree

			pCur->setLeft(deleteNode(pCur->getLeft(), query));
			return pCur;
		}
		else if (query > pCur->getKey()) {

			pCur->setRight(deleteNode(pCur->getRight(), query));
			return pCur;
		}

		// we reached the tricky part, when we are deleting this node

		if (pCur->getLeft() == nullptr) { // easy case: left is null

			BSTNode<T>* temp = pCur->getRight();
			delete pCur;
			return temp;
		}
		else if (pCur->getRight() == nullptr) { // easy case 2: right is null

			BSTNode<T>* temp = pCur->getLeft();
			delete pCur;
			return temp;
		}
		else { // tricky case: contains two children

			BSTNode<T>* parent = pCur;

			// loop until we find the closest right node
			BSTNode<T>* successor = pCur->getRight();
			while (successor->getLeft() != nullptr) {

				parent = successor;
				successor = successor->getLeft();
			}

			// rearrange links
			if (parent != pCur) {

				parent->setLeft(successor->getRight());
			}
			else {

				parent->setRight(successor->getRight());
			}

			// update pCur key
			pCur->setKey(successor->getKey());
			delete successor;
			return pCur;
		}
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
	/// Prints the tree in ascending order.
	/// </summary>
	void printInOrder() {

		printInOrder(pRoot);
	}

	/// <summary>
	/// Deallocates all nodes currently in the tree.
	/// </summary>
	void destroyTree() {

		destroyTree(pRoot);
		pRoot = nullptr;
	}

	/// <summary>
	/// Deletes a queried node in this tree.
	/// </summary>
	/// <param name="query">The key belonging to the node to delete.</param>
	void deleteNode(T query) {

		if (!isEmpty()) {

			pRoot = deleteNode(pRoot, query);
		}
	}
};