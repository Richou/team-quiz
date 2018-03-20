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
    stateMgr = new StateManager();
}

void TeamQuiz::handle_quiz() {
    if (stateMgr->isInitMode()) {
        _init_quiz();
    } else {
        _start_quiz();
    }
}

void TeamQuiz::_init_quiz() {
    exit_init_mode_input = digitalRead(exit_init_mode_input_pin);
    if (exit_init_mode_input == HIGH) {
        Serial.println("Exiting init mode !");
        stateMgr->setQuizState();
    }
}

void TeamQuiz::_start_quiz() {
    if (stateMgr->isQuizState()) {
        player_one_input = digitalRead(player_one_input_pin);
        player_two_input = digitalRead(player_two_input_pin);
        if (player_one_input == HIGH && player_two_input == LOW && player_three_input == LOW && player_four_input == LOW) {
            winner = player_one_output_pin;
            Serial.println("player 1 wins");
            stateMgr->setAnswerState();
        }
        if (player_two_input == HIGH && player_one_input == LOW && player_three_input == LOW && player_four_input == LOW) {
            winner = player_two_output_pin;
            Serial.println("player 2 wins");
            stateMgr->setAnswerState();
        }
        if (player_two_input == LOW && player_one_input == LOW && player_three_input == HIGH && player_four_input == LOW) {
            winner = player_three_input;
            Serial.println("player 3 wins");
            stateMgr->setAnswerState();
        }
        if (player_two_input == LOW && player_one_input == LOW && player_three_input == LOW && player_four_input == HIGH) {
            winner = player_four_input;
            Serial.println("player 4 wins");
            stateMgr->setAnswerState();
        }
    } else {
        player_one_input = LOW;
        player_two_input = LOW;
        player_three_input = LOW;
        player_four_input = LOW;
        if (winner != 0) digitalWrite(winner, HIGH);
    }
}