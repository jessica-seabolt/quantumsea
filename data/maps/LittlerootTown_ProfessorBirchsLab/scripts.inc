.set LOCALID_AIDE, 1
.set LOCALID_BIRCH, 2
.set LOCALID_RIVAL, 3
.set LOCALID_BALL_CYNDAQUIL, 4
.set LOCALID_BALL_TOTODILE, 5
.set LOCALID_BALL_CHIKORITA, 6

LittlerootTown_ProfessorBirchsLab_MapScripts:: @ 81F9C91
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	.byte 0

	@ State descriptions for VAR_DEX_UPGRADE_JOHTO_STARTER_STATE
	@ 1: Beat Elite Four, Dex upgrade ready
	@ 2: Received National Dex
	@ 3: Left lab after receiving National Dex
	@ 4: Entered lab after catching all Hoenn mons
	@ 5: Birch told player to choose Johto starter
	@ 6: Chose Johto starter

	@ State descriptions for VAR_BIRCH_LAB_STATE
	@ 1: Never occurs
	@ 2: Chose starter
	@ 3: Received starter in lab
	@ 4: Defeated rival on Route 103
	@ 5: Received pokedex

LittlerootTown_ProfessorBirchsLab_OnTransition: @ 81F9CA1
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter:: @ 81F9CCD
	specialvar VAR_RESULT, HasAllHoennMons
	compare VAR_RESULT, TRUE
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter:: @ 81F9CE9
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout

LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout:: @ 81F9CF3
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout:: @ 81F9CF7
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_OnWarp: @ 81F9D06
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
	map_script_2 VAR_LITTLEROOT_TOWN_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter:: @ 81F9D40
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade:: @ 81F9D45
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	addobject LOCALID_BIRCH
	addobject LOCALID_RIVAL
	turnobject LOCALID_RIVAL, DIR_NORTH
	setobjectxy LOCALID_RIVAL, 5, 5
	turnobject LOCALID_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCH, 6, 4
	turnobject LOCALID_AIDE, DIR_EAST
	setobjectxy LOCALID_AIDE, 10, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject:: @ 81F9D71
	addobject LOCALID_RIVAL
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters:: @ 81F9D75
	addobject LOCALID_BALL_CYNDAQUIL
	addobject LOCALID_BALL_TOTODILE
	addobject LOCALID_BALL_CHIKORITA
	addobject LOCALID_RIVAL
	turnobject LOCALID_BALL_CYNDAQUIL, DIR_SOUTH
	setobjectxy LOCALID_BALL_CYNDAQUIL, 8, 4
	turnobject LOCALID_BALL_TOTODILE, DIR_SOUTH
	setobjectxy LOCALID_BALL_TOTODILE, 9, 4
	turnobject LOCALID_BALL_CHIKORITA, DIR_SOUTH
	setobjectxy LOCALID_BALL_CHIKORITA, 10, 4
	turnobject LOCALID_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCH, 6, 4
	turnobject LOCALID_RIVAL, DIR_EAST
	setobjectxy LOCALID_RIVAL, 5, 5
	end

LittlerootTown_ProfessorBirchsLab_OnFrame: @ 81F9DB9
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GoGetPokemonEvent
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_GoGetPokemonEvent::
	lockall
	addobject LOCALID_RIVAL
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_LEFT
	msgbox GiveYouAPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox PleaseGiveUsAPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCH, ThinkAboutPokemon
	waitmovement 0
	msgbox OfCourse, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	warp MAP_LITTLEROOT_TOWN, 255, 20, 26
	releaseall
	end

GiveYouAPokemon:
	.string "Sakura: Let me get this straight.\p"
	.string "You two recklessly entered an area with\n"
	.string "wild Pokémon... to ask me for a Pokémon?\p"
	.string "And then you still expect me to just\n"
	.string "hand {PLAYER} a Pokémon of their own?\p"
	.string "{PLAYER}, your mother told me not to\n"
	.string "give you one yet. I'm supposed to be in\l"
	.string "charge of you... I really ought to tell\l"
	.string "your mom about this incident.$"

