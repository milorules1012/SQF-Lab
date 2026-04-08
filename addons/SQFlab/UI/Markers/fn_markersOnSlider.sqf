// File: fn_markersOnSlider.sqf
// Author: Milo
// Description: Updates slider value labels and color preview (UI only).

#include "ui_markers_controls.hpp"
private _display = uiNamespace getVariable ["SQFLab_markers_display", displayNull];
if (isNull _display) exitWith {
	diag_log "[SQFLab] SQFLab_MarkersOnSlider could not find the markers menu";
	systemChat "SQF Lab markers menu could not be found";
};

private _scrollGroup = uiNamespace getVariable ["SQFLab_markers_scrollGroup", controlNull];
if (isNull _scrollGroup) exitWith {
	diag_log "[SQFLab] SQFLab_MarkersOnSlider could not find scroll group";
	systemChat "SQF Lab markers scroll group could not be found";
};

private _pairs = [
	[SQFLAB_MKR_IDC_SLIDER_COLOR_R, SQFLAB_MKR_IDC_VALUE_COLOR_R],
	[SQFLAB_MKR_IDC_SLIDER_COLOR_G, SQFLAB_MKR_IDC_VALUE_COLOR_G],
	[SQFLAB_MKR_IDC_SLIDER_COLOR_B, SQFLAB_MKR_IDC_VALUE_COLOR_B],
	[SQFLAB_MKR_IDC_SLIDER_COLOR_A, SQFLAB_MKR_IDC_VALUE_COLOR_A],
	[SQFLAB_MKR_IDC_SLIDER_SIZE_A, SQFLAB_MKR_IDC_VALUE_SIZE_A],
	[SQFLAB_MKR_IDC_SLIDER_SIZE_B, SQFLAB_MKR_IDC_VALUE_SIZE_B],
	[SQFLAB_MKR_IDC_SLIDER_DIR, SQFLAB_MKR_IDC_VALUE_DIR]
];
{
	_x params ["_sliderIdc", "_valueIdc"];
	private _slider = _scrollGroup controlsGroupCtrl _sliderIdc;
	private _value = _scrollGroup controlsGroupCtrl _valueIdc;
	if (!isNull _slider && !isNull _value) then {
		private _sliderValue = sliderPosition _slider;
		_value ctrlSetText (_sliderValue toFixed 3);
	};
} forEach _pairs;

private _preview = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COLOR_PREVIEW;
if (!isNull _preview) then {
	private _r = sliderPosition (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_SLIDER_COLOR_R);
	private _g = sliderPosition (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_SLIDER_COLOR_G);
	private _b = sliderPosition (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_SLIDER_COLOR_B);
	private _a = sliderPosition (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_SLIDER_COLOR_A);
	_preview ctrlSetBackgroundColor [_r, _g, _b, _a];
};

[] call SQFLab_fnc_markersApplyPreview;

