RustboroCity_House3_MapScripts:: @ 8216190
	.byte 0

RustboroCity_House3_EventScript_OldMan:: @ 8216191
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman:: @ 821619A
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu:: @ 82161A3
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, 0
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames: @ 82161B6
	.string "Me and my Cubone are about to go battle\n"
	.string "Polter's Gym!$"

RustboroCity_House3_Text_NamingPikachuPekachu: @ 821622A
	.string "I'm very supportive of my little girl.\p"
	.string "I know she can't defeat Polter, but I\n"
	.string "can't help but smile when I see the fire\l"
	.string "in her eyes.$"

RustboroCity_House3_Text_Pekachu: @ 82162AB
	.string "Cubone: Bo bo bo!$"