ThinkAboutPokemon:
	jump_in_place_down
	jump_in_place_down
	step_end

OfCourse:
	.string "Sakura: I like you, {RIVAL}! You're funny!\p"
	.string "Sakura: {PLAYER}, I was just teasing you.\n"
	.string "Of course I'll give you a Pokémon!\p"
	.string "Just don't tell your mom on me, either!\n"
	.string "Deal?\p"
	.string "Well? Come on then, you two! Let's see\n"
	.string "what Pokémon {PLAYER} wants to pick!$"

PleaseGiveUsAPokemon:
	.string "{RIVAL}: I'm sorry Prof. Sakura, it was\n"
	.string "me who convinced {PLAYER} to go in there.\p"
	.string "I understand if you don't want to give\n"
	.string "{PLAYER} a Pokémon, but don't tell their\l"
	.string "mom about something I made them do!$"


@ The starter is technically given prior to this on Route 101 by special ChooseStarter
@ This is just where the game tells you its yours and lets you nickname it
LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent:: @ 81F9DDB
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestLeft
	bufferleadmonspeciesname 0
	message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_DEFAULT
	closemessage
	msgbox LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter:: @ 81F9E07
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival:: @ 81F9E17
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_DEFAULT
	closemessage
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival:: @ 81F9E36
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_BIRCH_LAB_STATE, 3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival:: @ 81F9E48
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent:: @ 81F9E67
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
	waitmovement 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex: @ 81F9E78
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex:: @ 81F9E80
	lockall
	delay 30
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
	waitmovement 0
	delay 20
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
	playse SE_PC_ON
	waitse
	delay 20
	applymovement LOCALID_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment:: @ 81F9F32
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment:: @ 81F9F3C
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes: @ 81F9F46
	walk_left
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_right
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex: @ 81F9F58
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_fastest_down
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter:: @ 81F9F62
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter: @ 81F9F7C
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide:: @ 81F9F84
	lock
	faceplayer
	compare VAR_BIRCH_LAB_STATE, 3
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
	setflag FLAG_BIRCH_AIDE_MET
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide2:: @ 81F9F84
	lock
	faceplayer
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork2, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet:: @ 81F9FA7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter:: @ 81F9FB1
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil:: @ 81F9FBB
	release
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	showmonpic SPECIES_CYNDAQUIL, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Totodile:: @ 81F9FEF
	release
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	showmonpic SPECIES_TOTODILE, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita:: @ 81FA023
	release
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	showmonpic SPECIES_CHIKORITA, 10, 3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter:: @ 81FA057
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime:: @ 81FA061
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil:: @ 81FA06C
	bufferspeciesname 0, SPECIES_CYNDAQUIL
	setvar VAR_TEMP_1, SPECIES_CYNDAQUIL
	givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty:: @ 81FA0A1
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CYNDAQUIL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC:: @ 81FA0CC
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CYNDAQUIL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC:: @ 81FA0F2
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil:: @ 81FA0FD
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile:: @ 81FA10D
	bufferspeciesname 0, SPECIES_TOTODILE
	setvar VAR_TEMP_1, SPECIES_TOTODILE
	givemon SPECIES_TOTODILE, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty:: @ 81FA142
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_TOTODILE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC:: @ 81FA16D
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_TOTODILE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC:: @ 81FA193
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile:: @ 81FA19E
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita:: @ 81FA1AE
	bufferspeciesname 0, SPECIES_CHIKORITA
	setvar VAR_TEMP_1, SPECIES_CHIKORITA
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty:: @ 81FA1E3
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CHIKORITA
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC:: @ 81FA20E
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BALL_CHIKORITA
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC:: @ 81FA234
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita:: @ 81FA23F
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter:: @ 81FA24F
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
	waitmessage
	waitfanfare
	return

