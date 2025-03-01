#pragma once
#include <inttypes.h>
#include "state.h"

#define MAX_FSM_NAME_LENGTH 255
#define MAX_INPUT_FROM_USER 127

typedef struct fsm
{
    char fsm_name[MAX_FSM_NAME_LENGTH];

    char input_buffer[MAX_INPUT_FROM_USER]; // Input provided to FSM
    u_int8_t input_buffer_size; // Size of input provided to FSM
    u_int8_t input_buffer_cursor; // Index for processed input

    state_t * initial_state;

} fsm_t;


fsm_t * create_new_fsm(char * fsm_name);