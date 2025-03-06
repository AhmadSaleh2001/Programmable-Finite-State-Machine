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

    insert_new_transition_table_entry(s1, "0", "1", s2);
    insert_new_transition_table_entry(s1, "1", "0", s3);

    insert_new_transition_table_entry(s2, "0", "!", s4);
    insert_new_transition_table_entry(s2, "1", "0", s3);

    insert_new_transition_table_entry(s3, "0", "1", s2);
    insert_new_transition_table_entry(s3, "1", "!", s4);

    insert_new_transition_table_entry(s4, "0", "!", s4);
    insert_new_transition_table_entry(s4, "1", "!", s4);

    bool result = 0;
    char fsm_output[MAX_TRANSITION_OUTPUT];
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result, fsm_output);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("fsm transition_output: %s\n", fsm_output);
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

    insert_new_transition_table_entry(s1, "0", "\0", s2);
    insert_new_transition_table_entry(s1, "1", "\0", s4);

    insert_new_transition_table_entry(s2, "0", "\0", s3);
    insert_new_transition_table_entry(s2, "1", "\0", s4);

    insert_new_transition_table_entry(s3, "0", "\0", s3);
    insert_new_transition_table_entry(s3, "1", "\0", s4);

    insert_new_transition_table_entry(s4, "0", "\0", s2);
    insert_new_transition_table_entry(s4, "1", "\0", s5);

    insert_new_transition_table_entry(s5, "0", "\0", s2);
    insert_new_transition_table_entry(s5, "1", "\0", s5);

    bool result = 0;
    char fsm_output[MAX_TRANSITION_OUTPUT];
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result, fsm_output);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("fsm transition_output: %s\n", fsm_output);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

void fsm_accept_at_the_end_aa_or_bb(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("accept any string ends with aa or bb");

    state_t * s1 = create_new_state("state 1", 0); // inital state
    state_t * s2 = create_new_state("state 2", 0); // when we have one a
    state_t * s3 = create_new_state("state 3", 1); // when we have two a's
    state_t * s4 = create_new_state("state 4", 0); // when we have one b
    state_t * s5 = create_new_state("state 5", 1); // when we have two b's

    set_state_as_initial_state(fsm, s1);

    insert_new_transition_table_entry(s1, "a", "0", s2);
    insert_new_transition_table_entry(s1, "b", "0", s4);

    insert_new_transition_table_entry(s2, "a", "1", s3);
    insert_new_transition_table_entry(s2, "b", "0", s4);

    insert_new_transition_table_entry(s3, "a", "1", s3);
    insert_new_transition_table_entry(s3, "b", "0", s4);

    insert_new_transition_table_entry(s4, "a", "0", s2);
    insert_new_transition_table_entry(s4, "b", "1", s5);

    insert_new_transition_table_entry(s5, "a", "0", s2);
    insert_new_transition_table_entry(s5, "b", "1", s5);

    bool result = 0;
    char fsm_output[MAX_TRANSITION_OUTPUT];
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result, fsm_output);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("fsm transition_output: %s\n", fsm_output);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

void accept_odd_number_of_ones(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("accept any string with odd number of ones");

    state_t * s1 = create_new_state("state 1", 0); // inital state, even number of ones
    state_t * s2 = create_new_state("state 2", 1); // odd number of ones

    set_state_as_initial_state(fsm, s1);

    insert_new_transition_table_entry(s1, "0", "", s1);
    insert_new_transition_table_entry(s1, "1", "", s2);

    insert_new_transition_table_entry(s2, "0", "", s2);
    insert_new_transition_table_entry(s2, "1", "", s1);


    bool result = 0;
    char fsm_output[MAX_TRANSITION_OUTPUT];
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result, fsm_output);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("fsm transition_output: %s\n", fsm_output);
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

    insert_new_transition_table_entry(s1, "(", "\0", s2);
    insert_new_transition_table_entry(s1, ")", "\0", s5);

    insert_new_transition_table_entry(s2, "(", "\0", s3);
    insert_new_transition_table_entry(s2, ")", "\0", s1);

    insert_new_transition_table_entry(s3, "(", "\0", s4);
    insert_new_transition_table_entry(s3, ")", "\0", s2);

    insert_new_transition_table_entry(s4, "(", "\0", s5);
    insert_new_transition_table_entry(s4, ")", "\0", s3);

    insert_new_transition_table_entry(s5, "(", "\0", s5);
    insert_new_transition_table_entry(s5, ")", "\0", s5);


    bool result = 0;
    char fsm_output[MAX_TRANSITION_OUTPUT];
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result, fsm_output);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("fsm transition_output: %s\n", fsm_output);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

void accept_phone_number_from_6_digits(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("accept phone number from 6 digits");

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
        for(int digit=0;digit<=9;digit++) {
            char transition_key[MAX_TRANSITION_INPUT - 1];
            snprintf(transition_key, sizeof(transition_key), "%d", digit);
            insert_new_transition_table_entry(states[state_number], transition_key, "\0", states[state_number + 1]);
        }
    }

    for(int digit=0;digit<=9;digit++) {
        char transition_key[MAX_TRANSITION_INPUT - 1];
        snprintf(transition_key, sizeof(transition_key), "%d", digit);
        insert_new_transition_table_entry(states[6], transition_key, "\0", states[7]);
        insert_new_transition_table_entry(states[7], transition_key, "\0", states[7]);
    }


    bool result = 0;
    char fsm_output[MAX_TRANSITION_OUTPUT];
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result, fsm_output);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("fsm transition_output: %s\n", fsm_output);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

