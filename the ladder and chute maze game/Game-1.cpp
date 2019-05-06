


#include"Game.h"


Game::Game()
{
	this->graph=new Graph("Maze1.txt");
	this->start=this->graph->findNodeByName("A1");
	this->cur=this->start;
	this->aim=this->graph->findNodeByName("H6");
	this->steps=0;
	this->path.clear();
}

void Game::welcome()
{
	cout<<"        ==========================================================="<<endl;
	cout<<"        |          Welcome to the Ladder and Chute Maze!          |"<<endl;
	cout<<"        ==========================================================="<<endl;
}

int Game::onemove()
{
	cout<<endl;
	cout<<"You are currently in Room "<<cur->getNodeName()<<" of the Ladder and Chute Maze, you can go";
	int cnt=0;
	for(int i=0;i<4;i++)
	{
		if(cur->getAttachedNode(i)!=NULL)
		{
			if(cnt>0)
			{
				cout<<" or";
			}
			cnt++;
			if(i==0)
				cout<<" North";
			else if(i==1)
				cout<<" East";
			else if(i==2)
				cout<<" South";
			else if(i==3)
				cout<<" West";
		}
	}
	cout<<".. What is your choice? ";
	string str;
	cin>>str;
	int direction=-1;
	if(str=="Q")
	{
		return 0;
	}
	else if(str=="N")
		direction=0;
	else if(str=="E")
		direction=1;
	else if(str=="S")
		direction=2;
	else if(str=="W")
		direction=3;

	if(direction==-1)
	{
		cout<<"Invalid input";
	}
	else if(this->cur->getAttachedNode(direction)==NULL)
	{
		cout<<"Invalid input";
	}
	else
	{
		this->path.push_back(this->cur);
		this->cur=this->cur->getAttachedNode(direction);
		this->steps++;
		while(1)
		{
			if(this->cur->getLadderChuteNode()!=NULL)
			{
				this->path.push_back(this->cur);
				this->cur=this->cur->getLadderChuteNode();
			}
			else
			{
				break;
			}
		}
	}

	return 1;
}

void Game::run()
{
	welcome();
	while(onemove())
	{
		if(this->cur==this->aim)
		{
			this->path.push_back(this->cur);
			cout<<"Congratulations! You have reached the finish point."<<endl;
			break;
		}
	}
	cout<<"You took "<<this->steps<<" steps."<<endl;
	cout<<"The nodes you visited are:";
	for(int i=0;i<this->path.size();i++)
	{
		cout<<" "<<this->path[i]->getNodeName();
	}
	cout<<endl;
}



