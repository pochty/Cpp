#pragma once
#include "CatalogItem.h"

CatalogItem::CatalogItem(std::string companyName_, std::string owner_, 
	std::string phone_, std::string address_, std::string activity_)
	: CatalogItem()
{
	SetData(companyName_, owner_, phone_, address_, activity_);
}

CatalogItem::CatalogItem(size_t id_, std::string companyName_, std::string owner_,
	std::string phone_, std::string address_, std::string activity_)
	: CatalogItem()
{
	id = id_;
	SetData(companyName_, owner_, phone_, address_, activity_);
}

CatalogItem::CatalogItem(const char* companyName_, const char* owner_,
	const char* phone_, const char* address_, const char* activity_)
	: CatalogItem()
{
	SetData(companyName_, owner_, phone_, address_, activity_);
}

void CatalogItem::SetData(std::string companyName_, std::string owner_, 
	std::string phone_, std::string address_, std::string activity_)
{
	companyName = companyName_;
	owner = owner_;
	phone = phone_;
	address = address_;
	activity = activity_;
}

std::ostream& operator<<(std::ostream& os, const CatalogItem& obj)
{
	os << "ID: " << obj.id
		<< "\nCompany: " << obj.companyName.c_str()
		<< "\nOwner: " << obj.owner.c_str()
		<< "\nPhone: " << obj.phone.c_str()
		<< "\nAddress: " << obj.address.c_str()
		<< "\nActivity: " << obj.activity.c_str() << std::endl;
	return os;
}

