.set LOCALID_LITTLE_BOY, 7
.set LOCALID_LITTLE_GIRL, 8
.set LOCALID_DEVON_EMPLOYEE, 9
.set LOCALID_GRUNT, 10
.set LOCALID_RIVAL, 13
.set LOCALID_SCIENTIST, 15
.set LOCALID_QUANTUM, 19

RustboroCity_MapScripts:: @ 81E06BD
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_OnFrame
	.byte 0

RustboroCity_OnTransition: @ 81E06C8
	setflag FLAG_VISITED_RUSTBORO_CITY
	clearflag FLAG_ROUTE_2_RAINING
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	call Common_EventScript_SetupRivalGfxId
	call_if_set FLAG_BADGE01_GET, MoveDevonGuySpectre
	end

MoveDevonGuySpectre::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 24, 12
	return

RustboroCity_EventScript_PositionScientistForExit:: @ 81E06EC
	compare VAR_TEMP_0, 11
	goto_if_eq RustboroCity_EventScript_PositionScientistLeftExit
	setobjectxyperm LOCALID_SCIENTIST, 12, 15
	end

RustboroCity_EventScript_PositionScientistLeftExit:: @ 81E06FF
	setobjectxyperm LOCALID_SCIENTIST, 11, 15
	end

RustboroCity_EventScript_HideMapNamePopup:: @ 81E0707
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

RustboroCity_OnFrame: @ 81E070B
	map_script_2 VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_EventScript_ScientistAddMatchCall
	.2byte 0

RustboroCity_EventScript_ScientistAddMatchCall:: @ 81E0715
	lockall
	setvar VAR_ROUTE104_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_Movement_PlayerWalkDown
	waitmovement 0
	playse SE_EXIT
	delay 10
	addobject LOCALID_SCIENTIST
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistApproachPlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistWalkInPlaceDown
	waitmovement 0
	msgbox RustboroCity_Text_DevelopedNewPokenavFeature, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HAS_MATCH_CALL
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 10
	playse SE_CLICK
	delay 20
	applymovement LOCALID_SCIENTIST, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox RustboroCity_Text_AddedMatchCallPleaseCallMrStone, MSGBOX_DEFAULT
	closemessage
	delay 20
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_PleaseSelectPokenav:: @ 81E07AC
	msgbox RustboroCity_Text_PleaseSelectPokenav, MSGBOX_DEFAULT
	closemessage
	delay 10
	goto RustboroCity_EventScript_MatchCallTutorial

RustboroCity_EventScript_MatchCallTutorial:: @ 81E07BD
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	special ScriptMenu_CreateStartMenuForPokenavTutorial
	waitstate
	switch VAR_RESULT
	case 0, RustboroCity_EventScript_PleaseSelectPokenav
	case 1, RustboroCity_EventScript_PleaseSelectPokenav
	case 2, RustboroCity_EventScript_PleaseSelectPokenav
	case 4, RustboroCity_EventScript_PleaseSelectPokenav
	case 5, RustboroCity_EventScript_PleaseSelectPokenav
	case 6, RustboroCity_EventScript_PleaseSelectPokenav
	case 7, RustboroCity_EventScript_PleaseSelectPokenav
	case MULTI_B_PRESSED, RustboroCity_EventScript_PleaseSelectPokenav
	special OpenPokenavForTutorial
	waitstate
	delay 20
	msgbox RustboroCity_Text_IdBetterGetBackToWork, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCIENTIST, RustboroCity_Movement_ScientistLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_SCIENTIST
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	setvar VAR_RUSTBORO_CITY_STATE, 7
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end

RustboroCity_Movement_ScientistWalkInPlaceDown: @ 81E084E
	walk_in_place_down
	step_end

RustboroCity_Movement_PlayerWalkDown: @ 81E0850
	walk_down
	step_end

RustboroCity_Movement_ScientistApproachPlayer: @ 81E0852
	walk_down
	delay_16
	step_end

@ Unused
RustboroCity_Movement_ScientistWalkAroundPlayer: @ 81E0855
	delay_16
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_fastest_up
	delay_16
	step_end

RustboroCity_Movement_ScientistLeave: @ 81E085D
	walk_up
	step_end

RustboroCity_EventScript_FatMan:: @ 81E085F
	lock
	faceplayer
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_FatManSawGrunt
	msgbox RustboroCity_Text_WeShortenItToDevon, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_FatManSawGrunt:: @ 81E0874
	msgbox RustboroCity_Text_SneakyLookingManWentAroundCorner, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_DevonEmployee2:: @ 81E087E
	lock
	faceplayer
	msgbox RustboroCity_Text_YoureNewAroundHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Woman:: @ 81E088A
	msgbox RustboroCity_Text_GymLeaderIsntEasyWithFire, MSGBOX_NPC
	end

RustboroCity_EventScript_Man1:: @ 81E0893
	lock
	faceplayer
	goto_if_set FLAG_OBTAINED_ZORUA, ZoruaAlreadyObtained
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_Man1HaveBadge
	msgbox RustboroCity_Text_HaveYouChallengedGym, MSGBOX_DEFAULT
	release
	end

ZoruaAlreadyObtained::
	msgbox ZoruaAlreadyObtainedText, MSGBOX_DEFAULT
	closemessage
	release
	end

ZoruaAlreadyObtainedText:
	.string "Please take good care of my Zorua! I\n"
	.string "promise it'll be a valuable fighter!$"

RustboroCity_EventScript_Man1HaveBadge:: @ 81E08A8
	msgbox RustboroCity_Text_HeyThatsRustborosGymBadge, MSGBOX_DEFAULT
	closemessage
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq Script_PlayerHasFullPartyZorua
	givemon SPECIES_ZORUA, 5, ITEM_LIFE_ORB
	playfanfare MUS_OBTAIN_ITEM
	msgbox Text_ReceivedZorua, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_OBTAINED_ZORUA
	release
	end

