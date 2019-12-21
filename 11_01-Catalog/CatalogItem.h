#pragma once
#include <iostream>
#include <string>
#include <fstream>

class CatalogItem
{
public:
	CatalogItem()
	{
		id = counter++;
	}
	CatalogItem(std::string companyName_, std::string owner_,
		std::string phone_, std::string address_, std::string activity_);
	CatalogItem(size_t id_, std::string companyName_, std::string owner_,
		std::string phone_, std::string address_, std::string activity_);
	CatalogItem(const char* companyName_, const char* owner_,
		const char* phone_, const char* address_, const char* activity_);
	void SetData(std::string companyName_, std::string owner_, 
		std::string phone_, std::string address_, std::string activity_);
	friend std::ostream& operator<<(std::ostream& os, const CatalogItem& obj);

private:
	static size_t counter;
	size_t id;
	std::string companyName;
	std::string owner;
	std::string phone;
	std::string address;
	std::string activity;
	friend class Catalog;
};

