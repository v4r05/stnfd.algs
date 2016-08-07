//
//  SndAlgs.h
//  SndAlgs
//
//  Created by lykanthrop on 2016.07.31.
//  Copyright © 2016 varo. All rights reserved.
//

#ifndef SndAlgs_h
#define SndAlgs_h

#include <string>

class SndAlgs
{
	friend int main(int argc, char** argv);

public:

	static void init();
	
	static void parseArguments(int argc, char** argv[]);
	
	static void logOutput(int vrb, std::string msg);
	
	static void logOutput(int vrb, std::string msg,int vl);
	static void logOutput(int vrb, std::string msg,int vl0, int vl1);
	static void logOutput(int vrb, std::string msg0,int vl0, std::string msg1, int vl1);
	
	static void logOutput(int vrb, std::string msg,unsigned long vl);
	static void logOutput(int vrb, std::string msg,unsigned long vl0, unsigned long vl1);
	static void logOutput(int vrb, std::string msg0,unsigned long vl0, std::string msg1, unsigned long vl1);
	
	static void logOutput(int vrb, void (*funct)(void));
	
	static void logTime(int vrb);
	static void logAccumulatedTime(int vrb);
	
protected:
	//Variables
	static int verbose;
	static time_t initTime;
	static time_t stepTime;
};
#endif /* SndAlgs_h */
