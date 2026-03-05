BattleFrontier_TrainingCenter_MapScripts::
	.byte 0

BattleFrontier_TrainingCenter_Trigger_ReceptionistCounter::
	lockall
	call_if_eq VAR_TRAINING_CENTER_STATE, 0, BattleFrontier_TrainingCenter_EventScript_ReceptionistGreating
	call_if_eq VAR_TRAINING_CENTER_STATE, 2, BattleFrontier_TrainingCenter_EventScript_ReceptionistExit
	releaseall
	end

BattleFrontier_TrainingCenter_Trigger_TrainingArea::
	call_if_eq VAR_TRAINING_CENTER_STATE, 1, BattleFrontier_TrainingCenter_EventScript_Training
	end

BattleFrontier_TrainingCenter_EventScript_Training::
	setvar VAR_TRAINING_CENTER_STATE, 2
	return
	end

BattleFrontier_TrainingCenter_EventScript_ReceptionistGreating::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement
	goto BattleFrontier_TrainingCenter_EventScript_Receptionist
	releaseall
	return
	end

BattleFrontier_TrainingCenter_EventScript_ReceptionistExit::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement
	setvar VAR_TRAINING_CENTER_STATE, 0
	clearflag FLAG_TRAINING_CENTER_GYM
	msgbox BattleFrontier_TrainingCenter_Text_ThankYou, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_TrainingCenter_Movement_StepBack
	waitmovement
	releaseall
	return
	end

