/*
 * Word.h
 *
 *  Created on: Nov 5, 2017
 *      Author: navee
 */

#ifndef WORD_H_
#define WORD_H_

#include <string>
using namespace std;

/**
 * A word entry consisting of a word text and a frequency count
 * for a concordance.
 */
class Word
{
public:
    /**
     * Default constructor.
     */
    Word();

    /**
     * Constructor.
     * Create a word entry with the given text. Initialize the count to 1.
     * @param text the text of the word.
     */
    Word(string text);

    /**
     * Destructor.
     */
    virtual ~Word();

    /*
     * Getter
     * return the text
     */
    string get_text();

    /*
     * Getter
     * return the count
     */
    int get_count();

    /*
     * Void function which will increment the count value by 1
     */
    void increment_count();

    /*
     * overloaded boolean operator(not equal to)
     * Checks for the two word entries
     * the entries are unequal if either their text or count not match with each other
     */
    friend bool operator != (Word word_1, Word word_2);

private:
    string text;
    int count;
};

#endif /* WORD_H_ */
