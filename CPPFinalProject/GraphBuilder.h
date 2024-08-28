#pragma once
#include "TextParser.h"
#include "Path.h"
#include <string>
class GraphBuilder
{
public:
	vector<Node> currentParser;
	string shortestPath;
	vector<char> visited;
	vector<char> unVisited;
	vector<Path> paths;
	int steps;
	int currentNeighvourIndex;
	bool firstLoop;
	char absoluteFirstChar;



	void CalculateShortestPathWithBFS(char startPos, char goal, vector<char> currentVisiterList);
	GraphBuilder(vector<Node> graphConteiner);
	void TransferFromUnVisitedTovisited(char currentChar, vector<char> visitedList, vector<char>);
	void RecourseAndBuildGraph(char startPos, char goal, vector<char> currentVisitedList);
	Node LocateNodeInListByChar(char tofind);
	bool DoesListContains(char susChar, vector<char> wantedList);

};

