#include "store2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "constants.h"
#include "desc.h"
#include "externs.h"
#include "io.h"
#include "misc1.h"
#include "misc2.h"
#include "moria1.h"
#include "store1.h"
#include "types.h"

/* Correct SUN stupidity in the std.h file */
#ifdef sun
char *sprintf();
#endif

double chr_adj();

/*
 * Comments vary...    -RAK-
 * Comment one: Finished haggling
 */
void prt_comment1()
{
    msg_flag = FALSE;

    switch(randint(14)) {
    case 1:
	msg_print("Done!");

	break;
    case 2:
	msg_print("Accepted!");

	break;
    case 3:
	msg_print("Fine...");

	break;
    case 4:
	msg_print("Agreed!");

	break;
    case 5:
	msg_print("Okay...");

	break;
    case 6:
	msg_print("Taken!");

	break;
    case 7:
	msg_print("You drive a hard bargain, but taken...");

	break;
    case 8:
	msg_print("You'll force me bankrupt, but it's a deal...");

	break;
    case 9:
	msg_print("Sigh...I'll take it...");

	break;
    case 10:
	msg_print("My poor sick children may starve, but done!");

	break;
    case 11:
	msg_print("Finally! I accept...");

	break;
    case 12:
	msg_print("Robbed again...");

	break;
    case 13:
	msg_print("A pleasure to do business with you!");

	break;
    case 14:
	msg_print("My spouse will skin me, but accepted.");

	break;
    }
}

/* %A1 is offer, %A2 is asking... */
void prt_comment2(int offer, int asking, int final)
{
    vtype comment;

    if(final > 0) {
	switch(randint(3)) {
	case 1:
	    strcpy(comment, "%A2 is my final offer; take it or leave it...");

	    break;
	case 2:
	    strcpy(comment, "I'll give you no more than %A2.");

	    break;
	case 3:
	    strcpy(comment, "My patience grows thin...%A2 is final.");

	    break;
	}
    }
    else {
	switch(randint(16)) {
	case 1:
	    strcpy(comment, "%A1 for such a fine item? HA! No less than %A2.");

	    break;
	case 2:
	    strcpy(comment, "%A1 is an insult! Trye %A2 gold pieces...");

	    break;
	case 3:
	    strcpy(comment, "%A1??? Thou wouldst rob my poor starving children?");

	    break;
	case 4:
	    strcpy(comment, "Why, I'll take no less than %A2 gold pieces.");

	    break;
	case 5:
	    strcpy(comment, "Ha! No less than %A2 gold pieces.");

	    break;
	case 6:
	    strcpy(comment, "Thou knave! No less than %A2 gold pieces.");

	    break;
	case 7:
	    strcpy(comment, "%A1 is far too little; hou about %A2?");

	    break;
	case 8:
	    strcpy(comment, "I pid more than %A1 for it myself, try %A2");

	    break;
	case 9:
	    strcpy(comment, "%A1? Are you mad??? How about %A2 gold pieces?");

	    break;
	case 10:
	    strcpy(comment, "As scrap this would bring %A1. Try %A2 in gold.");

	    break;
	case 11:
	    strcpy(comment, "May the fleas of 1000 orcs molest you. I want %A2.");

	    break;
	case 12:
	    strcpy(comment, "My mother you can get for %A1, this costs %A2.");

	    break;
	case 13:
	    strcpy(comment, "May your chickens grow lips. I want %A2 in gold!");

	    break;
	case 14:
	    strcpy(comment, "Sell this for such little pittance? Give me %A2 gold.");

	    break;
	case 15:
	    strcpy(comment, "May the balrog find you tasty! %A2 gold pieces?");

	    break;
	case 16:
	    strcpy(comment, "Your mother was a troll! %A2 or I'll tell...");

	    break;
	}
    }

    insert_num(comment, "%A1", offer, FALSE);
    insert_num(comment, "%A2", asking, FALSE);
    msg_print(comment);
}

