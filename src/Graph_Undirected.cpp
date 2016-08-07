//
//  Graph_Undirected.cpp
//  Stnfrd.Ass
//
//  Created by lykanthrop on 2016.07.31.
//  Copyright © 2016 varo. All rights reserved.
//

#include <cstdio>
#include <fstream>
#include "Graph_Undirected.h"

Graph_Undirected::Graph_Undirected()
{	
}

Graph_Undirected::Graph_Undirected(std::string filename)
{
	SndAlgs::logOutput(1, "Loading File");
	
	std::ifstream file(filename,std::fstream::in);
	
	
	if(file.is_open())
	{
		SndAlgs::logOutput(1, "File Open");
		
		std::string gluk;
		while(std::getline(file,gluk))
		{
			if(gluk.size()>0 && gluk!="\n")
			{
				numberOfNodes++;
			}
		}
		
		SndAlgs::logOutput(1,"Nodes",numberOfNodes);
		
		graph = new GraphNode_Undirected[numberOfNodes];
		
		for(int i=0; i<numberOfNodes; ++i)
		{
			graph[i] = GraphNode_Undirected(i);
		}
		
		file.clear();
		file.seekg(0);
		
		int i = 0;
		size_t posl;
		size_t posr;
		int value;
		
		std::string token;
		while(std::getline(file,gluk))
		{
			if(gluk.size()>0 && gluk!="\n")
			{
				posl = gluk.find(" ");
				
				while((posr = gluk.find(" ",posl+1))!=std::string::npos)
				{
					token = gluk.substr(posl+1,posr);
					posl = posr;
					
					try
					{
						value = std::stoi(token);
						graph[i].addNode(&graph[value-1]);
					} catch(std::invalid_argument& e)
					{
					}
				}
				
				token = gluk.substr(posl+1);
				try
				{
					value = std::stoi(token);
					graph[i].addNode(&graph[value-1]);
				} catch(std::invalid_argument& e)
				{
				}

				i++;
			}
		}
		
		file.close();
	}
	
	printGraph();
}

Graph_Undirected::~Graph_Undirected()
{
}

unsigned long Graph_Undirected::minimumCut()
{
	unsigned long out = 0;
	unsigned long luckyrep = 0;
	int repetitions = numberOfNodes*numberOfNodes;
	
	for(int i=0; i<repetitions; ++i)
	{
		SndAlgs::logOutput(1, "Repetition :",i);
		
		initCut();
		
		//printf("Starting Repetition : %i\n",i);
		//printCutGraph();
		//printf("Step : %lu\n",cutGraph.size());
		
		while (cutGraph.size()>2)
		{
			cut();
			
			//printf("Step : %lu\n",cutGraph.size());
			
			//printCutGraph();
		}
		
		if(out==0)
		{
			out = cutGraph[0]->connections.size();
			SndAlgs::logOutput(1, "New Time NMC", out);
			luckyrep = i;
		}
		else if(cutGraph[0]->connections.size()<out)
		{
			out = cutGraph[0]->connections.size();
			SndAlgs::logOutput(1, "All Time NMC", out);
			luckyrep = i;
		}
		
		SndAlgs::logOutput(2, "Repetition NMC", out);
		SndAlgs::logOutput(1, "All Time NMC", out,"Found on Repetition",luckyrep);
	}
	
	return out;
}

void Graph_Undirected::cut()
{	
	int id0 = rand()%(cutGraph.size());
	
	SndAlgs::logOutput(3,"Random 0", id0);
	
	GraphNode_Undirected* n0 = cutGraph[id0];
	
	int id1 = rand()%(n0->connections.size());
	
	SndAlgs::logOutput(3,"Random 1", id1);
	
	GraphNode_Undirected* n1 = n0->connections[id1];
	
	SndAlgs::logOutput(3,"Merging Nodes",n0->number,n1->number);
	
	n0->removeNode(n1);
	n0->merge(n1);
	
	//printf("Clearing %i\n",n1->number);
	n1->connections.clear();
	
	std::vector<GraphNode_Undirected*>::iterator it;
	
	for(it = cutGraph.begin();it!=cutGraph.end();++it)
	{
		if((*it)==n1)
		{
			cutGraph.erase(it);
			break;
		}
	}
	
	//printf("Cut Done\n");
}

void Graph_Undirected::printGraph()
{
	for(int i=0; i<numberOfNodes; ++i)
	{
		printf("%i",graph[i].number);
		
		for(int j=0;j<graph[i].connections.size();j++)
		{
			printf(" %i",graph[i].connections[j]->number);
		}
		printf("\n");
	}
}

void Graph_Undirected::printCutGraph()
{
	for(int i=0; i<cutGraph.size(); ++i)
	{
		printf("%i",cutGraph[i]->number);
		
		for(int j=0;j<cutGraph[i]->connections.size();j++)
		{
			printf(" %i",cutGraph[i]->connections[j]->number);
		}
		printf("\n");
	}
}

void Graph_Undirected::initCut()
{
	cutGraph.clear();
	
	for(int i=0; i<numberOfNodes; ++i)
	{
		cutGraph.push_back(new GraphNode_Undirected(i));
	}
	
	for(int i=0; i<numberOfNodes; ++i)
	{
		for(int j=0;j<graph[i].connections.size();j++)
		{
			cutGraph[i]->addNode(cutGraph[graph[i].connections[j]->number]);
		}
	}
}

void Graph_Undirected::merge(int n0, int n1)
{
}
