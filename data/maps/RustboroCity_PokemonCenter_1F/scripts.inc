.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts:: @ 8214D62
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition: @ 8214D6D
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse:: @ 8214D76
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man:: @ 8214D84
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy:: @ 8214D8D
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl:: @ 8214D96
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities: @ 8214D9F
	.string "My Pokémon needed to rest up after we\n"
	.string "got into a battle with some jerk.\p"
	.string "He insulted my Pokémon and ran off!$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon: @ 8214E13
	.string "Hey, have you been to the Contest Hall?\p"
	.string "It's a place where you and your Pokémon\n"
	.string "can show off against other Trainers!$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor: @ 8214E81
	.string "That old man Greevil is super stinking\n"
	.string "rich! How did he get all that money?$"
	