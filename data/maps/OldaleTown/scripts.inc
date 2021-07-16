.set LOCALID_MART_EMPLOYEE, 2
.set LOCALID_FOOTPRINTS_MAN, 3
.set LOCALID_RIVAL, 4

OldaleTown_MapScripts:: @ 81E8EA2
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition: @ 81E8EA8
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
	call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	call_if_set FLAG_ROUTE_2_RAINING, Route2Raining
	call_if_set FLAG_ROUTE_4_SNOWING, Route4Snowing
	end

Route2Raining::
	setweather WEATHER_RAIN_THUNDERSTORM
	doweather
	end

@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
OldaleTown_EventScript_SetOldaleState:: @ 81E8ECC
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

OldaleTown_EventScript_BlockWestEntrance:: @ 81E8ED2
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
	return

OldaleTown_EventScript_MoveMartEmployee:: @ 81E8EDE
	setobjectxyperm LOCALID_MART_EMPLOYEE, 13, 14
	setobjectmovementtype LOCALID_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
	return

OldaleTown_EventScript_CitySign:: @ 81E8EEA
	msgbox OldaleTown_Text_CitySign, MSGBOX_SIGN
	end

TaprootTown_LeafStone::
	finditem ITEM_LEAF_STONE, 1
	end

TaprootTown_Azumarill::
	playmoncry SPECIES_AZUMARILL, 0
	msgbox Azumarill, MSGBOX_NPC
	waitmoncry
	end

Azumarill:
	.string "Azumarill: Zuzuriii!$"

OldaleTown_EventScript_Girl:: @ 81E8EF3
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

WannaKnowSecret::
	msgbox WannaKnowSecretText, MSGBOX_NPC
	end

OldaleTown_EventScript_MartEmployee:: @ 81E8EFC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
	setflag FLAG_TEMP_1
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartSouth:: @ 81E8F47
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartNorth:: @ 81E8F5E
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartEast:: @ 81E8F75
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
	applymovement LOCALID_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_ExplainPokemonMart:: @ 81E8F8C
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	compare VAR_RESULT, FALSE
	goto_if_eq OldaleTown_EventScript_BagIsFull
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	release
	end

OldaleTown_EventScript_ExplainPotion:: @ 81E8FB9
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_BagIsFull:: @ 81E8FC3
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

OldaleTown_Movement_EmployeeEast: @ 81E8FCE
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_EmployeeSouth: @ 81E8FD7
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_EmployeeNorth: @ 81E8FE2
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_Unknown1: @ 81E8FEB
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_PlayerEast: @ 81E8FF9
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerSouth: @ 81E9001
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerNorth: @ 81E900B
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_Unknown2: @ 81E9013
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_EventScript_FootprintsMan:: @ 81E901F
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_2
	compare VAR_RESULT, TRUE
	goto_if_ne GiveSideQuest2
	questmenu QUEST_MENU_CHECK_COMPLETE SIDE_QUEST_2
	compare VAR_RESULT, TRUE
	goto_if_eq NickitAlreadyShown
	questmenu QUEST_MENU_GET_ACTIVE_QUEST 0
	compare VAR_RESULT, SIDE_QUEST_2
	goto_if_eq NickitQuestIsActive
	msgbox NickitQuestIsNotActive, MSGBOX_SIGN
	release
	end

NickitQuestIsActive::
	msgbox CheckForNickitText, MSGBOX_DEFAULT
	closemessage
	special ChoosePartyMon
	waitstate
	compare VAR_RESULT, 255
	goto_if_eq NickitCheckFailed
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_NICKIT
	goto_if_eq NickitCheckPassed
	msgbox Text_NickitCheckFailed, MSGBOX_SIGN
	release
	end	

NickitQuestIsNotActive:
	.string "Huh? No, I don't quite remember you.\n"
	.string "My brain isn't very {COLOR GREEN}Active{COLOR DARK_GREY} right now...$"

NickitCheckFailed::
	msgbox Text_NickitCheckFailed, MSGBOX_SIGN
	release
	end

NickitAlreadyShown::
	msgbox ExplainExpShareText, MSGBOX_SIGN
	release
	end

