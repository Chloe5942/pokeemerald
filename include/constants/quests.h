#ifndef GUARD_CONSTANTS_QUESTS_H
#define GUARD_CONSTANTS_QUESTS_H

//questmenu scripting command params
#define QUEST_MENU_OPEN                 0   //opens the quest menu (questId = 0)
#define QUEST_MENU_UNLOCK_QUEST         1   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_ACTIVE           2   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_REWARD           3   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_COMPLETE_QUEST       4   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_CHECK_UNLOCKED       5   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_INACTIVE       6   //checks if a questID is inactive. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_ACTIVE         7   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_REWARD         8   //checks if questId is in Reward state. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_COMPLETE       9   //checks if questId has been completed. Returns result to gSpecialVar_Result
#define QUEST_MENU_BUFFER_QUEST_NAME    10  //buffers a quest name to gStringVar1

// Quest Number Defines
// Main Game 
#define QUEST_RIVAL_NEXT_DOOR                0
#define QUEST_SCOUTING_SCOTT                 1
#define QUEST_CONTEST_STAR_COOL              2
#define QUEST_CONTEST_STAR_CUTE              3
#define QUEST_CONTEST_STAR_BEAUTY            4
#define QUEST_CONTEST_STAR_SMART             5
#define QUEST_CONTEST_STAR_TOUGH             6
// Post Game
#define QUEST_FRONTIER_WELCOME               7
#define QUEST_FRONTIER_SILVER                8
#define QUEST_FRONTIER_GOLD                  9
#define QUEST_SEAFARER                      10
#define QUEST_COUNT                         (QUEST_SEAFARER + 1) // 11/100 89 Free Spaces Left

// Rival Next Door
#define SUB_QUEST_FIRST_BATTLE               0
#define SUB_QUEST_SECOND_BATTLE              1
#define SUB_QUEST_THIRD_BATTLE               2
#define SUB_QUEST_FOURTH_BATTLE              3
#define SUB_QUEST_FIFTH_BATTLE               4
// Scouting Scott
#define SUB_QUEST_GRADUATING_CLASS           5
#define SUB_QUEST_CLASS_REUNION              6
#define SUB_QUEST_BATTLE_TENT_SLATEPORT      7
#define SUB_QUEST_BATTLE_TENT_VERDANTURF     8
#define SUB_QUEST_BATTLE_TENT_FALLARBOR      9
#define SUB_QUEST_LILYCOVE_MOTEL            10
#define SUB_QUEST_SPACEGAZER                11
#define SUB_QUEST_GRAND_BATTLES             12
// Cool Contests
#define SUB_QUEST_NORMAL_RANK_COOL          13
#define SUB_QUEST_SUPER_RANK_COOL           14
#define SUB_QUEST_HYPER_RANK_COOL           15
#define SUB_QUEST_MASTER_RANK_COOL          16
// Cute Contests
#define SUB_QUEST_NORMAL_RANK_CUTE          17
#define SUB_QUEST_SUPER_RANK_CUTE           18
#define SUB_QUEST_HYPER_RANK_CUTE           19
#define SUB_QUEST_MASTER_RANK_CUTE          20
// Beauty Contests
#define SUB_QUEST_NORMAL_RANK_BEAUTY        21
#define SUB_QUEST_SUPER_RANK_BEAUTY         22
#define SUB_QUEST_HYPER_RANK_BEAUTY         23
#define SUB_QUEST_MASTER_RANK_BEAUTY        24
// Smart Contests
#define SUB_QUEST_NORMAL_RANK_SMART         25
#define SUB_QUEST_SUPER_RANK_SMART          26
#define SUB_QUEST_HYPER_RANK_SMART          27
#define SUB_QUEST_MASTER_RANK_SMART         28
// Tough Contests
#define SUB_QUEST_NORMAL_RANK_TOUGH         29
#define SUB_QUEST_SUPER_RANK_TOUGH          30
#define SUB_QUEST_HYPER_RANK_TOUGH          31
#define SUB_QUEST_MASTER_RANK_TOUGH         32
// Silver Frontier Symbols
#define SUB_QUEST_KNOWLEDGE_SYMBOL_SILVER   33
#define SUB_QUEST_GUTS_SYMBOL_SILVER        34
#define SUB_QUEST_TACTICS_SYMBOL_SILVER     35
#define SUB_QUEST_LUCK_SYMBOL_SILVER        36
#define SUB_QUEST_SPIRITS_SYMBOL_SILVER     37
#define SUB_QUEST_BRAVE_SYMBOL_SILVER       38
#define SUB_QUEST_ABILITY_SYMBOL_SILVER     39
// Gold Frontier Symbols
#define SUB_QUEST_KNOWLEDGE_SYMBOL_GOLD     40
#define SUB_QUEST_GUTS_SYMBOL_GOLD          41
#define SUB_QUEST_TACTICS_SYMBOL_GOLD       42
#define SUB_QUEST_LUCK_SYMBOL_GOLD          43
#define SUB_QUEST_SPIRITS_SYMBOL_GOLD       44
#define SUB_QUEST_BRAVE_SYMBOL_GOLD         45
#define SUB_QUEST_ABILITY_SYMBOL_GOLD       46
// Seafarer
#define SUB_QUEST_AURORA_TICKET             47
#define SUB_QUEST_EON_TICKET                48
#define SUB_QUEST_MYSTIC_TICKET             49
#define SUB_QUEST_OLD_SEA_MAP               50

#define QUEST_RIVAL_NEXT_DOOR_SUB_COUNT      5
#define QUEST_SCOUTING_SCOTT_SUB_COUNT       8
#define QUEST_CONTEST_STAR_COOL_SUB_COUNT    4
#define QUEST_CONTEST_STAR_CUTE_SUB_COUNT    4
#define QUEST_CONTEST_STAR_BEAUTY_SUB_COUNT  4
#define QUEST_CONTEST_STAR_SMART_SUB_COUNT   4
#define QUEST_CONTEST_STAR_TOUGH_SUB_COUNT   4
#define QUEST_FRONTIER_SILVER_SUB_COUNT      7
#define QUEST_FRONTIER_GOLD_SUB_COUNT        7
#define QUEST_SEAFARER_SUB_COUNT             4

#define SUB_QUEST_COUNT (QUEST_RIVAL_NEXT_DOOR_SUB_COUNT + QUEST_SCOUTING_SCOTT_SUB_COUNT + QUEST_CONTEST_STAR_COOL_SUB_COUNT + QUEST_CONTEST_STAR_CUTE_SUB_COUNT + QUEST_CONTEST_STAR_BEAUTY_SUB_COUNT + QUEST_CONTEST_STAR_SMART_SUB_COUNT + QUEST_CONTEST_STAR_TOUGH_SUB_COUNT + QUEST_FRONTIER_SILVER_SUB_COUNT + QUEST_FRONTIER_GOLD_SUB_COUNT + QUEST_SEAFARER_SUB_COUNT) // 51/168 117 Free Spaces Left

#define QUEST_ARRAY_COUNT (SUB_QUEST_COUNT > QUEST_COUNT ? SUB_QUEST_COUNT : QUEST_COUNT)
#endif // GUARD_CONSTANTS_QUESTS_H
