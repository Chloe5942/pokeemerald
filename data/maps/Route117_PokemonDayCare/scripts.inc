Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_EventScript_EggIncubator::
	msgbox Route117_PokemonDayCare_Text_EggIncubator, MSGBOX_DEFAULT
	waitmessage
	closemessage
	showmoneybox 0, 0
	msgbox Route117_PokemonDayCare_Text_EggIncubator_Ask, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, Route117_PokemonDayCare_EventScript_EggIncubator_Incubate
	case NO, Route117_PokemonDayCare_EventScript_EggIncubator_Declined
	end

Route117_PokemonDayCare_EventScript_EggIncubator_Incubate::
	msgbox Route117_PokemonDayCare_Text_EggIncubator_Accepted, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route117_PokemonDayCare_EventScript_EggIncubator_NothingSelected
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, Route117_PokemonDayCare_EventScript_EggIncubator_Hatch
	goto_if_eq VAR_RESULT, FALSE, Route117_PokemonDayCare_EventScript_EggIncubator_NotEgg
	end

Route117_PokemonDayCare_EventScript_EggIncubator_NothingSelected::
	hidemoneybox
	msgbox Route117_PokemonDayCare_Text_EggIncubator_NothingSelected, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

Route117_PokemonDayCare_EventScript_EggIncubator_Declined::
	hidemoneybox
	msgbox Route117_PokemonDayCare_Text_EggIncubator_Declined, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

Route117_PokemonDayCare_EventScript_EggIncubator_NotEgg::
	hidemoneybox
	msgbox Route117_PokemonDayCare_Text_EggIncubator_NotEgg, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

Route117_PokemonDayCare_EventScript_EggIncubator_Hatch::
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
	removemoney 2500
	updatemoneybox
	msgbox Route117_PokemonDayCare_Text_EggIncubator_MoneyTaken, MSGBOX_DEFAULT
	waitmessage
	hidemoneybox
	closemessage
	end

Route117_PokemonDayCare_EventScript_EggIncubator_NotEnoughMoney::
	hidemoneybox
	msgbox Route117_PokemonDayCare_Text_EggIncubator_NotEnoughMoney, MSGBOX_DEFAULT
	waitmessage
	closemessage
	end

Route117_PokemonDayCare_Text_EggIncubator::
	.string "It's an Egg Incubator.\n"
	.string "It causes eggs to hatch immediately.$"

Route117_PokemonDayCare_Text_EggIncubator_Ask::
	.string "Do you want to incubate an egg?\n"
	.string "Costs ¥2500 per egg.$"

Route117_PokemonDayCare_Text_EggIncubator_NothingSelected::
	.string "Come back again!$"

Route117_PokemonDayCare_Text_EggIncubator_Declined::
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
