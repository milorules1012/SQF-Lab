// File: fn_markersMenu.sqf
// Author: Milo
// Description: Opens the map markers editor dialog from the SQF Lab main menu.

private _cfg = configFile >> "SQFLab_MarkersMenu";
if (!isClass _cfg) exitWith {
	diag_log "[SQFLab] SQFLab_MarkersMenu display class missing from config";
	systemChat "SQF Lab markers menu display class missing from config";
};

if !(isPlayer player) exitWith {
	diag_log "[SQFLab] SQFLab_MarkersMenu cannot run without being a player";
	systemChat "This feature does not work where you are not a player";
};

private _idd = getNumber (_cfg >> "idd");
private _display = findDisplay _idd;

if (!isNull _display) exitWith {
	_display closeDisplay 2;
};

createDialog "SQFLab_MarkersMenu";
