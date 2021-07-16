MauvilleCity_House1_MapScripts:: @ 820F975
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude:: @ 820F976
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM06, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM35
	setflag FLAG_RECEIVED_HM06
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash:: @ 820F9A5
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis: @ 820F9AF
	.string "Hey there, {PLAYER}.\p"
	.string "Huh? You don't remember me? I'm one of\n"
	.string "Prof. Sakura's assistants!\p"
	.string "I live here, in Iridium Bluffs.\p"
	.string "Since you took the time to visit me, I\n"
	.string "have a little something for you.$"

MauvilleCity_House1_Text_ExplainRockSmash: @ 820FAA9
	.string "That TM there contains Flamethrower.\p"
	.string "It's a super hot move that makes your\n"
	.string "foes super hot, too!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock: @ 820FB67
	.string "I work from home a lot doing research\n"
	.string "for Prof. Sakura.\p"
	.string "Well, that's what I tell her, anyway.\n"
	.string "This is the life!$"
