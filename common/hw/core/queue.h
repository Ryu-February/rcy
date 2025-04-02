/*
 * queue.h
 *
 *  Created on: Apr 2, 2025
 *      Author: fbcks
 */

#ifndef SRC_COMMON_HW_CORE_QUEUE_H_
#define SRC_COMMON_HW_CORE_QUEUE_H_


#ifdef __cplusplus
extern "C"{
#endif


#include "def.h"

typedef struct
{
    uint32_t front;
    uint32_t rear;
    uint32_t size;

    uint8_t *p_buf;
}queue_t;


void     queueInit(void);
bool     queueCreate(queue_t *p_node, uint8_t *p_buf, uint32_t size);
bool     enqueue(queue_t *p_node, uint8_t *p_data, uint32_t size);
bool     dequeue(queue_t *p_node, uint8_t *p_data, uint32_t size);
uint32_t queueAvailable(queue_t *p_node);
void     queueFlush(queue_t *p_node);

#ifdef __cplusplus
}
#endif

#include "hw_def.h"


#endif /* SRC_COMMON_HW_CORE_QUEUE_H_ */
