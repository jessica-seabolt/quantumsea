GraniteCave_B1F_MapScripts:: @ 822DC5E
	.byte 0

SpringrockPathHiker::
	lock
	faceplayer
	msgbox SpringrockPathHikerText, MSGBOX_DEFAULT
	closemessage
	release
	end

SpringrockPathHikerText:
	.string "Hey there, traveler!\p"
	.string "Oh, me? I'm no Pokémon Trainer, but if\n"
	.string "you do see a Trainer, be ready!\p"
	.string "As soon as your eyes meet, you're in for\n"
	.string "a Pokémon Battle!$"
