/*
 * Word.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: navee
 */

#include <string>
#include "Word.h"
using namespace std;

/*
 * Default constructor
 */
Word::Word() : text(""), count(0) {}

/*
 * Constructor
 * enter the word with the given text and set its count to one
 * @param text is the text of the word to be entered
 */
Word::Word(string text) : text(text), count(1) {}

/*
 * Destructor
 */
Word::~Word() {}

/*
 * Getter
 * return the text
 */
string Word::get_text()
{
	return text;
}

/*
 * Getter
 * return the count
 */
int Word::get_count()
{
	return count;
}

/*
 * Void function which will increment the count value by 1
 */
void Word::increment_count()
{
	count++;
}

/*
 * overloaded boolean operator(not equal to)
 * Checks for the two word entries
 * the entries are unequal if either their text or count not match with each other
 */
bool operator != (Word word_1, Word word_2)
{
	if((word_1.text != word_2.text)||(word_1.count != word_2.count))
	{
		return true;
	}
	else{return false;}
}
