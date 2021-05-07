#include "module/console/console.h"

/**
 * @brief Implement _putchar, which will be used
 * by printf_ function
 * 
 * @param character 
 */
void _putchar(char character)
{
    console_write(&character, 1);
}