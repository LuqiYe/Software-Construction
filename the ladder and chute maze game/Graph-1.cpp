

#include"Graph.h"


Graph::Graph(string filename)
{
	noden=0;
	for(int i=0;i<105;i++)
	{
		nodes[i]=NULL;
	}
	readfile(filename);
}

Node* Graph::findNodeByName(string name)
{
	for(int i=0;i<noden;i++)
	{
		if(nodes[i]->getNodeName()==name)
			return nodes[i];
	}
	return NULL;
}

void Graph::readfile(string filename)
{
	ifstream in(filename);
	string name;
	while(in>>name)
	{
		Node* node=findNodeByName(name);
		if(node==NULL)
		{
			nodes[noden++]=new Node(name);
			node=nodes[noden-1];
		}

		for(int i=0;i<5;i++)
		{
			in>>name;
			if(name=="*")
				continue;
			Node* othernode=findNodeByName(name);
			if(othernode==NULL)
			{
				nodes[noden++]=new Node(name);
				othernode=nodes[noden-1];
			}
			if(i<4)
				node->attachNewNode(othernode,i);
			else
				node->attachLadderChuteNode(othernode);
		}
	}
}