Script_PlayerHasFullPartyZorua::
	msgbox Text_PlayerHasFullPartyZorua, MSGBOX_DEFAULT
	release
	end

Text_PlayerHasFullPartyZorua:
	.string "Huh? Oh, your party is full. Come back\n"
	.string "when you have room, okay?$"

Text_ReceivedZorua:
	.string "{PLAYER} received a Zorua!$"

RustboroCity_EventScript_Boy2:: @ 81E08B2
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_6
	compare VAR_RESULT, TRUE
	goto_if_ne GiveSideQuest6
	questmenu QUEST_MENU_CHECK_COMPLETE SIDE_QUEST_6
	compare VAR_RESULT, TRUE
	goto_if_eq MimikyuAlreadyShown
	questmenu QUEST_MENU_GET_ACTIVE_QUEST 0
	compare VAR_RESULT, SIDE_QUEST_6
	goto_if_eq MimikyuQuestIsActive
	msgbox MimikyuQuestIsNotActive, MSGBOX_SIGN
	release
	end

MimikyuQuestIsActive::
	msgbox CheckForMimikyuText, MSGBOX_DEFAULT
	closemessage
	special ChoosePartyMon
	waitstate
	compare VAR_RESULT, 255
	goto_if_eq MimikyuCheckFailed
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_MIMIKYU
	goto_if_eq MimikyuCheckPassed
	msgbox Text_MimikyuCheckFailed, MSGBOX_SIGN
	release
	end	

MimikyuQuestIsNotActive:
	.string "Huh? No, I don't quite remember you.\n"
	.string "My brain isn't very {COLOR GREEN}Active{COLOR DARK_GREY} right now...$"

MimikyuCheckFailed::
	msgbox Text_MimikyuCheckFailed, MSGBOX_SIGN
	release
	end

MimikyuAlreadyShown::
	msgbox ExplainMimikiumZText, MSGBOX_SIGN
	release
	end

MimikyuCheckPassed::
	msgbox YouHaveAMimikyu, MSGBOX_SIGN
	giveitem ITEM_MIMIKIUM_Z, 1
	playfanfare MUS_REGISTER_MATCH_CALL
	questmenu QUEST_MENU_COMPLETE_QUEST SIDE_QUEST_6
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_6
	msgbox QuestCompleted, MSGBOX_SIGN
	waitfanfare
	release
	end

YouHaveAMimikyu:
	.string "Woah! I can't believe it! You actually\n"
	.string "found one?!\p"
	.string "Okay, fair's fair. Here's what I agreed\n"
	.string "to give you!$"

ExplainMimikiumZText:
	.string "The Mimikium Z is a special crystal that\n"
	.string "can unlock some awesome damage!\p"
	.string "You'll need a Mimikyu for it, of course.\n"
	.string "And a Z-Ring, too!$"

CheckForMimikyuText:
	.string "Hey, did you find that Mimikyu yet?$"

Text_MimikyuCheckFailed:
	.string "No Mimikyu? Darn, oh well... come\n"
	.string "back when you find one, okay?$"


GiveSideQuest6::
	msgbox CatchAMimikyuQuestText1, MSGBOX_DEFAULT
	closemessage
	showmonpic SPECIES_MIMIKYU, 10, 3
	msgbox CatchAMimikyuQuestText2, MSGBOX_DEFAULT
	closemessage
	hidemonpic
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_6
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_6
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox QuestName, MSGBOX_SIGN
	waitfanfare
	release
	end

CatchAMimikyuQuestText1::
	.string "Hey, can I ask you something?\p"
	.string "Have you ever heard of a Mimikyu? It's a\n"
	.string "super rare Ghost Pokémon, and I really\l"
	.string "want to see one."

CatchAMimikyuQuestText2::
	.string "If you can show me a Mimikyu, I can give\n"
	.string "you my lucky crystal!$"

RustboroCity_EventScript_Boy2BrineyLeftTunnel:: @ 81E08C7
	msgbox RustboroCity_Text_MrBrineyLovesPeeko, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_Twin:: @ 81E08D1
	msgbox RustboroCity_Text_WowYouHavePokemon, MSGBOX_NPC
	end

RustboroCity_EventScript_NinjaBoy:: @ 81E08DA
	msgbox RustboroCity_Text_CatchRarePokemonIfIGoToSchool, MSGBOX_SIGN
	end

RustboroCity_EventScript_TunnelSign:: @ 81E08E3
	msgbox RustboroCity_Text_TunnelNearingCompletion, MSGBOX_SIGN
	end

RustboroCity_EventScript_DevonCorpSign:: @ 81E08EC
	msgbox RustboroCity_Text_DevonCorpSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_GymSign:: @ 81E08F5
	msgbox RustboroCity_Text_GymSign, MSGBOX_SIGN
	end

@ Unused
RustboroCity_EventScript_DevonCorpBranchOfficeSign:: @ 81E08FE
	msgbox RustboroCity_Text_DevonCorpBranchOfficeSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CitySign:: @ 81E0907
	msgbox RustboroCity_Text_CitySign, MSGBOX_SIGN
	end

RustboroCity_EventScript_TrainersSchoolSign:: @ 81E0910
	msgbox RustboroCity_Text_TrainersSchoolSign, MSGBOX_SIGN
	end

RustboroCity_EventScript_CuttersHouseSign:: @ 81E0919
	msgbox RustboroCity_Text_CuttersHouse, MSGBOX_SIGN
	end

