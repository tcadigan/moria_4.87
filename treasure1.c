#include "constants.h"
#include "config.h"
#include "types.h"

/* Following are treasure arrays and variables */
/*
 * Object description: Objects are defined here. Each object has the following
 *  attributes:
 *      Descriptor: Name of item and formats.
 *         %C is replaced with a random color.
 *	   %W is replaced with a random wood.
 *	   %M is replaced with a random metal.
 *	   %R is replaced with a random rock.
 *	   %P1 is replaced with the number in P1 {see below}.
 *	   %P2 is replaced with plus-to-hit.
 *	   %P3 is replaced with plus-to-damage.
 *	   %P4 is replaced with plus-to-AC.
 *	   %P5 is replaced with number in P1, no sign.
 *	   & is replaced with 'a', 'an', or a number.
 *	   ~ is replaced with null or 's'.
 *     Character: Character that represents the item.
 *     Type value: Value representing the type of object.
 *         1   ~ Miscellaneous object.
 *	   2   & Chest.
 *	   10  {Left curly brace} Sling ammo.
 *	   11  {Left curly brace} Bolt.
 *	   12  {Left curly brace} Arrow.
 *	   13  ~ Spike.
 *	   15  ~ Lamp or Torch.
 *	   20  {Right curly brace} Bow, crossbow, or sling.
 *	   21  / Hafted weapon.
 *	   22  \ Pole arm.
 *	   23  | Sword or dagger.
 *	   30  ] Boots.
 *	   31  ] Gloves and gauntlets.
 *	   32  ( Cloak.
 *	   33  ] Helm.
 *	   34  ) Shield.
 *	   35  [ Hard armor.
 *	   36  ( Soft armor.
 *	   40  " Amulet.
 *	   45  = Ring.
 *	   55  _ Staff.
 *	   60  - Rod.
 *	   65  - Wand.
 *	   70  ? Scroll.
 *	   71  ? Scroll (continued).
 *	   75  ! Potion.
 *	   76  ! Potion (continued).
 *	   77  ! Flask of oil.
 *	   80  , Food.
 *	   90  ? Magic book.
 *	   91  ? Prayer book.
 *	   100 $ Valuable metal.
 *	   101 * Valuable gems.
 *	   102 . Unseen trap.
 *	   103 : Rubble.
 *	   104 ' Open door.
 *	   105 + Closed door.
 *	   107 < Up staircase.
 *	   108 > Down staircase.
 *	   109 # Secret door.
 *	   110 1,2,3,4,5,6 Entrance to store.
 *     Sub value: Separate value for each item of a type.
 *     Damage: Amount of damage item can cause.
 *     Weight: Number of items appearing in group
 *             If items can be added together 
 *	           then subval > 255
 *	       If items are considered one unit when added together
 *	           then subval > 511
 *     To hit: Magical plusses to hit.
 *     To damange : Magical plusses to damage.
 *     AC: Objects relatve armor class. 
 *         1 is worse than 5 is worse than 10 etc...
 *     To AC: Magical bonuses to AC.
 *     P1: Catch all for magical abilities such as plusses to strength,
 *         minuses to searching...
 *     Flags: Abilities of object. Each ability is a bit. 
 *            Bits 1-31 are used (signed integer).
 *
 *            Flags used for anything that can be worn or wielded:
 *	          Bit #    Hex #       Ability
 *		  1        00000001    Strength
 *		  2        00000002    Dexterity
 *		  3        00000004    Constitution
 *		  4        00000008    Intelligence
 *		  5        00000010    Wisdom
 *		  6        00000020    Charisma
 *		  7        00000040    Searching
 *		  8        00000080    Slow digestion
 *		  9        00000100    Stealth
 *		  10       00000200    Aggravation
 *		  11       00000400    Teleportation
 *		  12       00000800    Regeneration
 *		  13       00001000    Speed
 *		  14       00002000    Slay dragon
 *		  15       00004000    Slay monster
 *		  16       00008000    Slay Evil
 *		  17       00010000    Slay undead
 *		  18       00020000    Cold brand
 *		  19       00040000    Flame brand
 *		  20       00080000    Resist fire
 *		  21       00100000    Resist acid
 *		  22       00200000    Resist cold
 *		  23       00400000    Sustain stat (P1)
 *		  24       00800000    Free action
 *		  25       01000000    See invisible
 *		  26       02000000    Resist lightning
 *		  27       04000000    Feather fall
 *		  28       08000000    Blindness
 *		  29       10000000    Timidness
 *		  30       20000000    Tunneling
 *		  31       40000000    Infra vision
 *		  32       80000000    Cursed
 *     Level: Minimum level on which item can be found.
 *     Cost: Relative cost of item.
 *
 *     Special Abilities can be added to item by MAGIC_INIT, found in MISC.INC.
 *
 *     Scrolls, potions and Food: Flags is used to define a function which
 *                                reading/quaffing will cause. Most scrolls and
 *				  potions have only one bit set. Potions will
 *		                  generally have some food value, found in P1.
 *     Wands and staffs: Flags defines a function, P1 contains number of charges
 *                       for item. P1 is set in MAGIC_INIT (MISC.INC).
 *     Chests: Traps are added randomly by MAGIC.INIT in MISC.INC.
 */
