MauvilleCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
MauvilleCity_PokemonCenter_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

MauvilleCity_PokemonCenter_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

MauvilleCity_PokemonCenter_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

MauvilleCity_PokemonCenter_2F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Youngster, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_2F_EventScript_Girl1StartSoloBerryCrush::
	lockall
	faceplayer
	checkitem ITEM_POWDER_JAR
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_2F_EventScript_NeedPowderJar
	msgbox MauvilleCity_PokemonCenter_2F_Text_PlayBerryCrushSolo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_2F_EventScript_DeclinedBerryCrushFromGirl
    fadescreenswapbuffers FADE_TO_BLACK
    special StartBerryCrushSolo
	releaseall
	end

MauvilleCity_PokemonCenter_2F_EventScript_DeclinedBerryCrushFromGirl::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Girl1OkayThen, MSGBOX_AUTOCLOSE
	releaseall
	end

MauvilleCity_PokemonCenter_2F_EventScript_NeedPowderJar::
	msgbox MauvilleCity_PokemonCenter_2F_Text_NeedPowderJar, MSGBOX_AUTOCLOSE
	releaseall
	end

MauvilleCity_PokemonCenter_2F_Text_Youngster:
	.string "Did you know that you can link battle\n"
	.string "at the Colosseum here?\p"
	.string "They put up your record on the wall\n"
	.string "for everyone to see.\p"
	.string "It's embarrassing if you lose more\n"
	.string "often than you win…$"

MauvilleCity_PokemonCenter_2F_Text_PlayBerryCrushSolo:
	.string "Would you like to play BERRY CRUSH\n"
	.string "by yourself?$"

MauvilleCity_PokemonCenter_2F_Text_Girl1OkayThen:
	.string "Okay then…$"

MauvilleCity_PokemonCenter_2F_Text_NeedPowderJar:
	.string "If you want to play BERRY CRUSH by\n"
	.string "yourself, you'd need a POWDER JAR.$"

