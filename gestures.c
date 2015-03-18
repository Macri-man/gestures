#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
using namespace std;

void readFile(string &filename){
 	string line;
	istringstream secstream;
	string subline1,subline2;
	ifstream file(filename.c_str());
	int i=0;
	if(!file){
		cerr << "ERROR FILE NOT FOUND\n";
	}else{
		while(getline(file,line)){
			secstream.str(line);
			while(secstream >> subline1 >> subline2){
				if(isdigit(atoi(subline2.c_str()))){
					command.name=subline1;
					command.duration=subline2;
				}else{
					command.name=subline1;
					command.duration=5;
				}
				macro.macroList[macro.numOfMacro].push_Back(command);
			}
		}
	}
}

void initGestures(){
	gestrue.numOfGestures=3
	gesture.gestrueList.insert(1,"square");
	gesture.gestureList.insert(2,"triangle");
	gesture.gestureList.insert(3,"arch");
}
					
