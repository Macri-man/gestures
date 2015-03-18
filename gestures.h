#ifndef GESTURES_H
#define GESTURES_H

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

typedef Commands{
	string name;
	int duration;
}Commands;

typedef Macros{
	map<string, vector<command>> macroList;
	int numOfMacros;
} Macros;

typedef Gesture{
	map<int,string> gestureList;
	int numOfGestures;
}Gesture;

Macros macro;
Gestures gesture;
Commands command;


void readFile(string filename);
void initGestures();
