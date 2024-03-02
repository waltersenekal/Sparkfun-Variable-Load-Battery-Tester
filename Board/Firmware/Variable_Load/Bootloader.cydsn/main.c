#include "project.h"

void putString(const char *buffer);

int main(void)
{
    CyGlobalIntEnable;
    if (Bootloader_GET_RUN_TYPE == Bootloader_START_BTLDR)
    {
        Bootloader_Start();
    }
    else 
    {
        Bootloader_SET_RUN_TYPE(Bootloader_START_APP);
        CySoftwareReset();
    }
}
