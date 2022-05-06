#pragma once
#include<cstring>
#include<iostream>
using namespace std;

struct person {
	char* fname;
	char* sname;
	int birthYear, deathYear;
	char* gender;
	person* l_link;
	person* r_link;
	int childs;
};

class FamilyTree {
public:
	person* root;
	FamilyTree()
	{
		root = NULL;
	}
	person* newNode(char* firstName,char* surName,int BY,int DY, char* sex)
	{
		person* node = new person;
		node->fname = firstName;
		node->sname = surName;
		node->birthYear = BY;
		node->deathYear = DY;
		node->gender = sex;
		node->l_link = NULL;
		node->r_link = NULL;
		node->childs = 0;
		return(node);
	}
	person* insertIntoTree(person* leaf, char* input1,char* input2,int input3,int input4, char* input5)
	{
		person* ptr = leaf;
		if (ptr == NULL)
		{
			return (newNode(input1,input2,input3,input4,input5));
		}
		else
		{
			if (strcmp(input2, ptr->fname) == 0)
			{
				if (ptr->childs == 0)
				{
					ptr->l_link = insertIntoTree(ptr->l_link, input1, input2, input3, input4, input5);
					ptr->childs = 1;
				}
				else if(ptr->childs == 1)
				{
					ptr->r_link = insertIntoTree(ptr->r_link, input1, input2, input3, input4, input5);
					ptr->childs = 2;
				}
			}
			if(ptr->l_link != nullptr && strcmp(input2, ptr->fname) != 0)
			{
				ptr->l_link = insertIntoTree(ptr->l_link, input1, input2, input3, input4, input5);
			}
			if (ptr->r_link != nullptr && strcmp(input2, ptr->fname) != 0)
			{
				ptr->r_link = insertIntoTree(ptr->r_link, input1, input2, input3, input4, input5);
			}
			if (ptr->l_link == NULL && ptr->r_link == NULL && strcmp(input2, ptr->fname) != 0)
			{
			//if surname not found
			}
		}

		return ptr;
	}
	void insert(char* input1,char* input2,int input3,int input4,char* input5)
	{
		root = insertIntoTree(root, input1,input2, input3, input4, input5);
	}
	bool checkName(char* name1, char* name2)
	{
		if (name1 != nullptr && name2 != nullptr)
		{
			int l1, l2;
			for (l1 = 0;*(name1 + l1) != '\0';l1++);
			for (l2 = 0;*(name2 + l2) != '\0';l2++);
			if (l1 == l2)
			{
				for (int i = 0;i < l1;i++)
				{
					if (*(name1 + i) != *(name2 + i))
					{
						return false;
					}
				}
				return true;
			}
		}
		return false;
	}
	//proot => Parent Root
	person* deleteFromTree(person* proot, person* root, char* fname, char* sname,int direction)
	{
		if (checkName(fname,root->fname) && checkName(sname,root->sname))
		{
			person* temp = root;
			root = NULL;
			delete[] temp;
			proot->childs--;
			return root;
		}
		if (strcmp(fname, root->fname) != 0 && strcmp(sname, root->sname) == 0)
		{
			if (checkName(fname, root->l_link->fname) == true)
			{
				root->l_link = deleteFromTree(root,root->l_link,fname,sname,-1);
			}
			else if (strcmp(fname, root->r_link->fname) == 0)
			{
				root->r_link = deleteFromTree(root, root->r_link, fname, sname, 1);
			}
		}
		return root;
	}
	person* toDelete(char* input1,char* input2)
	{
		if (strcmp(input1, root->fname) == 0 && strcmp(input2, root->fname) == 0)
		{
			root = nullptr;
		}
		else {
			root = deleteFromTree(nullptr, root, input1, input2, 0);
		}
		return root;
	}
	
	person* toSearch(person* root,char* input1, char* input2)
	{
		if (checkName(input1, root->fname)  && checkName(input2, root->sname) )
		{
			cout << "Person Got Found Having Childs Tree: " << endl;
			inOrder(root);
			return root;
		}
		else 
		{
			if (checkName(input1, root->fname)==false && checkName(input2, root->sname))
			{
				toSearch(root->l_link, input1, input2);
			}
			else if (checkName(input1, root->fname)==false && checkName(input2, root->sname))
			{
				toSearch(root->r_link, input1, input2);
			}
		}
		return root;
	}
	void SEARCH(char* input1, char* input2)
	{
		root = toSearch(root, input1, input2);
		inOrder(root);
	}
	void inOrder(person* root)
	{
		if (root != NULL)
		{
			cout <<"\nFirst Name=>"<< root->fname << " \nSurName=> " << root->sname << " \nChilds=> " << root->childs << endl;
			cout << "Birth Year=> " << root->birthYear << "\nDeath Year=> " << root->deathYear << "\nGender=> " << root->gender << endl<<endl;
			inOrder(root->l_link);
			inOrder(root->r_link);
		}
	}
	void Modify(char* ptr1, char* ptr2)
	{
		root = toSearch(root, ptr1, ptr2);
		if (root != nullptr)
		{
			cout << "Person got found, What you wanna modify ?" << endl;
			cout << "a) To Modify First Name \n b)To Modify Sur Name \n c)To Modify Birth Year \n d)To Modify Death Year \n e)To Modify Gender \n 0) To End Modification" << endl;
			char entry;
			cout << "Enter Operations: ";
			cin >> entry;
			cin.ignore();
			if (entry == 'a')
			{
				char* ptr = new char[100];
				cout << "Enter new first Name: ";
				cin.getline(ptr, 100);
				root->fname = ptr;
			}
			else if (entry == 'b')
			{
				char* ptr = new char[100];
				cout << "Enter new Sur Name: ";
				cin.getline(ptr, 100);
				root->sname = ptr;
			}
			else if (entry == 'c')
			{
				int ptr ;
				cout << "Enter new Birth Year: ";
				cin >> ptr;
				cin.ignore();
				root->birthYear = ptr;
			}
			else if (entry == 'd')
			{
				int ptr;
				cout << "Enter new Death Year: ";
				cin >> ptr;
				cin.ignore();
				root->deathYear = ptr;
			}
			else if (entry == 'e')
			{
				char* ptr = new char[100];
				cout << "Enter new Gender: ";
				cin.getline(ptr, 100);
				root->gender = ptr;
			}
			else if (entry == '0')
			{
				cout << " => MODIFICAION END"<<endl;
			}
		}
	}
	void destroyTree(person* tree)
	{
		cout << "Destruction" << endl;
		if (tree != NULL)
		{
			destroyTree(tree->l_link);
			destroyTree(tree->r_link);
			person* temp = tree;
			tree = NULL;
			delete temp;
		}
	}
	~FamilyTree()
	{
		destroyTree(root);
	}
};
