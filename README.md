# SQF Lab

SQF Lab is an Arma 3 addon aimed at making **mission and mod development easier**. The addon provides multiple previews like the **3D scene**, the **map** where relevant, and **picture-in-picture** for features that use it—so you can judge colors, placement, and behaviour before exporting. Exporting produces ready-to-paste SQF code. Output goes to the clipboard when supported; otherwise it is written to the RPT log so you can still copy it with convenience.

# Features

## Light sources editor

Tune point and reflector lights (color, power, cone, flare, preview time, etc.) and export the setup as SQF.

<p align="center">
  <table border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td align="center" valign="top"><img src="https://i.gyazo.com/a03759b52422a5f5f8d0508edf42f98b.jpg" alt="Light sources editor — in-world preview" width="470" /></td>
      <td align="center" valign="top"><img src="https://i.gyazo.com/648af91bcbd2cc547696ecef6d1e6a55.jpg" alt="Light sources editor — UI panel" width="470" /></td>
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
      <td align="center" valign="top"><img src="https://i.gyazo.com/4d7b2784919450861296194fff9e3ea3.jpg" alt="Markers editor — map preview" width="470" /></td>
      <td align="center" valign="top"><img src="https://i.gyazo.com/103eb99ccdbe7ff92a0e5e516e53313a.jpg" alt="Markers editor — UI panel" width="470" /></td>
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
      <td align="center" valign="top"><img src="https://i.gyazo.com/ea994531cd1b218a8b6ab82e07d99e87.jpg" alt="Particles editor — in-world preview" width="470" /></td>
      <td align="center" valign="top"><img src="https://i.gyazo.com/a169ce9cf7132f942fc00f1a337781df.jpg" alt="Particles editor — UI panel" width="470" /></td>
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
      <td align="center" valign="top"><img src="https://i.gyazo.com/550d877551be1c1544c1ac22c1636859.jpg" alt="DrawIcon3D editor — in-world preview" width="470" /></td>
      <td align="center" valign="top"><img src="https://i.gyazo.com/12bedf3b62b596047c5c42308fa99616.jpg" alt="DrawIcon3D editor — export result preview" width="470" /></td>
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

![SQF Lab usage binding menu](https://i.gyazo.com/4808ad88a5aae47a5dc6a7986a38bf82.jpg)


