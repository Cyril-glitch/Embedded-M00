/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:21:28 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/07 12:57:56 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int is_set(uint8_t reg, int pos)
{
    return (reg & (1 << pos));
}

int is_press(uint8_t sw, int pos)
{
    return !(sw & (1 << pos));
}

int is_release(uint8_t sw, int pos)
{
    return (sw & (1 << pos));
}

void ignite(volatile uint8_t *led, int pos)
{
    volatile uint8_t* ddr = led - 1;
    SET(*led, pos);
    SET(*ddr, pos);
}

void turnoff(volatile uint8_t *led, int pos)
{
    volatile uint8_t* ddr = led - 1;
    CLEAR(*led, pos);
    CLEAR(*ddr, pos);
}

