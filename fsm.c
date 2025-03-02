#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "fsm.h"

fsm_t * create_new_fsm(char * fsm_name) {
    fsm_t * fsm = malloc(sizeof(fsm_t));
    memcpy(fsm->fsm_name, fsm_name, MAX_FSM_NAME_LENGTH - 1);
    fsm->fsm_name[MAX_FSM_NAME_LENGTH - 1] = '\0';
    return fsm;
}


// States

state_t * create_new_state(char * state_name, bool is_final_state) {
    state_t * state = malloc(sizeof(state_t));
    memcpy(state->state_name, state_name, MAX_STATE_NAME_LENGTH - 1);   
    state->state_name[MAX_STATE_NAME_LENGTH - 1] = '\0';
    state->is_final_state = is_final_state;
    state->transition_table = malloc(sizeof(transition_table_t));

    return state;
}

void set_state_as_initial_state(fsm_t * fsm, state_t * state) {
    fsm->initial_state = state;
}

void insert_new_transition_table_entry(state_t * state, char * state_transition_key, uint8_t state_transition_key_size, state_t * next_state) {
    create_and_insert_new_transition_table_entry(state->transition_table, state_transition_key, state_transition_key_size, next_state);
}

bool is_same_transition_key(char * str, transition_table_entry_t * transition_table_entry) {
    return strcmp(str, transition_table_entry->state_transition_key) == 0;
}

transition_table_entry_t * transition_table_lookup(transition_table_t * transition_table, char * input_buffer, uint8_t buffer_input_cursor, uint8_t buffer_input_size) {

    int remaining = buffer_input_size - buffer_input_cursor;
    for(int i=0;i<MAX_NUMBER_OF_TRANSITION_ENTRIES && !is_transition_table_entry_empty(transition_table->transition_entries[i]);i++) {
        int transition_key_size = transition_table->transition_entries[i].state_transition_key_size;
        if(remaining < transition_key_size)continue;

        char * input_buffer_substring = malloc(sizeof(char));
        strncpy(input_buffer_substring, input_buffer + buffer_input_cursor, transition_key_size);
        if(is_same_transition_key(input_buffer_substring, &transition_table->transition_entries[i])) {
            return &transition_table->transition_entries[i];
        }
    }

    return NULL;
}

state_t * get_next_state(state_t * current_state, char * input_buffer, uint8_t * i, uint8_t buffer_input_size) {
    transition_table_entry_t * transition_table_entry = transition_table_lookup(current_state->transition_table, input_buffer, *i, buffer_input_size);
    if(!transition_table_entry)return NULL;
    (*i)+=transition_table_entry->state_transition_key_size;
    return transition_table_entry->next_state;
}

fsm_error_t execute(fsm_t * fsm, char * buffer_input, uint8_t size, bool * fsm_result) {
    assert(fsm->initial_state);

    state_t * state = fsm->initial_state;
    uint8_t i = 0;
    while(i < size && state) {
        state = get_next_state(state, buffer_input, &i, size);
    }
    if(state == NULL) {
        *fsm_result = 0;
        return FSM_NO_TRANSITION;
    }
    *fsm_result = state->is_final_state == true;
    return FSM_NO_ERROR;
}


// Transition table entries

bool is_transition_table_entry_empty(transition_table_entry_t transition_table_entry) {
    return transition_table_entry.next_state == NULL;
}

int get_first_empty_transition_table_entry(transition_table_t * transition_table) {
    for(int i=0;i<MAX_NUMBER_OF_TRANSITION_ENTRIES;i++) {
        if(is_transition_table_entry_empty(transition_table->transition_entries[i]))
            return i;
    }
    assert(0);
    return -1;
}

transition_table_entry_t * create_and_insert_new_transition_table_entry(
    transition_table_t * tt,
    char * state_transition_key,
    uint8_t state_transition_key_size,
    state_t * next_state
) {
    int first_empty_entry = get_first_empty_transition_table_entry(tt);
    assert(first_empty_entry != -1);
    memcpy(tt->transition_entries[first_empty_entry].state_transition_key, state_transition_key, MAX_TRANSITION_INPUT - 1);
    tt->transition_entries[first_empty_entry].state_transition_key[MAX_TRANSITION_INPUT - 1] = '\0';    
    tt->transition_entries[first_empty_entry].next_state = next_state;
    tt->transition_entries[first_empty_entry].state_transition_key_size = state_transition_key_size;

    return &tt->transition_entries[first_empty_entry];
}