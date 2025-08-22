ResearchLab_MapScripts::
	.byte 0

ResearchLab_Movement_Call::
	walk_left
	walk_left
	walk_left
	walk_up
	face_up
	delay_8
	walk_in_place_slow_up
	delay_16
	walk_in_place_fast_up
	delay_16
	emote_exclamation_mark
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_down
	walk_right
	walk_right
	walk_right
	face_player
	step_end

ResearchLab_Movement_Call_Player::
	walk_down
	face_up
	delay_8
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	face_right
	step_end

ResearchLab_EventScript_Machine_Scientist1::
	lock
	faceplayer
	msgbox ResearchLab_Text_Machine_Work1, MSGBOX_DEFAULT
	release
	end

ResearchLab_EventScript_Machine_Scientist2::
	lock
	faceplayer
	msgbox ResearchLab_Text_Machine_Work2, MSGBOX_DEFAULT
	release
	end

ResearchLab_EventScript_Machine2_Scientist1::
	lock
	faceplayer
	msgbox ResearchLab_Text_Machine2_Work1, MSGBOX_DEFAULT
	release
	end

ResearchLab_EventScript_Machine2_Scientist2::
	lock
	faceplayer
	msgbox ResearchLab_Text_Machine2_Work2, MSGBOX_DEFAULT
	release
	end

ResearchLab_EventScript_PC_Scientist1::
	goto_if_subquest_complete QUEST_GIGANTIC_FINDINGS, SUB_QUEST_SEALED_DEPTHS, ResearchLab_EventScript_PC_Scientist1_DecoderUse
	lock
	faceplayer
	msgbox ResearchLab_Text_Pc_Work1, MSGBOX_DEFAULT
	goto_if_quest_active QUEST_GIGANTIC_FINDINGS, ResearchLab_EventScript_PC_Scientist1_Decoder
	release
	end

ResearchLab_EventScript_PC_Scientist1_Decoder::
	goto_if_subquest_complete QUEST_GIGANTIC_FINDINGS, SUB_QUEST_SEALED_DEPTHS, ResearchLab_EventScript_PC_Scientist1_DecoderUse
	lock
	faceplayer
	msgbox ResearchLab_Text_Pc_GiveDecoder, MSGBOX_DEFAULT
	setflag FLAG_RECIEVED_BRAILLE_DECODER
	release
	end

ResearchLab_EventScript_PC_Scientist1_DecoderUse::
	lock
	faceplayer
	msgbox ResearchLab_Text_Pc_UsingDecoder, MSGBOX_DEFAULT
	release
	end

ResearchLab_EventScript_PC_Scientist2::
	lock
	msgbox ResearchLab_Text_Pc_Work2, MSGBOX_DEFAULT
	release
	end

ResearchLab_EventScript_Head_Scientist::
	lock
	goto_if_quest_active QUEST_GIGANTIC_FINDINGS, ResearchLab_EventScript_Progress
	goto_if_quest_complete QUEST_GIGANTIC_FINDINGS, ResearchLab_EventScript_GreatThanks
	msgbox ResearchLab_Text_NeedAid, MSGBOX_DEFAULT
	waitmessage
	closemessage
	faceplayer
	msgbox ResearchLab_Text_WillingToHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ResearchLab_EventScript_StartHelping
	goto_if_eq VAR_RESULT, NO, ResearchLab_EventScript_DontStartHelping
	release
	end

ResearchLab_EventScript_StartHelping::
	lock
	faceplayer
	msgbox ResearchLab_Text_ManyThanks, MSGBOX_DEFAULT
	waitmessage
	closemessage
	startquest QUEST_GIGANTIC_FINDINGS
	subquestmenu QUEST_MENU_SET_ACTIVE, QUEST_GIGANTIC_FINDINGS, SUB_QUEST_SEALED_DEPTHS
	release
	end

