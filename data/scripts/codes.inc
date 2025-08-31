EventScript_CodeComputer::
	goto CodeComputer_EventScript_Interact
	end

CodeComputer_EventScript_Interact::
    lockall
    msgbox CodeComputer_Text_Welcome MSGBOX_YESNO
	switch VAR_RESULT
	case NO, CodeComputer_EventScript_Exit
	case YES, CodeComputer_EventScript_EnterCode
	case MULTI_B_PRESSED, CodeComputer_EventScript_Exit
	closemessage
	releaseall
	end

CodeComputer_EventScript_EnterCode::
    lockall
    special EnterCode
    waitstate
    special GetCodeFeedback
    goto_if_eq VAR_RESULT, 0, CodeComputer_EventScript_CodeFailed
    goto_if_eq VAR_RESULT, 1, CodeComputer_EventScript_EonTicket
    goto_if_eq VAR_RESULT, 2, CodeComputer_EventScript_AuroraTicket
    goto_if_eq VAR_RESULT, 3, CodeComputer_EventScript_MysticTicket
    goto_if_eq VAR_RESULT, 4, CodeComputer_EventScript_OldSeaMap
    goto_if_eq VAR_RESULT, 5, CodeComputer_EventScript_MirageBreaker
    goto_if_eq VAR_RESULT, 6, CodeComputer_EventScript_BigSale20XX
    goto_if_eq VAR_RESULT, 7, CodeComputer_EventScript_MasterBlender
    goto_if_eq VAR_RESULT, 8, CodeComputer_EventScript_RouletteLuck
    goto_if_eq VAR_RESULT, 9, CodeComputer_EventScript_DeveloperGift1
    goto_if_eq VAR_RESULT, 10, CodeComputer_EventScript_DeveloperGift2
    goto_if_eq VAR_RESULT, 11, CodeComputer_EventScript_DeveloperGift3
    goto_if_eq VAR_RESULT, 12, CodeComputer_EventScript_DeveloperGift4
    goto_if_eq VAR_RESULT, 13, CodeComputer_EventScript_DeveloperGift5
	releaseall
    end

