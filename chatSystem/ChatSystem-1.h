
#ifndef CHATSYSTEM_H_
#define CHATSYSTEM_H_


#include<iostream>

#include<fstream>

#include"Person.h"


using namespace std;

//the whole system
class ChatSystem
{
public:

	//person instance
	Person person;
	
	//show the title
	void showtitle();
	//show the welcome message
	void showwelcome();
	//login method
	void login();
	//show menu
	int menu();



	//run the system
	void run();


};

#endif


