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

	void CopyByChar(char* _str);
	void CopyByChar(const char _str[]);

	friend istream& operator>>(istream& is, String& st)
	{
		return is >> st.str;
	}
	friend ostream& operator<<(ostream& os, String& st)
	{
		return os << st.str;
	}
};


