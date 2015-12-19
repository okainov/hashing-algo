#pragma once

typedef int T;

class AbstractHashTable
{
public:
	virtual ~AbstractHashTable() {}
	virtual void add(T elem)=0;
	virtual bool lookup(T elem)=0;
	virtual void remove(T elem)=0;
	virtual void printUsageDetails()=0;

};