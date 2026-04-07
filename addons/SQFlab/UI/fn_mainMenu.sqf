// File: fn_mainMenu.sqf
// Author: Milo
// Description: Opens the SQF Lab main menu.

private _cfg = configFile >> "SQFLab_MainMenu";
if (!isClass _cfg) exitWith {
	diag_log "[SQFLab] SQFLab_MainMenu display class missing from config";
	systemChat "SQF Lab main menu display class missing from config";
};

private _idd = getNumber (_cfg >> "idd");
private _disp = findDisplay _idd;

if (!isNull _disp) exitWith {
	_disp closeDisplay 2;
};

createDialog "SQFLab_MainMenu"
