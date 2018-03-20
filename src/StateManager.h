#include "Mode.h"

class StateManager {
    private:
        Mode mode = Mode::INIT;
    public:
        bool isInitMode();
        void setInitState();
        bool isQuizState();
        void setQuizState();
        void setAnswerState();
};