#include "VectorCompare.h"
#include <iostream>

using namespace std;

int main()
{
	VectorCompare Test;
	Test.RunFileCompare("StatesWithExtraEntries.txt", "FiftyStates.txt");
}