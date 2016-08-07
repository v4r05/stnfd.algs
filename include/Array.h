//
//  Array.h
//  Stanford-Algorithms.Assignements
//
//  Created by lykanthrop on 2016.07.17.
//  Copyright © 2016 varo. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <stdio.h>
#include <string>

class Array{
		
public:
	
	enum sortType{merge=0,quickfst,quickmed,quicklst};
	enum pivotSelection{fst=0,med,lst};

	Array();
	Array(int* ptr, int sz);
	Array(std::string filename);
	~Array();
	
	int loadArrayFromFile(std::string filename);
	void printSorted();
	
	void sort(sortType tp);
	void mergeSort();
	void quickSort(pivotSelection psl);
	
	unsigned long int getInversions();
	unsigned long int getComparisons();
	
private:
	
	void merge_sort_recursion(int li, int length, int* buffer);
	void merge_sorting(int li, int lj, int ri, int rj, int* buffer);
	
	void quick_sort_recursion(int li, int ri, pivotSelection ps);
	int quick_sorting(int li, int ri, pivotSelection ps);
	
	//Variables
protected:
	
	int size=0;
	int* array_ptr = (int*)0;
	int* arraySorted_ptr = (int*)0;
		
	unsigned long int msInversions = 0;
	unsigned long int qsComparisons = 0;
};

#endif /* MSI_Array_h */
