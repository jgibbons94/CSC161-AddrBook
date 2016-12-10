//LinkListTests.h
//Written by Jesse Gibbons
#ifndef BIN_TREE_TESTS_H
#define BIN_TREE_TESTS_H
#include <cassert>
#include "Tests.h"
//#include "LinkList_IteratorTests.h"
#ifndef BIN_TREE_TEST_FRIENDS
#define BIN_TREE_TEST_FRIENDS
#endif
#include "BinTreeFriendTests.h"
#include "BinNode.h"
#include "BinTree.h"
//#include "Node.h"
#include "RandomGenerators.h"
namespace test
{
	using namespace AddrBookLib;
	template<class T>
	void TestBinTree(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);

	template<class T>
	void TestBinTree_Constructor0_0();
	////template<class T>
	////void TestBinTree_ConstructorFirst();
	////template<class T>
	////void TestBinTree_ConstructorLast();
	////template<class T>
	////void TestBinTree_ConstructorAsc();
	////template<class T>
	////void TestBinTree_ConstructorDesc();
	template<class T>
	void TestBinTree_CopyConstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestBinTree_CopyConstructor_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestBinTree_Assignment(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestBinTree_Assignment_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestBinTree_Add(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);

	template<class T>
	void TestBinTree_Remove(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);

	template<class T>
	void TestBinTree_CountItems(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);

	//template<class T>
	//void TestBinTree_Begin(GeneratorCallback<T> RandomGenerator);
	//template<class T>
	//void TestBinTree_IsEmpty();
	//template<class T>
	//void TestBinTree_Add(GeneratorCallback<T> RandomGenerator);
	//template<class T>
	//void TestBinTree_RemoveByItemNumber(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_RemoveByItem(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	template<class T>
	void TestBinTree_Deconstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);


	//helper processing functions

	template<class T>
	bool compareTreeNodeValues(AddrBookLib::BinNode<T>* node1, AddrBookLib::BinNode<T>* node2);
	template<class T>
	bool compareDifferentTreeNodePointers(AddrBookLib::BinNode<T>* node1, AddrBookLib::BinNode<T>* node2);
	template<class T>
	AddrBookLib::BinNode<T>* furthestLeft(AddrBookLib::BinNode<T>* root);
	template<class T>
	AddrBookLib::BinNode<T>* furthestRight(AddrBookLib::BinNode<T>* root);


	//template<class T>
	//void TestBinTree_ReadFile(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_WriteFile(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_PrintAll(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);

	////private functions

	//template<class T>
	//void TestBinTree_AllocNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_FindNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_HasOnlyOneElement(GeneratorCallback<T> randomGenerator);
	//template<class T>
	//void TestBinTree_AddAsc(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_AddDesc(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_AddEnd(GeneratorCallback<T> randomGenerator);
	//template<class T>
	//void TestBinTree_AddBeginning(GeneratorCallback<T> randomGenerator);
	//template<class T>
	//void TestBinTree_InsertValueAfterSpecifiedNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_Concat(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_RemoveFirst(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_RemoveNode(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_FreeNode(GeneratorCallback<T> RandomGenerator);
	//template<class T>
	//void TestBinTree_FreeAllNodes(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
	//template<class T>
	//void TestBinTree_FreeAllNodes_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);


	//helper

