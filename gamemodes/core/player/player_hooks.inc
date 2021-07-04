#if defined _inc_player_hooks
    #undef _inc_player_hooks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _player_hooks_included
    #endinput
#endif
#define _player_hooks_included

#include <YSI_Coding\y_hooks>

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_SECONDARY_ATTACK)) {
        if (IsPlayerInRangeOfPoint(playerid, Float: 1.5, Float: 1377.5708, Float: -1894.0348, Float: 13.5033)) {
            Streamer_UpdateEx(playerid, Float: 1377.6525, Float: -1890.6141, Float: 13.4739, .compensatedtime = 1500);
        }
        
        else if (IsPlayerInRangeOfPoint(playerid, Float: 1.5, Float: 1377.6525, Float: -1890.6141, Float: 13.4739)) {
            Streamer_UpdateEx(playerid, Float: 1377.5708, Float: -1894.0348, Float: 13.5033, .compensatedtime = 1500);
        }
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}