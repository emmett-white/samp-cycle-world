#if defined _inc_ui_speedo
    #undef _inc_ui_speedo
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ui_speedo_included
    #endinput
#endif
#define _ui_speedo_included

#include <YSI_Coding\y_hooks>

static
    PlayerText: ui_Speedometer[MAX_PLAYERS][8],
    gPlayerCycleGear[MAX_PLAYERS];

stock UI_CreateSpeedoTextDraws(const playerid, bool: status = true)
{
    if (!status) {
        for (new i = 0; i < 8; ++i) {
            PlayerTextDrawDestroy(playerid, PlayerText: ui_Speedometer[playerid][i]);
        }

        return 1;
    }

    ui_Speedometer[playerid][0] = CreatePlayerTextDraw(playerid, 631.083496, 364.514434, "_");
    PlayerTextDrawLetterSize(playerid, ui_Speedometer[playerid][0], 0.243045, 1.314167);
    PlayerTextDrawTextSize(playerid, ui_Speedometer[playerid][0], 3577.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ui_Speedometer[playerid][0], 3);
    PlayerTextDrawColor(playerid, ui_Speedometer[playerid][0], -1);
    PlayerTextDrawSetShadow(playerid, ui_Speedometer[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ui_Speedometer[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_Speedometer[playerid][0], 255);
    PlayerTextDrawFont(playerid, ui_Speedometer[playerid][0], 2);
    PlayerTextDrawSetProportional(playerid, ui_Speedometer[playerid][0], 1);

    ui_Speedometer[playerid][1] = CreatePlayerTextDraw(playerid, 630.183715, 405.816955, "295KM/H");
    PlayerTextDrawLetterSize(playerid, ui_Speedometer[playerid][1], 0.256632, 2.095833);
    PlayerTextDrawTextSize(playerid, ui_Speedometer[playerid][1], 3577.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ui_Speedometer[playerid][1], 3);
    PlayerTextDrawColor(playerid, ui_Speedometer[playerid][1], -1);
    PlayerTextDrawSetShadow(playerid, ui_Speedometer[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ui_Speedometer[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_Speedometer[playerid][1], 255);
    PlayerTextDrawFont(playerid, ui_Speedometer[playerid][1], 2);
    PlayerTextDrawSetProportional(playerid, ui_Speedometer[playerid][1], 1);

    ui_Speedometer[playerid][2] = CreatePlayerTextDraw(playerid, 520.519104, 393.866485, "");
    PlayerTextDrawTextSize(playerid, ui_Speedometer[playerid][2], 72.000000, 67.000000);
    PlayerTextDrawAlignment(playerid, ui_Speedometer[playerid][2], 1);
    PlayerTextDrawColor(playerid, ui_Speedometer[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ui_Speedometer[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_Speedometer[playerid][2], 0x00000000);
    PlayerTextDrawFont(playerid, ui_Speedometer[playerid][2], 5);
    PlayerTextDrawSetProportional(playerid, ui_Speedometer[playerid][2], 0);
    PlayerTextDrawSetPreviewModel(playerid, ui_Speedometer[playerid][2], 18631);
    PlayerTextDrawSetPreviewRot(playerid, ui_Speedometer[playerid][2], -20.000000, 0.000000, -45.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, ui_Speedometer[playerid][2], 1, 1);

    ui_Speedometer[playerid][3] = CreatePlayerTextDraw(playerid, 631.083496, 376.915191, "GORIVO:11l");
    PlayerTextDrawLetterSize(playerid, ui_Speedometer[playerid][3], 0.243045, 1.314167);
    PlayerTextDrawTextSize(playerid, ui_Speedometer[playerid][3], 3577.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ui_Speedometer[playerid][3], 3);
    PlayerTextDrawColor(playerid, ui_Speedometer[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, ui_Speedometer[playerid][3], 0);
    PlayerTextDrawSetOutline(playerid, ui_Speedometer[playerid][3], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_Speedometer[playerid][3], 255);
    PlayerTextDrawFont(playerid, ui_Speedometer[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, ui_Speedometer[playerid][3], 1);

    ui_Speedometer[playerid][4] = CreatePlayerTextDraw(playerid, 615.922302, 389.500061, "LD_BEAT:CHIT");
    PlayerTextDrawTextSize(playerid, ui_Speedometer[playerid][4], 13.000000, 16.000000);
    PlayerTextDrawAlignment(playerid, ui_Speedometer[playerid][4], 1);
    PlayerTextDrawColor(playerid, ui_Speedometer[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, ui_Speedometer[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_Speedometer[playerid][4], 255);
    PlayerTextDrawFont(playerid, ui_Speedometer[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, ui_Speedometer[playerid][4], 0);

    ui_Speedometer[playerid][5] = CreatePlayerTextDraw(playerid, 616.822082, 390.300109, "LD_BEAT:CHIT");
    PlayerTextDrawTextSize(playerid, ui_Speedometer[playerid][5], 11.190004, 14.000000);
    PlayerTextDrawAlignment(playerid, ui_Speedometer[playerid][5], 1);
    PlayerTextDrawColor(playerid, ui_Speedometer[playerid][5], 16711935);
    PlayerTextDrawSetShadow(playerid, ui_Speedometer[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_Speedometer[playerid][5], 255);
    PlayerTextDrawFont(playerid, ui_Speedometer[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, ui_Speedometer[playerid][5], 0);

    ui_Speedometer[playerid][6] = CreatePlayerTextDraw(playerid, 594.013671, 391.716613, "~w~123456");
    PlayerTextDrawLetterSize(playerid, ui_Speedometer[playerid][6], 0.231332, 1.115833);
    PlayerTextDrawTextSize(playerid, ui_Speedometer[playerid][6], 0.000000, 168.000000);
    PlayerTextDrawAlignment(playerid, ui_Speedometer[playerid][6], 2);
    PlayerTextDrawColor(playerid, ui_Speedometer[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ui_Speedometer[playerid][6], 0);
    PlayerTextDrawSetOutline(playerid, ui_Speedometer[playerid][6], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_Speedometer[playerid][6], 255);
    PlayerTextDrawFont(playerid, ui_Speedometer[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, ui_Speedometer[playerid][6], 1);

    ui_Speedometer[playerid][7] = CreatePlayerTextDraw(playerid, 622.413146, 392.350006, "N");
    PlayerTextDrawLetterSize(playerid, ui_Speedometer[playerid][7], 0.219150, 0.975832);
    PlayerTextDrawAlignment(playerid, ui_Speedometer[playerid][7], 2);
    PlayerTextDrawColor(playerid, ui_Speedometer[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ui_Speedometer[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_Speedometer[playerid][7], 255);
    PlayerTextDrawFont(playerid, ui_Speedometer[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, ui_Speedometer[playerid][7], 1);

    for (new i = 0; i < 8; ++i) {
        PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][i]);
    }

    return 1;
}

stock Speedo_SetPlayerGear(const playerid, const gear = 0)
{
    gPlayerCycleGear[playerid] = gear;

    static tmpvehid;
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cycles WHERE cycle_owner = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    for (new i; i < cache_num_rows(); ++i) {
        cache_get_value_name_int(i, "cycle_vehid", tmpvehid);
    }

    switch (gear) {
        case 0: {
            PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][4]);
            PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][5]);
            PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][7]);
            PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~123456");
        }

        case 1: {
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][4]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][5]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][7]);
            PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~b~1~w~23456");
        }

        case 2: {
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][4]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][5]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][7]);
            PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~1~b~2~w~3456");
        }

        case 3: {
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][4]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][5]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][7]);
            PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~12~b~3~w~456");
        }

        case 4: {
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][4]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][5]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][7]);
            PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~123~b~4~w~56");
        }

        case 5: {
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][4]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][5]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][7]);
            PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~1234~b~5~w~6");
        }

        case 6: {
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][4]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][5]);
            PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][7]);
            PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~12345~b~6");
        }
    }

    return 1;
}

