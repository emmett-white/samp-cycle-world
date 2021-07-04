#if defined _inc_ui_functions
    #undef _inc_ui_functions
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ui_functions_included
    #endinput
#endif
#define _ui_functions_included

#include <YSI_Coding\y_hooks>

#if defined MAX_PAGES
    #undef
#else
    const MAX_PAGES = 11;
#endif

static
    PlayerText: ui_BuyTextDraws[MAX_PLAYERS][10],
    gPlayerMenuPage[MAX_PLAYERS],
    gPlayerMenuPrice[MAX_PLAYERS];

stock UI_CreateBuyTextDraws(const playerid, const bool: status = true)
{
    if (!status) {
        for (new i = 0; i < 10; ++i) {
            PlayerTextDrawDestroy(playerid, PlayerText: ui_BuyTextDraws[playerid][i]);
        }

        return 1;
    }

    ui_BuyTextDraws[playerid][0] = CreatePlayerTextDraw(playerid, 267.911224, 104.966682, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_BuyTextDraws[playerid][0], 97.939773, 224.379791);
    PlayerTextDrawAlignment(playerid, ui_BuyTextDraws[playerid][0], 1);
    PlayerTextDrawColor(playerid, ui_BuyTextDraws[playerid][0], 255);
    PlayerTextDrawSetShadow(playerid, ui_BuyTextDraws[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_BuyTextDraws[playerid][0], 255);
    PlayerTextDrawFont(playerid, ui_BuyTextDraws[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, ui_BuyTextDraws[playerid][0], 0);

    ui_BuyTextDraws[playerid][1] = CreatePlayerTextDraw(playerid, 268.611328, 105.933357, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_BuyTextDraws[playerid][1], 98.000000, 224.000000);
    PlayerTextDrawAlignment(playerid, ui_BuyTextDraws[playerid][1], 1);
    PlayerTextDrawColor(playerid, ui_BuyTextDraws[playerid][1], -308521985);
    PlayerTextDrawSetShadow(playerid, ui_BuyTextDraws[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_BuyTextDraws[playerid][1], 255);
    PlayerTextDrawFont(playerid, ui_BuyTextDraws[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, ui_BuyTextDraws[playerid][1], 0);

    ui_BuyTextDraws[playerid][2] = CreatePlayerTextDraw(playerid, 289.794952, 307.983520, "LD_BEAT:LEFT");
    PlayerTextDrawTextSize(playerid, ui_BuyTextDraws[playerid][2], 16.000000, 19.000000);
    PlayerTextDrawAlignment(playerid, ui_BuyTextDraws[playerid][2], 1);
    PlayerTextDrawColor(playerid, ui_BuyTextDraws[playerid][2], 255);
    PlayerTextDrawSetShadow(playerid, ui_BuyTextDraws[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_BuyTextDraws[playerid][2], 255);
    PlayerTextDrawFont(playerid, ui_BuyTextDraws[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, ui_BuyTextDraws[playerid][2], 0);
    PlayerTextDrawSetSelectable(playerid, ui_BuyTextDraws[playerid][2], true);

    ui_BuyTextDraws[playerid][3] = CreatePlayerTextDraw(playerid, 328.597320, 308.583557, "LD_BEAT:RIGHT");
    PlayerTextDrawTextSize(playerid, ui_BuyTextDraws[playerid][3], 16.000000, 19.000000);
    PlayerTextDrawAlignment(playerid, ui_BuyTextDraws[playerid][3], 1);
    PlayerTextDrawColor(playerid, ui_BuyTextDraws[playerid][3], 255);
    PlayerTextDrawSetShadow(playerid, ui_BuyTextDraws[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_BuyTextDraws[playerid][3], 255);
    PlayerTextDrawFont(playerid, ui_BuyTextDraws[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, ui_BuyTextDraws[playerid][3], 0);
    PlayerTextDrawSetSelectable(playerid, ui_BuyTextDraws[playerid][3], true);

    ui_BuyTextDraws[playerid][4] = CreatePlayerTextDraw(playerid, 248.133102, 95.183738, "");
    PlayerTextDrawTextSize(playerid, ui_BuyTextDraws[playerid][4], 147.000000, 171.000000);
    PlayerTextDrawAlignment(playerid, ui_BuyTextDraws[playerid][4], 1);
    PlayerTextDrawColor(playerid, ui_BuyTextDraws[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ui_BuyTextDraws[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_BuyTextDraws[playerid][4], 0x00000000);
    PlayerTextDrawFont(playerid, ui_BuyTextDraws[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, ui_BuyTextDraws[playerid][4], 0);
    PlayerTextDrawSetPreviewModel(playerid, ui_BuyTextDraws[playerid][4], 18631);
    PlayerTextDrawSetPreviewRot(playerid, ui_BuyTextDraws[playerid][4], -10.000000, 0.000000, -45.000000, 1.000000);
    PlayerTextDrawSetPreviewVehCol(playerid, ui_BuyTextDraws[playerid][4], 1, 1);

    ui_BuyTextDraws[playerid][5] = CreatePlayerTextDraw(playerid, 317.979919, 110.500030, "_");
    PlayerTextDrawLetterSize(playerid, ui_BuyTextDraws[playerid][5], 0.147466, 1.057499);
    PlayerTextDrawAlignment(playerid, ui_BuyTextDraws[playerid][5], 2);
    PlayerTextDrawColor(playerid, ui_BuyTextDraws[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, ui_BuyTextDraws[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_BuyTextDraws[playerid][5], 255);
    PlayerTextDrawFont(playerid, ui_BuyTextDraws[playerid][5], 2);
    PlayerTextDrawSetProportional(playerid, ui_BuyTextDraws[playerid][5], 1);

    ui_BuyTextDraws[playerid][6] = CreatePlayerTextDraw(playerid, 317.511230, 228.615341, "_");
    PlayerTextDrawLetterSize(playerid, ui_BuyTextDraws[playerid][6], 0.153088, 0.935000);
    PlayerTextDrawTextSize(playerid, ui_BuyTextDraws[playerid][6], 0.000000, 345.000000);
    PlayerTextDrawAlignment(playerid, ui_BuyTextDraws[playerid][6], 2);
    PlayerTextDrawColor(playerid, ui_BuyTextDraws[playerid][6], 255);
    PlayerTextDrawSetShadow(playerid, ui_BuyTextDraws[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_BuyTextDraws[playerid][6], 255);
    PlayerTextDrawFont(playerid, ui_BuyTextDraws[playerid][6], 2);
    PlayerTextDrawSetProportional(playerid, ui_BuyTextDraws[playerid][6], 1);

    ui_BuyTextDraws[playerid][7] = CreatePlayerTextDraw(playerid, 286.983551, 278.033172, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_BuyTextDraws[playerid][7], 61.000000, 18.000000);
    PlayerTextDrawAlignment(playerid, ui_BuyTextDraws[playerid][7], 1);
    PlayerTextDrawColor(playerid, ui_BuyTextDraws[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, ui_BuyTextDraws[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_BuyTextDraws[playerid][7], 255);
    PlayerTextDrawFont(playerid, ui_BuyTextDraws[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, ui_BuyTextDraws[playerid][7], 0);

    ui_BuyTextDraws[playerid][8] = CreatePlayerTextDraw(playerid, 316.268615, 280.866790, "KUPI");
    PlayerTextDrawTextSize(playerid, ui_BuyTextDraws[playerid][8], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, ui_BuyTextDraws[playerid][8], 0.256163, 1.133333);
    PlayerTextDrawAlignment(playerid, ui_BuyTextDraws[playerid][8], 2);
    PlayerTextDrawColor(playerid, ui_BuyTextDraws[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ui_BuyTextDraws[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_BuyTextDraws[playerid][8], 255);
    PlayerTextDrawFont(playerid, ui_BuyTextDraws[playerid][8], 2);
    PlayerTextDrawSetProportional(playerid, ui_BuyTextDraws[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, ui_BuyTextDraws[playerid][8], true);

    ui_BuyTextDraws[playerid][9] = CreatePlayerTextDraw(playerid, 360.578186, 106.583335, "X");
    PlayerTextDrawLetterSize(playerid, ui_BuyTextDraws[playerid][9], 0.244450, 1.320000);
    PlayerTextDrawTextSize(playerid, ui_BuyTextDraws[playerid][9], 8.0, 20.0);
    PlayerTextDrawAlignment(playerid, ui_BuyTextDraws[playerid][9], 2);
    PlayerTextDrawColor(playerid, ui_BuyTextDraws[playerid][9], 255);
    PlayerTextDrawSetShadow(playerid, ui_BuyTextDraws[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_BuyTextDraws[playerid][9], 255);
    PlayerTextDrawFont(playerid, ui_BuyTextDraws[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, ui_BuyTextDraws[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, ui_BuyTextDraws[playerid][9], true);
    
    for (new i = 0; i < 10; ++i) {
        PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][i]);
    }

    return 1;
}

stock Cycle_SetMenuPage(const playerid, const pageid)
{
    switch (pageid) {
        case 0: {
            PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_BuyTextDraws[playerid][4], 481);
            PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][4]);
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][5], "BMX");
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][6],
                "TIP: BICIKL~n~STANJE: NOVO~n~CENA: $110"
            );

            gPlayerMenuPrice[playerid] = 110;
        }
        
        case 1: {
            PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_BuyTextDraws[playerid][4], 509);
            PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][4]);

            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][5], "OLD BIKE");
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][6],
                "VRSTA: BICIKL~n~STANJE: NOVO~n~CENA: $70"
            );

            gPlayerMenuPrice[playerid] = 70;
        }
        
        case 2: {
            PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_BuyTextDraws[playerid][4], 510);
            PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][4]);

            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][5], "BOOSTER GALAXY FS DISC");
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][6],
                "TIP: BICIKL~n~STANJE: NOVO~n~CENA: $210"
            );

            gPlayerMenuPrice[playerid] = 210;
        }
        
        case 3: {
            PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_BuyTextDraws[playerid][4], 462);
            PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][4]);

            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][5], "PIAGGIO LIBERTY");
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][6],
                "TIP: SCOOTER~n~ZAPREMINA: 50ccm~n~STANJE: NOVO~n~KW/KS: 2/3~n~CENA: $450"
            );

            gPlayerMenuPrice[playerid] = 450;
        }
        
        case 4: {
            PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_BuyTextDraws[playerid][4], 586);
            PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][4]);

            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][5], "HONDA SHADOW");
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][6],
                "TIP: CHOPPER / CRUISER~n~ZAPREMINA: 125ccm~n~STANJE: NOVO~n~KW/KS: 11/15~n~CENA: $1000"
            );

            gPlayerMenuPrice[playerid] = 1000;
        }
        
        case 5: {
            PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_BuyTextDraws[playerid][4], 463);
            PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][4]);

            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][5], "KAWASAKI VN CLASIC");
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][6],
                "TIP: CHOPPER / CRUISER~n~ZAPREMINA: 1500ccm~n~STANJE: NOVO~n~KW/KS: 35/48~n~CENA: $4000"
            );

            gPlayerMenuPrice[playerid] = 4000;
        }
        
        case 6: {
            PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_BuyTextDraws[playerid][4], 468);
            PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][4]);

            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][5], "SUZUKI RM");
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][6],
                "TIP: ENDURO / CROSS~n~ZAPREMINA: 125ccm~n~STANJE: NOVO~n~KW/KS: 55/75~n~CENA: $2100"
            );

            gPlayerMenuPrice[playerid] = 2100;
        }
        
        case 7: {
            PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_BuyTextDraws[playerid][4], 461);
            PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][4]);

            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][5], "HONDA CBR");
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][6],
                "TIP: SPORT / SUPER SPORT~n~ZAPREMINA: 125ccm~n~STANJE: NOVO~n~KW/KS: 9/12~n~CENA: $2600"
            );

            gPlayerMenuPrice[playerid] = 2600;
        }
        
        case 8: {
            PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_BuyTextDraws[playerid][4], 521);
            PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][4]);

            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][5], "YAMAHA YZF-R125");
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][6],
                "TIP: SPORT / SUPER SPORT~n~ZAPREMINA: 125ccm~n~STANJE: NOVO~n~KW/KS: 11/15~n~CENA: $3500"
            );

            gPlayerMenuPrice[playerid] = 3500;
        }
        
        case 9: {
            PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_BuyTextDraws[playerid][4], 581);
            PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][4]);

            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][5], "HONDA HORNET");
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][6],
                "TIP: NAKED~n~ZAPREMINA: 600ccm~n~STANJE: NOVO~n~KW/KS: 75/102~n~CENA: $4400"
            );

            gPlayerMenuPrice[playerid] = 4400;
        }
        
        case 10: {
            PlayerTextDrawSetPreviewModel(playerid, PlayerText: ui_BuyTextDraws[playerid][4], 522);
            PlayerTextDrawShow(playerid, PlayerText: ui_BuyTextDraws[playerid][4]);

            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][5], "YAMAHA YZF R6");
            PlayerTextDrawSetString(playerid, PlayerText: ui_BuyTextDraws[playerid][6],
                "TIP: SPORT / SUPER SPORT~n~ZAPREMINA: 600ccm~n~STANJE: NOVO~n~KW/KS: 87/118~n~CENA: $8000"
            );

            gPlayerMenuPrice[playerid] = 8000;
        }
    }

    return 1;
}

