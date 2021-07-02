#if defined _inc_cycle_main
    #undef _inc_cycle_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _cycle_main_included
    #endinput
#endif
#define _cycle_main_included

#include <cycle_functions>
#include <cycle_callbacks>