// File: fn_parseArrayOrFallback.sqf
// Author: Milo
// Description: Parses SQF array text and returns fallback when invalid.

params [
	["_text", "[]", [""]],
	["_fallback", [], [[]]]
];

private _parsed = call compile format ["%1", _text];
[_fallback, _parsed] select (_parsed isEqualType [])