ResearchLab_EventScript_Progress::
	lock
	faceplayer
	msgbox ResearchLab_Text_HowsLooking, MSGBOX_DEFAULT
	waitmessage
	closemessage
	call_if_unset FLAG_RETURNED_SEALED_CHAMBER, ResearchLab_Quest_SealedChamber_State
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, ResearchLab_Quest_NotingSelected
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_REGIROCK, ResearchLab_Quest_DesertRuins
	goto_if_eq VAR_RESULT, SPECIES_REGICE, ResearchLab_Quest_IslandCave
	goto_if_eq VAR_RESULT, SPECIES_REGISTEEL, ResearchLab_Quest_AncientTomb
	goto ResearchLab_Quest_NotRight
	release
	end

ResearchLab_Quest_NotRight::
	msgbox ResearchLab_Text_NotRight, MSGBOX_DEFAULT
	closemessage
	end

ResearchLab_Quest_SealedChamber_State::
	goto_if_subquest_complete QUEST_GIGANTIC_FINDINGS, SUB_QUEST_SEALED_DEPTHS, ResearchLab_Quest_SealedChamber_Seen
	goto_if_subquest_not_complete QUEST_GIGANTIC_FINDINGS, SUB_QUEST_SEALED_DEPTHS, ResearchLab_Quest_SealedChamber_Unseen
	return

ResearchLab_Quest_SealedChamber_Unseen::
	lock
	faceplayer
	msgbox ResearchLab_Text_HaventGone, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

ResearchLab_Quest_SealedChamber_Seen::
	lock
	faceplayer
	msgbox ResearchLab_Text_YoureBack, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement VAR_LAST_TALKED, ResearchLab_Movement_Call
	waitmovement
	faceplayer
	msgbox ResearchLab_Text_FieldTrip, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setflag FLAG_RETURNED_SEALED_CHAMBER
	subquestmenu QUEST_MENU_SET_ACTIVE QUEST_GIGANTIC_FINDINGS SUB_QUEST_RUINS_IN_THE_SANDS
	subquestmenu QUEST_MENU_SET_ACTIVE QUEST_GIGANTIC_FINDINGS SUB_QUEST_CAVE_OF_SOLITUDE
	subquestmenu QUEST_MENU_SET_ACTIVE QUEST_GIGANTIC_FINDINGS SUB_QUEST_TOMB_OF_THE_ANCIENTS
	release
	end

ResearchLab_Quest_DesertRuins::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_REGIROCK
	showmonpic SPECIES_REGIROCK, 10, 3
	playmoncry SPECIES_REGIROCK, CRY_MODE_NORMAL
	waitmoncry
	hidemonpic
	msgbox ResearchLab_Text_ThatPokemon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	completesubquest QUEST_GIGANTIC_FINDINGS SUB_QUEST_RUINS_IN_THE_SANDS
	release
	end

ResearchLab_Quest_IslandCave::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_REGICE
	showmonpic SPECIES_REGICE, 10, 3
	playmoncry SPECIES_REGICE, CRY_MODE_NORMAL
	waitmoncry
	hidemonpic
	msgbox ResearchLab_Text_ThatPokemon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	completesubquest QUEST_GIGANTIC_FINDINGS SUB_QUEST_CAVE_OF_SOLITUDE
	release
	end

ResearchLab_Quest_AncientTomb::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_REGISTEEL
	showmonpic SPECIES_REGISTEEL, 10, 3
	playmoncry SPECIES_REGISTEEL, CRY_MODE_NORMAL
	waitmoncry
	hidemonpic
	msgbox ResearchLab_Text_ThatPokemon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	completesubquest QUEST_GIGANTIC_FINDINGS SUB_QUEST_TOMB_OF_THE_ANCIENTS
	release
	end

ResearchLab_Quest_NotingSelected::
	msgbox ResearchLab_Text_NothingToShow, MSGBOX_DEFAULT
	release
	end

ResearchLab_EventScript_GreatThanks::
	lock
	faceplayer
	msgbox ResearchLab_Text_GreatThanks, MSGBOX_DEFAULT
	release
	end

ResearchLab_EventScript_DontStartHelping::
	lock
	faceplayer
	msgbox ResearchLab_Text_KeepLooking, MSGBOX_DEFAULT
	release
	end

