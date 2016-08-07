//
//  main.cpp
//  MSI
//
//  Created by lykanthrop on 2016.07.17.
//  Copyright © 2016 faros. All rights reserved.
//

#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "SndAlgs.h"
#include "Array.h"
#include "Graph_Undirected.h"

int main(int argc, char* argv[])
{
	SndAlgs::init();
	
	srand((unsigned int)SndAlgs::initTime);
	
	SndAlgs::verbose = 1;
	
	printf("Starting\n");
	
	if(argc>2)
	{
		std::string mainComm = std::string(argv[1]);
		
		
		if((!strcmp(argv[1], "sort")) && argc>3)
		{
			Array meaow;
			
			Array::sortType srtTp;
			
			if(!strcmp(argv[2],"merge"))
			{
				srtTp = Array::sortType::merge;
			}
			else if(!strcmp(argv[2],"quick"))
			{
				srtTp = Array::sortType::quickfst;
			}
			else if(!strcmp(argv[2],"quickfst"))
			{
				srtTp = Array::sortType::quickfst;
			}
			else if(!strcmp(argv[2],"quickmed"))
			{
				srtTp = Array::sortType::quickmed;
			}
			else if(!strcmp(argv[2],"quicklst"))
			{
				srtTp = Array::sortType::quicklst;
			}
			else{
				srtTp = Array::sortType::merge;
			}
			
			std::string filename(argv[3]);
			
			std::cout<<"File: "<<filename<<'\n';
			
			meaow.loadArrayFromFile(filename);
			
			meaow.sort(srtTp);
			
			meaow.printSorted();
			
			switch(srtTp)
			{
				case Array::sortType::merge:
					std::cout<<"Inversions : "<<meaow.msInversions<<'\n';
					break;
				case Array::sortType::quickfst:
				case Array::sortType::quickmed:
				case Array::sortType::quicklst:
					std::cout<<"Comparisons : "<<meaow.qsComparisons<<'\n';
					break;
				default:
					break;
			}
		}
		else if (!strcmp(argv[1], "mnmcut"))
		{
			std::string filename(argv[2]);
			
			std::cout<<"File: "<<filename<<'\n';
			
			Graph_Undirected grf = Graph_Undirected(filename);
						
			printf("Minimum Cut Number %lu\n",grf.minimumCut());
		}
		
	}
	
	SndAlgs::logAccumulatedTime(0);
	
    return 0;
}
