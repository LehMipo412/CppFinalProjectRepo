#include "GraphBuilder.h"
#include "TextParser.h"



GraphBuilder::GraphBuilder(vector<Node> graphConteiner)
{
	currentParser = graphConteiner;

	for (int i = 0; i < graphConteiner.size(); i++)
	{
		unVisited.push_back(tolower( graphConteiner[i].nodeLetter));
		cout << graphConteiner[i].nodeLetter << ",";
	}
	cout << "\n";
}



void GraphBuilder::CalculateShortestPathWithBFS( char startPos, char goal)
{
	cout << "this itaration starting pose is: " << startPos<<"\n";
	Node firstNode = LocateNodeInListByChar(startPos);
	cout << "the first node is: " << firstNode.nodeLetter << "\n";
	

	if (startPos == goal|| visited.size() == currentParser.size()||steps > currentParser.size())
	{
		return;
	}
	else
	{

		for (int i =0; i< firstNode.nighboursList.size();i++)
		{
			cout << "this edge has " << firstNode.nighboursList.size() <<" nighbours" << "\n";
			TransferFromUnVisitedTovisited(firstNode.nodeLetter);
			cout << "visited From " << firstNode.nodeLetter << " to " << firstNode.nighboursList[i].nodeLetter<< "\n";
			
			CalculateShortestPathWithBFS(tolower(firstNode.nighboursList[i].nodeLetter), goal);

		}

	}
	
}


void GraphBuilder::TransferFromUnVisitedTovisited(char currentchar)
{
	for (int i = 0; i < unVisited.size(); i++)
	{
		if (currentchar == unVisited[i])
		{
			visited.push_back(currentchar);
			unVisited.erase(unVisited.begin() + i);
		}
	}
}

Node GraphBuilder::LocateNodeInListByChar(char tofind)
{
	int indexer = 0;
	for (int i = 0; i < currentParser.size(); i++)
	{
		indexer++;
		cout << tofind<<"\n";
		if (tolower( tofind) ==  currentParser[i].nodeLetter);
		{
			cout << currentParser[i].nodeLetter<<"\n";
			return currentParser[i];
		}

	}
	return NULL;
}

