//***********************************************************************************
//                R E C U R S I V E _ F U N C T I O N S . C P P

/*******************************************************************************************************************************
Name: McKerlton Hyppolite    Z#: Z23590874
Course: Data Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date: 07/20/2021    Due Time: 11:59
Total Points: 25    Assignment: Module 10 Programming Assignment   Date: 07/17/2021

Description: A program that contains two recursive and one non-recursive functions to
			 check if a string is a palindrome.
********************************************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

bool palindrome(const string& s) 
{
	int length = s.length();
	string begin = s.substr(0, 1);
	string end = s.substr((length - 1), 1);

	if (begin == end)
	{
		string temp = s.substr((0 + 1), (length - 2));

		if (temp.length() <= 1)
		{
			return true;
		}
		return palindrome(temp);
	}
	else
	{
		return false;
	}
};

string  printReversel(const string& s) 
{
	int str_len = s.length();

	if (str_len <= 1)
	{
		return s;
	}
	else
	{
		return printReversel(s.substr(1, s.length())) + s.at(0);
	}
};

string printIterReverse(const string& s)
{
	string y;
	for (int i = s.size() - 1;i >= 0;i--)
	{
		y += s[i];
	}
	return y;
};


int main()
{
	string s = "";
	string response = "y";

	while (response == "y" || response == "Y")
	{
		cout << " please enter string: ";
		getline(cin, s);
		if (palindrome(s) == true)
		{
			cout << s << " is a palindrome \n";
		}
		else
		{
			cout << s << " is a not palindrome \n";
		}

		cout << "The Rec-reverse of \"" << s << "\" is \"" << printReversel(s) << "\"" << endl;
		cout << "The Iter-reverse of \"" << s << "\" is \"" << printIterReverse(s) << "\"" << endl;
		cout << endl << "Do you wish to continue (y or Y for yes; n or N for no ? ";
		cin >> response;
		cin.ignore();
	}
	return 0;
}
