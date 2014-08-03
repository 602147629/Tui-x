#ifndef __ALERT_HEADER__
#define __ALERT_HEADER__

#include <typedef.hpp>
#include <cocos-base.h>
#include <cocos-widget.h>
#include <TextButton.hpp>

CLIENT_NS_BEGIN

USING_NS_CC;

typedef void (CCObject::*SEL_ALERT_SELECTOR)();

#define alert_selector(_SELECTOR) (SEL_ALERT_SELECTOR)(&_SELECTOR)

class Alert :
	public CSceneExtension
{
	SINGLETON_INSTANCE(Alert)
public:
	~Alert();

	CREATE_SCENE_FUNC(Alert)

	// �������˵��
	// @param szContent			��������
	// @param bCancel			�Ƿ���ʾ�رհ�ť
	// @param bHide				�Ƿ���ȷ����رս���
	// @param pObject			�¼�����Ŀ��ָ��
	// @param confirmHandler		ȷ���ص�����
	// @param cancelHandler		ȡ���ص�����

	void show(const char* szContent, bool bCancel = false, bool bHide = true, CCObject* pObject = nullptr, SEL_ALERT_SELECTOR confirmHandler = nullptr, SEL_ALERT_SELECTOR cancelHandler = nullptr);
private:
	Alert();

	void initialize(const char* szContent, bool bCancel = false, bool bHide = true, CCNode* pObject = nullptr, SEL_ALERT_SELECTOR confirmHandler = nullptr, SEL_ALERT_SELECTOR cancelHandler = nullptr);

	void hide();
	
	void confirmBtnClickHandler(CCObject *pSender);

	void cancelBtnClickHandler(CCObject *pSender);
private:
	CC_SYNTHESIZE_READONLY(CCSprite*,					m_pBg,				Bg)

	CC_SYNTHESIZE_READONLY(cocoswidget::CLabel*,		m_pLabel,			Label)

	CC_SYNTHESIZE_READONLY(cocoswidget::CScrollView*,	m_pScrollView,		ScrollView)

	CC_SYNTHESIZE_READONLY(TextButton*,				m_pConfirmBtn,		ConfirmBtn)

	CC_SYNTHESIZE_READONLY(TextButton*,				m_pCancelBtn,		CancelBtn)
	// ��ʼ�����
	CC_SYNTHESIZE_READONLY(bool,						m_bInitialize,		Initialize)
	// �رհ�ť���
	CC_SYNTHESIZE_READONLY(bool,						m_bCancel,			Cancel)
	// ���ر��
	CC_SYNTHESIZE_READONLY(bool,						m_bHide,				Hide)
	// �¼�Ŀ��
	CC_SYNTHESIZE_READONLY(CCObject*,					m_pEventTarget,		EventTarget)
	// ȷ����ť����ָ��
	CC_SYNTHESIZE_READONLY(SEL_ALERT_SELECTOR,		m_xConfirmHandler,	ConfirmHandler)
	// ȡ����ť����ָ��
	CC_SYNTHESIZE_READONLY(SEL_ALERT_SELECTOR,		m_xCancelHandler,	CancelHandler)

	CC_SYNTHESIZE_READONLY(CSceneExtension*,			m_pRunningScene,		RunningScene)
};

#define g_alert Alert::getInstance()

APP_NS_END

#endif//__ALERT_HEADER__
