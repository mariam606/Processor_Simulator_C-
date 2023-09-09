#include "multiThreading.h"

multiThreading::multiThreading() {}

multiThreading::multiThreading(vector<string> fileName){
	this->fileName = fileName;
	//Reading all the files
	readThreading();
	threadMaker();
}

void multiThreading::readThreading() {
	r.setFile(fileName);
	r.storeInstructions();
}

void excuteThreading(vector<pair<string, vector<int>>> instructionSet){
	Execution exe;
	exe.executeSet(instructionSet);
}

void multiThreading::threadMaker(){
	int no_of_files = fileName.size();
	vector<thread> thrds(no_of_files);
	for (int i = 0; i < no_of_files; ++i) {
		vector<pair<string, vector<int>>> instructionSet = r.getSet(i);
		thrds[i] = thread(excuteThreading, instructionSet);
	}
	for (int i = 0; i < no_of_files; ++i)
		thrds[i].join();
}
