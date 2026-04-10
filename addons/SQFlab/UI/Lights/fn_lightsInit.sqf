// File: fn_lightsInit.sqf
// Author: Milo
// Description: PiP camera, preview anchor, slider defaults, first light spawn.

#include "ui_lights_controls.hpp"
params [
	["_event", displayNull, [displayNull, []]]
];

private _display = displayNull;
if (_event isEqualType displayNull) then {
	_display = _event;
} else {
	_display = _event param [0, displayNull, [displayNull]];
};
if (isNull _display) exitWith { false };

uiNamespace setVariable ["SQFLab_lights_display", _display];
uiNamespace setVariable ["SQFLab_lights_type", "point"];
uiNamespace setVariable ["SQFLab_lights_uiHidden", false];

private _datePrev = [date select 0, date select 1, date select 2, date select 3, date select 4];
uiNamespace setVariable ["SQFLab_lights_datePrev", _datePrev];
setDate [_datePrev select 0, _datePrev select 1, _datePrev select 2, 22, 0];

private _previewAnchor = "Sign_Sphere10cm_F" createVehicleLocal [0, 0, 0];
private _anchorPos = player modelToWorld [0, 3, 1.8];
_previewAnchor setPosATL _anchorPos;
_previewAnchor hideObject true;
uiNamespace setVariable ["SQFLab_lights_lastGoodPos", _anchorPos];

private _camTarget = "Sign_Sphere10cm_F" createVehicleLocal [0, 0, 0];
private _targetPos = _anchorPos vectorAdd [0, 0, 0.15];
_camTarget setPosATL _targetPos;
_camTarget hideObject true;

private _camPos = _targetPos vectorAdd [0, -2.8, 1.0];
private _cam = "camera" camCreate _camPos;
_cam cameraEffect ["INTERNAL", "BACK", "SQFLAB_LIGHT_RT"];
_cam camSetTarget _camTarget;
_cam camSetFov 0.75;
_cam camCommit 0;

uiNamespace setVariable ["SQFLab_lights_pipCamera", _cam];
uiNamespace setVariable ["SQFLab_lights_previewAnchor", _previewAnchor];
uiNamespace setVariable ["SQFLab_lights_pipTarget", _camTarget];
uiNamespace setVariable ["SQFLab_lights_light", objNull];

private _sliderDefaults = createHashMapFromArray [
	[SQFLAB_LT_IDC_SLIDER_DIR, 200],
	[SQFLAB_LT_IDC_SLIDER_UP, 0],
	[SQFLAB_LT_IDC_SLIDER_COL_R, 1],
	[SQFLAB_LT_IDC_SLIDER_COL_G, 0.55],
	[SQFLAB_LT_IDC_SLIDER_COL_B, 0.2],
	[SQFLAB_LT_IDC_SLIDER_AMB_R, 0.12],
	[SQFLAB_LT_IDC_SLIDER_AMB_G, 0.06],
	[SQFLAB_LT_IDC_SLIDER_AMB_B, 0.02],
	[SQFLAB_LT_IDC_SLIDER_INTENSITY, 2],
	[SQFLAB_LT_IDC_SLIDER_FLARE_SIZE, 0.6],
	[SQFLAB_LT_IDC_SLIDER_FLARE_MAX, 400],
	[SQFLAB_LT_IDC_SLIDER_CONE_OUT, 70],
	[SQFLAB_LT_IDC_SLIDER_CONE_IN, 55],
	[SQFLAB_LT_IDC_SLIDER_CONE_COEF, 5]
];

private _sliderRanges = [
	[SQFLAB_LT_IDC_SLIDER_DIR, 0, 360],
	[SQFLAB_LT_IDC_SLIDER_UP, -89, 89],
	[SQFLAB_LT_IDC_SLIDER_COL_R, 0, 1],
	[SQFLAB_LT_IDC_SLIDER_COL_G, 0, 1],
	[SQFLAB_LT_IDC_SLIDER_COL_B, 0, 1],
	[SQFLAB_LT_IDC_SLIDER_AMB_R, 0, 1],
	[SQFLAB_LT_IDC_SLIDER_AMB_G, 0, 1],
	[SQFLAB_LT_IDC_SLIDER_AMB_B, 0, 1],
	[SQFLAB_LT_IDC_SLIDER_INTENSITY, 0, 20],
	[SQFLAB_LT_IDC_SLIDER_FLARE_SIZE, 0.05, 3],
	[SQFLAB_LT_IDC_SLIDER_FLARE_MAX, 10, 2500],
	[SQFLAB_LT_IDC_SLIDER_CONE_OUT, 5, 120],
	[SQFLAB_LT_IDC_SLIDER_CONE_IN, 0, 110],
	[SQFLAB_LT_IDC_SLIDER_CONE_COEF, 0, 20]
];

{
	_x params ["_idc", "_min", "_max"];
	private _ctrl = _display displayCtrl _idc;
	_ctrl sliderSetRange [_min, _max];
	_ctrl sliderSetSpeed [((_max) - (_min)) / 100, ((_max) - (_min)) / 10];
	_ctrl sliderSetPosition (_sliderDefaults get _idc);
} forEach _sliderRanges;

(_display displayCtrl SQFLAB_LT_IDC_EDIT_POS) ctrlSetText str _anchorPos;

private _previewCtrl = _display displayCtrl SQFLAB_LT_IDC_PREVIEW_PICTURE;
_previewCtrl ctrlSetText "#(argb,512,512,1)r2t(SQFLAB_LIGHT_RT,1.0)";

[] call SQFLab_fnc_lightsOnSlider;

true
