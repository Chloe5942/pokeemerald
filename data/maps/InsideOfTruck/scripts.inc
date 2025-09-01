InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end

InsideOfTruck_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_SYS_QUEST_MENU_GET
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBox::
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end

InsideOfTruck_Text_BoxPrintedWithMonLogo:
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

InsideOfTruck_EventScript_DevPort::
	setflag FLAG_SYS_QUEST_MENU_GET
	startquest QUEST_RIVAL_NEXT_DOOR
	delay 5
	startquest QUEST_SCOUTING_SCOTT
	cleartrainerflag TRAINER_ROXANNE_1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	clearflag FLAG_BADGE01_GET
	clearflag FLAG_DEFEATED_RUSTBORO_GYM
	clearflag FLAG_RECEIVED_EXP_SHARE
	clearflag FLAG_HIDE_BATTLE_FRONTIER_RECEPTION_GATE_SCOTT
	clearflag FLAG_MET_SCOTT_RUSTBORO
	clearflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	clearflag FLAG_MET_SCOTT_IN_EVERGRANDE
	clearflag FLAG_MET_SCOTT_IN_FALLARBOR
	clearflag FLAG_MET_SCOTT_IN_LILYCOVE
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	clearflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
	clearflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	clearflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_SLATEPORT_CITY_SCOTT
	warpspinenter MAP_LITTLEROOT_TOWN, 12, 10
	end

InsideOfTruck_EventScript_DevPort2::
	random 4
	goto_if_eq VAR_RESULT, 0, InsideOfTruck_EventScript_DevPort2_PuzzleKabuto
	goto_if_eq VAR_RESULT, 1, InsideOfTruck_EventScript_DevPort2_PuzzleOmanyte
	goto_if_eq VAR_RESULT, 2, InsideOfTruck_EventScript_DevPort2_PuzzleAerodactyl
	goto_if_eq VAR_RESULT, 3, InsideOfTruck_EventScript_DevPort2_PuzzleHoOh
	end

InsideOfTruck_EventScript_DevPort2_PuzzleKabuto::
	setflag FLAG_SYS_QUEST_MENU_GET
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_KABUTO
	setvar VAR_0x8005, FALSE
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, InsideOfTruck_EventScript_DevPort2_Exit
	end

InsideOfTruck_EventScript_DevPort2_PuzzleOmanyte::
	setflag FLAG_SYS_QUEST_MENU_GET
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_OMANYTE
	setvar VAR_0x8005, FALSE
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, InsideOfTruck_EventScript_DevPort2_Exit
	end

InsideOfTruck_EventScript_DevPort2_PuzzleAerodactyl::
	setflag FLAG_SYS_QUEST_MENU_GET
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_AERODACTYL
	setvar VAR_0x8005, FALSE
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, InsideOfTruck_EventScript_DevPort2_Exit
	end

InsideOfTruck_EventScript_DevPort2_PuzzleHoOh::
	setflag FLAG_SYS_QUEST_MENU_GET
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_HO_OH
	setvar VAR_0x8005, FALSE
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, InsideOfTruck_EventScript_DevPort2_Exit
	end

InsideOfTruck_EventScript_DevPort2_Exit::
	startquest QUEST_HOMECOMING
	clearflag FLAG_ENABLE_MOM_MATCH_CALL
	clearflag FLAG_RECEIVED_AMULET_COIN
	warpspinenter MAP_LITTLEROOT_TOWN, 12, 10
	end
