// File: fn_lightsOnSlider.sqf
// Author: Milo
// Description: Syncs UI readouts and applies local light + orientation to the preview.

#include "ui_lights_controls.hpp"

private _display = uiNamespace getVariable ["SQFLab_lights_display", displayNull];
if (isNull _display) exitWith {
	diag_log "[SQFLab] SQFLab_lightsOnSlider could not find the lights menu";
	systemChat (localize "STR_SQFLAB_Err_LightsMenuNotFound");
};

private _pairs = [
	[SQFLAB_LT_IDC_SLIDER_DIR, SQFLAB_LT_IDC_VALUE_DIR],
	[SQFLAB_LT_IDC_SLIDER_UP, SQFLAB_LT_IDC_VALUE_UP],
	[SQFLAB_LT_IDC_SLIDER_COL_R, SQFLAB_LT_IDC_VALUE_COL_R],
	[SQFLAB_LT_IDC_SLIDER_COL_G, SQFLAB_LT_IDC_VALUE_COL_G],
	[SQFLAB_LT_IDC_SLIDER_COL_B, SQFLAB_LT_IDC_VALUE_COL_B],
	[SQFLAB_LT_IDC_SLIDER_AMB_R, SQFLAB_LT_IDC_VALUE_AMB_R],
	[SQFLAB_LT_IDC_SLIDER_AMB_G, SQFLAB_LT_IDC_VALUE_AMB_G],
	[SQFLAB_LT_IDC_SLIDER_AMB_B, SQFLAB_LT_IDC_VALUE_AMB_B],
	[SQFLAB_LT_IDC_SLIDER_INTENSITY, SQFLAB_LT_IDC_VALUE_INTENSITY],
	[SQFLAB_LT_IDC_SLIDER_FLARE_SIZE, SQFLAB_LT_IDC_VALUE_FLARE_SIZE],
	[SQFLAB_LT_IDC_SLIDER_FLARE_MAX, SQFLAB_LT_IDC_VALUE_FLARE_MAX],
	[SQFLAB_LT_IDC_SLIDER_CONE_OUT, SQFLAB_LT_IDC_VALUE_CONE_OUT],
	[SQFLAB_LT_IDC_SLIDER_CONE_IN, SQFLAB_LT_IDC_VALUE_CONE_IN],
	[SQFLAB_LT_IDC_SLIDER_CONE_COEF, SQFLAB_LT_IDC_VALUE_CONE_COEF]
];

{
	_x params ["_sliderIdc", "_valueIdc"];
	private _value = sliderPosition (_display displayCtrl _sliderIdc);
	(_display displayCtrl _valueIdc) ctrlSetText (str ([_value, 3] call BIS_fnc_cutDecimals));
} forEach _pairs;

private _lr = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_COL_R);
private _lg = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_COL_G);
private _lb = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_COL_B);
(_display displayCtrl SQFLAB_LT_IDC_COLOR_PREVIEW) ctrlSetBackgroundColor [_lr, _lg, _lb, 1];

private _type = toLower (uiNamespace getVariable ["SQFLab_lights_type", "point"]);
private _class = ["#lightpoint", "#lightreflector"] select (_type isEqualTo "reflector");

private _lit = uiNamespace getVariable ["SQFLab_lights_light", objNull];
if (!isNull _lit && { (typeOf _lit) != _class }) then {
	deleteVehicle _lit;
	_lit = objNull;
	uiNamespace setVariable ["SQFLab_lights_light", objNull];
};

if (isNull _lit) then {
	_lit = _class createVehicleLocal [0, 0, 0];
	uiNamespace setVariable ["SQFLab_lights_light", _lit];
};

private _defaultPos = uiNamespace getVariable ["SQFLab_lights_lastGoodPos", getPosATL player];
private _posRaw = ctrlText (_display displayCtrl SQFLAB_LT_IDC_EDIT_POS);
private _parsed = parseSimpleArray _posRaw;
private _pos = _defaultPos;
if (_parsed isEqualTypeArray [0, 0, 0]) then {
	_parsed params ["_px", "_py", "_pz"];
	_pos = [_px, _py, _pz];
	uiNamespace setVariable ["SQFLab_lights_lastGoodPos", _pos];
};

_lit setPosATL _pos;

private _dirDeg = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_DIR);
private _pitchDeg = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_UP);
private _yawRad = _dirDeg * pi / 180;
private _pitchRad = _pitchDeg * pi / 180;
private _dirVec = [
	(sin _yawRad) * (cos _pitchRad),
	(cos _yawRad) * (cos _pitchRad),
	sin _pitchRad
];
private _worldUp = [0, 0, 1];
private _right = [_worldUp, _dirVec] call SQFLab_fnc_vecCross;
if ((_right distance [0, 0, 0]) < 1e-4) then {
	_right = [[0, 1, 0], _dirVec] call SQFLab_fnc_vecCross;
};
_right = [_right] call SQFLab_fnc_vecNorm;
private _upVec = [[_dirVec, _right] call SQFLab_fnc_vecCross] call SQFLab_fnc_vecNorm;
_lit setVectorDirAndUp [_dirVec, _upVec];

private _ar = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_AMB_R);
private _ag = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_AMB_G);
private _ab = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_AMB_B);

_lit setLightColor [_lr, _lg, _lb];
_lit setLightAmbient [_ar, _ag, _ab];
_lit setLightAttenuation [0, 2, 4, 4, 0, 9, 10];

private _power = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_INTENSITY);
if (_type isEqualTo "reflector") then {
	_lit setLightIntensity (_power * 40);
} else {
	_lit setLightBrightness _power;
};

_lit setLightDayLight true;
_lit setLightIR false;

if (_type isEqualTo "reflector") then {
	private _outer = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_CONE_OUT);
	private _inner = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_CONE_IN);
	private _coef = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_CONE_COEF);
	_inner = _inner min (_outer - 0.5);
	_inner = _inner max 0;
	_lit setLightConePars [_outer, _inner, _coef];
	_lit setLightUseFlare false;
} else {
	private _useFlare = cbChecked (_display displayCtrl SQFLAB_LT_IDC_CHK_FLARE);
	private _fSize = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_FLARE_SIZE);
	private _fMax = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_FLARE_MAX);
	_lit setLightUseFlare _useFlare;
	_lit setLightFlareSize _fSize;
	_lit setLightFlareMaxDistance _fMax;
};
