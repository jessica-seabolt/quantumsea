.set LOCALID_GREEVIL, 1

RustboroCity_CuttersHouse_MapScripts:: @ 8215BD3
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter:: @ 8215BD4
	lock
	faceplayer
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_ASSAULT_VEST
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_GREEVIL
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	playse SE_EXIT
	fadescreen FADE_FROM_BLACK
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut:: @ 8215C00
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass:: @ 8215C0A
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse: @ 8215C13
	.string "Hello there, Trainer. My name's Greevil.\n"
	.string "I'm a Pokémon Trainer, just like you.\p"
	.string "Greevil: I wonder, what is it that truly\n"
	.string "brings together Trainers and Pokémon?\p"
	.string "Is it some unspoken bond? Perhaps the\n"
	.string "shared adventures?\p"
	.string "No, no...\p"
	.string "What truly brings together a Trainer and\n"
	.string "their Pokémon is power.\p"
	.string "This power can be good, it can be bad...\p"
	.string "Greevil: But it drives us. It is why we\n"
	.string "insist on pushing our Pokémon to their\l"
	.string "absolute limits. It helps them grow.\p"
	.string "I run an organization of the world's top\n"
	.string "scientists and Trainers. We attempt to\l"
	.string "determine how to further increase the\l"
	.string "fighting power of a Pokémon.\p"
	.string "You seem to be a kind Trainer. Here, a\n"
	.string "small gift from me. I insist.$"

RustboroCity_CuttersHouse_Text_ExplainCut: @ 8215D33
	.string "Greevil: That Assault Vest can enhance\n"
	.string "the Special Defense of a Pokémon by a\l"
	.string "large margin.\p"
	.string "Please, keep it. Perhaps someday, when\n"
	.string "the world's balance depends on it, we\l"
	.string "shall meet again.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees: @ 8215E39
	.string "When they were expanding the city of\n"
	.string "RUSTBORO, my dad helped out.\p"
	.string "He made his POKéMON use CUT to clear\n"
	.string "the land of trees.$"
