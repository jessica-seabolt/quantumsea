MtPyre_5F_MapScripts:: @ 8231C6D
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha:: @ 8231C6E
	trainerbattle_single TRAINER_DAISY, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro: @ 8231C85
	.string "I love Spectre Forest!\n"
	.string "It's calm, peaceful, pretty...\p"
	.string "And the perfect spot for a battle!$"

MtPyre_4F_Text_TashaDefeat: @ 8231CDB
	.string "Oof, so close!$"

MtPyre_4F_Text_TashaPostBattle: @ 8231CEE
	.string "I wish I could stay here forever. Isn't\n"
	.string "nature just wonderful?$"

QuantumBlockSpectreForest::
	msgbox QuantumBlockSpectreForestText, MSGBOX_NPC
	end

QuantumBlockSpectreForestText:
	.string "Hey, kid! Mind your own business! We\n"
	.string "have some important work to do here!$"