RustboroCity_EventScript_LittleBoy:: @ 81E0922
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonCanChangeLookFromExp, MSGBOX_DEFAULT
	applymovement LOCALID_LITTLE_BOY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_LittleGirl:: @ 81E0938
	lock
	faceplayer
	msgbox RustboroCity_Text_PokemonChangeShape, MSGBOX_DEFAULT
	applymovement LOCALID_LITTLE_GIRL, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_EventScript_Man2:: @ 81E094E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, OldrodReceivedSpectre
	msgbox RustboroCity_Text_TradePokemonGrowFast, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_OLD_ROD, 1
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox OldRodReceivedText, MSGBOX_DEFAULT
	closemessage
	release
	end

OldrodReceivedSpectre::
	msgbox OldRodReceivedText, MSGBOX_DEFAULT
	closemessage
	release
	end

OldRodReceivedText:
	.string "That Old Rod will come in handy near any\n"
	.string "bodies of water you might find!$"

RivalSpectreCityTrigger0::
	lockall
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	addobject LOCALID_RIVAL
	playse SE_EXIT
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	playbgm MUS_ENCOUNTER_BRENDAN, 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RivalSpectreCityBattle, MSGBOX_DEFAULT
	closemessage
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq RivalBattleSpectreCityMale
	checkplayergender
	compare VAR_RESULT, FEMALE
	call_if_eq RivalBattleSpectreCityFemale
	playbgm MUS_ENCOUNTER_BRENDAN, 0
	msgbox RivalSpectreCityDefeated, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, RivalSpectreCityLeaves0
	waitmovement 0
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_RUSTBORO_CITY_STATE, 1
	fadedefaultbgm
	releaseall
	end

RivalSpectreCityTrigger1::
	lockall
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	addobject LOCALID_RIVAL
	playse SE_EXIT
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	playbgm MUS_ENCOUNTER_BRENDAN, 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RivalSpectreCityBattle, MSGBOX_DEFAULT
	closemessage
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq RivalBattleSpectreCityMale
	checkplayergender
	compare VAR_RESULT, FEMALE
	call_if_eq RivalBattleSpectreCityFemale
	playbgm MUS_ENCOUNTER_BRENDAN, 0
	msgbox RivalSpectreCityDefeated, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, RivalSpectreCityLeaves1
	waitmovement 0
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_RUSTBORO_CITY_STATE, 1
	fadedefaultbgm
	releaseall
	end

RivalBattleSpectreCityMale::
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, SpectreCity_Text_Defeated
	return

RivalBattleSpectreCityFemale::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, SpectreCity_Text_Defeated
	return

SpectreCity_Text_Defeated:
	.string "{RIVAL}: Wicked! What a battle!$"

RivalSpectreCityDefeated:
	.string "{RIVAL}: You've gotten really tough!\n"
	.string "You and your Pokémon have bonded a lot.\p"
	.string "But you know what? You still lost our\n"
	.string "race! That makes you the Slakoth!\p"
	.string "It was great cathing up mate, but I've\n"
	.string "gotta get moving to the next Gym!\p"
	.string "...Oh, yeah! I almost forgot!\p"
	.string "I met this jerk earlier, Ravynn I think.\n"
	.string "Rumor has it he's a Pokémon thief. If\l"
	.string "you see him, make sure you teach him a\l"
	.string "lesson for me, yeah?\p"
	.string "Alright, {PLAYER}! I'm off. Good luck\n"
	.string "with your Gym battle!$"

RivalSpectreCityLeaves0:
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

RivalSpectreCityLeaves1:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

RivalSpectreCityBattle:
	.string "{RIVAL}: Hey, {PLAYER}! What luck!\p"
	.string "I was hoping I'd run into you soon.\n"
	.string "I fought Polter a little while ago.\p"
	.string "I had to come back because I left my\n"
	.string "Pokédex in there...\p"
	.string "But that's besides the point! He's not a\n"
	.string "joke, {PLAYER}! That guy can battle!\p"
	.string "Are you on your way in there to take\n"
	.string "a shot at it?\p"
	.string "Wicked! Let's see if you're ready. No\n"
	.string "backing out, {PLAYER}. Here I come!$"

RustboroCity_EventScript_StolenGoodsTrigger0:: @ 81E095A
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 0
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger1:: @ 81E0971
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 1
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger2:: @ 81E0988
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 2
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger3:: @ 81E099F
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 3
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsTrigger4:: @ 81E09B6
	lockall
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 14, 21
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_RIGHT
	setvar VAR_0x8004, 4
	goto RustboroCity_EventScript_StolenGoodsScene
	end

RustboroCity_EventScript_StolenGoodsScene:: @ 81E09CD
	msgbox RustboroCity_Text_OutOfTheWay, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, 0
	addobject LOCALID_GRUNT
	addobject LOCALID_DEVON_EMPLOYEE
	applymovement LOCALID_GRUNT, RustboroCity_Movement_GruntEscape
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt1
	waitmovement 0
	msgbox RustboroCity_Text_WaitDontTakeMyGoods, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeChaseGrunt2
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_DEVON_EMPLOYEE
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 30, 10
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_DEVON_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 2
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
	setvar VAR_ROUTE116_STATE, 1
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	releaseall
	end

@ Unused
RustboroCity_EventScript_ShadyCharacterTookOff:: @ 81E0A3B
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	return

@ Unused
RustboroCity_EventScript_YouGotItThankYou:: @ 81E0A44
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	return

@ Unknown, unused employee movements. Based on the differences in movement theyre for approaching an object (probably the player) in different positions
RustboroCity_EventScript_EmployeeApproachUp:: @ 81E0A4D
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachUp
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachLeft:: @ 81E0A58
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachLeft
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachRight:: @ 81E0A63
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachRight
	waitmovement 0
	return

@ Unused, see above
RustboroCity_EventScript_EmployeeApproachDown:: @ 81E0A6E
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachDown
	waitmovement 0
	return

