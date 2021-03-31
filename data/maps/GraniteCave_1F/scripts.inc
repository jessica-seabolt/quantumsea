.set LOCALID_RIVAL, 1
.set LOCALID_CUBONE1, 4
.set LOCALID_CUBONE2, 3

GraniteCave_1F_MapScripts:: @ 8210E5B
	map_script MAP_SCRIPT_ON_TRANSITION, GraniteCave_1F_OnTransition
	.byte 0

GraniteCave_1F_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

GraniteCave_1F_EventScript_RivalAtTunnel::
	lockall
	addobject LOCALID_RIVAL
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0	
	applymovement LOCALID_RIVAL, GraniteCave_1F_Movement_RivalGoesToPlayer
	waitmovement 0
	msgbox GraniteCave_1F_Text_SakurasLab, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, GraniteCave_1F_Movement_GoToCuboneRival
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_1F_Movement_GoToCubonePlayer
	waitmovement 0
	playse SE_PIN
	playbgm MUS_HELP, 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement LOCALID_CUBONE1, GraniteCave_1F_Movement_Cubone1Approach
	applymovement LOCALID_CUBONE2, GraniteCave_1F_Movement_Cubone2Approach
	waitmovement 0
	playmoncry SPECIES_CUBONE, 0
	msgbox GraniteCave_1F_Text_CuboneGrowl, MSGBOX_DEFAULT
	closemessage
	msgbox GraniteCave_1F_Text_Run, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, GraniteCave_1F_Movement_RunFromCuboneRival
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_1F_Movement_RunFromCubonePlayer
	applymovement LOCALID_CUBONE1, GraniteCave_1F_Movement_ChasePlayer1
	applymovement LOCALID_CUBONE2, GraniteCave_1F_Movement_ChasePlayer2
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	fadedefaultbgm
	msgbox GraniteCave_1F_Text_PhewThatWasClose, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_RIVAL_SPRINGROCK_PATH
	setflag FLAG_UNKNOWN_0x363
	setflag FLAG_UNKNOWN_0x393
	clearflag FLAG_HIDE_HIKER_SPRINGROCK_PATH
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_WILD_ENCOUNTERS
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
	waitstate
	playse SE_EXIT
	removeobject LOCALID_CUBONE1
	removeobject LOCALID_CUBONE2
	removeobject LOCALID_RIVAL
	release
	end



GraniteCave_1F_Movement_RivalGoesToPlayer:
	walk_down
	walk_down
	step_end

GraniteCave_1F_Text_SakurasLab:
	.string "{RIVAL}: Okay, {PLAYER}! Just follow me\n"
	.string "and we'll make it to her Lab in no time!\p"
	.string "Well? Come on, then!$"

GraniteCave_1F_Movement_GoToCuboneRival:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GraniteCave_1F_Movement_GoToCubonePlayer:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

GraniteCave_1F_Movement_Cubone1Approach:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

GraniteCave_1F_Movement_Cubone2Approach:
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

GraniteCave_1F_Text_CuboneGrowl:
	.string "Cubone: Grraaawrr!$"

GraniteCave_1F_Text_Run:
	.string "{RIVAL}: Um, {PLAYER}, I can't battle\n"
	.string "two Pokémon at one time! We should...\p"
	.string "RUN!!!$"

GraniteCave_1F_Movement_RunFromCuboneRival:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_left
	step_end

GraniteCave_1F_Movement_RunFromCubonePlayer:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_right
	step_end

GraniteCave_1F_Movement_ChasePlayer1:
	jump_in_place_up
	jump_in_place_left
	jump_in_place_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

GraniteCave_1F_Movement_ChasePlayer2:
	jump_in_place_up
	jump_in_place_left
	jump_in_place_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

GraniteCave_1F_Text_PhewThatWasClose:
	.string "{RIVAL}: Phew, that was too close! Good\n"
	.string "thing those Cubone were so slow!\p"
	.string "Sorry I got us into this mess, {PLAYER}.\n"
	.string "I was so sure my Pokémon could handle\l"
	.string "it that I dragged you into danger.\p"
	.string "Well, the exit's right over there...\p"
	.string "Let's just go through, before more scary\n"
	.string "Pokémon show up to chase us!$"

GraniteCave_1F_Movement_LeaveCaveRival:
	walk_down
	walk_down
	walk_down
	step_end

GraniteCave_1F_Movement_LeaveCavePlayer:
	walk_right
	walk_down
	walk_down
	step_end

GraniteCave_1F_EventScript_Hiker:: @ 822DA5E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM05, GraniteCave_1F_EventScript_ReceivedLeftovers
	questmenu QUEST_MENU_GET_ACTIVE_QUEST 0
	compare VAR_RESULT, SIDE_QUEST_1
	goto_if_ne YouNeedToActivateMyQuest
	msgbox QuestActiveHiker, MSGBOX_DEFAULT
	closemessage
	goto BattleHiker
	release
	end

QuestActiveHiker:
	.string "Hoho! Prof. Sakura sent you, did she?\n"
	.string "Well then! Let's see if you've got what\l"
	.string "it takes to earn my respect!$"

BattleHiker::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Hiker_Text_Defeated
	goto GraniteCave_1F_EventScript_AfterBattleHiker
	end

Hiker_Text_Defeated:
	.string "Hoho! Respect earned, kid!$"

GraniteCave_1F_EventScript_AfterBattleHiker::
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_LEFTOVERS
	setflag FLAG_RECEIVED_HM05
	msgbox GraniteCave_1F_Text_ExplainLeftovers, MSGBOX_DEFAULT
	closemessage
	questmenu QUEST_MENU_COMPLETE_QUEST SIDE_QUEST_1
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_1
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Quest1Completed, MSGBOX_SIGN
	waitfanfare
	release
	end

YouNeedToActivateMyQuest::
	msgbox SetMyQuest, MSGBOX_DEFAULT
	closemessage
	release
	end

SetMyQuest:
	.string "Hoho there, little one! I'd love to take\n"
	.string "you on in a battle, but, you see...\p"
	.string "I only battle Trainers who have a really\n"
	.string "{COLOR GREEN}Active{COLOR DARK_GREY} lifestyle!\p"
	.string "Looks to me like you're pretty {COLOR RED}Inactive{COLOR DARK_GREY}!$"


GraniteCave_1F_EventScript_ReceivedLeftovers:: @ 822DA8A
	msgbox GraniteCave_1F_Text_ExplainLeftovers, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo: @ 822DA94
	.string "Hey, kid! That was some nice battling!\p"
	.string "Listen, I made some delicious dinner last\n"
	.string "night and I LOVED it.\p"
	.string "Problem is, I made way too much! Would\n"
	.string "you mind taking these Leftovers for me?$"

GraniteCave_1F_Text_ExplainLeftovers: @ 822DBB7
	.string "Give those Leftovers to a Pokémon to\n"
	.string "hold! Might keep them going a little in\l"
	.string "battle if their belly is full! Oh ho ho!$"

Quest1Completed:
	.string "Quest completed:\n"
	.string "{COLOR GREEN}{STR_VAR_1}{COLOR DARK_GREY}!$"