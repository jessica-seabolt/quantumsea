OldaleTown_House1_MapScripts:: @ 81FBE85
	.byte 0

OldaleTown_House1_EventScript_Woman:: @ 81FBE86
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_3
	compare VAR_RESULT, TRUE
	goto_if_ne GiveSideQuest3
	goto_if_set FLAG_DEFEATED_SON_TAPROOT, CompleteQuest3
	questmenu QUEST_MENU_CHECK_COMPLETE SIDE_QUEST_3
	goto_if_eq SideQuest3Completed
	msgbox PleaseDefeatMySon, MSGBOX_NPC
	release
	end

SideQuest3Completed::
	msgbox Text_TM61, MSGBOX_NPC
	release
	end

GiveSideQuest3::
	msgbox DefeatMySon, MSGBOX_DEFAULT
	closemessage
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_3
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_3
	clearflag FLAG_HIDE_SIDE_QUEST_3_SON
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox QuestName, MSGBOX_SIGN
	waitfanfare
	release
	end

CompleteQuest3::
	msgbox YouDefeatedMySon, MSGBOX_SIGN
	giveitem ITEM_TM61, 1
	msgbox Text_TM61, MSGBOX_SIGN
	playfanfare MUS_REGISTER_MATCH_CALL
	questmenu QUEST_MENU_COMPLETE_QUEST SIDE_QUEST_3
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_3
	msgbox QuestCompleted, MSGBOX_SIGN
	setflag FLAG_HIDE_SIDE_QUEST_3_SON
	waitfanfare
	release
	end

DefeatMySon:
	.string "You...\p"
	.string "Your Pokémon have formed a very strong\n"
	.string "bond with you. I can tell.\p"
	.string "My son William has gotten a bit out of\n"
	.string "hand lately with his battling.\p"
	.string "He wants to challenge Polter in Darkwing\n"
	.string "Grove, but he hasn't learned to treat\l"
	.string "his Pokémon with respect.\p"
	.string "He's never going to get anywhere this\n"
	.string "way, and his Pokémon will be unhappy.\p"
	.string "You know how to handle Pokémon well...\p"
	.string "Could you battle my William and teach\n"
	.string "him how to take care of his Pokémon?\p"
	.string "I think he could lean a lot more about\n"
	.string "battles if someone skilled in raising\l"
	.string "Pokémon could defeat him. Please?$"

YouDefeatedMySon:
	.string "Oh? You did it? Thank you so much!\p"
	.string "I know William will be down about his\n"
	.string "loss, but I think it will help him grow.\p"
	.string "Please, accept this as my thanks!$"

Text_TM61:
	.string "TM61 contains Will-O-Wisp. It can burn\n"
	.string "opposing Pokémon in battle.\p"
	.string "Use it wisely!"

PleaseDefeatMySon:
	.string "Please defeat my son, William. He needs\n"
	.string "you to teach him how to train Pokémon.$"
