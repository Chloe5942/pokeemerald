EventScript_Bench_Left::
	lock
	applymovement LOCALID_PLAYER, TimeSkipping_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_FOLLOWING_POKEMON, TimeSkipping_Movement_SitRight
	msgbox TimeSkipping_Text_Bench, MSGBOX_DEFAULT
	waitmessage
	msgbox TimeSkipping_Text_Wait, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, TimeSkipping_EventScript_Bench_AskHowLong
	case NO, TimeSkipping_EventScript_Declined
	release
	end

EventScript_Bench_Right::
	lock
	applymovement LOCALID_PLAYER, TimeSkipping_Movement_FaceDown
	waitmovement 0
	applymovement LOCALID_FOLLOWING_POKEMON, TimeSkipping_Movement_SitLeft
	msgbox TimeSkipping_Text_Bench, MSGBOX_DEFAULT
	waitmessage
	msgbox TimeSkipping_Text_Wait, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, TimeSkipping_EventScript_Bench_AskHowLong
	case NO, TimeSkipping_EventScript_Declined
	release
	end

TimeSkipping_EventScript_Bench_AskHowLong::
	lock
	msgbox TimeSkipping_Text_HowLong, MSGBOX_DEFAULT
	dynmultipush TimeSkipping_Text_OneHour, 0
	dynmultipush TimeSkipping_Text_TwoHours, 1
	dynmultipush TimeSkipping_Text_ThreeHours, 2
	dynmultipush TimeSkipping_Text_FourHours, 3
	dynmultipush TimeSkipping_Text_FiveHours, 4
	dynmultipush TimeSkipping_Text_SixHours, 5
	dynmultipush TimeSkipping_Text_SevenHours, 6
	dynmultipush TimeSkipping_Text_EightHours, 7
	dynmultipush TimeSkipping_Text_NineHours, 8
	dynmultipush TimeSkipping_Text_TenHours, 9
	dynmultipush TimeSkipping_Text_ElevenHours, 10
	dynmultipush TimeSkipping_Text_TwelveHours, 11
	dynmultipush TimeSkipping_Text_ThirteenHours, 12
	dynmultipush TimeSkipping_Text_FourteenHours, 13
	dynmultipush TimeSkipping_Text_FifteenHours, 14
	dynmultipush TimeSkipping_Text_SixteenHours, 15
	dynmultipush TimeSkipping_Text_SeventeenHours, 16
	dynmultipush TimeSkipping_Text_EighteenHours, 17
	dynmultipush TimeSkipping_Text_NinteenHours, 18
	dynmultipush TimeSkipping_Text_TwentyHours, 19
	dynmultipush TimeSkipping_Text_TwentyOneHours, 20
	dynmultipush TimeSkipping_Text_TwentyTwoHours, 21
	dynmultipush TimeSkipping_Text_TwentyThreeHours, 22
	dynmultipush TimeSkipping_Text_TwentyFourHours, 23
	dynmultipush TimeSkipping_Text_Cancel, 24
	dynmultistack 19, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, TimeSkipping_EventScript_BenchWaiting
	case 1, TimeSkipping_EventScript_BenchWaiting
	case 2, TimeSkipping_EventScript_BenchWaiting
	case 3, TimeSkipping_EventScript_BenchWaiting
	case 4, TimeSkipping_EventScript_BenchWaiting
	case 5, TimeSkipping_EventScript_BenchWaiting
	case 6, TimeSkipping_EventScript_BenchWaiting
	case 7, TimeSkipping_EventScript_BenchWaiting
	case 8, TimeSkipping_EventScript_BenchWaiting
	case 9, TimeSkipping_EventScript_BenchWaiting
	case 10, TimeSkipping_EventScript_BenchWaiting
	case 11, TimeSkipping_EventScript_BenchWaiting
	case 12, TimeSkipping_EventScript_BenchWaiting
	case 13, TimeSkipping_EventScript_BenchWaiting
	case 14, TimeSkipping_EventScript_BenchWaiting
	case 15, TimeSkipping_EventScript_BenchWaiting
	case 16, TimeSkipping_EventScript_BenchWaiting
	case 17, TimeSkipping_EventScript_BenchWaiting
	case 18, TimeSkipping_EventScript_BenchWaiting
	case 19, TimeSkipping_EventScript_BenchWaiting
	case 20, TimeSkipping_EventScript_BenchWaiting
	case 21, TimeSkipping_EventScript_BenchWaiting
	case 22, TimeSkipping_EventScript_BenchWaiting
	case 23, TimeSkipping_EventScript_BenchWaiting
	case 24, TimeSkipping_EventScript_Declined
	case MULTI_B_PRESSED, TimeSkipping_EventScript_Declined
	release
	end