/* Object list (All objects must be defined here) */
treasure_type object_list[MAX_OBJECTS] = {
    { "& %M Mushroom~| of Poison"                         , 80,  ',', 0x00000001,  500,    0, 257,    1, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %M Mushroom~| of Blindness"                      , 80,  ',', 0x00000002,  500,    0, 258,    1, 1,    0,  0,  0,  0,   "0d0",  9 },
    { "& %M Mushroom~| of Paranoia"                       , 80,  ',', 0x00000004,  500,    0, 259,    1, 1,    0,  0,  0,  0,   "0d0",  9 },
    { "& %M Mushroom~| of Confusion"                      , 80,  ',', 0x00000008,  500,    0, 260,    1, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %M Mushroom~| of Hallucination"                  , 80,  ',', 0x00000010,  500,    0, 261,    1, 1,    0,  0,  0,  0,   "0d0", 13 },
    { "& %M Mushroom~| of Cure Poison"                    , 80,  ',', 0x00000020,  500,   60, 262,    1, 1,    0,  0,  0,  0,   "0d0",  8 },
    { "& %M Mushroom~| of Cure Blindness"                 , 80,  ',', 0x00000040,  500,   50, 263,    1, 1,    0,  0,  0,  0,   "0d0", 10 },
    { "& %M Mushroom~| of Cure Paranoia"                  , 80,  ',', 0x00000080,  500,   25, 264,    1, 1,    0,  0,  0,  0,   "0d0", 12 },
    { "& %M Mushroom~| of Cure confusion"                 , 80,  ',', 0x00000100,  500,   50, 265,    1, 1,    0,  0,  0,  0,   "0d0",  6 },
    { "& %M Mushroom~| of Weakness"                       , 80,  ',', 0x04000200,  500,    0, 266,    1, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %M Mushroom~| of Unhealth"                       , 80,  ',', 0x04000400,  500,   50, 267,    1, 1,    0,  0,  0,  0, "10d10", 15 },
    { "& %M Mushroom~| of Restore Constitution"           , 80,  ',', 0x00010000,  500,  350, 268,    1, 1,    0,  0,  0,  0,   "0d0", 20 },
    { "& %M Mushroom~| of First-Aid"                      , 80,  ',', 0x00200000,  500,    5, 269,    1, 1,    0,  0,  0,  0,   "0d0",  6 },
    { "& %M Mushroom~| of Minor Cures"                    , 80,  ',', 0x00400000,  500,   20, 270,    1, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %M Mushroom~| of Light Cures"                    , 80,  ',', 0x00800000,  500,   30, 271,    1, 1,    0,  0,  0,  0,   "0d0", 10 },
    { "& %M Mushroom~| of Restoring"                      , 80,  ',', 0x001F8040,  500, 1000, 272,    1, 1,    0,  0,  0,  0,   "0d0", 30 },
    { "& Hairy %M Mold~| of Poison"                       , 80,  ',', 0x00000001, 1200,    0, 273,    1, 1,    0,  0,  0,  0,   "0d0", 15 },
    { "& Hairy %M Mold~| of Hallucinations"               , 80,  ',', 0x00000010, 1200,    0, 274,    1, 1,    0,  0,  0,  0,   "0d0", 18 },
    { "& Hairy %M Mold~| of Cure Poison"                  , 80,  ',', 0x00000020, 1200,   75, 275,    1, 1,    0,  0,  0,  0,   "0d0", 19 },
    { "& Hairy %M Mold~| of Unhealth"                     , 80,  ',', 0x00000400, 1200,   25, 276,    1, 1,    0,  0,  0,  0,   "6d8", 28 },
    { "& Hairy %M Mold~| of Cure Serious Wounds"          , 80,  ',', 0x02000000, 1200,   75, 277,    2, 1,    0,  0,  0,  0,   "0d0", 16 },
    { "& Ration~ of Food"                                 , 80,  ',', 0x00000000, 5000,    3, 307,   10, 1,    0,  0,  0,  0,   "0d0",  0 },
    { "& Ration~ of Food"                                 , 80,  ',', 0x00000000, 5000,    3, 307,   10, 1,    0,  0,  0,  0,   "0d0",  5 },
    { "& Ration~ of Food"                                 , 80,  ',', 0x00000000, 5000,    3, 307,   10, 1,    0,  0,  0,  0,   "0d0", 10 },
    { "& Slime Mold~"                                     , 80,  ',', 0x00000000, 3000,    2, 308,    5, 1,    0,  0,  0,  0,   "0d0",  1 },
    { "& Piece~ of Elvish Waybread"                       , 80,  ',', 0x02000020, 7500,   10, 313,    3, 1,    0,  0,  0,  0,   "0d0",  6 },
    { "& Piece~ of Elvish Waybread"                       , 80,  ',', 0x02000020, 7500,   10, 313,    3, 1,    0,  0,  0,  0,   "0d0", 12 },
    { "& Piece~ of Elvish Waybread"                       , 80,  ',', 0x02000020, 7500,   10, 313,    3, 1,    0,  0,  0,  0,   "0d0", 20 },
    { "& Dagger (Main Gauche)^ (%P2,%P3)"                 , 23,  '|', 0x00000000,    0,   25,   1,   30, 1,    0,  0,  0,  0,   "1d5",  2 },
    { "& Dagger (Misericorde)^ (%P2,%P3)"                 , 23,  '|', 0x00000000,    0,   10,   2,   15, 1,    0,  0,  0,  0,   "1d4",  0 },
    { "& Dagger (Stiletto)^ (%P2,%P3)"                    , 23,  '|', 0x00000000,    0,   10,   3,   12, 1,    0,  0,  0,  0,   "1d4",  0 },
    { "& Dagger (Bodkin)^ (%P2,%P3)"                      , 23,  '|', 0x00000000,    0,   10,   4,   20, 1,    0,  0,  0,  0,   "1d4",  1 },
    { "& Broken Dagger^ (%P2,%P3)"                        , 23,  '|', 0x00000000,    0,    0,   5,   15, 1,   -2, -2,  0,  0,   "1d1",  0 },
    { "& Backsword^ (%P2,%P3)"                            , 23,  '|', 0x00000000,    0,   60,   6,   95, 1,    0,  0,  0,  0,   "1d9",  7 },
    { "& Bastard Sword^ (%P2,%P3)"                        , 23,  '|', 0x00000000,    0,  350,   7,  140, 1,    0,  0,  0,  0,   "3d4", 14 },
    { "& Thrusting Sword (Bilbo)^ (%P2,%P3)"              , 23,  '|', 0x00000000,    0,   60,   8,   80, 1,    0,  0,  0,  0,   "1d6",  4 },
    { "& Thrusting Sword (Baselard)^ (%P2,%P3)"           , 23,  '|', 0x00000000,    0,   80,   9,  100, 1,    0,  0,  0,  0,   "1d7",  5 },
    { "& Broadsword^ (%P2,%P3)"                           , 23,  '|', 0x00000000,    0,  255,  10,  150, 1,    0,  0,  0,  0,   "2d5",  9 },
    { "& Two-Handed Sword (Claymore)^ (%P2,%P3)"          , 23,  '|', 0x00000000,    0,  755,  11,  200, 1,    0,  0,  0,  0,   "3d6", 30 },
    { "& Cutlass^ (%P2,%P3)"                              , 23,  '|', 0x00000000,    0,   85,  12,  110, 1,    0,  0,  0,  0,   "1d7",  7 },
    { "& Two-Handed Sword (Espadon)^ (%P2,%P3)"           , 23,  '|', 0x00000000,    0,  655,  13,  180, 1,    0,  0,  0,  0,   "3d6", 35 },
    { "& Executioner's Sword^ (%P2,%P3)"                  , 23,  '|', 0x00000000,    0,  850,  14,  260, 1,    0,  0,  0,  0,   "4d5", 40 },
    { "& Two-Handed Sword (Flamberge)^ (%P2,%P3)"         , 23,  '|', 0x00000000,    0, 1000,  15,  240, 1,    0,  0,  0,  0,   "4d5", 45 },
    { "& Foil^ (%P2,%P3)"                                 , 23,  '|', 0x00000000,    0,   35,  16,   30, 1,    0,  0,  0,  0,   "1d5",  2 },
    { "& Katana^ (%P2,%P3)"                               , 23,  '|', 0x00000000,    0,  400,  17,  120, 1,    0,  0,  0,  0,   "3d4", 18 },
    { "& Longsword^ (%P2,%P3)"                            , 23,  '|', 0x00000000,    0,  300,  18,  130, 1,    0,  0,  0,  0,  "1d10", 12 },
    { "& Two-Handed Sword (No-Dachi)^ (%P2,%P3)"          , 23,  '|', 0x00000000,    0,  675,  19,  200, 1,    0,  0,  0,  0,   "4d4", 45 },
    { "& Rapier^ (%P2,%P3)"                               , 23,  '|', 0x00000000,    0,   42,  20,   40, 1,    0,  0,  0,  0,   "1d6",  4 },
    { "& Sabre^ (%P2,%P3)"                                , 23,  '|', 0x00000000,    0,   50,  21,   50, 1,    0,  0,  0,  0,   "1d7",  5 },
    { "& Small Sword^ (%P2,%P3)"                          , 23,  '|', 0x00000000,    0,   48,  22,   75, 1,    0,  0,  0,  0,   "1d6",  5 },
    { "& Two-Handed Sword (Zweihander)^ (%P2,%P3)"        , 23,  '|', 0x00000000,    0, 1000,  23,  280, 1,    0,  0,  0,  0,   "4d6", 50 },
    { "& Broken Sword^ (%P2,%P3)"                         , 23,  '|', 0x00000000,    0,    0,  24,   75, 1,   -2, -2,  0,  0,   "1d1",  0 },
    { "& Battle Axe (Balestarius)^ (%P2,%P3)"             , 21, '\\', 0x00000000,    0,  500,   1,  180, 1,    0,  0,  0,  0,   "2d8", 30 },
    { "& Ball and Chain^ (%P2,%P3)"                       , 21, '\\', 0x00000000,    0,  200,   2,  150, 1,    0,  0,  0,  0,   "2d4", 20 },
    { "& Battle Axe (European)^ (%P2,%P3)"                , 21, '\\', 0x00000000,    0,  334,   3,  170, 1,    0,  0,  0,  0,   "3d4", 13 },
    { "& Broad Axe^ (%P2,%P3)"                            , 21, '\\', 0x00000000,    0,  304,   4,  160, 1,    0,  0,  0,  0,   "2d6", 17 },
    { "& Cat-O-Nine Tails^ (%P2,%P3)"                     , 21, '\\', 0x00000000,    0,   14,   5,   40, 1,    0,  0,  0,  0,   "1d4",  3 },
    { "& Wooden Club^ (%P2,%P3)"                          , 21, '\\', 0x00000000,    0,    1,   6,  100, 1,    0,  0,  0,  0,   "1d3",  0 },
    { "& Flail^ (%P2,%P3)"                                , 21, '\\', 0x00000000,    0,  353,   7,  150, 1,    0,  0,  0,  0,   "2d6", 12 },
    { "& Two-Handed Great Flail^ (%P2,%P3)"               , 21, '\\', 0x00000000,    0,  590,   8,  280, 1,    0,  0,  0,  0,   "3d6", 45 },
    { "& Morningstar^ (%P2,%P3)"                          , 21, '\\', 0x00000000,    0,  396,   9,  150, 1,    0,  0,  0,  0,   "2d6", 10 },
    { "& Mace^ (%P2,%P3)"                                 , 21, '\\', 0x00000000,    0,  130,  10,  120, 1,    0,  0,  0,  0,   "2d4",  6 },
    { "& War Hammer^ (%P2,%P3)"                           , 21, '\\', 0x00000000,    0,  225,  11,  120, 1,    0,  0,  0,  0,   "3d3",  5 },
    { "& Mace (Lead-filled)^ (%P2,%P3)"                   , 21, '\\', 0x00000000,    0,  502,  12,  180, 1,    0,  0,  0,  0,   "3d4", 15 },
    { "& Awl-Pike^ (%P2,%P3)"                             , 22,  '/', 0x00000000,    0,  340,   1,  160, 1,    0,  0,  0,  0,   "1d8",  8 },
    { "& Beaked Axe^ (%P2,%P3)"                           , 22,  '/', 0x00000000,    0,  408,   2,  180, 1,    0,  0,  0,  0,   "2d6", 15 },
    { "& Fauchard^ (%P2,%P3)"                             , 22,  '/', 0x00000000,    0,  376,   3,  170, 1,    0,  0,  0,  0,  "1d10", 17 },
    { "& Glaive^ (%P2,%P3)"                               , 22,  '/', 0x00000000,    0,  363,   4,  190, 1,    0,  0,  0,  0,   "2d6", 20 },
    { "& Halberd^ (%P2,%P3)"                              , 22,  '/', 0x00000000,    0,  430,   5,  190, 1,    0,  0,  0,  0,   "3d4", 22 },
    { "& Lucerne Hammer^ (%P2,%P3)"                       , 22,  '/', 0x00000000,    0,  376,   6,  120, 1,    0,  0,  0,  0,   "2d5", 11 },
    { "& Pike^ (%P2,%P3)"                                 , 22,  '/', 0x00000000,    0,  358,   7,  160, 1,    0,  0,  0,  0,   "2d5", 15 },
    { "& Spear^ (%P2,%P3)"                                , 22,  '/', 0x00000000,    0,   36,   8,   50, 1,    0,  0,  0,  0,   "1d6",  5 },
    { "& Lance^ (%P2,%P3)"                                , 22,  '/', 0x00000000,    0,  230,   9,  300, 1,    0,  0,  0,  0,   "2d8", 10 },
    { "& Javelin^ (%P2,%P3)"                              , 22,  '/', 0x00000000,    0,   18,  10,   30, 1,    0,  0,  0,  0,   "1d4",  4 },
    { "& Short Bow^ (%P2)"                                , 20,  '}', 0x00000000,    2,   50,   1,   30, 1,    0,  0,  0,  0,   "0d0",  3 },
    { "& Long Bow^ (%P2)"                                 , 20,  '}', 0x00000000,    3,  120,   2,   40, 1,    0,  0,  0,  0,   "0d0", 10 },
    { "& Composite Bow^ (%P2)"                            , 20,  '}', 0x00000000,    4,  240,   3,   40, 1,    0,  0,  0,  0,   "0d0", 40 },
    { "& Light Crossbow^ (%P2)"                           , 20,  '}', 0x00000000,    5,  140,  10,  110, 1,    0,  0,  0,  0,   "0d0", 15 },
    { "& Heavy Crossbow^ (%P2)"                           , 20,  '}', 0x00000000,    6,  300,  11,  200, 1,    0,  0,  0,  0,   "0d0", 30 },
    { "& Sling^ (%P2)"                                    , 20,  '}', 0x00000000,    1,    5,  20,    5, 1,    0,  0,  0,  0,   "0d0",  1 },
    { "& Arrow~^ (%P2,%P3)"                               , 12,  '{', 0x00000000,    0,    1,   1,    2, 1,    0,  0,  0,  0,   "1d4",  2 },
    { "& Bolt~^ (%P2,%P3)"                                , 11,  '{', 0x00000000,    0,    2,   1,    3, 1,    0,  0,  0,  0,   "1d5",  2 },
    { "& Rounded Pebble~^ (%P2,%P3)"                      , 10,  '{', 0x00000000,    0,    1,   1,    4, 1,    0,  0,  0,  0,   "1d2",  0 },
    { "& Iron Shot~^ (%P2,%P3)"                           , 10,  '{', 0x00000000,    0,    2,   1,    5, 1,    0,  0,  0,  0,   "1d3",  3 },
    { "& Iron Spike~"                                     , 13,  '{', 0x00000000,    0,    1,   1,   10, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& Brass Lantern~ with %P5 turns of light"          , 15,  '~', 0x00000000, 7500,   35,   1,   50, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& Wooden Torch~ with %P5 turns of light"           , 15,  '~', 0x00000000, 4000,    2,  13,   30, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& Orcish Pick^ (%P1) (%P2,%P3)"                    , 25, '\\', 0x20000000,    2,  500,   2,  180, 1,    0,  0,  0,  0,   "1d3", 20 },
    { "& Dwarven Pick^ (%P1) (%P2,%P3)"                   , 25, '\\', 0x20000000,    3, 1200,   3,  200, 1,    0,  0,  0,  0,   "1d4", 50 },
    { "& Gnomish Shovel^ (%P1) (%P2,%P3)"                 , 25, '\\', 0x20000000,    1,  100,   5,   50, 1,    0,  0,  0,  0,   "1d2", 20 },
    { "& Dwarven Shovel^ (%P1) (%P2,%P3)"                 , 25, '\\', 0x20000000,    2,  250,   6,  120, 1,    0,  0,  0,  0,   "1d3", 40 },
    { "& Pair of Soft Leather Shoes^ [%P6,%P4]"           , 30,  ']', 0x00000000,    0,    4,   1,    5, 1,    0,  0,  1,  0,   "0d0",  1 },
    { "& Pair of Soft Leather Boots^ [%P6,%P4]"           , 30,  ']', 0x00000000,    0,    7,   2,   20, 1,    0,  0,  2,  0,   "1d1",  4 },
    { "& Pair of Hard Leather Boots^ [%P6,%P4]"           , 30,  ']', 0x00000000,    0,   12,   3,   40, 1,    0,  0,  3,  0,   "1d1",  6 },
    { "& Soft Leather Cap^ [%P4,%P6]"                     , 33,  ']', 0x00000000,    0,    4,   1,   10, 1,    0,  0,  1,  0,   "0d0",  2 },
    { "& Hard Leather Cap^ [%P6,%P4]"                     , 33,  ']', 0x00000000,    0,   12,   2,   15, 1,    0,  0,  2,  0,   "0d0",  4 },
    { "& Metal Cap^ [%P6,%P4]"                            , 33,  ']', 0x00000000,    0,   30,   3,   20, 1,    0,  0,  3,  0,   "1d1",  7 },
    { "& Iron Helm^ [%P6,%P4]"                            , 33,  ']', 0x00000000,    0,   75,   4,   75, 1,    0,  0,  5,  0,   "1d3", 20 },
    { "& Steel Helm^ [%P6,%P4]"                           , 33,  ']', 0x00000000,    0,  200,   5,   60, 1,    0,  0,  6,  0,   "1d3", 40 },
    { "& Silver Crown^ [%P6,%P4]"                         , 33,  ']', 0x00000000,    0,  250,   6,   20, 1,    0,  0,  0,  0,   "1d1", 44 },
    { "& Golden Crown^ [%P6,%P4]"                         , 33,  ']', 0x00000000,    0,  500,   7,   30, 1,    0,  0,  0,  0,   "1d1", 47 },
    { "& Jewel-Encrusted Crown^ [%P6,%P4]"                , 33,  ']', 0x00000000,    0, 1000,   8,   40, 1,    0,  0,  0,  0,   "1d1", 50 },
    { "& Robe^ [%P6,%P4]"                                 , 36,  '(', 0x00000000,    0,    4,   1,   20, 1,    0,  0,  2,  0,   "0d0",  1 },
    { "Soft Leather Armor^ [%P6,%P4]"                     , 36,  '(', 0x00000000,    0,   18,   2,   80, 1,    0,  0,  4,  0,   "0d0",  2 },
    { "Soft Studded Leather^ [%P6,%P4]"                   , 36,  '(', 0x00000000,    0,   35,   3,   90, 1,    0,  0,  5,  0,   "1d1",  3 },
    { "Hard Leather Armor^ [%P6,%P4]"                     , 36,  '(', 0x00000000,    0,   55,   4,  100, 1,   -1,  0,  6,  0,   "1d1",  5 },
    { "Hard Studded Leather^ [%P6,%P4]"                   , 36,  '(', 0x00000000,    0,  100,   5,  110, 1,   -1,  0,  7,  0,   "1d2",  7 },
    { "Woven Cord Armor^ [%P6,%P4]"                       , 36,  '(', 0x00000000,    0,   45,   6,  150, 1,   -1,  0,  6,  0,   "0d0",  7 },
    { "Soft Leather Ring Mail^ [%P6,%P4]"                 , 36,  '(', 0x00000000,    0,  160,   7,  130, 1,   -1,  0,  6,  0,   "1d2", 10 },
    { "Hard Leather Ring Mail^ [%P6,%P4]"                 , 36,  '(', 0x00000000,    0,  230,   8,  150, 1,   -2,  0,  8,  0,   "1d3", 12 },
    { "Leather Scale Mail^ [%P6,%P4]"                     , 36,  '(', 0x00000000,    0,  330,   9,  140, 1,   -1,  0, 11,  0,   "1d1", 14 },
    { "Metal Scale Mail^ [%P6,%P4]"                       , 35,  '[', 0x00000000,    0,  430,   1,  250, 1,   -2,  0, 13,  0,   "1d4", 24 },
    { "Chain Mail^ [%P6,%P4]"                             , 35,  '[', 0x00000000,    0,  530,   2,  220, 1,   -2,  0, 14,  0,   "1d4", 26 },
    { "Rusty Chain Mail^ [%P6,%P4]"                       , 35,  '[', 0x00000000,    0,    0,   3,  200, 1,   -5,  0, 14, -8,   "1d4", 26 },
    { "Double Chain Mail^ [%P6,%P4]"                      , 35,  '[', 0x00000000,    0,  630,   4,  260, 1,   -2,  0, 15,  0,   "1d4", 28 },
    { "Augmented Chain Mail^ [%P6,%P4]"                   , 35,  '[', 0x00000000,    0,  675,   5,  270, 1,   -2,  0, 16,  0,   "1d4", 30 },
    { "Bar Chain Mail^ [%P6,%P4]"                         , 35,  '[', 0x00000000,    0,  720,   6,  280, 1,   -2,  0, 18,  0,   "1d4", 34 },
    { "Metal Brigandine Armor^ [%P6,%P4]"                 , 35,  '[', 0x00000000,    0,  775,   7,  290, 1,   -3,  0, 19,  0,   "1d4", 36 },
    { "Laminated Armor^ [%P6,%P4]"                        , 35,  '[', 0x00000000,    0,  825,   8,  300, 1,   -3,  0, 20,  0,   "1d4", 38 },
    { "Partial Plate Armor^ [%P6,%P4]"                    , 35,  '[', 0x00000000,    0,  900,   9,  260, 1,   -3,  0, 22,  0,   "1d6", 42 },
    { "Metal Lamellar Armor^ [%P6,%P4]"                   , 35,  '[', 0x00000000,    0,  950,  10,  340, 1,   -3,  0, 23,  0,   "1d6", 44 },
    { "Full Plate Armor^ [%P6,%P4]"                       , 35,  '[', 0x00000000,    0, 1050,  11,  380, 1,   -3,  0, 25,  0,   "2d4", 48 },
    { "Ribbed Plate Armor^ [%P6,%P4]"                     , 35,  '[', 0x00000000,    0, 1200,  12,  380, 1,   -3,  0, 28,  0,   "2d4", 50 },
    { "& Cloak^ [%P6,%P4]"                                , 32,  '(', 0x00000000,    0,    3,   1,   10, 1,    0,  0,  1,  0,   "0d0",  1 },
    { "& Set of Leather Gloves^ [%P6,%P4]"                , 31,  ']', 0x00000000,    0,    3,   1,    5, 1,    0,  0,  1,  0,   "0d0",  1 },
    { "& Set of Gauntlets^ [%P6, %P4]"                    , 31,  ']', 0x00000000,    0,   35,   2,   25, 1,    0,  0,  2,  0,   "1d1", 12 },
    { "& Small Leather Shield^ [%P6,%P4]"                 , 34,  ')', 0x00000000,    0,   30,   1,   50, 1,    0,  0,  2,  0,   "1d1",  3 },
    { "& Medium Leather Shield^ [%P6,%P4]"                , 34,  ')', 0x00000000,    0,   60,   2,   75, 1,    0,  0,  3,  0,   "1d2",  8 },
    { "& Large Leather Shield^ [%P6,%P4]"                 , 34,  ')', 0x00000000,    0,  120,   3,  100, 1,    0,  0,  4,  0,   "1d2", 15 },
    { "& Small Metal Shield^ [%P6,%P4]"                   , 34,  ')', 0x00000000,    0,   50,   4,   65, 1,    0,  0,  3,  0,   "1d2", 10 },
    { "& Medium Metal Shield^ [%P6,%P4]"                  , 34,  ')', 0x00000000,    0,  125,   5,   90, 1,    0,  0,  4,  0,   "1d3", 20 },
    { "& Large Metal Shield^ [%P6,%P4]"                   , 34,  ')', 0x00000000,    0,  200,   6,  120, 1,    0,  0,  5,  0,   "1d3", 30 },
    { "& %R Ring| of Gain Strength^ (%P1)"                , 45,  '=', 0x00000001,    0,  400,   1,    2, 1,    0,  0,  0,  0,   "0d0", 30 },
    { "& %R Ring| of Gain Dexterity^ (%P1)"               , 45,  '=', 0x00000002,    0,  400,   2,    2, 1,    0,  0,  0,  0,   "0d0", 30 },
    { "& %R Ring| of Gain Constitution^ (%P1)"            , 45,  '=', 0x00000004,    0,  400,   3,    2, 1,    0,  0,  0,  0,   "0d0", 30 },
    { "& %R Ring| of Gain Intelligence^ (%P1)"            , 45,  '=', 0x00000008,    0,  350,   4,    2, 1,    0,  0,  0,  0,   "0d0", 30 },
    { "& %R Ring| of Speed^ (%P1)"                        , 45,  '=', 0x00001000,    0, 3000,   7,    2, 1,    0,  0,  0,  0,   "0d0", 50 },
    { "& %R Ring| of Searching^ (%P1)"                    , 45,  '=', 0x00000040,    0,  250,   8,    2, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %R Ring| of Teleportation^"                      , 45,  '=', 0x80000400,    0,    0,   9,    2, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %R Ring| of Slow Digestion^"                     , 45,  '=', 0x00000080,    0,  250,  10,    2, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %R Ring| of Resist Fire^"                        , 45,  '=', 0x00080000,    0,  250,  11,    2, 1,    0,  0,  0,  0,   "0d0", 14 },
    { "& %R Ring| of Resist Cold^"                        , 45,  '=', 0x00200000,    0,  250,  12,    2, 1,    0,  0,  0,  0,   "0d0", 14 },
    { "& %R Ring| of Feather Falling^"                    , 45,  '=', 0x04000000,    0,  250,  13,    2, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %R Ring| of Adornment^"                          , 45,  '=', 0x00000000,    0,   20,  14,    2, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %R Ring| of Adornment^"                          , 45,  '=', 0x00000000,    0,   30,  15,    2, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %R Ring| of Weakness^"                           , 45,  '=', 0x80000001,   -5,    0,  16,    2, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %R Ring| of Lordly Protection (FIRE)^ [%P4]"     , 45,  '=', 0x00080000,    0, 1200,  17,    2, 1,    0,  0,  0,  5,   "0d0", 50 },
    { "& %R Ring| of Lordly Protection (ACID)^ [%P4]"     , 45,  '=', 0x00100000,    0, 1200,  18,    2, 1,    0,  0,  0,  5,   "0d0", 50 },
    { "& %R Ring| of Lordly Protection (COLD)^ [%P4]"     , 45,  '=', 0x00200000,    0, 1200,  19,    2, 1,    0,  0,  0,  5,   "0d0", 50 },
    { "& %R Ring| of Woe^ [%P4]"                          , 45,  '=', 0x80000640,   -5,    0,  20,    2, 1,    0,  0,  0, -3,   "0d0", 50 },
    { "& %R Ring| of Stupidity^"                          , 45,  '=', 0x80000008,   -5,    0,  21,    2, 1,    0,  0,  0,  0,   "0d0", 50 },
    { "& %R Ring| of Increase Damage^ (%P3)"              , 45,  '=', 0x00000000,    0,  100,  22,    2, 1,    0,  0,  0,  0,   "0d0", 20 },
    { "& %R Ring| of Increase To-Hit^ (%P2)"              , 45,  '=', 0x00000000,    0,  100,  23,    2, 1,    0,  0,  0,  0,   "0d0", 20 },
    { "& %R Ring| of Protection^ [%P4]"                   , 45,  '=', 0x00000000,    0,  100,  24,    2, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %R Ring| of Aggravate Monster^"                  , 45,  '=', 0x80000200,    0,    0,  25,    2, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %R Ring| of See Invisible^"                      , 45,  '=', 0x01000000,    0,  340,  26,    2, 1,    0,  0,  0,  0,   "0d0", 40 },
    { "& %R Ring| of Sustain Strength^"                   , 45,  '=', 0x00400000,    1,  750,  27,    2, 1,    0,  0,  0,  0,   "0d0", 44 },
    { "& %R Ring| of Sustain Intelligence^"               , 45,  '=', 0x00400000,    2,  600,  28,    2, 1,    0,  0,  0,  0,   "0d0", 44 },
    { "& %R Ring| of Sustain Wisdom^"                     , 45,  '=', 0x00400000,    3,  600,  29,    2, 1,    0,  0,  0,  0,   "0d0", 44 },
    { "& %R Ring| of Sustain Constitution^"               , 45,  '=', 0x00400000,    4,  750,  30,    2, 1,    0,  0,  0,  0,   "0d0", 44 },
    { "& %R Ring| of Sustain Dexterity^"                  , 45,  '=', 0x00400000,    5,  750,  31,    2, 1,    0,  0,  0,  0,   "0d0", 44 },
    { "& %R Ring| of Sustain Charisma^"                   , 45,  '=', 0x00400000,    6,  500,  32,    2, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& %R Ring| of Slaying^ (%P2,%P3)"                  , 45,  '=', 0x00000000,    6, 1000,  33,    2, 1,    0,  0,  0,  0,   "0d0", 50 },
    { "& %A Amulet| of Wisdom^ (%P1)"                     , 40,  '"', 0x00000010,    0,  300,   5,    3, 1,    0,  0,  0,  0,   "0d0", 20 },
    { "& %A Amulet| of Charisma^ (%P1)"                   , 40,  '"', 0x00000020,    0,  250,   6,    3, 1,    0,  0,  0,  0,   "0d0", 20 },
    { "& %A Amulet| of Searching^ (%P1)"                  , 40,  '"', 0x00000040,    0,  250,   7,    3, 1,    0,  0,  0,  0,   "0d0", 14 },
    { "& %A Amulet| of Teleportation^"                    , 40,  '"', 0x80000400,    0,    0,   8,    3, 1,    0,  0,  0,  0,   "0d0", 14 },
    { "& %A Amulet| of Slow Digestion^"                   , 40,  '"', 0x00000080,    0,  200,   9,    3, 1,    0,  0,  0,  0,   "0d0", 14 },
    { "& %A Amulet| of Resist Acid^"                      , 40,  '"', 0x00100000,    0,  300,  10,    3, 1,    0,  0,  0,  0,   "0d0", 24 },
    { "& %A Amulet| of Adornment^"                        , 40,  '"', 0x00000000,    0,   20,  11,    3, 1,    0,  0,  0,  0,   "0d0", 16 },
    { "& %A Amulet| of Adornment^"                        , 40,  '"', 0x00000000,    0,   30,  12,    3, 1,    0,  0,  0,  0,   "0d0", 16 },
    { "& %A Amulet| of the Magi^ [%P4]"                   , 40,  '"', 0x01800040,    0, 5000,  13,    3, 1,    0,  0,  0,  3,   "0d0", 50 },
    { "& %A Amulet| of Doom^"                             , 40,  '"', 0x8000007F,   -5,    0,  14,    3, 1,    0,  0,  0,  0,   "0d0", 50 },
    { "& Scroll~ %T| of Enchant Weapon To-Hit"            , 70,  '?', 0x00000001,    0,  125, 257,    5, 1,    0,  0,  0,  0,   "0d0", 12 },
    { "& Scroll~ %T| of Enchant Weapon To-Dam"            , 70,  '?', 0x00000002,    0,  125, 258,    5, 1,    0,  0,  0,  0,   "0d0", 12 },
    { "& Scroll~ %T| of Enchant Armor"                    , 70,  '?', 0x00000004,    0,  125, 259,    5, 1,    0,  0,  0,  0,   "0d0", 12 },
    { "& Scroll~ %T| of Identify"                         , 70,  '?', 0x00000008,    0,   50, 260,    5, 1,    0,  0,  0,  0,   "0d0",  1 },
    { "& Scroll~ %T| of Identify"                         , 70,  '?', 0x00000008,    0,   50, 260,    5, 1,    0,  0,  0,  0,   "0d0",  5 },
    { "& Scroll~ %T| of Identify"                         , 70,  '?', 0x00000008,    0,   50, 260,    5, 1,    0,  0,  0,  0,   "0d0", 10 },
    { "& Scroll~ %T| of Remove Curse"                     , 70,  '?', 0x00000010,    0,  100, 261,    5, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& Scroll~ %T| of Light"                            , 70,  '?', 0x00000020,    0,   15, 262,    5, 1,    0,  0,  0,  0,   "0d0",  0 },
    { "& Scroll~ %T| of Light"                            , 70,  '?', 0x00000020,    0,   15, 262,    5, 1,    0,  0,  0,  0,   "0d0",  3 },
    { "& Scroll~ %T| of Light"                            , 70,  '?', 0x00000020,    0,   15, 262,    5, 1,    0,  0,  0,  0,   "0d0",  7 },
    { "& Scroll~ %T| Summon Monster"                      , 70,  '?', 0x00000040,    0,    0, 263,    5, 1,    0,  0,  0,  0,   "0d0",  1 },
    { "& Scroll~ %T| Phase Door"                          , 70,  '?', 0x00000080,    0,   15, 264,    5, 1,    0,  0,  0,  0,   "0d0",  1 },
    { "& Scroll~ %T| of Teleport"                         , 70,  '?', 0x00000100,    0,   40, 265,    5, 1,    0,  0,  0,  0,   "0d0", 10 },
    { "& Scroll~ %T| of Teleport Level"                   , 70,  '?', 0x00000200,    0,   50, 266,    5, 1,    0,  0,  0,  0,   "0d0", 20 },
    { "& Scroll~ %T| of Monster Confusion"                , 70,  '?', 0x00000400,    0,   30, 267,    5, 1,    0,  0,  0,  0,   "0d0",  5 },
    { "& Scroll~ %T| of Magic Mapping"                    , 70,  '?', 0x00000800,    0,   40, 268,    5, 1,    0,  0,  0,  0,   "0d0"   5 },
    { "& Scroll~ %T| of Sleep Monster"                    , 70,  '?', 0x00001000,    0,   35, 269,    5, 1,    0,  0,  0,  0,   "0d0",  5 },
    { "& Scroll~ %T| of Rune of Protection"               , 70,  '?', 0x00002000,    0,  500, 270,    5, 1,    0,  0,  0,  0,   "0d0", 50 },
    { "& Scroll~ %T| of Treasure Detection"               , 70,  '?', 0x00004000,    0,   15, 271,    5, 1,    0,  0,  0,  0,   "0d0",  0 },
    { "& Scroll~ %T| of Object Detection"                 , 70,  '?', 0x00008000,    0,   15, 272,    5, 1,    0,  0,  0,  0,   "0d0",  0 },
    { "& Scroll~ %T| of Trap Detection"                   , 70,  '?', 0x00010000,    0,   35, 273,    5, 1,    0,  0,  0,  0,   "0d0",  5 },
    { "& Scroll~ %T| of Trap Detection"                   , 70,  '?', 0x00010000,    0,   35, 273,    5, 1,    0,  0,  0,  0,   "0d0",  8 },
    { "& Scroll~ %T| of Trap Detection"                   , 70,  '?', 0x00010000,    0,   35, 273,    5, 1,    0,  0,  0,  0,   "0d0", 12 },
    { "& Scroll~ %T| of Door/Stair Location"              , 70,  '?', 0x00020000,    0,   35, 274,    5, 1,    0,  0,  0,  0,   "0d0",  5 },
    { "& Scroll~ %T| of Door/Stair Location"              , 70,  '?', 0x00020000,    0,   35, 274,    5, 1,    0,  0,  0,  0,   "0d0", 10 },
    { "& Scroll~ %T| of Door/Stair Location"              , 70,  '?', 0x00020000,    0,   35, 274,    5, 1,    0,  0,  0,  0,   "0d0", 15 },
    { "& Scroll~ %T| of Mass Genocide"                    , 70,  '?', 0x00040000,    0, 1000, 275,    5, 1,    0,  0,  0,  0,   "0d0", 50 },
    { "& Scroll~ %T| of Detect Invisible"                 , 70,  '?', 0x00080000,    0,   15, 276,    5, 1,    0,  0,  0,  0,   "0d0",  1 },
    { "& Scroll~ %T| of Aggravate Monster"                , 70,  '?', 0x00100000,    0,    0, 277,    5, 1,    0,  0,  0,  0,   "0d0",  5 },
    { "& Scroll~ %T| of Trap Creation"                    , 70,  '?', 0x00200000,    0,    0, 278,    5, 1,    0,  0,  0,  0,   "0d0", 12 },
    { "& Scroll~ %T| of Trap/Door Destruction"            , 70,  '?', 0x00400000,    0,   50, 279,    5, 1,    0,  0,  0,  0,   "0d0", 12 },
    { "& Scroll~ %T| of Door Creation"                    , 70,  '?', 0x00800000,    0,  100, 280,    5, 1,    0,  0,  0,  0,   "0d0", 12 },
    { "& Scroll~ %T| of Recharging"                       , 70,  '?', 0x01000000,    0,  200, 281,    5, 1,    0,  0,  0,  0,   "0d0", 40 },
    { "& Scroll~ %T| of Genocide"                         , 70,  '?', 0x02000000,    0,  750, 282,    5, 1,    0,  0,  0,  0,   "0d0", 35 },
    { "& Scroll~ %T| of Darkness"                         , 70,  '?', 0x04000000,    0,    0, 283,    5, 1,    0,  0,  0,  0,   "0d0",  1 },
    { "& Scroll~ %T| of Protection from Evil"             , 70,  '?', 0x08000000,    0,   50, 284,    5, 1,    0,  0,  0,  0,   "0d0", 30 },
    { "& Scroll~ %T| of Create Food"                      , 70,  '?', 0x10000000,    0,   10, 285,    5, 1,    0,  0,  0,  0,   "0d0",  5 },
    { "& Scroll~ %T| of Dispel Undead"                    , 70,  '?', 0x20000000,    0,  200, 286,    5, 1,    0,  0,  0,  0,   "0d0", 40 },
    { "& Scroll~ %T| of *Enchant Weapon*"                 , 71,  '?', 0x00000001,    0,  500, 257,    5, 1,    0,  0,  0,  0,   "0d0", 50 },
    { "& Scroll~ %T| of Curse Weapon"                     , 71,  '?', 0x00000002,    0,    0, 258,    5, 1,    0,  0,  0,  0,   "0d0", 50 },
    { "& Scroll~ %T| of *Enchant Armor*"                  , 71,  '?', 0x00000004,    0,  500, 259,    5, 1,    0,  0,  0,  0,   "0d0", 50 },
    { "& Scroll~ %T| of Curse Armor"                      , 71,  '?', 0x00000008,    0,    0, 260,    5, 1,    0,  0,  0,  0,   "0d0", 50 },
    { "& Scroll~ %T| of Summon Undead"                    , 71,  '?', 0x00000010,    0,    0, 261,    5, 1,    0,  0,  0,  0,   "0d0", 15 },
    { "& Scroll~ %T| of Blessing"                         , 71,  '?', 0x00000020,    0,   15, 262,    5, 1,    0,  0,  0,  0,   "0d0",  1 },
    { "& Scroll~ %T| of Holy Chant"                       , 71,  '?', 0x00000040,    0,   40, 263,    5, 1,    0,  0,  0,  0,   "0d0", 12 },
    { "& Scroll~ %T| of Holy Prayer"                      , 71,  '?', 0x00000080,    0,   80, 264,    5, 1,    0,  0,  0,  0,   "0d0", 24 },
    { "& Scroll~ %T| of Word-of-Recall"                   , 71,  '?', 0x00000100,    0,  150, 265,    5, 1,    0,  0,  0,  0,   "0d0",  5 },
    { "& Scroll~ %T| of *Destruction*"                    , 71,  '?', 0x00000200,    0,  250, 266,    5, 1,    0,  0,  0,  0,   "0d0", 40 },
    { "& %C Potion~| of Gain Strength"                    , 75,  '!', 0x00000001,    0,  200, 257,    4, 1,    0,  0,  0,  0,   "1d1", 25 },
    { "& %C Potion~| of Poison"                           , 75,  '!', 0x00000002,    0,    0, 258,    4, 1,    0,  0,  0,  0,   "1d1",  3 },
    { "& %C Potion~| of Restore Strength"                 , 75,  '!', 0x00000004,    0,  300, 259,    4, 1,    0,  0,  0,  0,   "1d1", 40 },
    { "& %C Potion~| of Gain Intelligence"                , 75,  '!', 0x00000008,    0,  300, 260,    4, 1,    0,  0,  0,  0,   "1d1", 25 },
    { "& %C Potion~| of Lose Intelligence"                , 75,  '!', 0x00000010,    0,    0, 261,    4, 1,    0,  0,  0,  0,   "1d1", 25 },
    { "& %C Potion~| of Restore Intelligence"             , 75,  '!', 0x00000020,    0,  300, 262,    4, 1,    0,  0,  0,  0,   "1d1", 40 },
    { "& %C Potion~| of Gain Wisdom"                      , 75,  '!', 0x00000040,    0,  300, 263,    4, 1,    0,  0,  0,  0,   "1d1", 25 },
    { "& %C Potion~| of Lose Wisdom"                      , 75,  '!', 0x00000080,    0,    0, 264,    4, 1,    0,  0,  0,  0,   "1d1", 25 },
    { "& %C Potion~| of Restore Wisdom"                   , 75,  '!', 0x00000100,    0,  300, 265,    4, 1,    0,  0,  0,  0,   "1d1", 40 },
    { "& %C Potion~| of Charisma"                         , 75,  '!', 0x00000200,    0,  300, 266,    4, 1,    0,  0,  0,  0,   "1d1", 25 },
    { "& %C Potion~| of Ugliness"                         , 75,  '!', 0x00000400,    0,    0, 267,    4, 1,    0,  0,  0,  0,   "1d1", 25 },
    { "& %C Potion~| of Restore Charisma"                 , 75,  '!', 0x00000800,    0,  300, 268,    4, 1,    0,  0,  0,  0,   "1d1", 40 },
    { "& %C Potion~| of Cure Light Wounds"                , 75,  '!', 0x10001000,   50,   15, 269,    4, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "& %C Potion~| of Cure Light Wounds"                , 75,  '!', 0x10001000,   50,   15, 269,    4, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& %C Potion~| of Cure Light Wounds"                , 75,  '!', 0x10001000,   50,   15, 269,    4, 1,    0,  0,  0,  0,   "1d1",  2 },
    { "& %C Potion~| of Cure Serious Wounds"              , 75,  '!', 0x30002000,  100,   40, 270,    4, 1,    0,  0,  0,  0,   "1d1",  3 },
    { "& %C Potion~| of Cure Critical Wounds"             , 75,  '!', 0x70004000,  100,  100, 271,    4, 1,    0,  0,  0,  0,   "1d1",  5 },
    { "& %C Potion~| of Healing"                          , 75,  '!', 0x70008000,  200,  200, 272,    4, 1,    0,  0,  0,  0,   "1d1", 12 },
    { "& %C Potion~| of Gain Constitution"                , 75,  '!', 0x00010000,    0,  300, 273,    4, 1,    0,  0,  0,  0,   "1d1", 25 },
    { "& %C Potion~| of Gain Experience"                  , 75,  '!', 0x00020000,    0, 2500, 274,    4, 1,    0,  0,  0,  0,   "1d1", 50 },
    { "& %C Potion~| of Sleep"                            , 75,  '!', 0x10040000,  100,    0, 275,    4, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "& %C Potion~| of Blindness"                        , 75,  '!', 0x00080000,    0,    0, 276,    4, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "& %C Potion~| of Confusion"                        , 75,  '!', 0x00100000,    0,    0, 277,    4, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "& %C Potion~| of Poison"                           , 75,  '!', 0x00200000,    0,    0, 278,    4, 1,    0,  0,  0,  0,   "1d1",  3 },
    { "& %C Potion~| of Haste Self"                       , 75,  '!', 0x00400000,    0,   75, 279,    4, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& %C Potion~| of Slowness"                         , 75,  '!', 0x00800000,   50,    0, 280,    4, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& Icky Green Potion~| of Slime Mold Juice"         , 75,  '!', 0x30000000,  400,    2, 281,    4, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "& Light Brown Potion~| of Apple Juice"             , 75,  '!', 0x00000000,  250,    1, 282,    4, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "& Clear Potion~| of Water"                         , 75,  '!', 0x00000000,  200,    0, 283,    4, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "& %C Potion~| of Gain Dexterity"                   , 75,  '!', 0x02000000,    0,  300, 284,    4, 1,    0,  0,  0,  0,   "1d1", 25 },
    { "& %C Potion~| of Restore Dexterity"                , 75,  '!', 0x04000000,    0,  300, 285,    4, 1,    0,  0,  0,  0,   "1d1", 40 },
    { "& %C Potion~| of Restore Constitution"             , 75,  '!', 0x68000000,    0,  300, 286,    4, 1,    0,  0,  0,  0,   "1d1", 40 },
    { "& %C Potion~| of Learning"                         , 76,  '!', 0x00000001,    0,  200, 287,    4, 1,    0,  0,  0,  0,   "1d1", 45 },
    { "& %C Potion~| of Lose Memories"                    , 76,  '!', 0x00000002,    0,    0, 288,    4, 1,    0,  0,  0,  0,   "1d1", 10 },
    { "& %C Potion~| of Salt Water"                       , 76,  '!', 0x00000004,    0,    0, 289,    4, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "& %C Potion~| of Invulnerability"                  , 76,  '!', 0x00000008,    0,  250, 290,    4, 1,    0,  0,  0,  0,   "1d1", 40 },
    { "& %C Potion~| of Heroism"                          , 76,  '!', 0x00000010,    0,   35, 291,    4, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& %C Potion~| of Super Heroism"                    , 76,  '!', 0x00000020,    0,  100, 292,    4, 1,    0,  0,  0,  0,   "1d1",  3 },
    { "& %C Potion~| of Boldness"                         , 76,  '!', 0x00000040,    0,   10, 293,    4, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& %C Potion~| of Restore Life Levels"              , 76,  '!', 0x00000080,    0,  400, 294,    4, 1,    0,  0,  0,  0,   "1d1", 40 },
    { "& %C Potion~| of Resist Heat"                      , 76,  '!', 0x00000100,    0,   30, 295,    4, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& %C Potion~| of Resist Cold"                      , 76,  '!', 0x00000200,    0,   30, 296,    4, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& %C Potion~| of Detect Invisible"                 , 76,  '!', 0x00000400,    0,   50, 297,    4, 1,    0,  0,  0,  0,   "1d1",  3 },
    { "& %C Potion~| of Slow Poison"                      , 76,  '!', 0x00000800,    0,   25, 298,    4, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& %C Potion~| of Neutralize Poison"                , 76,  '!', 0x00001000,    0,   75, 299,    4, 1,    0,  0,  0,  0,   "1d1",  5 },
    { "& %C Potion~| of Restore Mana"                     , 76,  '!', 0x00002000,    0,   35, 300,    4, 1,    0,  0,  0,  0,   "1d1", 25 },
    { "& %C Potion~| of Infra-Vision"                     , 76,  '!', 0x00004000,    0,   20, 301,    4, 1,    0,  0,  0,  0,   "1d1",  3 },
    { "& Flask~ of Oil"                                   , 77,  '!', 0x00040000, 7500,    3, 257,   10, 1,    0,  0,  0,  0,   "2d6",  1 },
    { "& %M Wand| of Light^ (%P1 charges)"                , 65,  '-', 0x00000001,    0,  200,   1,   10, 1,    0,  0,  0,  0,   "1d1",  2 },
    { "& %M Wand| of Lightning Bolts^ (%P1 charges)"      , 65,  '-', 0x00000002,    0,  600,   2,   10, 1,    0,  0,  0,  0,   "1d1", 15 },
    { "& %M Wand| of Frost Bolts^ (%P1 charges)"          , 65,  '-', 0x00000004,    0,  800,   3,   10, 1,    0,  0,  0,  0,   "1d1", 20 },
    { "& %M Wand| of Fire Bolts^ (%P1 charges)"           , 65,  '-', 0x00000008,    0, 1000,   4,   10, 1,    0,  0,  0,  0,   "1d1", 30 },
    { "& %M Wand| of Stone-to-Mud^ (%P1 charges)"         , 65,  '-', 0x00000010,    0,  300,   5,   10, 1,    0,  0,  0,  0,   "1d1", 12 },
    { "& %M Wand| of Polymorph^ (%P1 charges)"            , 65,  '-', 0x00000020,    0,  400,   6,   10, 1,    0,  0,  0,  0,   "1d1", 20 },
    { "& %M Wand| of Heal Monster^ (%P1 charges)"         , 65,  '-', 0x00000040,    0,    0,   7,   10, 1,    0,  0,  0,  0,   "1d1",  2 },
    { "& %M Wand| of Haste Monster^ (%P1 charges)"        , 65,  '-', 0x00000080,    0,    0,   8,   10, 1,    0,  0,  0,  0,   "1d1",  2 },
    { "& %M Wand| of Slow Monster^ (%P1 charges)"         , 65,  '-', 0x00000100,    0,  500,   9,   10, 1,    0,  0,  0,  0,   "1d1",  2 },
    { "& %M Wand| of Confuse Monster^ (%P1 charges)"      , 65,  '-', 0x00000200,    0,  400,  10,   10, 1,    0,  0,  0,  0,   "1d1",  2 },
    { "& %M Wand| of Sleep Monster^ (%P1 charges)"        , 65,  '-', 0x00000400,    0,  500,  11,   10, 1,    0,  0,  0,  0,   "1d1",  7 },
    { "& %M Wand| of Drain Life^ (%P1 charges)"           , 65,  '-', 0x00000800,    0, 1200,  12,   10, 1,    0,  0,  0,  0,   "1d1", 50 },
    { "& %M Wand| of Trap/Door Destruction^ (%P1 charges)", 65,  '-', 0x00001000,    0,  100,  13,   10, 1,    0,  0,  0,  0,   "1d1", 12 },
    { "& %M Wand| of Magic Missile^ (%P1 charges)"        , 65,  '-', 0x00002000,    0,  200,  14,   10, 1,    0,  0,  0,  0,   "1d1",  2 },
    { "& %M Wand| of Wall Building^ (%P1 charges)"        , 65,  '-', 0x00004000,    0,  400,  15,   10, 1,    0,  0,  0,  0,   "1d1", 25 },
    { "& %M Wand| of Clone Monster^ (%P1 charges)"        , 65,  '-', 0x00008000,    0,    0,  16,   10, 1,    0,  0,  0,  0,   "1d1",  2 },
    { "& %M Wand| of Teleport Away^ (%P1 charges)"        , 65,  '-', 0x00010000,    0,  350,  17,   10, 1,    0,  0,  0,  0,   "1d1", 20 },
    { "& %M Wand| of Disarming^ (%P1 charges)"            , 65,  '-', 0x00020000,    0,  700,  18,   10, 1,    0,  0,  0,  0,   "1d1", 20 },
    { "& %M Wand| of Lightning Balls^ (%P1 charges)"      , 65,  '-', 0x00040000,    0, 1200,  19,   10, 1,    0,  0,  0,  0,   "1d1", 35 },
    { "& %M Wand| of Cold Balls^ (%P1 charges)"           , 65,  '-', 0x00080000,    0, 1500,  20,   10, 1,    0,  0,  0,  0,   "1d1", 40 },
    { "& %M Wand| of Fire Balls^ (%P1 charges)"           , 65,  '-', 0x00100000,    0, 1800,  21,   10, 1,    0,  0,  0,  0,   "1d1", 50 },
    { "& %M Wand| of Stinking Cloud^ (%P1 charges)"       , 65,  '-', 0x00200000,    0,  400,  22,   10, 1,    0,  0,  0,  0,   "1d1",  5 },
    { "& %M Wand| of Acid Balls^ (%P1 charges)"           , 65,  '-', 0x00400000,    0, 1650,  23,   10, 1,    0,  0,  0,  0,   "1d1", 48 },
    { "& %M Wand| of Wonder^ (%P1 charges)"               , 65,  '-', 0x00800000,    0,  250,  24,   10, 1,    0,  0,  0,  0,   "1d1",  2 },
    { "& %W Staff| of Light^ (%P1 charges)"               , 55,  '_', 0x00000001,    0,  250,   1,   50, 1,    0,  0,  0,  0,   "1d2",  5 },
    { "& %W Staff| of Door/Stair Location^ (%P1 charges)" , 55,  '_', 0x00000002,    0,  350,   2,   50, 1,    0,  0,  0,  0,   "1d2", 10 },
    { "& %W Staff| of Trap Location^ (%P1 charges)"       , 55,  '_', 0x00000004,    0,  350,   3,   50, 1,    0,  0,  0,  0,   "1d2", 10 },
    { "& %W Staff| of Treasure Location^ (%P1 charges)"   , 55,  '_', 0x00000008,    0,  200,   4,   50, 1,    0,  0,  0,  0,   "1d2",  5 },
    { "& %W Staff| of Object Location^ (%P1 charges)"     , 55,  '_', 0x00000010,    0,  200,   5,   50, 1,    0,  0,  0,  0,   "1d2",  5 },
    { "& %W Staff| of Teleportation^ (%P1 charges)"       , 55,  '_', 0x00000020,    0,  400,   6,   50, 1,    0,  0,  0,  0,   "1d2", 20 },
    { "& %W Staff| of Earthquakes^ (%P1 charges)"         , 55,  '_', 0x00000040,    0,  350,   7,   50, 1,    0,  0,  0,  0,   "1d2", 40 },
    { "& %W Staff| of Summoning^ (%P1 charges)"           , 55,  '_', 0x00000080,    0,    0,   8,   50, 1,    0,  0,  0,  0,   "1d2", 10 },
    { "& %W Staff| of Summoning^ (%P1 charges)"           , 55,  '_', 0x00000080,    0,    0,   8,   50, 1,    0,  0,  0,  0,   "1d2", 50 },
    { "& %W Staff| of *Destruction*^ (%P1 charges)"       , 55,  '_', 0x00000200,    0, 2500,  10,   50, 1,    0,  0,  0,  0,   "1d2", 50 },
    { "& %W Staff| of Starlight^ (%P1 charges)"           , 55,  '_', 0x00000400,    0,  800,  11,   50, 1,    0,  0,  0,  0,   "1d2", 20 },
    { "& %W Staff| of Haste Monsters^ (%P1 charges)"      , 55,  '_', 0x00000800,    0,    0,  12,   50, 1,    0,  0,  0,  0,   "1d2", 10 },
    { "& %W Staff| of Slow Monsters^ (%P1 charges)"       , 55,  '_', 0x00001000,    0,  800,  13,   50, 1,    0,  0,  0,  0,   "1d2", 10 },
    { "& %W Staff| of Sleep Monsters^ (%P1 charges)"      , 55,  '_', 0x00002000,    0,  700,  14,   50, 1,    0,  0,  0,  0,   "1d2", 10 },
    { "& %W Staff| of Cure Light Wounds^ (%P1 charges)"   , 55,  '_', 0x00004000,    0,  350,  15,   50, 1,    0,  0,  0,  0,   "1d2",  5 },
    { "& %W Staff| of Detect Invisible^ (%P1 charges)"    , 55,  '_', 0x00008000,    0,  200,  16,   50, 1,    0,  0,  0,  0,   "1d2",  5 },
    { "& %W Staff| of Speed^ (%P1 charges)"               , 55,  '_', 0x00010000,    0,  800,  17,   50, 1,    0,  0,  0,  0,   "1d2", 40 },
    { "& %W Staff| of Slowness^ (%P1 charges)"            , 55,  '_', 0x00020000,    0,    0,  18,   50, 1,    0,  0,  0,  0,   "1d2", 40 },
    { "& %W Staff| of Mass Polymorph^ (%P1 charges)"      , 55,  '_', 0x00040000,    0,  750,  19,   50, 1,    0,  0,  0,  0,   "1d2", 46 },
    { "& %W Staff| of Remove Curse^ (%P1 charges)"        , 55,  '_', 0x00080000,    0,  500,  20,   50, 1,    0,  0,  0,  0,   "1d2", 47 },
    { "& %W Staff| of Detect Evil^ (%P1 charges)"         , 55,  '_', 0x00100000,    0,  350,  21,   50, 1,    0,  0,  0,  0,   "1d2", 20 },
    { "& %W Staff| of Curing^ (%P1 charges)"              , 55,  '_', 0x00200000,    0, 1000,  22,   50, 1,    0,  0,  0,  0,   "1d2", 25 },
    { "& %W Staff| of Dispel Evil^ (%P1 charges)"         , 55,  '_', 0x00400000,    0, 1200,  23,   50, 1,    0,  0,  0,  0,   "1d2", 49 },
    { "& %W Staff| of Darkness^ (%P1 charges)"            , 55,  '_', 0x01000000,    0,    0,  25,   50, 1,    0,  0,  0,  0,   "1d2", 50 },
    { "& %W Staff| of Darkness^ (%P1 charges)"            , 55,  '_', 0x01000000,    0,    0,  25,   50, 1,    0,  0,  0,  0,   "1d2",  5 },
    { "& Book of Magic Spells [Beginner's-Magik]"         , 90,  '?', 0x0000007F,    0,   25, 257,   30, 1, -100,  0,  0,  0,   "1d1", 40 },
    { "& Book of Magic Spells [Magik I]"                  , 90,  '?', 0x0000FF80,    0,  100, 258,   30, 1, -100,  0,  0,  0,   "1d1", 40 },
    { "& Book of Magic Spells [Magik II]"                 , 90,  '?', 0x00FF0000,    0,  400, 259,   30, 1, -100,  0,  0,  0,   "1d1", 40 },
    { "& Book of Magic Spells [The Mage's Guide to Power]", 90,  '?', 0x7F000000,    0,  800, 261,   30, 1, -100,  0,  0,  0,   "1d1", 40 },
    { "& Holy Book of Prayers [Beginners Handbook]"       , 91,  '?', 0x000000FF,    0,   25, 258,   30, 1, -100,  0,  0,  0,   "1d1", 40 },
    { "& Holy Book of Prayers [Words of Wisdom]"          , 91,  '?', 0x0000FF00,    0,  100, 259,   30, 1, -100,  0,  0,  0,   "1d1", 40 },
    { "& Holy Book of Prayers [Chants and Blessings]"     , 91,  '?', 0x01FF0000,    0,  300, 260,   30, 1, -100,  0,  0,  0,   "1d1", 40 },
    { "& Holy Book of Prayers [Exorcism and Dispelling]"  , 91,  '?', 0x7E000000,    0,  900, 261,   30, 1, -100,  0,  0,  0,   "1d1", 40 },
    { "& Small Wooden Chest"                              ,  2,  '&', 0x0F000000,    0,   20,   1,  250, 1,    0,  0,  0,  0,   "2d3",  7 },
    { "& Large Wooden Chest"                              ,  2,  '&', 0x15000000,    0,   60,   1,  500, 1,    0,  0,  0,  0,   "2d5", 15 },
    { "& Small Iron Chest"                                ,  2,  '&', 0x0F000000,    0,  100,   7,  300, 1,    0,  0,  0,  0,   "2d4", 25 },
    { "& Large Iron Chest"                                ,  2,  '&', 0x1F000000,    0,  150,  10, 1000, 1,    0,  0,  0,  0,   "2d6", 35 },
    { "& Small Steel Chest"                               ,  2,  '&', 0x0F000000,    0,  200,  13,  500, 1,    0,  0,  0,  0,   "2d4", 45 },
    { "& Large Steel Chest"                               ,  2,  '&', 0x23000000,    0,  250,  16, 1000, 1,    0,  0,  0,  0,   "2d6", 50 },
    { "& Rat Skeleton"                                    ,  1,  's', 0x00000000,    0,    0,   1,   10, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& Giant Centipede Skeleton"                        ,  1,  's', 0x00000000,    0,    0,   2,   25, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "Some Filthy Rags^ [%P6,%P4]"                       , 36,  '~', 0x00000000,    0,    0,  99,   20, 1,    0,  0,  1,  0,   "0d0",  0 },
    { "& Empty Bottle"                                    ,  1,  '!', 0x00000000,    0,    0,   4,    2, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "Some Shards of Pottery"                            ,  1,  '~', 0x00000000,    0,    0,   5,    5, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "& Human Skeleton"                                  ,  1,  's', 0x00000000,    0,    0,   7,   50, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& Dwarf Skeleton"                                  ,  1,  's', 0x00000000,    0,    0,   8,   60, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& Elf Skeleton"                                    ,  1,  's', 0x00000000,    0,    0,   9,   40, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& Gnome Skeleton"                                  ,  1,  's', 0x00000000,    0,    0,  10,   25, 1,    0,  0,  0,  0,   "1d1",  1 },
    { "& Broken Set of Teeth"                             ,  1,  's', 0x00000000,    0,    0,  11,    3, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "& Large Broken Bone"                               ,  1,  's', 0x00000000,    0,    0,  12,    2, 1,    0,  0,  0,  0,   "1d1",  0 },
    { "& Broken Stick"                                    ,  1,  '~', 0x00000000,    0,    0,  13,    3, 1,    0,  0,  0,  0,   "1d1",  0 }
};