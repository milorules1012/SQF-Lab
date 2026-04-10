// File: fn_markersCollectUi.sqf
// Author: Milo
// Description: Reads markers dialog controls into a hash map for preview and export.

#include "ui_markers_controls.hpp"

private _display = uiNamespace getVariable ["SQFLab_markers_display", displayNull];
private _scrollGroup = uiNamespace getVariable ["SQFLab_markers_scrollGroup", controlNull];
if (isNull _display || isNull _scrollGroup) exitWith { nil };

private _name = ctrlText (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_EDIT_NAME);
private _text = ctrlText (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_EDIT_TEXT);

private _chkPosOff = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_CHK_POS_OFFSET;
private _usePosOffset = true;
if (!isNull _chkPosOff) then {
	_usePosOffset = cbChecked _chkPosOff;
};

private _defaultPos = if (_usePosOffset) then {
	player getPos [SQFLAB_MKR_PREVIEW_OFFSET_METERS, 0];
} else {
	getPosATL player;
};

private _posRaw = ctrlText (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_EDIT_POS);
private _parsed = parseSimpleArray _posRaw;
private _pos = uiNamespace getVariable ["SQFLab_markers_lastGoodPos", _defaultPos];;
private _parsedOk = if (_parsed isEqualTypeArray [0,0,0]) then {
	_parsed params ["_posX", "_posY", "_posZ"];
	_pos = [_posX, _posY, _posZ];
	(true)
} else {
	(false)
};

private _list = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_LIST_TYPES;
private _mkrType = "hd_dot";
if (!isNull _list) then {
	private _i = lbCurSel _list;
	_i = [_i, 0] select (_i < 0);
	if ((lbSize _list) > 0) then {
		_mkrType = _list lbData _i;
		if (_mkrType isEqualTo "") then { _mkrType = _list lbText _i };
	};
};

private _comboShape = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COMBO_SHAPE;
private _shape = "ICON";
if (!isNull _comboShape && { lbSize _comboShape > 0 }) then {
	private _selectionIndex = lbCurSel _comboShape;
	if (_selectionIndex < 0) then { _selectionIndex = 0 };
	_shape = _comboShape lbData _selectionIndex;
	if (_shape isEqualTo "") then { _shape = _comboShape lbText _selectionIndex };
};

private _comboBrush = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COMBO_BRUSH;
private _brush = "Solid";
if (!isNull _comboBrush && { lbSize _comboBrush > 0 }) then {
	private _brushIndex = lbCurSel _comboBrush;
	if (_brushIndex < 0) then { _brushIndex = 0 };
	_brush = _comboBrush lbData _brushIndex;
	if (_brush isEqualTo "") then { _brush = _comboBrush lbText _brushIndex };
};

private _comboShadowCtrl = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COMBO_SHADOW;
private _shadow = 0;
if (!isNull _comboShadowCtrl && { lbSize _comboShadowCtrl > 0 }) then {
	private _si = lbCurSel _comboShadowCtrl;
	if (_si < 0) then { _si = 0 };
	private _sd = _comboShadowCtrl lbData _si;
	if (_sd isEqualTo "") then {
		_shadow = parseNumber (_si > 0);
	} else {
		_shadow = round (parseNumber _sd);
	};
};

private _comboChannel = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COMBO_CHANNEL;
private _channel = 0;
if (!isNull _comboChannel && { lbSize _comboChannel > 0 }) then {
	private _ci = lbCurSel _comboChannel;
	if (_ci < 0) then { _ci = 0 };
	private _chData = _comboChannel lbData _ci;
	_channel = round (parseNumber _chData);
	if !(_channel in [-1, 0, 1, 2, 3, 4, 5]) then { _channel = -1 };
};

private _r = sliderPosition (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_SLIDER_COLOR_R);
private _g = sliderPosition (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_SLIDER_COLOR_G);
private _b = sliderPosition (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_SLIDER_COLOR_B);
private _a = sliderPosition (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_SLIDER_COLOR_A);

private _colorRgbaStr = format ["#(%1,%2,%3,%4)", _r, _g, _b, _a];
private _global = uiNamespace getVariable ["SQFLab_markers_global", false];

// The way we return a map just kinda sucks here. Sorry.
createHashMapFromArray [
	["markerName", _name],
	["markerText", _text],
	["position", _pos],
	["positionParsedOk", _parsedOk],
	["mkrType", _mkrType],
	["shape", _shape],
	["brush", _brush],
	["shadow", _shadow],
	["sizeA", sliderPosition (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_SLIDER_SIZE_A)],
	["sizeB", sliderPosition (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_SLIDER_SIZE_B)],
	["dir", sliderPosition (_scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_SLIDER_DIR)],
	["channel", _channel],
	["r", _r],
	["g", _g],
	["b", _b],
	["alpha", _a],
	["colorRgbaStr", _colorRgbaStr],
	["global", _global]
]
