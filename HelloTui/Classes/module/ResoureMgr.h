#ifndef __RESOURE_MGR__
#define __RESOURE_MGR__

#include "../../CocosBase/cocos-base.h"
#include "tui/TuiMacros.h"
#include "cocos2d.h"
USING_NS_CC;

//��Դ����
class ResoureMgr : public Ref
{
public:
	SINGLE_INSTANCE_FUNC(ResoureMgr);
	virtual bool init();
	//ע�᳡��(�ͶԻ���)
	void registScene();

protected:
private:
};


#endif