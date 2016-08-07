//
//  Graph_Directed.cpp
//  SndAlgs
//
//  Created by YV4706 on 2016.08.07.
//  Copyright © 2016 varo. All rights reserved.
//

#include <vector>
#include <map>
#include <fstream>
#include "Graph_Directed.h"

Graph_Directed::Graph_Directed(){

}

Graph_Directed::Graph_Directed(std::string filename){

	std::ifstream file(filename,std::fstream::in);
	
	
	if(file.is_open()){

		SndAlgs::logOutput(0, "File Open");
		typedef struct{
			size_t inSize;
			size_t outSize;
		}sizes;


		std::map<unsigned int,sizes> sizeMap;

		std::string gluk;
		std::string token;
		size_t posl;
		unsigned int nodeSource;
		unsigned int nodeTarget;
		std::map<unsigned int,sizes>::iterator it;
		while(std::getline(file,gluk)){
			if(gluk.size()>0 && gluk!="\n"){
				
				posl = gluk.find(" ");
				
				try{
					nodeSource = std::stoi(gluk.substr(0,posl));
					nodeTarget = std::stoi(gluk.substr(posl+1));
					
					if((it = sizeMap.find(nodeSource-1))!=sizeMap.end()){
						
						it->second.outSize++;
					}
					else{
						sizes sz;
						sz.inSize = 0;
						sz.outSize = 1;
						sizeMap.insert(std::pair<unsigned int, sizes>(nodeSource-1,sz));
					}
					
					if((it = sizeMap.find(nodeTarget-1))!=sizeMap.end()){
						
						it->second.inSize++;
					}
					else{
						sizes sz;
						sz.inSize = 1;
						sz.outSize = 0;
						sizeMap.insert(std::pair<unsigned int, sizes>(nodeTarget-1,sz));
					}
				}
				catch(std::invalid_argument exc){
					
				}
				
			}
		}
		
		nodesSize = sizeMap.size();
		
		nodes = new GraphNode_Directed[nodesSize]();
		finishingTimes = new GraphNode_Directed*[nodesSize];
		
		for(int i=0;i<nodesSize;++i){
			
			nodes[i].set(i,sizeMap[i].inSize,sizeMap[i].outSize);
			
		}
		
		file.clear();
		file.seekg(0);
		
		while(std::getline(file,gluk)){
			if(gluk.size()>0 && gluk!="\n"){
				
				posl = gluk.find(" ");
				
				try{
					nodeSource = std::stoi(gluk.substr(0,posl));
					nodeTarget = std::stoi(gluk.substr(posl+1));
					
					nodes[nodeSource-1].addConnectionOut(nodes[nodeTarget-1]);
					
					nodes[nodeTarget-1].addConnectionIn(nodes[nodeSource-1]);
				}
				catch(std::invalid_argument exc){
					
				}
				
			}
		}
		
		//printGraph();
		
		file.close();
	}
	SndAlgs::logOutput(0,"File Closed");
}

Graph_Directed::~Graph_Directed(){
	
	if(finishingTimes!=(GraphNode_Directed**)0){
		delete finishingTimes;
	}
}

void Graph_Directed::printGraph(){
	
	SndAlgs::logOutput(0,"Printing");
	SndAlgs::logOutput(0,"Nodes",nodesSize);
	
	for(int i=0;i<nodesSize;++i){
		nodes[i].printNode();
	}
	
}

void Graph_Directed::findSCC(){
	
	resetNodes();
	fTime = nodesSize-1;
	dfsInv(nodes);
	
	resetNodes();
	dfs(finishingTimes);
	
	std::cout<<"SCC "<<sccSizes.size()<<'\n';
	
	for(int i=0;i<5;++i){
		long maxSCC = -1;
		int maxIndex = -1;

		for(int j=0;j<sccSizes.size();++j){

			if(sccSizes[j]>maxSCC){

				maxSCC = sccSizes[j];
				maxIndex = j;
			}
		}
		
		std::cout<<"END\n";
		
		if(maxIndex>-1){
			std::cout<<"MAX : "<<i<<" = "<<maxSCC<<" Leader : "<<leaders[maxIndex]->number<<'\n';
			leaders.erase(leaders.begin()+maxIndex);
			sccSizes.erase(sccSizes.begin()+maxIndex);
		}
	}
}

void Graph_Directed::dfs(GraphNode_Directed** graph){
	
	for(int i=0;i<nodesSize;++i){

		if(!graph[i]->visited){
			graph[i]->visited = true;
			leaders.push_back(graph[i]);
			sccSizes.push_back(1);
			dfs_recursion(leaders.size()-1, *graph[i]);
		}
	}
}

void Graph_Directed::dfsInv(GraphNode_Directed* graph){
	
	for(long i=nodesSize-1;i>=0;--i){

		if(!graph[i].visited){
			graph[i].visited = true;
			dfs_recursionInv(graph[i]);
		}
	}
}
void Graph_Directed::resetNodes(){
	
	for(int i=0;i<nodesSize;++i){
		nodes[i].visited = false;
	}
}

void Graph_Directed::dfs_recursion(unsigned long leader, GraphNode_Directed& nd){
	nd.visited = true;
	
	for(int i=0;i<nd.connectionsOutSize;++i){
		if(!nd.connectionsOut[i]->visited){
			++sccSizes[leader];
			dfs_recursion(leader,*nd.connectionsOut[i]);
		}
	}
}

void Graph_Directed::dfs_recursionInv(GraphNode_Directed& nd){
	nd.visited = true;
	
	for(int i=0;i<nd.connectionsInSize;++i){
		if(!nd.connectionsIn[i]->visited){
			dfs_recursionInv(*nd.connectionsIn[i]);
		}
	}
	finishingTimes[fTime] = &nd;
	--fTime;
}
