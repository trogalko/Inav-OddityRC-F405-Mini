/*
 * This file is part of INAV.
 *
 * INAV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INAV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INAV.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>

#include "platform.h"

#include "fc/fc_msp_box.h"

#include "io/piniobox.h"
#include "io/serial.h"

void targetConfiguration(void)
{
    // UART1 - Default serial RX (CRSF/ELRS)
    serialConfigMutable()->portConfigs[findSerialPortIndexByIdentifier(SERIAL_PORT_USART1)].functionMask = FUNCTION_RX_SERIAL;

    // UART5 - ESC telemetry
    serialConfigMutable()->portConfigs[findSerialPortIndexByIdentifier(SERIAL_PORT_USART5)].functionMask = FUNCTION_ESCSERIAL;

    // PINIO1 (PA4) - 9V BEC control via ARM box
    pinioBoxConfigMutable()->permanentId[0] = BOXARM;
}
