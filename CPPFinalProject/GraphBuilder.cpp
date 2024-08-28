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
	Path firstPath;
	paths.push_back(firstPath);
	steps = 0;
	currentNeighvourIndex = 0;
	firstLoop = true;
}



void GraphBuilder::CalculateShortestPathWithBFS( char startPos, char goal, vector<char> currentVisitedList)
{
	if (firstLoop)
	{
		absoluteFirstChar = startPos;
		firstLoop = false;
	}
	//cout << "this itaration starting pose is: " << startPos<<"\n";
	Node firstNode = LocateNodeInListByChar(startPos);
	//cout << "the first node is: " << firstNode.nodeLetter << "\n";
	

	

	
		RecourseAndBuildGraph(startPos, goal, currentVisitedList);
	
	

	Path shortestPath;
	shortestPath = paths[0];

	for (int i = 0; i < paths.size(); i++)
	{
		if (paths[i].singlePath.size() < shortestPath.singlePath.size())
		{
			if (paths[i].singlePath.size() != 0)
			{
				if (paths[i].singlePath[paths[i].singlePath.size() - 1] == tolower(goal))
				{
					shortestPath = paths[i];
				}
			}

		}
	}
	cout << "the shortest path is: ";
	for (char letter : shortestPath.singlePath)
	{
		cout << letter << " ,";
	}
	cout << "with " << shortestPath.singlePath.size() << " steps! \n";
	
}

void::GraphBuilder::RecourseAndBuildGraph(char startPos, char goal, vector<char> currentVisitedList)
{

	Node firstNode = LocateNodeInListByChar(startPos);


	vector<char> visitedNodes = vector<char>();
	vector<char> unVisitedNodes = vector<char>();

	for (int i = 0; i < currentVisitedList.size(); i++)
	{
		visitedNodes.push_back(currentVisitedList[i]);
	}
	for (int i = 0; i < firstNode.nighboursList.size(); i++)
	{
		if (!DoesListContains(firstNode.nighboursList[i].nodeLetter, visitedNodes))
		{
			unVisitedNodes.push_back(firstNode.nighboursList[i].nodeLetter);
		}
	}
	

	
		
		for (int i = 0; i < unVisitedNodes.size(); i++)
		{

			paths[steps].singlePath.push_back(firstNode.nighboursList[i].nodeLetter);
			if (tolower(unVisitedNodes[i]) == tolower(goal))
			{
				
				
				cout << "found Goal \n";
				cout << "visited From " << firstNode.nodeLetter << " to " << firstNode.nighboursList[i].nodeLetter << "\n";
				paths[steps].singlePath.insert(paths[steps].singlePath.begin(), absoluteFirstChar);
				cout << "the paths are:  \n";
				for (Path shem : paths)
				{
					for (char tav : shem.singlePath)
					{
						if (shem.singlePath[shem.singlePath.size() - 1] == goal)
						{
							cout << tav << ", ";
						}
					}
					cout << "\n";
					currentNeighvourIndex = 0;
					Path newpath;
					paths.push_back(newpath);
					steps++;

				}


				break;

			}
			else
			{
				
				visitedNodes.insert(visitedNodes.begin(), firstNode.nodeLetter);
				cout << "visited From " << firstNode.nodeLetter << " to " << firstNode.nighboursList[i].nodeLetter << "\n";
				RecourseAndBuildGraph(unVisitedNodes[i], goal, visitedNodes);

			}
		}
		



		//cout << "this edge has " << firstNode.nighboursList.size() <<" nighbours" << "\n";
		/*if (currentNeighvourIndex == firstNode.nighboursList.size())
		{
			TransferFromUnVisitedTovisited(firstNode.nodeLetter);
		}
		else
		{
			cout << "Not Last Nighbour \n";
			currentNeighvourIndex++;
		}*/

		//cout << "visited From " << firstNode.nodeLetter << " to " << firstNode.nighboursList[i].nodeLetter<< "\n";

		//CalculateShortestPathWithBFS(tolower(firstNode.nighboursList[i].nodeLetter), tolower(goal));



	
}


void GraphBuilder::TransferFromUnVisitedTovisited(char currentchar,  vector<char> currentVisiterList,  vector<char> currentUnVisiterList)
{
	for (int i = 0; i < currentUnVisiterList.size(); i++)
	{
		if (currentchar == currentUnVisiterList[i])
		{
			currentVisiterList.push_back(currentchar);
			currentUnVisiterList.erase(currentUnVisiterList.begin() + i);
		}
	}
}

Node GraphBuilder::LocateNodeInListByChar(char tofind)
{
	int indexer = 0;
	for (int i = 0; i < currentParser.size(); i++)
	{
		indexer++;
		//cout << tofind<<"\n";
		if (tolower( tofind) ==  currentParser[i].nodeLetter)
		{
			//cout << currentParser[i].nodeLetter<<"\n";
			return currentParser[i];
		}

	}
	return NULL;
}

bool GraphBuilder::DoesListContains(char susChar, vector<char> wantedList)
{

	for (int i = 0; i < wantedList.size(); i++)
	{
		if (tolower(susChar) == tolower(wantedList[i]))
		{
			return true;
		}
	}
	return false;
}

