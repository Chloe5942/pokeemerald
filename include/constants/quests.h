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

// quest number defines
#define QUEST_MAIN_STORY            0
#define QUEST_CONTEST_STAR_COOL     1
#define QUEST_CONTEST_STAR_CUTE     2
#define QUEST_CONTEST_STAR_BEAUTY   3
#define QUEST_CONTEST_STAR_SMART    4
#define QUEST_CONTEST_STAR_TOUGH    5
#define QUEST_FRONTIER_WELCOME      6
#define QUEST_FRONTIER_SILVER       7
#define QUEST_FRONTIER_GOLD         8
#define QUEST_COUNT                 (QUEST_FRONTIER_GOLD + 1) // 8/100 92 free spaces left

#define SUB_QUEST_1                          0
#define SUB_QUEST_2                          1
#define SUB_QUEST_3                          2
#define SUB_QUEST_4                          3
#define SUB_QUEST_5                          4
#define SUB_QUEST_6                          5
#define SUB_QUEST_7                          6
#define SUB_QUEST_8                          7
#define SUB_QUEST_9                          8
#define SUB_QUEST_10                         9 // Reserved
// Cool Contests
#define SUB_QUEST_NORMAL_RANK_COOL          10
#define SUB_QUEST_SUPER_RANK_COOL           11
#define SUB_QUEST_HYPER_RANK_COOL           12
#define SUB_QUEST_MASTER_RANK_COOL          13
// Cute Contests
#define SUB_QUEST_NORMAL_RANK_CUTE          14
#define SUB_QUEST_SUPER_RANK_CUTE           15
#define SUB_QUEST_HYPER_RANK_CUTE           16
#define SUB_QUEST_MASTER_RANK_CUTE          17
// Beauty Contests
#define SUB_QUEST_NORMAL_RANK_BEAUTY        18
#define SUB_QUEST_SUPER_RANK_BEAUTY         19
#define SUB_QUEST_HYPER_RANK_BEAUTY         20
#define SUB_QUEST_MASTER_RANK_BEAUTY        21
// Smart Contests
#define SUB_QUEST_NORMAL_RANK_SMART         22
#define SUB_QUEST_SUPER_RANK_SMART          23
#define SUB_QUEST_HYPER_RANK_SMART          24
#define SUB_QUEST_MASTER_RANK_SMART         25
// Tough Contests
#define SUB_QUEST_NORMAL_RANK_TOUGH         26
#define SUB_QUEST_SUPER_RANK_TOUGH          27
#define SUB_QUEST_HYPER_RANK_TOUGH          28
#define SUB_QUEST_MASTER_RANK_TOUGH         29
// Silver Frontier Symbols
#define SUB_QUEST_KNOWLEDGE_SYMBOL_SILVER   30
#define SUB_QUEST_GUTS_SYMBOL_SILVER        31
#define SUB_QUEST_TACTICS_SYMBOL_SILVER     32
#define SUB_QUEST_LUCK_SYMBOL_SILVER        33
#define SUB_QUEST_SPIRITS_SYMBOL_SILVER     34
#define SUB_QUEST_BRAVE_SYMBOL_SILVER       35
#define SUB_QUEST_ABILITY_SYMBOL_SILVER     36
// Gold Frontier Symbols
#define SUB_QUEST_KNOWLEDGE_SYMBOL_GOLD     37
#define SUB_QUEST_GUTS_SYMBOL_GOLD          38
#define SUB_QUEST_TACTICS_SYMBOL_GOLD       39
#define SUB_QUEST_LUCK_SYMBOL_GOLD          40
#define SUB_QUEST_SPIRITS_SYMBOL_GOLD       41
#define SUB_QUEST_BRAVE_SYMBOL_GOLD         42
#define SUB_QUEST_ABILITY_SYMBOL_GOLD       43

#define QUEST_MAIN_STORY_SUB_COUNT          10
#define QUEST_CONTEST_STAR_COOL_SUB_COUNT   4
#define QUEST_CONTEST_STAR_CUTE_SUB_COUNT   4
#define QUEST_CONTEST_STAR_BEAUTY_SUB_COUNT 4
#define QUEST_CONTEST_STAR_SMART_SUB_COUNT  4
#define QUEST_CONTEST_STAR_TOUGH_SUB_COUNT  4
#define QUEST_FRONTIER_SILVER_SUB_COUNT     7
#define QUEST_FRONTIER_GOLD_SUB_COUNT       7
#define SUB_QUEST_COUNT                     (SUB_QUEST_ABILITY_SYMBOL_GOLD + 1) // 44/168 138 free spaces left

#define QUEST_ARRAY_COUNT (SUB_QUEST_COUNT > QUEST_COUNT ? SUB_QUEST_COUNT : QUEST_COUNT)
#endif // GUARD_CONSTANTS_QUESTS_H
