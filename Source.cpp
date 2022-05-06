#include"FamilyTree.h"
#include<iostream>
using namespace std;

int main()
{
	FamilyTree a;
	cout << "          !! Welcome To Our Program !!";
	cout << endl << "1) To Insert Person" << endl << "2) To Delete A Person" << endl << "3) To Search A Person" << endl << "4) To Modify A Person" << endl;
	cout << "5) For Outpuut OF Tree "  << endl << "0) To End Program" << endl;

	int section = -1;
	while (true)
	{
		cout << endl << "Enter Section You Wanna Enter: ";
		cin >> section;
		cout << endl;
		cin.ignore();
		if (section == 1)
		{
			int range = 0;
			cout << "Enter Range Of Input's: ";
			cin >> range;
			cin.ignore();
			for (int i = 0;i < range;i++)
			{
				cout << "Input First Name : ";
				char* input1 = new char[100];
				cin.getline(input1, 100);
				cout << "Input Sur Name : ";
				char* input2 = new char[100];
				cin.getline(input2, 100);
				int input3;
				cout << "Enter Birth Year : ";
				cin >> input3;
				int input4;
				cout << "Enter Death Year : ";
				cin >> input4;
				cin.ignore();
				char* input5=new char[50];
				cout << "Enter Gender : ";
				cin.getline(input5, 50);
				a.insert(input1, input2,input3,input4,input5);
			}
		}
		else if(section==2)
		{
			cout << "Enter First Name Of Person You Wanna Delete: ";
			char* ptr1 = new char[100];
			cin.getline(ptr1, 100);
			cout << "Enter Last Name Of Person You Wanna Delete: ";
			char* ptr2 = new char[100];
			cin.getline(ptr2, 100);
			a.root=a.toDelete(ptr1, ptr2);
		}
		else if(section==3)
		{
			cout << "Enter First Name Of Person You Wanna Search: ";
			char* ptr1 = new char[100];
			cin.getline(ptr1, 100);
			cout << "Enter Last Name Of Person You Wanna Search: ";
			char* ptr2 = new char[100];
			cin.getline(ptr2, 100);
			a.SEARCH(ptr1, ptr2);
		}
		else if (section == 4)
		{
			cout << "Enter First Name Of Person You Wanna Modify: ";
			char* ptr1 = new char[100];
			cin.getline(ptr1, 100);
			cout << "Enter Last Name Of Person You Wanna Modify: ";
			char* ptr2 = new char[100];
			cin.getline(ptr2, 100);
			a.Modify(ptr1, ptr2);
			a.inOrder(a.root);
		}
		else if (section == 5)
		{
			a.inOrder(a.root);
		}
		else if (section == 0)
		{
			cout << "                !! Bye Bye !!" << endl << endl;
			break;
		}
	}
	system("pause");
	return 0;
}