CodeComputer_EventScript_Exit::
    lockall
    msgbox CodeComputer_Text_ComeAgain MSGBOX_DEFAULT
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_CodeFailed::
    lockall
    msgbox CodeComputer_Text_Failed MSGBOX_DEFAULT
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_EonTicket::
	goto_if_set FLAG_RECEIVED_EON_TICKET, CodeComputer_EventScript_EonTicketCode
	playse MUS_OBTAIN_ITEM
    msgbox CodeComputer_Text_Succeeded MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodeComputer_Text_SpecialItem MSGBOX_DEFAULT
	call MysteryGiftScript_EonTicket
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_AuroraTicket::
	goto_if_set FLAG_RECEIVED_AURORA_TICKET, CodeComputer_EventScript_AuroraTicketCode
	playse MUS_OBTAIN_ITEM
    msgbox CodeComputer_Text_Succeeded MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodeComputer_Text_SpecialItem MSGBOX_DEFAULT
	call MysteryGiftScript_AuroraTicket
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_MysticTicket::
	goto_if_set FLAG_RECEIVED_MYSTIC_TICKET, CodeComputer_EventScript_MysticTicketCode
	playse MUS_OBTAIN_ITEM
    msgbox CodeComputer_Text_Succeeded MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodeComputer_Text_SpecialItem MSGBOX_DEFAULT
	call MysteryGiftScript_MysticTicket
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_OldSeaMap::
	goto_if_set FLAG_RECEIVED_OLD_SEA_MAP, CodeComputer_EventScript_OldSeaMapCode
	playse MUS_OBTAIN_ITEM
    msgbox CodeComputer_Text_Succeeded MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodeComputer_Text_SpecialItem, MSGBOX_DEFAULT
	call MysteryGiftScript_OldSeaMap
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_EonTicketCode::
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
	msgbox CodeComputer_Text_GenItemDesc, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_AuroraTicketCode::
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	msgbox CodeComputer_Text_GenItemDesc, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_MysticTicketCode::
	bufferitemname STR_VAR_1, ITEM_MYSTIC_TICKET
	msgbox CodeComputer_Text_GenItemDesc, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_OldSeaMapCode::
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
	msgbox CodeComputer_Text_GenItemDesc, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_MirageBreaker::
	goto_if_set FLAG_MIRAGE_BREAKER_USED, CodeComputer_EventScript_MirageBreakerCode
	playse MUS_OBTAIN_ITEM
    msgbox CodeComputer_Text_Succeeded MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
	bufferstring STR_VAR_1, CodeComputer_Text_Route111
	bufferstring STR_VAR_2, CodeComputer_Text_Route130
    msgbox CodeComputer_Text_SpecialEvents MSGBOX_DEFAULT
	setflag FLAG_MIRAGE_BREAKER_USED
	setflag FLAG_MIRAGE_TOWER_VISIBLE
	setvar VAR_MIRAGE_TOWER_STATE, 0
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_BigSale20XX::
	goto_if_set FLAG_BIG_SALE_20XX_USED, CodeComputer_EventScript_BigSale20XXCode
	playse MUS_OBTAIN_ITEM
    msgbox CodeComputer_Text_Succeeded MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
	bufferstring STR_VAR_1, CodeComputer_Text_LilycoveCity
    msgbox CodeComputer_Text_SpecialEvent MSGBOX_DEFAULT
	setflag FLAG_BIG_SALE_20XX_USED
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_MasterBlender::
	goto_if_set FLAG_MASTER_BLENDER_USED, CodeComputer_EventScript_MasterBlenderCode
	playse MUS_OBTAIN_ITEM
    msgbox CodeComputer_Text_Succeeded MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
	bufferstring STR_VAR_1, CodeComputer_Text_LilycoveCity
    msgbox CodeComputer_Text_SpecialEvent MSGBOX_DEFAULT
	setflag FLAG_MASTER_BLENDER_USED
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_RouletteLuck::
	goto_if_set FLAG_ROULETTE_LUCK_USED, CodeComputer_EventScript_RouletteLuckCode
	playse MUS_OBTAIN_ITEM
    msgbox CodeComputer_Text_Succeeded MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
	bufferstring STR_VAR_1, CodeComputer_Text_MauvilleCity
    msgbox CodeComputer_Text_SpecialEvent, MSGBOX_DEFAULT
	setflag FLAG_ROULETTE_LUCK_USED
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_MirageBreakerCode::
	msgbox CodeComputer_Text_MirageBreaker, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_BigSale20XXCode::
	msgbox CodeComputer_Text_BigSale20XX, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_MasterBlenderCode::
	msgbox CodeComputer_Text_MasterBlender, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_RouletteLuckCode::
	msgbox CodeComputer_Text_RouletteLuck, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_DeveloperGift1::
	goto_if_set FLAG_RECEIVED_DEVELOPER_GIFT_1, CodeComputer_EventScript_DeveloperGift1Code
	playse MUS_OBTAIN_ITEM
    msgbox CodeComputer_Text_Succeeded MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodeComputer_Text_SpecialMon, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_DEVELOPER_GIFT_1
	givecustommon SPECIES_WEEDLE, 10, ITEM_POISON_BARB, ITEM_POKE_BALL, NATURE_ADAMANT, 0, 0, 0, 0, 0, 0, 0, 31, 31, 15, 31, 15, 15, MOVE_SLUDGE_BOMB, MOVE_TWINEEDLE, MOVE_HIDDEN_POWER, MOVE_HARDEN, FALSE
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_DeveloperGift2::
	goto_if_set FLAG_RECEIVED_DEVELOPER_GIFT_2, CodeComputer_EventScript_DeveloperGift2Code
	playse MUS_OBTAIN_ITEM
    msgbox CodeComputer_Text_Succeeded MSGBOX_DEFAULT
	waitmessage
	closemessage
	delay 5
    msgbox CodeComputer_Text_SpecialMon, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_DEVELOPER_GIFT_2
	givecustommon SPECIES_RALTS, 10, ITEM_TWISTED_SPOON, ITEM_PREMIER_BALL, NATURE_MODEST, 0, 0, 0, 0, 0, 0, 0, 31, 15, 15, 31, 31, 15, MOVE_PSYCHIC, MOVE_SHADOW_BALL, MOVE_HIDDEN_POWER, MOVE_CALM_MIND, TRUE
	waitmessage
	closemessage
    releaseall
    end

