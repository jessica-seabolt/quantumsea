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
	.string "you go out towards Route 1, there are a\l"
	.string "bunch of 'em waiting for you!$"
