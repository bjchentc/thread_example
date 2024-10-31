/*
 * Copyright (c) 2024 ITE Tech. Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <stdio.h>
#define USER_STACKSIZE	2048

uint32_t counter=0;

struct k_thread user_thread;
K_THREAD_STACK_DEFINE(user_stack, USER_STACKSIZE);

static void user_function(void *p1, void *p2, void *p3)
{
	while(1) {
		printf("[App-level] One-second counter in thread function = %d\n", counter);
		k_msleep(1000);
		counter++;
	}
}

int main(void)
{
	printf("IT513XX: Thread Example -- %s\n", CONFIG_BOARD_TARGET);

	k_thread_create(&user_thread, user_stack, USER_STACKSIZE,
			user_function, NULL, NULL, NULL,
			0, K_USER, K_NO_WAIT);

	return 0;
}
