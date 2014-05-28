#include "Module.h"
#include "Kernel.h"

Module::Module(){ }

void Module::on_module_loaded(){
}

void Module::register_for_event(int event_id){
    this->kernel->register_for_event(event_id, this);
}

void Module::on_main_loop(             void * argument){}
void Module::on_console_line_received( void * argument){}
void Module::on_gcode_received(        void * argument){}
void Module::on_stepper_wake_up(       void * argument){}
void Module::on_gcode_execute(         void * argument){}
void Module::on_speed_change(          void * argument){}
void Module::on_block_begin(           void * argument){}
void Module::on_block_end(             void * argument){}
void Module::on_config_reload(         void * argument){}
void Module::on_play(                  void * argument){}
void Module::on_pause(                 void * argument){}
void Module::on_idle(                  void * argument){}

