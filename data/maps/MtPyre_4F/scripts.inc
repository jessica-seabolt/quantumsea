MtPyre_4F_MapScripts:: @ 8231BC8
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi:: @ 8231BC9
	trainerbattle_single TRAINER_LEAH, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro: @ 8231BE0
	.string "Woah! You got the Umbra Badge, too?\n"
	.string "Let's see if you deserve it!$"

MtPyre_5F_Text_AtsushiDefeat: @ 8231C08
	.string "Wow... maybe I don't deserve the\n"
	.string "Umbra Badge...$"

MtPyre_5F_Text_AtsushiPostBattle: @ 8231C24
	.string "I'll train harder! You'll see!$"

StartBattleSpiritomb::
	lockall
	waitse
	playmoncry SPECIES_SPIRITOMB, 2
	delay 40
	waitmoncry
	msgbox SpiritombIsAngry, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_SPIRITOMB, 17, ITEM_SPELL_TAG
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DefeatedSpiritomb
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DefeatedSpiritomb
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq RanFromSpiritomb
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq RanFromSpiritomb
	setflag FLAG_QUEST_5_OBJECTIVE_COMPLETE
	releaseall
	end

DefeatedSpiritomb:: @ 8239768
	setflag FLAG_QUEST_5_OBJECTIVE_COMPLETE
	setvar VAR_MT_PYRE_STATE, 1
	goto DefeatedSpiritomb2
	end

DefeatedSpiritomb2::
	msgbox SpiritombCalmedDown, MSGBOX_DEFAULT
	closemessage
	warp MAP_RUSTBORO_CITY, 255, 23, 24
	waitstate
	releaseall
	end

RanFromSpiritomb::
	warp MAP_RUSTBORO_CITY, 255, 23, 24
	waitstate
	releaseall
	end

SpiritombCalmedDown::
	.string "Spiritomb calmed down. It seems to think\n"
	.string "it is safe from Team Quantum.$"

SpiritombIsAngry:
	.string "???: Gyaaaooo!$"
