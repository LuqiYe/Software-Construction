

#include"Person.h"




int Person::setPerson(string name)
{
	int ret=0;
	ifstream in(name);
	if(in.is_open())
	{
		this->name=name;
	}
	else
	{
		vector<string> names;
		
		ifstream in2("AllName");
		string str;
		while(getline(in2,str))
		{
			names.push_back(str);
		}

		names.push_back(name);

		in2.close();
		
		ofstream out("AllName");
		if(out.is_open())
		{
			for(int i=0;i<names.size();i++)
			{
				out<<names[i]<<endl;
			}
		}
		out.close();

		this->name=name;
		ofstream out2(name);
		out2.close();
		ret=1;
	}
	in.close();
	return ret;
}


void Person::readFriends()
{
	ifstream in(this->name+".Friends");
	this->friends.clear();
    if(in.is_open())
	{
		string str;
		while(getline(in,str))
		{
			this->friends.push_back(str);
		}
	}
	in.close();
}
void Person::addFriends(string friendsname)
{
	readFriends();
	ifstream in(friendsname);
	if(!in.is_open())
	{
		cout<<"Invalid friend's name"<<endl;
	}
	else
	{
		if(find(this->friends.begin(), this->friends.end(), friendsname)==this->friends.end())
		{
			this->friends.push_back(friendsname);
		}
	}
	writeFriends();
}
void Person::writeFriends()
{
	ofstream out(this->name+".Friends");
	if(out.is_open())
	{
		for(int i=0;i<this->friends.size();i++)
		{
			out<<this->friends[i]<<endl;
		}
	}
	out.close();
}


void Person::readHashtag()
{
	ifstream in(this->name+".Hashtags");
	this->hashtags.clear();
    if(in.is_open())
	{
		string str;
		while(getline(in,str))
		{
			this->hashtags.push_back(str);
		}
	}
	in.close();
}
void Person::addHashtag(string tagname)
{
	readHashtag();
	if(find(this->hashtags.begin(), this->hashtags.end(), tagname)==this->hashtags.end())
	{
		this->hashtags.push_back(tagname);
	}
	writeHashtag();
}
void Person::writeHashtag()
{
	ofstream out(this->name+".Hashtags");
	if(out.is_open())
	{
		for(int i=0;i<this->hashtags.size();i++)
		{
			out<<this->hashtags[i]<<endl;
		}
	}
	out.close();
}






void Person::readMessage()
{
	ifstream in(this->name);
	this->messages.clear();
    if(in.is_open())
	{
		string str;
		getline(in,str);
		int index=0;
		while(1)
		{
			if(index>=str.length())
				break;
			if(str[index]=='{'&&str[index+1]=='#')
			{
				string tem="{#";
				for(int i=index+2;;i++)
				{
					if((i>=str.length())||(str[i]=='{'&&str[i+1]=='#'))
					{
						Message msg;
						msg.init(tem);
						this->messages.push_back(msg);
						index=i;
						break;
					}
					else
					{
						tem+=str[i];
					}
				}
			}
		}
	}
	in.close();
}
void Person::addMessage(string str)
{
	readMessage();
	Message msg;
	msg.timestamp=timestamp.getNextTime();
	msg.content=str;
	this->messages.push_back(msg);
	writeMessage();
}
void Person::writeMessage()
{
	ofstream out(this->name);
	if(out.is_open())
	{
		for(int i=0;i<this->messages.size();i++)
		{
			out<<this->messages[i].format();
		}
	}
	out.close();
}


void Person::sortMessage()
{
	for(int i=0;i<this->messages.size();i++)
	{
		for(int j=i+1;j<this->messages.size();j++)
		{
			if(this->messages[i].timestamp>this->messages[j].timestamp)
			{
				Message msg=this->messages[i];
				this->messages[i]=this->messages[j];
				this->messages[j]=msg;
			}
		}
	}
}

void Person::printWallMessage()
{
	readMessage();
	sortMessage();
	cout<<"         ==========================================================="<<endl;
	cout<<"         |                    "<<this->name<<"¡¯s Wall Page                     |"<<endl;
	cout<<"         ==========================================================="<<endl;
	cout<<endl;
	for(int i=this->messages.size()-1;i>=0;i--)
	{
		cout<<endl;
		cout<<this->messages[i].content<<endl;
	}
	cout<<endl;
	cout<<"         ==========================================================="<<endl;
	cout<<"         |                 End of "<<this->name<<"¡¯s Wall Pag                   |"<<endl;
	cout<<"         ==========================================================="<<endl;
	cout<<endl;
}

void Person::printHomePage()
{
	vector<Message> allmessage;
	
	vector<string> allnames;
		
	ifstream in2("AllName");
	string str;
	while(getline(in2,str))
	{
		allnames.push_back(str);
	}

	in2.close();

	readFriends();

	for(int i=0;i<allnames.size();i++)
	{
		if(find(this->friends.begin(),this->friends.end(),allnames[i])==this->friends.end()
			&&allnames[i]!=this->name)
		{
			Person p;
			p.name=allnames[i];
			p.readMessage();
			readHashtag();
			for(int j=0;j<p.messages.size();j++)
			{
				int sign=0;
				for(int k=0;k<this->hashtags.size();k++)
				{
					if(p.messages[j].content.find(hashtags[k])!=string::npos)
					{
						sign=1;
						break;
					}
				}
				if(sign==1)
				{
					p.messages[j].name=p.name;
					allmessage.push_back(p.messages[j]);
				}
			}
		}
		else
		{
			Person p;
			p.name=allnames[i];
			p.readMessage();
			for(int j=0;j<p.messages.size();j++)
			{
				p.messages[j].name=p.name;
				allmessage.push_back(p.messages[j]);
			}
		}
	}
	
	for(int i=0;i<allmessage.size();i++)
	{
		for(int j=i+1;j<allmessage.size();j++)
		{
			if(allmessage[i].timestamp<allmessage[j].timestamp)
			{
				Message msg=allmessage[i];
				allmessage[i]=allmessage[j];
				allmessage[j]=msg;
			}
		}
	}



	cout<<"         ==========================================================="<<endl;
	cout<<"         |                     "<<this->name<<"¡¯s Home Page                    |"<<endl;
	cout<<"         ==========================================================="<<endl;

	for(int i=0;;i++)
	{
		if(i>=allmessage.size())
			break;
		if(i>=2)
			break;
		cout<<endl;
		cout<<allmessage[i].name<<" >"<<endl;
		cout<<allmessage[i].content<<endl;
	}

	if(allmessage.size()>2)
	{
		cout<<"                         More message? (yes/no):";
		string choice;
		getline(cin,choice);
		if(choice=="yes")
		{
			for(int i=2;i<allmessage.size();i++)
			{
				cout<<endl;
				cout<<allmessage[i].name<<" >"<<endl;
				cout<<allmessage[i].content<<endl;
			}
		}
	}
	cout<<endl;
	cout<<"         ==========================================================="<<endl;
	cout<<"         |                  End of "<<this->name<<"¡¯s Home Page                |"<<endl;
	cout<<"         ==========================================================="<<endl;
}

