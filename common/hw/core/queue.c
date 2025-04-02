/*
 * queue.c
 *
 *  Created on: Apr 2, 2025
 *      Author: fbcks
 */


#include "queue.h"





void queueInit(void)
{

}

bool queueCreate(queue_t *p_node, uint8_t *p_buf, uint32_t size)
{
    bool ret = true;

    p_node->front = 0;
    p_node->rear  = 0;
    p_node->size  = size;
    p_node->p_buf = p_buf;

    return ret;
}

bool enqueue(queue_t *p_node, uint8_t *p_data, uint32_t size)
{
    bool ret = true;
    uint32_t next_rear;

    for(int i = 0; i < size; i++)
    {
        next_rear = (p_node->rear + 1) % p_node->size;

        if(next_rear != p_node->front)//if front is same rear -> buffer full
        {
            if(p_node->p_buf != NULL)
            {
                p_node->p_buf[p_node->rear] = p_data[i];
            }
            p_node->rear = next_rear;
        }
        else
        {
            ret = false;
            break;
        }
    }

    return ret;


}

bool dequeue(queue_t *p_node, uint8_t *p_data, uint32_t size)
{
    bool ret = true;

    for(int i = 0; i < size; i++)
    {
        if(p_node->p_buf != NULL)
        {
            p_data[i] = p_node->p_buf[p_node->front];
        }

        if(p_node->front != p_node->rear)
        {
            p_node->front = (p_node->front + 1) % p_node->size;
        }
        else
        {
            ret = false;
        }
    }

    return ret;
}

uint32_t queueAvailable(queue_t *p_node)
{
    uint32_t ret;

    ret = (p_node->front - p_node->rear) % p_node->size;

    return ret;

}

void queueFlush(queue_t *p_node)
{
    p_node->front = 0;
    p_node->rear = 0;

}

