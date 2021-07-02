#if defined _inc_cycle_callbacks
    #undef _inc_cycle_callbacks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _cycle_callbacks_included
    #endinput
#endif
#define _cycle_callbacks_included

forward InsertCycleID(const id); public InsertCycleID(const id)
{
    Cycle_GetUniqueID(id) = cache_insert_id();
    return 1;
}