/**
 * Copyright Sunpy 2025
 * 
 * This is actually also a very efficient way to have 2 processes communicate without opening any port.
 * Simply access the process' memory and write to the address for quick secure cross process communication.
 *      
 *                                       |\    /|
 *                                    ___| \,,/_/
 *                                 ---__/ \/    \
 *                                __--/     (D)  \
 *                                _ -/    (_      \
 *                               // /       \_ /  -\
 *         __-------_____--___--/           / \_ O o)       <-- Horse (not donkey)
 *        /                                 /   \__/
 *       /                                 /
 *      ||          )                   \_/\
 *      ||         /              _      /  |
 *      | |      /--______      ___\    /\  :
 *      | /   __-  - _/   ------    |  |   \ \
 *       |   -  -   /                | |     \ )
 *       |  |   -  |                 | )     | |
 *        | |    | |                 | |    | |
 *        | |    < |                 | |   |_/
 *        < |    /__\                <  \
 *        /__\                       /___\
 */
#include <stdio.h>

#define NUMBER 0b01010101

static int first_value = NUMBER;
static int value = NUMBER;

int main() {
        int number = value;

	while (1) {
                if (number != value) {
			printf("Cosmic bit flip happens");
			return 1;
                }
		if (number != first_value) { // in case of BOTH number AND value both flipping at the same time to the same value :O
                        printf("Other cosmic bit flip happens");
                        return 1;
		}
        }

	return 0;
}
