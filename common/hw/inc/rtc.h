/*
 * rtc.h
 *
 *  Created on: Apr 1, 2025
 *      Author: fbcks
 */

#ifndef SRC_COMMON_HW_INC_RTC_H_
#define SRC_COMMON_HW_INC_RTC_H_

#include "hw_def.h"


#ifdef _USE_HW_RTC

bool rtcInit(void);

uint32_t rtcBackupRegRead(uint32_t index);
void rtcBackupRegWrite(uint32_t index, uint32_t data);


#endif

#endif /* SRC_COMMON_HW_INC_RTC_H_ */
