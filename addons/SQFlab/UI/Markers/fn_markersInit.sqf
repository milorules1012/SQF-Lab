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
	[SQFLAB_MKR_IDC_SLIDER_COLOR_G, 1],
	[SQFLAB_MKR_IDC_SLIDER_COLOR_B, 1],
	[SQFLAB_MKR_IDC_SLIDER_COLOR_A, 1],
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
		{
			_x params ["_strKey", "_data"];
			private _i = _comboShape lbAdd (localize _strKey);
			_comboShape lbSetData [_i, _data];
		} forEach [
			["STR_SQFLAB_Markers_ShapeIcon", "ICON"],
			["STR_SQFLAB_Markers_ShapeRectangle", "RECTANGLE"],
			["STR_SQFLAB_Markers_ShapeEllipse", "ELLIPSE"]
		];
		_comboShape lbSetCurSel 0;
	};

	private _comboBrush = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COMBO_BRUSH;
	if (!isNull _comboBrush) then {
		lbClear _comboBrush;
		{
			_x params ["_strKey", "_data"];
			private _i = _comboBrush lbAdd (localize _strKey);
			_comboBrush lbSetData [_i, _data];
		} forEach [
			["STR_SQFLAB_Markers_BrushSolid", "Solid"],
			["STR_SQFLAB_Markers_BrushBorder", "Border"],
			["STR_SQFLAB_Markers_BrushGrid", "Grid"],
			["STR_SQFLAB_Markers_BrushFDiagonal", "FDiagonal"],
			["STR_SQFLAB_Markers_BrushBDiagonal", "BDiagonal"],
			["STR_SQFLAB_Markers_BrushCross", "Cross"],
			["STR_SQFLAB_Markers_BrushDiagGrid", "DiagGrid"]
		];
		_comboBrush lbSetCurSel 0;
	};

	private _comboShadow = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COMBO_SHADOW;
	if (!isNull _comboShadow) then {
		lbClear _comboShadow;
		private _iOff = _comboShadow lbAdd (localize "STR_SQFLAB_Markers_ShadowOff");
		_comboShadow lbSetData [_iOff, "0"];
		private _iOn = _comboShadow lbAdd (localize "STR_SQFLAB_Markers_ShadowOn");
		_comboShadow lbSetData [_iOn, "1"];
		_comboShadow lbSetCurSel 0;
	};

	private _comboChannel = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_COMBO_CHANNEL;
	if (!isNull _comboChannel) then {
		lbClear _comboChannel;
		{
			_x params ["_strKey", "_data"];
			private _i = _comboChannel lbAdd (localize _strKey);
			_comboChannel lbSetData [_i, _data];
		} forEach [
			["STR_SQFLAB_Markers_ChannelDefault", "-1"],
			["STR_SQFLAB_Markers_ChannelGlobal", "0"],
			["STR_SQFLAB_Markers_ChannelSide", "1"],
			["STR_SQFLAB_Markers_ChannelCommand", "2"],
			["STR_SQFLAB_Markers_ChannelGroup", "3"],
			["STR_SQFLAB_Markers_ChannelVehicle", "4"],
			["STR_SQFLAB_Markers_ChannelDirect", "5"]
		];
		_comboChannel lbSetCurSel 0;
	};

	private _list = _scrollGroup controlsGroupCtrl SQFLAB_MKR_IDC_LIST_TYPES;
	if (isNull _list) then {
		diag_log "[SQFLab] markersInit: marker type list control missing";
	} else {
		lbClear _list;
		private _markerNames = (configProperties [configFile >> "CfgMarkers", "true", true]) select {
			(isClass _x && isText (_x >> "texture"))
		};
		_markerNames sort true;
		{
			private _cls = configName _x;
			private _tex = getText (_x >> "texture");
			private _i = _list lbAdd _cls;
			_list lbSetData [_i, _cls];
			_list lbSetPicture [_i, _tex];
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

