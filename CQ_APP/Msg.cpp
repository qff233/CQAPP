#include <CQSDK.h>
#include <string>

#include "app.h"
#include "command.h"

EVE_GroupMsg_EX(GroupMsg_EX)
{
	if(qff233::CommandMgr::GetInstance()->handle(e)) return;  //����ָ��
	qff233::handle(e);							   //����or��¼ ��Ϣ
}
EVE_Request_AddGroup_EX(Request_AddGroupMsg_EX)
{
	if (e.subType == 2) {
		e.pass();				//�Զ�ͬ���Ⱥ����
	}
}

EVE_PrivateMsg_EX(PrivateMsg_EX)
{
}
EVE_DiscussMsg_EX(DiscussMsg_EX) //��������Ϣ
{
}