LittlerootTown_ProfessorBirchsLab_EventScript_Birch:: @ 81FA25A
	lock
	faceplayer
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon:: @ 81FA28A
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting:: @ 81FA294
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister:: @ 81FA29E
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 3
	goto_if_eq ProfBirch_EventScript_RatePokedexOrRegister
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge ProfBirch_EventScript_RatePokedexOrRegister
	compare VAR_BIRCH_LAB_STATE, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
	release
	end

EventScript_RegisterProfBirch:: @ 81FA2D2
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex:: @ 81FA2F8
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
	closemessage
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_MEGA_BRACELET, 1
	compare VAR_RESULT, FALSE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
	msgbox MegaBracelet, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_QUEST_MENU_GET
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_1
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_1
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Quest1Name, MSGBOX_SIGN
	waitfanfare
	applymovement LOCALID_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, LeaveLabRival
	waitmovement 0
	playse SE_EXIT
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	removeobject LOCALID_RIVAL
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	setvar VAR_LITTLEROOT_INTRO_STATE, 8
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	releaseall
	end

LeaveLabRival:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MegaBracelet:
	.string "Sakura: It's called a Mega Bracelet.\p"
	.string "It unlocks the power of Mega Evolution\n"
	.string "with your Pokémon to unleash its full\l"
	.string "potential in battle!\p"
	.string "If that isn't enough for you, I have a\n"
	.string "friend who likes to hang out in\l"
	.string "Springrock Path.\p"
	.string "He's a great cook! He might have a\n"
	.string "little something for your journey, too!\p"
	.string "I almost feel like there's a name for\n"
	.string "optional things like these... maybe it's\l"
	.string "called a {COLOR GREEN}Side Quest?{COLOR DARK_GREY}\p"
	.string "You should be able to check that in a\n"
	.string "Menu somehow...\p"
	.string "Maybe with the Start button?\p"
	.string "Sakura: Oh, look at me ramble again!\p"
	.string "{RIVAL}, {PLAYER}! Get going! Go out and\n"
	.string "be the best Trainers Rika has ever seen!$"

LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls:: @ 81FA352
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	compare VAR_RESULT, FALSE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls:: @ 81FA37F
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	compare VAR_RESULT, FALSE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex:: @ 81FA3AC
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait:: @ 81FA3C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls:: @ 81FA3CE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls:: @ 81FA3D7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer: @ 81FA3E0
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Machine:: @ 81FA3E3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Rival:: @ 81FA3EC
	lock
	faceplayer
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext:: @ 81FA428
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext:: @ 81FA431
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans:: @ 81FA43A
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere:: @ 81FA453
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly: @ 81FA45C
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier:: @ 81FA465
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier:: @ 81FA47E
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier:: @ 81FA487
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork:: @ 81FA490
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork:: @ 81FA4A9
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork:: @ 81FA4B2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PC:: @ 81FA4BB
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf:: @ 81FA4C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Book:: @ 81FA4CD
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall:: @ 81FA4D6
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
	waitmessage
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork: @ 81FA4E2
	.string "Hunh? PROF. BIRCH?\p"
	.string "The PROF's away on fieldwork.\n"
	.string "Ergo, he isn't here.\p"
	.string "Oh, let me explain what fieldwork is.\p"
	.string "It is to study things in the natural\n"
	.string "environment, like fields and mountains,\l"
	.string "instead of a laboratory.\p"
	.string "The PROF isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork2: @ 81FA4E2
	.string "Pokémon are usually linked to their\n"
	.string "original Poké Ball when they're caught.\p"
	.string "Prof. Sakura, being the genius that she\n"
	.string "is, invented a machine to allow any\l"
	.string "Pokémon to switch its Poké Ball.\p"
	.string "Unfortunately, the technology was\n"
	.string "stolen from our Lab up in Glacial Dunes\l"
	.string "just last week.\p"
	.string "I wonder what they wanted with it?$"

LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork: @ 81FA641
	.string "Sakura? She's a brilliant woman.\p"
	.string "She may seem a little bit childish, but\n"
	.string "her work may save Rika's future one day.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo: @ 81FA6CE
	.string "Prof. Sakura and I wish you the best of\n"
	.string "luck, {PLAYER}! I hear that {RIVAL} is\l"
	.string "already catching a lot of Pokémon!$"

LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon: @ 81FA74D
	.string "Sakura: {PLAYER}, I have no doubt in my\n"
	.string "you can do great things.\p"
	.string "And so, it gives me great pleasure to\n"
	.string "officially call you a Pokémon Trainer!$"

LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon: @ 81FA8B1
	.string "Sakura: What an incredible battle!\n"
	.string "Bravo, both of you!$"

LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival: @ 81FA8F6
	.string "Sakura: You can also rename it anytime in\n"
	.string "your Party Menu. Cool?\p"
	.string "Now, listen, both of you. It's time I\n"
	.string "get some help around here. I have four\l"
	.string "Labs all across Rika, and yet we still\l"
	.string "struggle to get data on every Pokémon\l"
	.string "that lives here.\p"
	.string "So, I'd like to give you the Pokédex.$"

LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou: @ 81FA9D5
	.string "PROF. BIRCH: Great!\n"
	.string "{RIVAL} should be happy, too.\p"
	.string "Get {RIVAL} to teach you what it\n"
	.string "means to be a TRAINER.$"

LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay: @ 81FAA35
	.string "PROF. BIRCH: Oh, don't be that way.\n"
	.string "You should go meet my kid.$"

LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome: @ 81FAA74
	.string "Sakura: {RIVAL}?\n"
	.string "Gone home, I think.\p"
	.string "Or maybe that kid's scrabbling around\n"
	.string "in tall grass again somewhere…\p"
	.string "If you or your Pokémon get tired,\n"
	.string "you should get some rest at home.$"

LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex: @ 81FAB22
	.string "Sakura: The Pokédex is a super fancy\n"
	.string "book made of electricity!\p"
	.string "...No? No laughs?\p"
	.string "...Really? Tough crowd...\p"
	.string "It records data on Pokémon that you\n"
	.string "find in the wild and sends it to me!\p"
	.string "In other words... I want you to catch\n"
	.string "every Pokémon and record their data!\p"
	.string "And {PLAYER}, don't think about saying\n"
	.string "no to me- I'll tell your mom about what\l"
	.string "you did today!$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex: @ 81FAC32
	.string "{PLAYER} received the Pokédex!$"

LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex: @ 81FAC4B
	.string "Sakura: In addition to that, I bet you\n"
	.string "both really want to get out and battle!\p"
	.string "Luckily for you, the Rika League has\n"
	.string "just started. You'll have to defeat the\l"
	.string "eight Gym Leaders and collect Badges.\p"
	.string "Once you have all eight, you can battle\n"
	.string "the Champion for their title!\p"
	.string "The whole thing is a mystery for now.\n"
	.string "Not a word has been announced about\l"
	.string "who the Champion could be.\p"
	.string "Because Trainers are so tough in Rika, I\n"
	.string "think it might...\p"
	.string "Sakura: {PLAYER}, is that my Z-Ring?!\p"
	.string "Hahaha! I was going to give it to you\n"
	.string "right now, but it looks like you\l"
	.string "already took it! That's okay, though. I\l"
	.string "have another gift that might help you\l"
	.string "out as well!$"

LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait: @ 81FAD6F
	.string "Sakura: Go on, {PLAYER}!\n"
	.string "Show the world what you can do!$"

LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese: @ 81FADD7
	.string "MAY: Oh, wow, {PLAYER}{KUN}!\n"
	.string "You got a POKéDEX, too!\p"
	.string "That's great! Just like me!\n"
	.string "I've got something for you, too!$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls: @ 81FAE40
	.string "MAY: It's fun if you can get a lot of\n"
	.string "POKéMON!\p"
	.string "I'm going to look all over the place\n"
	.string "because I want different POKéMON.\p"
	.string "If I find any cute POKéMON, I'll catch\n"
	.string "them with POKé BALLS!$"

LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull: @ 81FAEF3
	.string "Oh? Your Bag's full.$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext: @ 81FAF08
	.string "MAY: I wonder where I should go look\n"
	.string "for POKéMON next?$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese: @ 81FAF3F
	.string "{RIVAL}: Aw, yeah! A Z-Ring and a Mega\n"
	.string "Bracelet, too! {PLAYER}, are you ready?\p"
	.string "I'm going to the Gym in Darkwing Grove!\n"
	.string "I bet I'll beat it right quick!\p"
	.string "I challenge you to a race! Whoever beats\n"
	.string "the Gym last is a Slakoth! Hahaha!\p"
	.string "Good luck, {PLAYER}!$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls: @ 81FAF8E
	.string "BRENDAN: You know it's more fun to\n"
	.string "have a whole bunch of POKéMON.\p"
	.string "I'm going to explore all over the place\n"
	.string "to find different POKéMON.\p"
	.string "If I find any cool POKéMON, you bet\n"
	.string "I'll try to get them with POKé BALLS.$"

LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull: @ 81FB05D
	.string "Hey, your BAG's full.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext: @ 81FB073
	.string "BRENDAN: Where should I look for\n"
	.string "POKéMON next…$"

LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine: @ 81FB0A2
	.string "It's a serious-looking machine.\n"
	.string "Prof. Sakura must use this for research.$"

LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch: @ 81FB0E7
	.string "It's a PC used for research.\n"
	.string "Better not mess around with it.$"

LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon: @ 81FB124
	.string "It's a display case of some high-tech\n"
	.string "gadgets and gizmos.$"

LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead: @ 81FB148
	.string "It's a book that's too hard to read.$"

LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational: @ 81FB16D
	.string "PROF. BIRCH: Now…\p"
	.string "{PLAYER}{KUN} and {RIVAL}, I've had the two\n"
	.string "of you help me study POKéMON.\p"
	.string "Thanks to your help, new facts\n"
	.string "are coming to light.\p"
	.string "It appears that in the HOENN region,\n"
	.string "there are also POKéMON from other\l"
	.string "regions.\p"
	.string "It goes to show how rich and varied\n"
	.string "the natural environments of HOENN\l"
	.string "happen to be.\p"
	.string "That's why I think it's necessary for\n"
	.string "me to upgrade your POKéDEX to\l"
	.string "the NATIONAL Mode.\p"
	.string "Here, let me see your POKéDEX units.$"

LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool: @ 81FB30F
	.string "MAY: Eheheh!\p"
	.string "It's so cool that even my POKéDEX\n"
	.string "is getting updated!\p"
	.string "It's because you went out and caught\n"
	.string "so many POKéMON, {PLAYER}{KUN}!$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe: @ 81FB38E
	.string "BRENDAN: I went out all over HOENN\n"
	.string "and checked out POKéMON.\p"
	.string "You can thank me for getting\n"
	.string "the NATIONAL Mode POKéDEX.\p"
	.string "Yep, you're lucky, {PLAYER}!$"

LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone: @ 81FB419
	.string "PROF. BIRCH: Okay, all done!$"

LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational: @ 81FB436
	.string "{PLAYER}'s POKéDEX was upgraded\n"
	.string "to the NATIONAL Mode!$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2: @ 81FB466
	.string "PROF. BIRCH: But listen.\n"
	.string "You've become the CHAMPION,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"

LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork: @ 81FB528
	.string "MAY: I think I'll take a short break\n"
	.string "from fieldwork.\p"
	.string "I think I'll help the PROF here for\n"
	.string "a while.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork: @ 81FB58A
	.string "BRENDAN: For the time being,\n"
	.string "I'm taking a break from fieldwork.\p"
	.string "I'll be helping out the PROF here\n"
	.string "for a while.$"

LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon: @ 81FB5F9
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
	.string "Let's have a look at your POKéDEX.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Yes, there's no doubt about it.\p"
	.string "You really have completed the HOENN\n"
	.string "region's POKéDEX.\p"
	.string "That's more than just impressive.\p"
	.string "I have a gift for you.\p"
	.string "Consider it my show of appreciation\n"
	.string "for the fantastic work you've done.\p"
	.string "My gift is a rare POKéMON only found\n"
	.string "in another region!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon: @ 81FB787
	.string "PROF. BIRCH: These are rare POKéMON\n"
	.string "only found in another region!\p"
	.string "You can have any one of these\n"
	.string "three POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil: @ 81FB7F6
	.string "PROF. BIRCH: The FIRE POKéMON\n"
	.string "CYNDAQUIL caught your eye!\p"
	.string "You're as sharp as ever!\p"
	.string "So the CYNDAQUIL is your choice?$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile: @ 81FB869
	.string "PROF. BIRCH: The WATER POKéMON\n"
	.string "TOTODILE is your choice!\p"
	.string "You know how to pick a good one.\p"
	.string "So, you'll take the TOTODILE?$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita: @ 81FB8E0
	.string "PROF. BIRCH: The GRASS POKéMON\n"
	.string "CHIKORITA is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the CHIKORITA?$"

LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable: @ 81FB959
	.string "PROF. BIRCH: Take your time before\n"
	.string "you decide.\p"
	.string "They're all invaluable POKéMON.$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon: @ 81FB9A8
	.string "PROF. BIRCH: I see!\n"
	.string "You picked a fine POKéMON!$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter: @ 81FB9D7
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. BIRCH!$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter: @ 81FB9FC
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_1} you received?$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting: @ 81FBA2C
	.string "PROF. BIRCH: Listen, {PLAYER}{KUN}.\n"
	.string "You've completed the HOENN POKéDEX,\l"
	.string "but your POKéMON journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is POKéMON.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"

LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone: @ 81FBAF8
	.string "You received the promised POKéMON.\n"
	.string "Better leave the others alone.$"

@ Unused
LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon: @ 81FBB3A
	.string "Oh, you don't have any room for\n"
	.string "this POKéMON.$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere: @ 81FBB68
	.string "MAY: {PLAYER}{KUN}, after this…\n"
	.string "What are you going to do?\p"
	.string "Are you going to keep battling\n"
	.string "and sharpening your skills?\p"
	.string "Or are you going to try filling\n"
	.string "the NATIONAL POKéDEX?\p"
	.string "I'm staying here to help the PROF.$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly: @ 81FBC2D
	.string "BRENDAN: Rather than collecting\n"
	.string "POKéMON, I prefer slowly and \l"
	.string "steadily raising the one I chose.$"

LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier: @ 81FBC8D
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\n"
	.string "Have you gone to that place,\l"
	.string "the BATTLE FRONTIER?$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier: @ 81FBCD2
	.string "BRENDAN: Hey, {PLAYER}!\n"
	.string "Have you gone out to that place,\l"
	.string "the BATTLE FRONTIER?$"

LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall: @ 81FBD1A
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
	.string "It's me, SCOTT.\p"
	.string "I'm aboard the S.S. TIDAL now.\n"
	.string "It feels great to be on the sea!\p"
	.string "By the way…\p"
	.string "There's this place that I'd like to\n"
	.string "invite you to for a visit.\p"
	.string "If you're interested, board a ferry\n"
	.string "at either SLATEPORT or LILYCOVE.\p"
	.string "I'll fill you in on the details when\n"
	.string "we meet. I'll be waiting!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Quest1Name:
	.string "Quest Started!\n"
	.string "{COLOR GREEN}{STR_VAR_1}{COLOR DARK_GREY}$"
