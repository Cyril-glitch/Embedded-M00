/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/07 14:04:56 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#define PORT_B  (*((volatile uint8_t *) 0x25))
#define DDR_B  (*((volatile uint8_t *) 0x24))

int main()
{
    //Set DDRB B0 to 1 (input/output config)     
    DDR_B |= 1;
    //Set PORTB b0 to 1 (ignite led)
    PORT_B |= 1;

    /*
    ddrb      = 0000 0000
    1U        = 0000 0001
    ddrb | 1U = 0000 0001
    */
    return 0;
}