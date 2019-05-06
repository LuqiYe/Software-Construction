// War Eagle Chat System.cpp : Defines the entry point for the console application.
//program: lab 1
//name: War Eagle Chat System
//7/3/2017
//lzy0021@auburn.edu
//Luqi Ye
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;
class User;

class HashTagList
{
public:
	HashTagList();
	void addTag(string tag, User u);
	vector<string> getTagByUser(User u);
private:
	map<string, vector<User> > tags;
};

class FriendList
{
public:
	FriendList();
	void addFriend(User user);
	vector<User> getFriends();
private:
	vector<User> friends;
};

class WallPage
{
public:
	WallPage();
	void addMessage(string m);
	void show();
private:
	vector<string> message;
};

class HomePage
{
public:
	HomePage();
	void show(User user, vector<string> tag);
	void addMessage(string m);
	bool brelated(string m, User u, vector<string> tag);
private:
	vector<string> hMessage;
};

class User
{
public:
	User(string n);
	string getName();
	vector<User> getFriends();
	void addFriend(User u);
	void postMessage(string m);
	void followTag(string tag);
	void showWallPage();
	void showHomePage();
private:
	string name;
	FriendList myFriends;
	WallPage myWallPage;
	HomePage myHomePage;
};

class Menu
{
public:
	Menu();
	bool showMenu();
	int createUser();
	void postMessage();
	void wallPage();
	void homePage();
	void addFriend();
	void followHashtag();
	void changeUser();
	void showTitle(string str);
private:
	char choose;
	int curUser;
	vector<User> users;
	HashTagList tagList;
	HomePage homeList;
};

class System
{
public:
	System();
	void run();
private:
	Menu menu;
};


int main(int argc, const char * argv[]) {
	System s;
	s.run();
	return 0;
}

Menu::Menu()
{
	choose = ' ';
	curUser = -1;
}

bool Menu::showMenu()
{
	cout << "Create new user(n), Post (p), Wall page (w), Home page (h), Add friend (f), Follow hashtag (t), Change user (c), Quit (q)" << endl;
	cout << "Enter option: ";
	cin >> choose;
	string str, tmp;

	switch (choose) {
	case 'n':
		curUser = createUser();
		break;

	case 'p':
		postMessage();
		break;

	case 'w':
		wallPage();
		break;

	case 'h':
		homePage();
		break;

	case 'f':
		addFriend();
		break;

	case 't':
		followHashtag();
		break;

	case 'c':
		changeUser();
		break;

	case 'q':
		showTitle("|     Thank you for using War Eagle Chat System     |");
		return false;

	default:
		cout << "invalid input" << endl;
		break;
	}
	return true;
}

int Menu::createUser()
{
	string str;
	cout << endl << "Please enter user name: ";
	cin >> str;
	showTitle("|     Welcome to War Eagle Chat System," + str + "!     |");
	for (int i = 0; i < users.size(); ++i)
	{
		if (users[i].getName() == str)
			return i;
	}
	users.push_back(User(str));
	return users.size() - 1;
}

void Menu::postMessage()
{
	if (curUser >= 0)
	{
		string str, tmp;
		cout << endl << "Enter message:" << endl;
		while (true)
		{
			getline(cin, tmp);
			if (tmp == "#$")
				break;
			str += tmp;
			str += "\n";
		}
		users[curUser].postMessage(str);
		homeList.addMessage(users[curUser].getName() + " >" + str);
	}
	else
	{
		cout << "please create a user" << endl;
	}
	cout << "\n" << setfill('=') << setw(101) << "" << endl;
}

void Menu::wallPage()
{
	if (curUser >= 0)
	{
		string str;
		str = "|     " + users[curUser].getName() + "\'s Wall Page     |";
		showTitle(str);
		users[curUser].showWallPage();
	}
	else
	{
		cout << "please create a user" << endl;
	}
	cout << "\n" << setfill('=') << setw(101) << "" << endl;
}

void Menu::homePage()
{
	if (curUser >= 0)
	{
		string str = "";
		str = "|     " + users[curUser].getName() + "\'s Home Page     |";
		showTitle(str);
		homeList.show(users[curUser], tagList.getTagByUser(users[curUser]));
	}
	else
	{
		cout << "please create a user" << endl;
	}

}


void Menu::showTitle(string str)
{
	cout << endl;
	cout << "\t" << setfill('=') << setw(str.length()) << "" << endl;
	cout << "\t" << str << endl;
	cout << "\t" << setfill('=') << setw(str.length()) << "" << endl << endl;
}

