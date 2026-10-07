/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/07 14:12:09 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#define PORT_B  (*((volatile uint8_t *) 0x25))
#define PORT_D  (*((volatile uint8_t *) 0x2B))

#define DDR_B  (*((volatile uint8_t *) 0x24))
#define DDR_D  (*((volatile uint8_t *) 0x2A))

#define PIN_D (*(volatile uint8_t *) 0x29)

#define SET(reg, pos) (reg |= (1U << pos))
#define CLEAR(reg, pos) (reg &= ~(1U << pos))

int is_set(uint8_t reg, int pos)
{
    return (reg & (1 << pos));
}

int main()
{
    SET(DDR_B, 0);                     //set ddr to writing mode
    while (1)
    {
        if (is_set(PIN_D, 2))         // if sw1 is release
            CLEAR(PORT_B, 0);         // turnoff led
        else if (!is_set(PIN_D, 2))   // if sw1 is pull down
            SET(PORT_B, 0);           // ignite led
    }
    return 0;
}