void add_digits_letters(state_t * current_state, state_t * next_state) {
    for(int digit=0;digit<=9;digit++) {
        char transition_key[MAX_TRANSITION_INPUT - 1];
        snprintf(transition_key, sizeof(transition_key), "%d", digit);
        insert_new_transition_table_entry(current_state, transition_key, "\0", next_state);
    }

    for(char lower_case='a';lower_case<='z';lower_case++) {
        char transition_key[MAX_TRANSITION_INPUT - 1];
        snprintf(transition_key, sizeof(transition_key), "%c", lower_case);
        insert_new_transition_table_entry(current_state, transition_key, "\0", next_state);
    }

    for(char upper_case='A';upper_case<='Z';upper_case++) {
        char transition_key[MAX_TRANSITION_INPUT - 1];
        snprintf(transition_key, sizeof(transition_key), "%c", upper_case);
        insert_new_transition_table_entry(current_state, transition_key, "\0", next_state);
    }
}

void accept_valid_email_address(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("accept email valid address");
    // username@gmail.com or username@hotmail.com
    // username should be at least 5 chars
    // username should be formed from lower capital letters and digits (0 - 9)

    state_t * states[9];
    /*
        Rules:
        state0: valid empty string
        state1: we have 1 char from user name
        state2: we have 2 chars from user name
        state3: we have 3 chars from user name
        state4: we have 4 chars from user name
        state5: we have 5 chars from user name
        state6: we have at least 5 chars
            a. if we got some character, we will go to this state
        state7: @gmail.com or @hotmail.com => final state
        state8: invalid state
    */

    for(int i=0;i<9;i++) {
        char state_name[MAX_STATE_NAME_LENGTH - 1];
        snprintf(state_name, sizeof(state_name), "state %d", i + 1);
        states[i] = create_new_state(state_name, i == 7);
    }

    set_state_as_initial_state(fsm, states[0]);
    for(int state_number=0;state_number<6;state_number++) {
        add_digits_letters(states[state_number], states[state_number + 1]);
    }

    add_digits_letters(states[6], states[6]);

    char * gmail = "@gmail.com\0";
    insert_new_transition_table_entry(states[6], gmail, "\0", states[7]);

    char * hotmail = "@hotmail.com\0";
    insert_new_transition_table_entry(states[6], gmail, "\0", states[7]);

    bool result = 0;
    char fsm_output[MAX_TRANSITION_OUTPUT];
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result, fsm_output);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("fsm transition_output: %s\n", fsm_output);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

void reverse_string(char * input_buffer) {
    int l = 0, r = strlen(input_buffer) - 1;
    while(r > l) {
        char t = input_buffer[l];
        input_buffer[l] = input_buffer[r];
        input_buffer[r] = t;
        r--, l++;
    }
}

void accept_binary_string_and_output_twos_complement(char * input_buffer) {
    fsm_t * fsm = create_new_fsm("accept any binary string and output two's complement");

    // we need to reverse the input buffer to take LSB firstly while processing it
    reverse_string(input_buffer);

    state_t * s1 = create_new_state("state 1", 1); // inital state and we have +1
    state_t * s2 = create_new_state("state 2", 1); // we dont have 1

    set_state_as_initial_state(fsm, s1);

    insert_new_transition_table_entry(s1, "0", "0", s1);
    insert_new_transition_table_entry(s1, "1", "1", s2);

    insert_new_transition_table_entry(s2, "0", "1", s2);
    insert_new_transition_table_entry(s2, "1", "0", s2);

    bool result = 0;
    char fsm_output[MAX_TRANSITION_OUTPUT];
    fsm_error_t error = execute(fsm, input_buffer, strlen(input_buffer), &result, fsm_output);

    reverse_string(fsm_output);
    reverse_string(input_buffer);

    printf("\n-------\n");
    printf("----------- fsm name: %s ----------- \n", fsm->fsm_name);
    printf("result for input buffer: %s\n", input_buffer);
    printf("fsm transition_output: %s\n", fsm_output);
    printf("valid input: %d\n", result);
    printf("error code: %d\n", error);
    printf("\n-------\n");
}

int main() {

    alternate_binary_fsm("010101010101\0");
    alternate_binary_fsm("0100101111\0");

    fsm_accept_at_the_end_00_or_11("01010100\0");
    fsm_accept_at_the_end_00_or_11("000111010\0");
    fsm_accept_at_the_end_00_or_11("00ahmad0111010\0");

    fsm_accept_at_the_end_aa_or_bb("aababaabbbaaabbabababb\0");

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

    accept_valid_email_address("ahmadmfsaleh@gmail.com");
    accept_valid_email_address("ali@gmail.com");
    accept_valid_email_address("ali1@hotmail.com");
    accept_valid_email_address("ali123@yahoo.com");
    accept_valid_email_address("yousef12434343@gmail.com");
    accept_valid_email_address("ali123@hotmail.comahmad");
    accept_valid_email_address("abc");

    accept_binary_string_and_output_twos_complement(strdup("111111"));
    accept_binary_string_and_output_twos_complement(strdup("000000"));
    accept_binary_string_and_output_twos_complement(strdup("000101"));
    accept_binary_string_and_output_twos_complement(strdup("00010001"));

    return 0;
}