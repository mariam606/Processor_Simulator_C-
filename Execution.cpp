#include "Execution.h"

Execution::Execution(string fileName){
	this->fileName = fileName;
	readFile();
	done = 0;
}

void Execution::readFile() {
	r.setFile(fileName);
	r.getNumOfInstructions();
	cout << "HERE!\n";
}

void Execution::executeSet(vector<pair<string, vector<int>>> instructionSet){
	
	PC = 0;
	//Initializing a timer to detect inifinite loop
	time_t timer = time(NULL) + 120;
	//Looping over the instructions
	while (PC < 1024 != done)
	{
		if (time(NULL) > timer) {
			cout << "An infinite loop detected, the program should terminate\n";
			exit(0);
		}
		//instruction = instructionSet[PC];
		executeInstruction(instructionSet[PC]);
		cout << endl;
	}
}

void Execution::executeInstruction(pair<string, vector<int>> instruction)
{
	if (instruction.first == "ADD")
	{
		unsigned int firstSrcMemIndex = instruction.second[0];
		unsigned int secSrcMemIndex = instruction.second[1];
		unsigned int destMemIndex = instruction.second[2];
		//Excuting the instruction
		Execution::DataMemory[destMemIndex] = Execution::DataMemory[firstSrcMemIndex] + Execution::DataMemory[secSrcMemIndex];
		//Detecting overflow
		if (Execution::DataMemory[destMemIndex] > INT_MAX) {
			cout << "\nAn overflow detected, the program should terminate\n";
			exit(0);
		}
		//Couting the output
		cout << " and stored it in memory location " << destMemIndex << " now with value " << Execution::DataMemory[destMemIndex] << endl;
		PC++;
	}

	else if (instruction.first == "NEG")
	{
		unsigned int srcMemIndex = instruction.second[0];
		unsigned int destMemIndex = instruction.second[1];
		//Couting the input
		cout << "The SIM just calculated the additive inverse of the memory location " << srcMemIndex << " with value " << Execution::DataMemory[srcMemIndex];
		//Excuting the instruction
		Execution::DataMemory[destMemIndex] = -Execution::DataMemory[srcMemIndex];
		//Couting the output
		cout << " and stored it in memory location " << destMemIndex << " now with value " << Execution::DataMemory[destMemIndex] << endl;
		PC++;
	}

	else if (instruction.first == "MUL")
	{
		unsigned int firstSrcMemIndex = instruction.second[0];
		unsigned int secSrcMemIndex = instruction.second[1];
		unsigned int destMemIndex = instruction.second[2];
		//Couting the input
		cout << "The SIM just multiplied memory location " << firstSrcMemIndex << " with value " << Execution::DataMemory[firstSrcMemIndex] << " and memory location " << secSrcMemIndex << " with value " << Execution::DataMemory[secSrcMemIndex];
		//Excuting the instruction
		Execution::DataMemory[destMemIndex] = Execution::DataMemory[firstSrcMemIndex] * Execution::DataMemory[secSrcMemIndex];
		//Detecting overflow
		if (Execution::DataMemory[destMemIndex] > INT_MAX) {
			cout << "\nAn overflow detected; the program should terminate\n";
			exit(0);
		}
		//Couting the output
		cout 
			<< " and stored it in memory location " << destMemIndex << " now with value " << Execution::DataMemory[destMemIndex] << endl;
		PC++;
	}
	else if (instruction.first == "JPA")
	{
		cout << "The SIM just jumped to address " << instruction.second[0] << endl;
		PC = instruction.second[0];
	}
	else if (instruction.first == "JP0")
	{
		unsigned int inAddress = Execution::DataMemory[instruction.second[0]];
		unsigned int destAddress = instruction.second[1];

		if (inAddress == 0) {
			cout << "The SIM just jumped to address " << destAddress << endl;
			PC = instruction.second[1];
		}
		else PC++;

	}
	else if (instruction.first == "ASI")
	{
		int immediate = instruction.second[0];
		unsigned int destAddress = instruction.second[1];

		Execution::DataMemory[destAddress] = immediate;
		cout << "The SIM just put the integer value " << Execution::DataMemory[destAddress] << " in memory location " << destAddress << endl;
		PC++;
	}
	else if (instruction.first == "LOE")
	{
		unsigned int firstSrcMemIndex = instruction.second[0];
		unsigned int secSrcMemIndex = instruction.second[1];
		unsigned int destMemIndex = instruction.second[2];

		if (Execution::DataMemory[firstSrcMemIndex] <= Execution::DataMemory[secSrcMemIndex])
			Execution::DataMemory[destMemIndex] = 1;
		else
			Execution::DataMemory[destMemIndex] = 0;


		cout << "The SIM just compared memory location " << firstSrcMemIndex << " with value " << Execution::DataMemory[firstSrcMemIndex]
			<< " and memory location " << secSrcMemIndex << " with value " << Execution::DataMemory[secSrcMemIndex]
			<< " and stored " << Execution::DataMemory[destMemIndex] << " in memory location " << destMemIndex << endl;
		PC++;
	}
	else if (instruction.first == "HLT")
	{
		cout << "The SIM stopped executing instructions " << endl;
		done = 1;
	}
	else
	{
		cout << "The SIM was not able to identify the instruction " << endl;
		PC++;
	}
}

long long Execution::DataMemory[1024];