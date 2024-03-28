#include "Lab10.hpp"

template <typename T>
class BSTNode {

private:

	/// <summary>
	/// The data stored in this node.
	/// </summary>
	T key;

	/// <summary>
	/// A pointer to the left sub-node.
	/// </summary>
	BSTNode<T>* pLeft;

	/// <summary>
	/// A pointer to the right sub-node.
	/// </summary>
	BSTNode<T>* pRight;

	/// -- PRIVATE METHODS -- ///

	/// <summary>
	/// Inserts the key into the stream.
	/// </summary>
	/// <param name="lhs">The stream to insert to.</param>
	/// <param name="rhs">The node being read from.</param>
	/// <returns>The updated stream.</returns>
	friend std::ostream& operator<<(std::ostream& lhs, const BSTNode<T>& rhs) {

		lhs << rhs.getKey();
		return lhs;
	}

public:

	/// -- CONSTRUCTORS -- ///

	/// <summary>
	/// Default constructor; initializes all fields with default values.
	/// </summary>
	BSTNode() {

		key = T();
		pLeft = pRight = nullptr;
	}

	/// <summary>
	/// Overloaded constructed; intializes key with a passed in value.
	/// </summary>
	/// <param name="nKey">The value to store in the node.</param>
	BSTNode(T nKey) {

		key = nKey;
		pLeft = pRight = nullptr;
	}

	/// -- GETTERS -- ///

	/// <summary>
	/// Gets the key field.
	/// </summary>
	/// <returns>The data stored in this node.</returns>
	T getKey() const {

		return key;
	}

	/// <summary>
	/// Gets the left sub-node.
	/// </summary>
	/// <returns>A reference to the left node.</returns>
	BSTNode<T>* getLeft() const {

		return pLeft;
	}

	/// <summary>
	/// Gets the right sub-node.
	/// </summary>
	/// <returns>A reference to the right node.</returns>
	BSTNode<T>* getRight() const {

		return pRight;
	}

	/// -- SETTERS -- ///

	/// <summary>
	/// Sets the key.
	/// </summary>
	/// <param name="nKey">The key to change to.</param>
	void setKey(T nKey) {

		key = nKey;
	}

	/// <summary>
	/// Sets the left node.
	/// </summary>
	/// <param name="nKey">The key to insert.</param>
	void setLeft(T nKey) {

		pLeft = new BSTNode<T>(nKey);
	}

	/// <summary>
	/// Sets the left node.
	/// </summary>
	/// <param name="nNode">The node to insert.</param>
	void setLeft(BSTNode<T>* nNode) {

		pLeft = nNode;
	}

	/// <summary>
	/// Sets the right node.
	/// </summary>
	/// <param name="nKey">The key to insert.</param>
	void setRight(T nKey) {

		pRight = new BSTNode<T>(nKey);
	}

	/// <summary>
	/// Sets the right node.
	/// </summary>
	/// <param name="nNode">The node to insert.</param>
	void setRight(BSTNode<T>* nNode) {

		pRight = nNode;
	}
};