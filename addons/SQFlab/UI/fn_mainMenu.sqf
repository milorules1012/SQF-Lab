// File: fn_mainMenu.sqf
// Author: Milo
// Description: Opens the SQF Lab main menu.

#include "ui_mainMenu_controls.hpp"

private _cfg = configFile >> "SQFLab_MainMenu";
if (!isClass _cfg) exitWith {
	diag_log "[SQFLab] SQFLab_MainMenu display class missing from config";
	systemChat "SQF Lab main menu display class missing from config";
};

private _idd = getNumber (_cfg >> "idd");
private _display = findDisplay _idd;

if (!isNull _display) exitWith {
	_display closeDisplay 2;
};

createDialog "SQFLab_MainMenu";

// Feature flagging
ctrlEnable [SQFLAB_MM_IDC_BTN_ANIMATIONS, false];
ctrlEnable [SQFLAB_MM_IDC_BTN_ATTACHTO, false];
ctrlEnable [SQFLAB_MM_IDC_BTN_CAMERA, false];
ctrlEnable [SQFLAB_MM_IDC_BTN_DRAWICON3D, false];
ctrlEnable [SQFLAB_MM_IDC_BTN_LIGHTSOURCES, false];
ctrlEnable [SQFLAB_MM_IDC_BTN_MARKERS, true];
ctrlEnable [SQFLAB_MM_IDC_BTN_PARTICLES, true];
ctrlEnable [SQFLAB_MM_IDC_BTN_SELECTIONVIEWER, false];
ctrlEnable [SQFLAB_MM_IDC_BTN_TURRET, false];
ctrlEnable [SQFLAB_MM_IDC_BTN_UIEDITOR, false];
ctrlEnable [SQFLAB_MM_IDC_BTN_WEATHER, false];
