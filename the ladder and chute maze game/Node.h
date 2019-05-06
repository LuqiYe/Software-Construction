
#include<string>


using namespace std;


#ifndef NODE_H_
#define NODE_H_

class Node 
{
public:
	Node(string newname);
	Node();
	void setNodeName(string newname);
	string getNodeName();
	void attachNewNode(Node *newNode, int direction);
	Node *getAttachedNode(int direction);
	void attachLadderChuteNode(Node *newNode);
	Node *getLadderChuteNode();
private:
	string name;
	Node *attachedNodes[4];
	Node *ladderOrChuteNodes;
};


#endif
