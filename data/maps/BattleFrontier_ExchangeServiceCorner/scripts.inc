BattleFrontier_ExchangeServiceCorner_MapScripts::
	.byte 0

BattleFrontier_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_BagFull::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Man::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Sailor::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_EventScript_Girl::
	msgbox BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Hello, this is the Exchange Service\n"
	.string "Corner.\p"
	.string "We exchange the Battle Points you\n"
	.string "have collected for lovely prizes.\p"
	.string "Please choose a prize from this list.$"

@ Unused
BattleFrontier_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "Please choose a prize from this list.$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.string "You've chosen the Kiss Poster.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.string "You've chosen the Kiss Cushion.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
	.string "You've chosen the Smoochum Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.string "You've chosen the Togepi Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.string "You've chosen the Meowth Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.string "You've chosen the Clefairy Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.string "You've chosen the Ditto Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.string "You've chosen the Cyndaquil Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.string "You've chosen the Chikorita Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.string "You've chosen the Totodile Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.string "You've chosen the Lapras Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.string "You've chosen the Snorlax Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.string "You've chosen the Venusaur Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.string "You've chosen the Charizard Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.string "You've chosen the Blastoise Doll.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "You've chosen the Protein.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "You've chosen the Calcium.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmIron:
	.string "You've chosen the Iron.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "You've chosen the Zinc.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "You've chosen the Carbos.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmHPUp:
	.string "You've chosen the HP Up.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "You've chosen the Brightpowder.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "You've chosen the White Herb.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "You've chosen the Quick Claw.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "You've chosen the Mental Herb.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "You've chosen the Choice Band.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "You've chosen the King's Rock.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "You've chosen the Focus Band.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "You've chosen the Scope Lens.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "You've chosen the Leftovers.\n"
	.string "Is that correct?$"

BattleFrontier_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

BattleFrontier_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Here is your prize!$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "I'm so sorry…\n"
	.string "You don't have enough Battle Points…$"

BattleFrontier_ExchangeServiceCorner_Text_PCIsFull:
	.string "I'm so sorry…\n"
	.string "Your PC appears to be full…$"

BattleFrontier_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "I'm so sorry…\n"
	.string "You don't have space to hold it…$"

BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Thank you very much.\p"
	.string "Please visit us when you have\n"
	.string "saved up Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, they're so nice!\n"
	.string "I wish I had them!\l"
	.string "Cute cushions!\l"
	.string "Big plush Dolls!\l"
	.string "Little plush Dolls!\l"
	.string "I wish I had them all!$"

BattleFrontier_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Leave it to your mommy!\p"
	.string "If it's anything you want, I'll go\n"
	.string "through anything to get it, honey!$"

BattleFrontier_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "If I can get hold of the items here,\n"
	.string "my Pokémon will get tougher.\p"
	.string "You bet they will!\n"
	.string "No question about it!$"

BattleFrontier_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Hah?\n"
	.string "What are you gawking at?\p"
	.string "I don't like you staring at my plush\n"
	.string "doll like that.\p"
	.string "If you want it, go get one yourself!\n"
	.string "Isn't that right, Smoochum?$"

BattleFrontier_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Did you know?\p"
	.string "If you stretch your record at any of\n"
	.string "the Battle facilities, they start\l"
	.string "giving you more and more Battle Points.$"

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "A large poster with a Smoochum print.$"

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "A Smoochum cushion.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "A Smoochum Doll.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "A Togepi Doll.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "A Meowth Doll.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "A Clefairy Doll.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "A Ditto Doll.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "A Cyndaquil Doll.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "A Chikorita Doll.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "A Totodile Doll.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "A large Doll.\n"
	.string "Place it on a mat or a desk.$"

BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc::
	.string "Raises the stat Attack of one\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc::
	.string "Raises the stat Sp. Atk of one\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_IronDesc::
	.string "Raises the stat Defense of one\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_ZincDesc::
	.string "Raises the stat Sp. Def of one\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc::
	.string "Raises the stat Speed of one\n"
	.string "Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc::
	.string "Raises the HP of one Pokémon.$"

BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "A hold item that gradually restores\n"
	.string "HP in battle.$"

BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "A hold item that restores any\n"
	.string "lowered stat.$"

BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "A hold item that occasionally allows\n"
	.string "the first strike.$"

BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "A hold item that snaps Pokémon out\n"
	.string "of infatuation.$"

BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "A hold item that casts a glare to\n"
	.string "reduce accuracy.$"

BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Raises a move's power, but permits\n"
	.string "only that move.$"

BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "A hold item that may cause flinching\n"
	.string "when the foe is hit.$"

BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "A hold item that occasionally\n"
	.string "prevents fainting.$"

BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "A hold item that raises the\n"
	.string "critical-hit rate.$"

BattleFrontier_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	battlepointmart BattleFrontier_ExchangeServiceCorner_HeldItems
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_ExchangeServiceCorner_HeldItems:
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_MENTAL_HERB
	.2byte ITEM_CHOICE_BAND
	.2byte ITEM_BRIGHT_POWDER
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_SCOPE_LENS
	.2byte ITEM_FOCUS_BAND
	pokemartlistend

BattleFrontier_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	battlepointmart BattleFrontier_ExchangeServiceCorner_Vitamins
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_ExchangeServiceCorner_Vitamins:
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_PP_UP
	.2byte ITEM_PP_MAX
	pokemartlistend

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	pokemartdecoration BattleFrontier_ExchangeServiceCorner_DecorCommon
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_ExchangeServiceCorner_DecorCommon:
	.2byte DECOR_LAPRAS_DOLL
	.2byte DECOR_SNORLAX_DOLL
	.2byte DECOR_RHYDON_DOLL
	.2byte DECOR_DITTO_DOLL
	.2byte DECOR_CLEFAIRY_DOLL
	.2byte DECOR_MEOWTH_DOLL
	.2byte DECOR_TOGEPI_DOLL
	.2byte DECOR_SNORLAX_DOLL
	.2byte DECOR_SMOOCHUM_DOLL
	.2byte DECOR_SEEDOT_DOLL
	.2byte DECOR_KISS_POSTER
	.2byte DECOR_KISS_CUSHION
	.2byte DECOR_TV
	.2byte DECOR_ROUND_TV
	.2byte DECOR_CUTE_TV
	pokemartlistend

BattleFrontier_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	msgbox BattleFrontier_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	pokemartdecoration BattleFrontier_ExchangeServiceCorner_DecorRare
	msgbox BattleFrontier_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	release
	end

	.align 2
BattleFrontier_ExchangeServiceCorner_DecorRare:
	.2byte DECOR_VENUSAUR_DOLL
	.2byte DECOR_CHARIZARD_DOLL
	.2byte DECOR_BLASTOISE_DOLL
	.2byte DECOR_REGISTEEL_DOLL
	.2byte DECOR_REGIROCK_DOLL
	.2byte DECOR_TIRE
	.2byte DECOR_STAND
	.2byte DECOR_FENCE_LENGTH
	.2byte DECOR_FENCE_WIDTH
	.2byte DECOR_MUD_BALL
	.2byte DECOR_BREAKABLE_DOOR
	.2byte DECOR_SAND_ORNAMENT
	.2byte DECOR_RED_TENT
	.2byte DECOR_BLUE_TENT
	.2byte DECOR_SLIDE
	pokemartlistend
