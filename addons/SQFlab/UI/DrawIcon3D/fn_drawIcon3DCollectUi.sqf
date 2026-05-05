// File: fn_drawIcon3DCollectUi.sqf
// Author: Milo
// Description: Collects DrawIcon3D editor UI controls into a normalized hash map.

#include "ui_drawIcon3D_controls.hpp"

private _display = uiNamespace getVariable ["SQFLab_drawIcon3D_display", displayNull];
private _group = uiNamespace getVariable ["SQFLab_drawIcon3D_group", controlNull];
if (isNull _display || isNull _group) exitWith { nil };

private _numFromEdit = {
	params ["_idc", "_fallback"];
	[ctrlText (_group controlsGroupCtrl _idc), _fallback] call SQFLab_fnc_parseNumberOrFallback
};

private _modeCtrl = _group controlsGroupCtrl SQFLAB_DI3D_IDC_COMBO_POS_MODE;
private _mode = lbCurSel _modeCtrl;
if (_mode < 0) then { _mode = 0 };

private _fontCtrl = _group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_FONT;
private _fontSel = lbCurSel _fontCtrl;
if (_fontSel < 0) then { _fontSel = 0 };
private _fontName = _fontCtrl lbData _fontSel;
if (_fontName isEqualTo "") then {
	_fontName = _fontCtrl lbText _fontSel;
};
if (_fontName isEqualTo "") then { _fontName = "RobotoCondensed" };

private _position = [0, 0, 2];
switch (_mode) do {
	case 0: {
		_position = [ctrlText (_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_POS_VEC), [0, 0, 2]] call SQFLab_fnc_parseArrayOrFallback;
	};
	case 1: {
		private _obj = call compile (ctrlText (_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_POS_OBJECT));
		if (isNil "_obj" || {isNull _obj}) then { _obj = player };
		_position = [_obj, [SQFLAB_DI3D_IDC_EDIT_POS_OFFSETZ, 2] call _numFromEdit];
	};
	default {
		private _obj2 = call compile (ctrlText (_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_POS_OBJECT));
		if (isNil "_obj2" || {isNull _obj2}) then { _obj2 = player };
		private _sel = ctrlText (_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_POS_SELECTION);
		private _offZ = [SQFLAB_DI3D_IDC_EDIT_POS_OFFSETZ, 0] call _numFromEdit;
		private _lodRaw = [SQFLAB_DI3D_IDC_EDIT_POS_LOD, -1] call _numFromEdit;
		_position = [_obj2, _sel, _offZ];
		if (_lodRaw >= 0) then { _position pushBack floor _lodRaw };
	};
};

private _dynamic = cbChecked (_group controlsGroupCtrl SQFLAB_DI3D_IDC_CHK_DYNAMIC);
private _drawArrows = cbChecked (_group controlsGroupCtrl SQFLAB_DI3D_IDC_CHK_DRAW_ARROWS);
if (_dynamic) then { _drawArrows = false };

private _textEntry = ctrlText (_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_TEXTS_TEXT);
private _texts = [];
if (_textEntry isNotEqualTo "") then {
	_texts pushBack [
		_textEntry,
		[SQFLAB_DI3D_IDC_EDIT_TEXTS_SIZE, 0.025] call _numFromEdit,
		[SQFLAB_DI3D_IDC_EDIT_TEXTS_OX, -0.085] call _numFromEdit,
		[SQFLAB_DI3D_IDC_EDIT_TEXTS_OY, 0] call _numFromEdit,
		[
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_TEXTS_R),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_TEXTS_G),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_TEXTS_B),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_TEXTS_A)
		],
		cbChecked (_group controlsGroupCtrl SQFLAB_DI3D_IDC_CHK_TEXTS_SHADOW)
	];
};

createHashMapFromArray [
	["@position", _position],
	["@texture", ctrlText (_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_TEXTURE)],
	["@size", sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_SIZE)],
	["@font", _fontName],
	["@color", [
		sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_COLOR_R),
		sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_COLOR_G),
		sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_COLOR_B),
		sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_COLOR_A)
	]],
	["@shadow", cbChecked (_group controlsGroupCtrl SQFLAB_DI3D_IDC_CHK_SHADOW)],
	["@fade", [ctrlText (_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_FADE), [-1, -1]] call SQFLab_fnc_parseArrayOrFallback],
	["@dynamic", _dynamic],
	["@offsetX", sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_OFFSET_X)],
	["@offsetY", sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_OFFSET_Y)],
	["@hardAlpha", sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_HARD_ALPHA)],
	["@checkVisibility", cbChecked (_group controlsGroupCtrl SQFLAB_DI3D_IDC_CHK_CHECK_VIS)],
	["@drawArrows", _drawArrows],
	["@arrowTexture", ctrlText (_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_ARROW_TEXTURE)],
	["@arrowSize", sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_SIZE)],
	["@arrowColor", [
		sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_R),
		sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_G),
		sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_B),
		sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_A)
	]],
	["@arrowText", [
		ctrlText (_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_ARROW_TEXT_TEXT),
		[SQFLAB_DI3D_IDC_EDIT_ARROW_TEXT_SIZE, 0.04] call _numFromEdit,
		[SQFLAB_DI3D_IDC_EDIT_ARROW_TEXT_OX, 1] call _numFromEdit,
		[SQFLAB_DI3D_IDC_EDIT_ARROW_TEXT_OY, 1] call _numFromEdit,
		[
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_R),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_G),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_B),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_A)
		],
		cbChecked (_group controlsGroupCtrl SQFLAB_DI3D_IDC_CHK_ARROW_TEXT_SHADOW)
	]],
	["@texts", _texts],
	["@progress", [
		[SQFLAB_DI3D_IDC_EDIT_PROGRESS_W, 0.005] call _numFromEdit,
		[SQFLAB_DI3D_IDC_EDIT_PROGRESS_H, 0.05] call _numFromEdit,
		[SQFLAB_DI3D_IDC_EDIT_PROGRESS_OX, -0.085] call _numFromEdit,
		[SQFLAB_DI3D_IDC_EDIT_PROGRESS_OY, 0] call _numFromEdit,
		[
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_R),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_G),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_B),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_A)
		],
		[
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_R),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_G),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_B),
			sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_A)
		]
	]],
	["@progressValue", sliderPosition (_group controlsGroupCtrl SQFLAB_DI3D_IDC_SLIDER_PROGRESS_VALUE)]
]
