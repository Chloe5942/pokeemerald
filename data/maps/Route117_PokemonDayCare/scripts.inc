Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_EventScript_DaycareStation::
	lockall
	playse SE_PC_ON
	waitse
	msgbox Route117_PokemonDayCare_Text_DaycareStation, MSGBOX_DEFAULT
	waitmessage
	closemessage
	dynmultipush Route117_PokemonDayCare_Text_Supplies, 0
	dynmultipush Route117_PokemonDayCare_Text_Incubator, 1
	dynmultipush Route117_PokemonDayCare_Text_Exit, 2
	dynmultistack 19, 0, FALSE, 5, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, Route117_PokemonDayCare_EventScript_Supplies
	case 1, Route117_PokemonDayCare_EventScript_Incubator
	case 2, Route117_PokemonDayCare_EventScript_Declined
	case MULTI_B_PRESSED, Route117_PokemonDayCare_EventScript_Declined
	releaseall
	end

Route117_PokemonDayCare_EventScript_DaycareStation_Quick::
	lockall
	dynmultipush Route117_PokemonDayCare_Text_Supplies, 0
	dynmultipush Route117_PokemonDayCare_Text_Incubator, 1
	dynmultipush Route117_PokemonDayCare_Text_Exit, 2
	dynmultistack 19, 0, FALSE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, Route117_PokemonDayCare_EventScript_Supplies
	case 1, Route117_PokemonDayCare_EventScript_Incubator
	case 2, Route117_PokemonDayCare_EventScript_Declined
	case MULTI_B_PRESSED, Route117_PokemonDayCare_EventScript_Declined
	releaseall
	end

Route117_PokemonDayCare_EventScript_Supplies::
	lockall
	message Route117_PokemonDayCare_Text_DaycareSupplies
	waitmessage
	pokemart Route117_PokemonDayCare_Supplies
	goto Route117_PokemonDayCare_EventScript_Declined
	releaseall
	end

	.align 2
Route117_PokemonDayCare_Supplies:
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_LUCKY_EGG
	.2byte ITEM_EVERSTONE
	pokemartlistend

Route117_PokemonDayCare_EventScript_Declined::
	lockall
	msgbox Route117_PokemonDayCare_Text_ComeBackAgain, MSGBOX_DEFAULT
	waitmessage
	closemessage
	goto Route117_PokemonDayCare_EventScript_DaycareStation_Off

Route117_PokemonDayCare_EventScript_Incubator::
	lockall
	playse SE_PC_ON
	waitse
	showmoneybox 0, 0
	msgbox Route117_PokemonDayCare_Text_EggIncubator_Ask, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Route117_PokemonDayCare_EventScript_EggIncubator_Incubate
	case NO, Route117_PokemonDayCare_EventScript_DaycareStation_Quick
	releaseall
	end

Route117_PokemonDayCare_EventScript_EggIncubator_Incubate::
	lockall
	msgbox Route117_PokemonDayCare_Text_EggIncubator_Accepted, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_EggIncubator_NothingSelected
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, Route117_PokemonDayCare_EventScript_EggIncubator_Hatch
	goto_if_eq VAR_RESULT, FALSE, Route117_PokemonDayCare_EventScript_EggIncubator_NotEgg
	releaseall
	end

Route117_PokemonDayCare_EventScript_EggIncubator_NothingSelected::
	lockall
	hidemoneybox
	msgbox Route117_PokemonDayCare_Text_EggIncubator_NoEgg, MSGBOX_DEFAULT
	waitmessage
	closemessage
	goto Route117_PokemonDayCare_EventScript_DaycareStation_Off

Route117_PokemonDayCare_EventScript_EggIncubator_NotEgg::
	lockall
	hidemoneybox
	msgbox Route117_PokemonDayCare_Text_EggIncubator_NotEgg, MSGBOX_DEFAULT
	waitmessage
	closemessage
	goto Route117_PokemonDayCare_EventScript_DaycareStation_Off

Route117_PokemonDayCare_EventScript_EggIncubator_Hatch::
	lockall
	checkmoney 2500
	goto_if_eq VAR_RESULT, FALSE, Route117_PokemonDayCare_EventScript_EggIncubator_NotEnoughMoney
	hidemoneybox
	special EggHatch
	setflag FLAG_EGG_MOVES_TUTOR
	waitstate
	msgbox Route117_PokemonDayCare_Text_EggIncubator_Hatched, MSGBOX_DEFAULT
	waitmessage
	closemessage
	showmoneybox 0, 0
	msgbox Route117_PokemonDayCare_Text_EggIncubator_TakeMoney, MSGBOX_DEFAULT
	waitmessage
	playse SE_SUCCESS
	waitse
	removemoney 2500
	updatemoneybox
	msgbox Route117_PokemonDayCare_Text_EggIncubator_MoneyTaken, MSGBOX_DEFAULT
	waitmessage
	hidemoneybox
	closemessage
	goto Route117_PokemonDayCare_EventScript_DaycareStation_Off