NickitCheckPassed::
	msgbox YouHaveANickit, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM61, 1
	playfanfare MUS_REGISTER_MATCH_CALL
	questmenu QUEST_MENU_COMPLETE_QUEST SIDE_QUEST_2
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_2
	msgbox QuestCompleted, MSGBOX_SIGN
	waitfanfare
	release
	end

YouHaveANickit:
	.string "A Nickit! Oh my gosh! It's so adorable!\p"
	.string "Thank you so much! I promised I would\n"
	.string "give you an item and I meant it!\p"
	.string "This Exp. Share will allow your Pokémon\n"
	.string "to share their experience together!\p"
	.string "But, who even needs other Pokémon when\n"
	.string "you have a Nickit?$"

Text_TM61:
	.string "The Exp. Share will allow your Pokémon\n"
	.string "to share their experience together!\p"
	.string "But, who even needs other Pokémon when\n"
	.string "you have a Nickit?$"

CheckForNickitText:
	.string "So? Do you have an an adorable little\n"
	.string "Nickit to show me?$"

Text_NickitCheckFailed:
	.string "Aw, okay! Come back when you have a\n"
	.string "Nickit to show me, ok?\p"
	.string "I think you can find them hiding out\n"
	.string "in the West section of Springrock Path.$"


GiveSideQuest2::
	msgbox CatchANickitQuestText1, MSGBOX_DEFAULT
	closemessage
	showmonpic SPECIES_NICKIT, 10, 3
	msgbox CatchANickitQuestText2, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_2
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_2
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox QuestName, MSGBOX_SIGN
	waitfanfare
	release
	end

SonCheckIfActive::
	lockall
	faceplayer
	questmenu QUEST_MENU_GET_ACTIVE_QUEST 0
	compare VAR_RESULT, SIDE_QUEST_3
	goto_if_eq SonBattleForQuestTaproot
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_3
	compare VAR_RESULT, TRUE
	goto_if_eq ActivateQuest3Script
	releaseall
	end

SonBattleForQuestTaproot::
	trainerbattle_single TRAINER_MARCEL, TaprootTown_Text_WilliamIntro, TaprootTown_Text_WilliamDefeat, TaprootTownSetQuest3Objective
	releaseall
	end

TaprootTownSetQuest3Objective::
	setflag FLAG_DEFEATED_SON_TAPROOT
	msgbox TaprootTown_Text_WilliamPostBattle, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

ActivateQuest3Script::
	goto_if_set FLAG_DEFEATED_SON_TAPROOT, SonDefeatedTaproot
	msgbox ActivateQuest3, MSGBOX_NPC
	releaseall
	end

SonDefeatedTaproot::
	msgbox TaprootTown_Text_WilliamPostBattle, MSGBOX_NPC
	end

ActivateQuest3:
	.string "Huh? You think you can battle me?\p"
	.string "Ha! Your Pokémon don't look very {COLOR GREEN}Active{COLOR DARK_GREY}\n"
	.string "to me!$"

TaprootTown_Text_WilliamIntro:
	.string "So, another Trainer thinks they can take\n"
	.string "on my Pokémon team?\p"
	.string "I make them train all day and night! No\n"
	.string "Pokémon worth catching gets too tired\l"
	.string "to battle chumps like you!\p"
	.string "Huh? You think I'm treating my Pokémon\n"
	.string "like tools?\p"
	.string "I'm treating them like the fighters they\n"
	.string "are. It makes them stronger!\p"
	.string "Here, let me show you what they can do!$"

TaprootTown_Text_WilliamDefeat:
	.string "I understand now. I should give my\n"
	.string "Pokémon a rest and take care of them.$"

TaprootTown_Text_WilliamPostBattle:
	.string "Thank you for opening my eyes. I never\n"
	.string "realized how much my attitude towards\l"
	.string "Pokémon could affect their well-being.\p"
	.string "I promise to give them breaks and not\n"
	.string "push them so hard.$"

CatchANickitQuestText1::
	.string "Hi there! I really, really, REALLY love\n"
	.string "the Pokémon Nickit.$"

CatchANickitQuestText2::
	.string "If you can show me a Nickit, I've got a\n"
	.string "great item just for you!$"


OldaleTown_EventScript_BlockedPath:: @ 81E903F
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
	waitmovement 0
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
	waitmovement 0
	releaseall
	end

