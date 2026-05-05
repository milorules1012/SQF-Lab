// File: fn_drawIcon3DInit.sqf
// Author: Milo
// Description: Initializes DrawIcon3D editor controls and preview handler.

#include "ui_drawIcon3D_controls.hpp"

params [["_event", displayNull, [displayNull, []]]];

private _display = if (_event isEqualType displayNull) then { _event } else { _event param [0, displayNull, [displayNull]] };
if (isNull _display) exitWith { false };

uiNamespace setVariable ["SQFLab_drawIcon3D_display", _display];
private _group = _display displayCtrl SQFLAB_DI3D_IDC_GROUP_SCROLL;
uiNamespace setVariable ["SQFLab_drawIcon3D_group", _group];

private _posMode = _group controlsGroupCtrl SQFLAB_DI3D_IDC_COMBO_POS_MODE;
lbClear _posMode;
{
	private _i = _posMode lbAdd _x;
	_posMode lbSetData [_i, str _forEachIndex];
} forEach ["vector", "object+offset", "object+selection+lod"];
_posMode lbSetCurSel 1;

private _defaultVec = (ASLToAGL eyePos player) vectorAdd [0, 0, 2];
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_POS_VEC) ctrlSetText str _defaultVec;

private _fontCombo = _group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_FONT;
lbClear _fontCombo;
private _fontCfg = configFile >> "CfgFontFamilies";
for "_i" from 0 to ((count _fontCfg) - 1) do {
	private _entry = _fontCfg select _i;
	if (isClass _entry) then {
		private _name = configName _entry;
		private _idx = _fontCombo lbAdd _name;
		_fontCombo lbSetData [_idx, _name];
	};
};
if ((lbSize _fontCombo) <= 0) then {
	private _fallback = _fontCombo lbAdd "RobotoCondensed";
	_fontCombo lbSetData [_fallback, "RobotoCondensed"];
};
private _defaultFontIdx = -1;
for "_fontIdx" from 0 to ((lbSize _fontCombo) - 1) do {
	private _fontName = _fontCombo lbData _fontIdx;
	if (_fontName isEqualTo "") then {
		_fontName = _fontCombo lbText _fontIdx;
	};
	if (_fontName isEqualTo "RobotoCondensed") exitWith {
		_defaultFontIdx = _fontIdx;
	};
};
if (_defaultFontIdx < 0) then { _defaultFontIdx = 0 };
_fontCombo lbSetCurSel _defaultFontIdx;

{
	_x params ["_idc", "_min", "_max", "_default"];
	private _ctrl = _group controlsGroupCtrl _idc;
	_ctrl sliderSetRange [_min, _max];
	_ctrl sliderSetSpeed [(_max - _min) / 100, (_max - _min) / 10];
	_ctrl sliderSetPosition _default;
} forEach [
	[SQFLAB_DI3D_IDC_SLIDER_SIZE, 0, 0.20, 0.05],
	[SQFLAB_DI3D_IDC_SLIDER_COLOR_R, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_COLOR_G, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_COLOR_B, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_COLOR_A, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_OFFSET_X, -0.5, 0.5, -0.12],
	[SQFLAB_DI3D_IDC_SLIDER_OFFSET_Y, -0.5, 0.5, 0],
	[SQFLAB_DI3D_IDC_SLIDER_HARD_ALPHA, -1, 1, -1],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_SIZE, 0, 0.20, 0.06],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_R, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_G, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_B, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_A, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_R, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_G, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_B, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_ARROW_TEXT_A, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_TEXTS_R, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_TEXTS_G, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_TEXTS_B, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_TEXTS_A, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_R, 0, 1, 0.8],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_G, 0, 1, 0.8],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_B, 0, 1, 0],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_FG_A, 0, 1, 1],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_R, 0, 1, 0],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_G, 0, 1, 0.6],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_B, 0, 1, 0],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_BG_A, 0, 1, 0.6],
	[SQFLAB_DI3D_IDC_SLIDER_PROGRESS_VALUE, -1, 1, 0.67]
];

(_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_TEXTURE) ctrlSetText "\A3\ui_f\data\map\markers\military\triangle_ca.paa";
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_ARROW_TEXTURE) ctrlSetText "\a3\Ui_f\data\IGUI\Cfg\Cursors\outArrow_ca.paa";
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_TEXTS_TEXT) ctrlSetText "Sample text";
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_TEXTS_SIZE) ctrlSetText "0.025";
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_TEXTS_OX) ctrlSetText "-0.085";
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_TEXTS_OY) ctrlSetText "0.05";
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_PROGRESS_W) ctrlSetText "0.005";
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_PROGRESS_H) ctrlSetText "0.05";
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_PROGRESS_OX) ctrlSetText "-0.085";
(_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_PROGRESS_OY) ctrlSetText "0";

[] call SQFLab_fnc_drawIcon3DOnSlider;

private _prevEh = uiNamespace getVariable ["SQFLab_drawIcon3D_ehId", -1];
if (_prevEh >= 0) then {
	removeMissionEventHandler ["Draw3D", _prevEh];
};

private _ehId = addMissionEventHandler ["Draw3D", { call SQFLab_fnc_drawIcon3DDrawEH }];
uiNamespace setVariable ["SQFLab_drawIcon3D_ehId", _ehId];
true
