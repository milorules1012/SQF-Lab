// File: fn_parseNumberOrFallback.sqf
// Author: Milo
// Description: Parses a numeric string and returns fallback when invalid.

params [
	["_text", "", [""]],
	["_fallback", 0, [0]]
];

private _value = parseNumber _text;
if (_value isEqualTo 0 && {_text != "0" && {_text != "0.0"}}) exitWith { _fallback };

_value
