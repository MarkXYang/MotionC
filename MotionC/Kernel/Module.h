#ifndef MODULE_H
#define MODULE_H

#include <string>
using std::string;

class Kernel;
class Module {
    public:
        Module();
        virtual void on_module_loaded();
        virtual void register_for_event(int event_id);
        virtual void on_main_loop(void * argument);
        virtual void on_console_line_received(  void * argument);
        virtual void on_gcode_received(         void * argument);
        virtual void on_gcode_execute(          void * argument);
        virtual void on_stepper_wake_up(        void * argument);
        virtual void on_speed_change(           void * argument);
        virtual void on_block_begin(            void * argument);
        virtual void on_block_end(              void * argument);
        virtual void on_config_reload(          void * argument);
        virtual void on_play(                   void * argument);
        virtual void on_pause(                  void * argument);
        virtual void on_idle(                   void * argument);
        Kernel * kernel;
};

#endif