OldaleTown_EventScript_NotBlockingPath:: @ 81E9066
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_Rival:: @ 81E9070
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_0x8009, 0
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger0:: @ 81E9086
	lockall
	playbgm MUS_RG_ENCOUNTER_DEOXYS, 0
	goto_if_set FLAG_VISITED_OLDALE_TOWN, RivalFightQuick0
	setflag FLAG_VISITED_OLDALE_TOWN
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	addobject LOCALID_RIVAL
	msgbox OutOfTheWayTaproot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowMayMessage
	end

OldaleTown_EventScript_RivalTrigger1:: @ 81E9086
	lockall
	playbgm MUS_RG_ENCOUNTER_DEOXYS, 0
	goto_if_set FLAG_VISITED_OLDALE_TOWN, RivalFightQuick1
	setflag FLAG_VISITED_OLDALE_TOWN
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	addobject LOCALID_RIVAL
	msgbox OutOfTheWayTaproot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowMayMessage
	end

OldaleTown_EventScript_RivalTrigger2:: @ 81E90A6
	lockall
	playbgm MUS_RG_ENCOUNTER_DEOXYS, 0
	goto_if_set FLAG_VISITED_OLDALE_TOWN, RivalFightQuick2
	setflag FLAG_VISITED_OLDALE_TOWN
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	addobject LOCALID_RIVAL
	msgbox OutOfTheWayTaproot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowMayMessage
	end

OldaleTown_EventScript_RivalTrigger3:: @ 81E90C6
	lockall
	playbgm MUS_RG_ENCOUNTER_DEOXYS, 0
	goto_if_set FLAG_VISITED_OLDALE_TOWN, RivalFightQuick3
	setflag FLAG_VISITED_OLDALE_TOWN
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	addobject LOCALID_RIVAL
	msgbox OutOfTheWayTaproot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowMayMessage
	end

BackAgainTaproot:
	.string "Ravynn: Really, {PLAYER}?$"

RivalFightQuick0::
	addobject LOCALID_RIVAL
	msgbox BackAgainTaproot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto ShowRavynnQuick
	end

RivalFightQuick1::
	addobject LOCALID_RIVAL
	msgbox BackAgainTaproot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto ShowRavynnQuick
	end

RivalFightQuick2::
	addobject LOCALID_RIVAL
	msgbox BackAgainTaproot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	setvar VAR_0x8009, 1
	goto ShowRavynnQuick
	end

RivalFightQuick3::
	addobject LOCALID_RIVAL
	msgbox BackAgainTaproot, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	setvar VAR_0x8009, 1
	goto ShowRavynnQuick
	end

OutOfTheWayTaproot:
	.string "???: Out of the way.$"

OldaleTown_Movement_RivalApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_in_place_left
	step_end

OldaleTown_EventScript_ShowRivalMessage:: @ 81E90E6
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq OldaleTown_EventScript_ShowMayMessage
	compare VAR_RESULT, FEMALE
	goto_if_eq OldaleTown_EventScript_ShowBrendanMessage
	end

OldaleTown_EventScript_ShowMayMessage:: @ 81E90FE
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
	closemessage
	goto OldaleTown_EventScript_RivalFinish
	end

ShowRavynnQuick::
	msgbox RavynnLetsGetThisOverWith, MSGBOX_DEFAULT
	closemessage
	goto OldaleTown_EventScript_RivalFinish
	end

RavynnLetsGetThisOverWith:
	.string "Ravynn: You seriously want more? Even\n"
	.string "after that pitiful battle?\p"
	.string "Fine. I'll happily put you down again.\n"
	.string "Let's just get this over with.$"

OldaleTown_EventScript_ShowBrendanMessage:: @ 81E910C
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_RivalFinish:: @ 81E911A
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, TaprootTown_RavynnDefeatedText
	goto TaprootTown_EventScript_AfterRavynnBattle
	end

TaprootTown_RavynnDefeatedText:
	.string "Hmph. You're tougher than I thought.$"

TaprootTown_EventScript_AfterRavynnBattle:
	playbgm MUS_RG_ENCOUNTER_DEOXYS, 0
	msgbox ImSureWellMeetAgain, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, RavynnLeaves
	waitmovement 0
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_QUANTUM_QUEST_4
	clearflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	fadedefaultbgm
	releaseall
	end

RavynnLeaves:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

