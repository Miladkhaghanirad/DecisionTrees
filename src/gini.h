/*
 * gini.h
 *
 *  Created on: Feb 1, 2019
 *      Author: milad
 */

#ifndef GINI_H_
#define GINI_H_
#include <iostream>
#include "gloabal.h"
using namespace std;


class gini {
	//initialization of variables
	float n_instances=0,size=0,score=0,p=0;
	int count = 0;
	float gini;

public:
	// Calculate the Gini index for a split dataset
	float gini_index(groups f,row y){
		gini = 0.0;
		// count all samples at split point
		n_instances = sizeof(f)/sizeof(y);
		//sum weighted Gini index for each group
		for(group l: f.c ){
			size = sizeof(l)/sizeof(y);
			//avoid divide by zero
			if(size != 0){
				score = 0;
				//score the group based on the score for each class
				for(int value:y.a){
					for(row cls:l.b){
							if(value == cls.a[1]){
								count++;
							}
					}
					p = count/size;
					count = 0;
					score += p * p;
				}
			}
			//weight the group score by its relative size
			gini += (1.0 - score) * (size / n_instances);
		}
		return gini;
	}
	//make a group from array of dataset
	groups groupsmaker(int a[][2]){
		//size of array
		int len = (sizeof(a) / 2) ;
		//2 time of group is one groups
		groups grus;
		//devide data set in 2 groups
		group gru[len/2];
		//one row is 2 data
		row cls[len];
		int j = 0;
		//collect all in one group
		for(int i=0;i<len;i++){
				cls[i]= { {a[i][0],a[i][1]}};
				if((i+1)%2 == 0){
					gru[j] = {{cls[i-1],cls[i]}};
					j++;
					grus = {{gru[0],gru[1]}};
				}
		}
		return grus;
	}

};

#endif /* GINI_H_ */
