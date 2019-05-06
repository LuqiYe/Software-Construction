




#ifndef MESSAGE_H_
#define MESSAGE_H_

#include<string>
#include <sstream>

using namespace std;


class Message
{
public:
	//author name of the message
	string name;
	//time stamp
	int timestamp;
	//content of the message
	string content;

	//init message 
	void init(string str);
	//change into format
	string format();

};


#endif

