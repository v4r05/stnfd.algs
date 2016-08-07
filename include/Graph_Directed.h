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

class Graph_Directed{

public:

	Graph_Directed();
	Graph_Directed(std::string filename);
	~Graph_Directed();

protected:

	//Variables
	size_t nodesSize;

	
};
#endif /* Graph_Directed_h */
