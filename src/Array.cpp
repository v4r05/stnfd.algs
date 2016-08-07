//
//  MSI_Array.cpp
//  MSI
//
//  Created by lykanthrop on 2016.07.17.
//
//

#include "Array.h"
#include <fstream>

Array::Array()
{	
}

Array::Array(int* ptr, int sz)
{
	size = sz;
	
	array_ptr = new int[size];
	
	for(int i=0;i<size;++i)
	{
		array_ptr[i] = ptr[i];
	}
	
	arraySorted_ptr = new int[size];
}

Array::~Array()
{
	if(array_ptr!=(int*)0)
	{
		delete[] array_ptr;
	}
	
	if(arraySorted_ptr!=(int*)0)
	{
		delete[] arraySorted_ptr;
	}
}

int Array::loadArrayFromFile(std::string filename)
{
	printf("Loading File\n");
	int out = -1;
	
	std::ifstream file(filename,std::fstream::in);
	
	
	if(file.is_open())
	{
		printf("File Open\n");
		
		std::string gluk;
		while(std::getline(file,gluk))
		{
			size++;
		}
		
		printf("Size: %i\n",size);
		array_ptr = new int[size];
		
		arraySorted_ptr = new int[size];
		
		file.clear();
		file.seekg(0);
		
		int i = 0;
		int value;
		while(std::getline(file,gluk))
		{
			printf("Array %i\n",std::stoi(gluk));
			value = std::stoi(gluk);
			array_ptr[i] = value;
			arraySorted_ptr[i] = value;
			i++;
		}
		
		file.close();
		
		out = 0;
	}
	
	return out;
}

void Array::printSorted()
{
	for(int i=0;i<size;++i)
	{
		printf("INDEX %i : %i\n",i,arraySorted_ptr[i]);
	}
}

void Array::sort(sortType tp)
{
	switch (tp)
	{
		case Array::sortType::quickfst:
			quickSort(Array::pivotSelection::fst);
			break;
		case Array::sortType::quickmed:
			quickSort(Array::pivotSelection::med);
			break;
		case Array::sortType::quicklst:
			quickSort(Array::pivotSelection::lst);
			break;
		default:
			mergeSort();
			break;
	}
}

void Array::mergeSort()
{
	if(size>0)
	{
		int* bufferArray = new int[size];
		
		for(int i=0;i<size;++i)
		{
			arraySorted_ptr[i] = array_ptr[i];
			bufferArray[i] = array_ptr[i];
		}
		
		printf("Sorting Array.\n");
		merge_sort_recursion(0, size-1, bufferArray);
		
		delete[] bufferArray;
	}
}

void Array::quickSort(Array::pivotSelection psl)
{
	if(size>0)
	{
		for(int i=0;i<size;++i)
		{
			arraySorted_ptr[i] = array_ptr[i];
		}
		
		printf("Sorting Array.\n");
		
		qsComparisons = 0;
		
		quick_sort_recursion(0,size-1,psl);
	}

}

unsigned long int Array::getInversions(){
	return msInversions;
}

unsigned long int Array::getComparisons(){
	return qsComparisons;
}

void Array::merge_sort_recursion(int l, int r, int* buffer)
{
	printf("Sorting from %i to %i\n",l,r);
	
	if(r>l)
	{
		int length = (r - l)/2;
		
		printf("Dividing %i -> %i : %i -> %i\n",l,l+length,l+length+1,r);
		merge_sort_recursion(l,l+length,buffer);
		merge_sort_recursion(l+length+1,r,buffer);
		
		merge_sorting(l,l+length,l+length+1,r,buffer);
		
	}
	else
	{
		printf("Nothing to Do\n");
	}
	
}

