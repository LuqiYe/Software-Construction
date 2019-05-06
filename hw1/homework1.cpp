// homework1.cpp : 定义控制台应用程序的入口点。
// Function: homwwoek1
// Name: Luqi Ye
// Information: lzy0021@auburn.edu
// School file: /home/u1/lzy0021/comp2710

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	cout << "===========================================================" << endl;
	cout << "           Welcome to our Wareagle Char Group!" << endl;
	cout << "===========================================================" << endl << endl << endl;
	string usernameE = "";
	string messageE = "";
	string result = "";
	string yn = "";

	do {
		cout << "Enter user name: ";
		getline(cin, usernameE);
		result += "\n" + usernameE + " >";
		cout << "Enter message: ";
		while (1)
		{
			getline(cin, messageE);
			if (messageE == "#$")
				break;
			result += ("\n" + messageE);
		}
		result += "\n";
		cout << "\nAny more users? ";
		getline(cin, yn);
		if (yn == "yes") {
			cout << endl;
		}

	} while (yn == "yes");

	cout << "\nCurrent Chat Messages >\n";
	cout << result;

	return 0;
}
