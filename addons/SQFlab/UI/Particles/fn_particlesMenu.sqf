// File: fn_particlesMenu.sqf
// Author: Milo
// Description: Creates the particle menu from the SQF lab main menu.

private _cfg = configFile >> "SQFLab_ParticlesMenu";
if (!isClass _cfg) exitWith {
	diag_log "[SQFLab] SQFLab_ParticlesMenu display class missing from config";
};

private _idd = getNumber (_cfg >> "idd");
private _disp = findDisplay _idd;

if (!isNull _disp) exitWith {
	_disp closeDisplay 2;
};

createDialog "SQFLab_ParticlesMenu"
