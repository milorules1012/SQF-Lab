// File: fn_mainMenu.sqf
// Author: Milo
// Description: Opens the SQF Lab main menu.

#include "ui_mainMenu_controls.hpp"

private _cfg = configFile >> "SQFLab_MainMenu";
if (!isClass _cfg) exitWith {
	diag_log "[SQFLab] SQFLab_MainMenu display class missing from config";
	systemChat (localize "STR_SQFLAB_Err_MainMenuDisplayMissing");
};

private _idd = getNumber (_cfg >> "idd");
private _display = findDisplay _idd;

if (!isNull _display) exitWith {
	_display closeDisplay 2;
};

createDialog "SQFLab_MainMenu";
