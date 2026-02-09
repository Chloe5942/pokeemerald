# ABOUT

This is a fork of the [matching decompilation](https://github.com/pret/pokeemerald) at [PRET](https://github.com/pret).

This fork tries to maintain vanilla compatibility whenever possible. It doesn't increase the size of any save data structure or the object event structure.

There are several branches, each with one main feature (and sometimes some extra stuff):

**followers** branch:
* [HGSS-style pokémon followers](https://bulbapedia.bulbagarden.net/wiki/Walking_Pok%C3%A9mon#Pok.C3.A9mon_HeartGold_and_SoulSilver) for all 386 pokémon (including forms & shinies)
* Includes follower emotes and a majority of the HGSS messages
* Custom pokeball sprites for Gen 1-7 pokéballs
* Followers can use field moves in the overworld
* Overworld form changes for Ditto, Mew, Castform, etc.
* Asymmetrical & 64x64 OW support
* Dynamic Overworld Palette System (DOWP) & reflections compatible with berry trees, etc.

> Note: Unless you have a specific need for it, you should probably use `followers-expanded-id` over this.

![Pokeball](https://i.imgur.com/OMbS67Q.gif)
![Messages](https://i.imgur.com/sTbGVEY.gif)
![Forms](https://i.imgur.com/wDhFNf4.gif)
![HM](https://i.imgur.com/lnXJGHd.gif)

**icons** branch:
* Everything from the **followers** branch.
* All pokemon icons updated to Gen 6, based on [this repo](https://github.com/msikma/pokesprite/tree/master/icons/pokemon/regular)
* This includes compatibility with the PC, trade, contests, mail, Battle Dome. Examples:
![PC](https://i.imgur.com/wzwJfd1.png)
![Party](https://i.imgur.com/8hbE88t.png)
![Contest](https://i.imgur.com/S9mCEFL.png)
* Icons share palettes with front sprites, meaning that shiny pokemon will also have shiny icons!

**lighting** branch:
* Everything from the **followers** branch.
* Day/night shading compatible with weather.
* GSC-style window lights.
* WIP interframe-blended lamp lights at night, i.e in Rustboro.
* HGSS-style alpha-blended shadows for object events.

**just-lighting** branch:
* `lighting-expanded-id` but with following pokémon code & assets completely removed. (This allows for more than 255 OW graphics)
* Saves with following pokémon can still safely be loaded.

**followers-expanded-id** branch:
* Like `followers`, but includes expands OW graphicsIds to 16-bits
in a backwards compatible way
* Includes support for compressed OW graphics

Additional branches to mention:

* `lighting-expanded-id` - like the above but for `lighting`.
# About this branch
This is a decapitalized (all-caps text replaced with proper capitalization) version of the [**pokeemerald**](https://travis-ci.org/pret/pokeemerald) dissasembly, originally made by [**Wyrserth**](https://github.com/Wyrserth) and adapted to the current structure of the project.

It builds the following ROM:

* pokeemerald.gba `sha1: 8C19F2555E10DFF32A9914CEAC360B018AF42E6C`

To set up the repository, see [INSTALL.md](INSTALL.md).

**guillotine** branch:
* ~~Decapitates~~ Decapitalizes **all** text at runtime, with some exceptions (see the [FAQ](#guillotine-q-how-can-i-keep-my-strings-from-being-decapped))
* Future-proof, does not require mass-replacing strings
Credit `Voluptua` (me) and `Pawkkie` if you are using this branch! 

This branch contains a custom start menu for vanilla pokeemerald. 
It's compatible with Dynamic Overworld Palettes and with the safari zone. 

### IMPORTANT:
I am no professional and there are infinite other ways to write the code better than I do. I realized that it could have been heavily improved. So adding a new menu option is REALLY difficult! (But you can change the current menu options, like I do for my Hack). 
However, there's another problem. If you use this for your hack and in your storyline, you change the order of what new menu option is added, you have to change some horrible functions I have created :smile: .
New options are added like this: `First the Party option, then the PokeDex and then the PokeNav`. So if the player in your hack, gets these menus in a different order, you will have a hard time to fix this... 

### SHOWCASE: 
![Normal](https://github.com/Voluptua/pokeemerald/blob/start_menu_1/normal.gif)
![Safari](https://github.com/Voluptua/pokeemerald/blob/start_menu_1/safari.gif)

## FAQ
### `(followers*)` Q: Where are the config settings?
A: Configuration for the follower system is mostly in [event_objects.h](include/constants/event_objects.h):
```c
// If true, follower pokemon will bob up and down
// during their idle & walking animations
#define OW_MON_BOBBING  TRUE

// If true, adds a small amount of overhead
// to OW code so that large (48x48, 64x64) OWs
// will display correctly under bridges, etc.
#define LARGE_OW_SUPPORT TRUE

// Followers will emerge from the pokeball they are stored in,
// instead of a normal pokeball
#define OW_MON_POKEBALLS TRUE

// New/old handling for followers during scripts;
// TRUE: Script collisions hide follower, FLAG_SAFE_FOLLOWER_MOVEMENT on by default
// (scripted player movement moves follower too!)
// FALSE: Script collisions unhandled, FLAG_SAFE_FOLLOWER_MOVEMENT off by default
#define OW_MON_SCRIPT_MOVEMENT TRUE

// If set, the only pokemon allowed to follow you
// will be those matching species, met location,
// and/or met level;
// These accept vars, too: VAR_TEMP_1, etc
#define OW_MON_ALLOWED_SPECIES (0)
#define OW_MON_ALLOWED_MET_LVL (0)
#define OW_MON_ALLOWED_MET_LOC (0)
```

### `(lighting)` Q: How do I mark certain colors in a palette as light-blended?
A: Create a `.pla` file in the same folder as the `.pal` with the same name.

In this file you can enter color indices [0,15]
on separate lines to mark those colors as being light-blended, i.e:

`06.pla:`
```
# A comment
0 # if color 0 is listed, uses it to blend with instead of the default!
1
9
10
```

You might have to `make mostlyclean` or change the `.pal` file to pick up the changes.

### `(guillotine)` Q: How can I keep my string(s) from being decapped?
A: There are a number of ways to make a string "fixed case" so that it will not be decapitalized when displayed:

C strings: Replace the `_` with `_C`:
```c
// _C = fixed (C)ase string!
const u8 gText_IDNumber[] = _C("IDNo.");
```
ASM strings: Replace `.string` with `.fixstr`:
```arm
gText_SavingDontTurnOff::
    @ Lasts until the string terminator '$'
	.fixstr "SAVING…\n"
	.string "DON'T TURN OFF THE POWER.$"
```
You can fix-case/unfix parts of a string like so:
```arm
	.string "{FIXED_CASE}WARNING!{UNFIX_CASE}\p"
```
For a placeholder (only the placeholder will be fixed-case):
```arm
	.string "{STR_VAR_2_FIXED} was transferred to\n"
	.string "BOX “{STR_VAR_1}.”$"
```
See also the configuration in [text.h](gflib/text.h).

There's also special handling for "separated bigrams"; basically, two letter words.
This includes: `"TM01", "PC", "EV"`, any two uppercase characters surrounded by digits, whitespace, or the start/end of a string. These will not be decapped.

## See also

## FAQ
### `(followers*)` Q: Where are the config settings?
A: Configuration for the follower system is mostly in [event_objects.h](include/constants/event_objects.h):
```c
// If true, follower pokemon will bob up and down
// during their idle & walking animations
#define OW_MON_BOBBING  TRUE

// If true, adds a small amount of overhead
// to OW code so that large (48x48, 64x64) OWs
// will display correctly under bridges, etc.
#define LARGE_OW_SUPPORT TRUE
```

### `(lighting)` Q: How do I mark certain colors in a palette as light-blended?
A: Create a `.pla` file in the same folder as the `.pal` with the same name.

In this file you can enter color indices [0,15]
on separate lines to mark those colors as being light-blended, i.e:

`06.pla:`
```
# A comment
0 # if color 0 is listed, uses it to blend with instead of the default!
1
9
10
```

You might have to `make mostlyclean` or change the `.pal` file to pick up the changes.

## See also

### TODO: 
- Add tutorials
- Make a pokeemerald-expansion branch for this
