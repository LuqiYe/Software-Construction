



#include"Timestamp.h"


int Timestamp::getNextTime()
{
	ifstream in("Timestamp");  
    if(!in.is_open())
	{
		ofstream out("Timestamp");
		if(out.is_open())
		{
			out<<0<<endl;
			out.close();
		}
	}
	else
	{
		in.close();
	}
	ifstream in2("Timestamp");
	int n;
	in2>>n;
	in2.close();
	n++;
	ofstream out("Timestamp");
	out<<n<<endl;
	out.close();
	return n;
}

