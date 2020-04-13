#include "admin.h"

#include "../admin_list.h"

namespace qff233 {
namespace command 
{

AddAdmin::AddAdmin()
	:Command("AddAdmin") { }

void
AddAdmin::handle(MsgEvent& e)
{
	if (e.message.size() < 15) {
		e.sendMsg("��Ч���˺�");
		return;
	}
	std::string str = e.message.substr(13, e.message.size() - 13);
	try {
		if (!AdminListMgr::GetInstance()->addAdmin(std::stoll(str))) {
			e.sendMsg("�ļ�����������!!!");
		}
	} catch (const std::exception & ex) {
		e.sendMsg(std::string("��Ч���˺�  ") + ex.what());
	}
}

DelAdmin::DelAdmin()
	:Command("DelAdmin") { }

void
DelAdmin::handle(MsgEvent& e)
{
	if (e.message.size() < 15) {
		e.sendMsg("��Ч���˺�");
		return;
	}
	std::string str = e.message.substr(13, e.message.size() - 13);
	try {
		if (!AdminListMgr::GetInstance()->delAdmin(std::stoll(str))) {
			e.sendMsg("�ļ�����������!!!");
		}
	}
	catch (const std::exception & ex) {
		e.sendMsg(std::string("��Ч���˺�  ") + ex.what());
	}
}

}
}