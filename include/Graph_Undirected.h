//
//  Graph_Undirected.h
//  Stnfrd.Ass
//
//  Created by lykanthrop on 2016.07.30.
//  Copyright © 2016 varo. All rights reserved.
//

#ifndef Graph_Undirected_h
#define Graph_Undirected_h

#include <string>
#include <vector>
#include "SndAlgs.h"
#include "GraphNode_Undirected.h"

class Graph_Undirected{
	
public:
	
	Graph_Undirected();
	Graph_Undirected(std::string filename);
	
	~Graph_Undirected();
	
	unsigned long minimumCut();
	
	void printGraph();
	void printCutGraph();
		
	void initCut();
	void merge(int n0, int n1);
	void cut();
	
protected:
	//Variables
	
	int numberOfNodes = 0;
	GraphNode_Undirected* graph = (GraphNode_Undirected*)0;
	std::vector<GraphNode_Undirected*> cutGraph;
};
#endif /* Graph_Undirected_h */
