#ifndef BIN_TREE_H
#define BIN_TREE_H
#include "BinNode.h"
#include "BinTreeFriendTests.h"
#include "CategorizedContact.h"
namespace AddrBookLib
{
	/*
	BinaryTree Template Class - New Data Structure instead of LinkList
	A BinaryTree is a collection data structure that is dynamic, storing BinNodes.
	Only BinNode pointers will be created in BinaryTree - NO BinNode objects
	A BinaryTree has a root BinNode pointer
	Public Members
	Default Constructor
	Copy Constructor
	Assignment Operator
	Destructor
	Add(Type dataIn)
	Bonus: Remove
	CountItems()
	ReadFile(string fileName)
	WriteFile(string fileName)
	PrintAll()
	inOrderTraverse(void process(Type&, int))
	Private Members
	CopyTree(BinNode*)
	Print(BinNode*, int&)
	WriteFile(BinNode*, ofstream&)
	BinNode* AllocBinNode(Type dataIn)
	FreeAllBinNodes(BinNode*)
	inOrderTraverse(BinNode*, int&, void process(Type&, int))
	Make sure all the member functions move links NOT data around when adding, removing.
	Make sure the class is a template and there is NO references to Name, Address, Contact, CategorizedContact
	*/
	//Requirement: Make sure the class is a template and there is NO references to Name, Address, Contact, CategorizedContact
	template<class T>
	class BinTree
	{
	public:
		//save some typing.
		//When adding or removing data, pass a constant reference.
		typedef const T & crefT;
		typedef T& refT;
		typedef BinTree<T> & refTBinTree;
		//Callback for transversing the binary tree.
		//the T reference refers to the data given in a node
		//the int reference can be used by the traversal callback function to keep track of how many have been successfully processed so far.
		using TraversalCallback = void(*) (refT, int);
		//typedef (void)(*TraversalCallback)(T&, int&);
		//Requirement: default constructor
		BinTree();
		//Requirement: copy constructor
		BinTree(const refTBinTree source);
		//Requirement: assignment operator
		refTBinTree operator=(const refTBinTree source);
		//Requirement: destructor
		~BinTree();
		//Requirement: Add(T dataIn)
		void Add(crefT dataIn);
		//Bonus: Rmove
		void Remove(int indexToRemove);
		//Requirement: countItes()
		int CountItems();
		//Requirement: ReadFile(string fileName)
		void ReadFile(const string & fileName);
		//Requirement: writeFile(string fileName)
		void WriteFile(string fileName);
		//Requirement: PrintAll()
		void PrintAll();
		//Requirement: inOrderTraverse(void process(T&, int))
		void inOrderTraverse(TraversalCallback process);


	private:
		//Private Members
		//Requirement: Make sure all the member functions move links NOT data around when adding, removing.
		//save more typing
		typedef BinNode<T> * PTBNode;
		//Requirement: CopyTree(BinNode*)
		void CopyTree(PTBNode rootToCopy);
		//Requirement: Print(BinNode*, int&)
		void Print(PTBNode aNode, int& number);
		//Requirement: WriteFile(BinNode*, ofstream&)
		void WriteFile(PTBNode node, ofstream& ofs);
		//Requirement: BinNode* AllocBinNode(Type dataIn)
		BinNode<T>* AllocBinNode(crefT dataIn);
		BinNode<T>* FindParentNode(crefT dataIn);
		//Requirement: FreeAllBinNodes(BinNode*)
		void FreeAllBinNodes(PTBNode aNode);
		//Requirement: inOrderTraverse(BinNode*, int&, void process(Type&, int))
		void InOrderTraverse(PTBNode aNode, int&, TraversalCallback process);

		void AddNode(PTBNode aNode);

		BinNode<T>* FindByIndex(int indexToFind);
		//return the index of the current node through the currentIndex reference.
		BinNode<T>* LookForIndex(int targetIndex, int & currentIndex, PTBNode root);

