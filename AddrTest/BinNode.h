#ifndef BIN_NODE_H
#define BIN_NODE_H
#include "BinTreeFriendTests.h"
namespace AddrBookLib
{
	template<class T>
	class BinTree;
	/*
	BinNode Template Class - Item for BinaryTree collection
	A BinNode has a data object and a link to the left and right BinNode.
	The BinNode class needs constructors (default and a constructor that will set the data)
	The BinNode class is NOT dynamic
	Make sure the class is a template and there is NO references to Name, Address, Contact,1 CategorizedContact
	The BinNode class is a helper class to BinaryTree and is only utilized in BinaryTree.
	*/
	template<class T>
	class BinNode
	{
	private:
		BinNode(T initialData = T())
		{
			data = initialData;
			left = nullptr;
			right = nullptr;
		}


		T data;
		BinNode<T>* left;
		BinNode<T>* right;
		friend class BinTree<T>;
		#ifdef BIN_TREE_TEST_FRIENDS
		friend bool test::compareTreeNodeValues<T>(AddrBookLib::BinNode<T>* node1, AddrBookLib::BinNode<T>* node2);
		friend bool test::compareDifferentTreeNodePointers(AddrBookLib::BinNode<T>* node1, AddrBookLib::BinNode<T>* node2);
		friend void test::TestBinTree_CopyConstructor<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_CopyConstructor_leaks<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_Assignment<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_Assignment_leaks<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_Deconstructor<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend AddrBookLib::BinNode<T>* test::furthestLeft<T>(AddrBookLib::BinNode<T>* root);
		friend AddrBookLib::BinNode<T>* test::furthestRight<T>(AddrBookLib::BinNode<T>* root);
		friend void test::TestBinTree_Add<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		#endif
	};
}

#endif
