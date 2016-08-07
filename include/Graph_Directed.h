//
//  Graph_Directed.h
//  SndAlgs
//
//  Created by YV4706 on 2016.08.07.
//  Copyright © 2016 varo. All rights reserved.
//

#ifndef Graph_Directed_h
#define Graph_Directed_h

#include <string>
#include "GraphNode_Directed.h"
#include "SndAlgs.h"

class Graph_Directed{

public:

	Graph_Directed();
	Graph_Directed(std::string filename);
	~Graph_Directed();

	void findSCC();
	
	void printGraph();
	
private:
	
	void resetNodes();
	void dfs(GraphNode_Directed** graph);
	void dfsInv(GraphNode_Directed* graph);
	void dfs_recursion(unsigned long leader, GraphNode_Directed& nd);
	void dfs_recursionInv(GraphNode_Directed& nd);
	
protected:

	//Variables
	size_t nodesSize;
	GraphNode_Directed* nodes;
	GraphNode_Directed** finishingTimes;
	size_t fTime;
	
private:
	std::vector<GraphNode_Directed*> leaders;
	std::vector<long> sccSizes;
};
#endif /* Graph_Directed_h */
