ResearchShip_Quarters_MapScripts::
	.byte 0

ResearchShip_Quarters_EventScript_Cabin1Sign::
	msgbox ResearchShip_Quarters_Text_Cabin1, MSGBOX_SIGN
	end

ResearchShip_Quarters_EventScript_Cabin2Sign::
	msgbox ResearchShip_Quarters_Text_Cabin2, MSGBOX_SIGN
	end

ResearchShip_Quarters_EventScript_Cabin3Sign::
	msgbox ResearchShip_Quarters_Text_Cabin3, MSGBOX_SIGN
	end

ResearchShip_Quarters_EventScript_Cabin4Sign::
	msgbox ResearchShip_Quarters_Text_Cabin4, MSGBOX_SIGN
	end

ResearchShip_Quarters_EventScript_Porthole::
	lockall
	msgbox ResearchShip_Quarters_Text_HorizonSpreadsBeyondPorthole, MSGBOX_DEFAULT
	releaseall
	end

ResearchShip_Quarters_Text_HorizonSpreadsBeyondPorthole:
	.string "The horizon spreads beyond\n"
	.string "the porthole.$"

ResearchShip_Quarters_Text_Cabin1:
	.string "Cabin 1$"

ResearchShip_Quarters_Text_Cabin2:
	.string "Cabin 2$"

ResearchShip_Quarters_Text_Cabin3:
	.string "Cabin 3$"

ResearchShip_Quarters_Text_Cabin4:
	.string "Cabin 4$"