@ Unused, similar movement to the above scripts
RustboroCity_EventScript_EmployeeApproachPlayerFar:: @ 81E0A79
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerFar
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

@ Unused
RustboroCity_Movement_GruntEscapeExtended: @ 81E0A8E
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_GruntEscape: @ 81E0AA0
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt1: @ 81E0AB1
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

RustboroCity_Movement_EmployeeChaseGrunt2: @ 81E0AB9
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachUp: @ 81E0AC1
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachLeft: @ 81E0AC5
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachRight: @ 81E0ACA
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachDown: @ 81E0ACF
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

@ Functionally unused
RustboroCity_Movement_EmployeeApproachPlayerFar: @ 81E0AD5
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

RustboroCity_EventScript_DevonEmployee1:: @ 81E0ADD
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_ReturnGoodsSpokeToEmployee
	msgbox RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel, MSGBOX_DEFAULT
	release
	end

RustboroCity_EventScript_ReturnGoodsSpokeToEmployee:: @ 81E0AF2
	waitse
	setvar VAR_TEMP_1, 4
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger0:: @ 81E0AFE
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger1:: @ 81E0B0A
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger2:: @ 81E0B16
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_HelpGetGoodsTrigger3:: @ 81E0B22
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_EmployeeAskToGetGoods
	end

RustboroCity_EventScript_EmployeeAskToGetGoods:: @ 81E0B2E
	compare VAR_TEMP_1, 0
	call_if_eq RustboroCity_EventScript_EmployeeFacePlayerUp1
	compare VAR_TEMP_1, 1
	call_if_eq RustboroCity_EventScript_EmployeeFacePlayerLeft1
	compare VAR_TEMP_1, 2
	call_if_eq RustboroCity_EventScript_EmployeeFacePlayerDown1
	compare VAR_TEMP_1, 3
	call_if_eq RustboroCity_EventScript_EmployeeApproachPlayerDown1
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setvar VAR_RUSTBORO_CITY_STATE, 3
	copyobjectxytoperm LOCALID_DEVON_EMPLOYEE
	msgbox RustboroCity_Text_HelpMeIWasRobbed, MSGBOX_DEFAULT
	releaseall
	end

@ The below movement scripts are either partially or fully duplicated by the movement scripts when the player returns the goods
RustboroCity_EventScript_EmployeeFacePlayerUp1:: @ 81E0B6F
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft1:: @ 81E0B9B
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerDown1:: @ 81E0BC7
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown1:: @ 81E0BF3
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

RustboroCity_Movement_EmployeeApproachPlayerDown: @ 81E0C29
	walk_down
	step_end

RustboroCity_EventScript_ReturnGoodsTrigger0:: @ 81E0C2B
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger1:: @ 81E0C37
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger2:: @ 81E0C43
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoodsTrigger3:: @ 81E0C4F
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_ReturnGoods
	end

RustboroCity_EventScript_ReturnGoods:: @ 81E0C5B
	msgbox RustboroCity_Text_YouGotItThankYou, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	compare VAR_RESULT, FALSE
	call_if_eq RustboroCity_EventScript_BagFull
	releaseall
	end

RustboroCity_EventScript_BagFull:: @ 81E0CD3
	msgbox RustboroCity_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_EmployeeFacePlayerUp2:: @ 81E0CDC
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerLeft2:: @ 81E0D08
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerDown2:: @ 81E0D34
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeApproachPlayerDown2:: @ 81E0D60
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_Movement_EmployeeApproachPlayerDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

RustboroCity_EventScript_EmployeeFacePlayerRight:: @ 81E0D96
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_Delay48
	waitmovement 0
	return

RustboroCity_EventScript_Rival:: @ 81E0DB8
	lockall
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_PlayRivalMusic:: @ 81E0DD1
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq RustboroCity_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	goto_if_eq RustboroCity_EventScript_PlayBrendanMusic
	return

RustboroCity_EventScript_PlayMayMusic:: @ 81E0DE9
	playbgm MUS_ENCOUNTER_MAY, 1
	return

RustboroCity_EventScript_PlayBrendanMusic:: @ 81E0DEE
	playbgm MUS_ENCOUNTER_BRENDAN, 1
	return

RustboroCity_EventScript_RivalTrigger0:: @ 81E0DF3
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger1:: @ 81E0E33
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger2:: @ 81E0E73
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger3:: @ 81E0EB3
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger4:: @ 81E0EF3
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer4
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger5:: @ 81E0F33
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer5
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger6:: @ 81E0F73
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer6
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalTrigger7:: @ 81E0FB3
	lockall
	call RustboroCity_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, RustboroCity_Movement_RivalApproachPlayer7
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto RustboroCity_EventScript_RivalEncounter

RustboroCity_EventScript_RivalEncounter:: @ 81E0FF3
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq RustboroCity_EventScript_MayEncounter
	compare VAR_RESULT, FEMALE
	goto_if_eq RustboroCity_EventScript_BrendanEncounter
	end

RustboroCity_EventScript_MayEncounter:: @ 81E100B
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_MayBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_MayAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_MayHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredMay, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_MayAskToBattle:: @ 81E1070
	setvar VAR_0x8008, 1
	msgbox RustboroCity_Text_MayWantToBattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_EventScript_BattleMay
	msgbox RustboroCity_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleMay:: @ 81E1092
	msgbox RustboroCity_Text_MayImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleMayTreecko
	case 1, RustboroCity_EventScript_BattleMayTorchic
	case 2, RustboroCity_EventScript_BattleMayMudkip
	end

RustboroCity_EventScript_MayBrineyHint:: @ 81E10C1
	msgbox RustboroCity_Text_MayMrBrineyHint, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_RestoreBgm:: @ 81E10D6
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

