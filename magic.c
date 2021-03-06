#include "magic.h"

#include "config.h"
#include "constants.h"
#include "externs.h"
#include "io.h"
#include "misc1.h"
#include "misc2.h"
#include "moria1.h"
#include "moria2.h"
#include "spells.h"
#include "types.h"

/* Throw a magic spell    -RAK- */
void cast()
{
    int i;
    int j;
    int item_val;
    int dir;
    int choice;
    int chance;
    int result;
    int dumy;
    int y_dumy;
    int x_dumy;
    int redraw;
    struct flags *f_ptr;
    struct misc *p_ptr;
    treasure_type *i_ptr;
    spell_type *m_ptr;

    reset_flag = TRUE;

    if(py.flags.blind > 0) {
	msg_print("You can't see to read your spell book!");
    }
    else if(no_light()) {
	msg_print("You have no light to read by.");
    }
    else if(py.flags.confused > 0) {
	msg_print("You are too ocnfused...");
    }
    else if(class[py.misc.pclass].mspell) {
	if(inven_ctr > 0) {
	    if(find_range(90, -1, &i, &j)) {
		redraw = FALSE;

		if(get_item(&item_val, "Use which spell-book?", &redraw, i, j)) {
		    result = cast_spell("Case which spell?",
					item_val,
					&choice,
					&chance,
					&redraw);

		    if(result == TRUE) {
			m_ptr = &magic_spell[py.misc.pclass][choice];
			reset_flag = FALSE;

			if(randint(100) < chance) {
			    msg_print("You failed to get the spell off!");
			}
			else {
			    y_dumy = char_row;
			    x_dumy = char_col;

			    /* Spells... */
			    ++choice;

			    switch(choice) {
			    case 1:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    fire_bolt(0,
					      dir,
					      char_row,
					      char_col,
					      damroll("2d6") + 1,
					      "Magic Missile");
				}

				break;
			    case 2:
				detect_monsters();

				break;
			    case 3:
				teleport(10);

				break;
			    case 4:
				light_area(char_row, char_col);

				break;
			    case 5:
				hp_player(damroll("4d4"), "a magic spell.");

				break;
			    case 6:
				detect_sdoor();
				detect_trap();

				break;
			    case 7:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    fire_ball(2,
					      dir,
					      char_row,
					      char_col,
					      9,
					      "Stinking Cloud");
				}

				break;
			    case 8:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    confuse_monster(dir, char_row, char_col);
				}

				break;
			    case 9:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    fire_bolt(1,
					      dir,
					      char_row,
					      char_col,
					      damroll("3d8") + 1,
					      "Lightning Bolt");
				}

				break;
			    case 10:
				td_destroy();

				break;
			    case 11:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    sleep_monster(dir, char_row, char_col);
				}

				break;
			    case 12:
				cure_poison();

				break;
			    case 13:
				teleport((int)(py.misc.lev * 5));

				break;
			    case 14:
				for(i = 22; i < INVEN_MAX; ++i) {
				    i_ptr = &inventory[i];
				    i_ptr->flags = (i_ptr->flags & 0x7FFFFFFF);
				}

				break;
			    case 15:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    fire_bolt(4,
					      dir,
					      char_row,
					      char_col,
					      damroll("4d8") + 1,
					      "Frost Bolt");
				}

				break;
			    case 16:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    wall_to_mud(dir, char_row, char_col);
				}

				break;
			    case 17:
				create_food();

				break;
			    case 18:
				recharge(20);

				break;
			    case 19:
				sleep_monsters1(char_row, char_col);

				break;
			    case 20:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    poly_monster(dir, char_row, char_col);
				}

				break;
			    case 21:
				ident_spell();

				break;
			    case 22:
				sleep_monsters2();

				break;
			    case 23:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    fire_bolt(5,
					      dir,
					      char_row,
					      char_col,
					      damroll("6d8") + 1,
					      "Fire Bolt");
				}

				break;
			    case 24:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    speed_monster(dir, char_row, char_col, -1);
				}

				break;
			    case 25:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    fire_ball(4,
					      dir,
					      char_row,
					      char_col,
					      33,
					      "Frost Ball");
				}

				break;
			    case 26:
				recharge(60);

				break;
			    case 27:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    teleport_monster(dir, char_row, char_col);
				}

				break;
			    case 28:
				f_ptr = &py.flags;
				f_ptr->fast += (randint(20) + py.misc.lev);

				break;
			    case 29:
				if(get_dir("Which direction?", &dir, &dumy, &y_dumy, &x_dumy)) {
				    fire_ball(5,
					      dir,
					      char_row,
					      char_col,
					      49,
					      "Fire Ball");
				}

				break;
			    case 30:
				destroy_area(char_row, char_col);

				break;
			    case 31:
				genocide();

				break;
			    default:

				break;
			    }

			    /* End of spells... */
			    if(!reset_flag) {
				p_ptr = &py.misc;
				p_ptr->exp += m_ptr->sexp;
				prt_experience();
				m_ptr->sexp = 0;
			    }
			}

			p_ptr = &py.misc;

			if(!reset_flag) {
			    if(m_ptr->smana > p_ptr->cmana) {
				msg_print("You faint from the effort!");
				py.flags.paralysis =
				    randint(5 * (int)(m_ptr->smana - (int)p_ptr->cmana));

				p_ptr->cmana = 0.0;

				if(randint(3) == 1) {
				    msg_print("You have damaged your health!");
				    py.stats.ccon = de_statt(py.stats.ccon);
				    prt_constitution();
				}
			    }
			    else {
				p_ptr->cmana -= (double)m_ptr->smana;
			    }

			    prt_cmana();
			}
		    }
		    else if(result == -1) {
			msg_print("You don't know any spells in that book.");
		    }
		}
		else {
		    if(redraw) {
			draw_cave();
		    }
		}
	    }
	    else {
		msg_print("But you are not carrying any spell-books!");
	    }
	}
	else {
	    msg_print("But you are not carrying any spell-books!");
	}
    }
    else {
	msg_print("You can't cast spells!");
    }
}
