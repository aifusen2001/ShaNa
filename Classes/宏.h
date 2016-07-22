//
//#define LS_PRE(p) __ls_##p 
//
//#define LS_PROPERTY_RETAIN(varType, varName, funName)\ CC_SYNTHESIZE_RETAIN(varType, LS_PRE(varName), funName);
//#define LS_P_INIT(p) LS_PRE(p)(0) 
//#define LS_P_RELEASE(p) CC_SAFE_RELEASE_NULL(LS_PRE(p)) 
//
//#include"cocos2d.h"
//USING_NS_CC;
//
//class LUser : public cocos2d::CCObject{
//public:
//	CREATE_FUNC(LUser);
//	virtual bool init(){
//		return true;
//	};
//	LUser(){
//		Log("LUser()");
//	};
//	~LUser(){
//		Log("LUser().~():%s", m_sUserName.c_str());
//	};
//
//	std::string m_sUserName;        // �û��� 
//	std::string m_sPassword;        // �û����� 
//};
//
//class PropertyTest : public CCLayer{
//public:
//	CREATE_FUNC(PropertyTest);
//
//	virtual bool init(){
//		CCLog("PropertyTest().init()");
//		LUser* lu = LUser::create();
//		lu->m_sUserName = "leafsoar";
//		lu->m_sPassword = "123456";
//		setLUser(lu);
//
//		this->scheduleUpdate();
//
//		return true;
//	};
//
//	virtual void update(float fDelta){
//		if (updateCount < 5){
//			updateCount++;
//			CCLog("update index: %d", updateCount);
//			// �ڲ�ͬ��֡����ز������Ա�۲� 
//			if (updateCount == 1){
//				// ����ʹ�� getLUser ��ȡ���ݣ����� [__ls_]m_pLUser��������������ǰ׺ 
//				if (getLUser())
//					CCLog("log lu: %s", getLUser()->m_sUserName.c_str());
//
//			}
//			else if (updateCount == 2){
//				// ���¸�ֵ 
//				LUser* lu = LUser::create();
//				lu->m_sUserName = "һҶ";
//				setLUser(lu);
//			}
//			else if (updateCount == 3){
//				if (getLUser())
//					CCLog("log lu: %s", getLUser()->m_sUserName.c_str());
//			}
//			else if (updateCount == 4){
//				// ������� seLUser(0),ֱ��ȡ�����ó��ж������������Ҳû�й�ϵ 
//				// ��Ϊ�ڵ�ǰ��������ʱ����Զ�����ͷ� 
//				setLUser(0);
//			}
//			CCLog("update index: %d end", updateCount);
//		}
//	};
//
//	PropertyTest() :
//		LS_P_INIT(m_pLUser),
//		updateCount(0)
//	{
//	};
//
//	~PropertyTest(){
//		LS_P_RELEASE(m_pLUser);
//	};
//	LS_PROPERTY_RETAIN(LUser*, m_pLUser, LUser);
//
//private:
//	int updateCount;
//};