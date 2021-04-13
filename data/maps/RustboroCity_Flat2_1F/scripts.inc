RustboroCity_Flat2_1F_MapScripts:: @ 8215F76
	.byte 0

RustboroCity_Flat2_1F_EventScript_OldWoman:: @ 8215F77
	msgbox RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere, MSGBOX_NPC
	end

RustboroCity_Flat2_1F_EventScript_Skitty:: @ 8215F80
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox RustboroCity_Flat2_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_Flat2_1F_Text_DevonWorkersLiveHere: @ 8215F93
	.string "My Skitty loves getting into all kinds\n"
	.string "of trouble.\p"
	.string "Why, just a short while ago I found her\n"
	.string "all the way in Springrock Villa!$"

RustboroCity_Flat2_1F_Text_Skitty: @ 8215FC6
	.string "Skitty: Mew! Mew!$"

