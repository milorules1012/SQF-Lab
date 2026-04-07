// File: fn_mainMenu.sqf
// Author: Milo
// Description: Opens the SQF Lab main menu.

if (!hasInterface) exitWith { false };

private _cfg = configFile >> "SQFLab_MainMenu";
if (!isClass _cfg) exitWith {
	diag_log "[SQFLab] SQFLab_MainMenu display class missing from config";
	false
};

private _idd = getNumber (_cfg >> "idd");
private _disp = findDisplay _idd;

if (!isNull _disp) exitWith {
	_disp closeDisplay 2;
	true
};

createDialog "SQFLab_MainMenu"