RustboroCity_EventScript_BattleMayTreecko:: @ 81E10DB
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TREECKO, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayTorchic:: @ 81E10EE
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_TORCHIC, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BattleMayMudkip:: @ 81E1101
	trainerbattle_no_intro TRAINER_MAY_RUSTBORO_MUDKIP, RustboroCity_Text_MayDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_MayBrineyHint
	end

RustboroCity_EventScript_BrendanEncounter:: @ 81E1114
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanBrineyHint
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_BrendanAskToBattle
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_BrendanHiLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Text_RegisteredBrendan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	msgbox RustboroCity_Text_BrendanPassedBrineyWantToBattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	call RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BrendanAskToBattle:: @ 81E1174
	msgbox RustboroCity_Text_BrendanWantToBattle, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_EventScript_BattleBrendan
	msgbox RustboroCity_Text_BrendanNoConfidenceInPokemon, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_BattleBrendan:: @ 81E1191
	msgbox RustboroCity_Text_BrendanIWontGoEasy, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_BattleBrendanTreecko
	case 1, RustboroCity_EventScript_BattleBrendanTorchic
	case 2, RustboroCity_EventScript_BattleBrendanMudkip
	end

RustboroCity_EventScript_BrendanBrineyHint:: @ 81E11C0
	msgbox RustboroCity_Text_BrendanMrBrineyHint, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq RustboroCity_EventScript_RestoreBgm
	releaseall
	end

RustboroCity_EventScript_BattleBrendanTreecko:: @ 81E11D5
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanTorchic:: @ 81E11E8
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_EventScript_BattleBrendanMudkip:: @ 81E11FB
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, RustboroCity_Text_BrendanDefeat
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_BrendanBrineyHint
	end

RustboroCity_Movement_RivalApproachPlayer0: @ 81E120E
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer1: @ 81E1215
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer2: @ 81E121B
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer3: @ 81E1220
	walk_down
	walk_left
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer4: @ 81E1224
	walk_down
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer5: @ 81E1227
	walk_down
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer6: @ 81E122B
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_Movement_RivalApproachPlayer7: @ 81E1230
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

QuantumQuest4Script::
	lockall
	faceplayer
	questmenu QUEST_MENU_GET_ACTIVE_QUEST 0
	compare VAR_RESULT, SIDE_QUEST_4
	goto_if_eq QuantumBattleForQuest4
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_4
	compare VAR_RESULT, TRUE
	goto_if_eq ActivateQuest4Script
	releaseall
	end

QuantumBattleForQuest4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, SpectreCity_Text_QuantumIntro, SpectreCity_Text_QuantumDefeat
	setflag FLAG_QUEST_4_QUANTUM_DEFEATED
	msgbox SpectreCity_Text_QuantumPostBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_QUANTUM
	playse SE_EXIT
	setflag FLAG_HIDE_QUANTUM_QUEST_4
	fadescreen FADE_FROM_BLACK
	release
	end

ActivateQuest4Script::
	goto_if_set FLAG_QUEST_4_QUANTUM_DEFEATED, QuantumDefeatedQuest4
	msgbox ActivateQuest4, MSGBOX_NPC
	releaseall
	end

QuantumDefeatedQuest4::
	msgbox SpectreCity_Text_QuantumPostBattle, MSGBOX_NPC
	end

ActivateQuest4:
	.string "Hm? What makes you think I'm an {COLOR GREEN}Active{COLOR DARK_GREY}\n"
	.string "member of Team Quantum, kid?$"

SpectreCity_Text_QuantumIntro:
	.string "What? That poor little girl wants her\n"
	.string "precious Escape Rope back?\p"
	.string "I suppose now is a great time to use it!\p"
	.string ". . . . . . . . . . . . . . . . . . . . .\p"
	.string "What?! It doesn't work here?! Gah, fine!\p"
	.string "You stupid little brat! If you want it\n"
	.string "so badly, just try and take it from me!$"

SpectreCity_Text_QuantumDefeat:
	.string "Beat by a punky little kid!$"

SpectreCity_Text_QuantumPostBattle:
	.string "Oh, whatever! This whole city was a big\n"
	.string "waste of time!\p"
	.string "They'll demote me when they find out I\n"
	.string "failed to find anything in the haunted\l"
	.string "Trainer's School...\p"
	.string "But they're going to fire me once they\n"
	.string "learn I lost a battle to some kid!\p"
	.string "You ruined everything! Gah! I'm out!$"

Quest4NPC:: @ 81E1236
	lock
	faceplayer
	questmenu QUEST_MENU_CHECK_COMPLETE, SIDE_QUEST_5
	compare VAR_RESULT, TRUE
	goto_if_eq Quest5Completed
	goto_if_set FLAG_QUEST_5_OBJECTIVE_COMPLETE, Quest5ObjectiveComplete
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_5
	compare VAR_RESULT, TRUE
	goto_if_eq Quest5AlreadyStarted
	goto_if_set FLAG_QUEST_4_QUANTUM_DEFEATED, Quest4ObjectiveComplete
	questmenu QUEST_MENU_CHECK_UNLOCKED SIDE_QUEST_4
	compare VAR_RESULT, TRUE
	goto_if_eq Quest4AlreadyStarted
	msgbox Quest4StartDialogue, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_REGISTER_MATCH_CALL
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_4
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_4
	clearflag FLAG_HIDE_QUANTUM_QUEST_4
	msgbox QuestName, MSGBOX_SIGN
	waitfanfare
	release
	end

Quest5Completed::
	msgbox ThanksForTheHelpQuest5, MSGBOX_DEFAULT
	closemessage
	release
	end

Quest4AlreadyStarted::
	msgbox Quest4AlreadyStartedDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

Quest5AlreadyStarted::
	msgbox Quest5AlreadyStartedDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

