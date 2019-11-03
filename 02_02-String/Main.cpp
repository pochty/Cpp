#include <iostream>
#include "String.h"

int main()
{
	String st("Input string");
	cout << st;
	st.InputString();
	cout << st;
	cout << "cin->";
	cin >> st;
	cout << st;
}