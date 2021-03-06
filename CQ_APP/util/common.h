#pragma once

#include <CQSDK.h>
#include <memory>
#include "config.h"
#include "singleton.h"

namespace qff233 {
	void InitLogger();
	std::shared_ptr<Logger> GetLogger();

	std::string gbk2utf8(const char* src_str);
	std::string utf82gbk(const char* src_str);
}