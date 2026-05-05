// File: fn_drawIcon3DOnSlider.sqf
// Author: Milo
// Description: Syncs slider values to readout edits and updates color previews.

#include "ui_drawIcon3D_controls.hpp"

private _display = uiNamespace getVariable ["SQFLab_drawIcon3D_display", displayNull];
private _group = uiNamespace getVariable ["SQFLab_drawIcon3D_group", controlNull];
if (isNull _display || isNull _group) exitWith { false };

{
	_x params ["_sliderIdc", "_valueIdc", "_decimals"];
	private _v = sliderPosition (_group controlsGroupCtrl _sliderIdc);
	(_group controlsGroupCtrl _valueIdc) ctrlSetText (_v toFixed _decimals);
} forEach [
	[SQFLAB_DI3D_IDC_SLIDER_SIZE, SQFLAB_DI3D_IDC_VALUE_SIZE, 3],
	[SQFLAB_DI3D_IDC_SLIDER_COLOR_R, SQFLAB_DI3D_IDC_VALUE_COLOR_R, 3],
	[SQFLAB_DI3D_IDC_SLIDER_COLOR_G, SQFLAB_DI3D_IDC_VALUE_COLOR_G, 3],
	[SQFLAB_DI3D_IDC_SLIDER_COLOR_B, SQFLAB_DI3D_IDC_VALUE_COLOR_B, 3],
	[SQFLAB_DI3D_IDC_SLIDER_COLOR_A, SQFLAB_DI3D_IDC_VALUE_COLOR_A, 3],
	[SQFLAB_DI3D_IDC_SLIDER_OFFSET_X, SQFLAB_DI3D_IDC_VALUE_OFFSET_X, 3],
	[SQFLAB_DI3D_IDC_SLIDER_OFFSET_Y, SQFLAB_DI3D_IDC_VALUE_OFFSET_Y, 3],
	[SQFLAB_DI3D_IDC_SLIDER_HARD_ALPHA, SQFLAB_DI3D_IDC_VALUE_HARD_ALPHA, 3],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_SIZE, SQFLAB_DI3D_IDC_VALUE_ARROW_SIZE, 3],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_R, SQFLAB_DI3D_IDC_VALUE_ARROW_R, 3],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_G, SQFLAB_DI3D_IDC_VALUE_ARROW_G, 3],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_B, SQFLAB_DI3D_IDC_VALUE_ARROW_B, 3],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_A, SQFLAB_DI3D_IDC_VALUE_ARROW_A, 3],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_R, SQFLAB_DI3D_IDC_VALUE_ARROW_TEXT_R, 3],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_G, SQFLAB_DI3D_IDC_VALUE_ARROW_TEXT_G, 3],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_B, SQFLAB_DI3D_IDC_VALUE_ARROW_TEXT_B, 3],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_A, SQFLAB_DI3D_IDC_VALUE_ARROW_TEXT_A, 3],
	[SQFLAB_DI3D_IDC_SLIDER_TEXTS_R, SQFLAB_DI3D_IDC_VALUE_TEXTS_R, 3],
	[SQFLAB_DI3D_IDC_SLIDER_TEXTS_G, SQFLAB_DI3D_IDC_VALUE_TEXTS_G, 3],
	[SQFLAB_DI3D_IDC_SLIDER_TEXTS_B, SQFLAB_DI3D_IDC_VALUE_TEXTS_B, 3],
	[SQFLAB_DI3D_IDC_SLIDER_TEXTS_A, SQFLAB_DI3D_IDC_VALUE_TEXTS_A, 3],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_R, SQFLAB_DI3D_IDC_VALUE_PROGRESS_FG_R, 3],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_G, SQFLAB_DI3D_IDC_VALUE_PROGRESS_FG_G, 3],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_B, SQFLAB_DI3D_IDC_VALUE_PROGRESS_FG_B, 3],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_A, SQFLAB_DI3D_IDC_VALUE_PROGRESS_FG_A, 3],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_R, SQFLAB_DI3D_IDC_VALUE_PROGRESS_BG_R, 3],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_G, SQFLAB_DI3D_IDC_VALUE_PROGRESS_BG_G, 3],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_B, SQFLAB_DI3D_IDC_VALUE_PROGRESS_BG_B, 3],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_A, SQFLAB_DI3D_IDC_VALUE_PROGRESS_BG_A, 3],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_VALUE, SQFLAB_DI3D_IDC_VALUE_PROGRESS_VALUE, 3]
];

(_group controlsGroupCtrl SQFLAB_DI3D_IDC_COLOR_PREVIEW) ctrlSetBackgroundColor [
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_COLOR_R),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_COLOR_G),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_COLOR_B),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_COLOR_A)
];
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_ARROW_COLOR_PREVIEW) ctrlSetBackgroundColor [
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_R),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_G),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_B),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_A)
];
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_ARROW_TEXT_COLOR_PREVIEW) ctrlSetBackgroundColor [
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_R),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_G),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_B),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_A)
];
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_TEXTS_COLOR_PREVIEW) ctrlSetBackgroundColor [
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_TEXTS_R),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_TEXTS_G),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_TEXTS_B),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_TEXTS_A)
];
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_PROGRESS_FG_PREVIEW) ctrlSetBackgroundColor [
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_R),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_G),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_B),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_A)
];
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_PROGRESS_BG_PREVIEW) ctrlSetBackgroundColor [
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_R),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_G),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_B),
	sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_A)
];

[] call SQFLab_fnc_drawIcon3DApplyPreview;
true
