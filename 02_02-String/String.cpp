#include "String.h"
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

inline void String::PrintString()
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		cout << str[i];
	}
}
