#include "TextParser.h"
#include <iostream>
#include <istream>
#include <fstream> 
#include <string>

TextParser::TextParser()
{
	graphFounders.clear();
}

void TextParser::DeconstruuctTextToData()
{
	fileToRead.open("TextToRead.txt");

	if (!fileToRead.is_open())
	{
		cout << "file failed to open, maybe the path is wrong?";
		throw exception();
	}

	while (getline(fileToRead, firstLine))
	{
		textContent.push_back(firstLine);
		cout << firstLine<<"\n";
	}
	firstLine = textContent[0];
	








	fileToRead.close();
}

void TextParser::PopulateFirstNodes()
{
	for (char shem : firstLine)
	{
		if (shem != ',' && shem != ' ')
		{
			if (!IsSameNodeInFirstLine( tolower(shem)))
			{
				graphFounders.push_back(tolower( shem));
				cout << shem << "\n";
			}
			else
			{
				cout << "Prepare for trouble, and make it double - you have more than 1 node in the first line";
				throw exception();
			}

		}
		
	}
}

void TextParser::PopulateNeighbours()
{
	for (int i = 1; i < textContent.size(); i++)
	{
		for (int j = 0; j < graphFounders.size();  j++)
		{
			if (tolower( graphFounders[j].nodeLetter )== tolower( textContent[i][0]))
			{
				graphFounders[j].nighboursList.push_back(tolower( textContent[i][2]));
				cout << graphFounders[j].nodeLetter << "<------>" << textContent[i][2] << "\n";
			}
		}
	}

}

bool TextParser::IsSameNodeInFirstLine(char susNode)
{

	for (int i = 0; i < graphFounders.size(); i++)
	{
		if (tolower(susNode) == tolower(graphFounders[i].nodeLetter))
		{
			return true;
		}
	}

	return false;
}