BattleFrontier_TrainingCenter_EventScript_Receptionist::
	lockall
	goto_if_set FLAG_TRAINING_CENTER_GYM, BattleFrontier_TrainingCenter_EventScript_GoIn
	special ShowBattlePointsWindow
	msgbox BattleFrontier_TrainingCenter_Text_Welcome, MSGBOX_DEFAULT
	dynmultipush gText_Yes, 0
	dynmultipush gText_No, 1
	dynmultipush gText_Info, 2
	dynmultistack 19, 0, FALSE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, BattleFrontier_TrainingCenter_EventScript_Accept
	case 1, BattleFrontier_TrainingCenter_EventScript_Decline
	case 2, BattleFrontier_TrainingCenter_EventScript_Info
	case MULTI_B_PRESSED, BattleFrontier_TrainingCenter_EventScript_Decline
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_GoIn::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_GoIn, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_Accept::
	lockall
	special ShowBattlePointsWindow
	setvar VAR_0x8004, 128
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_lt VAR_TEMP_1, VAR_0x8008, BattleFrontier_TrainingCenter_EventScript_NotEnoughBP
	special TakeFrontierBattlePoints
	special UpdateBattlePointsWindow
	msgbox BattleFrontier_TrainingCenter_Text_GoIn, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special CloseBattlePointsWindow
	setflag FLAG_TRAINING_CENTER_GYM
	setvar VAR_TRAINING_CENTER_STATE, 1
	applymovement LOCALID_PLAYER, BattleFrontier_TrainingCenter_Movement_StepForwards
	waitmovement
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_Decline::
	lockall
	special CloseBattlePointsWindow
	msgbox BattleFrontier_TrainingCenter_Text_Declined, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_TrainingCenter_Movement_StepBack
	waitmovement
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_Info::
	lockall
	special CloseBattlePointsWindow
	msgbox BattleFrontier_TrainingCenter_Text_Info, MSGBOX_DEFAULT
	waitmessage
	closemessage
	goto BattleFrontier_TrainingCenter_EventScript_ReceptionistQuick
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_ReceptionistQuick::
	lockall
	special ShowBattlePointsWindow
	msgbox BattleFrontier_TrainingCenter_Text_WelcomeQuick, MSGBOX_DEFAULT
	dynmultipush gText_Yes, 0
	dynmultipush gText_No, 1
	dynmultipush gText_Info, 2
	dynmultistack 19, 2, FALSE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, BattleFrontier_TrainingCenter_EventScript_Accept
	case 1, BattleFrontier_TrainingCenter_EventScript_Decline
	case 2, BattleFrontier_TrainingCenter_EventScript_Info
	case MULTI_B_PRESSED, BattleFrontier_TrainingCenter_EventScript_Decline
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_NotEnoughBP::
	lockall
	special CloseBattlePointsWindow
	msgbox BattleFrontier_TrainingCenter_Text_NotEnoughBP, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement LOCALID_PLAYER, BattleFrontier_TrainingCenter_Movement_StepBack
	waitmovement
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_TrainHP::
	lockall
	faceplayer
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_AZUMARILL
	bufferstring STR_VAR_2, gText_HP3
	setvar VAR_HP_EV, 3
	setvar VAR_ATK_EV, 0
	setvar VAR_DEF_EV, 0
	setvar VAR_SPEED_EV, 0
	setvar VAR_SPATK_EV, 0
	setvar VAR_SPDEF_EV, 0
	msgbox BattleFrontier_TrainingCenter_Text_PunchingBag, MSGBOX_DEFAULT
	waitmessage
	msgbox BattleFrontier_TrainingCenter_Text_AskTraining, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_TrainingCenter_EventScript_AcceptTraining
	case NO, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_TrainAtk::
	lockall
	faceplayer
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_MACHAMP
	bufferstring STR_VAR_2, gText_Attack
	setvar VAR_HP_EV, 0
	setvar VAR_ATK_EV, 3
	setvar VAR_DEF_EV, 0
	setvar VAR_SPEED_EV, 0
	setvar VAR_SPATK_EV, 0
	setvar VAR_SPDEF_EV, 0
	msgbox BattleFrontier_TrainingCenter_Text_PunchingBag, MSGBOX_DEFAULT
	waitmessage
	msgbox BattleFrontier_TrainingCenter_Text_AskTraining, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_TrainingCenter_EventScript_AcceptTraining
	case NO, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_TrainDef::
	lockall
	faceplayer
	playmoncry SPECIES_GOLEM, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_GOLEM
	bufferstring STR_VAR_2, gText_Defense
	setvar VAR_HP_EV, 0
	setvar VAR_ATK_EV, 0
	setvar VAR_DEF_EV, 3
	setvar VAR_SPEED_EV, 0
	setvar VAR_SPATK_EV, 0
	setvar VAR_SPDEF_EV, 0
	msgbox BattleFrontier_TrainingCenter_Text_PunchingBag, MSGBOX_DEFAULT
	waitmessage
	msgbox BattleFrontier_TrainingCenter_Text_AskTraining, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_TrainingCenter_EventScript_AcceptTraining
	case NO, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_TrainSPAtk::
	lockall
	faceplayer
	playmoncry SPECIES_BEAUTIFLY, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_BEAUTIFLY
	bufferstring STR_VAR_2, gText_SpAtk
	setvar VAR_HP_EV, 0
	setvar VAR_ATK_EV, 0
	setvar VAR_DEF_EV, 0
	setvar VAR_SPEED_EV, 0
	setvar VAR_SPATK_EV, 3
	setvar VAR_SPDEF_EV, 0
	msgbox BattleFrontier_TrainingCenter_Text_PunchingBag, MSGBOX_DEFAULT
	waitmessage
	msgbox BattleFrontier_TrainingCenter_Text_AskTraining, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_TrainingCenter_EventScript_AcceptTraining
	case NO, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_TrainSPDef::
	lockall
	faceplayer
	playmoncry SPECIES_DUSTOX, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_DUSTOX
	bufferstring STR_VAR_2, gText_SpDef
	setvar VAR_HP_EV, 0
	setvar VAR_ATK_EV, 0
	setvar VAR_DEF_EV, 0
	setvar VAR_SPEED_EV, 0
	setvar VAR_SPATK_EV, 0
	setvar VAR_SPDEF_EV, 3
	msgbox BattleFrontier_TrainingCenter_Text_PunchingBag, MSGBOX_DEFAULT
	waitmessage
	msgbox BattleFrontier_TrainingCenter_Text_AskTraining, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_TrainingCenter_EventScript_AcceptTraining
	case NO, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_TrainSpeed::
	lockall
	faceplayer
	playmoncry SPECIES_CROBAT, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, SPECIES_CROBAT
	bufferstring STR_VAR_2, gText_Speed
	setvar VAR_HP_EV, 0
	setvar VAR_ATK_EV, 0
	setvar VAR_DEF_EV, 0
	setvar VAR_SPEED_EV, 3
	setvar VAR_SPATK_EV, 0
	setvar VAR_SPDEF_EV, 0
	msgbox BattleFrontier_TrainingCenter_Text_PunchingBag, MSGBOX_DEFAULT
	waitmessage
	msgbox BattleFrontier_TrainingCenter_Text_AskTraining, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_TrainingCenter_EventScript_AcceptTraining
	case NO, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_AcceptTraining::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_ChooseLevel, MSGBOX_DEFAULT
	dynmultipush BattleFrontier_TrainingCenter_Text_Light, 0
	dynmultipush BattleFrontier_TrainingCenter_Text_Medium, 1
	dynmultipush BattleFrontier_TrainingCenter_Text_Heavy, 2
	dynmultipush BattleFrontier_TrainingCenter_Text_Intense, 3
	dynmultipush gText_Cancel, 4
	dynmultistack 19, 0, FALSE, 5, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, BattleFrontier_TrainingCenter_EventScript_TrainEVs_Light
	case 1, BattleFrontier_TrainingCenter_EventScript_TrainEVs_Medium
	case 2, BattleFrontier_TrainingCenter_EventScript_TrainEVs_Heavy
	case 3, BattleFrontier_TrainingCenter_EventScript_TrainEVs_Intense
	case 4, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	case MULTI_B_PRESSED, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_TrainEVs_Light::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_ChooseMon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_TrainingCenter_EventScript_CantTrainEgg
	special BufferMonNickname
	specialvar VAR_RESULT, AreMonEVsMaxedOut
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_TrainingCenter_EventScript_CantTrainEVs
	setvar VAR_EV_TRAINING, 5
	special AddMonEVs
	msgbox BattleFrontier_TrainingCenter_Text_CompletedTraining, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_TrainEVs_Medium::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_ChooseMon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_TrainingCenter_EventScript_CantTrainEgg
	special BufferMonNickname
	specialvar VAR_RESULT, AreMonEVsMaxedOut
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_TrainingCenter_EventScript_CantTrainEVs
	setvar VAR_EV_TRAINING, 10
	special AddMonEVs
	msgbox BattleFrontier_TrainingCenter_Text_CompletedTraining, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_TrainEVs_Heavy::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_ChooseMon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_TrainingCenter_EventScript_CantTrainEgg
	special BufferMonNickname
	specialvar VAR_RESULT, AreMonEVsMaxedOut
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_TrainingCenter_EventScript_CantTrainEVs
	setvar VAR_EV_TRAINING, 15
	special AddMonEVs
	msgbox BattleFrontier_TrainingCenter_Text_CompletedTraining, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_TrainEVs_Intense::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_ChooseMon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_TrainingCenter_EventScript_DeclineTraining
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_TrainingCenter_EventScript_CantTrainEgg
	special BufferMonNickname
	specialvar VAR_RESULT, AreMonEVsMaxedOut
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_TrainingCenter_EventScript_CantTrainEVs
	setvar VAR_EV_TRAINING, 20
	special AddMonEVs
	msgbox BattleFrontier_TrainingCenter_Text_CompletedTraining, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_DeclineTraining::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_DeclinedTraining, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_CantTrainEgg::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_CantTrainEgg, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_CantTrainEV::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_CantTrainEV, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_CantTrainEVs::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_CantTrainEVs, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_ResetTraining::
	lockall
	faceplayer
	msgbox BattleFrontier_TrainingCenter_Text_ResetTraining, MSGBOX_DEFAULT
	waitmessage
	msgbox BattleFrontier_TrainingCenter_Text_AskResetTraining, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_TrainingCenter_EventScript_AcceptReset
	case NO, BattleFrontier_TrainingCenter_EventScript_DeclineReset
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_AcceptReset::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_ChooseMon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_TrainingCenter_EventScript_DeclineReset
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_TrainingCenter_EventScript_CantResetEgg
	setvar VAR_0x8000, 0
	special ResetMonEvs
	special BufferMonNickname
	msgbox BattleFrontier_TrainingCenter_Text_CompletedReset, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_DeclineReset::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_DeclinedReset, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_CantResetEgg::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_CantResetEgg, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_PkmnGroomer::
	lockall
	faceplayer
	msgbox BattleFrontier_TrainingCenter_Text_WantMonGroomed, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BattleFrontier_TrainingCenter_EventScript_AcceptGrooming
	case NO, BattleFrontier_TrainingCenter_EventScript_DeclineGrooming
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_AcceptGrooming::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_ChooseMon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_TrainingCenter_EventScript_DeclineGrooming
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_TrainingCenter_EventScript_CantGroomEgg
	special GroomingServices
	special BufferMonNickname
	msgbox BattleFrontier_TrainingCenter_Text_HasBeenGroomed, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_DeclineGrooming::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_DeclinedGrooming, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_EventScript_CantGroomEgg::
	lockall
	msgbox BattleFrontier_TrainingCenter_Text_CantGroomEgg, MSGBOX_DEFAULT
	waitmessage
	closemessage
	releaseall
	end

