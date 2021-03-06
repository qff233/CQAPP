#include "admin.h"

#include <fstream>
#include <sstream>

#include "../admin_list.h"
#include "../util/common.h"
#include "../file_store.h"

namespace qbot {
namespace command
{

AddAdmin::AddAdmin()
	:Command("AddAdmin") { }

void
	AddAdmin::handle(MsgEvent& e)
{
	if (e.message.size() < 15) {
		e.sendMsg("无效的账号");
		e.message_block();
		return;
	}
	if (e.fromAccount != *AdminListMgr::GetInstance()) {
		e.sendMsg("哦豁 你不是管理员！");
		e.message_block();
		return;
	}
	std::string str = e.message.substr(13, e.message.size() - 13);
	if (str[0] == '[') {
		str = str.substr(10, str.size() - 11);
	}
	try {
		int64_t account = std::stoll(str);
		if (account == *AdminListMgr::GetInstance()) {
			e.sendMsg("已经有该账号了，不要重复添加！");
			e.message_block();
			return;
		}
		if (!AdminListMgr::GetInstance()->add(account)) {
			e.sendMsg("文件操作有问题!!!");
			e.message_block();
		}
		e.sendMsg("添加成功~");
		e.message_block();
	}
	catch (const std::exception & ex) {
		e.sendMsg(std::string("无效的账号  ") + ex.what());
		e.message_block();
	}
}

DelAdmin::DelAdmin()
	:Command("DelAdmin") { }

void
	DelAdmin::handle(MsgEvent& e)
{
	if (e.message.size() < 15) {
		e.sendMsg("无效的账号");
		e.message_block();
		return;
	}
	if (e.fromAccount != *AdminListMgr::GetInstance()) {
		e.sendMsg("哦豁 你不是管理员！");
		e.message_block();
		return;
	}
	std::string str = e.message.substr(13, e.message.size() - 13);
	if (str[0] == '[') {
		str = str.substr(10, str.size() - 11);
	}
	try {
		if (std::stoll(str) != *AdminListMgr::GetInstance()) {
			e.sendMsg("这个人不是管理员");
			e.message_block();
			return;
		}
		if (!AdminListMgr::GetInstance()->del(std::stoll(str))) {
			e.sendMsg("文件操作有问题!!!");
			e.message_block();
		}
		e.sendMsg("删除成功~");
		e.message_block();
	}
	catch (const std::exception & ex) {
		e.sendMsg(std::string("无效的账号  ") + ex.what());
		e.message_block();
	}
}

AdminHelp::AdminHelp()
	:Command("AdminHelp") 
{ 


	//std::ifstream ss;
	//ss.open("adminhelp.txt");
	//if (!ss.is_open()) {
	//	m_isError = true;
	//	return;
	//}
	//std::string str;
	//while (std::getline(ss, str))
	//{
	//	m_help += (str + "\n");
	//}
	//m_help = qff233::utf82gbk(m_help.c_str());
	//ss.close();
}

void
AdminHelp::handle(MsgEvent& e)
{
	if (e.fromAccount != *AdminListMgr::GetInstance()) {
		e.sendMsg("不是管理员。查什么查？");
		e.message_block();
		return;
	}
	auto fss = qff233::FileStore::GetFile<qff233::FileStoreString>("AdminHelp");
	const std::string& msg = fss->getContent();
	e.sendMsg(msg);
	e.message_block();
}

AdminList::AdminList()
	:Command("AdminList") { }

void
AdminList::handle(MsgEvent& e)
{
	if (e.fromAccount != *AdminListMgr::GetInstance()) {
		e.sendMsg("不是管理员。查什么查？");
		e.message_block();
		return;
	}
	const auto& vecs = AdminListMgr::GetInstance()->get();
	std::stringstream ss;
	for (const auto& i : vecs) {
		ss << i << std::endl;
	}
	e.sendMsg(ss.str());
	e.message_block();
}

}
}