/*
 * WordVector.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: navee
 */

#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"
#include <algorithm>

using namespace std;

/**
 * Default constructor.
 */
WordVector::WordVector()
{}

/**
 * Destructor.
 */
WordVector::~WordVector()
{}

/*
 * Getter
 * @return the vector reference
 */
vector<Word>& WordVector::get_data()
{
	return data;
}

/*
 * Getter
 * @return the size of the vector
 */
int WordVector::get_size()
{
	return data.size();
}

/**
 * Insert a new word into the sorted vector,
 * or increment the count of an existing word.
 * @param text the text of the word to insert or increment.
 * @return a pointer to the word entry.
 */
/*Word *WordVector::insert(const string text)
{
	bool found = false;
    if (data.size() == 0)	//if the vector is empty
    {
    	 data.push_back(Word(text));
    	 return &data[0];
    }

    else{	//insert a new word or increment its count if it already exists
    	vector<Word>::iterator index_itr;
    	for(index_itr = data.begin(); index_itr!= data.end(); index_itr++)	// iterate the entire vector while checking for the required string
    	   {
    			if(text == index_itr->get_text()) // if required word is found
    			{
    				found = true;
    				data[distance(data.begin(), index_itr)].increment_count();	// increment its count value by 1
    				break;
    			}
     		}

    	if(found == false) // if required word is not found
    	{
    		// iterate the entire vector while comparing value of the text to keep the vector elements sorted according to alphabetical order
    		 for(index_itr = data.begin(); ((index_itr!= data.end())&&(text > index_itr->get_text())); index_itr++)
    		    {}
    		  data.insert(index_itr, Word(text));
    		  return &data[distance(data.begin(), index_itr)];
    	}
    	return &data[distance(data.begin(), index_itr)];
    }
}*/

//******* EXTRA CREDIT ******* USED BINARY SEARCH FOR ITERATING THROUGH THE VECTOR *********** referred week 6 slide #47 for binary search code

Word *WordVector::insert(const string text)
{
	vector<Word>::iterator index_itr;
	bool found = false;
    if (data.size() == 0)
    {
    	 data.push_back(Word(text));
    	 return &data[0];
    }

    else{
    		//referred week 6 slide #47 for binary search code
    		int low = 0;
    		int high = data.size()-1;
    		while (low <= high)
    		{
    			int mid = (low + high)/2;	// Get the midpoint of the subrange

    			if(text == data[mid].get_text())	// Found the target value?
    			{
    				found = true;
    				data[mid].increment_count();
    				return &data[mid];
    			}

    			else if(text < data[mid].get_text())	// Search the first half next
    			{
    				high = mid-1;
    			}

    			else	// Search the second half next
    			{
    				low = mid+1;
    			}
    		}

    	if(found == false)
    	{
    		 for(index_itr = data.begin(); ((index_itr!= data.end())&&(text > index_itr->get_text())); index_itr++)
    		    {}
    		  data.insert(index_itr, Word(text));
    		  return &data[distance(data.begin(), index_itr)];
    	}
    	return nullptr;
    }
}

/**
 * Search the vector for a word entry with the given text.
 * @param text the text of the word to find.
 * @return a pointer to the word entry if found, nullptr if not.
 */
/*Word *WordVector::search(const string text)
{
	// iterate the entire vector while checking for the required string
	vector<Word>::iterator itr;
	for(itr = data.begin(); itr!= data.end(); itr++)
	   {
			if(text == itr->get_text()) // if found return a pointer to the word entry
	          {
				 return &data[distance(data.begin(), itr)];
	             break;
	          }
	   }
	return nullptr;	// else return null pointer
}*/

//******* EXTRA CREDIT ******* USED BINARY SEARCH FOR ITERATING THROUGH THE VECTOR *********** referred week 6 slide #47 for binary search code

Word *WordVector::search(const string text)
{
	//referred week 6 slide #47 for binary search code
	int low = 0;
	int high = data.size()-1;

	while (low <= high)
	{
	    int mid = (low + high)/2;	// Get the midpoint of the subrange

	    if(text == data[mid].get_text())	// Found the target value?
	    {
	    	return &data[mid];
	    }

	    else if(text < data[mid].get_text())	// Search the first half next
	    {
	    	high = mid-1;
	    }

	  	else		// Search the second half next
	   	{
	  		low = mid+1;
	    }
	}
return nullptr;
}

