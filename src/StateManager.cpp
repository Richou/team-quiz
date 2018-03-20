#include "StateManager.h"

bool StateManager::isInitMode() {
    return mode == Mode::INIT;
}

void StateManager::setAnswerState() {
    mode = Mode::ANSWER;
}

void StateManager::setInitState() {
    mode = Mode::INIT;
}

bool StateManager::isQuizState() {
    return mode == Mode::QUESTION;
}

void StateManager::setQuizState() {
    mode = Mode::QUESTION;
}