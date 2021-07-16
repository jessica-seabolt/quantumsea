.set LOCALID_NURSE, 1

MauvilleCity_PokemonCenter_1F_MapScripts:: @ 8210E5B
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition: @ 8210E66
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx:: @ 8210E74
	special ScrSpecial_SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse:: @ 8210E78
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1:: @ 8210E86
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2:: @ 8210E8F
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster:: @ 8210E98
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings: @ 8210EA1
	.string "Who is Cipher? And what do they want?$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner: @ 8210F06
	.string "Smithie is so cool! I wish I could battle\n"
	.string "like he does!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun: @ 8210F8A
	.string "I heard Team Quantum and Cipher don't\n"
	.string "get along very well.\p"
	.string "Cipher is the baddest of the bad! It\n"
	.string "looks like even Team Quantum has some\l"
	.string "sort of line.$"
