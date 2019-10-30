#include "Counter.h"

Counter::Counter() : minVal(0), maxVal(1), currentVal(0)
{
}

Counter::Counter(int _minVal, int _maxVal) : minVal(_minVal), maxVal(_maxVal), currentVal(0)
{
}

void Counter::SetMinVal(int val)
{
	if (val >= maxVal)
	{
		minVal = maxVal - 1;
	}
	else
	{
		minVal = val;
	}
}

void Counter::SetMaxVal(int val)
{
	if (val <= minVal)
	{
		maxVal = minVal + 1;
	}
	else
	{
		maxVal = val;
	}
}

int Counter::GetMinVal()
{
	return minVal;
}

int Counter::GetMaxVal()
{
	return maxVal;
}

int Counter::GetCurrentVal()
{
	return currentVal;
}

void Counter::Reset()
{
	currentVal = minVal;
}

void Counter::Print()
{
	using namespace std;
	cout << "Min value:\t" << GetMinVal() << endl
		<< "Max value:\t" << GetMaxVal() << endl
		<< "Current value:\t" << GetCurrentVal() << endl;
}

Counter& Counter::operator++()
{
	if (currentVal < maxVal)
	{
		++currentVal;
	}
	else
	{
		currentVal = minVal;
	}
	return *this;
}