Route117_PokemonDayCare_EventScript_EggIncubator_NotEnoughMoney::
	lockall
	hidemoneybox
	msgbox Route117_PokemonDayCare_Text_EggIncubator_NotEnoughMoney, MSGBOX_DEFAULT
	waitmessage
	closemessage
	goto Route117_PokemonDayCare_EventScript_DaycareStation_Off

Route117_PokemonDayCare_EventScript_DaycareStation_Off::
	lockall
	playse SE_PC_OFF
	waitse
	releaseall
	end

Route117_PokemonDayCare_EventScript_DaycareMasseuse::
	lockall
	faceplayer
	msgbox Route117_PokemonDayCare_Text_WantMonMassaged, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Route117_PokemonDayCare_EventScript_AcceptMassage
	case NO, Route117_PokemonDayCare_EventScript_DeclineMassage
	releaseall
	end

Route117_PokemonDayCare_EventScript_AcceptMassage::
	lockall
	msgbox Route117_PokemonDayCare_Text_ChooseMon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_DeclineMassage
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, Route117_PokemonDayCare_EventScript_CantMassageEgg
	special MassageServices
	special BufferMonNickname
	msgbox Route117_PokemonDayCare_Text_HasBeenMassaged, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

Route117_PokemonDayCare_EventScript_DeclineMassage::
	lockall
	msgbox Route117_PokemonDayCare_Text_DeclinedMassage, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

Route117_PokemonDayCare_EventScript_CantMassageEgg::
	lockall
	msgbox Route117_PokemonDayCare_Text_CantMassageEgg, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

Route117_PokemonDayCare_Text_DaycareStation::
	.string "Welcome to the Daycare Station!\n"
	.string "What service would you like?$"

Route117_PokemonDayCare_Text_DaycareSupplies::
	.string "Daycare Supplies.\n"
	.string "What would you like?$"

Route117_PokemonDayCare_Text_EggIncubator_Ask::
	.string "Do you want to incubate an egg?\n"
	.string "Costs ¥2500 per egg.$"

Route117_PokemonDayCare_Text_ComeBackAgain::
	.string "Come back again!$"

Route117_PokemonDayCare_Text_EggIncubator_NoEgg::
	.string "Oh, you don't want to incubate an egg.\n"
	.string "Come back again!$"

Route117_PokemonDayCare_Text_EggIncubator_Accepted::
	.string "Select an egg.$"

Route117_PokemonDayCare_Text_EggIncubator_NotEgg::
	.string "That's not an egg!$"

Route117_PokemonDayCare_Text_EggIncubator_NotEnoughMoney::
	.string "Just like a dropped egg, you're broke!$"

Route117_PokemonDayCare_Text_EggIncubator_Hatched::
	.string "Your egg has been hatched!$"

Route117_PokemonDayCare_Text_EggIncubator_TakeMoney::
	.string "Taking payment… … …$"

Route117_PokemonDayCare_Text_EggIncubator_MoneyTaken::
	.string "Payment accepted!$"

Route117_PokemonDayCare_Text_Supplies::
	.string "Daycare Supplies$"

Route117_PokemonDayCare_Text_Incubator::
	.string "Egg Incubator$"

Route117_PokemonDayCare_Text_Exit::
	.string "Exit$"

Route117_PokemonDayCare_Text_WantMonMassaged:
	.string "Hey, would you like one of your Pokémon\n"
	.string "to get a short massage?$"

Route117_PokemonDayCare_Text_CantMassageEgg:
	.string "I can't massage an Egg!$"

Route117_PokemonDayCare_Text_DeclinedMassage:
	.string "Oh, you don't want me to give one of\n"
	.string "your Pokémon a massage?\p"
	.string "Come back soon though!$"

Route117_PokemonDayCare_Text_HasBeenMassaged:
	.string "{STR_VAR_1} looks happier!$"

Route117_PokemonDayCare_Text_ChooseMon:
	.string "Choose a Pokémon.$"
