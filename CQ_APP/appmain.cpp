#include <CQSDK.h>
#include "appinfo.h"

#include "util/common.h"
#include "app.h"

MUST_AppInfo_RETURN(APP_ID)



//�����static,��ʾ���loggerֻ�б�cpp��Ч
static Logger logger("��Q����Ӧ��");


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
	logger.Info("Startup");
	qff233::InitLogger();
	qff233::init();
	//��������ִ���������ֻ��ִ��һ��
	//�������������ȫ����Դ
}






EVE_Enable_EX(Enable)
//name:���ý��޷���������
//priority:30000
{
	logger.Info("Enable");
	//Ӧ���п��ܶ������
	//����������������������ڲ���Ҫ����Դ
}






EVE_Disable_EX(Disable)
//name:���ý����ܱ�������
//priority:30000
{
	logger.Info("Disable");
	//Ӧ���п��ܶ��ֹͣ
	//ֹͣ��dll�����������
	//�����ղ����κ��¼�Ҳ���ܵ����κ�API
}






EVE_Exit_EX(Exit)
//name:�˳�����
//priority:30000
{
	logger.Info("Exit");
	//������ִ���Ժ�,��Q���ʱ���ڽ�������
}