void prt_comment3(int offer, int asking, int final)
{
    vtype comment;

    if(final > 0) {
	switch(randint(3)) {
	case 1:
	    strcpy(comment, "I'll pay no more than %A1; take it or leave it.");

	    break;
	case 2:
	    strcpy(comment, "You'll get no more than %A1 from me...");

	    break;
	case 3:
	    strcpy(comment, "%A1 and that's final.");

	    break;
	}
    }
    else {
	switch(randint(15)) {
	case 1:
	    strcpy(comment, "%A2 for that piece of junk? No more than %A1");

	    break;
	case 2:
	    strcpy(comment, "For %A2 I could own ten of those. Try %A1.");

	    break;
	case 3:
	    strcpy(comment, "%A2? NEVER! %A1 is more like it...");

	    break;
	case 4:
	    strcpy(comment, "Let's be reasonable...How about %A1 gold pieces?");

	    break;
	case 5:
	    strcpy(comment, "%A1 gold for that junk, no more...");

	    break;
	case 6:
	    strcpy(comment, "%A1 gold pieces and be thankful for it!");

	    break;
	case 7:
	    strcpy(comment, "%A1 gold pieces and not a copper more...");

	    break;
	case 8:
	    strcpy(comment, "%A2 gold? HA! %A1 is more like it...");

	    break;
	case 9:
	    strcpy(comment, "Try about %A1 gold...");

	    break;
	case 10:
	    strcpy(comment, "I wouldn't pay %A2 for your children, try %A1.");

	    break;
	case 11:
	    strcpy(comment, "*CHOKE* For that!? Let's say %A1.");

	    break;
	case 12:
	    strcpy(comment, "How about %A1?");

	    break;
	case 13:
	    strcpy(comment, "That looks war surplus! Say %A1 gold.");

	    break;
	case 14:
	    strcpy(comment, "I'll buy it as scrap for %A1.");

	    break;
	case 15:
	    strcpy(comment, "%A2 is too much; let us say %A1 gold.");

	    break;
	}
    }

    insert_num(comment, "%A1", offer, FALSE);
    insert_num(comment, "%A2", asking, FALSE);
    msg_print(comment);
}

/* Kick 'da bum out... */
void prt_comment4()
{
    msg_flag = FALSE;

    switch(randint(5)) {
    case 1:
	msg_print("ENOUGH! Thou hast abused me once too often!");
	msg_print("Out of may place!");

	break;
    case 2:
	msg_print("THAT DOES IT! You shall waste my time no more!");
	msg_print("out...Out...OUT!!!");

	break;
    case 3:
	msg_print("This is getting nowhere...I'm going home!");
	msg_print("Come back tomorrow...");

	break;
    case 4:
	msg_print("BAH! No more shall you insult me!");
	msg_print("Leave my place...Begone!");

	break;
    case 5:
	msg_print("Begone! I have had enough abuse for one day.");
	msg_print("Come back when thou art richer...");

	break;
    }

    /* Make sure place sees last message, before he is kicked out of store */
    msg_print(" ");
    msg_flag = FALSE;
}

void prt_comment5()
{
    switch(randint(10)) {
    case 1:
	msg_print("You will have to do better than that!");

	break;
    case 2:
	msg_print("that's an insult!");

	break;
    case 3:
	msg_print("Do you wish to do business or not?");

	break;
    case 4:
	msg_print("Hah! Try again...");

	break;
    case 5:
	msg_print("Ridiculous!");

	break;
    case 6:
	msg_print("You've got to be kidding!");

	break;
    case 7:
	msg_print("You'd better be kidding!!");

	break;
    case 8:
	msg_print("You try my patience.");

	break;
    case 9:
	msg_print("I don't hear you.");

	break;
    case 10:
	msg_print("Hmmm, nice weather we're having...");

	break;
    }
}

void prt_comment6()
{
    switch(randint(5)) {
    case 1:
	msg_print("I must have heard you wrong...");

	break;
    case 2:
	msg_print("What was that?");

	break;
    case 3:
	msg_print("I'm sorry, say that again...");

	break;
    case 4:
	msg_print("What did you say?");

	break;
    case 5:
	msg_print("Sorry, what was that again?");

	break;
    }
}

/* Displays the set of commands    -RAK- */
void display_commands()
{
    prt("You may:", 20, 0);
    prt(" p) Purchase an item.         b) Browse store's inventory.", 21, 0);
    prt(" s) Sell an item.             i) Inventory and Equipment lists.", 22, 0);
    prt("ESC) Exit from building.     ^R) Redraw the screen.", 23, 0);
}

/* Displays the set of commands    -RAK- */
void haggle_commands(int typ)
{
    if(typ == -1) {
	prt("Specify an asking price in gold pieces.", 21, 0);
    }
    else {
	prt("Specify an offer in gold pieces.", 21, 0);
    }

    prt("ESC) Quit haggling.", 22, 0);

    /* Clear last line. */
    prt("", 23, 0);
}

/* Displays a store's inventory    -RAK- */
void display_inventory(int store_num, int start)
{
    store_type *s_ptr;
    treasure_type *i_ptr;
    int i;
    int j;
    int stop;
    vtype out_val1;
    vtype out_val2;

    s_ptr = &store[store_num];
    i = start % 12;
    stop = ((start / 12) + 1) * 12;

    if(stop > s_ptr->store_ctr) {
	stop = s_ptr->store_ctr;
    }

    while(start < stop) {
	inventory[INVEN_MAX] = s_ptr->store_inven[start].sitem;
	i_ptr = &inventory[INVEN_MAX];

	if((i_ptr->subval > 255) && (i_ptr->subval < 512)) {
	    i_ptr->number = 1;
	}

	objdes(out_val1, INVEN_MAX, TRUE);
	sprintf(out_val2, "%c) %s", 97 + i, out_val1);
	prt(out_val2, i + 5, 0);

	if(s_ptr->store_inven[start].scost <= 0) {
	    j = abs(s_ptr->store_inven[start].scost);
	    j += (j * chr_adj());

	    if(j <= 0) {
		j = 1;
	    }

	    sprintf(out_val2, "%9d", j);
	}
	else {
	    sprintf(out_val2, "%9d [Fixed]", s_ptr->store_inven[start].scost);
	}

	prt(out_val2, i + 5, 59);
	++i;
	++start;
    }

    if(i < 12) {
	for(j = 0; j < (11 - i + 1); ++j) {
	    /* Clear remaining lines */
	    prt("", j + i + 5, 0);
	}
    }

    if(s_ptr->store_ctr > 12) {
	prt("- cont. -", 17, 60);
    }
    else {
	/* Clear the line */
	prt("", 17, 60);
    }
}