CodeComputer_EventScript_DeveloperGift3::
    special EnterName
    waitstate
    special GetNameFeedback
    goto_if_eq VAR_RESULT, 0, CodeComputer_EventScript_CodeFailed
    goto_if_eq VAR_RESULT, 1, CodeComputer_EventScript_Name1
    goto_if_eq VAR_RESULT, 2, CodeComputer_EventScript_Name2
    releaseall
    end

CodeComputer_EventScript_DeveloperGift4::
	msgbox CodeComputer_Text_BDayMessage1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_DeveloperGift5::
	msgbox CodeComputer_Text_BDayMessage2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_Name1::
	msgbox CodeComputer_Text_DevMessage1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_Name2::
	msgbox CodeComputer_Text_DevMessage2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_DeveloperGift1Code::
	bufferspeciesname STR_VAR_1, SPECIES_WEEDLE
	msgbox CodeComputer_Text_GenMonDesc, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_EventScript_DeveloperGift2Code::
	bufferspeciesname STR_VAR_1, SPECIES_RALTS
	msgbox CodeComputer_Text_GenMonDesc, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

CodeComputer_Text_Welcome:
    .string "Welcome to MYSTERY CODES SERVICE.\n"
    .string "Would you like to enter a code?$"

CodeComputer_Text_ComeAgain:
    .string "You're free to come back\n"
    .string "when you're ready to enter a code.$"

CodeComputer_Text_Failed:
    .string "...nothing happened.$"

CodeComputer_Text_Succeeded:
    .string "The code worked!$"

CodeComputer_Text_GenMonDesc:
    .string "This code was for a {STR_VAR_1}!\n"
    .string "You can't use it again!$"

CodeComputer_Text_GenItemDesc:
    .string "This code was for the {STR_VAR_1}!\n"
    .string "You can't use it again!$"

CodeComputer_Text_MirageBreaker:
    .string "This daily code causes both MIRAGE\n"
    .string "ISLAND and MIRAGE TOWER appear!\p"
    .string "You have already used it today!$"

CodeComputer_Text_BigSale20XX:
    .string "This daily code starts the LILYCOVE\n"
    .string "DEPARTMENT STORE's ROOFTOOP SALE!\p"
    .string "You have already used it today!$"

CodeComputer_Text_MasterBlender:
    .string "This daily code makes the BLEND MASTER\n"
    .string "appear in LILYCOVE's CONTEST HALL!\p"
    .string "You have already used it today!$"

CodeComputer_Text_RouletteLuck:
    .string "This daily code activates MAUVILLE's\n"
    .string "GAME CORNER Roulette luck bonus!\p"
    .string "You have already used it today!$"

CodeComputer_Text_SpecialItem:
    .string "It's a Special Item!$"

CodeComputer_Text_SpecialMon:
    .string "It's a Special POKéMON!$"

CodeComputer_Text_SpecialEvent:
    .string "A Special Event is happening!\n"
	.string "Head to {STR_VAR_1}!$"

CodeComputer_Text_SpecialEvents:
    .string "A Special Event is happening!\n"
	.string "Head to {STR_VAR_1} and {STR_VAR_2}!$"

CodeComputer_Text_MauvilleCity:
	.string "MAUVILLE CITY$"

CodeComputer_Text_LilycoveCity:
	.string "LILYCOVE CITY$"

CodeComputer_Text_Route111:
	.string "ROUTE 111$"

CodeComputer_Text_Route130:
	.string "ROUTE 130$"

CodeComputer_Text_DevMessage1:
	.string "I love you! <333$"

CodeComputer_Text_DevMessage2:
	.string "Yes I did make this :)$"

CodeComputer_Text_BDayMessage1:
	.string "Happy Birthday, dear! <333$"

CodeComputer_Text_BDayMessage2:
	.string "Happy Birthday, me!$"
