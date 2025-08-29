#ifndef GUARD_COMPLEX_QUESTS_H
#define GUARD_COMPLEX_QUESTS_H

#include "global.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_use.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "quests.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "event_object_movement.h"
#include "pokemon_icon.h"

//////////////////////////////////////////
////////////BEGIN QUEST NUMS//////////////

/* These will be where the number of descriptions and maps a quest has will be controlled.*/

enum RivalNextDoor_States{
    QUEST_RIVAL_NEXT_DOOR_STATE_1, // Route 103
    QUEST_RIVAL_NEXT_DOOR_STATE_2, // Rustboro City or Route 104
    QUEST_RIVAL_NEXT_DOOR_STATE_3, // Route 110
    QUEST_RIVAL_NEXT_DOOR_STATE_4, // Route 119
    QUEST_RIVAL_NEXT_DOOR_STATE_5, // Lilycove City
    QUEST_RIVAL_NEXT_DOOR_TOTAL_STATES,
};

enum ScoutingScott_States{
    QUEST_SCOUTING_SCOTT_STATE_1, // Rustboro City
    QUEST_SCOUTING_SCOTT_STATE_2, // Rustboro City
    QUEST_SCOUTING_SCOTT_STATE_3, // Slateport City
    QUEST_SCOUTING_SCOTT_STATE_4, // Verdanturf City
    QUEST_SCOUTING_SCOTT_STATE_5, // Fallabor City
    QUEST_SCOUTING_SCOTT_STATE_6, // Lilycove City
    QUEST_SCOUTING_SCOTT_STATE_7, // Mossdeep City
    QUEST_SCOUTING_SCOTT_STATE_8, // Ever Grande City
    QUEST_SCOUTING_SCOTT_TOTAL_STATES,
};

enum PuzzleSolver_States{
    QUEST_PUZZLE_SOLVER_STATE_1, // Solve the Puzzle: Maze of Trees
    QUEST_PUZZLE_SOLVER_STATE_2, // Return after obtaining the Dynamo Badge
    QUEST_PUZZLE_SOLVER_STATE_3, // Solve the Puzzle: Switchy Situation
    QUEST_PUZZLE_SOLVER_STATE_4, // Return after obtaining the Heat Badge
    QUEST_PUZZLE_SOLVER_STATE_5, // Solve the Puzzle: Maze of Doors
    QUEST_PUZZLE_SOLVER_STATE_6, // Return after obtaining the Balance Badge
    QUEST_PUZZLE_SOLVER_STATE_7, // Solve the Puzzle: Bouldering Boulders
    QUEST_PUZZLE_SOLVER_STATE_8, // Return after obtaining the Feather Badge
    QUEST_PUZZLE_SOLVER_STATE_9, // Solve the Puzzle: Mind Games
    QUEST_PUZZLE_SOLVER_STATE_10, // Return after obtaining the Mind Badge
    QUEST_PUZZLE_SOLVER_STATE_11, // Solve the Puzzle: Gated Paths
    QUEST_PUZZLE_SOLVER_STATE_12, // Return after obtaining the Rain Badge
    QUEST_PUZZLE_SOLVER_STATE_13, // Solve the Puzzle: Teleport and Spin
    QUEST_PUZZLE_SOLVER_STATE_14, // Return after beating the Champion
    QUEST_PUZZLE_SOLVER_STATE_15, // Solve the Puzzle: Slippery Floor
    QUEST_PUZZLE_SOLVER_TOTAL_STATES,
};

enum ContestStar_States{
    QUEST_CONTEST_STAR_STATE_1, // Enter a Cool Contest
    QUEST_CONTEST_STAR_STATE_2, // Enter a Cute Contest
    QUEST_CONTEST_STAR_STATE_3, // Enter a Beauty Contest
    QUEST_CONTEST_STAR_STATE_4, // Enter a Smart Contest
    QUEST_CONTEST_STAR_STATE_5, // Enter a Tough Contest
    QUEST_CONTEST_STAR_TOTAL_STATES,
};

enum FrontierExplorer_States{
    QUEST_FRONTIER_EXPLORER_STATE_1, // Go to the Battle Arena
    QUEST_FRONTIER_EXPLORER_STATE_2, // Go to the Battle Dome
    QUEST_FRONTIER_EXPLORER_STATE_3, // Go to the Battle Factory
    QUEST_FRONTIER_EXPLORER_STATE_4, // Go to the Battle Palace
    QUEST_FRONTIER_EXPLORER_STATE_5, // Go to the Battle Pike
    QUEST_FRONTIER_EXPLORER_STATE_6, // Go to the Battle Pyramid
    QUEST_FRONTIER_EXPLORER_STATE_7, // Go to the Battle Tower
    QUEST_FRONTIER_EXPLORER_STATE_8, // Return to Scott's House
    QUEST_FRONTIER_EXPLORER_TOTAL_STATES,
};

enum GiganticFindings_States{
    QUEST_GIGANTIC_FINDINGS_STATE_1, // Go to the Sealed Chamber
    QUEST_GIGANTIC_FINDINGS_STATE_2, // Return to the Research Lab
    QUEST_GIGANTIC_FINDINGS_STATE_3, // Go to the Desert Ruins
    QUEST_GIGANTIC_FINDINGS_STATE_4, // Return to the Research Lab
    QUEST_GIGANTIC_FINDINGS_STATE_5, // Go to the Island Cave
    QUEST_GIGANTIC_FINDINGS_STATE_6, // Return to the Research Lab
    QUEST_GIGANTIC_FINDINGS_STATE_7, // Go to the Ancient Tomb
    QUEST_GIGANTIC_FINDINGS_STATE_8, // Return to the Research Lab
    QUEST_GIGANTIC_FINDINGS_TOTAL_STATES,
};

/////////////END QUEST NUMS/////////////
////////////////////////////////////////

#endif