/* Re-displays only a single cost    -RAK- */
void display_cost(int store_num, int pos)
{
    int i;
    int j;
    vtype out_val;
    store_type *s_ptr;

    s_ptr = &store[store_num];
    i = pos % 12;

    if(s_ptr->store_inven[pos].scost < 0) {
	j = abs(s_ptr->store_inven[pos].scost);
	j += (j * chr_adj());
	sprintf(out_val, "%d", j);
    }
    else {
	sprintf(out_val, "%9d [Fixed]", s_ptr->store_inven[pos].scost);
    }

    prt(out_val, i + 5, 59);
}

/* Displays player's gold    -RAK- */
void store_prt_gold()
{
    vtype out_val;

    sprintf(out_val, "Gold remaining : %d", py.misc.au);
    prt(out_val, 18, 17);
}

/* Displays store    -RAK- */
void display_store(int store_num, int cur_top)
{
    store_type *s_ptr;

    s_ptr = &store[store_num];
    really_clear_screen();
    prt(owners[s_ptr->owner].owner_name, 3, 9);
    prt("   Item", 4, 0);
    prt("Asking price", 4, 60);
    store_prt_gold();
    display_commands();
    display_inventory(store_num, cur_top);
}

/* Get the ID of a store item and return it's value    -RAK- */
int get_store_item(int *com_val, char *pmt, int i, int j)
{
    char command;
    vtype out_val;
    int flag;

    *com_val = -1;
    flag = TRUE;
    sprintf(out_val, "(Items %c-%c, ESC to exit) %s", i + 97, j + 97, pmt);

    while(((*com_val < i) || (*com_val > j)) && flag) {
	prt(out_val, 0, 0);
	inkey(&command);
	*com_val = command;

	switch(*com_val) {
	case 0:
	case 27:
	    flag = FALSE;

	    break;
	default:
	    *com_val = *com_val - 97;

	    break;
	}
    }

    msg_flag = FALSE;
    erase_line(MSG_LINE, 0);

    return flag;
}

/* Increase the insult counter and get pissed if too many    -RAK- */
int increase_insults(int store_num)
{
    int increase;
    store_type *s_ptr;

    increase = FALSE;
    s_ptr = &store[store_num];
    ++s_ptr->insult_cur;

    if(s_ptr->insult_cur > owners[s_ptr->owner].insult_max) {
	prt_comment4();
	s_ptr->insult_cur = 0;
	s_ptr->store_open = turn + 2500 + randint(2500);
	increase = TRUE;
    }

    return increase;
}

/* Decrease insults    -RAK- */
void decrease_insults(int store_num)
{
    store_type *s_ptr;

    s_ptr = &store[store_num];
    s_ptr->insult_cur -= 2;

    if(s_ptr->insult_cur < 0) {
	s_ptr->insult_cur = 0;
    }
}

/* Have insulted while haggling    -RAK- */
int haggle_insults(int store_num)
{
    int haggle;

    haggle = FALSE;

    if(increase_insults(store_num)) {
	haggle = TRUE;
    }
    else {
	prt_comment5();
    }

    return haggle;
}

int get_haggle(char *comment, int *num)
{
    int i;
    vtype out_val;
    int flag;
    int clen;

    flag = TRUE;
    i = 0;
    clen = strlen(comment);

    msg_print(comment);
    msg_flag = FALSE;

    if(!get_string(out_val, 0, clen, 40)) {
	flag = FALSE;
	erase_line(MSG_LINE, 0);
    }

    sscanf(out_val, "%d", &i);

    while((i <= 0) && flag) {
	msg_print(comment);
	msg_flag = FALSE;

	if(!get_string(out_val, 0, clen, 40)) {
	    flag = FALSE;
	    erase_line(MSG_LINE, 0);
	}

	sscanf(out_val, "%d", &i);
    }

    if(flag) {
	*num = i;
    }

    return flag;
}

