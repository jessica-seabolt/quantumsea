RustboroCity_Gym_MapScripts:: @ 8212F30
	.byte 0

RustboroCity_Gym_EventScript_Roxanne:: @ 8212F31
	setflag FLAG_DISABLE_BAG
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM39, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	clearflag FLAG_DISABLE_BAG
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated:: @ 8212F66
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setflag FLAG_HIDE_IB_PIKA_1
	setflag FLAG_HIDE_IB_PIKA_2
	clearflag FLAG_DISABLE_BAG
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_eq Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb:: @ 8212FA4
	giveitem ITEM_TM51
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	giveitem ITEM_SABLENITE
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM39
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch:: @ 8212FC8
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh:: @ 8212FE3
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy:: @ 8212FFA
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc:: @ 8213011
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide:: @ 8213028
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory:: @ 821303D
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue:: @ 8213047
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue:: @ 8213057
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified:: @ 8213067
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue:: @ 8213071
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne:: @ 821307B
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice: @ 821309D
	.string "Hey, hey! Welcome to the Rika Leage!\p"
	.string "I'm here to help you out, yeah? I can\n"
	.string "give you some invaluable oversight on\l"
	.string "each Gym Leader!\p"
	.string "You probably already knew, but the Gym\n"
	.string "Leader here is Polter. He uses Ghost\l"
	.string "Pokémon, and they pack a supernatural\l"
	.string "punch that can blow you away!\p"
	.string "If you want to beat him, consider using\n"
	.string "a Dark type, or your own Ghost Pokémon.\p"
	.string "Gym Leaders can Mega Evolve, too. Be\n"
	.string "aware that Polter could use Mega\l"
	.string "Evolution at any time!\p"
	.string "Okay, you feel ready? Go for it, kid!$"

RustboroCity_Gym_Text_GymGuidePostVictory: @ 82132E2
	.string "Hey, hey! You made it! Take a look at\n"
	.string "your Trainer Card! You should see the\l"
	.string "Umbra Badge there.\p"
	.string "You just took your first step towards\n"
	.string "battling the Champion for their title!\p"
	.string "There's no time to waste. Other Gyms\n"
	.string "are awaiting your challenge!$"

RustboroCity_Gym_Text_JoshIntro: @ 82133E9
	.string "Ghost Pokémon aren't to be\n"
	.string "trifled with, child!$"

RustboroCity_Gym_Text_JoshDefeat: @ 821342D
	.string "My ghost Pokémon...$"

RustboroCity_Gym_Text_JoshPostBattle: @ 8213447
	.string "My Ghost Pokémon shall rise\n"
	.string "again!"

RustboroCity_Gym_Text_TommyIntro: @ 8213486
	.string "If you want to fight Polter, you\n"
	.string "need to beat me, first!$"

RustboroCity_Gym_Text_TommyDefeat: @ 82134C6
	.string "Jeez, I get it! You win!$"

RustboroCity_Gym_Text_TommyPostBattle: @ 82134E6
	.string "Polter has trained lots of Ghost\n"
	.string "Pokémon in his lifetime. He's\l"
	.string "pretty much an expert!$"

RustboroCity_Gym_Text_MarcIntro: @ 8213533
	.string "The power of the Ghost Pokémon\n"
	.string "will erase you from our Gym!$"

RustboroCity_Gym_Text_MarcDefeat: @ 8213589
	.string "Oh, man! I've never seen power\n"
	.string "like yours!$"

RustboroCity_Gym_Text_MarcPostBattle: @ 82135C0
	.string "I hate to say it, but you're one\n"
	.string "tough Trainer.$"

RustboroCity_Gym_Text_RoxanneIntro: @ 821362A
	.string "Ugh, what? You don't look\n"
	.string "nearly as tough as those other two.\p"
	.string "For a moment, I was having some fun\n"
	.string "battles, but you...\p"
	.string "Well, alright. If you really want\n"
	.string "to, we can battle.\p"
	.string "My name is Polter.\p"
	.string "Polter: In the Rika League, we want\n"
	.string "to truly test your strength. That means\l"
	.string "only Gym Leaders can use items.\p"
	.string "First to knock out their opponent's\n"
	.string "Pokémon is the winner.\p"
	.string "Of course, that won't be you...\p"
	.string "Polter: You don't even have a\n"
	.string "ghost of a chance!$"


RustboroCity_Gym_Text_RoxanneDefeat: @ 821370B
	.string "Wonderful! What a wonderful\n"
	.string "battle! I feel so alive!$"

RustboroCity_Gym_Text_ReceivedStoneBadge: @ 82137EC
	.string "{PLAYER} received the Umbra Badge\n"
	.string "from Polter!$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis: @ 8213816
	.string "Polter: That Umbra Badge is proof of\n"
	.string "our extraordinary battle today!\p"
	.string "You have what it takes to be the\n"
	.string "Champion of Rika. I can feel it!\p"
	.string "I have more gifts for you, too. Here!$"

RustboroCity_Gym_Text_ExplainRockTomb: @ 82138B1
	.string "That Technical Machine, or\n"
	.string "TM, contains my favorite move.\p"
	.string "Hex deals a good bit of damage to\n"
	.string "your opponent, and it does double\l"
	.string "if they have a status condition.\p"
	.string "That other item, the Sablenite, is\n"
	.string "a Mega Stone. That one is for Sableye.\p"
	.string "Use it well!$"

RustboroCity_Gym_Text_RoxannePostBattle: @ 82139A7
	.string "You showed me an amazing battle.\n"
	.string "There's no doubt in my mind. You\l"
	.string "have what it takes to be the Champ!$"

RustboroCity_Gym_Text_GymStatue: @ 8213A21
	.string "RUSTBORO CITY POKéMON GYM$"

RustboroCity_Gym_Text_GymStatueCertified: @ 8213A3B
	.string "RUSTBORO CITY POKéMON GYM\p"
	.string "ROXANNE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall: @ 8213A76
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "ROXANNE: Oh, hello, {PLAYER}?\n"
	.string "This is ROXANNE of RUSTBORO CITY.\p"
	.string "I heard from BRAWLY that you're\n"
	.string "moving up through the ranks of\l"
	.string "TRAINERS at an incredible clip.\p"
	.string "Well, I'd rather not think that\n"
	.string "I can't beat you.\p"
	.string "I promise, I will shape up my GYM\n"
	.string "so that you may challenge us again.\p"
	.string "I hope you'll be looking forward to\n"
	.string "that occasion as much as me!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RustboroCity_Gym_Text_RegisteredRoxanne: @ 8213C01
	.string "Registered GYM LEADER ROXANNE\n"
	.string "in the POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch: @ 8213C2F
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let us battle!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat: @ 8213CF9
	.string "Grr…\n"
	.string "Again, I have lost…$"

RustboroCity_Gym_Text_RoxannePostRematch: @ 8213D12
	.string "ROXANNE: I still have much to learn\n"
	.string "when it comes to battling POKéMON.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons: @ 8213D93
	.string "ROXANNE: I'm so glad to see you again.\n"
	.string "I'm ROXANNE, the GYM LEADER here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one POKéMON with you?\p"
	.string "Please return with at least one more\n"
	.string "POKéMON.$"
