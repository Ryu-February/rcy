/*
 * reset.h
 *
 *  Created on: Apr 1, 2025
 *      Author: fbcks
 */

#ifndef SRC_COMMON_HW_INC_RESET_H_
#define SRC_COMMON_HW_INC_RESET_H_

#include "hw_def.h"

#ifdef _USE_HW_RESET

bool resetInit(void);
bool rcyResetInit(void);

bool isRcyResetPinRead(/*unsigned char is_pin_valid*/void);

uint32_t resetGetCount(void);

#endif

#endif /* SRC_COMMON_HW_INC_RESET_H_ */
