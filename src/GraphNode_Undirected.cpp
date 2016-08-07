//
//  GraphNode_Undirected.cpp
//  Stnfrd.Ass
//
//  Created by lykanthrop on 2016.07.31.
//  Copyright © 2016 varo. All rights reserved.
//

#include <stdio.h>
#include "GraphNode_Undirected.h"

GraphNode_Undirected::GraphNode_Undirected(){
	number = -1;
}

GraphNode_Undirected::GraphNode_Undirected(int nmb){
	number = nmb;
}

GraphNode_Undirected::~GraphNode_Undirected(){
}

void GraphNode_Undirected::addNode(GraphNode_Undirected& gnu){
	if((&gnu)!=this){
		connections.push_back(&gnu);
	}
}

void GraphNode_Undirected::removeNode(GraphNode_Undirected* gnu)
{
	std::vector<GraphNode_Undirected*>::iterator it = connections.begin();
	
	while(it<connections.end())
	{
		if((*it)==gnu)
		{
			//printf("Removing from list of %i Node %i\n",number,(*it)->number);
			connections.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void GraphNode_Undirected::merge(GraphNode_Undirected* gnu)
{
	GraphNode_Undirected* target = (GraphNode_Undirected*)0;
	
	for(int i=0; i<gnu->connections.size(); ++i)
	{
		target = gnu->connections[i];
		
		//printf("Getting %i from %i\n",target->number,gnu->number);
		
		if(target!=this)
		{
			//printf("Adding %i to %i\n",target->number,number);
			connections.push_back(target);
			
			//printConnections();
			
			//target->printConnections();
			for(int j=0; j<target->connections.size();++j)
			{
				if(target->connections[j]==gnu)
				{
					target->connections[j] = this;
					//printf("Replacing position %i of %i with %i\n",j,target->number,number);
					//target->printConnections();
				}
			}
		}
	}
	
	//printf("Merge Done\n");
}

void GraphNode_Undirected::printConnections()
{
	printf("Node %i, %lu : ",number,connections.size());
	for(int i=0;i<connections.size();++i)
	{
		printf("%i ",connections[i]->number);
	}
	printf("\n");
}