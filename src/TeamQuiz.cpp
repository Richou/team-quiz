#include <Arduino.h>
#include "TeamQuiz.h"

void TeamQuiz::setup() {
    Serial.begin(9600);
    pinMode(player_one_input_pin, INPUT);
    pinMode(player_one_output_pin, OUTPUT);
    pinMode(player_two_input_pin, INPUT);
    pinMode(player_two_output_pin, OUTPUT);
    pinMode(player_three_input_pin, INPUT);
    pinMode(player_three_output_pin, OUTPUT);
    pinMode(player_four_input_pin, INPUT);
    pinMode(player_four_output_pin, OUTPUT);
    pinMode(exit_init_mode_input_pin, INPUT);
}

void TeamQuiz::handle_quiz() {
    if (mode == Mode::INIT) {
        _init_quiz();
    } else {
        _start_quiz();
    }
}

void TeamQuiz::_init_quiz() {
    exit_init_mode_input = digitalRead(exit_init_mode_input_pin);
    if (exit_init_mode_input == HIGH) {
        Serial.println("Exiting init mode !");
        mode = Mode::QUESTION;
    }
}

void TeamQuiz::_start_quiz() {
    if (mode == Mode::QUESTION) {
        player_one_input = digitalRead(player_one_input_pin);
        player_two_input = digitalRead(player_two_input_pin);
        if (player_one_input == HIGH && player_two_input == LOW) {
            mode = Mode::ANSWER;
            winner = player_one_output_pin;
            Serial.println("player 1 wins");
        }
        if (player_two_input == HIGH && player_one_input == LOW) {
            mode = Mode::ANSWER;
            winner = player_two_output_pin;
            Serial.println("player 2 wins");
        }
    } else {
        player_one_input = LOW;
        player_one_input = LOW;
        if (winner != 0) {
            Serial.println("Setting winner HIGH");
            Serial.println(winner);
            digitalWrite(winner, HIGH);
        }
    }
}