//Server Src
//common
//service.h
//Ekle
#define ENABLE_AUTO_SELECT_SKILL


//game
//char.cpp
//Bul
			if (amount)
			{
				quest::CQuestManager::instance().LevelUp(GetPlayerID());

//Altına Ekle
#ifdef ENABLE_AUTO_SELECT_SKILL
				if(GetSkillGroup() == 0 && GetLevel() >= 5)
					ChatPacket(CHAT_TYPE_COMMAND, "OpenAutoSkill");
#endif


//cmd.cpp
//Bul
struct command_info cmd_info[] =

//Üstüne ekle
#ifdef ENABLE_AUTO_SELECT_SKILL
ACMD(do_skillauto);
#endif


//Bul
	{ "\n",		NULL,			0,			POS_DEAD,	GM_IMPLEMENTOR	}

//Üstüne Ekle
#ifdef ENABLE_AUTO_SELECT_SKILL
	{ "skillauto",					do_skillauto,					0,			POS_DEAD,	GM_PLAYER		},
#endif



//cmd_general.cpp
//Sonuna Ekle
#ifdef ENABLE_AUTO_SELECT_SKILL
ACMD(do_skillauto)
{
	std::vector<std::string> vecArgs;
	split_argument(argument, vecArgs);
	if (vecArgs.size() < 2) { return; }
	else if (vecArgs[1] == "select")
	{
		if (vecArgs.size() < 3) { return; }
		if (ch->GetSkillGroup() != 0) { return; }
		BYTE skillIndex;
		str_to_number(skillIndex, vecArgs[2].c_str());
		if(skillIndex > 2) { return; }
		ch->RemoveGoodAffect();
		ch->SetSkillGroup(skillIndex);
		ch->ClearSkill();
		ch->SetSkillLevel(121,50);
		ch->SetSkillLevel(122,2);
		ch->SetSkillLevel(124,50);
		ch->SetSkillLevel(126,50);
		ch->SetSkillLevel(127,50);
		ch->SetSkillLevel(128,50);
		ch->SetSkillLevel(129,50);
		ch->SetSkillLevel(130,21);
		ch->SetSkillLevel(131,20);
		ch->SetSkillLevel(137,20);
		ch->SetSkillLevel(138,20);
		ch->SetSkillLevel(139,20);
		if (ch->GetJob() == 1) { ch->SetSkillLevel(140,20); }
		ch->SkillLevelPacket();
	}
}
#endif



//input_login.cpp
//Bul
	marriage::CManager::instance().Login(ch);

//Altına ekle
#ifdef ENABLE_AUTO_SELECT_SKILL
	if(ch->GetSkillGroup() == 0 && ch->GetLevel() >= 5)
		ch->ChatPacket(CHAT_TYPE_COMMAND, "OpenAutoSkill");
#endif


//questlua_pc.cpp
//Bul
			ch->SetSkillGroup((BYTE) rint(lua_tonumber(L, 1)));

//Altına Ekle
#ifdef ENABLE_AUTO_SELECT_SKILL
			if(ch->GetSkillGroup() == 0 && ch->GetLevel() >= 5)
				ch->ChatPacket(CHAT_TYPE_COMMAND, "OpenAutoSkill");
#endif



//Client Src
//UserInterFace
//Locale_inc.h
//Ekle
#define ENABLE_AUTO_SELECT_SKILL


//PythonApplicationModule.cpp
#ifdef ENABLE_AUTO_SELECT_SKILL
	PyModule_AddIntConstant(poModule, "ENABLE_AUTO_SELECT_SKILL", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_AUTO_SELECT_SKILL", 0);
#endif




//Binary
//root
//game.py
//Bul
			# PRIVATE_SHOP_PRICE_LIST
			"MyShopPriceList"		: self.__PrivateShop_PriceList,
			# END_OF_PRIVATE_SHOP_PRICE_LIST

			#####GIFT SYSTEM
			"gift_clear"	:self.gift_clear,
			"gift_item"		:self.gift_item,
			"gift_info"		:self.gift_show,
			"gift_load"		:self.gift_load,
			###
		}


//Altına Ekle
		if app.ENABLE_AUTO_SELECT_SKILL:
			serverCommandList.update({"OpenAutoSkill" : self.interface.OpenAutoSkillWindow})



//interfacemodule.py
//İmportların Altına Ekle
if app.ENABLE_AUTO_SELECT_SKILL:
	import uiAutoSkill


//Bul
		self.utilizareInventar = time.clock() + 2

//Üstüne Ekle
		if app.ENABLE_AUTO_SELECT_SKILL:
			self.wndAutoSkill = None


//Bul
		self.wndChatLog.Destroy()
		for btn in self.questButtonList:

//Üstüne Ekle
		if app.ENABLE_AUTO_SELECT_SKILL:
			if self.wndAutoSkill:
				self.wndAutoSkill.Hide()
				self.wndAutoSkill.Destroy()
				self.wndAutoSkill=None


//Bul
	def IsEditLineFocus(self):
		if self.ChatWindow.chatLine.IsFocus():
			return 1

		if self.ChatWindow.chatToLine.IsFocus():
			return 1

		return 0

	def EmptyFunction(self):
		pass

//Altına Ekle
	if app.ENABLE_AUTO_SELECT_SKILL:
		def MakeAutoSkillWindow(self):
			if self.wndAutoSkill == None:
				self.wndAutoSkill = uiAutoSkill.AutoSkillSelect()
		def OpenAutoSkillWindow(self):
			self.MakeAutoSkillWindow()
			self.wndAutoSkill.Show()


//Locale_xx
//locale_game.txt
//Ekle
AUTOSKILL_0_1	Vücut Gücünüzü Çalıştırın
AUTOSKILL_0_2	Vücut Dayanıklılığınızı Çalıştırın
AUTOSKILL_1_1	Öldürmek için hançerlerinizi bileyin
AUTOSKILL_1_2	Savaşmak için yayınızı kullanın
AUTOSKILL_2_1	Silahlarınızı büyüleyin
AUTOSKILL_2_2	Kara Büyü ile Oyna
AUTOSKILL_3_1	Yardım etmek için Gücü kullanın
AUTOSKILL_3_2	İyileştirmek için ışığı kullanın

//Root İçine At
uiautoskill.py

//Etc İçine At
//\etc\ymir work\ui\game
autoskill


İyi Eğlenceler.
Nyami
