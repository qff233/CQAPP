#include <CQSDK.h>
#include "appinfo.h"

#include "util/common.h"
#include "app.h"

MUST_AppInfo_RETURN(APP_ID)

EVE_Startup_EX(Startup)
//name:��Q����
//priority:30000
/*
����2��Ϊע��,����json�Զ�����
nameΪ�¼�����,һ���ʶ��;,����Ҫ�����¼�����
priorityΪ�¼����ȼ�(�μ� cq.im/deveventpriority)
��ͷ����Ϊ<//name:>��<//priority:>,�����пո��
���û��name,Ĭ��Ϊ�¼���
���û��priority,Ĭ��Ϊ30000
��Ҫ����{�ַ�,������Ϊ����
*/

{
	qff233::InitLogger();
	qff233::init();
	//��������ִ���������ֻ��ִ��һ��
	//�������������ȫ����Դ
}






EVE_Enable_EX(Enable)
//name:���ý��޷���������
//priority:30000
{
	//Ӧ���п��ܶ������
	//����������������������ڲ���Ҫ����Դ
}






EVE_Disable_EX(Disable)
//name:���ý����ܱ�������
//priority:30000
{
	//Ӧ���п��ܶ��ֹͣ
	//ֹͣ��dll�����������
	//�����ղ����κ��¼�Ҳ���ܵ����κ�API
}






EVE_Exit_EX(Exit)
//name:�˳�����
//priority:30000
{
	//������ִ���Ժ�,��Q���ʱ���ڽ�������
}
