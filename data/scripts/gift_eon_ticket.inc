MysteryGiftScript_EonTicket::
	setvaddress MysteryGiftScript_EonTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_EON_TICKET, EonTicket_Obtained
	vgoto_if_set FLAG_ENCOUNTERED_LATIAS_OR_LATIOS, EonTicket_Obtained
	checkitem ITEM_EON_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, EonTicket_Obtained
	vmessage sText_EonTicketThankYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_EON_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, EonTicket_NoBagSpace
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setflag FLAG_RECEIVED_EON_TICKET
	vmessage sText_EonTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

EonTicket_NoBagSpace:
	vmessage sText_EonTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

EonTicket_Obtained:
	vmessage sText_EonTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_EonTicketUseAtPort:
	.string "It appears to be for use at the\n"
	.string "LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"

sText_EonTicketThankYou:
	.string "Thank you for using the MYSTERY\n"
	.string "GIFT System.$"

sText_EonTicketBagFull:
	.string "Oh, I'm sorry,\n"
	.string "Your BAG's KEY ITEMS POCKET is full.\p"
	.string "Please store something on your PC,\n"
	.string "then come back for this.$"
