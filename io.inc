/*

░█▀▀█ ▒█░▄▀ ▀▀█▀▀ ░█▀▀█ ▒█░▒█ 
▒█▄▄█ ▒█▀▄░ ░▒█░░ ▒█▄▄█ ▒█▀▀█ 
▒█░▒█ ▒█░▒█ ░▒█░░ ▒█░▒█ ▒█░▒█

 * Copyright (c) 2021, Aktah */

#if defined _IO_included
	#endinput
#endif
#define _IO_included

#if !defined _samp_included
	#error "plz include a_samp.inc"
#endif

#if !defined SendClientCheck
    native SendClientCheck(playerid, type, arg, offset, size);
#endif

#if !defined OnClientCheckResponse
    forward OnClientCheckResponse(playerid, type, arg, response);
#endif

static playerNotAndroid[MAX_PLAYERS char];

stock isPlayerAndroid(playerId) { return playerNotAndroid{playerId}; }

#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerConnect@999(playerid)
#else
	public OnPlayerConnect(playerid)
#endif
	{
		SendClientCheck(playerid, 0x48, 0, 0, 2);

		#if defined INC_IO_OnPlayerConnect
			return INC_IO_OnPlayerConnect(playerid);
		#else
			return 1;
		#endif
	}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerConnect
		#undef OnPlayerConnect
	#else
		#define _ALS_OnPlayerConnect
	#endif

	#define OnPlayerConnect INC_IO_OnPlayerConnect
	#if defined INC_IO_OnPlayerConnect
		forward INC_IO_OnPlayerConnect(playerid);
	#endif
#endif


#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnClientCheckResponse(playerid, type, arg, response)
#else
	public OnClientCheckResponse(playerid, type, arg, response)
#endif
	{
		switch(type)
		{       
			case 0x48:
			{
				playerNotAndroid{playerid} = true;
			}
		}

		#if defined INC_IO_OnClientCheckResponse
			return INC_IO_OnClientCheckResponse(playerid, type, arg, response);
		#else
			return 1;
		#endif
	}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnClientCheckResponse
		#undef OnClientCheckResponse
	#else
		#define _ALS_OnClientCheckResponse
	#endif

	#define OnClientCheckResponse INC_IO_OnClientCheckResponse
	#if defined INC_IO_OnClientCheckResponse
		forward INC_IO_OnClientCheckResponse(playerid, type, arg, response);
	#endif
#endif
