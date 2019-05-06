#include<iostream>

#include"Timestamp.h"
#include"Person.h"
#include"Message.h"
#include"ChatSystem.h"

using namespace std;







//=========== for test ===============
void testPerson()
{
	Person p;
	p.name="a";
	p.readFriends();
	p.addFriends("Tom");
	p.addFriends("Jerry");
	p.addFriends("Tim");
}
void testHashtag()
{
	Person p;
	p.name="a";
	p.addHashtag("11");
	p.addHashtag("222");
	p.addHashtag("33");
}
void testAddPerson()
{
	Person p;
	p.name="Tom";
	p.addMessage("abs");
}
//=========== for test ===============





int main()
{
	ChatSystem chatsystem;
	chatsystem.run();
}

