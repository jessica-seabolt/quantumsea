.set LOCALID_CIPHER, 1

RustboroCity_Flat2_3F_MapScripts:: @ 8216116
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee:: @ 8216117
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, CipherPeonInHouseDefeatedText, CipherPeonInHouseDefeated
	end

CipherPeonInHouseDefeated::
	lockall
	msgbox CipherInHouseFineYouWin, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_CIPHER_IRIDIUM_BLUFF
	removeobject LOCALID_CIPHER
	fadescreen FADE_FROM_BLACK
	waitse
	releaseall
	end

RustboroCity_Flat2_3F_EventScript_Woman:: @ 8216120
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones: @ 8216129
	.string "What? You shouldn't be here!\n"
	.string "And now, I can't let you leave!$"

CipherPeonInHouseDefeatedText:
	.string "No! They're going to fire me!$"

CipherInHouseFineYouWin:
	.string "Fine! You win!\p"
	.string "But I'll never tell you what\n"
	.string "I was here for! Hahahahaha!$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones: @ 8216159
	.string "I don't know why that Cipher Peon was\n"
	.string "here, but I'm thankful that you came\l"
	.string "to rescue me.$"
