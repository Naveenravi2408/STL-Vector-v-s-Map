/*
 * WordVector.h
 *
 *  Created on: Nov 5, 2017
 *      Author: navee
 */

#ifndef WORDVECTOR_H_
#define WORDVECTOR_H_

#include <vector>
#include "TimedContainer.h"
#include "Word.h"

using namespace std;

/**
 * A vector implementation for the concordance that inherits a timer.
 */
class WordVector : public TimedContainer
{
public:
    /**
     * Default constructor.
     */
    WordVector();

    /**
     * Destructor.
     */
    virtual ~WordVector();

    /*
     * Getter
     * @return the vector reference
     */
    vector<Word>& get_data();

    /*
     * Getter
     * @return the size of the vector
     */
    int get_size();

    /**
     * Insert a new word into the sorted vector,
     * or increment the count of an existing word.
     * @param text the text of the word to insert or increment.
     * @return a pointer to the word entry.
     */
    Word *insert(const string text);

    /**
     * Search the vector for a word entry with the given text.
     * @param text the text of the word to find.
     * @return a pointer to the word entry if found, nullptr if not.
     */
    Word *search(const string text);

private:
    vector<Word> data;
};

#endif /* WORDVECTOR_H_ */

