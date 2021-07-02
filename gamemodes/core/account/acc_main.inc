#if defined _inc_acc_main
    #undef _inc_acc_main
#endif
// custom include-guard to ensure we don't duplicate
#if defined _acc_main_included
    #endinput
#endif
#define _acc_main_included

#include <acc_variables>
#include <acc_functions>
#include <acc_hooks>
#include <acc_callbacks>