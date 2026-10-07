/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/07 14:08:56 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main()
{
    SET(DDR_B, 0); // set DDRB0 on writing mode
    volatile uint8_t saved_state = 0;                       
    volatile uint8_t cur_state = 0;

    while (1)
    {
        cur_state = is_press(PIN_D, 2);         // get switch status
        if (cur_state > saved_state)            // falling edge detection
            TOGGLE(PORT_B, 0);
        saved_state = cur_state;                // saved switch status for next loop
        _delay_ms(20);
    }
}