TimeSkipping_EventScript_Declined::
	lock
	closemessage
	applymovement LOCALID_PLAYER, TimeSkipping_Movement_WalkDown
	waitmovement
	applymovement LOCALID_FOLLOWING_POKEMON, TimeSkipping_Movement_WalkDown
	waitmovement
	msgbox TimeSkipping_Text_Declined, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

TimeSkipping_EventScript_BenchWaiting::
	lock
	special HealLeadMon
	special WaitOnBench
	bufferpartymonnick STR_VAR_1, 0
	copyvar VAR_0x8004, VAR_RESULT
	buffernumberstring STR_VAR_2, VAR_0x8004
	fadescreenswapbuffers FADE_TO_BLACK
	special Special_ViewWallClock
	delay 10
	goto TimeSkipping_EventScript_BenchWaitingPost
	end

TimeSkipping_EventScript_BenchWaitingPost::
	lock
	applymovement LOCALID_PLAYER, TimeSkipping_Movement_WalkDown
	applymovement LOCALID_FOLLOWING_POKEMON, TimeSkipping_Movement_WalkDown
	waitmovement
	bufferpartymonnick STR_VAR_1, 0
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	buffernumberstring STR_VAR_2, VAR_0x8004
	msgbox TimeSkipping_Text_BenchWaiting, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

EventScript_Bed::
	lock
	hidefollower
	applymovement LOCALID_PLAYER, TimeSkipping_Movement_FaceDown
	waitmovement 0
	msgbox TimeSkipping_Text_Bed, MSGBOX_DEFAULT
	waitmessage
	msgbox TimeSkipping_Text_Rest, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, TimeSkipping_EventScript_Bed_AskUntilWhen
	case NO, TimeSkipping_EventScript_Declined
	release
	end

TimeSkipping_EventScript_Bed_AskUntilWhen::
	lock
	msgbox TimeSkipping_Text_UntilWhen, MSGBOX_DEFAULT
	dynmultipush TimeSkipping_Text_UntilMorning, 0
	dynmultipush TimeSkipping_Text_UntilNoon, 1
	dynmultipush TimeSkipping_Text_UntilNight, 2
	dynmultipush TimeSkipping_Text_UntilMidnight, 3
	dynmultipush TimeSkipping_Text_Cancel, 4
	dynmultistack 19, 0, FALSE, 5, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, TimeSkipping_EventScript_BedMorning
	case 1, TimeSkipping_EventScript_BedNoon
	case 2, TimeSkipping_EventScript_BedNight
	case 3, TimeSkipping_EventScript_BedMidnight
	case 4, TimeSkipping_EventScript_Declined
	case MULTI_B_PRESSED, TimeSkipping_EventScript_Declined
	release
	end

TimeSkipping_EventScript_BedMorning::
	lock
	fadescreenswapbuffers FADE_TO_BLACK
	delay 15
	special HealPlayerParty
	special RestInBed
	fadescreenswapbuffers FADE_FROM_BLACK
	setvar VAR_0x8004, 6
	bufferstring STR_VAR_1, TimeSkipping_Text_TimeMorning
	msgbox TimeSkipping_Text_BedWaiting, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

TimeSkipping_EventScript_BedNoon::
	lock
	fadescreenswapbuffers FADE_TO_BLACK
	delay 15
	special HealPlayerParty
	special RestInBed
	fadescreenswapbuffers FADE_FROM_BLACK
	setvar VAR_0x8004, 12
	bufferstring STR_VAR_1, TimeSkipping_Text_TimeNoon
	msgbox TimeSkipping_Text_BedWaiting, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

TimeSkipping_EventScript_BedNight::
	lock
	fadescreenswapbuffers FADE_TO_BLACK
	delay 15
	special HealPlayerParty
	special RestInBed
	fadescreenswapbuffers FADE_FROM_BLACK
	setvar VAR_0x8004, 18
	bufferstring STR_VAR_1, TimeSkipping_Text_TimeNight
	msgbox TimeSkipping_Text_BedWaiting, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

