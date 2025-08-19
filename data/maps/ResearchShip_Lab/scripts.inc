ResearchShip_Lab_MapScripts::
	.byte 0

ResearchShip_Lab_Movement_Call::
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

ResearchShip_Lab_Movement_Call_Player::
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

ResearchShip_Lab_EventScript_Machine_Scientist1::
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_Machine_Work1, MSGBOX_DEFAULT
	release
	end

ResearchShip_Lab_EventScript_Machine_Scientist2::
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_Machine_Work2, MSGBOX_DEFAULT
	release
	end

ResearchShip_Lab_EventScript_Machine2_Scientist1::
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_Machine2_Work1, MSGBOX_DEFAULT
	release
	end

ResearchShip_Lab_EventScript_Machine2_Scientist2::
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_Machine2_Work2, MSGBOX_DEFAULT
	release
	end

ResearchShip_Lab_EventScript_PC_Scientist1::
	goto_if_quest_complete QUEST_SEALED_DEPTHS, ResearchShip_Lab_EventScript_PC_Scientist1_DecoderUse
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_Pc_Work1, MSGBOX_DEFAULT
	goto_if_set FLAG_GIGANTIC_FINDINGS_STARTED, ResearchShip_Lab_EventScript_PC_Scientist1_Decoder
	release
	end

ResearchShip_Lab_EventScript_PC_Scientist1_Decoder::
	goto_if_quest_complete QUEST_SEALED_DEPTHS, ResearchShip_Lab_EventScript_PC_Scientist1_DecoderUse
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_Pc_GiveDecoder, MSGBOX_DEFAULT
	setflag FLAG_RECIEVED_BRAILLE_DECODER
	release
	end

ResearchShip_Lab_EventScript_PC_Scientist1_DecoderUse::
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_Pc_UsingDecoder, MSGBOX_DEFAULT
	release
	end

ResearchShip_Lab_EventScript_PC_Scientist2::
	lock
	msgbox ResearchShip_Lab_Text_Pc_Work2, MSGBOX_DEFAULT
	release
	end

ResearchShip_Lab_EventScript_Head_Scientist::
	lock
	goto_if_set FLAG_GIGANTIC_FINDINGS_STARTED, ResearchShip_Lab_EventScript_Progress
	goto_if_set FLAG_GIGANTIC_FINDINGS_FINISHED, ResearchShip_Lab_EventScript_GreatThanks
	msgbox ResearchShip_Lab_Text_NeedAid, MSGBOX_DEFAULT
	waitmessage
	closemessage
	faceplayer
	msgbox ResearchShip_Lab_Text_WillingToHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ResearchShip_Lab_EventScript_StartHelping
	goto_if_eq VAR_RESULT, NO, ResearchShip_Lab_EventScript_DontStartHelping
	release
	end

ResearchShip_Lab_EventScript_StartHelping::
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_ManyThanks, MSGBOX_DEFAULT
	waitmessage
	closemessage
	startquest QUEST_SEALED_DEPTHS
	setflag FLAG_GIGANTIC_FINDINGS_STARTED
	release
	end

ResearchShip_Lab_EventScript_Progress::
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_HowsLooking, MSGBOX_DEFAULT
	waitmessage
	closemessage
	call_if_unset FLAG_RETURNED_SEALED_CHAMBER, ResearchShip_Lab_Quest_SealedChamber_State
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x8004, VAR_TEMP_E
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, ResearchShip_Lab_Quest_RegiCheck
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, ResearchShip_Lab_Quest_NotingSelected
	release
	end

ResearchShip_Lab_Quest_RegiCheck::
	goto_if_eq VAR_TEMP_E, SPECIES_REGIROCK, ResearchShip_Lab_Quest_DesertRuins
	goto_if_eq VAR_TEMP_E, SPECIES_REGICE, ResearchShip_Lab_Quest_IslandCave
	goto_if_eq VAR_TEMP_E, SPECIES_REGISTEEL, ResearchShip_Lab_Quest_AncientTomb
	msgbox ResearchShip_Lab_Text_NotRight, MSGBOX_DEFAULT
	closemessage
	end

ResearchShip_Lab_Quest_SealedChamber_State::
	goto_if_quest_complete QUEST_SEALED_DEPTHS, ResearchShip_Lab_Quest_SealedChamber_Seen
	goto_if_quest_not_complete QUEST_SEALED_DEPTHS, ResearchShip_Lab_Quest_SealedChamber_Unseen
	return

ResearchShip_Lab_Quest_SealedChamber_Unseen::
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_HaventGone, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

ResearchShip_Lab_Quest_SealedChamber_Seen::
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_YoureBack, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement VAR_LAST_TALKED, ResearchShip_Lab_Movement_Call
	waitmovement
	faceplayer
	msgbox ResearchShip_Lab_Text_FieldTrip, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setflag FLAG_RETURNED_SEALED_CHAMBER
	startquest QUEST_RUINS_IN_THE_SANDS
	startquest QUEST_CAVE_OF_SOLITUDE
	startquest QUEST_TOMB_OF_THE_ANCIENTS
	release
	end

ResearchShip_Lab_Quest_DesertRuins::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_REGIROCK
	showmonpic SPECIES_REGIROCK, 10, 3
	playmoncry SPECIES_REGIROCK, CRY_MODE_NORMAL
	waitmoncry
	hidemonpic
	msgbox ResearchShip_Lab_Text_ThatPokemon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	completequest QUEST_RUINS_IN_THE_SANDS
	release
	end

