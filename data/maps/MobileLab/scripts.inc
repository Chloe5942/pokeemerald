MobileLab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MobileLab_EventScript_OnLoad
	.byte 0

MobileLab_EventScript_OnLoad::
	goto_if_eq VAR_LAST_LOCATION, MAP_ROUTE111, MobileLab_EventScript_Warp_Route111
	goto_if_eq VAR_LAST_LOCATION, MAP_ROUTE105, MobileLab_EventScript_Warp_Route105
	goto_if_eq VAR_LAST_LOCATION, MAP_ROUTE120, MobileLab_EventScript_Warp_Route120
	end

MobileLab_EventScript_Warp_Route120::
	setdynamicwarp MAP_ROUTE120, 3, 62
	end

MobileLab_EventScript_Warp_Route111::
	setdynamicwarp MAP_ROUTE111, 34, 90
	end

MobileLab_EventScript_Warp_Route105::
	setdynamicwarp MAP_ROUTE105, 10, 21
	end

MobileLab_EventScript_FieldScientist1::
	lockall
	faceplayer
	goto_if_quest_active QUEST_GIGANTIC_FINDINGS, MobileLab_EventScript_FieldScientist1_Quest
	msgbox MobileLab_Text_DoingResearch, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

MobileLab_EventScript_FieldScientist1_Quest::
	lockall
	faceplayer
	goto_if_eq VAR_GIGANTIC_FINDINGS, 2, MobileLab_EventScript_DesertRuins
	goto_if_eq VAR_GIGANTIC_FINDINGS, 3, MobileLab_EventScript_GotoResearchLab
	goto_if_eq VAR_GIGANTIC_FINDINGS, 4, MobileLab_EventScript_IslandCave
	goto_if_eq VAR_GIGANTIC_FINDINGS, 5, MobileLab_EventScript_GotoResearchLab
	goto_if_eq VAR_GIGANTIC_FINDINGS, 6, MobileLab_EventScript_AncientTomb
	goto_if_eq VAR_GIGANTIC_FINDINGS, 7, MobileLab_EventScript_GotoResearchLab
	releaseall
	end

MobileLab_EventScript_DesertRuins::
	goto_if_mon_caught SPECIES_REGIROCK, MobileLab_EventScript_UpdateQuest
	goto_if_mon_seen SPECIES_REGIROCK, MobileLab_EventScript_DidntCatchIt
	lockall
	faceplayer
	msgbox MobileLab_Text_DesertRuins, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

MobileLab_EventScript_IslandCave::
	goto_if_mon_caught SPECIES_REGICE, MobileLab_EventScript_UpdateQuest
	goto_if_mon_seen SPECIES_REGICE, MobileLab_EventScript_DidntCatchIt
	lockall
	faceplayer
	msgbox MobileLab_Text_IslandCave, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

MobileLab_EventScript_AncientTomb::
	goto_if_mon_caught SPECIES_REGISTEEL, MobileLab_EventScript_UpdateQuest
	goto_if_mon_seen SPECIES_REGISTEEL, MobileLab_EventScript_DidntCatchIt
	lockall
	faceplayer
	msgbox MobileLab_Text_AncientTomb, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

MobileLab_EventScript_UpdateQuest::
	updatequest QUEST_GIGANTIC_FINDINGS, VAR_GIGANTIC_FINDINGS
	goto MobileLab_EventScript_GotoResearchLab
	end

MobileLab_EventScript_GotoResearchLab::
	lockall
	faceplayer
	msgbox MobileLab_Text_GotoResearchLab, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

MobileLab_EventScript_DidntCatchIt::
	lockall
	faceplayer
	msgbox MobileLab_Text_DidntCatchIt, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

MobileLab_Text_DoingResearch:
	.string "Sorry, I'm on the phone at the moment.$"

MobileLab_Text_DidntCatchIt:
	.string "{PLAYER}, you didn't catch it?$"

MobileLab_Text_DesertRuins:
	.string "You must be {PLAYER}, right?\n"
	.string "The boss told us that you'll be coming.\p"
	.string "We've picked up on an energy signal\n"
	.string "that seems to belong to a ROCK type\p"
	.string "POKéMON from the DESERT RUINS.\n"
	.string "We would like for you to investigate it.$"

MobileLab_Text_IslandCave:
	.string "Welcome back {PLAYER}!\n"
	.string "The boss told us that you'll be coming.\p"
	.string "We've picked up on an energy signal\n"
	.string "that seems to belong to a ICE type\p"
	.string "POKéMON from the ISLAND CAVE.\n"
	.string "We would like for you to investigate it.$"

MobileLab_Text_AncientTomb:
	.string "Welcome back once more {PLAYER}!\n"
	.string "The boss told us that you'll be coming.\p"
	.string "We've picked up on an energy signal\n"
	.string "that seems to belong to a STEEL type\p"
	.string "POKéMON from the ANCIENT TOMB.\n"
	.string "We would like for you to investigate it.$"

MobileLab_Text_GotoResearchLab:
	.string "{PLAYER}!\p"
	.string "The boss told us that he wants you to\n"
	.string "come back to the RESEARCH LAB with\p"
	.string "the POKéMON you just caught.\n"
	.string "ABRA there can teleport you to the lab.$"

MobileLab_EventScript_FieldScientist2::
	lockall
	faceplayer
	goto_if_quest_active QUEST_GIGANTIC_FINDINGS, MobileLab_EventScript_FieldScientist2_Quest
	msgbox MobileLab_Text_DoingResearch2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