stock Speedo_GetPlayerGear(const playerid) return gPlayerCycleGear[playerid];
stock Speedo_GetCycleSpeed(vehicleid)
{
    static
        pos_y,
        pos_x,
        pos_z,
        Float: veh_speed;

    GetVehicleVelocity(vehicleid, Float: pos_x, Float: pos_y, Float: pos_z);
    veh_speed = (floatsqroot((Float: pos_x * Float: pos_x) + (Float: pos_y * Float: pos_y) + (Float: pos_z * Float: pos_z)) * 200);
    
    return floatround(Float: veh_speed, floatround_round);
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    static tmpvehid;
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cycles WHERE cycle_owner = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    for (new i; i < cache_num_rows(); ++i) {
        cache_get_value_name_int(i, "cycle_vehid", tmpvehid);
    }

    if (newstate == PLAYER_STATE_DRIVER) {
        UI_CreateSpeedoTextDraws(playerid);
        Speedo_SetPlayerGear(playerid);

        switch (tmpvehid) {
            case 481: {
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][0], "BMX");
                PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_Speedometer[playerid][2], 481);
                PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][2]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][1]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][3]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][4]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][5]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][6]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][7]);
            }
            
            case 509: {
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][0], "OLD BIKE");
                PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_Speedometer[playerid][2], 509);
                PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][2]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][1]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][3]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][4]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][5]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][6]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][7]);
            }
            
            case 510: {
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][0], "BOOSTER GALAXY FS DISC");
                PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_Speedometer[playerid][2], 510);
                PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][2]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][1]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][3]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][4]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][5]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][6]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][7]);
            }
            
            case 462: {
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][0], "PIAGGIO LIBERTY");
                PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_Speedometer[playerid][2], 462);
                PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][2]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][4]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][5]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][6]);
                PlayerTextDrawHide(playerid, PlayerText: ui_Speedometer[playerid][7]);
            }
            
            case 586: {
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][0], "HONDA SHADOW");
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~123456");
                PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_Speedometer[playerid][2], 586);
                PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][2]);
            }
            
            case 463: {
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][0], "KAWASAKI VN CLASIC");
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~123456");
                PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_Speedometer[playerid][2], 463);
                PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][2]);
            }
            
            case 468: {
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][0], "SUZUKI RM");
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~123456");
                PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_Speedometer[playerid][2], 468);
                PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][2]);
            }
            
            case 461: {
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][0], "HONDA CBR");
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~123456");
                PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_Speedometer[playerid][2], 461);
                PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][2]);
            }
            
            case 521: {
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][0], "YAMAHA YZF-R125");
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~123456");
                PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_Speedometer[playerid][2], 521);
                PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][2]);
            }
            
            case 581: {
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][0], "HONDA HORNET");
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~123456");
                PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_Speedometer[playerid][2], 581);
                PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][2]);
            }
            
            case 522: {
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][0], "YAMAHA YZF R6");
                PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][6], "~w~123456");
                PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_Speedometer[playerid][2], 522);
                PlayerTextDrawShow(playerid, PlayerText: ui_Speedometer[playerid][2]);
            }
        }
    }

    else if (newstate == PLAYER_STATE_ONFOOT) {
        UI_CreateSpeedoTextDraws(playerid, false);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

// Update gears
ptask Speedo_UpdateSpeedo[1](playerid)
{
    va_PlayerTextDrawSetString(playerid, PlayerText: ui_Speedometer[playerid][1], "%dkm/h", Speedo_GetCycleSpeed(GetPlayerVehicleID(playerid)));

    switch (Speedo_GetCycleSpeed(GetPlayerVehicleID(playerid))) {
        case 0: return Speedo_SetPlayerGear(playerid);
        case 1..30: return Speedo_SetPlayerGear(playerid, 1);
        case 40..60: return Speedo_SetPlayerGear(playerid, 2);
        case 70..100: return Speedo_SetPlayerGear(playerid, 3);
        case 110..150: return Speedo_SetPlayerGear(playerid, 4);
        case 160..175: return Speedo_SetPlayerGear(playerid, 5);
        case 185..220: return Speedo_SetPlayerGear(playerid, 6);
    }

    return 1;
}