	template<class T>
	void TestBinTree(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		AnnounceTests("LinkList<T>");
		TestBinTree_Constructor0_0<T>();
		//TestBinTree_ConstructorFirst<T>();
		//TestBinTree_ConstructorLast<T>();
		//TestBinTree_ConstructorAsc<T>();
		//TestBinTree_ConstructorDesc<T>();
		TestBinTree_CopyConstructor<T>(low, medium, high);
		TestBinTree_CopyConstructor_leaks<T>(low, medium, high);
		TestBinTree_Assignment<T>(low, medium, high);
		TestBinTree_Assignment_leaks<T>(low, medium, high);
		TestBinTree_Deconstructor<T>(low, medium, high);

		TestBinTree_Add<T>(low, medium, high);
		TestBinTree_Remove<T>(low, medium, high);
		//for (int i = 0; i < GenerateHighRandomNumber(); i++)
			TestBinTree_CountItems<T>(low, medium, high);
		//TestBinTree_Begin<T>(medium);
		//TestBinTree_CountItems<T>(high);
		//TestBinTree_IsEmpty<T>();
		//TestBinTree_RemoveByItemNumber<T>(low, medium, high);
		//TestBinTree_RemoveByItem<T>(low, medium, high);
		//TestBinTree_ReadFile<T>(low, medium, high);
		//TestBinTree_WriteFile<T>(low, medium, high);
		//TestBinTree_PrintAll<T>(low, medium, high);
		////private functions
		//TestBinTree_AllocNode<T>(high);
		//TestBinTree_FindNode<T>(low, medium, high);
		//TestBinTree_HasOnlyOneElement<T>(low);
		//TestBinTree_AddAsc<T>(low, medium, high);
		//TestBinTree_AddDesc<T>(low, medium, high);
		//TestBinTree_AddEnd<T>(medium);
		//TestBinTree_AddBeginning<T>(medium);
		//TestBinTree_InsertValueAfterSpecifiedNode<T>(low, medium, high);
		//TestBinTree_Concat<T>(low, medium, high);
		//TestBinTree_RemoveFirst<T>(low, medium, high);
		//TestBinTree_RemoveNode<T>(low, medium, high);
		//TestBinTree_FreeNode<T>(high);
		//TestBinTree_FreeAllNodes<T>(low, medium, high);
		//TestBinTree_FreeAllNodes_leaks<T>(low, medium, high);

		//TestBinTree_Iterator<T>(low);
	}

	template<class T>
	void TestBinTree_Constructor0_0()
	{
		BinTree<T> tree;
		assert(tree.root == nullptr);
	}

