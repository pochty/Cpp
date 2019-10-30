#pragma once
#include <string>
#include <iostream>
#include "Student.h"

class StudentGroup
{
public:
	StudentGroup()
	{
		name = "-";
		size = 0;
		capacity = size + 10;
		students = new Student[capacity];
	}
	StudentGroup(std::string _name) : StudentGroup()
	{
		name = _name;
	}
	StudentGroup(const StudentGroup& that)
	{
		name = that.name;
		size = that.size;
		capacity = that.capacity;
		students = new Student[capacity];
		for (size_t i = 0; i < size; i++)
		{
			students[i] = that.students[i];
		}
	}
	~StudentGroup()
	{
		delete[] students;
	}
	StudentGroup& operator=(const StudentGroup& that);
	friend std::ostream& operator<<(std::ostream& os, StudentGroup group);
	void Push(const Student& st) //Add student to the group
	{
		if (size >= capacity)
		{
			capacity += 10;
			Student* studentsTmp = students;
			students = new Student[capacity];
			for (size_t i = 0; i < size; i++)
			{
				students[i] = studentsTmp[i];
			}
			delete[] studentsTmp;
		}
		students[size++] = st;
	}
	void Remove(std::string _name) //Remove student from the group
	{
		for (size_t i = 0; i < size; i++)
		{
			if (students[i].GetName() == _name)
			{
				std::swap(students[i], students[--size]);
				break;
			}
		}
	}

private:
	std::string name;
	size_t size;
	size_t capacity;
	Student* students;

};