int receive_offer(int store_num, char *comment, int *new_offer, int last_offer, int factor)
{
    int flag;
    int receive;

    receive = 0;
    flag = FALSE;

    if(get_haggle(comment, new_offer)) {
	if((*new_offer * factor) >= (last_offer * factor)) {
	    flag = TRUE;
	}
	else if(haggle_insults(store_num)) {
	    receive = 2;
	    flag = TRUE;
	}
    }
    else {
	receive = 1;
	flag = TRUE;
    }

    while(!flag) {
	if(get_haggle(comment, new_offer)) {
	    if((*new_offer * factor) >= (last_offer * factor)) {
		flag = TRUE;
	    }
	    else if(haggle_insults(store_num)) {
		receive = 2;
		flag = TRUE;
	    }
	}
	else {
	    receive = 1;
	    flag = TRUE;
	}
    }

    return receive;
}

/* Haggling routine    -RAK- */
int purchase_haggle(int store_num, int *price, treasure_type item)
{
    int max_sell;
    int min_sell;
    int max_buy;
    int cost;
    int cur_ask;
    int final_ask;
    int min_offer;
    int last_offer;
    int new_offer;
    int final_flag = 0;
    int x3;
    double x1;
    double x2;
    double min_per;
    double max_per;
    int flag;
    int loop_flag;
    vtype out_val;
    vtype comment;
    int purchase;
    store_type *s_ptr;
    owner_type *o_ptr;

    flag = FALSE;
    purchase = 0;
    *price = 0;
    msg_flag = FALSE;
    s_ptr = &store[store_num];
    o_ptr = &owners[s_ptr->owner];
    cost = sell_price(store_num, &max_sell, &min_sell, item);
    max_sell = max_sell + (max_sell * chr_adj());

    if(max_sell <= 0) {
	max_sell = 1;
    }

    min_sell = min_sell + (min_sell * chr_adj());

    if(min_sell <= 0) {
	min_sell = 1;
    }

    max_buy = cost * (1 - o_ptr->max_inflate);
    min_per = o_ptr->haggle_per;
    max_per = min_per * 3.0;
    haggle_commands(1);
    cur_ask = max_sell;
    final_ask = min_sell;
    min_offer = max_buy;
    last_offer = min_offer;
    strcpy(comment, "Asking :");

    loop_flag = TRUE;
    sprintf(out_val, "%s %d", comment, cur_ask);
    put_buffer(out_val, 1, 0);

    switch(receive_offer(store_num, "What do you offer? ", &new_offer, last_offer, 1)) {
    case 1:
	purchase = 1;
	flag = TRUE;

	break;
    case 2:
	purchase = 2;
	flag = TRUE;

	break;
    default:
	if(new_offer > cur_ask) {
	    prt_comment6();
	}
	else if(new_offer == cur_ask) {
	    flag = TRUE;
	    *price = new_offer;
	}
	else {
	    loop_flag = FALSE;
	}
    }

    while(!flag && loop_flag) {
	loop_flag = TRUE;
	sprintf(out_val, "%s %d", comment, cur_ask);
	put_buffer(out_val, 1, 0);

	switch(receive_offer(store_num, "What do you offer? ", &new_offer, last_offer, 1)) {
	case 1:
	    purchase = 1;
	    flag = TRUE;

	    break;
	case 2:
	    purchase = 2;
	    flag = TRUE;

	    break;
	default:
	    if(new_offer > cur_ask) {
		prt_comment6();
	    }
	    else if(new_offer == cur_ask) {
		flag = TRUE;
		*price = new_offer;
	    }
	    else {
		loop_flag = FALSE;
	    }
	}
    }

    if(!flag) {
	x1 = (double)(new_offer - last_offer) / (double)(cur_ask - last_offer);

	if(x1 < min_per) {
	    flag = haggle_insults(store_num);

	    if(flag) {
		purchase = 2;
	    }
	}
	else {
	    if(x1 > max_per) {
		x1 = x1 * 0.75;

		if(x1 < max_per) {
		    x1 = max_per;
		}
	    }
	}

	x2 = x1 + ((randint(5) - 3) / 100.0);
	x3 = ((cur_ask - new_offer) * x2) + 1;

	/* Don't let the price go up */
	if(x3 < 0) {
	    x3 = 0;
	}

	cur_ask -= x3;

	if(cur_ask < final_ask) {
	    cur_ask = final_ask;
	    strcpy(comment, "Final offer : ");
	    ++final_flag;

	    if(final_flag > 3) {
		if(increase_insults(store_num)) {
		    purchase = 2;
		}
		else {
		    purchase = 1;
		}

		flag = TRUE;
	    }
	}
	else if(new_offer >= cur_ask) {
	    flag = TRUE;
	    *price = new_offer;
	}

	if(!flag) {
	    last_offer = new_offer;

	    /* Clear the line */
	    prt("", 1, 0);
	    sprintf(out_val, "Your last offer : %d", last_offer);
	    put_buffer(out_val, 1, 39);
	    prt_comment2(last_offer, cur_ask, final_flag);
	}
    }

    while(!flag) {
	loop_flag = TRUE;
	sprintf(out_val, "%s %d", comment, cur_ask);
	put_buffer(out_val, 1, 0);

	switch(receive_offer(store_num, "What do you offer? ", &new_offer, last_offer, 1)) {
	case 1:
	    purchase = 1;
	    flag = TRUE;

	    break;
	case 2:
	    purchase = 2;
	    flag = TRUE;

	    break;
	default:
	    if(new_offer > cur_ask) {
		prt_comment6();
	    }
	    else if(new_offer == cur_ask) {
		flag = TRUE;
		*price = new_offer;
	    }
	    else {
		loop_flag = FALSE;
	    }
	}

	while(!flag && loop_flag) {
	    loop_flag = TRUE;
	    sprintf(out_val, "%s %d", comment, cur_ask);
	    put_buffer(out_val, 1, 0);

	    switch(receive_offer(store_num, "What do you offer? ", &new_offer, last_offer, 1)) {
	    case 1:
		purchase = 1;
		flag = TRUE;

		break;
	    case 2:
		purchase = 2;
		flag = TRUE;

		break;
	    default:
		if(new_offer > cur_ask) {
		    prt_comment6();
		}
		else if(new_offer == cur_ask) {
		    flag = TRUE;
		    *price = new_offer;
		}
		else {
		    loop_flag = FALSE;
		}
	    }
	}

	if(!flag) {
	    x1 = (double)(new_offer - last_offer) / (double)(cur_ask - last_offer);

	    if(x1 < min_per) {
		flag = haggle_insults(store_num);

		if(flag) {
		    purchase = 2;
		}
	    }
	    else {
		if(x1 > max_per) {
		    x1 = x1 * 0.75;

		    if(x1 < max_per) {
			x1 = max_per;
		    }
		}
	    }

	    x2 = x1 + ((randint(5) - 3) / 100.0);
	    x3 = ((cur_ask - new_offer) * x2) + 1;

	    /* Don't let the price go up */
	    if(x3 < 0) {
		x3 = 0;
	    }

	    cur_ask -= x3;

	    if(cur_ask < final_ask) {
		cur_ask = final_ask;
		strcpy(comment, "Final offer : ");
		++final_flag;

		if(final_flag > 3) {
		    if(increase_insults(store_num)) {
			purchase = 2;
		    }
		    else {
			purchase = 1;
		    }

		    flag = TRUE;
		}
	    }
	    else if(new_offer >= cur_ask) {
		flag = TRUE;
		*price = new_offer;
	    }

	    if(!flag) {
		last_offer = new_offer;

		/* Clear the line */
		prt("", 1, 0);
		sprintf(out_val, "Your last offer : %d", last_offer);
		put_buffer(out_val, 1, 39);
		prt_comment2(last_offer, cur_ask, final_flag);
	    }
	}
    }

    /* Clear the line */
    prt("", 1, 0);
    display_commands();

    return purchase;
}

