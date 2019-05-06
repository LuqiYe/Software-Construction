


#include"Message.h"


void Message::init(string str)
{

	this->timestamp=0;
	int i;
	for(i=2;i<str.length();i++)
	{
		if(str[i]=='#')
			break;
		this->timestamp=this->timestamp*10+str[i]-'0';
	}
	this->content="";
	for(i=i+2;i<str.length();i++)
	{
		if(str[i]=='&'&&str[i+1]=='&')
		{
			this->content+="\n";
			i++;
		}
		else
		{
			this->content+=str[i];
		}
	}

}


string Message::format()
{
	string str="";
    stringstream ss;
	string s;
	ss<<this->timestamp;
	ss>>s;
	str+="{#"+s+"#}";
	for(int i=0;i<this->content.length();i++)
	{
		if(this->content[i]=='\n')
		{
			str+="&&";
		}
		else
		{
			str+=this->content[i];
		}
	}
	return str;
}

