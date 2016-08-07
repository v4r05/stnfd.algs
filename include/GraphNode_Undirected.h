//
//  GraphNode_Undirected.h
//  Stnfrd.Ass
//
//  Created by lykanthrop on 2016.07.30.
//  Copyright © 2016 varo. All rights reserved.
//

#ifndef GraphNode_Undirected_h
#define GraphNode_Undirected_h

#include <vector>

class GraphNode_Undirected
{
	friend class Graph_Undirected;
	
public:
	
	GraphNode_Undirected();
	GraphNode_Undirected(int nmb);
	~GraphNode_Undirected();
	
	void addNode(GraphNode_Undirected* gnu);
	void removeNode(GraphNode_Undirected* gnu);
	void merge(GraphNode_Undirected* gnu);
	
	void printConnections();
	
protected:
	//Variables
	int number;
	std::vector<GraphNode_Undirected*> connections;
};

#endif /* GraphNode_Undirected_h */