BattleFrontier_TrainingCenter_Movement_StepBack:
	walk_left
	step_end

BattleFrontier_TrainingCenter_Movement_StepForwards:
	walk_right
	step_end

BattleFrontier_TrainingCenter_Text_PunchingBag:
	.string "It's a {STR_VAR_1} training dummy.\n"
	.string "It raises {STR_VAR_2} EVs.$"

BattleFrontier_TrainingCenter_Text_AskTraining:
	.string "Do you want to use this {STR_VAR_1}\n"
	.string "training dummy to raise one of your\p"
	.string "Pokémon's {STR_VAR_2} EVs?$"

BattleFrontier_TrainingCenter_Text_CompletedTraining:
	.string "{STR_VAR_1} has finished training!$"

BattleFrontier_TrainingCenter_Text_ChooseMon:
	.string "Choose a Pokémon.$"

BattleFrontier_TrainingCenter_Text_CantTrainEgg:
	.string "You can't train an Egg's EVs!$"

BattleFrontier_TrainingCenter_Text_CantTrainEV:
	.string "{STR_VAR_1}'s EVs for this stat\n"
	.string "is already maxed out!$"

BattleFrontier_TrainingCenter_Text_CantTrainEVs:
	.string "{STR_VAR_1} can't train anymore!$"

