GraniteCave_B1F_MapScripts:: @ 822DC5E
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_SetHoleWarp: @ 822DC6E
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F, 255, 0, 0
	end

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