Quest4ObjectiveComplete::
	questmenu QUEST_MENU_GET_ACTIVE_QUEST 0
	compare VAR_RESULT, SIDE_QUEST_4
	goto_if_ne YouNeedToActivateSideQuest4
	msgbox Quest4ObjectiveCompleteDialogue, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_ESCAPE_ROPE, 1
	playfanfare MUS_REGISTER_MATCH_CALL
	questmenu QUEST_MENU_COMPLETE_QUEST SIDE_QUEST_4
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_4
	msgbox QuestCompleted, MSGBOX_SIGN
	waitfanfare
	msgbox Quest5StartDialogue, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_REGISTER_MATCH_CALL
	questmenu QUEST_MENU_UNLOCK_QUEST SIDE_QUEST_5
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_5
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	msgbox QuestName, MSGBOX_SIGN
	waitfanfare
	release
	end

Quest5ObjectiveComplete::
	questmenu QUEST_MENU_GET_ACTIVE_QUEST 0
	compare VAR_RESULT, SIDE_QUEST_5
	goto_if_ne YouNeedToActivateSideQuest5
	msgbox Quest5ObjectiveCompleteDialogue, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TOXIC_ORB, 1
	playfanfare MUS_REGISTER_MATCH_CALL
	questmenu QUEST_MENU_COMPLETE_QUEST SIDE_QUEST_5
	questmenu QUEST_MENU_BUFFER_QUEST_NAME SIDE_QUEST_5
	msgbox QuestCompleted, MSGBOX_SIGN
	waitfanfare
	closemessage
	release
	end


YouNeedToActivateSideQuest4::
	msgbox SideQuest4Inactive, MSGBOX_DEFAULT
	closemessage
	release
	end

YouNeedToActivateSideQuest5::
	msgbox SideQuest5Inactive, MSGBOX_DEFAULT
	closemessage
	release
	end

Quest5IsntStarted::
	msgbox Quest5IsntStartedText, MSGBOX_NPC
	end

ForestSign1::
	msgbox SpectreForestSign, MSGBOX_SIGN
	end

ForestSign2::
	msgbox SpectreWoodsSign, MSGBOX_SIGN
	end

SpectreForestSign:
	.string "Spectre Forest\p"
	.string "Route 4 {UP_ARROW}$"

SpectreWoodsSign:
	.string "Spectre Woods\p"
	.string "Route 9 {UP_ARROW}$"

Quest5IsntStartedText:
	.string "Hm? You want into the Trainer's School?\p"
	.string "I'm sorry to disappoint, but it's been\l"
	.string "closed indefinitely.\p"
	.string "It was already overrun by Ghost Pokémon\n"
	.string "before, and now Team Quantum has taken\l"
	.string "interest in the place too.\p"
	.string "It's simply too dangerous right now.$"

SideQuest4Inactive:
	.string "Oh, is the search for my Escape Rope\n"
	.string "still {COLOR GREEN}Active{COLOR DARK_GREY}, or have you given up?$"

SideQuest5Inactive:
	.string "Oh, have you checked out the Trainer's\n"
	.string "School? Or is the search still {COLOR GREEN}Active{COLOR DARK_GREY}?$"

Quest4StartDialogue:
	.string "Hi, um... can you help me?\p"
	.string "This mean scary woman came and took my\n"
	.string "Escape Rope. I think she was with that\n"
	.string "awful Team Quantum gang.\p"
	.string "I don't really use it, but it was a\n"
	.string "gift from my father. It means a lot to\l"
	.string "me... I would hate to lose it.\p"
	.string "Please, can you help me get it back?$"

Quest4AlreadyStartedDialogue:
	.string "Please, help me get my Escape Rope back\n"
	.string "from that Team Quantum lady!$"

Quest5AlreadyStartedDialogue:
	.string "Would you mind checking out the haunted\n"
	.string "Trainer's School for me?\p"
	.string "I would hate for Team Quantum to do some\n"
	.string "awful thing with the Ghost Pokémon.$"

Quest4ObjectiveCompleteDialogue:
	.string "You did it! You got my Escape Rope back!\p"
	.string "Oh, how can I ever repay you? I haven't\n"
	.string "got much money...\p"
	.string "I know! You can keep that Escape Rope\n"
	.string "you got back for me. I'll be happy\l"
	.string "knowing someone as kind as you is\l"
	.string "getting good use out of it.\p"
	.string "Please, I insist!$"

Quest5ObjectiveCompleteDialogue:
	.string "Oh, there was a Pokémon up there? Wow!\p"
	.string "I'm glad Team Quantum can't get their\n"
	.string "hands on it. I wonder what they might\l"
	.string "have wanted with it?$"

ThanksForTheHelpQuest5:
	.string "Thank you again for all of your help!\n"
	.string "Spectre City is safe thanks to you!$"

ExplainEscapeRope:
	.string "The Escape Rope can get you out of any\n"
	.string "tricky situations you might get into if\l"
	.string "you lose your way in places like caves\l"
	.string "and forests. Take good care of it!$"

Quest5StartDialogue:
	.string "The Escape Rope can get you out of any\n"
	.string "tricky situations you might get into if\l"
	.string "you lose your way in places like caves\l"
	.string "and forests.\p"
	.string "Huh? that Quantum lady said something\n"
	.string "about the Trainer's School?\p"
	.string "I hate to bother you, but would you\n"
	.string "mind looking into that? I don't think\l"
	.string "I'm equipped for it myself...$"

RustboroCity_Text_WeShortenItToDevon: @ 81E123F
	.string "Did you hear? The weather has been all\n"
	.string "over the place. It's not normal.\p"
	.string "They think it has to do with whatever\n"
	.string "that Team Quantum gang is up to.$"

RustboroCity_Text_SneakyLookingManWentAroundCorner: @ 81E12AC
	.string "Team Quantum? No, I don't know much.\n"
	.string "I know they're trouble, though.$"

