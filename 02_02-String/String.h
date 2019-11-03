/*Draft class Person */
#pragma once
#include <iostream>
using namespace std;

class String
{
public:
	String() : strSize{ 80 }
	{
		str = new char[strSize] { '\0' };
	}
	String(const char _str[])
	{
		CopyByChar(_str);
	}
	void InputString();
	void SetString(const char _str[])
	{
		CopyByChar(_str);
	}
	void SetString(char* _str)
	{
		CopyByChar(_str);
	}
	char* GetString()
	{
		return str;
	}
	void PrintString();
	String& operator=(String& rVal)
	{
		CopyByChar(rVal.str);
		return *this;
	}

private:
	size_t strSize;
	char* str;

	void CopyByChar(char* _str)
	{
		strSize = strnlen_s(_str, 10000) + 1;
		if (str) delete[] str;
		str = new char[strSize];
		for (size_t i = 0; i < strSize; i++)
		{
			str[i] = _str[i];
		}
	}
	void CopyByChar(const char _str[])
	{
		strSize = strnlen_s(_str, 10000) + 1;
		if (str) delete[] str;
		str = new char[strSize];
		for (size_t i = 0; i < strSize; i++)
		{
			str[i] = _str[i];
		}
	}

	friend istream& operator>>(istream& is, String& st)
	{
		is >> st.str;
		return is;
	}
	friend ostream& operator<<(ostream& os, String& st)
	{
		os << st.str;
		return os;
	}
};


