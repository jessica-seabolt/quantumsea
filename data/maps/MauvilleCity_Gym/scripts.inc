MauvilleCity_Gym_MapScripts:: @ 820DD6E
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad: @ 820DD74
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers:: @ 820DDBA
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers:: @ 820DDC4
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, 1
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, 1
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, 1
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, 0
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, 0
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, 1
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, 1
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, 0
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, 0
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, 1
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, 1
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, 0
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, 0
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, 0
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, 0
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, 0
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, 0
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, 0
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, 0
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, 1
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, 0
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, 0
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, 0
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, 0
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, 0
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, 0
	end

MauvilleCity_Gym_EventScript_Switch1Pressed:: @ 820DEAF
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed:: @ 820DEBD
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed:: @ 820DECB
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed:: @ 820DED9
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle:: @ 820DEE7
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson:: @ 820DEEB
	setflag FLAG_DISABLE_BAG
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	clearflag FLAG_DISABLE_BAG
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM34, MauvilleCity_Gym_EventScript_GiveShockWave2
	compare VAR_NEW_MAUVILLE_STATE, 2
	goto_if_eq MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated:: @ 820DF2B
	clearflag FLAG_DISABLE_BAG
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE02_GET
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2:: @ 820DF8D
	giveitem ITEM_TM52
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	giveitem ITEM_MAWILITE
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM34
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave:: @ 820DFB1
	giveitem ITEM_TM52
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_BagIsFull
	giveitem ITEM_MAWILITE
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM34
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville:: @ 820DFD4
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch:: @ 820DFDE
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1:: @ 820DFF9
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	compare VAR_MAUVILLE_GYM_STATE, 1
	goto_if_eq MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2:: @ 820E01E
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	compare VAR_MAUVILLE_GYM_STATE, 2
	goto_if_eq MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3:: @ 820E043
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	compare VAR_MAUVILLE_GYM_STATE, 3
	goto_if_eq MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4:: @ 820E068
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	compare VAR_MAUVILLE_GYM_STATE, 4
	goto_if_eq MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch:: @ 820E08D
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing:: @ 820E0AD
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState:: @ 820E0AF
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState:: @ 820E0B4
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk:: @ 820E0B9
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn:: @ 820E0D0
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben:: @ 820E0E7
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian:: @ 820E0FE
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo:: @ 820E115
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide:: @ 820E12C
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory:: @ 820E141
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue:: @ 820E14B
	lockall
	goto_if_set FLAG_BADGE02_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue:: @ 820E15B
	lockall
	goto_if_set FLAG_BADGE02_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified:: @ 820E16B
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue:: @ 820E175
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice: @ 820E17F
	.string "Hey, {PLAYER}! Ready for Smithie's Gym?\p"
	.string "This one's all about the Steel Type. It\n"
	.string "can dish out some powerful hits, but the\l"
	.string "real power of Steel Pokémon comes from\l"
	.string "their incredible defense!\p"
	.string "Try taking them down with a powerful\n"
	.string "Fire or Ground move, yeah? Good luck!$"

MauvilleCity_Gym_Text_GymGuidePostVictory: @ 820E283
	.string "Whoa, you did it! On to the next Gym!$"

MauvilleCity_Gym_Text_KirkIntro: @ 820E2BC
	.string "Hahaha! Isn't this Gym so crazy?\n"
	.string "Which way do you go next?$"

MauvilleCity_Gym_Text_KirkDefeat: @ 820E2FC
	.string "Aw, man! You're smart!$"

MauvilleCity_Gym_Text_KirkPostBattle: @ 820E336
	.string "Smithie put this arrow puzzle in\n"
	.string "to make things interesting!$"

MauvilleCity_Gym_Text_ShawnIntro: @ 820E369
	.string "Cipher? In our Gym?\n"
	.string "Impossible!$"

MauvilleCity_Gym_Text_ShawnDefeat: @ 820E3A7
	.string "Ugh, beat by a kid!$"

MauvilleCity_Gym_Text_ShawnPostBattle: @ 820E3C1
	.string "Smithie isn't associated with Cipher!\n"
	.string "...I mean, I don't think he is...$"

MauvilleCity_Gym_Text_BenIntro: @ 820E443
	.string "Aha! A Challenger! I'll take care of\n"
	.string "you myself!$"

MauvilleCity_Gym_Text_BenDefeat: @ 820E469
	.string "It's no fun to lose…$"

MauvilleCity_Gym_Text_BenPostBattle: @ 820E47E
	.string "Sometimes, I get lost in here just\n"
	.string "trying to leave.\p"
	.string "It's so frustrating!$"

MauvilleCity_Gym_Text_VivianIntro: @ 820E4BB
	.string "So, you want to challenge Smithie with\n"
	.string "your Pokémon?\p"
	.string "Yeah, good luck with that!$"

