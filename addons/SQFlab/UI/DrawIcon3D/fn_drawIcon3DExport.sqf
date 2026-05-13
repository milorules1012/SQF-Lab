// File: fn_drawIcon3DExport.sqf
// Author: Milo
// Description: Builds SQF export for DrawIcon3D alternative syntax.

#include "ui_drawIcon3D_controls.hpp"

private _icon = call SQFLab_fnc_drawIcon3DCollectUi;
if (isNil "_icon") exitWith {};

private _group = uiNamespace getVariable ["SQFLab_drawIcon3D_group", controlNull];
private _mode = 0;
if !(isNull _group) then {
	private _modeCtrl = _group controlsGroupCtrl SQFLAB_DI3D_IDC_COMBO_POS_MODE;
	_mode = lbCurSel _modeCtrl;
	if (_mode < 0) then { _mode = 0 };
};

private _pairs = [];
{
	private _key = _x;
	private _value = _icon get _key;
	if (_key isEqualTo "@position" && { _value isEqualType [] } && { count _value >= 2 } && { _mode > 0 }) then {
		private _objExpr = "player";
		if !(isNull _group) then {
			private _rawObjExpr = ctrlText (_group controlsGroupCtrl SQFLAB_DI3D_IDC_EDIT_POS_OBJECT);
			if (_rawObjExpr isNotEqualTo "") then { _objExpr = _rawObjExpr };
		};

		private _posStr = "";
		if (_mode isEqualTo 1) then {
			_posStr = format ["[%1,%2]", _objExpr, str (_value select 1)];
		} else {
			private _sel = if (count _value > 1) then { _value select 1 } else { "" };
			private _offZ = if (count _value > 2) then { _value select 2 } else { 0 };
			_posStr = format ["[%1,%2,%3", _objExpr, str _sel, str _offZ];
			if (count _value > 3) then {
				_posStr = _posStr + format [",%1", str (_value select 3)];
			};
			_posStr = _posStr + "]";
		};

		_pairs pushBack format ["	[%1, %2]", str _key, _posStr];
	} else {
		_pairs pushBack format ["	[%1, %2]", str _key, str _value];
	};
} forEach [
	"@position", "@texture", "@size", "@font", "@color", "@shadow", "@fade",
	"@dynamic", "@offsetX", "@offsetY", "@hardAlpha", "@checkVisibility",
	"@drawArrows", "@arrowTexture", "@arrowSize", "@arrowColor", "@arrowText",
	"@texts", "@progress", "@progressValue"
];

private _lines = [
	"// SQF Lab - DrawIcon3D export",
	"removeAllMissionEventHandlers ""Draw3D"";",
	"SQFLab_drawIcon3D_exportIcon = createHashMapFromArray",
	"[",
	(_pairs joinString ("," + toString [10])),
	"];",
	"addMissionEventHandler [""Draw3D"", { drawIcon3D SQFLab_drawIcon3D_exportIcon }];"
];

private _out = _lines joinString (toString [10]);
if (isServer) then {
	copyToClipboard _out;
	hint (localize "STR_SQFLAB_Hint_DrawIcon3DExportClipboard");
} else {
	{ diag_log _x } forEach _lines;
	hint (localize "STR_SQFLAB_Hint_DrawIcon3DExportRpt");
};
