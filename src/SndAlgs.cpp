//
//  SndAlgs.cpp
//  SndAlgs
//
//  Created by lykanthrop on 2016.07.31.
//  Copyright © 2016 varo. All rights reserved.
//

#include <iostream>
#include "SndAlgs.h"

int SndAlgs::verbose = -1;
time_t SndAlgs::initTime = 0;
time_t SndAlgs::stepTime = 0;

void SndAlgs::init()
{
	initTime = std::time(0);
	stepTime = initTime;
}

void SndAlgs::parseArguments(int argc, char ***argv)
{
	
}

void SndAlgs::logOutput(int vrb, std::string msg)
{
	if(vrb<=verbose)
	{
		std::cout<<msg<<"\n";
	}
}

void SndAlgs::logOutput(int vrb, std::string msg, int vl)
{
	if(vrb<=verbose)
	{
		msg = msg+" : "+std::to_string(vl);
		
		std::cout<<msg<<"\n";
	}
}

void SndAlgs::logOutput(int vrb, std::string msg, int vl0, int vl1)
{
	if(vrb<=verbose)
	{
		msg = msg+" : "+std::to_string(vl0)+" , "+std::to_string(vl1);
		
		std::cout<<msg<<"\n";
	}
}

void SndAlgs::logOutput(int vrb, std::string msg0, int vl0, std::string msg1, int vl1)
{
	if(vrb<=verbose)
	{
		std::cout<<msg0<<" : "<<vl0<<" , "<<msg1<<" : "<<vl1<<"\n";
	}
}

void SndAlgs::logOutput(int vrb, std::string msg, unsigned long vl)
{
	if(vrb<=verbose)
	{
		msg = msg+" : "+std::to_string(vl);
		
		std::cout<<msg<<"\n";
	}
}

void SndAlgs::logOutput(int vrb, std::string msg, unsigned long vl0, unsigned long vl1)
{
	if(vrb<=verbose)
	{
		msg = msg+" : "+std::to_string(vl0)+" , "+std::to_string(vl1);
		
		std::cout<<msg<<"\n";
	}
}

void SndAlgs::logOutput(int vrb, std::string msg0, unsigned long vl0, std::string msg1, unsigned long vl1)
{
	if(vrb<=verbose)
	{
		std::cout<<msg0<<" : "<<vl0<<" , "<<msg1<<" : "<<vl1<<"\n";
	}
}

void SndAlgs::logOutput(int vrb, void (*funct)(void))
{
	if(vrb<=verbose)
	{
		funct();
	}
}

void SndAlgs::logTime(int vrb)
{
	time_t now = std::time(0);
	std::cout<<"Time from Previous Step : "<<(now-stepTime)<<"\n";
	stepTime = now;
}

void SndAlgs::logAccumulatedTime(int vrb)
{
	std::cout<<"Total Running Time : "<<(std::time(0)-initTime)<<"\n";
}