void Array::merge_sorting(int li, int lj, int ri, int rj, int* buffer)
{
	printf("Merging right: %i -> %i left %i -> %i\n",li,lj,ri,rj);
	
	int index = li;
	int indexl = li;
	int indexr = ri;
	while(indexl<=lj && indexr<=rj)
	{
		if(buffer[indexl]<=buffer[indexr])
		{
			arraySorted_ptr[index] = buffer[indexl];
			indexl++;
		}
		else
		{
			arraySorted_ptr[index] = buffer[indexr];
			indexr++;
			
			msInversions+=(lj-indexl+1);
		}
		index++;
	}
	
	for(int i=indexl;i<=lj;++i)
	{
		arraySorted_ptr[index] = buffer[i];
		index++;
	}
	
	for(int i=indexr;i<=rj;++i)
	{
		arraySorted_ptr[index] = buffer[i];
		index++;
	}
	
	for(int i=li;i<=rj;++i)
	{
		buffer[i] = arraySorted_ptr[i];
	}
}

void Array::quick_sort_recursion(int li, int ri, pivotSelection ps)
{
	if(li<ri)
	{
		int idx = quick_sorting(li,ri,ps);
		
		quick_sort_recursion(li,idx-1,ps);
		quick_sort_recursion(idx+1,ri,ps);
	}
}

int Array::quick_sorting(int li, int ri, pivotSelection ps)
{
	printf("Quick Sorting from %i to %i\n",li,ri);
	int pivotIdx = li;
	int currentIdx = li+1;
	
	int swapValue = 0;
	int i = 0;
	
	switch (ps)
	{
		case Array::pivotSelection::med:
			
			printf("Sorting MED\n");
			i = (ri+li)/2;
			
			if((arraySorted_ptr[ri]<arraySorted_ptr[li] && arraySorted_ptr[ri]>arraySorted_ptr[i]) ||
			   (arraySorted_ptr[ri]>arraySorted_ptr[li] && arraySorted_ptr[ri]<arraySorted_ptr[i]))
			{
				swapValue = arraySorted_ptr[pivotIdx];
				
				arraySorted_ptr[pivotIdx] = arraySorted_ptr[ri];
				arraySorted_ptr[ri] = swapValue;
			}
			else if((arraySorted_ptr[i]<arraySorted_ptr[ri] && arraySorted_ptr[i]>arraySorted_ptr[li]) ||
					(arraySorted_ptr[i]>arraySorted_ptr[ri] && arraySorted_ptr[i]<arraySorted_ptr[li]))
			{
				swapValue = arraySorted_ptr[pivotIdx];
				
				arraySorted_ptr[pivotIdx] = arraySorted_ptr[i];
				arraySorted_ptr[i] = swapValue;
			}
			
			break;
		case Array::pivotSelection::lst:
			printf("Sorting LST\n");
			swapValue = arraySorted_ptr[pivotIdx];
			
			arraySorted_ptr[pivotIdx] = arraySorted_ptr[ri];
			arraySorted_ptr[ri] = swapValue;
			break;
		default:
			printf("Sorting FST\n");
			break;
	}
	
	int pivotValue = arraySorted_ptr[pivotIdx];
	
	printf("Pivot Value: %i\n",pivotValue);
	
	while(currentIdx<=ri)
	{
		
		if(arraySorted_ptr[currentIdx]<pivotValue)
		{
			printf("Swaping\n");
			swapValue = arraySorted_ptr[pivotIdx+1];
			arraySorted_ptr[pivotIdx+1] = arraySorted_ptr[currentIdx];
			arraySorted_ptr[currentIdx] = swapValue;
			
			++pivotIdx;
		}
		
		++currentIdx;
	}
	
	if(pivotIdx>li)
	{
		arraySorted_ptr[li] = arraySorted_ptr[pivotIdx];
		arraySorted_ptr[pivotIdx] = pivotValue;
	}
	
	qsComparisons+=ri-li;
	
	printf("Comparisons: %lu\n",qsComparisons);
	printf("Pivot Index: %i\n",pivotIdx);
	
	return pivotIdx;
}