/* Haggling routine    -RAK- */
int sell_haggle(int store_num, int *price, treasure_type item)
{
    int max_sell;
    int max_buy;
    int min_buy;
    int cost;
    int cur_ask;
    int final_ask;
    int min_offer;
    int last_offer;
    int new_offer;
    int final_flag;
    int x3;
    int max_gold;
    double x1;
    double x2;
    double min_per;
    double max_per;
    int flag;
    int loop_flag;
    vtype comment;
    vtype out_val;
    store_type *s_ptr;
    owner_type *o_ptr;
    int sell;

    flag = FALSE;
    sell = 0;
    *price = 0;
    msg_flag = FALSE;
    s_ptr = &store[store_num];
    cost = item_value(item);

    if(cost < 1) {
	sell = 3;
	flag = TRUE;
    }
    else {
	o_ptr = &owners[s_ptr->owner];
	cost += (-(cost * chr_adj()) - (cost * rgold_adj[o_ptr->owner_race][py.misc.prace]));

	if(cost < 1) {
	    cost = 1;
	}

	max_sell = cost * (1 + o_ptr->max_inflate);
	max_buy = cost * (1 - o_ptr->max_inflate);
	min_buy = cost * (1 - o_ptr->min_inflate);

	if(min_buy < 1) {
	    min_buy = 1;
	}

	if(max_buy < 1) {
	    max_buy = 1;
	}

	if(min_buy < max_buy) {
	    min_buy = max_buy;
	}

	min_per = o_ptr->haggle_per;
	max_per = min_per * 3.0;
	max_gold = o_ptr->max_cost;
    }

    if(!flag) {
	haggle_commands(-1);

	if(max_buy > max_gold) {
	    final_flag = 1;
	    strcpy(comment, "Final offer : ");
	    cur_ask = max_gold;
	    final_ask = max_gold;
	    msg_print("I am sorry, but I have not the money to afford such a fine item.");
	    
	    /* Make sure player sees the message */
	    msg_print(" ");
	}
	else {
	    cur_ask = max_buy;
	    final_ask = min_buy;

	    if(final_ask > max_gold) {
		final_ask = max_gold;
	    }

	    strcpy(comment, "Offer : ");
	}

	min_offer = max_sell;
	last_offer = min_offer;

	if(cur_ask < 1) {
	    cur_ask = 1;
	}

	loop_flag = TRUE;
	sprintf(out_val, "%s %d", comment, cur_ask);
	put_buffer(out_val, 1, 0);

	switch(receive_offer(store_num, "What price do you ask? ", &new_offer, last_offer, -1)) {
	case 1:
	    sell = 1;
	    flag = TRUE;

	    break;
	case 2:
	    sell = 2;
	    flag = TRUE;

	    break;
	default:
	    if(new_offer < cur_ask) {
		prt_comment6();
	    }
	    else if(new_offer == cur_ask) {
		flag = TRUE;
		*price = new_offer;
	    }
	    else {
		loop_flag = FALSE;
	    }
	}

	while(!flag && loop_flag) {
	    loop_flag = TRUE;
	    sprintf(out_val, "%s %d", comment, cur_ask);
	    put_buffer(out_val, 1, 0);

	    switch(receive_offer(store_num, "What price do you ask? ", &new_offer, last_offer, -1)) {
	    case 1:
		sell = 1;
		flag = TRUE;

		break;
	    case 2:
		sell = 2;
		flag = TRUE;

		break;
	    default:
		if(new_offer < cur_ask) {
		    prt_comment6();
		}
		else if(new_offer == cur_ask) {
		    flag = TRUE;
		    *price = new_offer;
		}
		else {
		    loop_flag = FALSE;
		}
	    }
	}

	if(!flag) {
	    msg_flag = FALSE;
	    x1 = (double)(last_offer - new_offer) / (double)(last_offer - cur_ask);

	    if(x1 < min_per) {
		flag = haggle_insults(store_num);

		if(flag) {
		    sell = 2;
		}
	    }
	    else {
		if(x1 > max_per) {
		    x1 = x1 * 0.75;
		}
	    }

	    x2 = x1 + ((randint(5) - 3) / 100.0);
	    x3 = ((new_offer - cur_ask) * x2) + 1;

	    /* Don't let the price go down */
	    if(x3 < 0) {
		x3 = 0;
	    }

	    cur_ask += x3;

	    if(cur_ask > final_ask) {
		cur_ask = final_ask;
		strcpy(comment, "Final offer : ");
		++final_flag;

		if(final_flag > 3) {
		    if(increase_insults(store_num)) {
			sell = 2;
		    }
		    else {
			sell = 1;
		    }

		    flag = TRUE;
		}
	    }
	    else if(new_offer <= cur_ask) {
		flag = TRUE;
		*price = new_offer;
	    }

	    if(!flag) {
		last_offer = new_offer;

		/* Clear the line */
		prt("", 1, 0);
		sprintf(out_val, "Your last bid %d", last_offer);
		put_buffer(out_val, 1, 39);
		prt_comment3(cur_ask, last_offer, final_flag);
	    }
	}

	while(!flag) {
	    loop_flag = TRUE;
	    sprintf(out_val, "%s %d", comment, cur_ask);
	    put_buffer(out_val, 1, 0);

	    switch(receive_offer(store_num, "What price do you ask? ", &new_offer, last_offer, -1)) {
	    case 1:
		sell = 1;
		flag = TRUE;

		break;
	    case 2:
		sell = 2;
		flag = TRUE;

		break;
	    default:
		if(new_offer < cur_ask) {
		    prt_comment6();
		}
		else if(new_offer == cur_ask) {
		    flag = TRUE;
		    *price = new_offer;
		}
		else {
		    loop_flag = FALSE;
		}
	    }

	    while(!flag && loop_flag) {
		loop_flag = TRUE;
		sprintf(out_val, "%s %d", comment, cur_ask);
		put_buffer(out_val, 1, 0);

		switch(receive_offer(store_num, "What price do you ask? ", &new_offer, last_offer, -1)) {
		case 1:
		    sell = 1;
		    flag = TRUE;

		    break;
		case 2:
		    sell = 2;

		    flag = TRUE;
		default:
		    if(new_offer < cur_ask) {
			prt_comment6();
		    }
		    else if(new_offer == cur_ask) {
			flag = TRUE;
			*price = new_offer;
		    }
		    else {
			loop_flag = FALSE;
		    }
		}
	    }

	    if(!flag) {
		msg_flag = FALSE;
		x1 = (double)(last_offer - new_offer) / (double)(last_offer - cur_ask);

		if(x1 < min_per) {
		    flag = haggle_insults(store_num);

		    if(flag) {
			sell = 2;
		    }
		}
		else {
		    if(x1 > max_per) {
			x1 = x1 * 0.75;
		    }
		}

		x2 = x1 + ((randint(5) - 3) / 100.0);
		x3 = ((new_offer - cur_ask) * x2) + 1;

		/* Don't let the price go down */
		if(x3 < 0) {
		    x3 = 0;
		}

		cur_ask += x3;

		if(cur_ask > final_ask) {
		    cur_ask = final_ask;
		    strcpy(comment, "Final offer : ");
		    ++final_flag;

		    if(final_flag > 3) {
			if(increase_insults(store_num)) {
			    sell = 2;
			}
			else {
			    sell = 1;
			}

			flag = TRUE;
		    }
		}
		else if(new_offer <= cur_ask) {
		    flag = TRUE;
		    *price = new_offer;
		}

		if(!flag) {
		    last_offer = new_offer;

		    /* Clear the line */
		    prt("", 1, 0);
		    sprintf(out_val, "Your last bid %d", last_offer);
		    put_buffer(out_val, 1, 39);
		    prt_comment3(cur_ask, last_offer, final_flag);
		}
	    }
	}

	/* Clear the line */
	prt("", 1, 0);
	display_commands();
    }

    return sell;
}

