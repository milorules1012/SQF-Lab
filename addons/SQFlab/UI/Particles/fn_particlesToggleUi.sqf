// File: fn_particlesToggleUi.sqf
// Author: Milo
// Description: Toggles hiding and unhiding of the UI for player view.

#include "ui_particles_controls.hpp"

private _display = uiNamespace getVariable ["SQFLab_particles_display", displayNull];
if (isNull _display) exitWith { false };

private _hideBtn = _display displayCtrl SQFLAB_IDC_BTN_HIDE_UI;
private _isHidden = uiNamespace getVariable ["SQFLab_particles_uiHidden", false];
private _nextHidden = !_isHidden;

{
	private _ctrl = _x;
	private _idc = ctrlIDC _ctrl;
	_ctrl ctrlShow (_idc == SQFLAB_IDC_BTN_HIDE_UI || !_nextHidden);
} forEach (allControls _display);

_hideBtn ctrlSetText (["Hide UI", "Show UI"] select _nextHidden);
uiNamespace setVariable ["SQFLab_particles_uiHidden", _nextHidden];
