#ifndef TEEIN_H
#define TEEIN_H
#include <ostream>

/******************************************
Tee.h - This class is based off of the Unix shell command tee
to be able to output values to multiple locations.
by overriding the << operator, I am able to use this
class to output text to both the console and a file
at the same time, with the same line.

Author:		Adam Allard
Created:	06/13/15 - Initial

Source
Credit:		Username: Useless
Website:     http://stackoverflow.com/questions/13978480/using-freopen-to-print-to-file-and-screen
*******************************************/


class TeeIn
{
	std::istream &first;
	std::ostream &second;

	template<typename T> friend Tee& operator>> (Tee&, T);

public:
	TeeIn(std::istream &f, std::ostream &s) : first(f), second(s) {}
};

template <typename T>
Tee& operator>> (Tee &t, T val)
{
	t.first >> val;
	t.second << val;
	return t;
}
#endif