RustboroCity_Text_HaveYouChallengedGym: @ 81E130D
	.string "Oh, are you here to get a Badge from\n"
	.string "Polter's Gym?\p"
	.string "Well, good luck! You're gonna need it!$"

RustboroCity_Text_HeyThatsRustborosGymBadge: @ 81E139E
	.string "Woah! You got the Umbra Badge? Like, the\n"
	.string "real thing? That's awesome!\p"
	.string "I guess you'll be heading out for your\n"
	.string "next Badge, then?\p"
	.string "Here, since you got that Badge, I think\n"
	.string "you're the perfect person for this.\p"
	.string "I can't raise it myself, so... please\n"
	.string "give this Zorua a good home!$"

RustboroCity_Text_YoureNewAroundHere: @ 81E1407
	.string "I haven't seen you around here before.\n"
	.string "Have you met Polter yet?$"

RustboroCity_Text_GymLeaderIsntEasyWithFire: @ 81E1480
	.string "I challenged Polter in his Gym just a\n"
	.string "short while ago.\p"
	.string "Man, who knew Ghosts were so powerful?$"

RustboroCity_Text_MrBrineyWalksInTheTunnel: @ 81E1520
	.string "The old sailor MR. BRINEY lives in\n"
	.string "a cottage by the sea.\p"
	.string "He goes for walks in the tunnel every\n"
	.string "so often.$"

RustboroCity_Text_MrBrineyLovesPeeko: @ 81E1589
	.string "The old sailor MR. BRINEY lives in\n"
	.string "a cottage by the sea.\p"
	.string "He said he was going shopping in\n"
	.string "SLATEPORT for his pet, PEEKO.\p"
	.string "That old sea dog, he must really love\n"
	.string "that PEEKO.$"

RustboroCity_Text_WowYouHavePokemon: @ 81E1633
	.string "Hiya! Are you looking for the Pokémon\n"
	.string "Gym? It's just up North from here!$"

RustboroCity_Text_CatchRarePokemonIfIGoToSchool: @ 81E1695
	.string "Heheh, yeah, I've been in the Trainer's\n"
	.string "School before! I snuck in through the\l"
	.string "front door when nobody was around!\p"
	.string "...No, you're right. I'm lying. There's\n"
	.string "no way I'm going in there!$"

RustboroCity_Text_PokemonCanChangeLookFromExp: @ 81E16F4
	.string "I'm the best Pokémon Trainer! Tell her\n"
	.string "it's me!$"

RustboroCity_Text_PokemonChangeShape: @ 81E174B
	.string "I'm a better Pokémon Trainer than he is!\n"
	.string "Can't you see?$"

RustboroCity_Text_TradePokemonGrowFast: @ 81E1789
	.string "Pokémon are great, am I right?\p"
	.string "...And fishing for Pokémon is also great!\n"
	.string "Am I right?\p"
	.string "You seem alright, pal! Here, take this!$"

RustboroCity_Text_OutOfTheWay: @ 81E17FE
	.string "Get out!\n"
	.string "Out of the way!$"

RustboroCity_Text_WaitDontTakeMyGoods: @ 81E1817
	.string "Wait! Pleeeaaase!\p"
	.string "Don't take my GOODS!$"

RustboroCity_Text_HelpMeIWasRobbed: @ 81E183E
	.string "Oh, it's you!\p"
	.string "You're that fantastic TRAINER who\n"
	.string "helped me in PETALBURG WOODS!\p"
	.string "Help me! I was robbed by TEAM AQUA!\n"
	.string "I have to get the DEVON GOODS back!\p"
	.string "If I don't…\n"
	.string "I'm going to be in serious trouble.$"

RustboroCity_Text_ShadyCharacterTookOffTowardsTunnel: @ 81E1904
	.string "Sorry, I can't let you through here. The\n"
	.string "police are investigating rumors of a\l"
	.string "thief who uses his bird Pokémon to make\l"
	.string "his victims surrender their belongings.$"

RustboroCity_Text_YouGotItThankYou: @ 81E194D
	.string "Oh, the investigation? It's all over.\n"
	.string "Here, you can have this for being so\l"
	.string "patient for us.$"

RustboroCity_Text_YoureLoadedWithItems: @ 81E19E5
	.string "You're loaded with items.\n"
	.string "I can't give you this Great Ball.$"

RustboroCity_Text_PleaseComeWithMe: @ 81E1A21
	.string "Excuse me, please!\n"
	.string "Please come with me!$"

RustboroCity_Text_MayHiLetsRegister: @ 81E1A49
	.string "MAY: Oh, hi, {PLAYER}{KUN}!\p"
	.string "You had a MATCH CALL feature put\n"
	.string "on your POKéNAV!\p"
	.string "Let's register each other so we can\n"
	.string "contact one another anytime!\p"
	.string "… … … … … …$"

RustboroCity_Text_RegisteredMay: @ 81E1ADB
	.string "Registered MAY\n"
	.string "in the POKéNAV.$"

RustboroCity_Text_MayPassedBrineyWantToBattle: @ 81E1AFA
	.string "MAY: Oh, by the way, I passed\n"
	.string "MR. BRINEY in PETALBURG WOODS.\p"
	.string "I guess he's on his way home to his\n"
	.string "cottage by the sea.\p"
	.string "How's your POKéDEX coming along,\n"
	.string "{PLAYER}{KUN}? Mine's looking pretty decent!\p"
	.string "So…\n"
	.string "How about a little battle?$"

RustboroCity_Text_MayOhHaventRaisedPokemonEnough: @ 81E1BD3
	.string "MAY: Oh, what's the matter?\p"
	.string "Haven't you caught or raised your\n"
	.string "POKéMON very much?\p"
	.string "That's not very good for a TRAINER!$"

