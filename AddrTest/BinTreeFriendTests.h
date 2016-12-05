#ifndef BIN_TREE_FRIEND_TESTS_H
#define BIN_TREE_FRIEND_TESTS_H
#ifdef BIN_TREE_TEST_FRIENDS
namespace AddrBookLib
{
	template<class T>
	class BinNode;
}
namespace test
{
	//The following functions are required friends in testing the BinTree object:

	//Friends of BinTree

	template<class T>
	void TestBinTree_Constructor0_0();


	//Friends of BinNode

	template<class T>
	bool compareTreeNodeValues(AddrBookLib::BinNode<T>* node1, AddrBookLib::BinNode<T>* node2);
	template<class T>
	bool compareDifferentTreeNodePointers(AddrBookLib::BinNode<T>* node1, AddrBookLib::BinNode<T>* node2);

	//friends of both BinNode and BinTree

	template<class T>
	void TestBinTree_CopyConstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestBinTree_CopyConstructor_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestBinTree_Assignment(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestBinTree_Assignment_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestBinTree_Deconstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	AddrBookLib::BinNode<T>* furthestLeft(AddrBookLib::BinNode<T>* root);
	template<class T>
	AddrBookLib::BinNode<T>* furthestRight(AddrBookLib::BinNode<T>* root);
	template<class T>
	void TestBinTree_Add(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
}
#endif//BIN_TREE_TEST_FRIENDS
#endif//BIN_TREE_FRIEND_TESTS_H
