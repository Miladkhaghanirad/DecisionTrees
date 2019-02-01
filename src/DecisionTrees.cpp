//============================================================================
// Name        : DecisionTrees.cpp
// Author      : Milad Khaghanirad
// Version     :
// Copyright   : @it is free to all
// Description : implementing all decision trees in C++
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include "gini.h"
#include "gloabal.h"
#include <list>
#include <iterator>
using namespace std;

int main() {
	//set Dataset
	int gr0[][2]= {{0,0},{0,0},{2,2},{2,2}};
	int gr1[][2]= {{1,0},{1,1},{1,0},{1,1}};
	gini index;
	//make one group
	groups u1 = index.groupsmaker(gr0);
	groups u2 = index.groupsmaker(gr1);
	//# test Gini values
	cout <<index.gini_index(u1,{{0,2}}) << "\n";
	cout <<index.gini_index(u2,{{0,1}}) << "\n";
}
