#include "main.h"

/**
 * _write_binary - Write an unsigned integer in binary format
 * @num: The unsigned integer to convert to binary
 * @count: Pointer to the character count
 */
void _write_binary(unsigned int num, int *count)
{
    if (num == 0)
    {
        _write_char('0', count);
        return;
    }

    int binary[32]; // Assuming 32-bit integer
    int i = 0;

    while (num > 0)
    {
        binary[i] = num % 2;
        num /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        _write_char(binary[j] + '0', count);
    }
}