stock Cycle_BuyMenuPage(const playerid, const pageid)
{
    switch (pageid) {
        case 0: {
            if (Player_GetMoney(playerid) < gPlayerMenuPrice[playerid]) {
                SendClientMessage(playerid, -1, "Nemate dovoljno novca.");
                return 0;
            }

            Player_SetMoney(playerid, (Player_GetMoney(playerid) - gPlayerMenuPrice[playerid]));
            GivePlayerMoney(playerid, -gPlayerMenuPrice[playerid]);
            
            Player_SpawnedCycle(playerid) = Cycle_Create(481, ReturnPlayerName(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191
            );
            
            SendClientMessage(playerid, X11_RED, "* Buy: "WHITE"Cestitamo! Kupili ste novi bicikl!");
            
            PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);
            CancelSelectTextDraw(playerid);
            UI_CreateBuyTextDraws(playerid, false);
        }
        
        case 1: {
            if (Player_GetMoney(playerid) < gPlayerMenuPrice[playerid]) {
                SendClientMessage(playerid, -1, "Nemate dovoljno novca.");
                return 1;
            }

            Player_SetMoney(playerid, (Player_GetMoney(playerid) - gPlayerMenuPrice[playerid]));
            GivePlayerMoney(playerid, -gPlayerMenuPrice[playerid]);
            
            Player_SpawnedCycle(playerid) = Cycle_Create(509, ReturnPlayerName(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191
            );

            SendClientMessage(playerid, X11_RED, "* Buy: "WHITE"Cestitamo! Kupili ste novi bicikl!");

            PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);
            CancelSelectTextDraw(playerid);
            UI_CreateBuyTextDraws(playerid, false);
        }
        
        case 2: {
            if (Player_GetMoney(playerid) < gPlayerMenuPrice[playerid]) {
                SendClientMessage(playerid, -1, "Nemate dovoljno novca.");
                return 1;
            }

            Player_SetMoney(playerid, (Player_GetMoney(playerid) - gPlayerMenuPrice[playerid]));
            GivePlayerMoney(playerid, -gPlayerMenuPrice[playerid]);
            
            Player_SpawnedCycle(playerid) = Cycle_Create(510, ReturnPlayerName(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191
            );

            SendClientMessage(playerid, X11_RED, "* Buy: "WHITE"Cestitamo! Kupili ste novi bicikl!");
            
            PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);
            CancelSelectTextDraw(playerid);
            UI_CreateBuyTextDraws(playerid, false);
        }
        
        case 3: {
            if (Player_GetMoney(playerid) < gPlayerMenuPrice[playerid]) {
                SendClientMessage(playerid, -1, "Nemate dovoljno novca.");
                return 1;
            }

            Player_SetMoney(playerid, (Player_GetMoney(playerid) - gPlayerMenuPrice[playerid]));
            GivePlayerMoney(playerid, -gPlayerMenuPrice[playerid]);
            
            Player_SpawnedCycle(playerid) = Cycle_Create(462, ReturnPlayerName(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191
            );

            SendClientMessage(playerid, X11_RED, "* Buy: "WHITE"Cestitamo! Kupili ste novi motor!");
            
            PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);
            CancelSelectTextDraw(playerid);
            UI_CreateBuyTextDraws(playerid, false);
        }
        
        case 4: {
            if (Player_GetMoney(playerid) < gPlayerMenuPrice[playerid]) {
                SendClientMessage(playerid, -1, "Nemate dovoljno novca.");
                return 1;
            }

            Player_SetMoney(playerid, (Player_GetMoney(playerid) - gPlayerMenuPrice[playerid]));
            GivePlayerMoney(playerid, -gPlayerMenuPrice[playerid]);
            
            Player_SpawnedCycle(playerid) = Cycle_Create(586, ReturnPlayerName(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191
            );

            SendClientMessage(playerid, X11_RED, "* Buy: "WHITE"Cestitamo! Kupili ste novi motor!");
            
            PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);
            CancelSelectTextDraw(playerid);
            UI_CreateBuyTextDraws(playerid, false);
        }
        
        case 5: {
            if (Player_GetMoney(playerid) < gPlayerMenuPrice[playerid]) {
                SendClientMessage(playerid, -1, "Nemate dovoljno novca.");
                return 1;
            }

            Player_SetMoney(playerid, (Player_GetMoney(playerid) - gPlayerMenuPrice[playerid]));
            GivePlayerMoney(playerid, -gPlayerMenuPrice[playerid]);
            
            Player_SpawnedCycle(playerid) = Cycle_Create(463, ReturnPlayerName(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191
            );

            SendClientMessage(playerid, X11_RED, "* Buy: "WHITE"Cestitamo! Kupili ste novi motor!");
            
            PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);
            CancelSelectTextDraw(playerid);
            UI_CreateBuyTextDraws(playerid, false);
        }
        
        case 6: {
            if (Player_GetMoney(playerid) < gPlayerMenuPrice[playerid]) {
                SendClientMessage(playerid, -1, "Nemate dovoljno novca.");
                return 1;
            }

            Player_SetMoney(playerid, (Player_GetMoney(playerid) - gPlayerMenuPrice[playerid]));
            GivePlayerMoney(playerid, -gPlayerMenuPrice[playerid]);
            
            Player_SpawnedCycle(playerid) = Cycle_Create(468, ReturnPlayerName(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191
            );

            SendClientMessage(playerid, X11_RED, "* Buy: "WHITE"Cestitamo! Kupili ste novi motor!");
            
            PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);
            CancelSelectTextDraw(playerid);
            UI_CreateBuyTextDraws(playerid, false);
        }
        
        case 7: {
            if (Player_GetMoney(playerid) < gPlayerMenuPrice[playerid]) {
                SendClientMessage(playerid, -1, "Nemate dovoljno novca.");
                return 1;
            }

            Player_SetMoney(playerid, (Player_GetMoney(playerid) - gPlayerMenuPrice[playerid]));
            GivePlayerMoney(playerid, -gPlayerMenuPrice[playerid]);
            
            Player_SpawnedCycle(playerid) = Cycle_Create(461, ReturnPlayerName(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191
            );

            SendClientMessage(playerid, X11_RED, "* Buy: "WHITE"Cestitamo! Kupili ste novi motor!");
            
            PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);
            CancelSelectTextDraw(playerid);
            UI_CreateBuyTextDraws(playerid, false);
        }
        
        case 8: {
            if (Player_GetMoney(playerid) < gPlayerMenuPrice[playerid]) {
                SendClientMessage(playerid, -1, "Nemate dovoljno novca.");
                return 1;
            }

            Player_SetMoney(playerid, (Player_GetMoney(playerid) - gPlayerMenuPrice[playerid]));
            GivePlayerMoney(playerid, -gPlayerMenuPrice[playerid]);
            
            Player_SpawnedCycle(playerid) = Cycle_Create(521, ReturnPlayerName(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191
            );

            SendClientMessage(playerid, X11_RED, "* Buy: "WHITE"Cestitamo! Kupili ste novi motor!");
            
            PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);
            CancelSelectTextDraw(playerid);
            UI_CreateBuyTextDraws(playerid, false);
        }
        
        case 9: {
            if (Player_GetMoney(playerid) < gPlayerMenuPrice[playerid]) {
                SendClientMessage(playerid, -1, "Nemate dovoljno novca.");
                return 1;
            }

            Player_SetMoney(playerid, (Player_GetMoney(playerid) - gPlayerMenuPrice[playerid]));
            GivePlayerMoney(playerid, -gPlayerMenuPrice[playerid]);

            Player_SpawnedCycle(playerid) = Cycle_Create(581, ReturnPlayerName(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191
            );

            SendClientMessage(playerid, X11_RED, "* Buy: "WHITE"Cestitamo! Kupili ste novi motor!");
            
            PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);
            CancelSelectTextDraw(playerid);
            UI_CreateBuyTextDraws(playerid, false);
        }
        
        case 10: {
            if (Player_GetMoney(playerid) < gPlayerMenuPrice[playerid]) {
                SendClientMessage(playerid, -1, "Nemate dovoljno novca.");
                return 1;
            }

            Player_SetMoney(playerid, (Player_GetMoney(playerid) - gPlayerMenuPrice[playerid]));
            GivePlayerMoney(playerid, -gPlayerMenuPrice[playerid]);

            Player_SpawnedCycle(playerid) = Cycle_Create(522, ReturnPlayerName(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191
            );

            SendClientMessage(playerid, X11_RED, "* Buy: "WHITE"Cestitamo! Kupili ste novi motor!");
            
            PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);
            CancelSelectTextDraw(playerid);
            UI_CreateBuyTextDraws(playerid, false);
        }
    }

    return 1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if (PlayerText: playertextid == PlayerText: ui_BuyTextDraws[playerid][9]) {
        CancelSelectTextDraw(playerid);
        UI_CreateBuyTextDraws(playerid, false);
    }

    // back
    else if (PlayerText: playertextid == PlayerText: ui_BuyTextDraws[playerid][2]) {
        if (!gPlayerMenuPage[playerid]) {
            SendClientMessage(playerid, -1, "Ne mozete vise unazad.");
            return 1;
        }

        --gPlayerMenuPage[playerid];

        switch (gPlayerMenuPage[playerid]) {
            case 0: return Cycle_SetMenuPage(playerid, 0);
            case 1: return Cycle_SetMenuPage(playerid, 1);
            case 2: return Cycle_SetMenuPage(playerid, 2);
            case 3: return Cycle_SetMenuPage(playerid, 3);
            case 4: return Cycle_SetMenuPage(playerid, 4);
            case 5: return Cycle_SetMenuPage(playerid, 5);
            case 6: return Cycle_SetMenuPage(playerid, 6);
            case 7: return Cycle_SetMenuPage(playerid, 7);
            case 8: return Cycle_SetMenuPage(playerid, 8);
            case 9: return Cycle_SetMenuPage(playerid, 9);
            case 10: return Cycle_SetMenuPage(playerid, 10);
        }
    }

    // forward
    else if (PlayerText: playertextid == PlayerText: ui_BuyTextDraws[playerid][3]) {
        if (gPlayerMenuPage[playerid] == MAX_PAGES) {
            SendClientMessage(playerid, -1, "Nemamo vise modela.");
            return 1;
        }

        ++gPlayerMenuPage[playerid];

        switch (gPlayerMenuPage[playerid]) {
            case 0: return Cycle_SetMenuPage(playerid, 0);
            case 1: return Cycle_SetMenuPage(playerid, 1);
            case 2: return Cycle_SetMenuPage(playerid, 2);
            case 3: return Cycle_SetMenuPage(playerid, 3);
            case 4: return Cycle_SetMenuPage(playerid, 4);
            case 5: return Cycle_SetMenuPage(playerid, 5);
            case 6: return Cycle_SetMenuPage(playerid, 6);
            case 7: return Cycle_SetMenuPage(playerid, 7);
            case 8: return Cycle_SetMenuPage(playerid, 8);
            case 9: return Cycle_SetMenuPage(playerid, 9);
            case 10: return Cycle_SetMenuPage(playerid, 10);
        }
    }

    else if (PlayerText: playertextid == PlayerText: ui_BuyTextDraws[playerid][8]) {
        switch (gPlayerMenuPage[playerid]) {
            case 0: return Cycle_BuyMenuPage(playerid, 0);
            case 1: return Cycle_BuyMenuPage(playerid, 1);
            case 2: return Cycle_BuyMenuPage(playerid, 2);
            case 3: return Cycle_BuyMenuPage(playerid, 3);
            case 4: return Cycle_BuyMenuPage(playerid, 4);
            case 5: return Cycle_BuyMenuPage(playerid, 5);
            case 6: return Cycle_BuyMenuPage(playerid, 6);
            case 7: return Cycle_BuyMenuPage(playerid, 7);
            case 8: return Cycle_BuyMenuPage(playerid, 8);
            case 9: return Cycle_BuyMenuPage(playerid, 9);
            case 10: return Cycle_BuyMenuPage(playerid, 10);
        }
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}