BattleFrontier_TrainingCenter_Text_DeclinedTraining:
	.string "You decided not to train a Pokémon.$"

BattleFrontier_TrainingCenter_Text_ResetTraining:
	.string "Hey there, I can reset one of your\n"
	.string "Pokémon's EVs for retraining.$"

BattleFrontier_TrainingCenter_Text_AskResetTraining:
	.string "Do you want me to reset one of your\n"
	.string "Pokémon's EV training progress?\p"
	.string "This can't be undone.$"

BattleFrontier_TrainingCenter_Text_CantResetEgg:
	.string "You can't reset an Egg's EVs!$"

BattleFrontier_TrainingCenter_Text_DeclinedReset:
	.string "You decided not to reset your\n"
	.string "Pokémon's EVs.$"

BattleFrontier_TrainingCenter_Text_CompletedReset:
	.string "{STR_VAR_1}'s EV training\n"
	.string "has been reset!$"

BattleFrontier_TrainingCenter_Text_ChooseLevel:
	.string "What training level would you like?$"

BattleFrontier_TrainingCenter_Text_Light:
	.string "Light$"

BattleFrontier_TrainingCenter_Text_Medium:
	.string "Medium$"

BattleFrontier_TrainingCenter_Text_Heavy:
	.string "Heavy$"

BattleFrontier_TrainingCenter_Text_Intense:
	.string "Intense$"

BattleFrontier_TrainingCenter_Text_Welcome:
	.string "Welcome to the Training Center!\p"
	.string "Here we can help you train your Pokémon\n"
	.string "to their full potential!\p"
	.string "Would you like to enter? Costs 128 BP.$"

BattleFrontier_TrainingCenter_Text_GoIn:
	.string "Thank you! You may now enter the gym!$"

BattleFrontier_TrainingCenter_Text_Info:
	.string "Here at the Training Center, we offer\n"
	.string "six different Pokémon shaped\p"
	.string "training dummies. They allow you to\n"
	.string "choose a training regime to raise your\p"
	.string "Pokémon's Effort Values (EVs).\n"
	.string "We also have a worker who can reset\p"
	.string "your Pokémon's EVs if you need it.$"

BattleFrontier_TrainingCenter_Text_WelcomeQuick:
	.string "Do you want to enter? Costs 128 BP.$"

BattleFrontier_TrainingCenter_Text_NotEnoughBP:
	.string "Sorry, but you don't have enough BP.$"

BattleFrontier_TrainingCenter_Text_Declined:
	.string "Oh, you don't want to train any of\n"
	.string "your Pokémon. Come by again!$"

BattleFrontier_TrainingCenter_Text_ThankYou:
	.string "Thank you for your patronage!\p"
	.string "We hope both you and your Pokémon\n"
	.string "enjoyed using our Training Center!\p"
	.string "Come back again soon!$"

BattleFrontier_TrainingCenter_Text_WantMonGroomed:
	.string "Heya, if you want, I can give one of\n"
	.string "your Pokémon a nice grooming session.\p"
	.string "So, do you want a Pokémon groomed?$"

BattleFrontier_TrainingCenter_Text_CantGroomEgg:
	.string "I can't groom an Egg!$"

BattleFrontier_TrainingCenter_Text_DeclinedGrooming:
	.string "Oh, you don't want me to\n"
	.string "groom one of your Pokémon?\p"
	.string "Come back soon though!$"

BattleFrontier_TrainingCenter_Text_HasBeenGroomed:
	.string "{STR_VAR_1} looks happier!\n"
	.string "{STR_VAR_1} likes their new style too!$"