/* Buy an item from a store    -RAK- */
int store_purchase(int store_num, int *cur_top)
{
    int i;
    int item_val;
    int price;
    int item_new;
    int choice;
    int save_number;
    vtype out_val;
    vtype tmp_str;
    store_type *s_ptr;
    treasure_type *i_ptr;
    inven_record *r_ptr;
    int purchase;

    purchase = FALSE;
    s_ptr = &store[store_num];

    /* i == Number of objects shown on screen */
    if(*cur_top == 12) {
	i = s_ptr->store_ctr - 1 - 12;
    }
    else if(s_ptr->store_ctr > 11) {
	i = 11;
    }
    else {
	i = s_ptr->store_ctr - 1;
    }

    if(s_ptr->store_ctr < 1) {
	msg_print("I am currently out of stock.");
    }
    else if(get_store_item(&item_val, "Which item are you interested in? ", 0, i)) {
	/* Get the item number to be bought */

	/* TRUE item_val */
	item_val = item_val + *cur_top;
	inventory[INVEN_MAX] = s_ptr->store_inven[item_val].sitem;
	i_ptr = &inventory[INVEN_MAX];

	if((i_ptr->subval > 255) && (i_ptr->subval < 512)) {
	    save_number = i_ptr->number;
	    i_ptr->number = 1;
	}
	else {
	    save_number = 1;
	}

	if(inven_check_weight()) {
	    if(inven_check_num()) {
		if(s_ptr->store_inven[item_val].scost > 0) {
		    price = s_ptr->store_inven[item_val].scost;
		    choice = 0;
		}
		else {
		    choice = purchase_haggle(store_num, &price, inventory[INVEN_MAX]);
		}

		switch(choice) {
		case 0:
		    if(py.misc.au >= price) {
			prt_comment1();
			decrease_insults(store_num);
			py.misc.au -= price;
			store_destroy(store_num, item_val, TRUE);
			inven_carry(&item_new);
			objdes(tmp_str, item_new, TRUE);
			sprintf(out_val, "You have %s (%c)", tmp_str, item_new + 97);
			msg_print(out_val);

			if(*cur_top >= s_ptr->store_ctr) {
			    *cur_top = 0;
			    display_inventory(store_num, *cur_top);
			}
			else {
			    r_ptr = &s_ptr->store_inven[item_val];

			    if(save_number > 1) {
				if(r_ptr->scost < 0) {
				    r_ptr->scost = price;
				    display_cost(store_num, item_val);
				}
			    }
			    else {
				display_inventory(store_num, item_val);
			    }

			    store_prt_gold();
			}
		    }
		    else {
			if(increase_insults(store_num)) {
			    purchase = TRUE;
			}
			else {
			    prt_comment1();
			    msg_print("Liar! You have not the gold!");
			}
		    }

		    break;
		case 2:
		    purchase = TRUE;

		    break;
		default:

		    break;
		}

		/* Clear the line */
		prt("", 1, 0);
	    }
	    else {
		prt("You cannot carry that many different items.", 0, 0);
	    }
	}
	else {
	    prt("You can not carry that much weight.", 0, 0);
	}
    }

    return purchase;
}

