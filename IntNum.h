#pragma once

#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
#include <stdint.h>
using namespace std;

class IntNum 
{
	int base_10_int; //uint_32 
public:
	IntNum();
	~IntNum();
	bool input();
	void outputBase();
	void output();
	int &overK();
	int oneComplement();
	int twoComplement();
	string SignMagnitude();
	float singlePrecisionfloat();
	int saveFile();
	int saveFile(string file_name);
	friend IntNum &operator-(IntNum& a, IntNum b);
	friend istream &operator>>(istream & ist, IntNum a);
};

