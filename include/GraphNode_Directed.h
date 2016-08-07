//
//  GraphNode_Directed.h
//  SndAlgs
//
//  Created by YV4706 on 2016.08.07.
//  Copyright © 2016 varo. All rights reserved.
//

#ifndef GraphNode_Directed_h
#define GraphNode_Directed_h

#include <iostream>
#include <stdlib.h>

class GraphNode_Directed{

	friend class Graph_Directed;
	
public:

	GraphNode_Directed();
	GraphNode_Directed(unsigned int nmb, size_t cnsi, size_t cnso);
	~GraphNode_Directed();

	void set(unsigned int nmb, size_t cnsi, size_t cnso);
	
	void addConnectionOut(GraphNode_Directed& gnd);
	void addConnectionIn(GraphNode_Directed& gnd);
	
	bool isVisited();
	
	void printNode();
	
	void printNodeInfo();

protected:
	//Variables
	unsigned int number;
	
	size_t connectionsOutSize = 0;
	size_t connectionsInSize = 0;
	
	GraphNode_Directed** connectionsOut = (GraphNode_Directed**)0;
	GraphNode_Directed** connectionsIn = (GraphNode_Directed**)0;
	
	size_t currentIn = 0;
	size_t currentOut = 0;
	
	bool visited = false;
};
#endif /* GraphNode_Directed_h */
