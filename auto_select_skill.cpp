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


//Not Split Argumant Yoksa Ekleyin
//Server Src
//game
//utils.cpp
//Bul
#include "stdafx.h"

//Altına Ekle
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>


//Bul
const char *two_arguments(const char *argument, char *first_arg, size_t first_size, char *second_arg, size_t second_size)
{
	return (one_argument(one_argument(argument, first_arg, first_size), second_arg, second_size));
}

//Altına Ekle
void split_argument(const char *argument, std::vector<std::string> & vecArgs)
{
	std::string arg = argument;
	boost::split(vecArgs, arg, boost::is_any_of(" "), boost::token_compress_on);
}


//utils.h
//Bul
extern const char *	two_arguments(const char *argument, char *first_arg, size_t first_size, char *second_arg, size_t second_size);

//Altına Ekle
extern const char *	first_cmd(const char *argument, char *first_arg, size_t first_arg_size, size_t *first_arg_len_result);





//08.11.2023 GÜNCELLEME
//char.cpp
//Bul
	sync_time = 0;
	
	m_dwPacketAntiFloodCount = 0;
	m_dwPacketAntiFloodPulse = 0;

//Altına Ekle
#ifdef ENABLE_AUTO_SELECT_SKILL
	LastSkillReset = 0;
#endif


//char.h
//Bul
		float GetDamMul() { return this->m_fDamMul; }
		void SetDamMul(float newDamMul) {this->m_fDamMul = newDamMul; }

//Altına Ekle
#ifdef ENABLE_AUTO_SELECT_SKILL
	protected:
		int				LastSkillReset;
#endif


//char_item.cpp
//Bul
							case 71013: // 축제용폭죽
								CreateFly(number(FLY_FIREWORK1, FLY_FIREWORK6), this);
								item->SetCount(item->GetCount() - 1);
								break;

//Altına Ekle
#ifdef ENABLE_AUTO_SELECT_SKILL
							case 84001:
								if (get_global_time() < LastSkillReset + 40)
								{
									ChatPacket(CHAT_TYPE_INFO, LC_TEXT("You can use in %d seconds."), 40 - (get_global_time() - LastSkillReset));
									return false;
								}
								LastSkillReset = get_global_time();
								RemoveGoodAffect();
								ClearSkill();
								SetSkillGroup(0);
								if(GetSkillGroup() == 0 && GetLevel() >= 5)
									ChatPacket(CHAT_TYPE_COMMAND, "OpenAutoSkill");
								item->SetCount(item->GetCount() - 1);
								break;
#endif



//cmd_general.cpp
//Bul
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

//Değiştir
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
		ch->SetSkillLevel(130,30);
		ch->SetSkillLevel(131,50);
		ch->SetSkillLevel(137,50);
		ch->SetSkillLevel(138,50);
		ch->SetSkillLevel(139,50);
		if (ch->GetJob() == 0)
		{
			if(skillIndex == 1)
			{
				ch->SetSkillLevel(1,50);
				ch->SetSkillLevel(2,50);
				ch->SetSkillLevel(3,50);
				ch->SetSkillLevel(4,50);
				ch->SetSkillLevel(5,50);
			}else
			{
				ch->SetSkillLevel(16,50);
				ch->SetSkillLevel(17,50);
				ch->SetSkillLevel(18,50);
				ch->SetSkillLevel(19,50);
				ch->SetSkillLevel(20,50);
			}
		}
		if (ch->GetJob() == 1)
		{
			if(skillIndex == 1)
			{
				ch->SetSkillLevel(31,50);
				ch->SetSkillLevel(32,50);
				ch->SetSkillLevel(33,50);
				ch->SetSkillLevel(34,50);
				ch->SetSkillLevel(35,50);
			}else
			{
				ch->SetSkillLevel(46,50);
				ch->SetSkillLevel(47,50);
				ch->SetSkillLevel(48,50);
				ch->SetSkillLevel(49,50);
				ch->SetSkillLevel(50,50);
			}
			ch->SetSkillLevel(140,20);
		}
		if (ch->GetJob() == 2)
		{
			if(skillIndex == 1)
			{
				ch->SetSkillLevel(61,50);
				ch->SetSkillLevel(62,50);
				ch->SetSkillLevel(63,50);
				ch->SetSkillLevel(64,50);
				ch->SetSkillLevel(65,50);
				ch->SetSkillLevel(66,50);
			}else
			{
				ch->SetSkillLevel(76,50);
				ch->SetSkillLevel(77,50);
				ch->SetSkillLevel(78,50);
				ch->SetSkillLevel(79,50);
				ch->SetSkillLevel(80,50);
				ch->SetSkillLevel(81,50);
			}
		}
		if (ch->GetJob() == 3)
		{
			if(skillIndex == 1)
			{
				ch->SetSkillLevel(91,50);
				ch->SetSkillLevel(92,50);
				ch->SetSkillLevel(93,50);
				ch->SetSkillLevel(94,50);
				ch->SetSkillLevel(95,50);
				ch->SetSkillLevel(96,50);
			}else
			{
				ch->SetSkillLevel(106,50);
				ch->SetSkillLevel(107,50);
				ch->SetSkillLevel(108,50);
				ch->SetSkillLevel(109,50);
				ch->SetSkillLevel(110,50);
				ch->SetSkillLevel(111,50);
			}
		}
		ch->SkillLevelPacket();
	}
}
#endif




//PROTO
84001	Beceri Sıfırlama Nesnesi
84001	???????	ITEM_USE	USE_SPECIAL	1	ANTI_DROP | ANTI_GIVE | ANTI_MYSHOP | ANTI_SAFEBOX | ANTI_STACK	LOG	NONE	NONE	0	0	0	0	0	LIMIT_NONE	0	LIMIT_NONE	0	APPLY_NONE	0	APPLY_NONE	0	APPLY_NONE	0	0	0	0	0	0	0	0	0	0



//Locale_xx//item_lis.txt
84001	ETC	icon/item/71173.tga	