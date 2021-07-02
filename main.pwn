#include <a_samp>
#include <crashdetect>
#include <chrono>
#include <a_mysql>
#include <PawnPlus>
#include <streamer>
#include <pp-mysql>
#include <sscanf2>
#include <env>

#define YSI_NO_HEAP_MALLOC
#define YSI_NO_VERSION_CHECK
#define YSI_NO_MODE_CACHE
#define YSI_NO_OPTIMISATION_MESSAGE

#include <YSI_Coding\y_timers>
#include <YSI_Coding\y_iterate>
#include <YSI_Server\y_colours>
#include <YSI_Data\y_bit>

#include <jit>
#include <easy-dialog>
#include <geolocation>

/**
* Modules
*/
#include <database_main>
#include <settings>
#include <cmd_process>
#include <acc_main>
#include <ban_main>
#include <admin_main>
#include <player_main>
#include <maps>
#include <cycle_main>
#include <ui_main>

main()
{
	printf("JIT is %spresent", (IsJITPresent() ? ("not ") : ("")));
	OnJITCompile();
	
	new
		Timestamp: ts = Timestamp: Now(),
		string: ts_fmt[24];

	TimeFormat(Timestamp: ts, ISO6801_TIME, string: ts_fmt, sizeof(ts_fmt));
	printf("Gamemode successfully loaded at %s", string: ts_fmt);
}

/**
  * Callbacks
 */
forward OnJITCompile();
forward Bind_OnPlayerDisconnect(
	CallbackHandler: self, Handle: task_handle, Task: task, const orig_playerid, const playerid
);

public OnGameModeInit()
{
	EnableStuntBonusForAll(0);
	DisableInteriorEnterExits();
	UsePlayerPedAnims();

	return 1;
}

public OnJITCompile()
{
	printf("OnJITCompile->JIT is %spresent", (IsJITPresent() ? ("not ") : ("")));
	return 1;
}

public Bind_OnPlayerDisconnect(
	CallbackHandler: self, Handle: task_handle, Task: task, const orig_playerid, const playerid
)
{
    if(orig_playerid == playerid) {
        pawn_unregister_callback(self);
        handle_release(task_handle);

        if(handle_linked(task_handle)) {
            task_delete(task);
        }
    }
}

BindToPlayer(Task: task, const playerid)
{
    new
		Handle: handle = handle_new(_:task, .tag_id = tagof(task));
		
    handle_acquire(handle);
    pawn_register_callback(#OnPlayerDisconnect, #Bind_OnPlayerDisconnect, _, "eddd", _:handle, _:task, playerid);
    
    return _:task;
}