TimeSkipping_EventScript_BedMidnight::
	lock
	fadescreenswapbuffers FADE_TO_BLACK
	delay 15
	special HealPlayerParty
	special RestInBed
	fadescreenswapbuffers FADE_FROM_BLACK
	setvar VAR_0x8004, 21
	bufferstring STR_VAR_1, TimeSkipping_Text_TimeMidnight
	msgbox TimeSkipping_Text_BedWaiting, MSGBOX_DEFAULT
	waitmessage
	closemessage
	release
	end

TimeSkipping_Movement_FaceDown:
	face_down
	step_end

TimeSkipping_Movement_WalkDown:
	face_down
	walk_down
	step_end

TimeSkipping_Movement_SitLeft:
	walk_left
	walk_up
	face_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

TimeSkipping_Movement_SitRight:
	walk_right
	walk_up
	face_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

TimeSkipping_Text_Bench:
	.string "It's a small bench.$"

TimeSkipping_Text_Bed:
	.string "It's a cozy bed.$"

TimeSkipping_Text_Wait:
	.string "Would you like to wait?$"

TimeSkipping_Text_Rest:
	.string "Would you like to rest a bit?$"

TimeSkipping_Text_HowLong:
	.string "Wait how long?$"

TimeSkipping_Text_UntilWhen:
	.string "Rest until when?$"

TimeSkipping_Text_Declined:
	.string "You've decided not to.$"

TimeSkipping_Text_BenchWaiting:
	.string "You and {STR_VAR_1} waited\n"
	.string "for {STR_VAR_2} Hour(s).$"

TimeSkipping_Text_BedWaiting:
	.string "You and your Pokémon rested\n"
	.string "until {STR_VAR_1}.$"

TimeSkipping_Text_OneHour:
	.string "1 Hour(s)$"

TimeSkipping_Text_TwoHours:
	.string "2 Hour(s)$"

TimeSkipping_Text_ThreeHours:
	.string "3 Hour(s)$"

TimeSkipping_Text_FourHours:
	.string "4 Hour(s)$"

TimeSkipping_Text_FiveHours:
	.string "5 Hour(s)$"

TimeSkipping_Text_SixHours:
	.string "6 Hour(s)$"

TimeSkipping_Text_SevenHours:
	.string "7 Hour(s)$"

TimeSkipping_Text_EightHours:
	.string "8 Hour(s)$"

TimeSkipping_Text_NineHours:
	.string "9 Hour(s)$"

TimeSkipping_Text_TenHours:
	.string "10 Hour(s)$"

TimeSkipping_Text_ElevenHours:
	.string "11 Hour(s)$"

TimeSkipping_Text_TwelveHours:
	.string "12 Hour(s)$"

TimeSkipping_Text_ThirteenHours:
	.string "13 Hour(s)$"

TimeSkipping_Text_FourteenHours:
	.string "14 Hour(s)$"

TimeSkipping_Text_FifteenHours:
	.string "15 Hour(s)$"

TimeSkipping_Text_SixteenHours:
	.string "16 Hour(s)$"

TimeSkipping_Text_SeventeenHours:
	.string "17 Hour(s)$"

TimeSkipping_Text_EighteenHours:
	.string "18 Hour(s)$"

TimeSkipping_Text_NinteenHours:
	.string "19 Hour(s)$"

TimeSkipping_Text_TwentyHours:
	.string "20 Hour(s)$"

TimeSkipping_Text_TwentyOneHours:
	.string "21 Hour(s)$"

TimeSkipping_Text_TwentyTwoHours:
	.string "22 Hour(s)$"

TimeSkipping_Text_TwentyThreeHours:
	.string "23 Hour(s)$"

TimeSkipping_Text_TwentyFourHours:
	.string "24 Hour(s)$"

TimeSkipping_Text_UntilMorning:
	.string "Morning$"

TimeSkipping_Text_UntilNoon:
	.string "Noon$"

TimeSkipping_Text_UntilNight:
	.string "Night$"

TimeSkipping_Text_UntilMidnight:
	.string "Midnight$"

TimeSkipping_Text_TimeMorning:
	.string "morning$"

TimeSkipping_Text_TimeNoon:
	.string "noon$"

TimeSkipping_Text_TimeNight:
	.string "night$"

TimeSkipping_Text_TimeMidnight:
	.string "midnight$"

TimeSkipping_Text_Cancel:
	.string "Cancel$"
