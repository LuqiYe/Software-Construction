



#include"ChatSystem.h"



void ChatSystem::showtitle()
{
	cout<<"         ==========================================================="<<endl;
	cout<<"         |            Distributed War Eagle Chat System!           |"<<endl;
	cout<<"         ==========================================================="<<endl;
	cout<<endl;
	cout<<"Please enter user name: ";
}

void ChatSystem::showwelcome()
{
	cout<<"         ==========================================================="<<endl;
	cout<<"         | Welcome to Distributed War Eagle Chat System, "<<person.name<<"! |"<<endl;
	cout<<"         ==========================================================="<<endl;
	cout<<endl;
}

void ChatSystem::login()
{
	showtitle();
	string name;
	getline(cin,name);
	person.setPerson(name);
	showwelcome();
}













int ChatSystem::menu()
{
	cout<<endl;
	cout<<"Add Friend (f), Post (p), Follow (t), Wall (w), Home (h), Quit (q)"<<endl;
	cout<<"Enter option:";

	string choice="";
	getline(cin,choice);
	if(choice=="q")
	{
		return 0;
	}
	else if(choice=="f")
	{
		cout<<endl;
		cout<<"Please enter friend¡¯s name: ";
		string name;
		getline(cin,name);
		person.addFriends(name);
		cout<<endl;
		cout<<"         ==========================================================="<<endl;
		cout<<"         |                Added "<<name<<" to Friend¡¯s List             |"<<endl;
		cout<<"         ==========================================================="<<endl;
	}
	else if(choice=="p")
	{
		cout<<endl;
		cout<<"Enter message:"<<endl;
		string str="";
		string line="";
		int n=0;
		while(1)
		{
			getline(cin,line);
			if(line[0]=='#'&&line[1]=='$')
			{
				break;
			}
			else
			{
				if(n==0)
				{
					str+=line;
				}
				else
				{
					str+="\n"+line;
				}
				n++;
			}
		}
		person.addMessage(str);
		cout<<endl;
		cout<<"         ==========================================================="<<endl;
		cout<<"         |                    New message added                    |"<<endl;
		cout<<"         ==========================================================="<<endl;
	}
	else if(choice=="t")
	{
		cout<<"Enter hashtag: ";
		string tag;
		getline(cin,tag);
		person.addHashtag(tag);
	}
	else if(choice=="w")
	{
		person.printWallMessage();
	}
	else if(choice=="h")
	{
		person.printHomePage();
	}
	else
	{
		cout<<"Invalid input, Please input again."<<endl;
	}



	return 1;
}




void ChatSystem::run()
{
	login();

	while(menu()){;}

	cout<<endl;
	cout<<"==========================================================="<<endl;
	cout<<"|      Thank you for using the War Eagle Chat System      |"<<endl;
	cout<<"==========================================================="<<endl;
}

