.set LOCALID_NURSE, 2
.set LOCALID_ZIGZAGOON, 4

Route101_MapScripts:: @ 81EBCBA
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition: @ 81EBCC5
	call ProfBirch_EventScript_UpdateLocation
	call_if_set FLAG_ROUTE_2_RAINING, Route2Raining
	end

Route101_OnFrame: @ 81EBCCB
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup:: @ 81EBCD5
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_StartBirchRescue:: @ 81EBCDE
	lockall
	playbgm MUS_HELP, 1
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_NURSE, 0, 15
	setobjectxy LOCALID_ZIGZAGOON, 0, 16
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_NURSE, Route101_Movement_BirchRunAway1
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_NURSE, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_NURSE, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_NURSE, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth:: @ 81EBD4E
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest:: @ 81EBD64
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth:: @ 81EBD7A
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth: @ 81EBD90
	walk_up
	step_end

Route101_Movement_PreventExitWest: @ 81EBD92
	walk_right
	step_end

Route101_Movement_PreventExitNorth: @ 81EBD94
	walk_down
	step_end

Route101_Movement_ZigzagoonChaseInCircles: @ 81EBD96
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_ZigzagoonChase1: @ 81EBDB5
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_ZigzagoonFaceBirch: @ 81EBDBD
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene: @ 81EBDC2
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_fastest_left
	step_end

Route101_Movement_BirchRunInCircles: @ 81EBDC8
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1: @ 81EBDE7
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFaceZigzagoon: @ 81EBDEF
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1: @ 81EBDF4
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2: @ 81EBDF7
	walk_up
	walk_left
	walk_up
	step_end

Route1_EventScript_Mikey:: @ 81F7331
	trainerbattle_single TRAINER_TISHA, Route1_Text_MikeyIntro, Route1_Text_MikeyDefeat
	msgbox Route1_Text_MikeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Ryan:: @ 81F7331
	trainerbattle_single TRAINER_SAWYER_1, Route1_Text_RyanIntro, Route1_Text_RyanDefeat
	msgbox Route1_Text_RyanPostBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Lilith:: @ 81F7331
	trainerbattle_single TRAINER_GABRIELLE_1, Route1_Text_LilithIntro, Route1_Text_LilithDefeat
	msgbox Route1_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

Route101_EventScript_Boy:: @ 81EBE04
	lock
	faceplayer
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	msgbox AllHealedUpRoute1, MSGBOX_DEFAULT
	applymovement LOCALID_NURSE, Route1HealMovement
	waitmovement 0
	closemessage
	release
	end

Route101_EventScript_RouteSign:: @ 81EBE0D
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route1CobaltTownSign::
	msgbox Route1CobaltTownSignText, MSGBOX_SIGN
	end

Route1CobaltTownSignText:
	.string "Route 1\p"
	.string "Taproot Town {UP_ARROW}$"

Route101_EventScript_BirchsBag:: @ 81EBE16
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ZIGZAGOON
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement LOCALID_NURSE, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route101_EventScript_HideMayInBedroom
	compare VAR_RESULT, FEMALE
	call_if_eq Route101_EventScript_HideBrendanInBedroom
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom:: @ 81EBE85
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom:: @ 81EBE89
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer: @ 81EBE8D
	walk_right
	step_end

Route101_Text_HelpMe: @ 81EBE8F
	.string "H-help me!$"

Route101_Text_PleaseHelp: @ 81EBE9A
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"

Route101_Text_DontLeaveMe: @ 81EBEDF
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_Text_YouSavedMe: @ 81EBF12
	.string "PROF. BIRCH: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my POKéMON LAB later, okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter: @ 81EBFDD
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"

Route101_Text_WildPokemonInTallGrass: @ 81EC04A
	.string "Nurse Joy: Hello, Trainer! It must be\n"
	.string "a rough journey coming all this way!\p"
	.string "Here, let me heal your Pokémon!$"

AllHealedUpRoute1:
	.string "Nurse Joy: There you are! If you ever\n"
	.string "need help, just look for your nearest\l"
	.string "Pokémon Center.\p"
	.string "We'll heal you right up!$"

Route101_Text_RouteSign: @ 81EC0C8
	.string "Springrock Path\p"
	.string "Springrock Villa {UP_ARROW}$"

Route1HealMovement:
    nurse_joy_bow
    delay_4
    step_end

Route1_Text_MikeyIntro:
	.string "Wow! Are you a beginner, too? We should\n"
	.string "battle and see who's tougher!$"

Route1_Text_MikeyDefeat:
	.string "What? I can't believe it!$"

Route1_Text_MikeyPostBattle:
	.string "I guess you're not a beginner after all.\p"
	.string "Maybe you should try to battle Polter in\n"
	.string "Spectre City's Gym.$"

Route1_Text_RyanIntro:
	.string "Mwahaha! You cannot defeat the power of\n"
	.string "my Bug Pokémon!$"

Route1_Text_RyanDefeat:
	.string "Aw, what? You really Bug me!$"

Route1_Text_RyanPostBattle:
	.string "I guess Bug Pokémon can't do everything\n"
	.string "all on their own...$"

Route1_Text_LilithIntro:
	.string "Are you a Pokémon Trainer?\p"
	.string "Then you have to battle me! You can't\n"
	.string "say no to a challenge!$"

Route1_Text_LilithDefeat:
	.string "I wish you said no to my challenge...$"

Route1_Text_LilithPostBattle:
	.string "Hm? Are you Pokémon hurt? You can find a\n"
	.string "Pokémon Center in most Towns.\p"
	.string "The Nurse there can heal you right up!$"
