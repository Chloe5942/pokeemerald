SealedChamber_OuterRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SealedChamber_OuterRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SealedChamber_OuterRoom_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SealedChamber_OuterRoom_OnLoad
	.byte 0

SealedChamber_OuterRoom_OnResume:
	setdivewarp MAP_UNDERWATER_SEALED_CHAMBER, 12, 44
	setescapewarp MAP_UNDERWATER_SEALED_CHAMBER, 12, 44
	end

SealedChamber_OuterRoom_OnTransition:
	setflag FLAG_LANDMARK_SEALED_CHAMBER
	end

SealedChamber_OuterRoom_OnLoad:
	call_if_unset FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance
	end

SealedChamber_OuterRoom_EventScript_CloseInnerRoomEntrance::
	setmetatile 9, 1, METATILE_Cave_EntranceCover, TRUE
	setmetatile 10, 1, METATILE_Cave_EntranceCover, TRUE
	setmetatile 11, 1, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 10, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 11, 2, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

SealedChamber_OuterRoom_EventScript_BrailleABC::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_ABC
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodeABC
	releaseall
	end

SealedChamber_OuterRoom_EventScript_DecodeABC::
	msgbox SealedChamber_OuterRoom_Text_ABC, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_OuterRoom_EventScript_BrailleGHI::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_GHI
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodeGHI
	releaseall
	end

SealedChamber_OuterRoom_EventScript_DecodeGHI::
	msgbox SealedChamber_OuterRoom_Text_GHI, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_OuterRoom_EventScript_BrailleMNO::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_MNO
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodeMNO
	releaseall
	end

SealedChamber_OuterRoom_EventScript_DecodeMNO::
	msgbox SealedChamber_OuterRoom_Text_MNO, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_OuterRoom_EventScript_BrailleTUV::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_TUV
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodeTUV
	releaseall
	end

SealedChamber_OuterRoom_EventScript_DecodeTUV::
	msgbox SealedChamber_OuterRoom_Text_TUV, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_OuterRoom_EventScript_BrailleDEF::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_DEF
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodeDEF
	releaseall
	end

SealedChamber_OuterRoom_EventScript_DecodeDEF::
	msgbox SealedChamber_OuterRoom_Text_DEF, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_OuterRoom_EventScript_BrailleJKL::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_JKL
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodeJKL
	releaseall
	end

SealedChamber_OuterRoom_EventScript_DecodeJKL::
	msgbox SealedChamber_OuterRoom_Text_JKL, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_OuterRoom_EventScript_BraillePQRS::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_PQRS
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodePQRS
	releaseall
	end

SealedChamber_OuterRoom_EventScript_DecodePQRS::
	msgbox SealedChamber_OuterRoom_Text_PQRS, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_OuterRoom_EventScript_BraillePeriod::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_Period
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodePeriod
	releaseall
	end

SealedChamber_OuterRoom_EventScript_DecodePeriod::
	msgbox SealedChamber_OuterRoom_Text_Period, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_OuterRoom_EventScript_BrailleWXYZ::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_WXYZ
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodeWXYZ
	releaseall
	end

SealedChamber_OuterRoom_EventScript_DecodeWXYZ::
	msgbox SealedChamber_OuterRoom_Text_WXYZ, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_OuterRoom_EventScript_BrailleComma::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_Comma
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodeComma
	releaseall
	end

SealedChamber_OuterRoom_EventScript_DecodeComma::
	msgbox SealedChamber_OuterRoom_Text_Comma, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_OuterRoom_EventScript_InnerRoomEntranceWall::
	lockall
	goto_if_set FLAG_SYS_BRAILLE_DIG, SealedChamber_OuterRoom_EventScript_HoleInWall
	braillemsgbox SealedChamber_OuterRoom_Braille_DigHere
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodeDigHere
	releaseall
	end

SealedChamber_OuterRoom_EventScript_HoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

SealedChamber_OuterRoom_EventScript_BrailleDigHere::
	lockall
	braillemsgbox SealedChamber_OuterRoom_Braille_DigHere
	call_if_set FLAG_RECIEVED_BRAILLE_DECODER, SealedChamber_OuterRoom_EventScript_DecodeDigHere
	releaseall
	end

SealedChamber_OuterRoom_EventScript_DecodeDigHere::
	msgbox SealedChamber_OuterRoom_Text_DigHere, MSGBOX_DEFAULT
	waitmessage
	return

SealedChamber_OuterRoom_Text_ABC:
	.string "A B C$"

SealedChamber_OuterRoom_Text_DEF:
	.string "D E F$"

SealedChamber_OuterRoom_Text_GHI:
	.string "G H I$"

SealedChamber_OuterRoom_Text_JKL:
	.string "J K L$"

SealedChamber_OuterRoom_Text_MNO:
	.string "M N O$"

SealedChamber_OuterRoom_Text_PQRS:
	.string "P Q R S$"

SealedChamber_OuterRoom_Text_TUV:
	.string "T U V$"

SealedChamber_OuterRoom_Text_WXYZ:
	.string "W X Y Z$"

SealedChamber_OuterRoom_Text_DigHere:
	.string "DIG HERE.$"

SealedChamber_OuterRoom_Text_Comma:
	.string ",$"

SealedChamber_OuterRoom_Text_Period:
	.string ".$"
