#pragma once

#include <vector>

#include "util/singleton.h"

namespace qbot 
{

class AdminList 
{
public:
	bool add(int64_t v);
	bool del(int64_t v);
	
	const std::vector<int64_t>& get() const;

	bool operator==(int64_t rhs) const;
	bool operator!=(int64_t rhs) const;
};

bool operator!=(const int64_t al, const AdminList& v);
bool operator==(const int64_t al, const AdminList& v);

typedef qff233::Singleton<AdminList> AdminListMgr;

}