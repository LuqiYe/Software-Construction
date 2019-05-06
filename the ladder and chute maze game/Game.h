
#include<iostream>
#include<string>
#include<vector>
#include"Graph.h"

using namespace std;


#ifndef GAME_H_
#define GAME_H_

class Game 
{
public:
	//graph pointer
	Graph* graph;
	//start node pointer
	Node* start;
	//aim node pointer
	Node* aim;
	//current node pointer
	Node* cur;
	//step count
	int steps;
	//path vector
	vector<Node*> path;

	Game();

	void welcome();

	void run();

	int onemove();


};


#endif