RustboroCity_Text_MayWantToBattle: @ 81E1C48
	.string "MAY: So, what do you think?\n"
	.string "How about a little battle here?$"

RustboroCity_Text_MayImNotGoingToLose: @ 81E1C84
	.string "MAY: You just became a TRAINER,\n"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"

RustboroCity_Text_MayDefeat: @ 81E1CC1
	.string "Yikes!\n"
	.string "You're better than I expected!$"

RustboroCity_Text_MayMrBrineyHint: @ 81E1CE7
	.string "MAY: Oh, by the way, MR. BRINEY, who\n"
	.string "I just passed…\p"
	.string "{PLAYER}{KUN}, you just moved here so you\n"
	.string "might not know this, but MR. BRINEY\l"
	.string "was once a revered seafarer.$"

RustboroCity_Text_BrendanHiLetsRegister: @ 81E1D7D
	.string "BRENDAN: Oh, hey, {PLAYER}!\p"
	.string "You had a MATCH CALL feature put\n"
	.string "on your POKéNAV! Cool!\p"
	.string "Let's register each other so we can\n"
	.string "get in touch anytime!\p"
	.string "… … … … … …$"

RustboroCity_Text_RegisteredBrendan: @ 81E1E11
	.string "Registered BRENDAN\n"
	.string "in the POKéNAV.$"

RustboroCity_Text_BrendanPassedBrineyWantToBattle: @ 81E1E34
	.string "BRENDAN: By the way, {PLAYER}, I walked\n"
	.string "by MR. BRINEY in PETALBURG WOODS.\p"
	.string "I bet he was on his way home to his\n"
	.string "cottage by the sea.\p"
	.string "{PLAYER}, how's your POKéDEX?\n"
	.string "Have you filled in any pages yet?\p"
	.string "Mine rules.\p"
	.string "Want to have a battle to test how\n"
	.string "far you've progressed?$"

RustboroCity_Text_BrendanNoConfidenceInPokemon: @ 81E1F2F
	.string "BRENDAN: What's the matter? Don't have\n"
	.string "any confidence in your POKéMON?$"

RustboroCity_Text_BrendanWantToBattle: @ 81E1F76
	.string "BRENDAN: What's up?\n"
	.string "Want to have a battle with me?$"

RustboroCity_Text_BrendanIWontGoEasy: @ 81E1FA9
	.string "BRENDAN: I know you just became\n"
	.string "a TRAINER, but I won't go easy!$"

RustboroCity_Text_BrendanDefeat: @ 81E1FE9
	.string "Hmm…\n"
	.string "You're pretty good.$"

RustboroCity_Text_BrendanMrBrineyHint: @ 81E2002
	.string "BRENDAN: By the way, you know\n"
	.string "MR. BRINEY? The guy I just passed?\p"
	.string "I bet you didn't know this, since you\n"
	.string "just moved here, {PLAYER}, but\l"
	.string "MR. BRINEY was once a great sailor.$"

RustboroCity_Text_TunnelNearingCompletion: @ 81E20A6
	.string "“Timesaving tunnel nearing\n"
	.string "completion!”\p"
	.string "…Is what it says on the sign, but\n"
	.string "there's also a big “X” splashed\l"
	.string "across it in red paint…$"

RustboroCity_Text_DevonCorpSign: @ 81E2128
	.string "Spectre City Contest Hall$"

RustboroCity_Text_GymSign: @ 81E2167
	.string "Spectre City Pokémon Gym\n"
	.string "Leader: Polter\p"
	.string "“He'll scare you into submission!”$"

RustboroCity_Text_DevonCorpBranchOfficeSign: @ 81E21B3
	.string "Spectre City Contest Hall$"

RustboroCity_Text_CitySign: @ 81E220B
	.string "Spectre City\p"
	.string "“The city of life's end.”$"

RustboroCity_Text_TrainersSchoolSign: @ 81E2253
	.string "POKéMON TRAINER'S SCHOOL\p"
	.string "“We'll teach you anything about\n"
	.string "POKéMON!”$"

RustboroCity_Text_CuttersHouse: @ 81E2296
	.string "Greevil's House$"

RustboroCity_Text_DevelopedNewPokenavFeature: @ 81E22A5
	.string "I've been developing an added feature\n"
	.string "for the POKéNAV…\p"
	.string "And it turned out great!\p"
	.string "{PLAYER}, may I see that POKéNAV?\n"
	.string "The one our PRESIDENT gave you?$"

RustboroCity_Text_AddedMatchCallPleaseCallMrStone: @ 81E2331
	.string "There you go, {PLAYER}!\p"
	.string "I added a new feature named\n"
	.string "MATCH CALL to your POKéNAV.\p"
	.string "Using the MATCH CALL feature,\n"
	.string "you can chat with people who have\l"
	.string "been registered in your POKéNAV.\p"
	.string "{PLAYER}, our PRESIDENT STONE should\n"
	.string "be registered in your POKéNAV.\p"
	.string "Test it out.\n"
	.string "Please give our PRESIDENT a call.$"

RustboroCity_Text_PleaseSelectPokenav: @ 81E2449
	.string "Please select the POKéNAV.$"

RustboroCity_Text_IdBetterGetBackToWork: @ 81E2464
	.string "Okay, I'd better get back to work.\n"
	.string "Please take care, {PLAYER}!$"

RustboroCity_Text_YouCanHave2On2Battle: @ 81E249D
	.string "Did you know this?\p"
	.string "You can have a 2-on-2 battle even\n"
	.string "if you're not with another TRAINER.\p"
	.string "If you catch the eyes of two TRAINERS\n"
	.string "when you have two or more POKéMON,\l"
	.string "they'll both challenge you.\p"
	.string "Don't you think it'd be cool if you\n"
	.string "could beat two TRAINERS by yourself?$"
