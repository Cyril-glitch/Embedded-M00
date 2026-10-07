/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:19:44 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/07 11:28:47 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <util/delay.h>

//REGISTRES ADRESSE
#define PORT_B  (*((volatile uint8_t *) 0x25))
#define PORT_D  (*((volatile uint8_t *) 0x2B))

#define DDR_B  (*((volatile uint8_t *) 0x24))
#define DDR_D  (*((volatile uint8_t *) 0x2A))

#define PIN_D (*(volatile uint8_t *) 0x29)

//BITWISE MACRO
#define SET(reg, pos) (reg |= (1U << pos))
#define CLEAR(reg, pos) (reg &= ~(1U << pos))
#define TOGGLE(reg, pos) (reg ^= (1U << pos))

#define LOW 0
#define HIGH 1


//BIT STATUS
int is_set(uint8_t reg, int pos);

int is_press(uint8_t sw, int pos);

int is_release(uint8_t sw, int pos);

void ignite(volatile uint8_t *led, int pos);

void turnoff(volatile uint8_t *led, int pos);


#endif