void Menu::followHashtag()
{
	if (curUser >= 0)
	{
		string str;
		cout << endl << "Enter hashtag topic: ";
		cin >> str;
		tagList.addTag(str, users[curUser]);
	}
	else
	{
		cout << "please create a user" << endl;
	}
	cout << "\n" << setfill('=') << setw(101) << "" << endl;
}

void Menu::changeUser()
{
	string str;
	cout << "\nEnter user\'s name: ";
	cin >> str;
	bool b = false;
	for (int i = 0; i < users.size(); ++i)
	{
		if (users[i].getName() == str)
		{
			b = true;
			curUser = i;
			str = "|     Welcome back to War Eagle Chat System," + str + "!     |";
			cout << "\n\t=======================================================\n";
			cout << "\t" << str;
			cout << "\n\t=======================================================\n\n";
			break;
		}
	}
	if (!b)
	{
		cout << "invalid input" << endl;
	}
	
}

void Menu::addFriend()
{
	if (curUser >= 0)
	{
		string name;
		bool b = false;
		cout << endl << "Enter friend\'s name: ";
		cin >> name;
		for (int i = 0; i < users.size(); ++i)
		{
			if (i == curUser)
				continue;
			if (users[i].getName() == name)
			{
				users[curUser].addFriend(users[i]);
				b = true;
				break;
			}
		}
		if (!b)
		{
			cout << "invalid input" << endl;
		}
	}
	else
	{
		cout << "please create a user" << endl;
	}
	cout << "\n" << setfill('=') << setw(101) << "" << endl;
}

User::User(string n)
{
	name = n;
}

vector<User> User::getFriends()
{
	return myFriends.getFriends();
}

void User::addFriend(User u)
{
	myFriends.addFriend(u);
}

void User::postMessage(string m)
{
	myWallPage.addMessage(m);
}

void User::showWallPage()
{
	myWallPage.show();
}

string User::getName()
{
	return name;
}

void User::showHomePage()
{

}

FriendList::FriendList()
{

}

void FriendList::addFriend(User user)
{
	friends.push_back(user);
}

vector<User> FriendList::getFriends()
{
	return friends;
}

WallPage::WallPage()
{

}

void WallPage::addMessage(string m)
{
	message.insert(message.begin() + 0, m);
}

void WallPage::show()
{
	int i = 0;
	string str;
	for (i = 0; i < message.size(); ++i)
	{
		if (i < 2)
			cout << message[i] << endl;
		else
			break;
	}
	if (message.size() > 2)
	{
		cout << "\t\t\t\tMore message? (yes/no): ";
		cin >> str;
		if (str == "yes")
		{
			for (i = 2; i < message.size(); ++i)
			{
				cout << message[i] << endl;
			}
		}
	}
}

System::System()
{
	menu.showTitle("|     Welcome to War Eagle Chat System!     |");
}

void System::run()
{
	bool ret = true;
	while (ret)
	{
		ret = menu.showMenu();

	}
}

HashTagList::HashTagList()
{

}

void HashTagList::addTag(string tag, User u)
{
	if (tags.count(tag))
	{
		tags[tag].push_back(u);
	}
	else
	{
		vector<User> us;
		us.push_back(u);
		tags[tag] = us;
	}
}

vector<string> HashTagList::getTagByUser(User u)
{
	vector<string> tag;
	for (map<string, vector<User> >::iterator it = tags.begin(); it != tags.end(); ++it)
	{
		for (int i = 0; i < it->second.size(); ++i)
		{
			if (it->second[i].getName() == u.getName())
			{
				tag.push_back(it->first);
				break;
			}
		}
	}
	return tag;
}

HomePage::HomePage()
{

}

void HomePage::show(User user, vector<string> tag)
{
	int i = 0;
	string str;
	int count = 0;
	for (; i < hMessage.size(); ++i)
	{
		if (count == 2)
			break;
		if (brelated(hMessage[i], user, tag))
		{
			++count;
			cout << hMessage[i] << endl;
		}
	}
	if (count == 2)
	{
		cout << "\t\t\t\tMore message? (yes/no): ";
		cin >> str;
		if (str == "yes")
		{
			for (; i < hMessage.size(); ++i)
			{
				if (brelated(hMessage[i], user, tag))
				{
					cout << hMessage[i] << endl;
				}
			}
		}
	}
}

bool HomePage::brelated(string m, User u, vector<string> tag)
{
	if (m.find(u.getName() + " >") == 0)
		return true;
	for (int i = 0; i < u.getFriends().size(); ++i)
	{
		if (m.find(u.getFriends()[i].getName() + " >") == 0)
			return true;
	}
	for (int i = 0; i < tag.size(); ++i)
	{
		if (m.find(tag[i]) != -1)
			return true;
	}
	return false;
}

void HomePage::addMessage(string m)
{
	hMessage.insert(hMessage.begin(), m);
}


