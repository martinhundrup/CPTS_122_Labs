#include "BST.hpp"
#include "AVLTree.hpp"

void task_3() {

	BST<std::string> bst;

	std::string names[100];
	
	std::ifstream infile("names.txt");

	// store into array
	for (int i = 0; !infile.eof(); i++) {
		infile >> names[i];
	}

	// foreach loop in cpp
	// store into bst
	for (std::string s : names) {
		bst.insert(s);
	}

	std::string* array = bst.fillArray();

	for (int i = 0; i < bst.countNodes(); i++) {
		std::cout << array[i] << std::endl;
	}
}

int main() {

	//BSTNode<int>* myNode = new BSTNode<int>(15);
	//std::cout << *myNode << std::endl;
	//
	//BST<int> myTree;

	//for (int i = 0; i < 100; i++) {
	//	myTree.insert(rand() % 100);
	//}

	////myTree.printInOrder(); std::cout << std::endl;

	////std::cout << myTree.depth() << std::endl;

	//BST<int> testTree;
	//testTree.insert(42);
	//testTree.insert(25);
	//testTree.insert(10);
	//testTree.insert(30);
	//testTree.insert(15);
	//testTree.insert(75);
	//testTree.insert(65);
	//testTree.insert(100);
	//testTree.insert(70);

	//std::cout << testTree.depth() << std::endl;
	//std::cout << "in order: "; testTree.printInOrder();
	//std::cout << "\npre order: "; testTree.printPreOrder();
	//std::cout << "\npost order: "; testTree.printPostOrder();
	//testTree.destroyTree();

	//AVLTree<int> avl;
	//BST<int> bst;

	//

	//for (int i = 0; i < 100000; i++) {

	//	// Start measuring time
	//	auto begin = std::chrono::high_resolution_clock::now();
	//	avl.insert(i);
	//	// Stop measuring time and calculate the elapsed time
	//	auto end = std::chrono::high_resolution_clock::now();
	//	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	//	printf("AVL time measured: %.3f seconds.\n", elapsed.count() * 1e-9);

	//	std::cout << "i: " << i << ", AVL height : " << avl.getRoot()->getHeight() << std::endl;
	//}

	//

	//int avlheight = avl.depth();
	//avl.destroyTree();

	//// Start measuring time
	//auto begin2 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < 10000; i++) {
	//	//bst.insert(i);
	//}

	//// Stop measuring time and calculate the elapsed time
	//// Stop measuring time and calculate the elapsed time
	//auto end2 = std::chrono::high_resolution_clock::now();
	//auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);

	//

	//printf("BST time measured: %.3f seconds.\n", elapsed2.count() * 1e-9);

	//std::cout << "BST height: " << bst.depth() << std::endl;
	////std::cout << avl;



	/*BST<int> bst;

	for (int i = 0; i < 100; i++) {
		bst.insert(rand() % 100);
	}

	AVLTree<int> avl;

	for (int i = 0; i < 10; i++) {
		avl.insert(i);
	}*/

	//bst.printLevelOrder();
	//avl.printLevelOrder();

	task_3();

	/*int* array = bst.fillArray();

	for (int i = 0; i < bst.countNodes(); i++) {
		std::cout << array[i] << std::endl;
	}*/

	return 0;
}