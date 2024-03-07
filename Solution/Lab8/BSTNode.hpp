#include "Lab8.hpp"

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

	/// <summary>
	/// The height of this node.
	/// </summary>
	int height;
	
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

	/// <summary>
	/// Inserts the key into the file stream.
	/// </summary>
	/// <param name="lhs">The stream to insert to.</param>
	/// <param name="rhs">The node being read from.</param>
	/// <returns>The updated stream.</returns>
	friend std::ofstream& operator<<(std::ofstream& lhs, const BSTNode<T>& rhs) {

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

	/// -- DESTRUCTOR -- //

	/// <summary>
	/// Destroys this object
	/// </summary>
	~BSTNode() {

		//std::cout << "destroying node\n";
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

	/// <summary>
	/// Gets the height.
	/// </summary>
	/// <returns>The current height of the node.</returns>
	int getHeight() const {

		return height;
	}

	/// -- SETTERS -- ///

	/// <summary>
	/// Sets the left node.
	/// </summary>
	/// <param name="nKey">The key to insert.</param>
	void setLeft(T nKey) {

		pLeft = new BSTNode<T>(nKey);
	}

	/// <summary>
	/// Sets the right node.
	/// </summary>
	/// <param name="nKey">The key to insert.</param>
	void setRight(T nKey) {

		pRight = new BSTNode<T>(nKey);
	}

	/// <summary>
	/// Sets the height.
	/// </summary>
	/// <param name="nHeight">The new height of the node.</param>
	void setHeight(int nHeight) {

		height = nHeight;
	}
};