/* Sell an item to the store    -RAK- */
int store_sell(int store_num, int cur_top)
{
    int item_val;
    int item_pos;
    int price;
    int redraw;
    vtype out_val;
    vtype tmp_str;
    treasure_type *i_ptr;
    int sell;

    sell = FALSE;
    redraw = FALSE;

    if(get_item(&item_val, "Which one? ", &redraw, 0, inven_ctr - 1)) {
	if(redraw) {
	    display_store(store_num, cur_top);
	}

	inventory[INVEN_MAX] = inventory[item_val];
	i_ptr = &inventory[INVEN_MAX];

	if((i_ptr->subval > 255) && (i_ptr->subval < 512)) {
	    i_ptr->number = 1;
	}

	objdes(tmp_str, INVEN_MAX, TRUE);
	sprintf(out_val, "Selling %s (%c)", tmp_str, item_val + 97);
	msg_print(out_val);

	/* Make sure the player sees the message */
	msg_print(" ");

	if(store_buy[store_num](inventory[INVEN_MAX].tval)) {
	    if(store_check_num(store_num)) {
		switch(sell_haggle(store_num, &price, inventory[INVEN_MAX])) {
		case 0:
		    prt_comment1();
		    py.misc.au += price;
		    inven_destroy(item_val);
		    store_carry(store_num, &item_pos);

		    if(item_pos >= 0) {
			if(item_pos < 12) {
			    if(cur_top < 12) {
				display_inventory(store_num, item_pos);
			    }
			    else {
				display_inventory(store_num, cur_top);
			    }
			}
		    }
		    else if(cur_top > 11) {
			display_inventory(store_num, item_pos);
		    }

		    store_prt_gold();

		    break;
		case 2:
		    sell = TRUE;

		    break;
		case 3:
		    msg_print("How dare you!");
		    msg_print("I will not buy that!");
		    sell = increase_insults(store_num);

		    break;
		default:

		    break;
		}
	    }
	    else {
		prt("I have not the room in my store to keep it...", 0, 0);
	    }
	}
	else {
	    prt("I do not buy such items.", 0, 0);
	}
    }
    else if(redraw) {
	display_store(store_num, cur_top);
    }

    return sell;
}

