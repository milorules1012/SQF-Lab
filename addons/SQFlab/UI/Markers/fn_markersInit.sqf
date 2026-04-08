// File: fn_markersInit.sqf
// Author: Milo
// Description: Initializes the markers editor UI (map center, combos, list, sliders).

#include "ui_markers_controls.hpp"
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

uiNamespace setVariable ["SQFLab_markers_display", _display];
if (isNil { uiNamespace getVariable "SQFLab_markers_global" }) then {
	uiNamespace setVariable ["SQFLab_markers_global", false];
};

private _scrollGroup = _display displayCtrl SQFLAB_MKR_IDC_GROUP_SCROLL;
uiNamespace setVariable ["SQFLab_markers_scrollGroup", _scrollGroup];

/* Before sliders / list / combos run: their config events call apply; name must not be empty. */
private _markerEdit = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_EDIT_NAME;
_markerEdit ctrlSetText format ["SQFLab_mkr_%1", floor (random 999999)];

private _sliderDefaults = createHashMapFromArray [
	[SQFLAB_MKR_IDC_SLIDER_COLOR_R, 1],
	[SQFLAB_MKR_IDC_SLIDER_COLOR_G, 0.5],
	[SQFLAB_MKR_IDC_SLIDER_COLOR_B, 0.1],
	[SQFLAB_MKR_IDC_SLIDER_COLOR_A, 0.9],
	[SQFLAB_MKR_IDC_SLIDER_SIZE_A, 1],
	[SQFLAB_MKR_IDC_SLIDER_SIZE_B, 1],
	[SQFLAB_MKR_IDC_SLIDER_DIR, 0]
];
private _sliderRanges = [
	[SQFLAB_MKR_IDC_SLIDER_COLOR_R, 0, 1],
	[SQFLAB_MKR_IDC_SLIDER_COLOR_G, 0, 1],
	[SQFLAB_MKR_IDC_SLIDER_COLOR_B, 0, 1],
	[SQFLAB_MKR_IDC_SLIDER_COLOR_A, 0, 1],
	[SQFLAB_MKR_IDC_SLIDER_SIZE_A, 1, 3000],
	[SQFLAB_MKR_IDC_SLIDER_SIZE_B, 1, 3000],
	[SQFLAB_MKR_IDC_SLIDER_DIR, 0, 360]
];

if (!isNull _scrollGroup) then {
	{
		_x params ["_idc", "_min", "_max"];
		private _ctrl = _scrollGroup controlsGroupCtrl _idc;
		if (!isNull _ctrl) then {
			_ctrl sliderSetRange [_min, _max];
			_ctrl sliderSetSpeed [((_max) - (_min)) / 100, ((_max) - (_min)) / 10];
			_ctrl sliderSetPosition (_sliderDefaults get _idc);
		};
	} forEach _sliderRanges;
};

if (!isNull _scrollGroup) then {
	private _comboShape = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COMBO_SHAPE;
	if (!isNull _comboShape) then {
		lbClear _comboShape;
		{ _comboShape lbAdd _x } forEach ["ICON", "RECTANGLE", "ELLIPSE"];
		_comboShape lbSetCurSel 0;
	};

	private _comboBrush = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COMBO_BRUSH;
	if (!isNull _comboBrush) then {
		lbClear _comboBrush;
		{ _comboBrush lbAdd _x } forEach ["Solid", "Border", "Grid", "FDiagonal", "BDiagonal", "Cross", "DiagGrid"];
		_comboBrush lbSetCurSel 0;
	};

	private _comboShadow = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COMBO_SHADOW;
	if (!isNull _comboShadow) then {
		lbClear _comboShadow;
		_comboShadow lbAdd "Off";
		_comboShadow lbAdd "On";
		_comboShadow lbSetCurSel 0;
	};

	private _comboChannel = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COMBO_CHANNEL;
	if (!isNull _comboChannel) then {
		lbClear _comboChannel;
		{
			_x params ["_label", "_data"];
			private _i = _comboChannel lbAdd _label;
			_comboChannel lbSetData [_i, _data];
		} forEach [
			["Default", "-1"],
			["Global", "0"],
			["Side", "1"],
			["Command", "2"],
			["Group", "3"],
			["Vehicle", "4"],
			["Direct", "5"]
		];
		_comboChannel lbSetCurSel 0;
	};

	private _list = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_LIST_TYPES;
	if (isNull _list) then {
		diag_log "[SQFLab] markersInit: marker type list control missing";
	} else {
		lbClear _list;
		private _cfgMarkers = configFile >> "CfgMarkers";
		private _markerNames = (configProperties [_cfgMarkers, "true", true]) select {
			(isClass _x && isText (_x >> "texture"))
		};
		_markerNames sort true;
		{
			private _i = _list lbAdd (configName _x);
			_list lbSetData [_i, (configName _x)];
		} forEach _markerNames;
		_list lbSetCurSel 0;
	};

	private _globalCheckbox = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_CHK_GLOBAL;
	if (!isNull _globalCheckbox) then {
		_globalCheckbox cbSetChecked (uiNamespace getVariable ["SQFLab_markers_global", false]);
	};
};

private _map = _display displayCtrl SQFLAB_MKR_IDC_MAP;
if (!isNull _map && !isNull _scrollGroup) then {
	private _positionEdit = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_EDIT_POS;
	private _offsetCheckbox = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_CHK_POS_OFFSET;
	private _pos = if (cbChecked _offsetCheckbox) then {
		(player getPos [SQFLAB_MKR_PREVIEW_OFFSET_METERS, 0])
	} else {
		(getPosATL player)
	};
	_positionEdit ctrlSetText str _pos;

	_map ctrlMapAnimAdd [0, 0.22, _pos];
	ctrlMapAnimCommit _map;
};

[] call SQFLab_fnc_markersOnSlider;

