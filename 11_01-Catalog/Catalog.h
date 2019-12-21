#pragma once
#include "CatalogItem.h"
#include <vector>
#include <fstream>

class Catalog
{
public:
	void Add(const char* companyName_, const char* owner_, 
		const char* phone_, const char* address_, const char* activity_);
	void Add(std::string companyName_, std::string owner_,
		std::string phone_, std::string address_, std::string activity_);
	void Print();
	void SetItem(int id_, const char* companyName_, const char* owner_,
		const char* phone_, const char* address_, const char* activity_);
	void FindCompanyName(const std::string matchStr);
	void FindOwner(const std::string matchStr);
	void FindPhone(const std::string matchStr);
	void FindAddress(const std::string matchStr);
	void FindActivity(const std::string matchStr);
	void FileSave();
	void FileLoad();

private:
	std::vector<CatalogItem> items;
	void WriteField(std::string field, std::fstream& fs);
	std::string ReadField(std::fstream& fs);
};

