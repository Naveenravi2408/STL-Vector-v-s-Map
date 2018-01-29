/*
 * TimedContainer.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: navee
 */

#include "TimedContainer.h"
#include "Word.h"
#include <ctime>
#include <chrono>

using namespace std::chrono;

/*
 * Default constructor
 */
TimedContainer::TimedContainer()
{
	elapsed_time = 0;
}

/*
 * Destructor
 */
TimedContainer::~TimedContainer()
{}

/*
 * Getter function
 * return the elapsed time
 */
long TimedContainer::get_elapsed_time() const
{
	return elapsed_time;
}

/*
 * Reset the elapsed time
 */
void TimedContainer::reset_elapsed_time()
{
	elapsed_time = 0;
}

/**
 * Time the insertion operation and
 * add the time to elapsed_time.
 * @param text the text of the word to insert.
 * @return pointer to the inserted word element.
 */
Word *TimedContainer::timed_insert(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Do the insertion.
    Word *word = insert(text);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(duration_cast<microseconds>(end_time - start_time).count());

    return word;
}

/**
 * Time the search operation and
 * add the time to elapsed_time.
 * @param text the text of the word to insert.
 * @return pointer to the word element if found, else nullptr.
 */
Word *TimedContainer::timed_search(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Do the search.
    Word *word = search(text);

    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    long elapsed = duration_cast<microseconds>(end_time - start_time).count();
    increment_elapsed_time(elapsed);

    return word;
}

/*
 * Increment the elapsed time
 * @param micro_sec is the number of microseconds to be added
 */
void TimedContainer::increment_elapsed_time(long micro_sec)
{
	elapsed_time = elapsed_time + micro_sec;
}