	template<class T>
	void TestBinTree_CopyConstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		BinTree<T> tree1;
		for (int i = 0; i < 10; i++)
		{
			tree1.Add(medium());
		}
		for (int i = 0; i < 10; i++)
		{
			tree1.Add(low());
		}
		for (int i = 0; i < 10; i++)
		{
			tree1.Add(high());
		}
		BinTree<T> tree2(tree1);
		assert(compareTreeNodeValues(tree1.root, tree2.root));
	}

	template<class T>
	bool compareTreeNodeValues(BinNode<T> * node1, BinNode<T> * node2)
	{
		if (node1 == nullptr || node2 == nullptr)
			return node1 == node2;
		return(node1->data == node2->data
			&& compareTreeNodeValues(node1->left, node2->left)
			&& compareTreeNodeValues(node1->right, node2->right));
	}

	template<class T>
	void TestBinTree_CopyConstructor_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		BinTree<T> tree1;
		for (int i = 0; i < 10; i++)
		{
			tree1.Add(medium());
		}
		for (int i = 0; i < 10; i++)
		{
			tree1.Add(low());
		}
		for (int i = 0; i < 10; i++)
		{
			tree1.Add(high());
		}
		BinTree<T> tree2(tree1);
		assert(compareDifferentTreeNodePointers(tree1.root, tree2.root));
	}
	template<class T>
	bool compareDifferentTreeNodePointers(AddrBookLib::BinNode<T>* node1, AddrBookLib::BinNode<T>* node2)
	{
		if (node1 == nullptr || node2 == nullptr)
			return node1 == node2;
		return(node1 != node2
			&& compareDifferentTreeNodePointers(node1->left, node2->left)
			&& compareDifferentTreeNodePointers(node1->right, node2->right));

	}
	template<class T>
	AddrBookLib::BinNode<T>* furthestLeft(AddrBookLib::BinNode<T>* root)
	{
		if (root == nullptr || root->left == nullptr) return root;
		return furthestLeft(root->left);
	}
	template<class T>
	AddrBookLib::BinNode<T>* furthestRight(AddrBookLib::BinNode<T>* root)
	{
		if (root == nullptr || root->right == nullptr) return root;
		return furthestLeft(root->right);
	}
	template<class T>
	void TestBinTree_Assignment(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		BinTree<T> tree1;
		for (int i = 0; i < 100; i++)
		{
			tree1.Add(medium());
		}
		for (int i = 0; i < 100; i++)
		{
			tree1.Add(low());
		}
		for (int i = 0; i < 100; i++)
		{
			tree1.Add(high());
		}
		BinTree<T> tree2 = tree1;
		assert(compareTreeNodeValues(tree1.root, tree2.root));
	}
	template<class T>
	void TestBinTree_Assignment_leaks(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		BinTree<T> tree1;
		for (int i = 0; i < 10; i++)
		{
			tree1.Add(medium());
		}
		for (int i = 0; i < 10; i++)
		{
			tree1.Add(low());
		}
		for (int i = 0; i < 10; i++)
		{
			tree1.Add(high());
		}
		BinTree<T> tree2 = tree1;
		assert(compareDifferentTreeNodePointers(tree1.root, tree2.root));
	}
	template<class T>
	void TestBinTree_Add(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		bool pass1 = false,
			pass2 = false,
			pass3 = false;
		BinTree<T> tree;
		T vLow = low(),
			vMedium = medium(),
			vHigh = high();
		tree.Add(vMedium);
		tree.Add(vLow);
		tree.Add(vHigh);
		if (tree.root->data == vMedium)
			pass1 = true;
		if (tree.root->left->data == vLow)
			pass2 = true;
		if (tree.root->right->data == vHigh)
			pass3 = true;
		assert(pass1&&pass2&&pass3);
	}
	template<class T>
	void TestBinTree_Remove(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		//setup
		BinTree<T> tree;
		BinNode<T> *removeParent = nullptr,
			*findParent = nullptr;
		T leaf1 = medium(), leaf2 = medium();
		while (leaf1 == leaf2)
		{
			leaf1 = medium();
			leaf2 = medium();
		}
		T leafToRemove = (leaf1 < leaf2) ? leaf1 : leaf2;
		T leafToFind = (leaf1 < leaf2) ? leaf1 : leaf2;
		//act
		//build a random tree of all high values
		for (int i = 0; i < 100; i++)
			tree.Add(high());
		tree.Add(leafToRemove);
		removeParent = tree.FindParentNode(leafToRemove);
		//leafToFind will end up far left.
		tree.Add(leafToFind);//Will be put on the left of leafToRemove, so it will take the place of leafToRemove. Therefore, its parent after leafToRemove should be leafToRemove's parent before it was removed.
		int removeIndex = tree.FindItemIndex(leafToRemove);
		//All of the following children will be children of leafToFind, even after leafToRemove is removed.
		for (int i = 0; i < 100; i++)
			tree.Add(low());
		tree.Remove(removeIndex);
		findParent = tree.FindParentNode(leafToFind);
		//assert
		assert(findParent == removeParent);
	}
	template<class T>
	void TestBinTree_CountItems(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		int lowCount = GenerateMediumRandomNumber()*GenerateMediumRandomNumber(),
			mediumCount = GenerateMediumRandomNumber()*GenerateMediumRandomNumber(),
			highCount = GenerateMediumRandomNumber()*GenerateMediumRandomNumber(),
			expectedCount = lowCount + mediumCount + highCount;
		BinTree<T> tree;
		for (int i = 0; i < lowCount; i++)
			tree.Add(medium());
		for (int i = 0; i < mediumCount; i++)
			tree.Add(high());
		for (int i = 0; i < highCount; i++)
			tree.Add(low());
		assert(tree.CountItems() == expectedCount);
	}
	template<class T>
	void TestBinTree_Deconstructor(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high)
	{
		bool pass1 = false,
			pass2 = false;

		BinTree<T>* tree = new BinTree<T>();
		for (int i = 0; i < 10; i++)
		{
			tree->Add(medium());
		}
		for (int i = 0; i < 10; i++)
		{
			tree->Add(low());
		}
		for (int i = 0; i < 10; i++)
		{
			tree->Add(high());
		}
		BinNode<T> * left = furthestLeft(tree->root),
			*right = furthestRight(tree->root);
		T vLeft = left->data,
			vRight = right->data;
		BinNode<T>** pLeft = &left,
			** pRight = &right;
		assert(left != nullptr);
		assert(right != nullptr);
		delete tree;
		try
		{
			T check = right->data;
			if (check == vRight)
				cerr << "Memory leak detected in BinTree's deconstructor." << endl;
			else
				pass1 = true;
		}
		catch (...)
		{
			pass1 = true;
		}
		try
		{
			T check = left->data;
			if (check == vLeft)
				cerr << "Memory leak detected in BinTree's deconstructor." << endl;
			else
				pass2 = true;
		}
		catch (...)
		{
			pass2 = true;
		}
		assert(pass1 == true && pass2 == true);
	}


}


#endif