MauvilleCity_Gym_Text_VivianDefeat: @ 820E4F4
	.string "Ha, maybe I needed the good luck!$"

MauvilleCity_Gym_Text_VivianPostBattle: @ 820E50F
	.string "I've heard that Smithie does some shady\n"
	.string "deals with that Cipher group.\p"
	.string "Maybe I should reconsider working here.$"

MauvilleCity_Gym_Text_AngeloIntro: @ 820E593
		.string "You can't battle Smithie!\n"
	.string "I won't allow it!$"

MauvilleCity_Gym_Text_AngeloDefeat: @ 820E5A8
	.string "Fine, go ahead...$"

MauvilleCity_Gym_Text_AngeloPostBattle: @ 820E5C2
	.string "I never beat any of the Trainers who\n"
	.string "make it this far.\p"
	.string "I'm bound to get fired soon...$"

MauvilleCity_Gym_Text_WattsonIntro: @ 820E602
	.string "Ah, another challneger! Trainers are\n"
	.string "always welcome to challenge me!\p"
	.string "Allow me to introduce myself! My name\n"
	.string "is Smithie, and I'm the Iridium Bluff\l"
	.string "Gym Leader. I specialize in steel Types!\p"
	.string "Smithie: Hm? Cipher? Why, I've hardly\n"
	.string "heard the name! The rumors are simply\l"
	.string "fabricated lies, friend!\p"
	.string "Come, let us forget about that! Do you\n"
	.string "know the rules? No Items for you! Knock\l"
	.string "out my Pokémon for the Badge!\p"
	.string "Ready? No turning back! Hahahahaha!$"

MauvilleCity_Gym_Text_WattsonDefeat: @ 820E734
	.string "Hahaha! I've never seen such a great\n"
	.string "battle! Here, take this!$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge: @ 820E77F
	.string "{PLAYER} received the Alloy Badge\n"
	.string "from Smithie.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis: @ 820E7AA
	.string "I'm sure you're already familiar with\n"
	.string "what a Badge does...\p"
	.string "So take these, too!$"

MauvilleCity_Gym_Text_ExplainShockWave: @ 820E844
	.string "That TM52 there contains Iron Defense!\p"
	.string "It boosts your defense. Who'd have\n"
	.string "guessed it? Hahaha! And that Mawilite\l"
	.string "is for Mega Evolving a Mawile!\p"
	.string "Because you beat me, I'll let you in on\n"
	.string "a secret. I am part of Cipher.\p"
	.string "But, what can you do about it? Kid, I\n"
	.string "paid off the officials.\p"
	.string "Cipher owns this city! Hahahaha!\p"
	.string "Now, run along! Continue challenging the\n"
	.string "Gyms like a good kid! Good luck!\p"
	.string "Hahahahahahahaha!$"

MauvilleCity_Gym_Text_WattsonPostBattle: @ 820E8E3
	.string "Because you beat me, I'll let you in on\n"
	.string "a secret. I am part of Cipher.\p"
	.string "But, what can you do about it? Kid, I\n"
	.string "paid off the officials.\p"
	.string "Cipher owns this city! Hahahaha!\p"
	.string "Now, run along! Continue challenging the\n"
	.string "Gyms like a good kid! Good luck!\p"
	.string "Hahahahahahahaha!$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor: @ 820E925
	.string "Wahahahah!\n"
	.string "Go forth and endeavor, youngster!$"

MauvilleCity_Gym_Text_GymStatue: @ 820E96C
	.string "Iridium Bluff Pokémon Gym\p"
	.string "Smithie's Certified Trainers:\n"
	.string "{RIVAL}\l"
	.string "Ravynn$"

MauvilleCity_Gym_Text_GymStatueCertified: @ 820E96C
	.string "Iridium Bluff Pokémon Gym\p"
	.string "Smithie's Certified Trainers:\n"
	.string "{RIVAL}\l"
	.string "Ravynn\l"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch: @ 820E9A7
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "I'll make sparks fly from you!\n"
	.string "Don't say I didn't warn you!$"

MauvilleCity_Gym_Text_WattsonRematchDefeat: @ 820EA42
	.string "Oof…\n"
	.string "Our batteries ran dry…$"

MauvilleCity_Gym_Text_WattsonPostRematch: @ 820EA5E
	.string "WATTSON: We'll have to recharge our\n"
	.string "batteries again.\p"
	.string "When we're fully charged up, we'll\n"
	.string "gladly accept your challenge.\p"
	.string "So, come back again sometime,\n"
	.string "won't you?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons: @ 820EAFD
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Oops! Wait!\n"
	.string "You've only one POKéMON with you!\p"
	.string "Come see me with two or more\n"
	.string "POKéMON, all right?$"
