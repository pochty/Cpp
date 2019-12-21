#include "Catalog.h"

void Catalog::Add(const char* companyName_, const char* owner_, 
	const char* phone_, const char* address_, const char* activity_)
{
	CatalogItem item(companyName_, owner_, phone_, address_, activity_);
	items.push_back(item);
}

void Catalog::Add(std::string companyName_, std::string owner_, 
	std::string phone_, std::string address_, std::string activity_)
{
	CatalogItem item(companyName_, owner_, phone_, address_, activity_);
	items.push_back(item);
}

void Catalog::Print()
{
	for (size_t i = 0; i < items.size(); i++)
	{
		std::cout << items[i] << std::endl;
	}
}

void Catalog::SetItem(int id_,const char* companyName_, const char* owner_, 
	const char* phone_, const char* address_, const char* activity_)
{
	CatalogItem item(companyName_, owner_, phone_, address_, activity_);

}

void Catalog::FindCompanyName(const std::string matchStr)
{
	for (auto& item : items)
	{
		if (matchStr == item.companyName)
		{
			std::cout << item;
		}
	}
}

void Catalog::FindOwner(const std::string matchStr)
{
	for (auto& item : items)
	{
		if (matchStr == item.owner)
		{
			std::cout << item;
		}
	}
}

void Catalog::FindPhone(const std::string matchStr)
{
	for (auto& item : items)
	{
		if (matchStr == item.phone)
		{
			std::cout << item;
		}
	}
}

void Catalog::FindAddress(const std::string matchStr)
{
	for (auto& item : items)
	{
		if (matchStr == item.address)
		{
			std::cout << item;
		}
	}
}

void Catalog::FindActivity(const std::string matchStr)
{
	for (auto& item : items)
	{
		if (matchStr == item.activity)
		{
			std::cout << item;
		}
	}
}

void Catalog::FileSave()
{
	std::fstream fs("catalog.bin", std::ios::out | std::ios::binary);
	if (fs.bad())
	{
		std::cout << "File error" << std::endl;
		exit(1);
	}
	else
	{
		size_t counter = CatalogItem::counter;
		fs.write((char*)&counter, sizeof(size_t));
		for (auto item : items)
		{
			size_t id_ = item.id;
			fs.write((char*)&id_, sizeof(id_));
			WriteField(item.companyName, fs);
			WriteField(item.owner, fs);
			WriteField(item.phone, fs);
			WriteField(item.address, fs);
			WriteField(item.activity, fs);
		}
		fs.close();
	}
}

void Catalog::FileLoad()
{
	std::fstream fs("catalog.bin", std::ios::in | std::ios::binary | std::ios::_Nocreate);
	if (fs.bad())
	{
		std::cout << "File error" << std::endl;
		exit(1);
	}
	else
	{
		items.clear();
		size_t counter = 0;
		fs.read((char*)&counter, sizeof(size_t));
		size_t id_;
		while (fs.read((char*)&id_, sizeof(id_)))
		{
			std::string companyName_ = this->ReadField(fs);
			std::string owner_ = this->ReadField(fs);
			std::string phone_ = this->ReadField(fs);
			std::string address_ = this->ReadField(fs);
			std::string activity_ = this->ReadField(fs);
			CatalogItem item(id_, companyName_, owner_, phone_, address_, activity_);
			items.push_back(item);
		}
		CatalogItem::counter = counter;
		fs.close();
	}
}

void Catalog::WriteField(std::string field, std::fstream& fs)
{
	size_t sz = field.length();
	fs.write((char*)&sz, sizeof(sz));//write size of field
	fs.write((char*)field.c_str(), sz * sizeof(char));//write field
}

std::string Catalog::ReadField(std::fstream& fs)
{
	size_t sz;
	fs.read((char*)&sz, sizeof(sz));//read size of field
	char* str = new char[sz + 1];
	fs.read((char*)str, sz);//read field
	str[sz] = '\0';
	std::string result = str;
	delete[] str;
	return result;
}

