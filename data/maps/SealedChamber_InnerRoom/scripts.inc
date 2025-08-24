SealedChamber_InnerRoom_MapScripts::
	.byte 0

SealedChamber_InnerRoom_EventScript_BrailleBackWall::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_InnerRoom_Braille_DecodeFirstWailordLastRelicanth
	goto_if_set FLAG_REGI_DOORS_OPENED, SealedChamber_InnerRoom_EventScript_NoEffect
	specialvar VAR_RESULT, CheckRelicanthWailord
	goto_if_eq VAR_RESULT, FALSE, SealedChamber_InnerRoom_EventScript_NoEffect
	fadeoutbgm 0
	updatequest QUEST_GIGANTIC_FINDINGS, VAR_GIGANTIC_FINDINGS
	playse SE_TRUCK_MOVE
	special DoSealedChamberShakingEffect_Long
	waitstate
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	msgbox gText_DoorOpenedFarAway, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setflag FLAG_REGI_DOORS_OPENED
	clearflag FLAG_HIDE_ABRA_ROUTE105
	clearflag FLAG_HIDE_MOBILE_LAB_ROUTE111
	clearflag FLAG_HIDE_MOBILE_LAB_ROUTE120
	releaseall
	end

SealedChamber_InnerRoom_EventScript_NoEffect::
	releaseall
	end

SealedChamber_InnerRoom_Braille_DecodeFirstWailordLastRelicanth::
	msgbox SealedChamber_InnerRoom_Text_FirstWailordLastRelicanth, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_InnerRoom_EventScript_BrailleStoryPart1::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_InnerRoom_EventScript_DecodeInThisCaveWeHaveLived
	releaseall
	end

SealedChamber_InnerRoom_EventScript_DecodeInThisCaveWeHaveLived::
	msgbox SealedChamber_InnerRoom_Text_InThisCaveWeHaveLived, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_InnerRoom_EventScript_BrailleStoryPart2::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_InnerRoom_EventScript_DecodeWeOweAllToThePokemon
	releaseall
	end

SealedChamber_InnerRoom_EventScript_DecodeWeOweAllToThePokemon::
	msgbox SealedChamber_InnerRoom_Text_WeOweAllToThePokemon, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_InnerRoom_EventScript_BrailleStoryPart3::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_InnerRoom_EventScript_DecodeButWeSealedThePokemonAway
	releaseall
	end

SealedChamber_InnerRoom_EventScript_DecodeButWeSealedThePokemonAway::
	msgbox SealedChamber_InnerRoom_Text_ButWeSealedThePokemonAway, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_InnerRoom_EventScript_BrailleStoryPart4::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_WeFearedIt
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_InnerRoom_EventScript_DecodeWeFearedIt
	releaseall
	end

SealedChamber_InnerRoom_EventScript_DecodeWeFearedIt::
	msgbox SealedChamber_InnerRoom_Text_WeFearedIt, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_InnerRoom_EventScript_BrailleStoryPart5::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_ThoseWithCourageHope
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_InnerRoom_EventScript_DecodeThoseWithCourageHope
	releaseall
	end

SealedChamber_InnerRoom_EventScript_DecodeThoseWithCourageHope::
	msgbox SealedChamber_InnerRoom_Text_ThoseWithCourageHope, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_InnerRoom_EventScript_BrailleStoryPart6::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_InnerRoom_EventScript_DecodeOpenDoorEternalPokemonWaits
	releaseall
	end

SealedChamber_InnerRoom_EventScript_DecodeOpenDoorEternalPokemonWaits::
	msgbox SealedChamber_InnerRoom_Text_OpenDoorEternalPokemonWaits, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_InnerRoom_Text_FirstWailordLastRelicanth:
	.string "FIRST COMES WAILORD.\n"
	.string "LAST COMES RELICANTH.$"

SealedChamber_InnerRoom_Text_InThisCaveWeHaveLived:
	.string "IN THIS CAVE\n"
	.string "WE HAVE LIVED.$"

SealedChamber_InnerRoom_Text_WeOweAllToThePokemon:
	.string "WE OWE ALL\n"
	.string "TO THE POKEMON.$"

SealedChamber_InnerRoom_Text_ButWeSealedThePokemonAway:
	.string "BUT WE SEALED,\n"
	.string "THE POKEMON AWAY.$"

SealedChamber_InnerRoom_Text_WeFearedIt:
	.string "WE FEARED IT.$"

SealedChamber_InnerRoom_Text_ThoseWithCourageHope:
	.string "THOSE WITH COURGAE,\n"
	.string "THOSE WITH HOPE.$"

SealedChamber_InnerRoom_Text_OpenDoorEternalPokemonWaits:
	.string "OPEN A DOOR.\n"
	.string "AN ETERNAL POKEMON WAITS.$"
