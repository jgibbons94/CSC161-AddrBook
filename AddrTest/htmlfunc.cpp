/*
 * This file contains miscelleneous functions to print HTML code
 * for the item book binary tree project for CSC161.
 *
 * Written by Cathy Bishop, April 1998
 * Updated by Cathy Bishop, November, 2000
 * Updated by Julie Schneider, Nov., 2014
 * Updated by Jesse Gibbons, Dec., 2016
 *
 */
#include	"htmlfunc.h"

 // Misc HTML functions

void	printHTMLhead(ostream &os, string title);
void	printHTMLend(ostream &os);

// File that will have the HTML index to my item book

ofstream	htmlIndex;

/*
 * Function: printHTMLindex(binTree<itemEntry> &book)
 *
 * This function takes the item book (which is a binary tree)
 * and prints the HTML index for the item book. The index
 * is in the file index.htm. You can open this file with your
 * browser to access your itemes.
 *
 * This function uses the inOrderTraverse() member function of the
 * binary tree template code to print the individual hrefs. It passes
 * the stand-alone function printHTMLrefs() to actually print them.
 *
 * Parameters:
 *
 *	book	- the item book (as a binary tree!)
 *
 * Returns:
 *
 * NONE
 *
 */

void	printHTMLindex(BinaryTree<CategorizedContact> &book)
{
	htmlIndex.open("index.htm");
	printHTMLhead(htmlIndex, "Item Book Index");
	book.inOrderTraverse(printHTMLrefs);
	printHTMLend(htmlIndex);
	htmlIndex.close();
}

/*
 * Function: printHTMLpages(binTree<itemEntry> &book)
 *
 * This function takes the item book (which is a binary tree)
 * and prints the HTML pages for the item book. You can access
 * the pages by opening the index.htm file with your browser.
 *
 * This function uses the inOrderTraverse() member function of the
 * binary tree template code to print the individual pages. It passes
 * the stand-alone function printHTMLpage() to actually print them.
 *
 * Parameters:
 *
 *	book	- the item book (as a binary tree!)
 *
 * Returns:
 *
 * NONE
 *
 */

void	printHTMLpages(BinaryTree<CategorizedContact> &book)
{
	book.inOrderTraverse(printHTMLpage);
}

/*
 * Function: printHTMLhref(int counter, itemEntry &item)
 *
 * This function takes an item entry and prints the HTML
 * href to its page. The file for the page is named addrNNNN.htm,
 * where N is a counter. This counter should be passed by the
 * inOrderTraverse() member function of the binary tree template code.
 * The easiest way to generate this number is to make it a counter
 * that counts the nodes as they are being traversed.
 *
 * The output from this function will look like this:
 *
 * <p><a href=addr0001.htm> Cathy Bishop</a>
 *
 * Parameters:
 *
 *	counter	- the number used to generate a unique HTML file reference.
 *	item	- the item entry.
 *
 * Returns:
 *
 * NONE
 *
 */

void	printHTMLrefs(CategorizedContact &item,
	int counter)
{
	char		fileName[13];

	sprintf_s(fileName, "addr%4.4d.htm", counter);

	htmlIndex << "<p><a href='" << fileName << "'> "
		<< item.GetFullName().GetLastName() << ", " << item.GetFullName().GetFirstName() << "</a></p>\n";
}
// field Contact::nameLastCommaFirst() const;

/*
 * Function: printHTMLpage(int counter, itemEntry &item)
 *
 * This function takes an item entry and prints the HTML
 * page. The file for the page is named addrNNNN.htm,
 * where N is a counter. This counter should be passed by the
 * inOrderTraverse() member function of the binary tree template code.
 * The easiest way to generate this number is to make it a counter
 * that counts the nodes as they are being traversed.
 *
 * Old output = bad
 * HTML and style should be separated.
 *
 * The output from this function will look like this:
 *
 * <p class='title'>
 * <H1>
 * Cathy Bishop
 * </H1>
 * <body>
 * <p class='contact'>
 * <h1>Red Rocks Community College</h1>
 * <strong>Category: </strong> Other<br />
 * <br>Lakewood, CO 80026<br />
 * <p><strong>phone:</strong> 914-6250</p><br />
 * <p><strong>email:</strong> cbishop@pobox.com</p><br />
 * <p><strong>Birthday:</strong> January 28</p><br />
 * </p>
 * </body>
 * </html>
 *
 * Parameters:
 *
 *	counter	- the number used to generate a unique HTML file reference.
 *	item	- the item entry.
 *
 * Returns:
 *
 * NONE
 *
 */

void	printHTMLpage(CategorizedContact &item,
	int counter)
{
	char		fileName[13];
	ofstream	htmlPage;
	string		title;

	sprintf_s(fileName, "addr%4.4d.htm", counter);

	htmlPage.open(fileName);
	if (!htmlPage)
	{
		cout << "Unable to write HTML page: " << fileName << endl;
		return;
	}

	// The person's name will be the title for the page

	title = item.GetFullName().GetLastName() + ", " + item.GetFullName().GetFirstName();
	printHTMLhead(htmlPage, title);

	// Here's the formatted item

	//htmlPage << "</font>";
	//htmlPage << "<font size=+2>\n<p>";
	htmlPage << "<p class='contact'>\n";
	htmlPage << "<div><strong>Category:</strong> " << item.GetCategory() << "<br></div>" << endl;

	htmlPage << "<div><br><strong>Address:</strong><br>" << item.GetFullAddress().GetStreetAddress() << "<br>"
		<< item.GetFullAddress().GetCity() << ", " << item.GetFullAddress().GetState()
		<< "<br>" << item.GetFullAddress().GetZip() << "</div>" << endl;

	// Here's the phone number

	htmlPage << "<div><strong>phone:</strong> " << item.GetPhone() << "</div>" << endl;

	// Here's the email item

	// htmlPage << "<p><strong>email:</strong> " << item.email() << endl;
	htmlPage << "<div><strong>email:</strong> <a href='mailto:" << item.GetEmail()
		<< "'> " << item.GetEmail() << "</a></div>\n";

	// Here's the birthday

	htmlPage << "<div><strong>Birthday:</strong> " << item.GetBirthday() << "</div>" << endl;

	// Here's the optional picture

	if (item.GetPictureFile() != " ")
		htmlPage << "<div><img src='" << item.GetPictureFile()
		<< "' /></div>\n";

	htmlPage << "</p>";
	printHTMLend(htmlPage);
	htmlPage.close();
}

// This function prints the required HTML code to start a page

void		printHTMLhead(ostream &os, string title)
{
	string	pageTitle;

	if (title == "")
		pageTitle = "HTML Page";
	else
		pageTitle = title;

	os << "<!doctype htmL>"
		<< "<html>\n<head>\n<title>" << pageTitle << "</title>\n"
		<< "<style>\np.title\n{\ntext-align:center;\n}\n"
		<< "body\n{\nbackground-color:'white';\n}\n"
		<< "p.contact\n{\nfont-size:larger;\n}\n"
		<< "</style>\n"
		<< "</head>\n"
		<< "<body>\n"
		<< "<p class='title'>\n<h1>\n"
		<< pageTitle << "\n</h1>\n</p>\n";
}


// This function prints the required HTML code to end a page

void		printHTMLend(ostream &os)
{
	os << "</body>\n</html>\n";
}