/* Entering a store    -RAK- */
void enter_store(int store_num)
{
    int com_val;
    int cur_top;
    char command;
    int exit_flag;
    store_type *s_ptr;

    s_ptr = &store[store_num];

    if(s_ptr->store_open < turn) {
	exit_flag = FALSE;
	cur_top = 0;
	display_store(store_num, cur_top);

	if(get_com("", &command)) {
	    msg_flag = FALSE;
	    com_val = command;

	    switch(com_val) {
	    case 18:
		display_store(store_num, cur_top);

		break;
	    case 98:
		if(cur_top == 0) {
		    if(s_ptr->store_ctr > 12) {
			cur_top = 12;
			display_inventory(store_num, cur_top);
		    }
		    else {
			prt("Entire inventory is shown.", 0, 0);
		    }
		}
		else {
		    cur_top = 0;
		    display_inventory(store_num, cur_top);
		}

		break;
	    case 101: /* Equipment list */
		if(inven_command('e', 0, 0)) {
		    display_store(store_num, cur_top);
		}

		break;
	    case 105: /* Inventory */
		if(inven_command('i', 0, 0)) {
		    display_store(store_num, cur_top);
		}

		break;
	    case 116: /* Take off */
		if(inven_command('t', 0, 0)) {
		    display_store(store_num, cur_top);
		}

		break;
	    case 119: /* Wear */
		if(inven_command('w', 0, 0)) {
		    display_store(store_num, cur_top);
		}

		break;
	    case 120: /* Switch weapon */
		if(inven_command('x', 0, 0)) {
		    display_store(store_num, cur_top);
		}

		break;
	    case 112:
		exit_flag = store_purchase(store_num, &cur_top);

		break;
	    case 115:
		exit_flag = store_sell(store_num, cur_top);

		break;
	    default:
		prt("Invalid command.", 0, 0);

		break;
	    }
	}
	else {
	    exit_flag = TRUE;
	}

	while(!exit_flag) {
	    if(get_com("", &command)) {
		msg_flag = FALSE;
		com_val = command;

		switch(com_val) {
		case 18:
		    display_store(store_num, cur_top);

		    break;
		case 98:
		    if(cur_top == 0) {
			if(s_ptr->store_ctr > 12) {
			    cur_top = 12;
			    display_inventory(store_num, cur_top);
			}
			else {
			    prt("Entire inventory is shown.", 0, 0);
			}
		    }
		    else {
			cur_top = 0;
			display_inventory(store_num, cur_top);
		    }

		    break;
		case 101: /* Equipment list */
		    if(inven_command('e', 0, 0)) {
			display_store(store_num, cur_top);
		    }

		    break;
		case 105: /* Inventory */
		    if(inven_command('i', 0, 0)) {
			display_store(store_num, cur_top);
		    }

		    break;
		case 116: /* Take off */
		    if(inven_command('t', 0, 0)) {
			display_store(store_num, cur_top);
		    }

		    break;
		case 119: /* Wear */
		    if(inven_command('w', 0, 0)) {
			display_store(store_num, cur_top);
		    }

		    break;
		case 120: /* Switch weapon */
		    if(inven_command('x', 0, 0)) {
			display_store(store_num, cur_top);
		    }

		    break;
		case 112:
		    exit_flag = store_purchase(store_num, &cur_top);

		    break;
		case 115:
		    exit_flag = store_sell(store_num, cur_top);

		    break;
		default:
		    prt("Invalid command.", 0, 0);

		    break;
		}
	    }
	    else {
		exit_flag = TRUE;
	    }
	}

	draw_cave();
    }
    else {
	msg_print("The doors are locked.");
    }
}
