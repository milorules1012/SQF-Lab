// File: fn_markersSliderValueCommit.sqf
// Author: Milo
// Description: Simply changes the sliders to it's corresponding edit value

#include "ui_markers_controls.hpp"

private _edit = param [0, controlNull, [controlNull]];
if (isNull _edit) exitWith {};

private _idc = ctrlIDC _edit;
private _sliderIdc = switch (_idc) do {
	case SQFLAB_MKR_IDC_VALUE_COLOR_R: { SQFLAB_MKR_IDC_SLIDER_COLOR_R };
	case SQFLAB_MKR_IDC_VALUE_COLOR_G: { SQFLAB_MKR_IDC_SLIDER_COLOR_G };
	case SQFLAB_MKR_IDC_VALUE_COLOR_B: { SQFLAB_MKR_IDC_SLIDER_COLOR_B };
	case SQFLAB_MKR_IDC_VALUE_COLOR_A: { SQFLAB_MKR_IDC_SLIDER_COLOR_A };
	case SQFLAB_MKR_IDC_VALUE_SIZE_A: { SQFLAB_MKR_IDC_SLIDER_SIZE_A };
	case SQFLAB_MKR_IDC_VALUE_SIZE_B: { SQFLAB_MKR_IDC_SLIDER_SIZE_B };
	case SQFLAB_MKR_IDC_VALUE_DIR: { SQFLAB_MKR_IDC_SLIDER_DIR };
	default { -1 };
};
if (_sliderIdc < 0) exitWith {};

private _sg = uiNamespace getVariable ["SQFLab_markers_scrollGroup", controlNull];
private _slider = _sg controlsGroupCtrl _sliderIdc;
if (isNull _sg || isNull _slider) exitWith {};

(sliderRange _slider) params ["_min", "_max"];
private _n = parseNumber (ctrlText _edit);
_n = if (finite _n) then {
	_min max _n min _max;
} else {
	sliderPosition _slider;
};

_slider sliderSetPosition _n;
[] call SQFLab_fnc_markersOnSlider;

