#include "Execution.h"

int main()
{
	//Getting the file name from the user
	string fileName;
	cout << "Please enter  the instruction file name\n";
	cin >> fileName;

	//Initializing the data memory
	for (int i = 0; i < 1024; i++)
		Execution::DataMemory[i] = 1;

	Execution(fileName);
}
