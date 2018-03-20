#include <Arduino.h>
#include "StateManager.h"

class TeamQuiz {
    public:
        void setup();
        void handle_quiz();
    private:
        const int player_one_input_pin = 2;
        const int player_one_output_pin = 3;
        int player_one_input = LOW;
        const int player_two_input_pin = 4;
        const int player_two_output_pin = 5;
        int player_two_input = LOW;
        const int player_three_input_pin = 6;
        const int player_three_output_pin = 7;
        int player_three_input = LOW;
        const int player_four_input_pin = 8;
        const int player_four_output_pin = 9;
        int player_four_input = LOW;
        const int exit_init_mode_input_pin = 10;
        int exit_init_mode_input = LOW;
        int winner = 0;

        void _init_quiz();
        void _start_quiz();

        StateManager * stateMgr;
};