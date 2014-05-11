#include "ResoureMgr.h"

#include "scene/Welcome/Welcomeui.h"
#include "scene/Main/Mainui.h"
#include "scene/Main/dialog/MessageBox.h"
#include "scene/Store/Storeui.h"

bool ResoureMgr::init(){
	return true;
}

void ResoureMgr::registScene(){

	REGISTER_SCENE_FUNC(Welcome::Welcomeui);				//��ӭҳ

	REGISTER_SCENE_FUNC(Main::Mainui);						//������
	REGISTER_SCENE_FUNC(Main::MessageBox);					//��Ϣ��

	REGISTER_SCENE_FUNC(Store::Storeui);					//�̵�
}