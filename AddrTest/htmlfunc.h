/*
 * This file contains the prototypes fo miscelleneous functions to
 * print HTML code for the address book binary tree project for CSC161.
 *
 * Written by Cathy Bishop, April 1998
 * Updated by Cathy Bishop, November, 2000
 * Updated by Julie Schneider, Nov. 2014
 * Updated by Jesse Gibbons, Dec., 2016
 *
 */

#ifndef HTMLFUNC_H
#define HTMLFUNC_H

#include	<fstream>
#include	<iostream>
#include	<cstdio>
#include 	<string>
#include	<string.h>
#include	<cstdlib>
using namespace std;
#include	"categorizedContact.h"
#include	"binnode.h"
#include	"bintree.h"
using namespace AddrBookLib;
#define _CRT_SECURE_NO_WARNINGS
template<class T> using BinaryTree = BinTree<T>;
// Takes the binary tree of addresses and prints the HTML index file.

void	printHTMLindex(BinaryTree<CategorizedContact> &book);

// Takes binary tree of addresses and prints the HTML page for each address.

void	printHTMLpages(BinaryTree<CategorizedContact> &book);

// Takes an address and prints an HTML reference to its HTML page.

void	printHTMLrefs(CategorizedContact &item,
	int counter);

// Takes an address and prints an HTML page.

void	printHTMLpage(CategorizedContact &item,
	int counter);

#endif
