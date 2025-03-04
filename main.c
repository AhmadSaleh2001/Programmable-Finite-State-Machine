#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "fsm.h"

void alternate_binary_fsm(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("strict alternating binary number");

    state_t * s1 = create_new_state("state 1", 0); // inital state
    state_t * s2 = create_new_state("state 2", 1); // when we have zero
    state_t * s3 = create_new_state("state 3", 1); // when we have one
    state_t * s4 = create_new_state("state 4", 0); // invalid state

    set_state_as_initial_state(fsm, s1);

    insert_new_transition_table_entry(s1, "0", 1, s2);
    insert_new_transition_table_entry(s1, "1", 1, s3);

    insert_new_transition_table_entry(s2, "0", 1, s4);
    insert_new_transition_table_entry(s2, "1", 1, s3);

    insert_new_transition_table_entry(s3, "0", 1, s2);
    insert_new_transition_table_entry(s3, "1", 1, s4);

    insert_new_transition_table_entry(s4, "0", 1, s4);
    insert_new_transition_table_entry(s4, "1", 1, s4);

    bool result = 0;
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

void fsm_accept_at_the_end_00_or_11(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("accept any string ends with 00 or 11");

    state_t * s1 = create_new_state("state 1", 0); // inital state
    state_t * s2 = create_new_state("state 2", 0); // when we have one zero
    state_t * s3 = create_new_state("state 3", 1); // when we have two zeros
    state_t * s4 = create_new_state("state 4", 0); // when we have one one
    state_t * s5 = create_new_state("state 5", 1); // when we have two ones

    set_state_as_initial_state(fsm, s1);

    insert_new_transition_table_entry(s1, "0", 1, s2);
    insert_new_transition_table_entry(s1, "1", 1, s4);

    insert_new_transition_table_entry(s2, "0", 1, s3);
    insert_new_transition_table_entry(s2, "1", 1, s4);

    insert_new_transition_table_entry(s3, "0", 1, s3);
    insert_new_transition_table_entry(s3, "1", 1, s4);

    insert_new_transition_table_entry(s4, "0", 1, s2);
    insert_new_transition_table_entry(s4, "1", 1, s5);

    insert_new_transition_table_entry(s5, "0", 1, s2);
    insert_new_transition_table_entry(s5, "1", 1, s5);

    bool result = 0;
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

void accept_odd_number_of_ones(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("accept any string with odd number of ones");

    state_t * s1 = create_new_state("state 1", 0); // inital state, even number of ones
    state_t * s2 = create_new_state("state 2", 1); // odd number of ones

    set_state_as_initial_state(fsm, s1);

    insert_new_transition_table_entry(s1, "0", 1, s1);
    insert_new_transition_table_entry(s1, "1", 1, s2);

    insert_new_transition_table_entry(s2, "0", 1, s2);
    insert_new_transition_table_entry(s2, "1", 1, s1);


    bool result = 0;
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

void balanced_parenthesis_and_up_to_three_nested_levels(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("accept any string balanced parenthesis and up to three nested levels");

    state_t * s1 = create_new_state("state 1", 1); // valid empty string
    state_t * s2 = create_new_state("state 2", 0); // level 1
    state_t * s3 = create_new_state("state 3", 0); // level 2
    state_t * s4 = create_new_state("state 4", 0); // level 3
    state_t * s5 = create_new_state("state 5", 0); // invalid state

    set_state_as_initial_state(fsm, s1);

    insert_new_transition_table_entry(s1, "(", 1, s2);
    insert_new_transition_table_entry(s1, ")", 1, s5);

    insert_new_transition_table_entry(s2, "(", 1, s3);
    insert_new_transition_table_entry(s2, ")", 1, s1);

    insert_new_transition_table_entry(s3, "(", 1, s4);
    insert_new_transition_table_entry(s3, ")", 1, s2);

    insert_new_transition_table_entry(s4, "(", 1, s5);
    insert_new_transition_table_entry(s4, ")", 1, s3);


    insert_new_transition_table_entry(s5, "(", 1, s5);
    insert_new_transition_table_entry(s5, ")", 1, s5);


    bool result = 0;
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

void accept_phone_number_from_6_digits(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("accept any string with odd number of ones");

    state_t * states[8];
    /*
        Rules:
        state0: valid empty string
        state1: we have 1 digit
        state2: we have 2 digit
        state3: we have 3 digit
        state4: we have 4 digit
        state5: we have 5 digit
        state6: we have 6 digit
        state7: invalid state
    */

    for(int i=0;i<8;i++) {
        char state_name[MAX_STATE_NAME_LENGTH - 1];
        snprintf(state_name, sizeof(state_name), "state %d", i + 1);
        states[i] = create_new_state(state_name, i == 6);
    }

    set_state_as_initial_state(fsm, states[0]);
    for(int state_number=0;state_number<6;state_number++) {
        for(char digit=0;digit<=9;digit++) {
            char transition_key[MAX_TRANSITION_INPUT - 1];
            snprintf(transition_key, sizeof(transition_key), "%d", digit);
            insert_new_transition_table_entry(states[state_number], transition_key, 1, states[state_number + 1]);
        }
    }

    for(char digit=0;digit<=9;digit++) {
        char transition_key[MAX_TRANSITION_INPUT - 1];
        snprintf(transition_key, sizeof(transition_key), "%d", digit);
        insert_new_transition_table_entry(states[6], transition_key, 1, states[7]);
        insert_new_transition_table_entry(states[7], transition_key, 1, states[7]);
    }


    bool result = 0;
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

int main() {

    alternate_binary_fsm("010101010101\0");
    alternate_binary_fsm("0101011\0");

    fsm_accept_at_the_end_00_or_11("01010100\0");
    fsm_accept_at_the_end_00_or_11("000111010\0");
    fsm_accept_at_the_end_00_or_11("00ahmad0111010\0"); // invalid case

    accept_odd_number_of_ones("01100000001\0");
    accept_odd_number_of_ones("111\0");
    accept_odd_number_of_ones("01100001001\0");

    balanced_parenthesis_and_up_to_three_nested_levels("((()))\0");
    balanced_parenthesis_and_up_to_three_nested_levels("(((())))\0");
    balanced_parenthesis_and_up_to_three_nested_levels("(()\0");
    balanced_parenthesis_and_up_to_three_nested_levels("(())()()()\0");
    balanced_parenthesis_and_up_to_three_nested_levels("(())()()()(\0");
    balanced_parenthesis_and_up_to_three_nested_levels("(())()()())\0");


    accept_phone_number_from_6_digits("12356");
    accept_phone_number_from_6_digits("12ahmad0");
    accept_phone_number_from_6_digits("666123");

    return 0;
}