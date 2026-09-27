# Clair Obscur Area Item Tracker

A simple script to track which areas have been completed

Tracked items:
- Weapons
- Pictos
- Outfits
- Journals

# Usage

First, you need to convert your `.sav` save file to `.json` using the `uesave` tool.

Then, run the tracker executable from a terminal and pass the file path of the `.json` file:

```
./e33tracker.exe path/to/file.json
```

The output looks like this:
```
Item completion:
Weapons: 116/116
Pictos: 210/210
Outfits: 201/201
Journals: 49/49

Area completion:
Spring Meadows: Yes
Flying Waters: Yes
Ancient Sanctuary: Yes
Gestral Village: Yes
...
```

# Notes

- Only main and side areas are included, i.e. no continent items etc.
- Areas with just a music record are not included
- NG+/ending-specific items are not included:
  - Gustave's Crimson uniform outfit, Bun & Renoir haircuts
  - 'Baguette' weapon
  - Renoir haircut and outfit for Verso & Gustave
  - Civilian outfit for Lune & Sciel

