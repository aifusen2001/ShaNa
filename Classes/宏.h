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
//	std::string m_sUserName;        // 用户名 
//	std::string m_sPassword;        // 用户密码 
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
//			// 在不同的帧做相关操作，以便观察 
//			if (updateCount == 1){
//				// 这里使用 getLUser 获取数据，而非 [__ls_]m_pLUser，所以我设置了前缀 
//				if (getLUser())
//					CCLog("log lu: %s", getLUser()->m_sUserName.c_str());
//
//			}
//			else if (updateCount == 2){
//				// 重新赋值 
//				LUser* lu = LUser::create();
//				lu->m_sUserName = "一叶";
//				setLUser(lu);
//			}
//			else if (updateCount == 3){
//				if (getLUser())
//					CCLog("log lu: %s", getLUser()->m_sUserName.c_str());
//			}
//			else if (updateCount == 4){
//				// 这里调用 seLUser(0),直接取消引用持有对象，如果不调用也没有关系 
//				// 因为在当前类析构的时候会自动检测释放 
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