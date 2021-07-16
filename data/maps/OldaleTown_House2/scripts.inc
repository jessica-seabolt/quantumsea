OldaleTown_House2_MapScripts:: @ 81FBF5A
	.byte 0

OldaleTown_House2_EventScript_Woman:: @ 81FBF5B
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man:: @ 81FBF64
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp: @ 81FBF6D
	.string "My grandson Wes wants to go all the way\n"
	.string "to Orre someday.\p"
	.string "I know he loves the desert, but it's too\n"
	.string "dangerous. It's been overrun by thugs.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon: @ 81FBFB0
	.string "Don't tell my grandmother, but I'm going\n"
	.string "to sneak out anyday now and go to Orre.\p"
	.string "This guy Gonzap said he could give me\n"
	.string "a place to stay and everything.\p"
	.string "All I have to do is join Team Snagem!$"
