

#include"Node.h"





Node::Node(string newname)
{
	this->name=newname;
	for(int i=0;i<4;i++)
		this->attachedNodes[i]=NULL;
	this->ladderOrChuteNodes=NULL;
}
Node::Node()
{
	this->name="";
	for(int i=0;i<4;i++)
		this->attachedNodes[i]=NULL;
	this->ladderOrChuteNodes=NULL;
}
void Node::setNodeName(string newname)
{
	this->name=newname;
}
string Node::getNodeName()
{
	return this->name;
}
void Node::attachNewNode(Node *newNode, int direction)
{
	this->attachedNodes[direction]=newNode;
}
Node * Node::getAttachedNode(int direction)
{
	return this->attachedNodes[direction];
}
void Node::attachLadderChuteNode(Node *newNode)
{
	this->ladderOrChuteNodes=newNode;
}
Node * Node::getLadderChuteNode()
{
	return this->ladderOrChuteNodes;
}


