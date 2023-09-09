#pragma once
#ifndef EXCUTION_H
#define EXCUTION_H

#include "Reading.h"

using namespace std;

class Execution
{
private:
	string fileName;
	pair<string, vector<int>> instruction;
	vector<pair<string, vector<int>>> instructionSet;
	int PC = 0;
	bool done;
	Reading r;

public:
	static long long DataMemory[];
	Execution(string fileName);
	void readFile();
	void executeInstruction(pair<string, vector<int>>);
	void executeSet(vector<pair<string, vector<int>>> instructions);
	//void print();
};

#endif