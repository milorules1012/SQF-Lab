// File: fn_trimSpaces.sqf
// Author: Milo
// Description: Removes spaces from text.

params [
	["_text", "", [""]]
];

(_text splitString " ") joinString ""