MobileLab_EventScript_FieldScientist2_Quest::
	lockall
	faceplayer
	goto_if_eq VAR_GIGANTIC_FINDINGS, 2, MobileLab_EventScript_DesertRuins2
	goto_if_eq VAR_GIGANTIC_FINDINGS, 3, MobileLab_EventScript_GotoResearchLab2
	goto_if_eq VAR_GIGANTIC_FINDINGS, 4, MobileLab_EventScript_IslandCave2
	goto_if_eq VAR_GIGANTIC_FINDINGS, 5, MobileLab_EventScript_GotoResearchLab2
	goto_if_eq VAR_GIGANTIC_FINDINGS, 6, MobileLab_EventScript_AncientTomb2
	goto_if_eq VAR_GIGANTIC_FINDINGS, 7, MobileLab_EventScript_GotoResearchLab2
	releaseall
	end

MobileLab_EventScript_DesertRuins2::
	lockall
	faceplayer
	msgbox MobileLab_Text_DesertRuins2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	goto_if_set FLAG_RECIEVED_TIMER_BALLS_REGIROCK, MobileLab_EventScript_End
	giveitem ITEM_TIMER_BALL, 10
	setflag FLAG_RECIEVED_TIMER_BALLS_REGIROCK
	releaseall
	end

MobileLab_EventScript_IslandCave2::
	lockall
	faceplayer
	msgbox MobileLab_Text_IslandCave2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	goto_if_set FLAG_RECIEVED_TIMER_BALLS_REGICE, MobileLab_EventScript_End
	giveitem ITEM_TIMER_BALL, 10
	setflag FLAG_RECIEVED_TIMER_BALLS_REGICE
	releaseall
	end

MobileLab_EventScript_AncientTomb2::
	lockall
	faceplayer
	msgbox MobileLab_Text_AncientTomb2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	goto_if_set FLAG_RECIEVED_TIMER_BALLS_REGISTEEL, MobileLab_EventScript_End
	giveitem ITEM_TIMER_BALL, 10
	setflag FLAG_RECIEVED_TIMER_BALLS_REGISTEEL
	releaseall
	end

MobileLab_EventScript_GotoResearchLab2::
	lockall
	faceplayer
	msgbox MobileLab_Text_GotoResearchLab2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

MobileLab_EventScript_End::
	lockall
	faceplayer
	msgbox MobileLab_Text_AlreadyGave, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

MobileLab_Text_DoingResearch2:
	.string "We're researching the strange\n"
	.string "energy readings that are in the area.$"

MobileLab_Text_DesertRuins2:
	.string "{PLAYER}, we suspect the POKéMON in\n"
	.string "the DESERT RUINS to be REGIROCK.\p"
	.string "Here are some TIMER BALLS to aid you.$"

MobileLab_Text_IslandCave2:
	.string "{PLAYER}, we suspect the POKéMON in\n"
	.string "the ISLAND CAVE to be REGICE.\p"
	.string "Here are some TIMER BALLS to aid you.$"

MobileLab_Text_AncientTomb2:
	.string "{PLAYER}, we suspect the POKéMON in\n"
	.string "the ANCIENT TOMB to be REGISTEEL.\p"
	.string "Here are some TIMER BALLS to aid you.$"

MobileLab_Text_AlreadyGave:
	.string "{PLAYER}, I've already given\n"
	.string "you some TIMER BALLS.$"

MobileLab_Text_GotoResearchLab2:
	.string "{PLAYER}, I heard that the boss wants\n"
	.string "you to come back to the RESEARCH LAB\p"
	.string "with the POKéMON you just caught.\n"
	.string "ABRA there can teleport you to the lab.$"

MobileLab_EventScript_Abra::
	lockall
	faceplayer
	goto_if_eq VAR_GIGANTIC_FINDINGS, 3, MobileLab_EventScript_AbraTeleportResearchLab
	goto_if_eq VAR_GIGANTIC_FINDINGS, 4, MobileLab_EventScript_AbraTeleportMobileLab
	goto_if_eq VAR_GIGANTIC_FINDINGS, 5, MobileLab_EventScript_AbraTeleportResearchLab
	goto_if_eq VAR_GIGANTIC_FINDINGS, 7, MobileLab_EventScript_AbraTeleportResearchLab
	msgbox MobileLab_Text_AbraNormal, MSGBOX_DEFAULT
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	waitmoncry
	msgbox MobileLab_Text_Abra, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

MobileLab_EventScript_AbraTeleportDeclined::
	lockall
	faceplayer
	msgbox MobileLab_Text_NoTeleport, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

MobileLab_EventScript_AbraTeleportMobileLab::
	lockall
	faceplayer
	msgbox MobileLab_Text_AbraWantTeleport, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MobileLab_EventScript_AbraTeleportDeclined
	msgbox MobileLab_Text_AbraTeleport, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	playmoncry SPECIES_ABRA, CRY_MODE_HIGH_PITCH
	warpteleport MAP_MOBILE_LAB, 4, 5
	end

MobileLab_EventScript_AbraTeleportResearchLab::
	lockall
	faceplayer
	msgbox MobileLab_Text_AbraWantTeleport, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MobileLab_EventScript_AbraTeleportDeclined
	msgbox MobileLab_Text_AbraTeleport, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	playmoncry SPECIES_ABRA, CRY_MODE_HIGH_PITCH
	warpteleport MAP_RESEARCH_LAB, 9, 12
	end

MobileLab_Text_AbraTeleport:
	.string "BRA ABRA AB!$"

MobileLab_Text_AbraNormal:
	.string "ABRA AB ABRA$"

MobileLab_Text_Abra:
	.string "ABRA seems to be waiting.$"

MobileLab_Text_AbraWantTeleport:
	.string "Do you want ABRA to teleport you?$"

MobileLab_Text_NoTeleport:
	.string "You decided not to.$"
