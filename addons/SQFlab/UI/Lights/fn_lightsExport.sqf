// File: fn_lightsExport.sqf
// Author: Milo
// Description: Clipboard / RPT export of local light creation SQF.

#include "ui_lights_controls.hpp"

private _display = uiNamespace getVariable ["SQFLab_lights_display", displayNull];
if (isNull _display) exitWith {
	diag_log "[SQFLab] SQFLab_lightsExport could not find the lights menu";
	systemChat (localize "STR_SQFLAB_Err_LightsMenuNotFound");
};

private _type = toLower (uiNamespace getVariable ["SQFLab_lights_type", "point"]);
private _class = ["#lightpoint", "#lightreflector"] select (_type isEqualTo "reflector");

private _pos = uiNamespace getVariable ["SQFLab_lights_lastGoodPos", getPosATL player];
private _posRaw = ctrlText (_display displayCtrl SQFLAB_LT_IDC_EDIT_POS);
private _parsed = parseSimpleArray _posRaw;
if (_parsed isEqualTypeArray [0, 0, 0]) then {
	_pos = _parsed;
};

private _dirDeg = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_DIR);
private _pitchDeg = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_UP);
private _lr = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_COL_R);
private _lg = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_COL_G);
private _lb = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_COL_B);
private _ar = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_AMB_R);
private _ag = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_AMB_G);
private _ab = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_AMB_B);
private _power = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_INTENSITY);
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

private _lines = [
	"// SQF Lab — local light export (run on client where the light should exist)",
	format ["// Type: %1", _type],
	format ["private _lt = %1 createVehicleLocal [0, 0, 0];", str _class],
	format ["_lt setPosATL %1;", _pos],
	format ["_lt setVectorDirAndUp [%1, %2];", _dirVec, _upVec],
	format ["_lt setLightColor [%1, %2, %3];", _lr, _lg, _lb],
	format ["_lt setLightAmbient [%1, %2, %3];", _ar, _ag, _ab],
	"_lt setLightAttenuation [0, 2, 4, 4, 0, 9, 10]; // tweak per BIKI if needed"
];

if (_type isEqualTo "reflector") then {
	private _outer = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_CONE_OUT);
	private _inner = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_CONE_IN);
	private _coef = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_CONE_COEF);
	_inner = (_inner min (_outer - 0.5)) max 0;
	_lines pushBack format ["_lt setLightIntensity %1;", _power * 40];
	_lines pushBack format ["_lt setLightConePars [%1, %2, %3];", _outer, _inner, _coef];
	_lines pushBack format ["_lt setLightVolumeShape %1;", str "a3\data_f\VolumeLightFlashlight.p3d"];
} else {
	_lines pushBack format ["_lt setLightBrightness %1;", _power];
	private _useFlare = cbChecked (_display displayCtrl SQFLAB_LT_IDC_CHK_FLARE);
	private _fSize = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_FLARE_SIZE);
	private _fMax = sliderPosition (_display displayCtrl SQFLAB_LT_IDC_SLIDER_FLARE_MAX);
	_lines pushBack format ["_lt setLightUseFlare %1;", _useFlare];
	_lines pushBack format ["_lt setLightFlareSize %1;", _fSize];
	_lines pushBack format ["_lt setLightFlareMaxDistance %1;", _fMax];
};

_lines pushBack "_lt setLightDayLight true;";
_lines pushBack "_lt setLightIR false;";

private _nl = toString [10];
private _text = _lines joinString _nl;

if (isServer) then {
	copyToClipboard _text;
	hint (localize "STR_SQFLAB_Hint_LightExportClipboard");
} else {
	{ diag_log _x } forEach _lines;
	hint (localize "STR_SQFLAB_Hint_LightExportRpt");
};