ResearchLab_Text_Machine_Work1:
	.string "WHAT!? CAN YOU SPEAK UP!\n"
	.string "THESE GENERATORS POWERS THIS LAB!\p"
	.string "SADLY, THEY ARE VERY LOUD UP CLOSE!$"

ResearchLab_Text_Machine_Work2:
	.string "SORRY! IT'S VERY LOUD OVER HERE,\n"
	.string "SO I CAN'T HEAR YOU CLEARLY!\p"
	.string "DO YOU NOT HAVE A RADIO OR SOMETHING?!$"

ResearchLab_Text_Machine2_Work1:
	.string "This machine helps keeps us afloat.\p"
	.string "Thankfully it's not a loud as those\n"
	.string "ones in the back.$"

ResearchLab_Text_Machine2_Work2:
	.string "This machine allows us to monitor the\n"
	.string "SEALED CHAMBER. Which seems to be\p"
	.string "emitting some kind of energy.$"

ResearchLab_Text_Pc_Work1:
	.string "I'm working on a device that will allow\n"
	.string "one to decode the strange markings in\p"
	.string "the SEALED CHAMBER without a guide.$"

ResearchLab_Text_Pc_GiveDecoder:
	.string "You're going to the SEALED CHAMBER?\n"
	.string "I've finished the decoder for the\p"
	.string "markings down there.\n"
	.string "I call it the BRAILLE DECODER!$"

ResearchLab_Text_Pc_UsingDecoder:
	.string "Is the BRAILLE DECODER working well?\n"
	.string "It is, that's good to hear.$"

ResearchLab_Text_Pc_Work2:
	.string "He seems to be busy coding something.\p"
	.string "… … …\p"
	.string "Best to leave him alone.$"

ResearchLab_Text_NeedAid:
	.string "We're researching the SEALED CHAMBER,\n"
	.string "that we found under ROUTE 134.\p"
	.string "Though none of us are really trainers,\n"
	.string "so we are in need of help from one.$"

ResearchLab_Text_WillingToHelp:
	.string "Wait, are you a POkéMON TRAINER?\n"
	.string "Will you be willing to help us?$"

ResearchLab_Text_ManyThanks:
	.string "Thank you! What's your name?\n"
	.string "… … …\p"
	.string "{PLAYER}, alright, you can speak to my\n"
	.string "teammate over there to get a prototype\p"
	.string "decoding device, as you'll need it to\n"
	.string "decode the SEALED CHAMBER's messages.$"

ResearchLab_Text_HowsLooking:
	.string "{PLAYER}, how's it going?\n"
	.string "Got anything to share?$"

ResearchLab_Text_HaventGone:
	.string "{PLAYER}, you haven't been to the\n"
	.string "SEALED CHAMBER yet?$"

ResearchLab_Text_YoureBack:
	.string "{PLAYER}, you're back!\n"
	.string "Did you feel that earthquake?\p"
	.string "… … …\p"
	.string "Wait!? You were the cause of it!?\p"
	.string "… … …\p"
	.string "Give me a moment, got a call coming in.$"

ResearchLab_Text_FieldTrip:
	.string "{PLAYER}, huge news!\n"
	.string "My field researchers have reported\p"
	.string "that doors have suddenly appeared\n"
	.string "in the ancient monuments located\p"
	.string "across the Hoenn region!\n"
	.string "How soon are you able to investigate?\p"
	.string "… … …\p"
	.string "Alright, I'll let them know that you're\n"
	.string "on the way to them.$"

ResearchLab_Text_GreatThanks:
	.string "{PLAYER}, thank you for your help!\n"
	.string "You have provided a ton of information\p"
	.string "about the SEALED CHAMBER and the\n"
	.string "3 GIANTS of Hoenn's legends.$"

ResearchLab_Text_ThatPokemon:
	.string "That POKéMON!\p"
	.string "It that an actual {STR_VAR_1}?\n"
	.string "It is!? This is a huge breakthrough!$"

ResearchLab_Text_KeepLooking:
	.string "Oh, ok. I'll keep looking.$"

ResearchLab_Text_NothingToShow:
	.string "Don't have anything to show?$"

ResearchLab_Text_NotRight:
	.string "{PLAYER}, this isn't the right POKéMON.$"
