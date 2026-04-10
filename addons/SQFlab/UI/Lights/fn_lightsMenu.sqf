// File: fn_lightsMenu.sqf
// Author: Milo
// Description: Opens the light source editor from the SQF Lab main menu.

private _cfg = configFile >> "SQFLab_LightsMenu";
if (!isClass _cfg) exitWith {
	diag_log "[SQFLab] SQFLab_LightsMenu display class missing from config";
	systemChat (localize "STR_SQFLAB_Err_LightsDisplayMissing");
};

if !(isPlayer player) exitWith {
	diag_log "[SQFLab] SQFLab_lightsMenu cannot run without being a player";
	systemChat (localize "STR_SQFLAB_Err_FeatureRequiresPlayer");
};

private _idd = getNumber (_cfg >> "idd");
private _display = findDisplay _idd;

if (!isNull _display) exitWith {
	_display closeDisplay 2;
};

createDialog "SQFLab_LightsMenu";
