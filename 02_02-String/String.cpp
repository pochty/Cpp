#include "String.h"

void String::InputString()
{
	char buf[1000];
	cout << "->";
	int i{};
	while ((buf[i++] = getchar()) != '\n');
	buf[i - 1] = '\0';
	CopyByChar(buf);
}

void String::PrintString()
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		cout << str[i];
	}
}

void String::CopyByChar(char* _str)
{
	strSize = strnlen_s(_str, 10000) + 1;
	if (str) delete[] str;
	str = new char[strSize];
	for (size_t i = 0; i < strSize; i++)
	{
		str[i] = _str[i];
	}
}

void String::CopyByChar(const char _str[])
{
	strSize = strnlen_s(_str, 10000) + 1;
	if (str) delete[] str;
	str = new char[strSize];
	for (size_t i = 0; i < strSize; i++)
	{
		str[i] = _str[i];
	}
}