		int FindItemIndex(crefT itemToFind);
		int LookForItem(crefT itemToFind, int& currentIndex, PTBNode root);
		PTBNode root;
#ifdef BIN_TREE_TEST_FRIENDS
		friend void test::TestBinTree_Constructor0_0<T>();
		friend void test::TestBinTree_CopyConstructor<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_CopyConstructor_leaks<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_Assignment<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_Assignment_leaks<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_Deconstructor<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_Add<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_Remove<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
		friend void test::TestBinTree_ReadFile<T>(GeneratorCallback<T> low, GeneratorCallback<T> medium, GeneratorCallback<T> high);
#endif
	};
	typedef BinTree<CategorizedContact> AddrBook;
	//begin BinTree.tem
	template<class T>
	inline BinTree<T>::BinTree()
	{
		this->root = nullptr;
	}
	template<class T>
	inline BinTree<T>::BinTree(const refTBinTree source)
	{
		this->root = nullptr;
		this->CopyTree(source.root);
	}
	template<class T>
	inline BinTree<T>& BinTree<T>::operator=(const refTBinTree source)
	{
		if (this != &source)
			this->CopyTree(source.root);
		return *this;
	}
	template<class T>
	inline BinTree<T>::~BinTree()
	{
		this->FreeAllBinNodes(this->root);
	}
	template<class T>
	inline void BinTree<T>::Add(crefT dataIn)
	{
		PTBNode data = AllocBinNode(dataIn);
		AddNode(data);
	}
	template<class T>
	inline void BinTree<T>::Remove(int indexToRemove)
	{
		if (indexToRemove == 0) return;
		PTBNode _nodeToRemove = FindByIndex(indexToRemove);
		if (_nodeToRemove == nullptr)
			return;
		crefT dataToRemove = _nodeToRemove->data;
		PTBNode parent = FindParentNode(dataToRemove);
		if (parent == nullptr)
			return;
		PTBNode childToRemove = nullptr;
		if (parent->data > dataToRemove)
		{
			childToRemove = parent->left;
			parent->left = nullptr;
		}
		else
		{
			childToRemove = parent->right;
			parent->right = nullptr;
		}
		CopyTree(childToRemove->left);
		CopyTree(childToRemove->right);
		//Because the data above the removed child is copied rather than added,
		//we would have a memory leak if we didn't delete childToRemove and its children.
		FreeAllBinNodes(childToRemove);

	}
	template<class T>
	inline int BinTree<T>::CountItems()
	{
		int count = 0;
		//use an empty lambda, because all we are doing is traversing to get the count.
		this->InOrderTraverse(root, count, [](refT, int) {});
		return count;
	}
	template<class T>
	inline void BinTree<T>::ReadFile(const string& fileName)
	{

		using namespace std;
		ifstream fileIn(fileName);
		T tmpItem;
		char delim = ',';
		if (!fileIn)
		{
			cerr << "Error opening file " << fileName << " to read." << endl << endl;
			fileIn.close();
			return;
		}
		fileIn >> tmpItem;
		while (!fileIn.fail())
		{
			Add(tmpItem);
			//read format fname1,lname1,street address1,city1,state1,zip1,phone1,email1,bday1,picture file1,
			fileIn >> tmpItem;
		}
		fileIn.close();
		return;
	}
	template<class T>
	inline void BinTree<T>::WriteFile(string fileName)
	{
		ofstream fileOut(fileName);
		//		T tmpItem;
		//		char delim = ',';
		if (!fileOut)
		{
			cerr << "Error opening file " << fileName << " to write." << endl << endl;
			fileOut.close();
			return;
		}
		WriteFile(root, fileOut);
	}
	template<class T>
	inline void BinTree<T>::PrintAll()
	{
		int number = 1;
		this->Print(this->root, number);
	}
	template<class T>
	inline void BinTree<T>::inOrderTraverse(TraversalCallback process)
	{
		int x = 0;
		this->InOrderTraverse(this->root, x, process);
	}
	template<class T>
	inline void BinTree<T>::CopyTree(PTBNode rootToCopy)
	{
		if (rootToCopy == nullptr)
			return;
		Add(rootToCopy->data);
		CopyTree(rootToCopy->left);
		CopyTree(rootToCopy->right);

	}
	template<class T>
	inline void BinTree<T>::Print(PTBNode aNode, int & number)
	{
		if (aNode == nullptr)
			return;
		Print(aNode->left, number);
		number++;
		cout << number << ": " << aNode->data << endl;
		Print(aNode->right, number);
	}
	template<class T>
	inline void BinTree<T>::WriteFile(PTBNode node, ofstream & ofs)
	{
		if (node == nullptr)
			return;
		ofs << node->data << endl;
		WriteFile(node->left, ofs);
		WriteFile(node->right, ofs);
	}
	template<class T>
	inline BinNode<T> * BinTree<T>::AllocBinNode(crefT dataIn)
	{
		return new BinNode<T>(dataIn);//new BinNode<T>();
	}
	template<class T>
	inline BinNode<T>* BinTree<T>::FindParentNode(crefT dataIn)
	{
		PTBNode parent = nullptr,
			next = root;
		while (next->data != dataIn)
		{
			parent = next;
			if (next->data > dataIn)
				next = next->left;
			else
				next = next->right;
			if (next == nullptr)
				return nullptr;
		}
		return parent;
	}
	template<class T>
	inline void BinTree<T>::FreeAllBinNodes(PTBNode aNode)
	{
		if (aNode == nullptr)
			return;
		FreeAllBinNodes(aNode->left);
		FreeAllBinNodes(aNode->right);
		delete aNode;
	}
	template<class T>
	inline void BinTree<T>::InOrderTraverse(PTBNode aNode, int & index, TraversalCallback process)
	{
		if (aNode == nullptr) return;
		InOrderTraverse(aNode->left, index, process);

		++index;
		process(aNode->data, index);

		InOrderTraverse(aNode->right, index, process);

	}
	template<class T>
	inline void BinTree<T>::AddNode(PTBNode data)
	{
		if (root == nullptr)
		{
			root = data;
			return;
		}
		//root is not nullptr.
		PTBNode parent = nullptr,
			*next = &root;
		//pointer to a pointer -- we want to be able to get a pointer that could point to a nullptr, and set the data later.
		do
		{
			parent = *next;
			if (parent->data > data->data)
				next = &(parent->left);
			else
				next = &(parent->right);

		} while (*next != nullptr);//next is not null; *next is null, **next does not exist.
		*next = data;
	}
	template<class T>
	inline BinNode<T>* BinTree<T>::FindByIndex(int indexToFind)
	{
		if (indexToFind < 0) return nullptr;
		if (indexToFind == 0) return root;
		int i = 0;
		PTBNode nodeToReturn = LookForIndex(indexToFind, i, root);
		return nodeToReturn;


	}

