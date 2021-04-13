RustboroCity_House2_MapScripts:: @ 8215EB3
	.byte 0

RustboroCity_House2_EventScript_PokefanF:: @ 8215EB4
	msgbox RustboroCity_House2_Text_TrainerSchoolExcellent, MSGBOX_NPC
	end

RustboroCity_House2_EventScript_LittleGirl:: @ 8215EBD
	msgbox RustboroCity_House2_Text_RoxanneKnowsALot, MSGBOX_NPC
	end

RustboroCity_House2_Text_TrainerSchoolExcellent: @ 8215EC6
	.string "Oh, hello {PLAYER}.\p"
	.string "Hm? Don't you remember me? I'm one of\n"
	.string "Prof. Sakura's assistants.\p"
	.string "I live here, in Spectre City. It's a\n"
	.string "peaceful, affordable little place.$"

RustboroCity_House2_Text_RoxanneKnowsALot: @ 8215F21
	.string "When I grow up, I want to do science\n"
	.string "research. Just like my dad!$"
