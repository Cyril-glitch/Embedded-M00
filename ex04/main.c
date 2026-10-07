/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/07 13:12:03 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void display(volatile uint8_t val)
{
    PORT_B = (val & 0b00000111);                   //get val bits(0 - 2) stats
    PORT_B |= (val & 0b00001000) << 1;             //get val bits(3) stats
}

void increment(volatile uint8_t *val)
{
    static volatile uint8_t saved_state = 0;
    static volatile uint8_t cur_state = 0;

    cur_state = is_press(PIN_D, 2);                 // get cur bouton state
    if (cur_state > saved_state)                    // detect falling edge
    {
        (*val)++;
        display(*val);
    }
    saved_state = cur_state;                        // saved bouton state for next loop
}

void decrement(volatile uint8_t *val)
{
    static volatile uint8_t saved_state = 0;
    static volatile uint8_t cur_state = 0;

    cur_state = is_press(PIN_D, 4);                 // get cur bouton state
    if (cur_state > saved_state)                    // detect falling edge
    {
        (*val)--;
        display(*val);
    }
    saved_state = cur_state;                        // saved bouton state for next loop
}

int main()
{
    DDR_B = 0b00010111;                //set all DDR to writing mode
    volatile uint8_t val = 0;

    while (1)
    {
        increment(&val);
        decrement(&val);
        _delay_ms(20);                //deboucing switch
    }
}