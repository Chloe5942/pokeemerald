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
#define QUEST_SPECIAL_DELIVERY               2
#define QUEST_TREND_SETTER                   3
#define QUEST_PUZZLE_SOLVER                  4
#define QUEST_MAIL_RUN                       5
#define QUEST_COIN_COLLECTOR                 6
#define QUEST_CONTEST_STAR                   7
// Post Game
#define QUEST_FRONTIER_WELCOME               8
#define QUEST_FRONTIER_EXPLORER              9
#define QUEST_GIGANTIC_FINDINGS             10
#define QUEST_SEAFARER                      11
#define QUEST_COUNT                         (QUEST_SEAFARER + 1) // 12/100 88 Free Spaces Left

#define SUB_QUEST_DUMMY               0

/*
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
// Puzzle Solver
#define SUB_QUEST_FIRST_PUZZLE              13
#define SUB_QUEST_SECOND_PUZZLE             14
#define SUB_QUEST_THIRD_PUZZLE              15
#define SUB_QUEST_FOURTH_PUZZLE             16
#define SUB_QUEST_FIFTH_PUZZLE              17
#define SUB_QUEST_SIXTH_PUZZLE              18
#define SUB_QUEST_SEVENTH_PUZZLE            19
#define SUB_QUEST_EIGHTH_PUZZLE             20
// Contest Star
#define SUB_QUEST_CONTEST_COOL              21
#define SUB_QUEST_CONTEST_CUTE              22
#define SUB_QUEST_CONTEST_BEAUTY            23
#define SUB_QUEST_CONTEST_SMART             24
#define SUB_QUEST_CONTEST_TOUGH             25
// Frontier Explorer
#define SUB_QUEST_BATTLE_FACTORY            26
#define SUB_QUEST_BATTLE_ARENA              27
#define SUB_QUEST_BATTLE_DOME               28
#define SUB_QUEST_BATTLE_PIKE               29
#define SUB_QUEST_BATTLE_PALACE             30
#define SUB_QUEST_BATTLE_PYRAMID            31
#define SUB_QUEST_BATTLE_TOWER              32
// Gigantic Findings
#define SUB_QUEST_SEALED_DEPTHS             33
#define SUB_QUEST_RUINS_IN_THE_SANDS        34
#define SUB_QUEST_CAVE_OF_SOLITUDE          35
#define SUB_QUEST_TOMB_OF_THE_ANCIENTS      36
// Seafarer
#define SUB_QUEST_AURORA_TICKET             37
#define SUB_QUEST_EON_TICKET                38
#define SUB_QUEST_MYSTIC_TICKET             39
#define SUB_QUEST_OLD_SEA_MAP               40
*/

#define QUEST_DUMMY_SUB_COUNT      1
/*
#define QUEST_RIVAL_NEXT_DOOR_SUB_COUNT      5
#define QUEST_SCOUTING_SCOTT_SUB_COUNT       8
#define QUEST_PUZZLE_SOLVER_SUB_COUNT        8
#define QUEST_CONTEST_STAR_SUB_COUNT         5
#define QUEST_FRONTIER_EXPLORER_SUB_COUNT    7
#define QUEST_GIGANTIC_FINDINGS_SUB_COUNT    4
#define QUEST_SEAFARER_SUB_COUNT             4
*/
#define SUB_QUEST_COUNT (QUEST_DUMMY_SUB_COUNT) // 1/168 167 Free Spaces Left

#define QUEST_ARRAY_COUNT (SUB_QUEST_COUNT > QUEST_COUNT ? SUB_QUEST_COUNT : QUEST_COUNT)
#endif // GUARD_CONSTANTS_QUESTS_H
