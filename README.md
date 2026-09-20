# SQF Lab

SQF Lab is an Arma 3 addon aimed at making **mission and mod development easier**. The addon provides multiple previews like the **3D scene**, the **map** where relevant, and **picture-in-picture** for features that use it—so you can judge colors, placement, and behaviour before exporting. Exporting produces ready-to-paste SQF code. Output goes to the clipboard when supported; otherwise it is written to the RPT log so you can still copy it with convenience.

# Features

## Light sources editor

Tune point and reflector lights (color, power, cone, flare, preview time, etc.) and export the setup as SQF.

<p align="center">
  <table border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td align="center" valign="top"><img src="https://images.steamusercontent.com/ugc/14201715434627435796/9E9CBA0CDBE53210A33B1844BC7067F4BA883153/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true" alt="Light sources editor — in-world preview" width="470" /></td>
      <td align="center" valign="top"><img src="https://images.steamusercontent.com/ugc/9422597684703172656/D18726F02327E01972F165A5EEA783BD902C1873/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true" alt="Light sources editor — UI panel" width="470" /></td>
    </tr>
  </table>
</p>

- **Light type** — switch between point and reflector lights.
- **Transform** — edit ATL position; tune direction and up with sliders (for aiming reflectors via `setVectorDirAndUp`).
- **Color** — separate light and ambient RGB; live color preview swatch.
- **Power** — one control that drives `setLightBrightness` (point) or `setLightIntensity` (reflector).
- **Flare (point)** — optional flare, size, and max distance (although not visible in camera due to limitations- sorry!).
- **Preview time** — day / night presets (`setDate`) for the mission clock; affects the world and the picture-in-picture preview; restored when you close the dialog.
- **Reflector cone** — outer, inner, and coef for `setLightConePars` (ignored for point lights).
- **Live preview** — dedicated PiP panel next to the editor so you see the light while tweaking values.

## Markers editor

Configure marker identity, channel, shape, brush, color (RGBA), position, and related options, with a live map preview and SQF export.

<p align="center">
  <table border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td align="center" valign="top"><img src="https://images.steamusercontent.com/ugc/10472742808075756170/22BFF0A10C1843E8C7F7022C78C1AEA585AA4260/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true" alt="Markers editor — map preview" width="470" /></td>
      <td align="center" valign="top"><img src="https://images.steamusercontent.com/ugc/10365813461409619382/639C613B2188FFB28482609EB7E925BBC618C5BD/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true" alt="Markers editor — UI panel" width="470" /></td>
    </tr>
  </table>
</p>

- **Map preview** — full map control beside the form; marker updates as you edit.
- **Identity** — marker name and display text.
- **Scope** — controls whether exported commands are local or suffix with one global.
- **Channel** — defines channel (default, global, side, command, group, vehicle, direct).
- **Type** — pick an icon from `CfgMarkers` (limited by markers with a `texture` property- sorry!).
- **Color (RGBA)** — sliders for color affect direct RGBA strings for `setMarkerColorLocal`.
- **Position** — position for `setMarkerPos`; optional north offset so the preview is not drawn on player icon.
- **Shape** — icon, rectangle, or ellipse; size A/B and direction.
- **Brush** — `setMarkerBrush` patterns (solid, border, grid, diagonals, cross, DiagGrid).

## Particles editor

Adjust particle type, colors, motion, and related parameters, then export particle SQF.

<p align="center">
  <table border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td align="center" valign="top"><img src="https://images.steamusercontent.com/ugc/13695614413253223818/0742302BB10E3008D35BFF58F5A9305AAD545D1D/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true" alt="Particles editor — in-world preview" width="470" /></td>
      <td align="center" valign="top"><img src="https://images.steamusercontent.com/ugc/12447255737539556952/1F4B0578D286D90D29B1F3AA7E7474C490B3D12F/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true" alt="Particles editor — UI panel" width="470" /></td>
    </tr>
  </table>
</p>

- **Preset** — fire, smoke, or drop modes; each applies different base color and motion defaults.
- **Color** — RGBA sliders with a live preview swatch (combined with the preset base).
- **Particle params** — size, lifetime, spawn interval, move velocity, rotation velocity, weight, volume, and rubbing; etc.
- **Live preview** — picture-in-picture next to the panel so you see the effect while moving sliders.

## DrawIcon3D editor

Build and preview `drawIcon3D` payloads in real time, then export a ready-to-run Draw3D snippet.

<p align="center">
  <table border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td align="center" valign="top"><img src="https://images.steamusercontent.com/ugc/13593164696727906443/2D1AD46A1F5B1EA52C3EDD79E8F44973C4758376/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true" alt="DrawIcon3D editor — in-world preview" width="470" /></td>
      <td align="center" valign="top"><img src="https://images.steamusercontent.com/ugc/18101135485976749788/F6012A0EA2CE656CA8A3BA06BBFC337623291FE3/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true" alt="DrawIcon3D editor — export result preview" width="470" /></td>
    </tr>
  </table>
</p>

- **Position modes** — place the icon by direct vector, object + Z offset, or object selection + optional LOD.
- **Core icon fields** — texture, size, font, color RGBA, shadow, fade, dynamic mode, screen offsets, hard alpha, and visibility checks.
- **Arrow block** — toggle directional arrows with separate texture, size, color, and optional arrow label settings.
- **Overlay blocks** — configure optional text and progress bar overlays with independent color and layout controls.
- **Live world preview** — changes are rendered through a `Draw3D` mission event handler while the menu is open.
- **Export** — generates a `createHashMapFromArray` icon definition plus `Draw3D` handler scaffolding.
- **Current limitation** — this editor is temporarily available only on Arma 3 Development build (sorry).

# Usage
Bind the menu in your Arma 3 Settings.

![SQF Lab usage binding menu](https://images.steamusercontent.com/ugc/15861013107902507457/381BDA3B6017BBD33A22FB337BB5BA38D45C1D78/?imw=637&imh=358&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true)


