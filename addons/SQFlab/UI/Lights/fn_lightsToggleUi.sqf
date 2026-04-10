// File: fn_lightsToggleUi.sqf
// Author: Milo
// Description: Hides dialog chrome so you can see the world; keeps Hide UI visible.

#include "ui_lights_controls.hpp"

private _display = uiNamespace getVariable ["SQFLab_lights_display", displayNull];
if (isNull _display) exitWith {
	diag_log "[SQFLab] SQFLab_lightsToggleUi could not find the lights menu";
	systemChat (localize "STR_SQFLAB_Err_LightsMenuNotFound");
};

private _hideBtn = _display displayCtrl SQFLAB_LT_IDC_BTN_HIDE_UI;
private _isHidden = uiNamespace getVariable ["SQFLab_lights_uiHidden", false];
private _nextHidden = !_isHidden;

{
	private _ctrl = _x;
	private _idc = ctrlIDC _ctrl;
	_ctrl ctrlShow (_idc == SQFLAB_LT_IDC_BTN_HIDE_UI || !_nextHidden);
} forEach (allControls _display);

private _hideKey = ["STR_SQFLAB_Common_HideUI", "STR_SQFLAB_Common_ShowUI"] select _nextHidden;
_hideBtn ctrlSetText (localize _hideKey);
uiNamespace setVariable ["SQFLab_lights_uiHidden", _nextHidden];
