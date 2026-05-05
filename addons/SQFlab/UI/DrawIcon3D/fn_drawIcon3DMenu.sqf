// File: fn_drawIcon3DMenu.sqf
// Author: Milo
// Description: Opens the DrawIcon3D editor dialog from SQF Lab main menu.

private _cfg = configFile >> "SQFLab_DrawIcon3DMenu";
if (!isClass _cfg) exitWith {
	diag_log "[SQFLab] SQFLab_DrawIcon3DMenu display class missing from config";
	systemChat (localize "STR_SQFLAB_Err_DrawIcon3DDisplayMissing");
};

if !(isPlayer player) exitWith {
	diag_log "[SQFLab] SQFLab_DrawIcon3DMenu cannot run without being a player";
	systemChat (localize "STR_SQFLAB_Err_FeatureRequiresPlayer");
};

private _idd = getNumber (_cfg >> "idd");
private _display = findDisplay _idd;
if (!isNull _display) exitWith {
	_display closeDisplay 2;
};

createDialog "SQFLab_DrawIcon3DMenu";
