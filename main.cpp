// main.cpp
// LinkedList
//
// Created by Khalid Saeed on 10/21/19.
// Copyright © 2019 Khalid Saeed. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
// #include <conio.h>
using namespace std;
string lowercase(string n);
class LinkedList
{
private:
	typedef struct Node
	{
		string name;
		int score;
		// Node* prev;
		Node *next;
		// Node* prev;
	} *nodePtr;		 // makes a typedef and calls it nodePtr
	nodePtr current; // current
	nodePtr temp;	 // temporary
	nodePtr last;
	nodePtr head; // head of list
	int count;	  // num of nodes
public:
	void print();
	LinkedList();
	void Add(string name, int score); // TO ADD a node
	// void Delete(string name, int score);//remove exact person by name and score
	void Delete(string name);	 // overloaded easier way to remove by just name.
	string makeFormal(string n); // makes a string in a more formal format
	// void SortASC();
	LinkedList Insert(LinkedList list, int ascdes); // takes in a regular linkedlist andreturns it in order
	void Addasc(string name, int score);			// TO ADD a node in new linked list in ascendingorder
	void ADDdes(string name, int score);			// ADDs a new liked list in descending order
	void Search(string name);						// searches for name in list
};
LinkedList::LinkedList()
{ // constructor
	// sets values of pointers to null
	current = NULL;
	temp = NULL;
	head = NULL;
	last = 0;
	// prev->next = nullptr;
	count = 0;
}
void LinkedList::Add(string name, int score)
{						  // Add people
	nodePtr n = new Node; // creates a new node
	current = head;		  // sets current node to head in order to loop through list
	last = nullptr;		  // last = null
	n->next = nullptr;	  // starts with next=null
	n->name = name;		  // initalizing a temporary node in order to add it to list
	n->score = score;
	if (head == 0)
	{ // if there is no node the first node is n
		head = n;
	}
	else
	{
		while (current != nullptr) // alogirthm for looping through the node
		{
			if (current->name == name) // if current==name delete the name and set current =head on order to add the same name in the correct spot so it goes through loop again
			{
				Delete(name);	// delete name
				current = head; // current to start from begining in loop
			}
			else if (current->name > name) // if its greater than name than that is the spot so break
				break;
			else
			{
				last = current;
				current = current->next;
			}
		}
		if (current == head) // if it exits loop and curent is head than that means we only have 1 person in and he had same name so we add him in
		{
			n->next = head;
			head = n;
		}
		else
		{
			n->next = current; // puts the person if hes not at the head to the last correct spotin list.the next of n is current and the next of the previous is n
			last->next = n;
		}
	}
	cout << "\nInserted: " << n->name << " with a score of " << n->score; // just to show whats going on.and who was inserted
	count++;
}
void LinkedList::Addasc(string name, int score)
{ // Add people in ascending order:: ::it basically works the same as the one above it but instead of sorting byname it sorts by score
	nodePtr n = new Node;
	current = head;
	last = nullptr;
	n->next = nullptr;
	n->name = name;
	n->score = score;
	if (head == 0)
	{
		head = n;
	}
	else
	{
		while (current != nullptr)
		{
			if (current->score > score) // the only difference here checks score
				break;
			else
			{
				last = current;
				current = current->next;
			}
		}
		if (current == head)
		{
			n->next = head;
			head = n;
		}
		else
		{
			n->next = current;
			last->next = n;
		}
	}
	// count++;
}
void LinkedList::ADDdes(string name, int score)
{ // Add people same as ascending except does it descending order nodePtr n = new Node;
	current = head;
	last = nullptr;
	n->next = nullptr;
	n->name = name;
	n->score = score;
	if (head == 0)
	{
		head = n;
	}
	else
	{
		while (current != nullptr)
		{
			if (current->score < score) // only difference is the less than sign
				break;
			else
			{
				last = current;
				current = current->next;
			}
		}
		if (current == head)
		{
			n->next = head;
			head = n;
		}
		else
		{
			n->next = current;
			last->next = n;
		}
	}
	// count++;
}
void LinkedList::Search(string name)
{				   // Search people
	int found = 0; // a way to check if hes found
	current = head;
	cout << "\nSearching..." << endl; // just to reference searching
	while (current != nullptr)		  // loops through the list and exits when current is null
	{
		if (current->name == name) // enters if equal
		{
			cout << "\nThe person you have searched for has been found: " << makeFormal(current->name) << " with a score " << current->score; // prints the person found.Makeformal is a way to make name look better
			found = 1;																														  // sets found = 1 so it doesn't print the not found below
			break;
		}
		else
		{
			last = current; // allows list to keep moving forward to keep searching
			current = current->next;
		}
	}
	if (found == 0)
		cout << "\n"
			 << makeFormal(name) << " was not found in the list."; // if hes not found
}
void LinkedList::Delete(string name) // deletes a person but also makes pointers	point in the correct direction
{
	if (head == 0) // empty list
	{
		cout << "\nThe list is empty";
	}
	else
	{
		current = head;			   // sets curent to head
		last = nullptr;			   // and before null
		while (current != nullptr) // while its not null
		{
			if (current->name == name) // if the names equal loop outside and break. This is the person we want to delete.There are also no repeated names so its guarenteed to work.
				{
					break;
				}
			else
			{
				last = current;			 // to keep going through loop
				current = current->next; // ^^^^^^^
			}
		}
		if (current == nullptr) // if current is null then the person was not in the list
		{
			cout << "\nAttempted to Delete but " << makeFormal(name) << " is not found";
		}
		else
		{
			if (head == current) // head == current make the head the next one in list so u can	delete the head
				{
					head = head->next;
				}
			else
			{
				last->next = current->next; // make the last equal to the next
			}
			cout << "\nDeleted: " << current->name << " with a score of " << current->score; //show something delete current;													 // what actually deletes
			count--;																		 // the count variable is decremented
		}
	}
}
LinkedList LinkedList::Insert(LinkedList list, int ascdes) // this makes a new list for descending and ascending order. Takes it original list and then returns a different list sorted in that order
{
	LinkedList returning;			// new list
	list.current = list.head;		// list sent in is equal to head
	while (list.current != nullptr) // while its not null
	{
		// cout << "\nHello: " << list.current->name;
		if (ascdes == 0)											   // if variable sent in is 0 we know to sort in ascending format
			returning.Addasc(list.current->name, list.current->score); // call the add in sorted format function in the returning list and send in all the names and scores of the LIST from the parameter.(original list) else if (ascdes == 1) // if one descending
			returning.ADDdes(list.current->name, list.current->score);	  // same as addasc except in descending format
			list.current = list.current->next;
	}
	return returning; // return sorted list
}
void LinkedList::print() // simple printing function
{
	current = head;
	while (current != NULL)
	{
		// cout << "\n************************************************************************************************************************************************";
		string s = current->name;
		s = makeFormal(s);
		cout << "\nName: " << s << " and score of " << current->score << endl;
		current = current->next;
	}
}
string LinkedList::makeFormal(string n) // the make formal its simple and really unneccasary.Used to make a name khalid = Khalid
{
	n[0] = n[0] - 32;
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] == ' ')
			n[i + 1] = n[i + 1] - 32;
	}
	return n;
}
int main(int argc, const char *argv[])
{
	LinkedList l;		// creates an original list
	string name, l1;	// string name and l1 are used later in the get file. I made a complicated code unneccesarily for the get from file. Sorry
	int numsize = 0;	// keeps track of size.
	int numArray[100];	// stores numbers for the scores in an array
	string line[100];	// stores the names in an array
	string final1[100]; // keeps track of inserted names
	string final2[100]; // keeps track of all names
	int score;			// score variable
	// char choice; choice
	int num = 0;	  // counter for array
	int num1 = 0;	  // counter for array
	ifstream theFile; // opening file
	theFile.open("a3.txt");
	int i = 0; // setting i=0 which is keeping track of number of lines in file
	// int j = 0;
	while (getline(theFile, l1)) // getting every line in file
	{
		line[i] = l1;
		i++;
	}
	// cout << i << endl;
	// here is where things get confusing this is like a way to parse my the line
	for (int j = 0; j < i; j++) // nested loop to get every line and character
	{
		for (int x = 0; x < line[j].length(); x++) // every character in line loop
		{
			if (line[j][x] == ' ') // one it sees a space it knows that everything before is a string
			{
				final1[num] = lowercase(line[j].substr(0, x)); // so it gets the substring of it and stores them into the two string arrays
				final2[num1] = lowercase(line[j].substr(0, x));
				// fix to get anysize number
				int n = x;				   // makes a new variable and sets it equal it X
				while (line[j][n] != NULL) // checks how many spaces after X is not null
				{
					n++;
				}
				numsize = n - x;									  // subtract X from N and you get the amount of characters in the number after the space
				numArray[num] = stoi(line[j].substr(x + 1, numsize)); // now you use stoi to convert that string into an integer
				// cout << final1[num] << endl;
				num++;	// increment num and num1. NUM is for inserting
				num1++; // num1 is for all names
			}
			if (line[j][line[j].length() - 1] > 'A' && line[j][0] != '%' && x >= 3 && line[j][x + 1] == NULL)
			{
				final2[num1] = lowercase(line[j].substr(0, line[j].length()));
				// numArray[num] = stoi(line[j].substr(x + 1, 2));
				// cout << final2[num1] <<"----------"<< endl;
				num1++;
			}
		}
	}
	// cout << num1;
	// l.Add("help", 23);
	// for (int j = 0; j < i; j++)
	cout << line[j] << endl;
	// LinkedList printer;
	// printer = l;
	LinkedList l12;	  // second list
	LinkedList l2;	  // third list
	int printer = 0;  // printer
	int j = 0;		  // j
	int counterI = 0; // coounters
	int counter = 0;  // counters
	while (j < i)
	{
		if (line[j][0] == '%') // if the first character is %
		{
			// cout << line[j] << "hi" << endl;
			if (line[j] == "%INSERT") // if its insert
			{
				cout << "\nInserting**********************************************************" << endl;
				// cout << "\nInsertingFUNCTION---------------------------------------------------------------------------------------------------";
				while (line[j + 1][0] != '%' || line[j + 1][1] == 'I') // loop and fill every nameuntil u see the next %
				{
					// cout << "\nInserting: " << final1[counterI] << " whose score is " <<
					numArray[counterI];
					l.Add(final1[counterI], numArray[counterI]);
					counter++;
					counterI++;
					j++;
				}
				printer = 1;
			}
			else if (line[j] == "%VISIT")
			{ // visit if printer is 1 print orignal 2 print ascending 3 print descending
				cout << "\nVisiting**********************************************************" << endl;
				if (printer == 1)
					l.print();
				else if (printer == 2)
				{
					cout << "\nSorted Order: Ascending" << endl;
					l12.print();
				}
				else if (printer == 3)
				{
					cout << "\nSorted Order: Descending" << endl;
					l2.print();
				}
			}
			else if (line[j] == "%DELETE")
			{ // delete
				// cout << "\nDELETINGFUNCTION---------------------------------------------------------------------------------------------------";
				// cout << j;
				// cout << final2[counter] << endl;
				cout << "\nDeleteing*****************************************************************************" << endl;
				// cout<<j;
				while (line[j + 1][0] != '%' || line[j + 1][1] == 'D') // delete every name till u see the next %
				{
					// cout << j << endl;
					// cout << counter;
					// cout << "\nDeleting: " << final2[counter];// << " whose score is " <<
					numArray[counter];
					// cout<<counter;
					// cout<<"\n"<<final2[counter];
					l.Delete(final2[counter]);
					counter++;
					j++;
				}
			}
			else if (line[j] == "%SEARCH")
			{ // searcher
				cout << "\nSearching******************************************************************************" << endl;
				while (line[j + 1][0] != '%' || line[j + 1][1] == 'S') // search every name till you
					see next %
					{
						l.Search(final2[counter]);
						counter++;
						j++;
					}
			}
			else if (line[j] == "%SORTDES")
			{ // sorter
				l12 = l12.Insert(l, 1);
				printer = 2;
			}
			else if (line[j] == "%SORTASC")
			{ // sorter
				// cout << "\n\n\n\n\n\n\n\n\n\n";
				l2 = l2.Insert(l, 0); // sends the list ///
				printer = 3;		  // for the printer
									  // l2.print();
			}
			else if (line[j] == "%END")
			{ // if its %END set the while loop incremeter equal to i to exit
				j = i;
			}
		}
		j++;
	}
	cout << "\n***************************************************************************************";
	// l.print();
	theFile.close(); // close file
	return 0;
}
string lowercase(string n) // makes every character lowercase for easy comparison
{
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] < 91 && n[i] != ' ' && n[i] >= 65)
			n[i] = n[i] + 32;
	}
	return n;
}
/*
 do {
 cout << "\nPlease enter a name: ";
 getline(cin,name);
 cout << "\nPlease enter " << name << "'s score: ";
 cin >> score;
 cout << "Would you like to enter another person. Y/N";
 choice = _getch();
 while (1)
 {
 if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
 break;
 choice = _getch();
 }
 cin.ignore();
 name = lowercase(name);
 l.Add(name,score);
 } while (choice == 'Y' || choice == 'y');
 l.print();
 do {
 cout << "\nPlease enter a name you would like to delete: ";
 getline(cin, name);
 name = lowercase(name);
 l.Delete(name);
 cout << "Would you like to delete another person. Y/N";
 choice = _getch();
 while(1)
 {
 if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
 break;
 choice = _getch();
 }
 } while (choice == 'Y' || choice == 'y');
 l.print();*/