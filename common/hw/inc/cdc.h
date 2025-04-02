/*
 * cdc.h
 *
 *  Created on: Apr 2, 2025
 *      Author: fbcks
 */

#ifndef SRC_COMMON_HW_INC_CDC_H_
#define SRC_COMMON_HW_INC_CDC_H_


#include "hw_def.h"

#ifdef _USE_HW_CDC


bool     cdcInit(void);
uint32_t cdcAvailable(void);
uint8_t  cdcDequeue(void);
void     cdcEnqueue(uint8_t rx_data);
uint32_t cdcWrite(uint8_t *p_data, uint32_t length);
uint32_t cdcGetBaud(void);


#endif

#endif /* SRC_COMMON_HW_INC_CDC_H_ */
