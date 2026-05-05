// File: fn_drawIcon3DApplyPreview.sqf
// Author: Milo
// Description: Caches normalized DrawIcon3D state for Draw3D callback.

private _icon = call SQFLab_fnc_drawIcon3DCollectUi;
if (isNil "_icon") exitWith { false };

uiNamespace setVariable ["SQFLab_drawIcon3D_icon", _icon];
true
