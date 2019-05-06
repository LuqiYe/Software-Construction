




#ifndef PERSON_H_
#define PERSON_H_

#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include <algorithm>
#include"Message.h"
#include"Timestamp.h"

using namespace std;


class Person
{
public:

	Timestamp timestamp;

	string name;
	vector<string> friends;
	vector<string> hashtags;
	vector<Message> messages;

	
	//============ people operations ==============
	int setPerson(string name);

	//============ friends operations ==============
	void readFriends();
	void addFriends(string friendsname);
	void writeFriends();

	
	//============ hashtag operations ==============
	void readHashtag();
	void addHashtag(string tagname);
	void writeHashtag();

	
	//============ message operations ==============
	void readMessage();
	void addMessage(string str);
	void writeMessage();

	void sortMessage();

	void printWallMessage();

	void printHomePage();

};


#endif

