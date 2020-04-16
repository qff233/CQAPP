#include "admin.h"

#include <fstream>
#include <sstream>

#include "../admin_list.h"
#include "../util/common.h"

namespace qbot {
namespace command
{

	AddAdmin::AddAdmin()
		:Command("AddAdmin") { }

	void
		AddAdmin::handle(MsgEvent& e)
	{
		if (e.message.size() < 15) {
			e.sendMsg("��Ч���˺�");
			e.message_block();
			return;
		}
		if (e.fromAccount != *AdminListMgr::GetInstance()) {
			e.sendMsg("Ŷ�� �㲻�ǹ���Ա��");
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
				e.sendMsg("�Ѿ��и��˺��ˣ���Ҫ�ظ���ӣ�");
				e.message_block();
				return;
			}
			if (!AdminListMgr::GetInstance()->addAdmin(account)) {
				e.sendMsg("�ļ�����������!!!");
				e.message_block();
			}
			e.sendMsg("��ӳɹ�~");
			e.message_block();
		}
		catch (const std::exception & ex) {
			e.sendMsg(std::string("��Ч���˺�  ") + ex.what());
			e.message_block();
		}
	}

	DelAdmin::DelAdmin()
		:Command("DelAdmin") { }

	void
		DelAdmin::handle(MsgEvent& e)
	{
		if (e.message.size() < 15) {
			e.sendMsg("��Ч���˺�");
			e.message_block();
			return;
		}
		if (e.fromAccount != *AdminListMgr::GetInstance()) {
			e.sendMsg("Ŷ�� �㲻�ǹ���Ա��");
			e.message_block();
			return;
		}
		std::string str = e.message.substr(13, e.message.size() - 13);
		if (str[0] == '[') {
			str = str.substr(10, str.size() - 11);
		}
		try {
			if (!AdminListMgr::GetInstance()->delAdmin(std::stoll(str))) {
				e.sendMsg("�ļ�����������!!!");
				e.message_block();
			}
			e.sendMsg("ɾ���ɹ�~");
			e.message_block();
		}
		catch (const std::exception & ex) {
			e.sendMsg(std::string("��Ч���˺�  ") + ex.what());
			e.message_block();
		}
	}

AdminHelp::AdminHelp()
	:Command("AdminHelp") 
{ 
	std::ifstream ss;
	ss.open("adminhelp.txt");
	if (!ss.is_open()) {
		m_isError = true;
		return;
	}
	std::string str;
	while (std::getline(ss, str))
	{
		m_help += (str + "\n");
	}
	m_help = qff233::utf82gbk(m_help.c_str());
	ss.close();
}

void 
AdminHelp::reload()
{
	std::ifstream ss;
	ss.open("adminhelp.txt");
	if (!ss.is_open()) {
		m_isError = true;
		return;
	}
	std::string str;
	while (std::getline(ss, str))
	{
		m_help += (str + "\n");
	}
	m_help = qff233::utf82gbk(m_help.c_str());
	ss.close();
}

void
AdminHelp::handle(MsgEvent& e)
{
	if (m_isError) {
		e.sendMsg("��ʼ������ʧ�ܣ� �Ͻ��п����߱���");
		e.message_block();
		return;
	}
	if (e.fromAccount != *AdminListMgr::GetInstance()) {
		e.sendMsg("���ǹ���Ա����ʲô�飿");
		e.message_block();
		return;
	}
	e.sendMsg(m_help);
	e.message_block();
}

AdminList::AdminList()
	:Command("AdminList") { }

void
AdminList::handle(MsgEvent& e)
{
	if (e.fromAccount != *AdminListMgr::GetInstance()) {
		e.sendMsg("���ǹ���Ա����ʲô�飿");
		e.message_block();
		return;
	}
	const auto& vecs = AdminListMgr::GetInstance()->getList();
	std::stringstream ss;
	for (const auto& i : vecs) {
		ss << i << std::endl;
	}
	e.sendMsg(ss.str());
	e.message_block();
}

}
}