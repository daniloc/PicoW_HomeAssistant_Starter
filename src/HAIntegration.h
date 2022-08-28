#ifndef SRC_HAINTEGRATION
#define SRC_HAINTEGRATION

#include <ArduinoHA.h>

class HAIntegration {
    public:
    void loop();
    void configure();
    static void switchHandler(bool state, HASwitch* sender);
};

#endif // SRC_HAINTEGRATION
