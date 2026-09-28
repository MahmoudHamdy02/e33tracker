# Clair Obscur Area Item Tracker

A simple script to track which areas have been completed and print missing items in each area

Tracked items:
- Weapons
- Pictos
- Outfits
- Journals

# Usage

First, you need to convert your `.sav` save file to `.json` using the [`uesave` tool](https://github.com/trumank/uesave).

In a terminal:
```
./uesave.exe to-json -i path/to/save/file.sav -o path/to/json/file.json
```

Then, run the tracker and pass the file path of the `.json` file:

```
./e33tracker.exe path/to/json/file.json
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

Print missing items in each area? (y/n)
y
Sky Island: Urnaro, GreaterSlow,
...
```

# Notes

- Only main and side areas are included, i.e. no continent items etc.
- Areas with just a music record are not included
- Pictos with several levels are only counted once; if you have a level 1 picto then an area with the same picto at level 20 will still count it as picked up
- If an area contains a Manor Door which leads to an item, it will be tracked in the area itself, not 'The Manor'
- NG+/ending-specific items are not included:
  - Gustave's Crimson uniform outfit, Bun & Renoir haircuts
  - 'Baguette' weapon
  - Renoir haircut and outfit for Verso & Gustave
  - Civilian outfit for Lune & Sciel

