#pragma once
#include <iostream>
/*Class Counter*/
class Counter
{
public:
	Counter();
	Counter(int minVal, int maxVal);
	void SetMinVal(int val); //If the minimum value is greater than the maximum value then the value is maxVal-1
	void SetMaxVal(int val); //If the maximum value is lesser than the minimum value then the value is minVal+1
	int GetMinVal();
	int GetMaxVal();
	int GetCurrentVal();
	void Reset();
	void Print(); //Prints out the current state of the counter
	Counter& operator++(); //Counter resets on the max value

private:
	int minVal;
	int maxVal;
	int currentVal;
};

