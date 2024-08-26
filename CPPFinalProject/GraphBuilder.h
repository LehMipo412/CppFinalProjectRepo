#pragma once
#include "TextParser.h"
#include <string>
class GraphBuilder
{
public:
	vector<Node> currentParser;
	string shortestPath;
	vector<char> visited;
	vector<char> unVisited;
	int steps;


	void CalculateShortestPathWithBFS(char startPos, char goal);
	GraphBuilder(vector<Node> graphConteiner);
	void TransferFromUnVisitedTovisited(char currentChar);
	Node LocateNodeInListByChar(char tofind);

};