ResearchShip_Lab_Quest_IslandCave::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_REGICE
	showmonpic SPECIES_REGICE, 10, 3
	playmoncry SPECIES_REGICE, CRY_MODE_NORMAL
	waitmoncry
	hidemonpic
	msgbox ResearchShip_Lab_Text_ThatPokemon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	completequest QUEST_CAVE_OF_SOLITUDE
	release
	end

ResearchShip_Lab_Quest_AncientTomb::
	lock
	faceplayer
	bufferspeciesname STR_VAR_1, SPECIES_REGISTEEL
	showmonpic SPECIES_REGISTEEL, 10, 3
	playmoncry SPECIES_REGISTEEL, CRY_MODE_NORMAL
	waitmoncry
	hidemonpic
	msgbox ResearchShip_Lab_Text_ThatPokemon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	completequest QUEST_TOMB_OF_THE_ANCIENTS
	release
	end

ResearchShip_Lab_Quest_NotingSelected::
	msgbox ResearchShip_Lab_Text_NothingToShow, MSGBOX_DEFAULT
	release
	end

ResearchShip_Lab_EventScript_GreatThanks::
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_GreatThanks, MSGBOX_DEFAULT
	release
	end

ResearchShip_Lab_EventScript_DontStartHelping::
	lock
	faceplayer
	msgbox ResearchShip_Lab_Text_KeepLooking, MSGBOX_DEFAULT
	release
	end

ResearchShip_Lab_Text_Machine_Work1:
	.string "WHAT!? CAN YOU SPEAK UP!\n"
	.string "THESE 3 GENERATORS POWERS THE SHIP!\p"
	.string "SADLY, THEY ARE VERY LOUD UP CLOSE!$"

ResearchShip_Lab_Text_Machine_Work2:
	.string "SORRY! IT'S VERY LOUD OVER HERE,\n"
	.string "SO I CAN'T HEAR YOU CLEARLY!\p"
	.string "DO YOU NOT HAVE A RADIO OR SOMETHING?!$"

ResearchShip_Lab_Text_Machine2_Work1:
	.string "This machine helps keeps us afloat.\p"
	.string "Thankfully it's not a loud as those\n"
	.string "ones in the back.$"

ResearchShip_Lab_Text_Machine2_Work2:
	.string "This machine allows us to monitor the\n"
	.string "SEALED CHAMBER. Which seems to be\p"
	.string "emitting some kind of energy.$"

ResearchShip_Lab_Text_Pc_Work1:
	.string "I'm working on a device that will allow\n"
	.string "one to decode the strange markings in\p"
	.string "the SEALED CHAMBER without a guide.$"

ResearchShip_Lab_Text_Pc_GiveDecoder:
	.string "You're going to the SEALED CHAMBER?\n"
	.string "I've finished the decoder for the\p"
	.string "markings down there.\n"
	.string "I call it the BRAILLE DECODER!$"

ResearchShip_Lab_Text_Pc_UsingDecoder:
	.string "Is the BRAILLE DECODER working well?\n"
	.string "It is, that's good to hear.$"

ResearchShip_Lab_Text_Pc_Work2:
	.string "He seems to be busy coding something.\p"
	.string "… … …\p"
	.string "Best to leave him alone.$"

ResearchShip_Lab_Text_NeedAid:
	.string "We're researching the SEALED CHAMBER,\n"
	.string "that we found under ROUTE 134.\p"
	.string "Though none of us are really trainers,\n"
	.string "so we are in need of help from one.$"

ResearchShip_Lab_Text_WillingToHelp:
	.string "Wait, are you a POkéMON TRAINER?\n"
	.string "Will you be willing to help us?$"

ResearchShip_Lab_Text_ManyThanks:
	.string "Thank you! What's your name?\n"
	.string "… … …\p"
	.string "{PLAYER}, alright, you can speak to my\n"
	.string "teammate over there to get a prototype\p"
	.string "decoding device, as you'll need it to\n"
	.string "decode the SEALED CHAMBER's messages.$"

ResearchShip_Lab_Text_HowsLooking:
	.string "{PLAYER}, how's it going?\n"
	.string "Got anything to share?$"

ResearchShip_Lab_Text_HaventGone:
	.string "{PLAYER}, you haven't been to the\n"
	.string "SEALED CHAMBER yet?$"

ResearchShip_Lab_Text_YoureBack:
	.string "{PLAYER}, you're back!\n"
	.string "Did you feel that earthquake?\p"
	.string "… … …\p"
	.string "Wait!? You were the cause of it!?\p"
	.string "… … …\p"
	.string "Give me a moment, got a call coming in.$"

ResearchShip_Lab_Text_FieldTrip:
	.string "{PLAYER}, huge news!\n"
	.string "My field researchers have reported\p"
	.string "that doors have suddenly appeared\n"
	.string "in the ancient monuments located\p"
	.string "across the Hoenn region!\n"
	.string "How soon are you able to investigate?\p"
	.string "… … …\p"
	.string "Alright, I'll let them know that you're\n"
	.string "on the way to them.$"

ResearchShip_Lab_Text_GreatThanks:
	.string "{PLAYER}, thank you for your help!\n"
	.string "You have provided a ton of information\p"
	.string "about the SEALED CHAMBER and the\n"
	.string "3 GIANTS of Hoenn's legends.$"

ResearchShip_Lab_Text_ThatPokemon:
	.string "That POKéMON!\p"
	.string "It that an actual {STR_VAR_1}?\n"
	.string "It is!? This is a huge breakthrough!$"

ResearchShip_Lab_Text_KeepLooking:
	.string "Oh, ok. I'll keep looking.$"

ResearchShip_Lab_Text_NothingToShow:
	.string "Don't have anything to show?$"

ResearchShip_Lab_Text_NotRight:
	.string "{PLAYER}, this isn't the right POKéMON.$"
