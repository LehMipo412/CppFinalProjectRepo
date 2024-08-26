#pragma once
using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <istream>
#include <fstream> 
#include "Node.h";

class TextParser
{
public:

	ifstream fileToRead;
	vector<string> textContent;
	string firstLine;
	vector<Node> graphFounders;

	void DeconstruuctTextToData();
	void PopulateFirstNodes();
	void PopulateNeighbours();
	bool IsSameNodeInFirstLine(char susNode);

	TextParser();

};

