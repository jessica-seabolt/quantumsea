MauvilleCity_Mart_MapScripts:: @ 82110E5
	.byte 0

MauvilleCity_Mart_EventScript_Clerk:: @ 82110E6
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

IridiumBluff_Mart_EventScript_PokemartSeedShop:: @ 8214F21
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IridiumBluff_Mart_Pokemart_SeedShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

IridiumBluff_Mart_Pokemart_SeedShop: @ 8214F30
	.2byte ITEM_GRASSY_SEED
	.2byte ITEM_ELECTRIC_SEED
	.2byte ITEM_MISTY_SEED
	.2byte ITEM_PSYCHIC_SEED
	release
	end

IridiumBluff_Mart_EventScript_PokemartDamageShop:: @ 8214F21
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IridiumBluff_Mart_Pokemart_DamageShop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

IridiumBluff_Mart_Pokemart_DamageShop: @ 8214F30
	.2byte ITEM_ABSORB_BULB
	.2byte ITEM_CELL_BATTERY
	.2byte ITEM_EJECT_BUTTON
	.2byte ITEM_LUMINOUS_MOSS
	.2byte ITEM_SNOWBALL
	.2byte ITEM_WEAKNESS_POLICY
	release
	end

	.align 2
MauvilleCity_Mart_Pokemart: @ 8211100
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

MauvilleCity_Mart_EventScript_ExpertM:: @ 821111C
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
	end

MauvilleCity_Mart_EventScript_Man:: @ 8211125
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
	end

MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats: @ 821112E
	.string "There are items that temporarily\n"
	.string "elevate the stats of POKéMON.\p"
	.string "The ones I know you use in battle\n"
	.string "are X ATTACK and X DEFEND…\p"
	.string "I do believe that there are others\n"
	.string "like them.$"

MauvilleCity_Mart_Text_DecisionsDetermineBattle: @ 82111D8
	.string "Use a certain move, or use an item\n"
	.string "instead…\p"
	.string "The TRAINER's decisions determine how\n"
	.string "battles turn out, I think.$"

