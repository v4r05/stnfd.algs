//
//  GraphNode_Directed.cpp
//  SndAlgs
//
//  Created by YV4706 on 2016.08.07.
//  Copyright © 2016 varo. All rights reserved.
//

#include "GraphNode_Directed.h"

GraphNode_Directed::GraphNode_Directed(){

	
}

GraphNode_Directed::GraphNode_Directed(unsigned int nmb, size_t cnsi, size_t cnso){
	
	number = nmb;
	
	connectionsInSize = cnsi;
	connectionsOutSize = cnso;
	
	connectionsIn = new GraphNode_Directed*[connectionsInSize];
	connectionsOut = new GraphNode_Directed*[connectionsOutSize];
}

GraphNode_Directed::~GraphNode_Directed(){
	
	std::cout<<"GraphNode destructor Call\n";
	
	if(connectionsIn!=(GraphNode_Directed**)0){
		delete connectionsIn;
	}
	
	if(connectionsOut!=(GraphNode_Directed**)0){
		delete connectionsOut;
	}
}

void GraphNode_Directed::set(unsigned int nmb, size_t cnsi, size_t cnso){
	
	number = nmb;
	
	connectionsInSize = cnsi;
	connectionsOutSize = cnso;
	
	connectionsIn = new GraphNode_Directed*[connectionsInSize];
	connectionsOut = new GraphNode_Directed*[connectionsOutSize];
}

void GraphNode_Directed::addConnectionOut(GraphNode_Directed& gnd){
	
	connectionsOut[currentOut] = &gnd;
	++currentOut;
}

void GraphNode_Directed::addConnectionIn(GraphNode_Directed& gnd){
	connectionsIn[currentIn] = &gnd;
	++currentIn;
}

void GraphNode_Directed::printNode(){
	std::cout<<"Node: "<<number<<" Out Nodes->";
	
	for(int i=0;i<connectionsOutSize;++i){
		std::cout<<" "<<connectionsOut[i]->number;
	}
	
	std::cout<<" In Nodes<-";
	
	for(int i=0;i<connectionsInSize;++i){
		std::cout<<" "<<connectionsIn[i]->number;
	}
	
	std::cout<<'\n';
}

void GraphNode_Directed::printNodeInfo(){
	std::cout<<"Node: "<<number<<" In Nodes: "<<connectionsInSize<<" Out Nodes: "<<connectionsOutSize<<'\n';
}
