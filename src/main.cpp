#include <Arduino.h>
#include "TeamQuiz.h"

TeamQuiz * teamQuiz;

void setup() {
    teamQuiz = new TeamQuiz();
    teamQuiz->setup();
}

void loop() {
    teamQuiz->handle_quiz();
}