EventScript_TradeMachine::
	lock
	faceplayer
	msgbox TradeMachine_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq TradeMachine_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq TradeMachine_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	setvar VAR_0x8004, 6
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox TradeMachine_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

TradeMachine_EventScript_DeclineTrade::
	msgbox TradeMachine_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

TradeMachine_Text_IllTradeIfYouWant::
	.string "Trade Machine: Welcome, trainer! My job\n"
	.string "is to help you trade with yourself.\p"
	.string "Would you like to trade Pokémon?$"

TradeMachine_Text_ComeBack::
	.string "Trade Machine: Come back anytime!$"

TradeMachine_Text_YouDontWantTo::
	.string "Trade Machine: Oh, you dont want to?$"