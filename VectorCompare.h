// Quentin Curteman
// July 3, 2017

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class VectorCompare
{
private:
	std::vector<std::string> originalVector;
	std::vector<std::string> upToDateVector;
	std::vector<std::string> matchingElementsVector;
	std::vector<std::string> nonMatchingElementsVector;
	std::vector<std::string> copyElementsInOriginalVector;
	std::fstream inStream;
	std::fstream outStream;
	std::string tempString;
	char inStreamChar;
	int NumOfCharReadIn;
	void FillOriginalAndUpToDateVectors(std::string originalListFileName, std::string upToDateListFileName);
	void FillOriginalVector(std::string originalListFileName);
	void FillUpToDateVector(std::string upToDateListFileName);
	void FillVector(std::string fileName, std::vector<std::string> &vectorName);
	void OpenAndCheckForFile(std::string fileName, std::fstream &stream);
	void ReadInFileAndFillVector(std::vector<std::string> &vectorName);
	void getCharacterFromFile();
	void CheckForSpaceOrEmptyLine();
	void CloseFile(std::fstream &stream);
	void FillIntoVector(std::vector<std::string> &vectorName);
	void CheckForLastStringInFile(std::vector<std::string> &vectorName);
	void ClearStringAndGetChar();
	void CompareVectors();
	std::vector<std::string>::iterator getBeginningOfVectorIterator();
	std::vector<std::string>::iterator getEndOfVectorIterator();
	bool CheckForCopyElement(unsigned int index);
	void WriteVectorsToFile();
	void WriteToFile(std::string fileName, std::vector<std::string> vector);
	void ClearVectors();

public:
	VectorCompare();
	void RunFileCompare(std::string originalListFileName, std::string upToDateListFileName);
};