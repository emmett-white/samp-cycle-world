#if defined _inc_acc_callbacks
    #undef _inc_acc_callbacks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _acc_callbacks_included
    #endinput
#endif
#define _acc_callbacks_included

forward InsertAccountID(const playerid); public InsertAccountID(const playerid)
{
    acc_UniqueID[playerid] = cache_insert_id();
    return 1;
}

forward InsertCharacterID(const playerid); public InsertCharacterID(const playerid)
{
    char_UniqueID[playerid] = cache_insert_id();
    return 1;
}