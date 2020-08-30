#pragma once
// recordng.h
#ifndef RECORDING_H
#define RECORDING_H

#include <iostream>
#include "iobuffer.h"

// class person with fixed field buffer

class Recording
	// a recording with a composite key
{
public:
	Recording();
	Recording(char * label, char * idNum, char * title,
		char * composer, char * artist);
	char Label[4];
	char IdNum[7]; char Title[30]; char Composer[30];
	char Artist[30]; //char Label[7]; ERROR! USELESS
	char* Key() const; // return key of object
	int Unpack(IOBuffer &);
	int Pack(IOBuffer &) const;
	void Print(ostream &, char * label = 0) const;
	friend ostream & operator << (ostream &, Recording &);
	friend istream & operator >> (istream & stream, Recording & rec);
};


inline ostream & operator << (ostream & stream, Recording & rec)
{
	rec.Print(stream); return stream;
}

inline istream & operator >> (istream & stream, Recording & rec) {
	cout << "<Input Record >" << endl;
	cout << "Label(3) : " << flush;
	stream.getline(rec.Label,4);
	cout << "IDNumber(6) : " << flush;
	stream.getline(rec.IdNum, 7);
	cout << "Title (29) : " << flush;
	stream.getline(rec.Title, 30);
	cout << "Composer (29) : " << flush;
	stream.getline(rec.Composer,30);
	cout << "Artist (29) : " << flush;
	stream.getline(rec.Artist, 30);
	return stream;
}

#endif
