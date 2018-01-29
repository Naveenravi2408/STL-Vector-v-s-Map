/*
 * WordMap.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: navee
 */

#include <iostream>
#include <map>
#include "WordMap.h"

using namespace std;
/**
 * Default constructor.
 */
WordMap::WordMap()
{}

/**
 * Destructor.
 */
WordMap::~WordMap()
{}

/*
 * Getter
 * @return the size of the map
 */
int WordMap::get_size()
{
	return data.size();
}

/*
 * Getter
 * @return the map reference
 */
map<string, Word>& WordMap::get_data()
{
	return data;
}

/**
 * Insert a new word into the map,
 * or increment the count of an existing word.
 * @param text the text of the word to insert or increment.
 * @return a pointer to the word entry.
 */
Word *WordMap::insert(const string text)
{
    map<string, Word>::iterator itr;
    itr = data.find(text);	// find the required word in the map

    if(itr != data.end())	// if the word is found increment its count
    {
    	// referred =>> http://thispointer.com/how-check-if-a-given-key-exists-in-a-map-c/
    	itr->second.increment_count();
    }

    else{	// if the word is not found then insert it as a new word

    	// referred =>> http://thispointer.com/c-map-insert-example/
    	data.insert(std::pair<std::string, Word>(text,Word(text)));
    }
    return &data[text];
}

/**
 * Search the map for a word entry with the given text.
 * @param text the text of the word to find.
 * @return a pointer to the word entry if found, nullptr if not.
 */
Word *WordMap::search(const string text)
{
	map<string, Word>::iterator itr;
	itr = data.find(text);	// find the required word in the map

	if(itr == data.end())	// if the word is not found return nullptr
	{
		return nullptr;
	}
	else{		// if the word is found return a pointer to the word entry
		return &data[text];
	}
}


