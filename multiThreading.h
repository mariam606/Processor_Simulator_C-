#pragma once
#ifndef MULTITHREADING_H
#define MULTITHREADING_H

#include <bits/stdc++.h>
#include"Reading.h"
#include"Execution.h"
#include <thread>


using namespace std;

class multiThreading:public Execution
{
private:
	vector<string> fileName;
	Reading r;

public:
	multiThreading();
	multiThreading(vector<string> fileName);
	void readThreading();
	void threadMaker();
};

#endif

