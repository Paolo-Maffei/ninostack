/*
    NanoStack: MCU software and PC tools for IP-based wireless sensor networking.
		
    Copyright (C) 2006-2007 Sensinode Ltd.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

		Address:
		Sensinode Ltd.
		Teknologiantie 6	
		90570 Oulu, Finland

		E-mail:
		info@sensinode.com
*/


#define NANOSENSE_VERSION 1.1
#define LIBNANOSENSE_VERSION 0.5

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define GET_ALL_CONTEXTS 0xff

typedef struct context_def_t
{
	unsigned char context_type;
	char context_descr[16];
} context_def_t;


enum libNS_pkt_types { ADVERTISE = 0x00, PUBLISH, SUBSCRIBE };

int libNS_create_adv_msg(unsigned char *buf, unsigned short int ttl, unsigned char contexts, struct context_def_t *context_def);

int libNS_create_pub_msg(unsigned char *buf, unsigned short int sample_rate, unsigned char contexts, unsigned char samples, unsigned char *context_types, unsigned short int **data);

int libNS_create_sub_msg(unsigned char *buf, unsigned short int ttl, unsigned short int sample_interval, unsigned char contexts, unsigned char *context_types, unsigned char *utility_values);

int libNS_parse_adv_msg(unsigned char *buf, unsigned short int len, unsigned short int *ttl, unsigned char *contexts, struct context_def_t *context_def);

int libNS_parse_pub_msg(unsigned char *buf, unsigned short int *sample_int, unsigned char *contexts, unsigned char *samples, unsigned char *context_types, unsigned short int **data);

int libNS_parse_sub_msg(unsigned char *buf, unsigned short int *ttl, unsigned short int *sample_int, unsigned char *contexts, unsigned char *context_types, unsigned char *utility_values);