	template<class T>
	inline BinNode<T>* BinTree<T>::LookForIndex(int targetIndex, int & currentIndex, PTBNode rootNode)
	{
		/*

		Possible map of the tree:



					 1
				 2 <
			  3 <
			 /   4
		5	<
			  \               6
			   \           7 <
				\         /   \   9
				 \	     /     8 <
				  \		/         10
				   11 <
					   \		   12
						\	   13 <
						 \	  /    14
						  15 <
							  \    16
							   17 <
								   18




		*/

		if (rootNode == nullptr)
			return nullptr;

		//is it to the left?
		PTBNode upperAnswer = LookForIndex(targetIndex, currentIndex, rootNode->left);
		if (upperAnswer != nullptr)
			return upperAnswer;
		//is it this one?
		++currentIndex;
		if (currentIndex == targetIndex)
			return rootNode;
		//is it to the right?
		upperAnswer = LookForIndex(targetIndex, currentIndex, rootNode->right);
		if (upperAnswer != nullptr)
			return upperAnswer;
		return nullptr;
	}

	template<class T>
	inline int BinTree<T>::FindItemIndex(crefT itemToFind)
	{
		bool finished = false;
		int index = 0;
		int returnedIndex = LookForItem(itemToFind, index, this->root);
		return returnedIndex;
	}

	template<class T>
	inline int BinTree<T>::LookForItem(crefT itemToFind, int & currentIndex, PTBNode rootNode)
	{
		int upperIndex = -1;
		if (rootNode == nullptr)
			return -1;
		upperIndex = LookForItem(itemToFind, currentIndex, rootNode->left);
		if (upperIndex > 0)
			return upperIndex;
		++currentIndex;
		if (rootNode->data == itemToFind)
			return currentIndex;
		upperIndex = LookForItem(itemToFind, currentIndex, rootNode->right);
		if (upperIndex > 0)
			return upperIndex;
		return -1;
	}




}
#endif
