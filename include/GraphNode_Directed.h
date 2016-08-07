//
//  GraphNode_Directed.h
//  SndAlgs
//
//  Created by YV4706 on 2016.08.07.
//  Copyright © 2016 varo. All rights reserved.
//

#ifndef GraphNode_Directed_h
#define GraphNode_Directed_h

#include <stdlib.h>

class GraphNode_Directed{

public:

	GraphNode_Directed();
	GraphNode_Directed(size_t cns);
	~GraphNode_Directed();

	void addConnection(GraphNode_Directed gnd);
	void setVisited(bool vst);

	bool isVisited();

protected:
	//Variables
	unsigned int number;
	size_t connectionsOutSize = 0;
	size_t connectionsInSize = 0;
	GraphNode_Directed** connectionsOut = (GraphNode_Directed**)0;
	GraphNode_Directed** connectionsIn = (GraphNode_Directed**)0;
	bool visited = false;
};
#endif /* GraphNode_Directed_h */
