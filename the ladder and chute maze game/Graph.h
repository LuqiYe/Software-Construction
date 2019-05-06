
#include<string>
#include<fstream>
#include"Node.h"

using namespace std;


#ifndef GRAPH_H_
#define GRAPH_H_

class Graph 
{
public:
	//node array
	Node* nodes[105];
	//node size
	int noden;

	Graph(string filename);
	void readfile(string filename);

	Node* findNodeByName(string name);



};


#endif
