#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include "VectorCompare.h"

using namespace std;

void VectorCompare::RunFileCompare(string originalListFileName, string upToDateListFileName)
{
	FillOriginalAndUpToDateVectors(originalListFileName, upToDateListFileName);
	CompareVectors();
	WriteVectorsToFile();
	ClearVectors();
}

VectorCompare::VectorCompare()
{
	tempString = "";
	inStreamChar = '\0';
	NumOfCharReadIn = 1;
}

void VectorCompare::FillOriginalAndUpToDateVectors(string originalListFileName, string upToDateListFileName)
{
	FillOriginalVector(originalListFileName);
	FillUpToDateVector(upToDateListFileName);
}

void VectorCompare::FillOriginalVector(string originalListFileName)
{
	FillVector(originalListFileName, originalVector);
}

void VectorCompare::FillUpToDateVector(string upToDateListFileName)
{
	FillVector(upToDateListFileName, upToDateVector);
}

void VectorCompare::FillVector(string fileName, vector<string> &vectorName)
{
	OpenAndCheckForFile(fileName, inStream);
	ReadInFileAndFillVector(vectorName);
	CloseFile(inStream);
}

void VectorCompare::OpenAndCheckForFile(string fileName, fstream &stream)
{
	stream.open(fileName);
	if (stream.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}
}

void VectorCompare::CloseFile(fstream &stream)
{
	stream.close();
}

void VectorCompare::ReadInFileAndFillVector(vector<string> &vectorName)
{
	ClearStringAndGetChar();
	CheckForSpaceOrEmptyLine();
	while (!inStream.eof())
	{
		tempString.append(NumOfCharReadIn, inStreamChar);
		getCharacterFromFile();
		if (inStreamChar == '\n')
		{
			FillIntoVector(vectorName);
			tempString.clear();
			CheckForSpaceOrEmptyLine();
		}
	}
	CheckForLastStringInFile(vectorName);
}

void VectorCompare::ClearStringAndGetChar()
{
	tempString.clear();
	getCharacterFromFile();
}

void VectorCompare::CheckForSpaceOrEmptyLine()
{
	while ((inStreamChar == ' ') || (inStreamChar == '\n') && (!inStream.eof()))
		getCharacterFromFile();
}

void VectorCompare::getCharacterFromFile()
{
	inStream.get(inStreamChar);
}

void VectorCompare::FillIntoVector(vector<string> &vectorName)
{
	vectorName.push_back(tempString);
}

void VectorCompare::CheckForLastStringInFile(vector<string> &vectorName)
{
	if (!(tempString == "" || tempString == "\n"))
		FillIntoVector(vectorName);
}

void VectorCompare::CompareVectors()
{
	unsigned int index = 0;
	while (index < originalVector.size())
	{
		if (binary_search(getBeginningOfVectorIterator(), getEndOfVectorIterator(), originalVector.at(index)))
		{
			if (CheckForCopyElement(index))
				copyElementsInOriginalVector.push_back(originalVector.at(index));
			else
				matchingElementsVector.push_back(originalVector.at(index));
		}
		else
		{
			nonMatchingElementsVector.push_back(originalVector.at(index));
		}
		index++;
	}
}

vector<string>::iterator VectorCompare::getBeginningOfVectorIterator()
{
	return upToDateVector.begin();
}

vector<string>::iterator VectorCompare::getEndOfVectorIterator()
{
	vector<string>::iterator temp = upToDateVector.begin();
	return (temp + (upToDateVector.size()));
}

bool VectorCompare::CheckForCopyElement(unsigned int index)
{
	if (index > 0)
		if (originalVector.at(index) == originalVector.at(index - 1))
			return true;
		else
			return false;
	else
		return false;
}

void VectorCompare::WriteVectorsToFile()
{
	WriteToFile("MatchingElements.txt", matchingElementsVector);
	WriteToFile("NonMatchingElements.txt", nonMatchingElementsVector);
	WriteToFile("CopyElements.txt", copyElementsInOriginalVector);
}

void VectorCompare::WriteToFile(string fileName, vector<string> vector)
{
	outStream.open(fileName, ios::out | ios::trunc);
	unsigned int index = 0;
	while (index < vector.size())
		outStream << vector.at(index++) << "\n";
	CloseFile(outStream);
}

void VectorCompare::ClearVectors()
{
	originalVector.clear();
	upToDateVector.clear();
	matchingElementsVector.clear();
	nonMatchingElementsVector.clear();
}