ImSureWellMeetAgain:
	.string "Ravynn: Interesting. I held back and\n"
	.string "you still struggled to defeat me.\p"
	.string "You're lucky my Shadow Pokémon haven't\n"
	.string "reached their full power yet, {PLAYER}.\p"
	.string "Still, you're stronger than I thought.\n"
	.string "I'll be watching your progress closely.\p"
	.string "I'm sure we'll meet again, in due time.$"

OldaleTown_EventScript_DoExitMovement1:: @ 81E9148
	compare VAR_FACING, DIR_SOUTH
	goto_if_ne OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_EventScript_DoExitMovement2:: @ 81E915E
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_WatchRivalExit
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_Movement_RivalApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_in_place_left
	step_end

OldaleTown_Movement_RivalApproachPlayer2: @ 81E9173
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_in_place_right
	step_end

OldaleTown_Movement_RivalApproachPlayer3: @ 81E9175
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_in_place_right
	step_end

OldaleTown_Movement_RivalExit: @ 81E9177
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Movement_WatchRivalExit: @ 81E917E
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_PlayerStepBack: @ 81E9182
	delay_8
	walk_right
	step_end

OldaleTown_Movement_BackUp: @ 81E9185
	walk_fast_up
	walk_in_place_fastest_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_ReturnToOriginalPosition: @ 81E918B
	walk_down
	walk_left
	step_end

OldaleTown_Text_SavingMyProgress: @ 81E918E
	.string "Taproot Town isn't the biggest place\n"
	.string "in Rika, but it's home to me.$"

WannaKnowSecretText: @ 81E918E
	.string "Hey, kid. Wanna know a secret?\p"
	.string "Sometimes you can find hidden items\n"
	.string "in nooks and crannies like this one.\p"
	.string "There might even be something down in\n"
	.string "that corner if you press the A Button.$"

OldaleTown_Text_IWorkAtPokemonMart: @ 81E91C0
	.string "Hi!\n"
	.string "I work at a POKéMON MART.\p"
	.string "Can I get you to come with me?$"

OldaleTown_Text_ThisIsAPokemonMart: @ 81E91FD
	.string "Hey, Trainer! Are you familiar with the\n"
	.string "Pokémon Market?\p"
	.string "It's a place where Trainers can purchase\n"
	.string "all of the essential goods they need.\p"
	.string "Here, let me give you a share of what I\n"
	.string "just picked up!$"

OldaleTown_Text_PotionExplanation: @ 81E92AF
	.string "A Premier Ball is a free Poké Ball that\n"
	.string "you can get if you purchase at least\l"
	.string "ten of any type of Poké Ball!\p"
	.string "Isn't that neat?$"

OldaleTown_Text_WaitDontComeInHere: @ 81E9313
	.string "This text is impossible to see.$"

OldaleTown_Text_DiscoveredFootprints: @ 81E939A
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_FinishedSketchingFootprints: @ 81E93F8
	.string "I finished sketching the footprints of\n"
	.string "a rare POKéMON.\p"
	.string "But it turns out they were only my\n"
	.string "own footprints…$"

OldaleTown_Text_MayLetsGoBack: @ 81E9462
	.string "???: Who are you?\p"
	.string "...{PLAYER}?\p"
	.string "{RIVAL} told me about you. They said you\n"
	.string "would teach me a lesson while their\l"
	.string "pathetic Pokémon collapsed from pain.\p"
	.string "Weaklings, all of you. And here I was\n"
	.string "thinking Rika's Trainers might offer me\l"
	.string "a slight challenge.\p"
	.string "My name is Ravynn. I'm going to defeat\n"
	.string "the Champion and become the strongest\l"
	.string "Pokémon Trainer who ever lived.\p"
	.string "Everyone will know my name.\p"
	.string "Ravynn: So, you really think you have a\n"
	.string "fighting chance against me?\p"
	.string "So be it.\p"
	.string "Don't be surprised if you need a trip to\n"
	.string "Lavender Town after I humiliate you.$"

OldaleTown_Text_BrendanLetsGoBack: @ 81E948A
	.string "BRENDAN: I'm heading back to my dad's\n"
	.string "LAB now.\l"
	.string "{PLAYER}, you should hustle back, too.$"

OldaleTown_Text_CitySign: @ 81E94DA
	.string "Taproot Town\n"
	.string "“The town of beautiful memories!”$"
